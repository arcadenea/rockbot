#include <cstdlib>
#include "projectilelib.h"
#include "timerlib.h"
#include "classmap.h"
#include <cmath>

#include "soundlib.h"
extern soundLib soundManager;

extern timerLib timer;
extern CURRENT_FILE_FORMAT::file_game game_data;

#define QUAKE_TIMER 80

extern FREEZE_EFFECT_TYPES freeze_weapon_effect;
extern int freeze_weapon_id;
#define FREEZE_DURATION 3500


// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
projectile::projectile(int id, int set_direction, st_position set_position, classMap *set_map, bool _owner_is_player) : _move_type(-1), is_reflected(false), status(0), _effect_timer(0), _effect_n(0), _points(1), _target_position(NULL), _weapon_id(-1), _is_temporary(true)
{
    set_default_values();
	_id = id; // -1 is default projectile
    map = set_map;
    position = set_position;
    direction = set_direction;
	_size = get_size();

	/// @TODO _ move this to game load
    _speed = PROJECTILE_DEFAULT_SPEED;
	if (_id == -1) {
		_size.width = 6;
		_size.height = 6;
    } else if (game_data.projectiles[_id].speed > 0) {
        _speed = game_data.projectiles[_id].speed;
    }


    animation_timer = timer.getTimer() + PROJECTILE_DEFAULT_ANIMATION_TIME; // used to control each frame duration

	position.y -= _size.height/2;
	_max_frames = get_surface()->width / _size.width;
	_move_type = get_trajectory();


    if (_move_type == TRAJECTORY_ARC) {
        position0.x = position.x;
        position0.y = position.y;
        _trajectory_parabola = trajectory_parabola(RES_W/2);

    } else if (_move_type == TRAJECTORY_ARC_TO_TARGET) {
        position0.x = position.x;
    } else if (_move_type == TRAJECTORY_SIN) {
		if (direction == ANIM_DIRECTION_LEFT) {
			position0.x = 0;
		}
	} else if (_move_type == TRAJECTORY_QUAKE) {
		_quake_info.timer = timer.getTimer() + QUAKE_TIMER;
	} else if (_move_type == TRAJECTORY_FREEZE) {
		_quake_info.timer = timer.getTimer() + FREEZE_DURATION;
        if (_owner_is_player == true) {
            freeze_weapon_effect = FREEZE_EFFECT_NPC;
            //std::cout << "PLAYER SET freeze to [" << FREEZE_EFFECT_NPC << "], value [" << freeze_weapon_effect << "]" << std::endl;
        } else {
            freeze_weapon_effect = FREEZE_EFFECT_PLAYER;
            //std::cout << "NPC SET freeze to [" << FREEZE_EFFECT_NPC << "], value [" << freeze_weapon_effect << "]" << std::endl;
        }
        freeze_weapon_id = _id;
		graphLib.blink_screen(235, 235, 235);
	} else {
		position0.x = position.x;
		position0.y = position.y;
        //std::cout << ">> position0.x: " << position0.x << ", position.x: " << position.x << std::endl;
	}
    //_target_distance = 0;
    _effect_timer = timer.getTimer() + 3600;
    animation_pos = 0;
    diagonal_flag = false;
    angle = 0;
    radius = 0;
    _owner_direction = 0;
    is_reflected = false;
    _change_direction_counter = 0;


    //std::cout << ">> Added projectyle, move_type: " << _move_type << ", TRAJECTORY_FOLLOW: " << TRAJECTORY_FOLLOW << ", w: " << _size.width << ", h: " << _size.height << std::endl;

    // for size, use getsize
    // for speed, use get_speed
    // for damage, use get_damage
    // for trajectory, get_trajectory

}

void projectile::set_is_permanent()
{
    _is_temporary = false;
}

void projectile::set_default_values()
{
    _owner_position = NULL;
    is_finished = false;
    move_timer = 0;
    move_delay = 10;
}

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
projectile::~projectile()
{
    if (_is_temporary == false && _move_type == TRAJECTORY_FREEZE) {
        //std::cout << "projectile::projectile - freeze projectile DESTRUCTOR" << std::endl;
        freeze_weapon_effect = FREEZE_EFFECT_NONE;
        freeze_weapon_id = -1;
	}
}


st_size projectile::get_size() const
{
    if (_id == -1) {
		return st_size(6, 6);
	}
    return game_data.projectiles[_id].size;
}

void projectile::move_ahead(st_size &moved)
{
    if (direction == ANIM_DIRECTION_LEFT || direction == ANIM_DIRECTION_DOWN_LEFT || direction == ANIM_DIRECTION_UP_LEFT) {
        position.x -= get_speed();
        moved.width -= get_speed();
    } else {
        position.x += get_speed();
        moved.width += get_speed();
    }
}

void projectile::position_to_ground()
{
    // change y until the projectile reachs ground
    while ((position.y + get_surface()->height/2) < RES_H) {
        int lock = map->getMapPointLock(st_position(position.x/TILESIZE, (position.y + get_surface()->height/2)/TILESIZE)); //map->map_tiles.tiles[position.x/TILESIZE][position.y/TILESIZE].locked;
        if (lock != TERRAIN_UNBLOCKED && lock != TERRAIN_WATER) {
            return;
        }
        position.y++;
    }
}

void projectile::set_direction_from_xyinc(int xinc, int yinc)
{
    if (_change_direction_counter > 1) { // avoid too often changes in direction animation
        _change_direction_counter = 0;
    } else {
        return;
    }
    _change_direction_counter++;
    if (yinc > 0) {
        if (xinc > 0) {
            direction = ANIM_DIRECTION_DOWN_RIGHT;
        } else if (xinc < 0) {
            direction = ANIM_DIRECTION_DOWN_LEFT;
        } else {
            direction = ANIM_DIRECTION_DOWN;
        }
    } else if (yinc < 0) {
        if (xinc > 0) {
            direction = ANIM_DIRECTION_UP_RIGHT;
        } else if (xinc < 0) {
            direction = ANIM_DIRECTION_UP_LEFT;
        } else {
            direction = ANIM_DIRECTION_UP;
        }
    } else { // yinc equals zero
        if (xinc > 0) {
            direction = ANIM_DIRECTION_RIGHT;
        } else {
            direction = ANIM_DIRECTION_LEFT;
        }
    }
}

void projectile::set_direction_from_targetpos(int middle_tolerance)
{
    if (_target_position->y < position.y+_size.height/2-middle_tolerance) {        // target above
        if (_target_position->x+_size.width/2 > position.x) {
            direction = ANIM_DIRECTION_UP_RIGHT;
        } else if (_target_position->x+_size.width/2 < position.x) {
            direction = ANIM_DIRECTION_UP_LEFT;
        } else {
            direction = ANIM_DIRECTION_UP;
        }
    } else if (_target_position->y > position.y+_size.height/2+middle_tolerance) { // target under
        if (_target_position->x+_size.width/2 > position.x) {
            direction = ANIM_DIRECTION_DOWN_RIGHT;
        } else if (_target_position->x+_size.width/2 < position.x) {
            direction = ANIM_DIRECTION_DOWN_LEFT;
        } else {
            direction = ANIM_DIRECTION_DOWN;
        }
    } else {                                                    // target on same line
        if (_target_position->x+_size.width/2 > position.x) {
            direction = ANIM_DIRECTION_RIGHT;
        } else {
            direction = ANIM_DIRECTION_LEFT;
        }
    }
}



unsigned short projectile::get_speed() const
{
    return _speed;
}

unsigned short projectile::get_damage() const
{
    if (_id == -1) {
        return PROJECTILE_DEFAULT_DAMAGE;
    }
    if ((get_trajectory() == TRAJECTORY_BOMB || get_trajectory() == TRAJECTORY_FALL_BOMB) && _effect_n == 0) {
		return 0;
	}
	if (game_data.projectiles[_id].damage <= 0) {
		return PROJECTILE_DEFAULT_DAMAGE;
	}
    return game_data.projectiles[_id].damage;
}

unsigned short projectile::get_trajectory() const
{
    if (_id == -1) {
        return TRAJECTORY_LINEAR;
    }
	return game_data.projectiles[_id].trajectory;
}

void projectile::set_trajectory(short new_trajectory)
{
	_move_type = new_trajectory;
}


void projectile::set_target_position(st_float_position *pos)
{
	_target_position = pos;
	if (_target_position == NULL && _move_type == TRAJECTORY_FOLLOW) { // if a follow projectile could not find any target, act as zig-zag
        //std::cout << "TRAJECTORY_FOLLOW - could not find target" << std::endl;
		_move_type = TRAJECTORY_ZIGZAG;
    } else 	if (_target_position != NULL && _move_type == TRAJECTORY_TARGET_DIRECTION) { // change type to be the best one to hit player
        // three position (diagonal up, left/right or diagonal down)
        //std::cout << ">> _target_position->y: " << _target_position->y << ", pos.y: " << position.y << std::endl;
		if (_target_position->y < position.y-TILESIZE*2) {
			_move_type = TRAJECTORY_DIAGONAL_UP;
		} else if (_target_position->y > position.y+TILESIZE*2) {
			_move_type = TRAJECTORY_DIAGONAL_DOWN;
        } else {
			_move_type = TRAJECTORY_LINEAR;
            _diagonal_speed.y = 0;
		}
        set_direction_from_targetpos(TILESIZE*2);


    } else 	if (_target_position != NULL && _move_type == TRAJECTORY_TARGET_EXACT) {
        _diagonal_speed.x = get_speed();
        int dist_x = _target_position->x - position.x;
        int dist_y = _target_position->y - position.y;
        _diagonal_speed.y = (_diagonal_speed.x * dist_y) / dist_x;
        if (dist_x < 0) {
            _diagonal_speed.y = _diagonal_speed.y * -1;
        }
        set_direction_from_targetpos(TILESIZE/2);


    } else if (_target_position != NULL && _move_type == TRAJECTORY_ARC_TO_TARGET) {
        _trajectory_parabola = trajectory_parabola(_target_position->x - position.x);
        position0.y = position.y;
    }
}

graphicsLib_gSurface *projectile::get_surface()
{
	if (_id == -1) {
        if (&graphLib.projectile_surface[0].gSurface == NULL) {
            graphLib.show_debug_msg("projectile surface error #1");
        }
		return &graphLib.projectile_surface[0];
	} else {
        if (&graphLib.projectile_surface[_id].gSurface == NULL) {
            graphLib.show_debug_msg("projectile surface error #2");
        }
        return &graphLib.projectile_surface[_id];
	}
}

st_size projectile::move() {
	st_size moved;

	//std::cout << "projectile::move - TRAJECTORY: " << _move_type << ", x: " << position.x << ", y: " << position.y << ", direction: " << direction << std::endl;

	if (move_timer >= timer.getTimer()) {
		//std::cout << "projectile::projectile - return #1" << std::endl;
		return st_size(0, 0);
	}
    move_timer = timer.getTimer()+ move_delay;




	if (_move_type == TRAJECTORY_LINEAR || _move_type == TRAJECTORY_DIAGONAL_UP || _move_type == TRAJECTORY_DIAGONAL_DOWN) {
        move_ahead(moved);

		//std::cout << "projectile::move - new position - " << ", x: " << position.x << ", y: " << position.y << std::endl;

		if (diagonal_flag == false) {
			if (_move_type == TRAJECTORY_DIAGONAL_UP) {
				position.y -= get_speed();
				moved.height -= get_speed();
			} else if (_move_type == TRAJECTORY_DIAGONAL_DOWN) {
				position.y += get_speed();
				moved.height += get_speed();
			}
			diagonal_flag = true;
		} else {
			diagonal_flag = false;
		}
    } else if (_move_type == TRAJECTORY_TARGET_DIRECTION || _move_type == TRAJECTORY_TARGET_EXACT) {
        move_ahead(moved);
        position.y += _diagonal_speed.y;


    } else if (_move_type == TRAJECTORY_ARC) {
        if (position.y < _size.height || position.y > RES_H) {
            is_finished = true;
            return st_size(0, 0);
        }
        move_ahead(moved);
        position.y = position0.y - _trajectory_parabola.get_y_point(abs(position.x - position0.x));
    } else if (_move_type == TRAJECTORY_ARC_TO_TARGET) {
        move_ahead(moved);
        position.y = position0.y - _trajectory_parabola.get_y_point(abs(position.x - position0.x));
	} else if (_move_type == TRAJECTORY_SIN) {
		angle += 0.5;
		if (angle > 360.0) {
			angle = 0.0;
		}
        move_ahead(moved);
		position.y = sin(angle)*TILESIZE*2 + position0.y;
	} else if (_move_type == TRAJECTORY_BOMB) {
		if (_effect_n == 0 && _effect_timer < timer.getTimer()) {
            //std::cout << "BOMB - TRANSFORM into explosion" << std::endl;
			/// morph into a bigger explosion
			_points = 5000;
			_effect_timer = timer.getTimer()+3600;

			_size.width = 56;
			_size.height = 56;
			position.x -= 28;
			position.y -= 28;
			_max_frames = get_surface()->width / _size.width;
			_effect_n++;
			soundManager.play_repeated_sfx(SFX_BIG_EXPLOSION, 3);
		} else if (_effect_n == 1 && _effect_timer < timer.getTimer()) {
			is_finished = true;
		}
		//std::cout << "projectile::move - BOMB" << std::endl;
		// do nothing, it is a bomb, it just stays until explodes
	} else if (_move_type == TRAJECTORY_CHAIN) {
        if (status == 0) { // increasing
            //std::cout << "position0.x: " << position0.x << ", position.x: " << position.x << std::endl;
            if (direction == ANIM_DIRECTION_LEFT) {
				position.x -= get_speed();
			} else {
				position.x += get_speed();
            }
            if (abs((float)position0.x-position.x) > _size.width) {
				status = 1;
			}
		} else { // returning
			moved.width -= get_speed();
			if (direction == ANIM_DIRECTION_LEFT) {
				position.x += get_speed();
			} else {
				position.x -= get_speed();
			}
			if (abs((float)position0.x-position.x) <= 0) {
				is_finished = true;
			}
		}
	} else if (_move_type == TRAJECTORY_QUAKE) { // shake the screen
        //std::cout << "TRAJECTORY_QUAKE - quake.timer: " << _quake_info.timer << ", timer: " << timer.getTimer() << std::endl;
		if (_quake_info.timer < timer.getTimer()) {
			if (_quake_info.counter1 == 1) {
				_quake_info.counter1 = 2;
				graphLib.set_screen_adjust(st_position(-QUAKE_SCREEN_MOVE, 0));
			} else {
				_quake_info.counter1 = 1;
				graphLib.set_screen_adjust(st_position(QUAKE_SCREEN_MOVE, 0));
			}
			_quake_info.counter2++;
			if (_quake_info.counter2 > 20) {
				_quake_info.counter1 = 0;
				graphLib.set_screen_adjust(st_position(0, 0));
				is_finished = true;
			}
			_quake_info.timer = timer.getTimer() + QUAKE_TIMER;
		}
	} else if (_move_type == TRAJECTORY_FREEZE) {
        //std::cout << "projectile::projectile - freeze RUNNING, timer: " << timer.getTimer() << ", should stop at " << _quake_info.timer << std::endl;
		if (_quake_info.timer < timer.getTimer()) {
            //std::cout << "projectile::projectile - freeze STOPPED at[" << timer.getTimer() << "], should stop at [" << _quake_info.timer << "]" << std::endl;
            freeze_weapon_effect = FREEZE_EFFECT_NONE;
			is_finished = true;
		}
	} else if (_move_type == TRAJECTORY_CENTERED) {
		//std::cout << "TRAJECTORY_CENTERED CHECK - timer: " << timer.getTimer() << ", _quake_info.timer: " << _quake_info.timer << std::endl;

		if (_owner_position == NULL) {
            std::cout << "ERROR: owner positoon NOT set in centered projectile" << std::endl;
		} else {
			position.x = _owner_position->x - 15;
			position.y = _owner_position->y - 7;
			if (_owner_direction != NULL) {
				direction = *_owner_direction;
			}
            // after some time, change to linear
			if (_effect_timer < timer.getTimer()) {
				_move_type = TRAJECTORY_LINEAR;
			}
		}
	} else if (_move_type == TRAJECTORY_ZIGZAG) {
        move_ahead(moved);
		if (check_map_colision(st_position(moved.width, moved.height)) == true) {
			status++;
			if (status > 3) {
				is_finished = true;
			} else {
				direction = !direction;
			}
		}
	} else if (_move_type == TRAJECTORY_FOLLOW && _target_position != NULL) {
		int xinc = 0;
		int yinc = 0;
		if (_target_position->x > position.x) {
			xinc = get_speed();
		} else if (_target_position->x < position.x) {
			xinc = -get_speed();
		}
		if (_target_position->y > position.y) {
			yinc = get_speed();
		} else if (_target_position->y < position.y) {
			yinc = -get_speed();
		}
        //std::cout << "TRAJECTORY_FOLLOW - xinc: " << xinc << ", yinc: " << yinc << ", x: " << position.x << ", y: " << position.y << std::endl;
		position.x += xinc;
		moved.width += xinc;
		position.y += yinc;
		moved.height += yinc;


        set_direction_from_xyinc(xinc, yinc); // change frame type depending on xinc/yinc


	} else if (_move_type == TRAJECTORY_FOLLOW && _target_position == NULL) {
		_move_type = TRAJECTORY_ZIGZAG;
    } else 	if ((_move_type == TRAJECTORY_TARGET_DIRECTION || _move_type == TRAJECTORY_TARGET_EXACT) && _target_position == NULL) { // if do not have a target, act as linear
        move_ahead(moved);
    } else if (_move_type == TRAJECTORY_PROGRESSIVE) { // move a bit each time the animation is reset
        if (animation_pos == 0) {
            position_to_ground();
            move_ahead(moved);
        }
        // gravity
    } else if (_move_type == TRAJECTORY_FALL_BOMB) {
        if (_effect_n == 0) {
            position.y += get_speed();
            // check if hit ground
            int point_lock = map->getMapPointLock(st_position(position.x/TILESIZE, position.y/TILESIZE));
            if (point_lock != TERRAIN_WATER && point_lock != TERRAIN_UNBLOCKED) { // hit ground, lets change to explosion
                //std::cout << "BOMB - TRANSFORM into explosion" << std::endl;
                /// morph into a bigger explosion
                _points = 5000;
                _effect_timer = timer.getTimer()+3600;

                _size.width = 56;
                _size.height = 56;
                position.x -= 28;
                position.y -= 48;
                _max_frames = get_surface()->width / _size.width;
                _effect_n++;
                soundManager.play_repeated_sfx(SFX_BIG_EXPLOSION, 3);
            }
        } else if (_effect_n == 1 && _effect_timer < timer.getTimer()) {
            is_finished = true;
        }

    } else {
        std::cout << "projectile::move - UNKNOWN TRAJECTORY #" << _move_type << std::endl;
	}

	realPosition.x = position.x - map->getMapScrolling().x;
	realPosition.y = position.y - map->getMapScrolling().y;
	// check out of screen
	if (_move_type != TRAJECTORY_FREEZE && _move_type != TRAJECTORY_QUAKE) { // special effect weapons can work out of screen
		if (realPosition.x > RES_W+TILESIZE*2 || realPosition.x < 0-TILESIZE*2 || realPosition.y > RES_H+TILESIZE*2 || realPosition.y < 0-+TILESIZE*2) {
			is_finished = true;
		}
	}
	return moved;
}

void projectile::draw() {
    if ((_move_type == TRAJECTORY_BOMB || _move_type == TRAJECTORY_FALL_BOMB) && _effect_n == 1) {
		graphLib.draw_explosion(realPosition);
		return;
	}

	if (_move_type == TRAJECTORY_QUAKE || _move_type == TRAJECTORY_FREEZE) { /// QTODO: freeze could use some "sparkling" effect
		//std::cout << "projectile::draw - invisible type" << std::endl;
		return;
	}

	if (animation_pos >= _max_frames) {
		//std::cout << "projectile::draw - RESET animation_pos" << std::endl;
		animation_pos = 0;
	}

    int anim_pos = animation_pos*_size.width;
    int show_width = _size.width;
    if (_move_type == TRAJECTORY_CHAIN) {
        show_width = abs(position.x - position0.x);
        if (show_width > _size.width) {
            show_width = _size.width;
        }
    }


    //std::cout << "projectile::draw - animation_pos: " << animation_pos << ", _max_frames: " << _max_frames << ", show_width: " << show_width << ", anim_pos: " << anim_pos << std::endl;


	if (direction == ANIM_DIRECTION_LEFT && get_surface()->height >= _size.height*2) {
        graphLib.showSurfaceRegionAt(get_surface(), st_rectangle(anim_pos, _size.height, show_width, _size.height), realPosition);
    } else if (direction == ANIM_DIRECTION_UP && get_surface()->height >= _size.height*3) {
        graphLib.showSurfaceRegionAt(get_surface(), st_rectangle(anim_pos, _size.height*2, show_width, _size.height), realPosition);
    } else if (direction == ANIM_DIRECTION_DOWN && get_surface()->height >= _size.height*4) {
        graphLib.showSurfaceRegionAt(get_surface(), st_rectangle(anim_pos, _size.height*3, show_width, _size.height), realPosition);
    } else if (direction == ANIM_DIRECTION_UP_LEFT && get_surface()->height >= _size.height*5) {
        graphLib.showSurfaceRegionAt(get_surface(), st_rectangle(anim_pos, _size.height*4, show_width, _size.height), realPosition);
    } else if (direction == ANIM_DIRECTION_UP_RIGHT && get_surface()->height >= _size.height*6) {
        graphLib.showSurfaceRegionAt(get_surface(), st_rectangle(anim_pos, _size.height*5, show_width, _size.height), realPosition);
    } else if (direction == ANIM_DIRECTION_DOWN_LEFT && get_surface()->height >= _size.height*7) {
        graphLib.showSurfaceRegionAt(get_surface(), st_rectangle(anim_pos, _size.height*6, show_width, _size.height), realPosition);
    } else if (direction == ANIM_DIRECTION_DOWN_LEFT && get_surface()->height >= _size.height*8) {
        graphLib.showSurfaceRegionAt(get_surface(), st_rectangle(anim_pos, _size.height*7, show_width, _size.height), realPosition);
    } else { // right is the default frame
        graphLib.showSurfaceRegionAt(get_surface(), st_rectangle(anim_pos, 0, show_width, _size.height), realPosition);
	}

	//std::cout << "projectile::draw - animation_timer: " << animation_timer << ", timer: " << timer.getTimer() << std::endl;
    if (animation_timer < timer.getTimer()) {
        animation_pos++;
		//std::cout << "projectile::draw - inc anim_pos to " << animation_pos << std::endl;
		animation_timer = timer.getTimer() + PROJECTILE_DEFAULT_ANIMATION_TIME;
	}
}

// TODO: width/height must come from editor instead of using graphLib.projectile_surface
bool projectile::check_colision(st_rectangle enemy_pos, st_position pos_inc) const
{
    if (_move_type == TRAJECTORY_QUAKE || _move_type == TRAJECTORY_FREEZE) {
        return false;
    }


	st_position p1, p2, p3, p4;
	st_position enemy1, enemy2, enemy3, enemy4;
	// point 1, top/left
	p1.x = position.x + pos_inc.x;
	p1.y = position.y + pos_inc.y;

	// ponto 2, baixo/esquerda
	p2.x = position.x + pos_inc.x;
	p2.y = position.y + pos_inc.y + _size.height;

	// ponto 3, topo/direita
	p3.x = position.x + pos_inc.x + _size.width;
	p3.y = position.y + pos_inc.y;

	// ponto 4, baixo/direita
	p4.x = position.x + pos_inc.x + _size.width;
	p4.y = position.y + pos_inc.y + _size.height;

	enemy1.x = enemy_pos.x;
	enemy1.y = enemy_pos.y;
	enemy2.x = enemy_pos.x + enemy_pos.w;
	enemy2.y = enemy_pos.y;
	enemy3.x = enemy_pos.x;
	enemy3.y = enemy_pos.y + enemy_pos.h;
	enemy4.x = enemy_pos.x + enemy_pos.w;
	enemy4.y = enemy_pos.y + enemy_pos.h;

	//std::cout << "projectile::check_colision - p1: " << p1.x << "." << p1.y << " p2: " << p2.x << "." << p2.y << " p3: " << p3.x << "." << p3.y << " p4: " << p4.x << "." << p4.y << std::endl;
	//std::cout << "projectile::check_colision - enemy1: " << enemy1.x << "." << enemy1.y << " enemy2: " << enemy2.x << "." << enemy2.y << " enemy3: " << enemy3.x << "." << enemy3.y << " enemy4: " << enemy4.x << "." << enemy4.y << std::endl << std::endl;

	/// check if any of the PROJECTILE points is inside NPC
	if (p1.x >= enemy1.x && p1.x <= enemy2.x && p1.y >= enemy1.y && p1.y <= enemy3.y) {
		//std::cout << "projectile::check_colision - HIT 1" << std::endl;
		return true;
	} else if (p2.x >= enemy1.x && p2.x <= enemy2.x && p2.y >= enemy1.y && p2.y <= enemy3.y) {
		//std::cout << "projectile::check_colision - HIT 2" << std::endl;
		return true;
	} else if (p3.x >= enemy1.x && p3.x <= enemy2.x && p3.y >= enemy1.y && p3.y <= enemy3.y) {
		//std::cout << "projectile::check_colision - HIT 3" << std::endl;
		return true;
	} else if (p4.x >= enemy1.x && p4.x <= enemy2.x && p4.y >= enemy1.y && p4.y <= enemy3.y) {
		//std::cout << "projectile::check_colision - HIT 4" << std::endl;
		return true;
	}
	// npc inside projectile
	if (p1.x >= enemy1.x && p1.x <= enemy2.x && p1.y <= enemy1.y && p2.y >= enemy2.y) {
		//std::cout << "projectile::check_colision - HIT 5" << std::endl;
		return true;
	}
	if (p3.x >= enemy1.x && p3.x <= enemy2.x && p3.y <= enemy1.y && p4.y >= enemy2.y) {
		//std::cout << "projectile::check_colision - HIT 6" << std::endl;
		return true;
	}
	//std::cout << "projectile::check_colision - missed" << std::endl;
	return false;
}

bool projectile::check_map_colision(st_position pos_inc) const
{
	int p_y[3];
	p_y[0] = position.y + pos_inc.y;
	p_y[1] = position.y + get_size().height/2 + pos_inc.y;
	p_y[2] = position.y + get_size().height + pos_inc.y;
	int p_x;
	if (direction == ANIM_DIRECTION_LEFT) {
		p_x = position.x + pos_inc.x;
	} else {
		p_x = position.x + get_size().width + pos_inc.x;
	}
    for (int i=0; i<3; i++) {
        int lock = map->getMapPointLock(st_position(p_x/TILESIZE, p_y[i]/TILESIZE));// map->map_tiles.tiles[p_x/TILESIZE][p_y[i]/TILESIZE].locked;
		if (lock != TERRAIN_UNBLOCKED && lock != TERRAIN_WATER) {
            //std::cout << ">> projectile::check_map_colision - point (" << p_x << ", " << p_y[i] << ") lock: " << lock << std::endl;
			return true;
		}
	}
	return false;
}


int projectile::get_direction() const
{
	return direction;
}

void projectile::reflect()
{
	if (direction == ANIM_DIRECTION_LEFT) {
		direction = ANIM_DIRECTION_RIGHT;
	} else {
		direction = ANIM_DIRECTION_LEFT;
	}
    if (((int)position.y)%2) {
		_move_type = TRAJECTORY_DIAGONAL_UP;
	} else {
		_move_type = TRAJECTORY_DIAGONAL_DOWN;
	}
	is_reflected = true;
	soundManager.play_sfx(SFX_SHOT_REFLECTED);
}

short projectile::get_move_type() const
{
    if (_id == -1) {
        return TRAJECTORY_LINEAR;
    }
    return game_data.projectiles[_id].trajectory;
}

void projectile::set_y(int sety)
{
	position.y = sety;
	position0.y = sety;
	position1.y = sety;
}

void projectile::consume_projectile()
{
	// non-consumable types and conditions
    int my_traj = get_trajectory();
    if (my_traj == TRAJECTORY_CHAIN || my_traj == TRAJECTORY_FREEZE) {
		return;
    } else if ((get_trajectory() == TRAJECTORY_BOMB || get_trajectory() == TRAJECTORY_FALL_BOMB) && _effect_n == 0) {
		return;
	}
	_points--;
	//std::cout << "projectile::consume_projectile - _points: " << _points << std::endl;
	if (_points <= 0) {
		is_finished = true;
	}
}

void projectile::set_weapon_id(short wpn_id)
{
	_weapon_id = wpn_id;
}

short projectile::get_weapon_id() const
{
	return _weapon_id;
}

short projectile::get_effect_n() const
{
    return _effect_n;
}

void projectile::set_owner_position(st_float_position *owner_position)
{
	_owner_position = owner_position;
}

void projectile::set_owner_direction(int *owner_direction)
{
	_owner_direction = owner_direction;
}
