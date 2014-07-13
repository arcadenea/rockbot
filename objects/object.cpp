#include <cstdlib>
#include "object.h"
#include "file/format.h"
#include "classmap.h"
#include "st_common.h"

extern graphicsLib graphLib;
extern std::string FILEPATH;

#include "timerlib.h"
extern timerLib timer;

#include "graphicslib.h"
extern graphicsLib graphLib;

#include "soundlib.h"
extern soundLib soundManager;


extern CURRENT_FILE_FORMAT::file_game game_data;

#define GRAVITY_SPEED 4

#include "game.h"
extern game gameControl;

#define DISAPPEARNING_VISIBLE_TIME 1500
#define DISAPPEARNING_HIDDEN_TIME 2000
#define INITIAL_ACTIVATION_DELAY 220

// constructor for game_object


// constructor for map_object
object::object(int set_id, classMap *set_map, st_position map_pos) : _finished(false), _state(0), _duration(0), _timer_limit(0), _started(false), _animation_finished(false), _animation_reversed(false), _hidden(false)
{
	map = set_map;
	_id = set_id;
	name = std::string(game_data.objects[_id].name);
	graphic_filename = game_data.objects[_id].graphic_filename;
	type = game_data.objects[_id].type;
	obj_timer = game_data.objects[_id].timer;
	speed = game_data.objects[_id].speed;
	limit = game_data.objects[_id].limit;
	direction = 0;
	distance = 0;
	framesize_w = game_data.objects[_id].size.width;
	framesize_h = game_data.objects[_id].size.height;
	frame = 0;
	start_point.x = map_pos.x*TILESIZE;
	start_point.y = map_pos.y*TILESIZE;
    position.x = map_pos.x*TILESIZE;
    position.y = map_pos.y*TILESIZE;
	//std::cout << ">>> NEW map_pos.x: " << map_pos.x << ", map_pos.y: " << map_pos.y << ", obj.x: " << position.x << ", y: " << position.y << std::endl;
	//std::string complete_filename(FILEPATH + graphic_filename);
	if (limit == 0 && (type == OBJ_MOVING_PLATFORM_LEFTRIGHT || type == OBJ_MOVING_PLATFORM_UPDOWN)) {
		limit = 48;
    } else if (type == OBJ_DISAPPEARING_BLOCK) {
        _hidden = true;
        _started = true;
    }
	//std::cout << ">>>>> RESET COMMAND UP" << std::endl;
	_command_up = false;
	_command_down = false;
    _start_timer = 0;
    _obj_frame_timer = timer.getTimer()+game_data.objects[_id].frame_duration;
    _timer_limit = 0;
    _must_play_appearing_sfx = false;
    _must_teleport_in = false;
    _teleport_state = 0;
    _colision_mode = COLISION_MODE_XY;
    add_graphic();
}

object::~object()
{
    //std::cout << "object[" << name << "] destructor" << std::endl;
}

void object::reset()
{
    _finished = false;
    _state = 0;
    _duration = 0;
    _timer_limit = 0;
    _started = false;
    _animation_finished = false;
    _animation_reversed = false;
    _hidden = false;
    direction = 0;
    distance = 0;
    position.x = start_point.x;
    position.y = start_point.y;
    if (limit == 0 && (type == OBJ_MOVING_PLATFORM_LEFTRIGHT || type == OBJ_MOVING_PLATFORM_UPDOWN)) {
        limit = 48;
    } else if (type == OBJ_DISAPPEARING_BLOCK) {
        _hidden = true;
    }
    _command_up = false;
    _command_down = false;

}


// ********************************************************************************************** //
// adds an entry into object_graphics_list map, if needed                                      //
// ********************************************************************************************** //
void object::add_graphic()
{
    draw_lib.get_object_graphic(_id);
}

void object::remove_graphic()
{
///@TODO

}

void object::gravity()
{
    if (is_on_screen() == false) {
        return;
    }
	// non-falling object types
    if (type == OBJ_MOVING_PLATFORM_UPDOWN || type == OBJ_MOVING_PLATFORM_LEFTRIGHT || type == OBJ_DISAPPEARING_BLOCK || type == OBJ_FALL_PLATFORM || type == OBJ_ITEM_FLY || type == OBJ_FLY_PLATFORM || type == OBJ_ACTIVE_DISAPPEARING_BLOCK) {
		return;
	}
	for (int i=GRAVITY_SPEED; i>0; i--) {
        bool can_fall = test_change_position(0, i);
        //std::cout << "OBJECT::gravity - can_fall: " << can_fall << std::endl;
        if (can_fall == true) {
			position.y += i;
			check_player_move(0, i);
			break;
		}
	}
	if (position.y > RES_H) {
		_finished = true;
	}
}

bool object::test_change_position(short xinc, short yinc)
{
	if (map == NULL) {
		return false;
	}
	if (xinc == 0 && yinc == 0) {
		return true;
	}

    if (yinc > 0 && position.y > RES_H) { // check if item felt out of screen
        //std::cout << "OBJ::test_change_position - out of screen(down)" << std::endl;
        if (position.y < RES_H+TILESIZE*2) {
            if (type != OBJ_FALL_PLATFORM && type != OBJ_MOVING_PLATFORM_UPDOWN) {
                _finished = true;
                return false;
            } else {
                return true; // fall platform can move out of screen
            }
        } else {
            return true; // too much out of the screen, can't move more
        }
    }

    if (!is_consumable()) {
        // collision agains player when player is not using a platform
        int blocked = map->colision_rect_player_obj(gameControl.get_player(), this, 0, 0, 0, 0, xinc, yinc);
        //if (blocked != 0) std::cout << "obj.blocked: " << blocked << std::endl;
        /// @TODO - consumable items should not stop if blocked by player
        if (gameControl.get_player_platform() != this && blocked != 0) {
            //std::cout << "OBJ::test_change_position - can't move, BLOCKED by player" << std::endl;
            return false;
        }
    }

    if (position.y+yinc+framesize_h-2 > RES_H) { // falling out of the screen
        return true;
    }

	short p1 = map->getMapPointLock(st_position((position.x+2+xinc)/TILESIZE, (position.y+yinc+framesize_h-2)/TILESIZE));
	short p2 = map->getMapPointLock(st_position((position.x+framesize_w-2+xinc)/TILESIZE, (position.y+yinc+framesize_h-2)/TILESIZE));
    //std::cout << "object::test_change_position - p1: " << p1 << ", p2: " << p2 << std::endl;
	if ((p1 == TERRAIN_UNBLOCKED ||  p1 == TERRAIN_WATER) && (p2 ==TERRAIN_UNBLOCKED ||  p2 == TERRAIN_WATER)) {
		return true;
	}
	return false;
}

void object::check_player_move(int xinc, int yinc) const
{
	//std::cout << "object::check_player_move::START - p.platform: " << gameControl.get_player_platform() << ", this: " << this << std::endl;
	if (xinc == 0 && yinc == 0) {
        //std::cout << "object::check_player_move::LEAVE" << std::endl;
		return;
	}
	if (yinc < 0 && position.y+framesize_h < 0) {
		return;
	}
	if (yinc > 0 && position.y > RES_H) {
		return;
    }
	if (gameControl.get_player_platform() == this) {
        //std::cout << "************* object::check_player_move - MOVE xinc: " << xinc << ", yinc: " << yinc << " **************" << std::endl;
		gameControl.change_player_position(xinc, yinc, 0);
    }
}

void object::set_colision_mode(colision_modes colision_mode)
{
    _colision_mode = colision_mode;
}

colision_modes object::get_colision_mode() const
{
    return _colision_mode;
}

void object::reset_timers()
{
    _obj_frame_timer = 0;
    _timer_limit = 0;
}

void object::use_teleport_in_out()
{
    _must_teleport_in = true;
}

bool object::is_consumable()
{
    if (type == OBJ_ENERGY_PILL_BIG || type == OBJ_ENERGY_PILL_SMALL || type == OBJ_ENERGY_TANK || type == OBJ_LIFE || type == OBJ_WEAPON_PILL_BIG || type == OBJ_WEAPON_PILL_SMALL || type == OBJ_WEAPON_TANK) {
        return true;
    }
    return false;
}

void object::set_precise_position(st_position pos, int direction)
{
    position = pos;
    if (direction == ANIM_DIRECTION_LEFT) {
        position.x -= framesize_w;
    }
    start_point.x = position.x;
    start_point.y = position.y;

}





// ********************************************************************************************** //
// adds an entry into object_graphics_list map, if needed                                      //
// ********************************************************************************************** //
void object::show()
{
	st_rectangle graphic_origin;
	st_position graphic_destiny;

	if (map == NULL) {
		return;
	}

    if (draw_lib.get_object_graphic(_id) == NULL) {
		//std::cout << "object::show - could not find graphic for object with id " << _id << std::endl;
		return;
	}

	//printf("********* check draw object, x: %d, y: %d\n", position.x, position.y);
    if (_hidden == true) {
		//printf("********* show_object_sprites - hidden object\n");
		return;
	}

    if (_must_teleport_in) {
        if (_teleport_state == e_object_teleport_state_teleport_in || _teleport_state == e_object_teleport_state_teleport_out) {
            draw_lib.show_teleport_small(position.x - map->getMapScrolling().x, position.y);
            return;
        }
    }

    int max_frames = ((draw_lib.get_object_graphic(_id))->width/framesize_w)-1;
    //if (name == "Disappearing Block #1") std::cout << "OBJ::show::max_frames: " << max_frames << std::endl;

	// checks if the Object is near the screen to show it
	if (position.x+16 >= abs((float)map->getMapScrolling().x) && position.x-16 <= abs((float)map->getMapScrolling().x)+RES_W) {
		// animation

		//std::cout << "object::show - frame_duration: " << game_data.objects[_id].frame_duration << std::endl;

        if ((game_data.objects[_id].animation_auto_start == true || (game_data.objects[_id].animation_auto_start == false && _started == true)) && framesize_w * 2 <= (draw_lib.get_object_graphic(_id)->width))  { // have at least two frames
			graphic_origin.x = frame * framesize_w;
            if (_obj_frame_timer < timer.getTimer()) {
				if (_animation_finished == false) { //
					if (_animation_reversed == false) {
						frame++;
					} else {
						frame--;
					}
				}
                _obj_frame_timer = timer.getTimer()+game_data.objects[_id].frame_duration;
			}

			if (frame <= 0) {
				if (_animation_reversed == true) {
					_animation_finished = false;
					_animation_reversed = false;
					_started = false;
				}
				frame = 0;
			}
			if	(_animation_reversed == false && frame > max_frames) {
				if (game_data.objects[_id].animation_loop == false) { // if animation loop is set to false, set this to show always the last frame
					if (game_data.objects[_id].animation_reverse == false) { // don't need to reverse animation, finish it
						_animation_finished = true;
                        frame = draw_lib.get_object_graphic(_id)->width/framesize_w-1;
					} else {
						_animation_reversed = true; // start animation reverse process
						frame--;
					}
				} else {
					frame = 0;
				}
			}
		} else {
			graphic_origin.x = 0;
		}

		//std::cout << "object::show - frame_n: " << frame << ", _animation_reversed: " << _animation_reversed << ", max_frames: " << max_frames << std::endl;


		// direction
		//printf(">> sprite->h: %d, framesize_h*2: %d <<\n", sprite->h, (framesize_h*2));
        if (framesize_h*2 <= draw_lib.get_object_graphic(_id)->height)  {
			//std::cout << ">>>> object height is enought for direction-right";
			if (direction != ANIM_DIRECTION_RIGHT) {
				graphic_origin.y = 0;
			} else {
				graphic_origin.y = framesize_h;
			}
		} else {
			//std::cout << ">>>> NOT object image-height(" << (objects_sprite_list.find(name)->second).height << ") is NOT enought for direction-right. framesize_h: " << framesize_h << std::endl;
			graphic_origin.y = 0;
		}


		graphic_origin.w = framesize_w;
		graphic_origin.h = framesize_h;

		// parte que vai ser colada
		graphic_destiny.x = position.x - map->getMapScrolling().x;
		graphic_destiny.y = position.y + map->getMapScrolling().y;
		//std::cout << "searching for graphic '" << name << "'" << std::endl;
		//std::cout << "object::show - map->getMapScrolling().x: " << map->getMapScrolling().x << ", map->getMapScrolling().y: " << map->getMapScrolling().y << ", position.y: " << position.y << ", graphic_destiny.x: " << graphic_destiny.x << ", graphic_destiny.y: " << graphic_destiny.y << std::endl;

		std::map<unsigned int, graphicsLib_gSurface>::iterator it;
        if (draw_lib.get_object_graphic(_id) != NULL) { // there is no graphic with this key yet, add it
            graphLib.copyArea(st_rectangle(graphic_origin.x, graphic_origin.y, graphic_origin.w, graphic_origin.h), st_position(graphic_destiny.x, graphic_destiny.y), draw_lib.get_object_graphic(_id), &graphLib.gameScreen);
            // disappearning block has a shadow under it
            if (type == OBJ_DISAPPEARING_BLOCK) {
                graphLib.clear_area(graphic_destiny.x, graphic_destiny.y+framesize_h, framesize_w, 6, 0, 0, 0);
                if (_must_play_appearing_sfx == true) {
                    _must_play_appearing_sfx = false;
                    soundManager.play_sfx(SFX_DISAPPEARING_BLOCK);
                }
            }
		}

	// remove item that is out of vision
    } else if (_teleport_state == 2 && (type == OBJ_ITEM_FLY || type == OBJ_ITEM_JUMP)) {
        //std::cout << "REMOVE ITEM" << std::endl;
		_finished = true;
	}
}

void object::move()
{
    // check teleport
    if (_must_teleport_in == true) {
        //std::cout << "OBJECT::TELEPORT #1 - _teleport_state: " << _teleport_state << std::endl;
        // init teleport IN
        if (_teleport_state == e_object_teleport_state_initial) {
            if (type == OBJ_ITEM_FLY) {
                draw_lib.set_teleport_small_colors(st_color(219, 43, 0), st_color(235, 235, 235));
            } else if (type == OBJ_ITEM_JUMP) {
                draw_lib.set_teleport_small_colors(st_color(0, 147, 59), st_color(235, 235, 235));
            } else {
                draw_lib.set_teleport_small_colors(st_color(112, 110, 110), st_color(235, 235, 235));
            }
            position.y = -framesize_h+2;
            //std::cout << "OBJECT::TELEPORT #2 - pos.y: " << position.y << std::endl;
            _teleport_state = e_object_teleport_state_teleport_in;
            return;
        // teleporting IN
        } else if (_teleport_state == e_object_teleport_state_teleport_in) {
            int yinc = GRAVITY_SPEED*3;
            //std::cout << "OBJECT::TELEPORT #3 - pos.y: " << position.y << ", start_point.y: " << start_point.y << std::endl;
            if (position.y+yinc > start_point.y) {
                position.y = start_point.y;
            } else {
                position.y += yinc;
            }
            if (position.y == start_point.y) {
                // check if not teleported inside terrain, if so, teleport out
                int map_lock = map->getMapPointLock(st_position((position.x+framesize_w/2)/TILESIZE, (position.y+framesize_h/2)/TILESIZE));
                if (map_lock != TERRAIN_UNBLOCKED && map_lock != TERRAIN_WATER) {
                    _teleport_state = e_object_teleport_state_teleport_out;
                } else {
                    _teleport_state = e_object_teleport_state_waiting;
                }
            }
            return; // will stay in 2 until finished, when will be set to 3
        // teleporting out
        } else if (_teleport_state == e_object_teleport_state_teleport_out) {
            //std::cout << "OBJECT::move - teleport OUT" << std::endl;
            int yinc = GRAVITY_SPEED*3;
            position.y -= yinc;
            if (position.y + framesize_h < 0) {
                _finished = true;
            }
        }
    }


    //std::cout << "name: " << name << ", _duration: " << _duration << ", time-limit: " << _timer_limit << ", timer: " << timer.getTimer() << std::endl;
	if (_duration > 0 && timer.getTimer() > _timer_limit) {
        if (_must_teleport_in == true) {
            //std::cout << "OBJECT::move - is finished, but must teleport out first" << std::endl;
            _teleport_state = 3;
        } else {
            _finished = true;
        }
		return;
	}
	//std::cout << "object::move::START" << std::endl;
	if (type == OBJ_MOVING_PLATFORM_LEFTRIGHT) {
		if (distance > limit) {
			invert_direction_x();
			distance = 0;
		}
		int xinc=0;
		if (direction == ANIM_DIRECTION_LEFT) {
			xinc = -speed;
		} else {
			xinc = speed;
		}
		bool can_move = test_change_position(xinc, 0);
		//std::cout << "object::move::OBJ_MOVING_PLATFORM_LEFTRIGHT - xinc: " << xinc << ", can_move: " << can_move << ", distance: " << distance << ", limit: " << limit << std::endl;
		if (can_move) {
			position.x += xinc;
			check_player_move(xinc, 0);
			distance += abs((float)xinc);
		} else {
			invert_direction_x();
            // calc the distance based on how much was missing for the limit
            distance = limit - distance;
		}
	} else if (type == OBJ_MOVING_PLATFORM_UPDOWN) {
		if (distance > limit) {
			//std::cout << "OBJ_MOVING_PLATFORM_UPDOWN - limit reached - distance: " << distance << ", limit: " << limit << ", invert" << std::endl;
			invert_direction_y();
			distance = 0;
		}
        int yinc = 0;
		if (direction == ANIM_DIRECTION_UP) {
			yinc = -speed;
		} else {
			yinc = speed;
		}
		bool can_move = test_change_position(0, yinc);
		//std::cout << "object::move::OBJ_MOVING_PLATFORM_LEFTRIGHT - xinc: " << xinc << ", can_move: " << can_move << ", distance: " << distance << ", limit: " << limit << std::endl;
		if (can_move) {
			position.y += yinc;
			check_player_move(0, yinc);
			distance += abs((float)yinc);
		} else {
            std::cout << "object is blocked, yinc: " << yinc << ", current-dist: " << distance << ", limit: " << limit << ", new-dist: " << (limit-distance) << std::endl;
            distance = limit - distance + yinc;
            invert_direction_y();
        }
	} else if (type == OBJ_FALL_PLATFORM) {
        if (timer.getTimer() < _start_timer) { // initial delay
            return;
        }
		if (_state == OBJ_STATE_MOVE) { // falling state
			int yinc = speed;
			bool can_move = test_change_position(0, yinc);
			if (can_move) {
                //std::cout << "OBJ_FALL_PLATFORM - yinc: " << yinc << ", pos.y: " << position.y << std::endl;
				position.y += yinc;
				check_player_move(0, yinc);
				distance += abs((float)yinc);
			} else {
                //std::cout << "OBJ_FALL_PLATFORM - RETURN " << std::endl;
				_state = OBJ_STATE_RETURN;
			}
		} else if (_state == OBJ_STATE_RETURN) { // returning state
            if (gameControl.get_player_platform() != this) { // do not return if player is on it
                if (distance == 0) { // added because of initial delay
                    stop();
                } else {
                    int yinc = -speed/2;
                    if (yinc == 0) {
                        yinc = -1;
                    }
                    position.y += yinc;
                    check_player_move(0, yinc);
                    distance -= abs((float)yinc);
                    if (distance == 0) {
                        stop();
                    }
                }
            }
		}
		// check out of screen
		if (_state == 1 && position.y > RES_H+TILESIZE*3) {
			_state = OBJ_STATE_RETURN;
		}
	} else if (type == OBJ_FLY_PLATFORM) {
        if (timer.getTimer() < _start_timer) { // initial delay
            return;
        }
        if (_state == OBJ_STATE_MOVE) { // flying state
            int yinc = -speed;
            bool can_move = test_change_position(0, yinc);
            if (can_move) {
                check_player_move(0, yinc);
                position.y += yinc;
                distance += abs((float)yinc);
            } else {
                _state = OBJ_STATE_RETURN;
            }
            // check out of screen
            //std::cout << "FLY PLATFORM, position.y: " << position.y << ", framesize_h+TILESIZE: " << (framesize_h+TILESIZE) << std::endl;
            if (_state == 1 && position.y < -(framesize_h+TILESIZE)) {
                //std::cout << "FLY PLATFORM -> RETURN" << std::endl;
                _state = OBJ_STATE_RETURN;
            }
        } else if (_state == OBJ_STATE_RETURN) { // returning state
            if (distance == 0) { // added because of initial delay
                //std::cout << "FLY_PLATFORM::RETURN::STOP#1" << std::endl;
                stop();
            } else {
                int yinc = speed/2;
                if (yinc == 0) {
                    yinc = -1;
                }
                position.y += yinc;
                //std::cout << "FLY_PLATFORM::RETURN::MOVE, yinc: " << yinc << ", pos.y: " << position.y << std::endl;
                check_player_move(0, yinc);
                distance -= abs((float)yinc);
                if (distance == 0) {
                    //std::cout << "FLY_PLATFORM::RETURN::STOP#2" << std::endl;
                    stop();
                }
            }
        }


	} else if (type == OBJ_ITEM_FLY && _started == true) {
		if (speed < 1) {
			speed = 3;
		}
		int xinc = speed;
		int yinc = 0;
		if (direction == ANIM_DIRECTION_LEFT) {
			xinc = -speed;
		}
		if (_command_up == true) {
			yinc = -speed;
		}
		if (_command_down == true) {
			yinc = speed;
		}
		position.x += xinc;
		position.y += yinc;
        //std::cout << "OBJ FLY STARTED - move - xinc: " << xinc << ", position.x: " << position.x << std::endl;
		check_player_move(xinc, yinc); // @TODO - player can move up/down
		distance += abs((float)xinc);
		_command_up = false;
		_command_down = false;
    } else if (type == OBJ_DISAPPEARING_BLOCK) { // 1500 is visible time and 2000 is hidden time. initial delay is defined by obj_timer
        /// @TODO - this must be "static" for all objects of this type
        if (_timer_limit < timer.getTimer()) {
            if (_timer_limit == 0) {
                //std::cout << "OBJ::move() - init timer[" << _id << "]: " << obj_timer << std::endl;
                _timer_limit = timer.getTimer() + obj_timer;
            } else {
                //std::cout << "OBJ_DISAPPEARING_BLOCK - obj_timer: " << obj_timer << ", limit: " << limit << std::endl;
                int timer_add = DISAPPEARNING_HIDDEN_TIME;
                if (_hidden == false) {
                    timer_add = DISAPPEARNING_VISIBLE_TIME;
                }
                _timer_limit = timer.getTimer() + timer_add;
                _hidden = !_hidden;
                if (_hidden == false && is_on_screen() == true) {
                    reset_animation();
                    _must_play_appearing_sfx = true;
                }
            }
        }
    } else if (type == OBJ_ACTIVE_DISAPPEARING_BLOCK) {
        //std::cout << "OBJ_ACTIVE_DISAPPEARING_BLOCK - MOVE - _started: " << _started << ", _timer_limit: " << _timer_limit << ", timer.now: " << timer.getTimer() << std::endl;
        if (_started == true && _timer_limit < timer.getTimer()) {
            if (_hidden == false) { // turn hidden
                //std::cout << "OBJ_ACTIVE_DISAPPEARING_BLOCK - HIDE" << std::endl;
                _hidden = true;
                _timer_limit = timer.getTimer() + DISAPPEARNING_HIDDEN_TIME;
            } else { // return to visible state
                //std::cout << "OBJ_ACTIVE_DISAPPEARING_BLOCK - SHOW" << std::endl;
                _started = false;
                _hidden = false;
            }
        }
    }
}

void object::reset_animation()
{
    frame = 0;
    _animation_finished = false;
    _obj_frame_timer = timer.getTimer()+game_data.objects[_id].frame_duration;
}

void object::stop()
{
    _state = OBJ_STATE_STAND;
    _started = false;
    reset_animation();
}


// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void object::execute()
{
	move();
    gravity();
	/// @TODO: finish items
}

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
st_position object::get_position() const
{
	return position;
}


// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
st_size object::get_size()
{
	return st_size(framesize_w, framesize_h);
}


// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
short int object::get_type() const
{
    return type;
}

short object::get_id() const
{
    return _id;
}

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
int object::get_direction() const
{
	return direction;
}

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void object::set_direction(int new_dir)
{
	direction = new_dir;
}

int object::get_distance() const
{
	return distance;
}



void object::set_distance(int new_dist)
{
	distance = new_dist;
}


void object::set_timer(int new_timer)
{
	obj_timer = new_timer;
}

unsigned int object::get_timer() const
{
	return obj_timer;
}

bool object::finished() const
{
    //std::cout << ">> object::finished: " << _finished << std::endl;
	return _finished;
}

void object::set_finished(bool is_finished)
{
    //std::cout << ">> object::set_finished: " << is_finished << std::endl;
	_finished = is_finished;
}

void object::invert_direction_x()
{
	if (direction == ANIM_DIRECTION_LEFT) {
		//std::cout << "invert left->right" << std::endl;
		direction = ANIM_DIRECTION_RIGHT;
	} else {
		//std::cout << "invert right->left" << std::endl;
		direction = ANIM_DIRECTION_LEFT;
	}
}

void object::invert_direction_y() {
	if (direction == ANIM_DIRECTION_UP) {
		//std::cout << "invert up->down" << std::endl;
		direction = ANIM_DIRECTION_DOWN;
	} else {
		//std::cout << "invert down->up" << std::endl;
		direction = ANIM_DIRECTION_UP;
	}
}

void object::set_state(short obj_state)
{
	_state = obj_state;
	//std::cout << "********* object::set_state::state: " << _state << std::endl;
}

short object::get_state() const
{
	return _state;
}

void object::set_duration(int duration)
{
	_duration = duration;
	_timer_limit = timer.getTimer() + duration;
}

void object::start()
{
	_started = true;
    _start_timer = timer.getTimer() + INITIAL_ACTIVATION_DELAY;
    //std::cout << "OBJECT::start - _start_timer: " << _start_timer << std::endl;
    if (type == OBJ_ACTIVE_DISAPPEARING_BLOCK) {
        //std::cout << "OBJ_ACTIVE_DISAPPEARING_BLOCK - STARTED - obj_timer: " << obj_timer << std::endl;
        _timer_limit = timer.getTimer() + obj_timer;
    }
}

void object::command_up()
{
	_command_up = true;
    //std::cout << ">>>>> SET COMMAND UP" << std::endl;
}

void object::command_down()
{
	_command_down = true;
}

std::string object::get_name() const
{
    return name;
}

bool object::is_hidden() const
{
    //std::cout << "object::is_hidden - _hidden: " << _hidden << std::endl;
    return _hidden;
}

bool object::is_started() const
{
    return _started;
}

bool object::is_on_screen()
{
    st_position scroll = map->getMapScrolling();
    // entre scroll.x-RES_W/2 e scroll.x+RES_W+RES_W/2

    //if (realPosition.x < -TILESIZE*2 || realPosition.x > (RES_W+TILESIZE*2)) {
    if (abs((float)position.x) > scroll.x-RES_W/2 && abs((float)position.x) < scroll.x+RES_W*1.5) {
        return true;
    }
    return false;
}

