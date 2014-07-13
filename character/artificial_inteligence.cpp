#include "artificial_inteligence.h"
#include "classmap.h"
#include <cmath>
#include <cstdlib>
#include "character/classplayer.h"

extern CURRENT_FILE_FORMAT::file_game game_data;
extern FREEZE_EFFECT_TYPES freeze_weapon_effect;

std::vector<character*> *artificial_inteligence::player_list=NULL;


artificial_inteligence::artificial_inteligence() :  walk_range(TILESIZE*6), target(NULL), speed_y(max_speed), acceleration_y(0.05), IA_type(0), is_ghost(false), _ai_timer(0), _ai_chain_n(0), _trajectory_parabola(NULL)
{
    _ghost_move_speed_reducer = 0;
    _auto_respawn = false;
    _did_shot = false;
    _reaction_state = 0;
    _reaction_type = 0;
    _last_jump_yinc = 0;
    _check_always_move_ahead = true;
    _initialized = false;
    _ai_state.main_status = 0;
    _ai_id = -1;
    _parameter = 0;
}


artificial_inteligence::~artificial_inteligence()
{

}

// ********************************************************************************************** //
// Find the nearest player and return a struct with distance and a reference to player            //
// ********************************************************************************************** //
struct_player_dist artificial_inteligence::dist_npc_players()
{
    int dist;
    struct struct_player_dist res;
    if (!map) {
        std::cout << "ERROR: trying to calc NPC-player distance before map pointer is set on NPC" << std::endl;
        graphLib.show_debug_msg("EXIT #A.01");
        exit(-1);
    }
    if (map->_player_list.size() == 0) {
        std::cout << "ERROR: trying to calc NPC-player distance before there is a player in the game or this NPC does not have set the player_list" << std::endl;
        graphLib.show_debug_msg("EXIT #01");
        exit(-1);
    }

    res.pObj = map->_player_list.at(0);
    dist = sqrt(pow((position.x - res.pObj->getPosition().x), 2) + pow((position.y - res.pObj->getPosition().y), 2));
    res.dist_xy.x = abs((float)position.x - res.pObj->getPosition().x);
    res.dist_xy.y = abs((float)position.y - res.pObj->getPosition().y);

    res.dist = dist;
    return res;

}




void artificial_inteligence::ground_damage_players()
{
    std::vector<classPlayer*>::iterator player_it;
	for (player_it=map->_player_list.begin(); player_it != map->_player_list.end(); player_it++) {
		// check if player is on ground
        st_float_position npc_pos = (*player_it)->getPosition();
		npc_pos.x = (npc_pos.x + (*player_it)->get_size().width/2)/TILESIZE;
        npc_pos.y = (npc_pos.y + (*player_it)->get_size().height)/TILESIZE;
        int lock = map->getMapPointLock(st_position(npc_pos.x, npc_pos.y));
        //std::cout << "ground_damage_players - NPC[" << (*player_it)->getName() << "].lock: " << lock << ", x: " << npc_pos.x << ", y: " << npc_pos.y << std::endl;
		if (lock == TERRAIN_UNBLOCKED || lock == TERRAIN_STAIR || lock == TERRAIN_WATER) {
			continue;
		} else {
            //std::cout << "&&&&&&&&&&&&& ground_damage_players - DAMAGING PLAYER[" << (*player_it)->getName() << "]" << std::endl;
            (*player_it)->damage(3, false);
		}
    }
}

bool artificial_inteligence::auto_respawn() const
{
    return _auto_respawn;
}


void artificial_inteligence::ia_action_jump_to_player()
{
    if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {
        //std::cout << "AI::ia_action_jump_to_player::INIT" << std::endl;
        _ai_state.sub_action_sub_status = IA_ACTION_STATE_INITIAL;
        struct_player_dist dist_npc_player = dist_npc_players();
        int px = dist_npc_player.pObj->getPosition().x + dist_npc_player.pObj->get_size().width/2;
        _dest_point.x = px - frameSize.width/2;
        _dest_point.y = dist_npc_player.pObj->getPosition().y + dist_npc_player.pObj->get_size().height;
        _ai_state.sub_status = IA_ACTION_STATE_EXECUTING;
    } else {
        ia_action_jump_to_point(st_position(_dest_point.x, _dest_point.y));
        if ( _ai_state.sub_action_sub_status == IA_ACTION_STATE_FINISHED) {
            //std::cout << "AI::ia_action_jump_to_player::FINISH" << std::endl;
             _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
        }
    }
}

void artificial_inteligence::ia_action_jump_to_point(st_position point)
{
    int xinc = 0;
    if (state.direction == ANIM_DIRECTION_LEFT) {
        xinc = -move_speed; /// @TODO - check collision against walls (will have to "fake" the x position to continue jump movement)
    } else {
        xinc = move_speed; /// @TODO - check collision against walls (will have to "fake" the x position to continue jump movement)
    }

    if (_ai_state.sub_action_sub_status == IA_ACTION_STATE_INITIAL) {
        //std::cout << "AI::ia_action_jump_to_point - START" << std::endl;
        int jump_dist = abs(position.x - point.x);
        if (jump_dist < TILESIZE/2) { // avoid too short jumps
            std::cout << "AI::ia_action_jump_to_point - jump is too short (" << jump_dist << ")" << std::endl;
            _ai_state.sub_action_sub_status = IA_ACTION_STATE_FINISHED;
            return;
        }
        if (position.x < point.x) {
            state.direction = ANIM_DIRECTION_RIGHT;
        } else {
            state.direction = ANIM_DIRECTION_LEFT;
        }
        if (xinc <= 0) {
            _trajectory_parabola = new trajectory_parabola(position.x - point.x);
        } else {
            _trajectory_parabola = new trajectory_parabola(point.x - position.x);
        }
        _ai_state.initial_position.x = position.x;
        _ai_state.initial_position.y = position.y;
        set_animation_type(ANIM_TYPE_JUMP);
        _ai_state.sub_action_sub_status = IA_ACTION_STATE_EXECUTING;
        _last_jump_yinc = 0;
        _ignore_gravity = true; // disable gravity
        _origin_point.x = 0; // used when can't move x to continue increasing value for the parabola method
    } else if (_ai_state.sub_action_sub_status == IA_ACTION_STATE_EXECUTING) {
        //std::cout << "AI::ia_action_jump_to_player - EXECUTE" << std::endl;


        bool can_move_x = test_change_position(xinc, 0);
        if (can_move_x == false) { // hit a wall, fall
            //std::cout << "AI::ia_action_jump_to_point - hit wall, start falling y axis only; Pos.y: " << position.y << std::endl;
            _origin_point.x += xinc;
            xinc = 0;
        }

        int new_x = abs((position.x + _origin_point.x) - _ai_state.initial_position.x);
        int new_y = _ai_state.initial_position.y - _trajectory_parabola->get_y_point(new_x);



        int yinc = position.y - new_y;
        if (abs(yinc) >= TILESIZE) {
            if (yinc > 0) {
                yinc = TILESIZE-1;
            } else {
                yinc = -(TILESIZE-1);
            }
        }
        if (yinc >= TILESIZE-1) { // never move more than tilesize, no matter if will change jump behavior or else you could end up out of screen
            yinc = TILESIZE-2;
        }

        position.x += xinc;
        bool can_move_y = false;
        can_move_y = test_change_position(0, yinc*-1);


        //std::cout << "xinc: " << xinc << std::endl;

        //std::cout << ">>>> AI::ia_action_jump_to_point - yinc: " << yinc << ", yinc: " << yinc << ", y: " << position.y << ", new_y: " << new_y << ", can_move_y: " << can_move_y << std::endl;


        // check hit-head when going up
        if (yinc > 0 && can_move_y == false) { // falling. @NOTE: y values are inverted, so > 0 meand going up and < 0 meand going down
            bool found_point = false;
            if (_last_jump_yinc > 0 || yinc != 0) {
                // reduce Y in case hit head
                for (int i=yinc*-1; i>0; i--) {
                    can_move_y = test_change_position(0, i);
                    if (can_move_y == true) {
                        std::cout << ">>>> AI::ia_action_jump_to_point - hit head, can-move-y with i[" << i << "] at pos.y[" << position.y << "]" << std::endl;
                        yinc = i;
                        found_point = true;
                        break;
                    }
                }
            }
            std::cout << ">>>> AI::ia_action_jump_to_point - hit head, found_point: " << found_point << std::endl;
            // ignore Y movement if can't move in this axis
            /// @TODO: increase X virtual position until the point the NPC starts falling
            if (found_point == false) {
                yinc = 0;
                //std::cout << ">>>> AI::ia_action_jump_to_point - search for parabole flex point" << std::endl;
                int temp_xinc = 1;
                if (state.direction == ANIM_DIRECTION_LEFT) {
                    temp_xinc = -1;
                }
                int temp_yinc = 1;

                //int new_x = abs((position.x + _origin_point.x) - _ai_state.initial_position.x);
                int temp_pos_x = new_x;


                while (true) { // search for the point when parabole changes signal
                    int temp_new_y = _ai_state.initial_position.y - _trajectory_parabola->get_y_point(temp_pos_x);
                    temp_yinc = position.y - temp_new_y;

                    //std::cout << "AI::jump_to_point - new_x: " << new_x << ", pos.y: " << position.y << ", temp_yinc: " << temp_yinc << ", temp_pos_x: " << temp_pos_x << ", temp_new_y: " << temp_new_y << std::endl;

                    if (temp_yinc >= 0) {
                        int temp_diff = position.x - temp_pos_x;
                        //std::cout << "found parabole flex point at x[" << temp_pos_x << "], pos.x[" << position.x << "]" << std::endl;
                        _origin_point.x += temp_diff;
                        break;
                    }
                    temp_pos_x += temp_xinc;
                }

                return;
            }
        }


        // check ground when falling
        if (yinc < 0 && can_move_y == false) { // falling. @NOTE: y values are inverted, so > 0 meand going up and < 0 meand going down
            //std::cout << ">>>> AI::ia_action_jump_to_point - hit ground" << std::endl;
            bool found_point = false;
            if (_last_jump_yinc > 0 || yinc != 0) {
                // reduce Y in case hit ground
                for (int i=yinc; i>=0; i--) {
                    can_move_y = test_change_position(0, i);
                    if (can_move_y == true) {
                        yinc = i;
                        found_point = true;
                        break;
                    }
                }
            }
            if (found_point == false) {
                //std::cout << "AI::ia_action_jump_to_point - FINISHED #3 (hit-ground)" << std::endl;
                if (_trajectory_parabola != NULL) {
                    delete _trajectory_parabola;
                }
                _ignore_gravity = false; // enable gravity
                _ai_state.sub_action_sub_status = IA_ACTION_STATE_FINISHED;
                set_animation_type(ANIM_TYPE_STAND);
                moveCommands.right = 0;
                moveCommands.left = 0;
                _ai_timer = timer.getTimer() + 500;
                if (xinc == 0) { // if didn't moved x, then must change AI to other action
                    std::cout << "AI::ia_action_jump_to_point - FINISHED #4 (hit-ground)" << std::endl;
                    _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
                }
                return;
            }
        }
        position.y -= yinc;
        _last_jump_yinc = yinc;
    }
}

void artificial_inteligence::ia_action_jump_to_random()
{
    if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {
        _ai_state.sub_action_sub_status = IA_ACTION_STATE_INITIAL;
        int dist = 0;
        int rand_x = 0;
        while (dist < TILESIZE*4) {
            rand_x = rand() % RES_W;
            dist = abs(position.x - rand_x);
        }
        _dest_point.x = rand() % RES_W;
        std::cout << "AI::ia_action_jump_to_random - INIT - _dest_point.x: " << _dest_point.x << std::endl;
        _dest_point.y = position.y;
        _ai_state.sub_status = IA_ACTION_STATE_EXECUTING;
    } else {
        ia_action_jump_to_point(st_position(_dest_point.x, _dest_point.y));
        if ( _ai_state.sub_action_sub_status == IA_ACTION_STATE_FINISHED) {
             _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
        }
    }
}

void artificial_inteligence::ia_action_jump_ahead()
{
    if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {
        //std::cout << "AI::ia_action_jump_ahead::INIT" << std::endl;
        if (state.direction == ANIM_DIRECTION_LEFT) {
            _origin_point.x = position.x - frameSize.width/2 - walk_range;
            _dest_point.x = position.x - TILESIZE*4;
        } else {
            _origin_point.x = position.x + frameSize.width/2 + walk_range;
            _dest_point.x = position.x + TILESIZE*4;
        }
        _ai_state.sub_action_sub_status = IA_ACTION_STATE_INITIAL;
        _dest_point.y = position.y;
        _ai_state.sub_status = IA_ACTION_STATE_EXECUTING;
    } else {
        ia_action_jump_to_point(st_position(_dest_point.x, _dest_point.y));
        if ( _ai_state.sub_action_sub_status == IA_ACTION_STATE_FINISHED) {
            // only stop when reached _origin_poin
            // check how much we need to jump yet
            if (abs(_origin_point.x - position.x) < TILESIZE*4) {
                //std::cout << "AI::ia_action_jump_ahead - FINISHED, dist: " << dist << std::endl;
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
                return;
            }
            //std::cout << "AI::ia_action_jump_ahead - new-jump, dist: " << dist << std::endl;
            if (state.direction == ANIM_DIRECTION_LEFT) {
                _dest_point.x = position.x - TILESIZE*4;
            } else {
                _dest_point.x = position.x + TILESIZE*4;
            }
            _ai_state.sub_action_sub_status = IA_ACTION_STATE_INITIAL;
        }
    }
}

void artificial_inteligence::ia_action_jump_once()
{
    if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {
        if (state.direction == ANIM_DIRECTION_LEFT) {
            _origin_point.x = position.x - frameSize.width/2 - walk_range;
            _dest_point.x = position.x - TILESIZE*4;
        } else {
            _origin_point.x = position.x + frameSize.width/2 + walk_range;
            _dest_point.x = position.x + TILESIZE*4;
        }
        _ai_state.sub_action_sub_status = IA_ACTION_STATE_INITIAL;
        _dest_point.y = position.y;
        _ai_state.sub_status = IA_ACTION_STATE_EXECUTING;
    } else {
        ia_action_jump_to_point(st_position(_dest_point.x, _dest_point.y));
        if (_ai_state.sub_action_sub_status == IA_ACTION_STATE_FINISHED) {
            std::cout << "AI::ia_action_jump_once::FINISHED" << std::endl;
            _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
        }
    }
}

void artificial_inteligence::ia_action_jump_to_roof()
{
	if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {
        set_animation_type(ANIM_TYPE_JUMP);
		_ai_state.sub_status = IA_ACTION_STATE_EXECUTING;
		int limit_y = 0;
		for (int y=position.y; y>=0; y--) {
			st_position new_pos(position.x/TILESIZE, (y)/TILESIZE);
			if (map->is_point_solid(new_pos) == true) {
				limit_y = y;
				break;
			}
		}
		_ai_state.secondary_position.y = limit_y;
		_ai_state.step = (limit_y - position.y)/max_speed;
        _ignore_gravity = true; // disable gravity
        speed_y = max_speed*2;
		return;
	}
	// @TODO: acceleration
	if (position.y > _ai_state.secondary_position.y) {
		ia_accelerate_up();
		//std::cout << ">> IA::ia_action_jump_to_roof << JUMPING - position.y: " << position.y << ", limit.y: " << ia_state.secondary_position.y << std::endl;
	} else {
		_ai_state.sub_status = IA_ACTION_STATE_FINISHED;
	}
}

void artificial_inteligence::ia_action_air_walk()
{

	if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {
		//std::cout << "artificial_inteligence::ia_action_air_walk - INITIALIZE" << std::endl;
        set_animation_type(ANIM_TYPE_WALK_AIR);
		_ai_state.sub_status = IA_ACTION_STATE_EXECUTING;
		struct_player_dist dist_npc_player = dist_npc_players();
		if (position.x < dist_npc_player.pObj->getPosition().x) {
			state.direction = ANIM_DIRECTION_RIGHT;
			_ai_state.secondary_position.x = position.x + dist_npc_player.dist_xy.x;
		} else {
			state.direction = ANIM_DIRECTION_LEFT;
			_ai_state.secondary_position.x = position.x - dist_npc_player.dist_xy.x;
		}
		//std::cout << "artificial_inteligence::ia_action_air_walk - dist:" << dist_npc_player.dist << std::endl;
	} else if (_ai_state.sub_status == IA_ACTION_STATE_EXECUTING) {
		//std::cout << "artificial_inteligence::ia_action_air_walk - EXECUTE" << std::endl;
		/// @TODO use move speed and reducer for last part
		if (state.direction == ANIM_DIRECTION_RIGHT) {
			position.x += move_speed;
		} else {
			position.x -= move_speed;
		}
		if ((state.direction == ANIM_DIRECTION_RIGHT && position.x >= _ai_state.secondary_position.x) || (state.direction == ANIM_DIRECTION_LEFT && position.x <= _ai_state.secondary_position.x)) {
			//std::cout << "artificial_inteligence::ia_action_air_walk - FINISH" << std::endl;
            set_animation_type(ANIM_TYPE_JUMP);
			_ai_state.sub_status = IA_ACTION_STATE_FINISHED;
		}
	}
}

void artificial_inteligence::ia_action_jump_fall()
{
    //std::cout << "******** artificial_inteligence::ia_action_jump_fall - speed_y: " << speed_y << std::endl;
	if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {
		_ai_state.sub_status = IA_ACTION_STATE_EXECUTING;
        speed_y = 5;
	} else if (_ai_state.sub_status == IA_ACTION_STATE_EXECUTING) {
		ia_accelerate_down();
		if (hit_ground() == true) {
            //std::cout << "artificial_inteligence::ia_action_jump_fall - FINISH" << std::endl;
            set_animation_type(ANIM_TYPE_STAND);
			_ai_state.sub_status = IA_ACTION_STATE_FINISHED;
			_ai_timer = timer.getTimer() + 1200;
            _ignore_gravity = false;
        }
	}
}

void artificial_inteligence::ia_action_quake_attack()
{
	if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {
		_ai_state.sub_status = IA_ACTION_STATE_EXECUTING;
		_ai_state.initial_position.x = 0;
	} else if (_ai_state.sub_status == IA_ACTION_STATE_EXECUTING) {
		//std::cout << "IA_STATE_QUAKE_ATTACK - ia_state.timer: EXEC" << std::endl;
		_ai_state.initial_position.x++;
		if (_ai_state.initial_position.x % 20) {
            graphLib.set_screen_adjust(st_position(-QUAKE_SCREEN_MOVE, 0));
			ground_damage_players();
		} else if (_ai_state.initial_position.x % 25) {
            graphLib.set_screen_adjust(st_position(QUAKE_SCREEN_MOVE, 0));
			ground_damage_players();
		}
		_ai_state.timer = timer.getTimer() + 500;
		if (_ai_state.initial_position.x > 200) {
			graphLib.set_screen_adjust(st_position(0, 0));
            set_animation_type(ANIM_TYPE_STAND);
			_ai_state.sub_status = IA_ACTION_STATE_FINISHED;
		}
	}
}

void artificial_inteligence::ia_accelerate_up()
{
	//std::cout << "ia_accelerate_up - 1.speed_y: " << std::fixed << speed_y << std::endl;
	speed_y -= speed_y*acceleration_y;
	//std::cout << "ia_accelerate_up - 2.speed_y: " << std::fixed << speed_y << std::endl;
    if (speed_y < 3) {
		//speed_y = acceleration_y;
        speed_y = 3;
    } else if (speed_y > max_speed*2) {
        speed_y = max_speed*2;
	}
	position.y -= speed_y;
	/// @TODO - adjustment when ground is near
}


void artificial_inteligence::ia_accelerate_down()
{
	//std::cout << "ia_accelerate_down - 1.speed_y: " << std::fixed << speed_y << std::endl;
    speed_y += speed_y*acceleration_y*4;
    //std::cout << "ia_accelerate_down - 2.speed_y: " << std::fixed << speed_y << ", max_speed: " << max_speed << std::endl;
	if (speed_y < 1) {
        speed_y = acceleration_y*4;
    } else if (speed_y > TILESIZE-1) {
        speed_y = TILESIZE-1;
	}
    // adjust fall to hit ground exactly on the point
    if (will_hit_ground(speed_y) == true) {
        for (int i=speed_y-1; i>=0; i--) {
            if (will_hit_ground(i-1) == false) {
                speed_y = i;
                break;
            }
        }
    }
	position.y += speed_y;
	/// @TODO - adjustment when ground is near
}



void artificial_inteligence::ia_set_destiny_point(st_position dest_point)
{
	_ai_state.initial_position.x = position.x;
	_ai_state.initial_position.y  = position.y;
	_ai_state.secondary_position.x = dest_point.x;
	_ai_state.secondary_position.y = dest_point.y;
	if (_ai_state.secondary_position.x < _ai_state.initial_position.x) {
		state.direction = ANIM_DIRECTION_LEFT;
	} else {
		state.direction = ANIM_DIRECTION_RIGHT;
	}
}

// walk until reaching a given X coordinate
// @TODO - jump if needed
void artificial_inteligence::ia_walk_to_position()
{
	// @TODO - if can't walk, change action to jump to player
	//if (!test_change_position(-move_speed, 0)) {

    bool finished = false;
	if (_ai_state.secondary_position.x < _ai_state.initial_position.x) {
		position.x -= move_speed;
		if (position.x <= _ai_state.secondary_position.x) {
			finished = true;
		}
	} else {
		position.x += move_speed;
		if (position.x >= _ai_state.secondary_position.x) {
			finished = true;
		}
	}
	if (finished == true) {
        set_animation_type(ANIM_TYPE_STAND);
		_ai_state.sub_status = IA_ACTION_STATE_FINISHED;
		state.move_timer = timer.getTimer() + 2000;
	}
}

void artificial_inteligence::ia_float_to_position()
{
	bool finished = false;
	int xinc = 0;
	int yinc = 0;
	bool reached_x = false;
	bool reached_y = false;


	if (_ai_state.secondary_position.x < _ai_state.initial_position.x) {
		if (position.x <= _ai_state.secondary_position.x) {
			xinc = 0;
		} else {
			xinc -= move_speed;
		}
	} else {
		if (position.x >= _ai_state.secondary_position.x) {
			xinc = 0;
		} else {
			xinc += move_speed;
		}
	}
	if (_ai_state.secondary_position.y < _ai_state.initial_position.y) {
		if (position.y <= _ai_state.secondary_position.y) {
			yinc = 0;
		} else {
			yinc -= move_speed;
		}
	} else {
		if (position.y >= _ai_state.secondary_position.y) {
			yinc = 0;
		} else {
			yinc += move_speed;
		}
	}


	if (test_change_position(xinc, 0) == false) {
		xinc = 0;
	}
	if (test_change_position(0, yinc) == false) {
		yinc = 0;
	}
	if (xinc == 0 && yinc == 0) { // both X and Y blocked, leave
		finished = true;
	} else {
		std::cout << "*** artificial_inteligence::ia_float_to_position - xinc: " << xinc << ", yinc: " << yinc << std::endl;
		position.x += xinc;
		position.y += yinc;
	}

	if (reached_x == true && reached_y == true) {
		finished = true;
	}
	// check if reached the point
	if (finished == true) {
        set_animation_type(ANIM_TYPE_STAND);
		_ai_state.sub_status = IA_ACTION_STATE_FINISHED;
		state.move_timer = timer.getTimer() + 2000;
	}
}

void artificial_inteligence::ia_dash()
{
	bool finished = false;
	if (_ai_state.secondary_position.x < _ai_state.initial_position.x) {
        position.x -= max_speed;
		if (position.x <= _ai_state.secondary_position.x) {
			finished = true;
		}
	} else {
        position.x += max_speed;
		if (position.x >= _ai_state.secondary_position.x) {
			finished = true;
		}
	}
	if (finished == true) {
        set_animation_type(ANIM_TYPE_STAND);
		_ai_state.sub_status = IA_ACTION_STATE_FINISHED;
		state.move_timer = timer.getTimer() + 2000;
	}
}




/*
 * OK - IA_STAND
  * OK - IA_FOLLOW
 * OK - IA_ZIGZAG
 * - IA_SIDETOSIDE: add a way so that walk-ahead only stops when hitting a wall, not by distance
 * OK - IA_BAT
 * OK - IA_ROOF_SHOOTER
 * OK - IA_GROUND_SHOOTER
 * OK - IA_SHOOT_AND_GO
 * OK - IA_FLY_ZIG_ZAG
 * OK - IA_BUTTERFLY
 * - IA_HORIZONTAL_GO_AHEAD: works, but when reaching point, does not turn back (must also add a way to ignore distance)
 * OK - IA_HORIZONTAL_TURN
 * OK - IA_FIXED_JUMPER
 * - IA_SIDE_SHOOTER
 * OK - IA_GHOST: add a way to pass walls
 * OK - IA_FISH
 * IA_DOLPHIN
 * IA_VERTICAL_ZIGZAG
 *
*/

void artificial_inteligence::execute_ai()
{
    if (_ai_id == -1) {
        _ai_id = game_data.game_npcs[_number].gravity_level;
        //std::cout << "AI::AI - _number: " << _number << ", _ai_id: " << _ai_id << std::endl;
        _current_ai_type = get_ai_type();
    }
    //std::cout << "AI::execute_ai::START[" << name << "]" << std::endl;
    if (_check_always_move_ahead == true) {
        _always_move_ahead = always_move_ahead();
        _check_always_move_ahead = false;
    }
    check_ai_reaction();
	if (timer.getTimer() < _ai_timer) {
		return;
	}
    //std::cout << "AI::execute_ai - _current_ai_type: " << _current_ai_type << ", _ai_state.sub_status: " << _ai_state.sub_status << std::endl;
	// check if action is finished
    if (_ai_state.sub_status == IA_ACTION_STATE_FINISHED) {
        //std::cout << "AI::execute_ai::FINISHED" << std::endl;
        if (_reaction_type == 0) {
            int delay = game_data.ai_types[game_data.game_npcs[_number].gravity_level].states[_ai_chain_n].go_to_delay;
            _ai_timer = timer.getTimer() + delay;
        } else {
            _ai_timer = timer.getTimer() + 200;
        }
        _ai_state.sub_status = IA_ACTION_STATE_INITIAL;
		define_ai_next_step();
    } else {
        execute_ai_step();
    }
}

void artificial_inteligence::check_ai_reaction()
{
    //std::cout << "AI::check_ai_reaction::START - hitPoints.current: " << hitPoints.current << std::endl;
    // check and reset state if needed
    if (_reaction_state == 1) {
        //std::cout << ">>>>> AI::check_ai_reaction - EXECUTING <<<<<" << std::endl;
        if (_ai_state.sub_status == IA_ACTION_STATE_FINISHED) {
            //std::cout << ">>>>> AI::check_ai_reaction - DONE <<<<<" << std::endl;
            _reaction_state = 0;
        }
        return; // do not check again if already executing
    }

    bool start_reaction = false;
    // near player
    struct_player_dist dist_players = dist_npc_players();
    if (dist_players.dist < TILESIZE*4 && game_data.game_npcs[_ai_id].sprites[ANIM_TYPE_TELEPORT][1].colision_rect.x >= 0) {
        //std::cout << ">>>>> AI::check_ai_reaction - NEAR - START!!! <<<<<" << std::endl;
        _reaction_type = 1;
        start_reaction = true;
    // hit
    } else if (_was_hit == true && game_data.game_npcs[_ai_id].sprites[ANIM_TYPE_TELEPORT][2].colision_rect.x >= 0) {
        //std::cout << ">>>>> AI::check_ai_reaction - HIT - START!!! <<<<<" << std::endl;
        _reaction_type = 2;
        start_reaction = true;
    // dead
    } else if (hitPoints.current <= 0 && game_data.game_npcs[_ai_id].sprites[ANIM_TYPE_TELEPORT][3].colision_rect.x >= 0) {
        //std::cout << ">>>>> AI::check_ai_reaction - DEAD - START!!! <<<<<" << std::endl;
        _reaction_type = 3;
        start_reaction = true;
    }

    _was_hit = false; // reset flag

    if (start_reaction == true) {

        // do not start a walk-reaction in middle air
        int react_type = game_data.game_npcs[_ai_id].sprites[ANIM_TYPE_TELEPORT][_reaction_type].colision_rect.x;
        //std::cout << "AI::check_ai_reaction - react_type: " << react_type << std::endl;
        if (react_type == AI_ACTION_WALK && hit_ground() == false && can_fly == false) {
            return;
        }
        _reaction_state = 1;
        _ai_state.sub_status = IA_ACTION_STATE_INITIAL;
        _ai_timer = timer.getTimer(); // start now, ignoring delay
        _current_ai_type = get_ai_type();
    }
}

void artificial_inteligence::define_ai_next_step()
{
    if (_initialized == false || game_data.ai_types[game_data.game_npcs[_number].gravity_level].states[_ai_chain_n].go_to == AI_ACTION_GOTO_CHANCE) { // CHANCE
        _initialized = true;
		int rand_n = rand() % 100;
        //std::cout << "AI::define_ai_next_step - CHANCE - rand_n: " << rand_n << std::endl;
        bool found_chance = false;
        int chance_sum = 0;
        for (int i=0; i<8; i++) {
            //std::cout << "[" << i << "].chance: " << game_data.ai_types[game_data.game_npcs[_number].gravity_level].states[i].chance << ", chance_sum: " << chance_sum << std::endl;
            chance_sum += game_data.ai_types[game_data.game_npcs[_number].gravity_level].states[i].chance;
            if (rand_n < chance_sum) {
                //std::cout << "AI::define_ai_next_step - FOUND CHANCE at [" << i << "]" << std::endl;
				_ai_chain_n = i;
				found_chance = true;
				break;
			}
		}
        if (found_chance == false) {
            //std::cout << "AI::define_ai_next_step - no chance found, use ZERO as default" << std::endl;
			_ai_chain_n = 0;
		}
	} else {
		_ai_chain_n = game_data.ai_types[game_data.game_npcs[_number].gravity_level].states[_ai_chain_n].go_to-1;
        //std::cout << "AI::define_ai_next_step FORCE NEXT - " << _ai_chain_n << std::endl;
    }
    _current_ai_type = get_ai_type();
    //std::cout << "AI::define_ai_next_step _ai_chain_n: " << _ai_chain_n << ", _current_ai_type: " << _current_ai_type << std::endl;
    _ai_state.sub_status = IA_ACTION_STATE_INITIAL;
}

/*
    AI_ACTION_WALK,
    AI_ACTION_FLY,
    AI_ACTION_JUMP,
    AI_ACTION_WAIT_UNTIL_PLAYER_IS_IN_RANGE,
    AI_ACTION_SAVE_POINT,
    AI_ACTION_SHOT_PROJECTILE_1,
    AI_ACTION_SHOT_PROJECTILE_2,
    AI_ACTION_SHOT_INVERT_PROJECTILE_1,
    AI_ACTION_AIR_WALK,
    AI_ACTION_FALL_TO_GROUND,
    AI_ACTION_TELEPORT,
    AI_ACTION_DASH,
    AI_ACTION_GRAB_WALL,
    AI_ACTION_SPAWN_NPC
*/

void artificial_inteligence::execute_ai_step()
{
    //std::cout << "artificial_inteligence::execute_ai_step[" << name << "] - _number: " << _number << ", _current_ai_type: " << _current_ai_type << std::endl;
	_ai_timer = timer.getTimer() + 20;
    if (_current_ai_type == AI_ACTION_WALK) {
        //std::cout << ">> AI:exec[" << name << "] WALK" << std::endl;
		execute_ai_step_walk();
    } else if (_current_ai_type == AI_ACTION_FLY) {
        execute_ai_step_fly();
    } else if (_current_ai_type == AI_ACTION_JUMP) {
        //std::cout << ">> AI:exec[" << name << "] JUMP <<" << std::endl;
        execute_ai_step_jump();
    } else if (_current_ai_type == AI_ACTION_WAIT_UNTIL_PLAYER_IS_IN_RANGE) {
        //std::cout << ">> AI:exec[" << name << "] WAIT_UNTIL_PLAYER_IS_IN_RANGE <<" << std::endl;
		execute_ai_action_wait_until_player_in_range();
    } else if (_current_ai_type == AI_ACTION_SAVE_POINT) {
        //std::cout << ">> AI:exec[" << name << "] SAVE_POINT <<" << std::endl;
    } else if (_current_ai_type == AI_ACTION_SHOT_PROJECTILE_1) {
        //std::cout << ">> AI:exec[" << name << "] SHOT_PROJECTILE_1 <<" << std::endl;
		execute_ai_action_trow_projectile(0, false);
    } else if (_current_ai_type == AI_ACTION_SHOT_PROJECTILE_2) {
        //std::cout << ">> AI:exec[" << name << "] SHOT_PROJECTILE_2 <<" << std::endl;
		execute_ai_action_trow_projectile(1, false);
    } else if (_current_ai_type == AI_ACTION_SHOT_INVERT_PROJECTILE_1) {
        //std::cout << ">> AI:exec[" << name << "] SHOT_INVERT_PROJECTILE_1 <<" << std::endl;
		execute_ai_action_trow_projectile(1, true);
    } else if (_current_ai_type == AI_ACTION_AIR_WALK) {
        //std::cout << ">> AI:exec[" << name << "] AIR_WALK <<" << std::endl;
        ia_action_air_walk();
    } else if (_current_ai_type == AI_ACTION_FALL_TO_GROUND) {
        //std::cout << ">> AI:exec[" << name << "] FALL_TO_GROUND <<" << std::endl;
        ia_action_jump_fall();
    } else if (_current_ai_type == AI_ACTION_TELEPORT) {
        //std::cout << ">> AI:exec[" << name << "] TELEPORT <<" << std::endl;
        ia_action_teleport();
    } else if (_current_ai_type == AI_ACTION_DASH) {
        //std::cout << ">> AI:exec[" << name << "] DASH <<" << std::endl;
        execute_ai_step_dash();
    } else if (_current_ai_type == AI_ACTION_GRAB_WALL) {
        //std::cout << ">> AI:exec[" << name << "] GRAB_WALL <<" << std::endl;
        execute_ai_step_jump_to_wall();
    } else if (_current_ai_type == AI_ACTION_SPAWN_NPC) {
        //std::cout << ">> AI:exec[" << name << "] SPAWN_NPC <<" << std::endl;
        execute_ai_step_spawn_npc();
    } else {
        std::cout << "********** AI number[" << _ai_id << "], pos[" << _ai_chain_n << "], _current_ai_type[" << _current_ai_type << "] - NOT IMPLEMENTED *******" << std::endl;
    }
}
//enum IA_TYPE_LIST { IA_FOLLOW, IA_ZIGZAG, IA_SIDETOSIDE, IA_BAT, IA_ROOF_SHOOTER, IA_GROUND_SHOOTER, IA_SHOOT_AND_GO, IA_FLY_ZIG_ZAG, IA_BUTTERFLY, IA_HORIZONTAL_GO_AHEAD, IA_HORIZONTAL_TURN, IA_FIXED_JUMPER, IA_SIDE_SHOOTER, IA_GHOST, IA_FISH, IA_DOLPHIN, IA_VERTICAL_ZIGZAG, IA_TYPES_COUNT };


/// @TODO - jump if needed
void artificial_inteligence::execute_ai_step_walk()
{
    short move_type = _parameter;
    _dest_point.y = position.y; // is not flying, keep the position

    //std::cout << "execute_ai_step_walk::EXEC - status: " << _ai_state.sub_status << ", move_type: " << move_type << std::endl;

	if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {

        //std::cout << "execute_ai_step_walk::INIT" << std::endl;

        // if not on ground and can't fly, leave
        if (hit_ground() == false && can_fly == false) {
            //std::cout << "**** AI::execute_ai_step_walk - INIT - can't walk on midair" << std::endl;
            _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            return;
        }

        //std::cout << "**** AI::execute_ai_step_walk - move_type: " << move_type << std::endl;

        if (move_type == AI_ACTION_WALK_OPTION_HORIZONTAL_TURN || move_type == AI_ACTION_WALK_OPTION_TURN_TO_PLAYER) {
            //std::cout << "AI::execute_ai_step_walk::init - TURN::INIT" << std::endl;
            if (state.animation_type != ANIM_TYPE_TURN) {
                //std::cout << "AI::execute_ai_step_walk::init - TURN - change animation to TURN" << std::endl;
                set_animation_type(ANIM_TYPE_TURN);
            }
        } else {
            if (move_type == AI_ACTION_WALK_OPTION_TO_PLAYER) {
                struct_player_dist dist_players = dist_npc_players();
                _dest_point = dist_players.pObj->getPosition();
            } else if (move_type == AI_ACTION_WALK_OPTION_HORIZONTAL_AHEAD) {
                if (state.direction == ANIM_DIRECTION_LEFT) {
                    _dest_point.x = position.x - frameSize.width/2 - walk_range;
                } else {
                    _dest_point.x = position.x + frameSize.width/2 + walk_range;
                }
            }
            set_animation_type(ANIM_TYPE_WALK);
        }

		_ai_state.sub_status = IA_ACTION_STATE_EXECUTING;
        //std::cout << ">>>>>>> artificial_inteligence::execute_ai_step_walk - direction" << state.direction << std::endl;
	} else {
        if (move_type == AI_ACTION_WALK_OPTION_HORIZONTAL_TURN) {
            //std::cout << "AI::execute_ai_step_walk::exec - TURN - direction: " << state.direction << std::endl;
            if (_is_last_frame == true) { // finished turn animation
                //std::cout << "AI::execute_ai_step_walk::exec - TURN - last frame - direction: " << state.direction << std::endl;
                if (state.direction == ANIM_DIRECTION_LEFT) {
                    state.direction = ANIM_DIRECTION_RIGHT; /// @TODO - turn if not facing the given direction
                } else {
                    state.direction = ANIM_DIRECTION_LEFT;
                }
                set_animation_type(ANIM_TYPE_WALK);
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            }
        } else if (move_type == AI_ACTION_WALK_OPTION_TURN_TO_PLAYER) {
            //std::cout << "AI_ACTION_WALK_OPTION_TURN_TO_PLAYER::EXEC" << std::endl;
            struct_player_dist dist_players = dist_npc_players();
            if (dist_players.pObj->getPosition().x > position.x) {
                state.direction = ANIM_DIRECTION_RIGHT;
            } else {
                state.direction = ANIM_DIRECTION_LEFT;
            }
            set_animation_type(ANIM_TYPE_WALK);
            _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
        } else {
            if (move_to_point(_dest_point, move_speed, 0, is_ghost) == true) {
                //std::cout << "AI::execute_ai_step_walk::exec - reached point or is blocked" << std::endl;
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            }
        }
    }
    last_execute_time = timer.getTimer() + 20;
}

void artificial_inteligence::execute_ai_action_wait_until_player_in_range()
{
	if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {
		_ai_state.sub_status = IA_ACTION_STATE_EXECUTING;
        set_animation_type(ANIM_TYPE_STAND);
	} else {
		struct_player_dist dist_players = dist_npc_players();
		int dist_player = abs((float)dist_players.pObj->getPosition().x - position.x);
		if (dist_player <= walk_range) {
			_ai_state.sub_status = IA_ACTION_STATE_FINISHED;
		}
	}
}

void artificial_inteligence::execute_ai_action_trow_projectile(unsigned short n, bool invert_direction)
{
    //std::cout << "AI::execute_ai_action_trow_projectile - BEGIN" << std::endl;

    //std::cout << "AI::execute_ai_action_trow_projectile[" << name << "]" << std::endl;

    // some projectile types are limited to one
    if (game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].trajectory == TRAJECTORY_CENTERED && projectile_list.size() > 0) {
        _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
        return;
    }

    // can't fire a player's targeted projectile if move_speed zero (can't turn) and facing the wrong side
    if (move_speed == 0 && (game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].trajectory == TRAJECTORY_ARC_TO_TARGET || game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].trajectory == TRAJECTORY_TARGET_DIRECTION || game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].trajectory == TRAJECTORY_TARGET_EXACT)) {
        struct_player_dist dist_players = dist_npc_players();
        if ((dist_players.pObj->getPosition().x > position.x && state.direction == ANIM_DIRECTION_LEFT) || (dist_players.pObj->getPosition().x < position.x && state.direction == ANIM_DIRECTION_RIGHT)) {
            _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            return;
        }
    }


    unsigned int max_shots = 3;
    if (game_data.game_npcs[_number].projectile_id[n] != -1) {
        max_shots = game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].max_shots;
    }
    if (projectile_list.size() >= max_shots) {
        //std::cout << "max_shots[" << game_data.game_npcs[_number].projectile_id[n] << "]: " << game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].max_shots << std::endl;
        _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
        return;
    }


	if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {
        //std::cout << "AI::execute_ai_action_trow_projectile - START, id: " << game_data.game_npcs[_number].projectile_id[n] << ", trajectory: " << game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].trajectory << std::endl;
        if (state.animation_type == ANIM_TYPE_WALK_AIR) {
            set_animation_type(ANIM_TYPE_JUMP_ATTACK);
        } else {
            set_animation_type(ANIM_TYPE_ATTACK);
        }
        // face player to shoot, if parameter is not shot-ahead-only
        if (move_speed > 0 && _parameter != AI_ACTION_SHOT_AHEAD) {
            //std::cout << "AI::execute_ai_action_trow_projectile - face player, walk_range: " << walk_range << std::endl;
            struct_player_dist dist_players = dist_npc_players();
            if (dist_players.pObj->getPosition().x > position.x) {
                state.direction = ANIM_DIRECTION_RIGHT;
            } else {
                state.direction = ANIM_DIRECTION_LEFT;
            }
        }
		state.animation_state = 0;
		state.animation_timer = 0;
		_ai_state.sub_status = IA_ACTION_STATE_EXECUTING;
        _did_shot = false;
	} else {
        //std::cout << "AI::execute_ai_action_trow_projectile - EXECUTE - _was_animation_reset: " << _was_animation_reset << std::endl;
        if (_was_animation_reset == true && _did_shot == true) {
            //std::cout << "AI::execute_ai_action_trow_projectile - FINISH" << std::endl;
			_ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            _did_shot = false;
            if (state.animation_type == ANIM_TYPE_WALK_AIR || state.animation_type == ANIM_TYPE_JUMP || state.animation_type == ANIM_TYPE_JUMP_ATTACK) {
                set_animation_type(ANIM_TYPE_JUMP);
            } else {
                set_animation_type(ANIM_TYPE_STAND);
            }
        } else if (_is_last_frame == true && _did_shot == false) { // only shoot when reached the last frame in animation attack
            //std::cout << "AI::execute_ai_action_trow_projectile - SHHHHHHHHHHHOOOOOOOOOOOT" << std::endl;
            st_position proj_pos;
            int proj_direction = state.direction;
            if (invert_direction == true) {
                proj_direction = !proj_direction;
            }
            if (proj_direction == ANIM_DIRECTION_LEFT) {
                proj_pos = st_position(position.x+TILESIZE/2, position.y+frameSize.height/2);
            } else {
                proj_pos = st_position(position.x+frameSize.width-TILESIZE*2, position.y+frameSize.height/2);
            }
            projectile_list.push_back(projectile(game_data.game_npcs[_number].projectile_id[n], proj_direction, proj_pos, map, is_player()));
            projectile &temp_proj = projectile_list.back();

            if (game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].trajectory == TRAJECTORY_CENTERED) {
                temp_proj.set_owner_direction(&state.direction);
                temp_proj.set_owner_position(&position);
            }

            if (game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].trajectory == TRAJECTORY_TARGET_DIRECTION || game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].trajectory == TRAJECTORY_TARGET_EXACT || game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].trajectory == TRAJECTORY_ARC_TO_TARGET || game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].trajectory == TRAJECTORY_FOLLOW) {
                if (!is_player() && map->_player_list.size() > 0) {
                    character* p_player = map->_player_list.at(0);
                    temp_proj.set_target_position(p_player->get_position_ref());
                }
            }

            _did_shot = true;
        }
	}
}

void artificial_inteligence::execute_ai_step_fly()
{
    // INITIALIZATION
	if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {
        if (_parameter == AI_ACTION_FLY_OPTION_TO_PLAYER) {
            _dest_point = position;
        } else if (_parameter == AI_ACTION_FLY_OPTION_TO_RANDOM_POINT) {
            int rand_x = rand() % RES_W;
            int rand_y = rand() % RES_H;
            _dest_point = st_position(rand_x, rand_y);
        } else if (_parameter == AI_ACTION_FLY_OPTION_HORIZONTAL_AHEAD) {
            if (state.direction == ANIM_DIRECTION_LEFT) {
                _dest_point.x = position.x - frameSize.width/2 - walk_range;
            } else {
                _dest_point.x = position.x + frameSize.width/2 + walk_range;
            }
        } else if (_parameter == AI_ACTION_FLY_OPTION_UP) {
            _dest_point.y = position.y - walk_range;
        } else if (_parameter == AI_ACTION_FLY_OPTION_DOWN) {
            _dest_point.y = position.y + walk_range;
        } else if (_parameter == AI_ACTION_FLY_OPTION_FALL) {
            _dest_point.y = RES_H + frameSize.height + 2;
        } else if (_parameter == AI_ACTION_FLY_OPTION_DRILL_DOWN) { // DRILL_DOWN is similar to move-down, but NPC is ghostly (can walk walls) and when on walls, move 1/4 of speed.Also, it randomizes its x point when restarted
            randomize_x_point(TILESIZE*2);
            _dest_point.y = RES_H + frameSize.height + TILESIZE;
            _ghost_move_speed_reducer = 4;
            walk_range = RES_H + TILESIZE*4;
            _auto_respawn = true;
        } else if (_parameter == AI_ACTION_FLY_OPTION_VERTICAL_CENTER) {
            _dest_point.y = RES_H/2 - frameSize.height/2;




        } else if (_parameter == AI_ACTION_FLY_OPTION_PLAYER_DIRECTION) {
            struct_player_dist dist_players = dist_npc_players();
            if (dist_players.pObj->getPosition().x < position.x) {
                state.direction = ANIM_DIRECTION_LEFT;
                _dest_point.x = position.x - walk_range;
            } else {
                state.direction = ANIM_DIRECTION_RIGHT;
                _dest_point.x = position.x + walk_range;
            }
            _dest_point.y = position.y;


        } else if (_parameter == AI_ACTION_FLY_OPTION_OPOSITE_WALL) {
            if (realPosition.x > RES_W/2) {
                state.direction = ANIM_DIRECTION_LEFT;
                _dest_point.x = position.x - walk_range;
            } else {
                state.direction = ANIM_DIRECTION_RIGHT;
                _dest_point.x = position.x + walk_range;
            }
            _dest_point.y = position.y;
            //std::cout << "AI::AI_ACTION_FLY_OPTION_OPOSITE_WALL - dest.x: " << _dest_point.x << ", dest.y: " << _dest_point.y << ", pos.x: " << position.x << ", pos.y: " << position.y << std::endl;
            _origin_point.x = position.x;
        } else if (_parameter == AI_ACTION_FLY_OPTION_OPOSITE_SHOOT_1) {
            if (realPosition.x + frameSize.width/2 > RES_W/2) {
                state.direction = ANIM_DIRECTION_LEFT;
                _dest_point.x = position.x - walk_range;
            } else {
                state.direction = ANIM_DIRECTION_RIGHT;
                _dest_point.x = position.x + walk_range;
            }
            _dest_point.y = position.y;
            _origin_point.x = position.x;
            _counter = 0;
        } else if (_parameter == AI_ACTION_FLY_OPTION_TO_PLAYER_X) {
            struct_player_dist dist_players = dist_npc_players();
            if (dist_players.pObj->getPosition().x < position.x) {
                state.direction = ANIM_DIRECTION_LEFT;
            } else {
                state.direction = ANIM_DIRECTION_RIGHT;
            }
            _dest_point.x = dist_players.pObj->getPosition().x;
            _dest_point.y = position.y;

        } else if (_parameter == AI_ACTION_FLY_OPTION_TO_PLAYER_Y) {
            struct_player_dist dist_players = dist_npc_players();
            _dest_point.x = position.x;
            _dest_point.y = dist_players.pObj->getPosition().y;
        } else if (_parameter == AI_ACTION_FLY_OPTION_ZIGZAG_AHEAD) {
            if (state.direction == ANIM_DIRECTION_LEFT) {
                _dest_point.x = position.x - frameSize.width/2 - walk_range;
            } else {
                _dest_point.x = position.x + frameSize.width/2 + walk_range;
            }
            _dest_point.y = position.y;
            _ai_state.initial_position.x = 0;
            _ai_state.initial_position.y = position.y;

        }

        set_animation_type(ANIM_TYPE_WALK);
		_ai_state.sub_status = IA_ACTION_STATE_EXECUTING;

    // EXECUTION
	} else {
        if (state.animation_type == ANIM_TYPE_TURN && have_frame_graphic(state.direction, state.animation_type, (state.animation_state+1)) == false) {
            //std::cout << "*************** artificial_inteligence::execute_ai_step_fly - reached last turn frame, reset to stand" << std::endl;
            set_animation_type(ANIM_TYPE_STAND);
            state.direction = !state.direction;
			_ai_state.sub_status = IA_ACTION_STATE_FINISHED;
			return;
		}

        if (_parameter == AI_ACTION_FLY_OPTION_HORIZONTAL_AHEAD) {
            //std::cout << "artificial_inteligence::execute_ai_step_fly - HORIZONTAL RIGHT" << std::endl;
            if (move_to_point(_dest_point, move_speed, 0, is_ghost) == true) {
                //std::cout << "AI::execute_ai_step_fly - HORIZONTAL RIGHT - FINISHED" << std::endl;
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            }
        } else if (_parameter == AI_ACTION_FLY_OPTION_HORIZONTAL_TURN) {
            if (state.animation_type != ANIM_TYPE_TURN) {
                //std::cout << "artificial_inteligence::execute_ai_step_fly - HORIZONTAL TURN" << std::endl;
                set_animation_type(ANIM_TYPE_TURN);
                state.animation_state = 0;
                distance.width = 0;
                state.animation_timer = timer.getTimer() + 200;
            }
        } else if (_parameter == AI_ACTION_FLY_OPTION_UP) {
			//std::cout << "artificial_inteligence::execute_ai_step_fly - UP" << std::endl;
            if (move_to_point(_dest_point, 0, move_speed, is_ghost) == true) {
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            }
        } else if (_parameter == AI_ACTION_FLY_OPTION_DOWN) {
            //std::cout << "artificial_inteligence::execute_ai_step_fly - DOWN - dest_point.y: " << _dest_point.y << std::endl;
            if (move_to_point(_dest_point, 0, move_speed, is_ghost) == true) {
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            }
        } else if (_parameter == AI_ACTION_FLY_OPTION_DRILL_DOWN) {
            bool res_move = move_to_point(_dest_point, 0, move_speed, true);
            if (res_move == true || position.y >= RES_H+TILESIZE) {
                position.y = -TILESIZE*2;
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
                //std::cout << "**** DRILL.FINISHED - move to initial position" << std::endl;
            }
        } else if (_parameter == AI_ACTION_FLY_OPTION_FALL) {
            //std::cout << "artificial_inteligence::execute_ai_step_fly - DOWN - dest_point.y: " << _dest_point.y << std::endl;
            if (move_to_point(_dest_point, 0, move_speed, is_ghost) == true) {
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            }
        } else if (_parameter == AI_ACTION_FLY_OPTION_TO_PLAYER) {
			struct_player_dist dist_players = dist_npc_players();
            if (dist_players.dist < TILESIZE/2) {
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            } else {
                if (move_to_point(dist_players.pObj->getPosition(), move_speed, move_speed, is_ghost) == true) {
                    _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
                }
            }
        } else if (_parameter == AI_ACTION_FLY_OPTION_TO_SAVED_POINT || _parameter == AI_ACTION_FLY_OPTION_TO_RANDOM_POINT) {
			//std::cout << "artificial_inteligence::execute_ai_step_fly - POINT" << std::endl;
            if (move_to_point(_dest_point, move_speed, move_speed, is_ghost) == true) {
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            }
        } else if (_parameter == AI_ACTION_FLY_OPTION_VERTICAL_CENTER) {
            if (move_to_point(_dest_point, 0, move_speed, is_ghost) == true) {
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            }
        } else if (_parameter == AI_ACTION_FLY_OPTION_PLAYER_DIRECTION) {
            //std::cout << "FLY_PLAYER_DIRECTION(EXEC) - dest.x: " << _dest_point.x << ", pos.x : " << position.x << std::endl;
            if (move_to_point(_dest_point, move_speed, 0, is_ghost) == true) {
                //std::cout << "FLY_PLAYER_DIRECTION(FINISH)" << std::endl;
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            }

        } else if (_parameter == AI_ACTION_FLY_OPTION_OPOSITE_WALL) {
            if (move_to_point(_dest_point, move_speed, 0, is_ghost) == true) {
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            }
        } else if (_parameter == AI_ACTION_FLY_OPTION_OPOSITE_SHOOT_1) {
            int dist = abs(position.x - _origin_point.x);
            if (dist > 120 * _counter) {
                _counter++;

                st_position proj_pos;
                int n = 0;
                int proj_direction = state.direction;
                if (proj_direction == ANIM_DIRECTION_LEFT) {
                    proj_pos = st_position(position.x+TILESIZE/2, position.y+frameSize.height/2);
                } else {
                    proj_pos = st_position(position.x+frameSize.width-TILESIZE*2, position.y+frameSize.height/2);
                }
                projectile_list.push_back(projectile(game_data.game_npcs[_number].projectile_id[n], proj_direction, proj_pos, map, is_player()));
                projectile &temp_proj = projectile_list.back();

                if (game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].trajectory == TRAJECTORY_CENTERED) {
                    temp_proj.set_owner_direction(&state.direction);
                    temp_proj.set_owner_position(&position);
                }

                if (game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].trajectory == TRAJECTORY_TARGET_DIRECTION || game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].trajectory == TRAJECTORY_TARGET_EXACT || game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].trajectory == TRAJECTORY_ARC_TO_TARGET || game_data.projectiles[game_data.game_npcs[_number].projectile_id[n]].trajectory == TRAJECTORY_FOLLOW) {
                    if (!is_player() && map->_player_list.size() > 0) {
                        character* p_player = map->_player_list.at(0);
                        temp_proj.set_target_position(p_player->get_position_ref());
                    }
                }

                _did_shot = true;
            }
            if (move_to_point(_dest_point, move_speed, move_speed, is_ghost) == true) {
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            }
        } else if (_parameter == AI_ACTION_FLY_OPTION_TO_PLAYER_X) {
            if (move_to_point(_dest_point, move_speed, 0, is_ghost) == true) {
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            }
        } else if (_parameter == AI_ACTION_FLY_OPTION_TO_PLAYER_Y) {
            if (move_to_point(_dest_point, 0, move_speed, is_ghost) == true) {
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            }
        } else if (_parameter == AI_ACTION_FLY_OPTION_ZIGZAG_AHEAD) {
            if (position.x != _dest_point.x) {
                if (_ai_state.initial_position.y == position.y) {
                        _dest_point.y = position.y - TILESIZE;
                } else if (position.y <= _ai_state.initial_position.y - TILESIZE) {
                    _dest_point.y = position.y + TILESIZE;
                }
            }

            if (move_to_point(_dest_point, move_speed, 2, is_ghost) == true) {
                //std::cout << "AI::execute_ai_step_fly - HORIZONTAL RIGHT - FINISHED" << std::endl;
                _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            }
        } else {
            std::cout << "AI::FLY(EXECUTE) - unknown parameter #" << _parameter << std::endl;
        }
    }
}

void artificial_inteligence::execute_ai_step_dash()
{
    if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {
        set_animation_type(ANIM_TYPE_SLIDE);
        _ai_state.sub_status = IA_ACTION_STATE_EXECUTING;
        if (_parameter == AI_ACTION_DASH_OPTION_LEFT) {
            _dest_point.x = position.x + frameSize.width/2 - walk_range;
            state.direction = ANIM_DIRECTION_LEFT;
        } else if (_parameter == AI_ACTION_DASH_OPTION_RIGHT) {
            _dest_point.x = position.x + frameSize.width/2 + walk_range;
            state.direction = ANIM_DIRECTION_RIGHT;
        } else if (_parameter == AI_ACTION_DASH_OPTION_TO_PLAYER) {
            struct_player_dist dist_players = dist_npc_players();
            if (dist_players.dist > 0) {
                state.direction = ANIM_DIRECTION_RIGHT;
            } else {
                state.direction = ANIM_DIRECTION_LEFT;
            }
            _dest_point.x = dist_players.pObj->getPosition().x;
            _dest_point.y = position.y;
            //std::cout << ">>>>>>>>> AI::execute_ai_step_dash - dest_point.x: " << _dest_point.x << ", position.x: " << position.x << std::endl;
        } else {
            _ai_state.sub_status = IA_ACTION_STATE_FINISHED; // unknown mode
            set_animation_type(ANIM_TYPE_STAND);
        }
    } else {
        //std::cout << "###### AI::execute_ai_step_dash - execute - dest_point.x: " << _dest_point.x << ", position.x: " << position.x << std::endl;
        if (move_to_point(_dest_point, max_speed, 0, is_ghost) == true || abs(_dest_point.x - position.x) < TILESIZE) {
            _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            set_animation_type(ANIM_TYPE_STAND);
        }
    }
    last_execute_time = timer.getTimer() + 20;
}

// returns false if can ove and true if blocked
bool artificial_inteligence::move_to_point(st_float_position dest_point, float speed_x, float speed_y, bool can_pass_walls)
{
    float xinc = 0;
    float yinc = 0;

    // invert direction if needed
    if (position.x > dest_point.x && state.direction != ANIM_DIRECTION_LEFT) {
        state.direction = ANIM_DIRECTION_LEFT;
    }
    if (position.x < dest_point.x && state.direction != ANIM_DIRECTION_RIGHT) {
        state.direction = ANIM_DIRECTION_RIGHT;
    }

    if (abs(dest_point.x - position.x) < speed_x) {
        speed_x = abs(dest_point.x - position.x);
    }
    if (abs(dest_point.y - position.y) < speed_y) {
        speed_y = abs(dest_point.y - position.y);
    }

    float block_speed_x = speed_x;
    float block_speed_y = speed_y;
    if (can_pass_walls == true) {
        if (_ghost_move_speed_reducer > 0 && speed_x != 0) {
            block_speed_x = speed_x/_ghost_move_speed_reducer;
            if ((int)block_speed_x == 0) {
                if (speed_x > 0) {
                    block_speed_x = 1;
                } else {
                    block_speed_x = -1;
                }
            }
        }
        if (_ghost_move_speed_reducer > 0 && speed_y != 0) {
            block_speed_y = speed_y/_ghost_move_speed_reducer;
            if ((int)block_speed_y == 0) {
                if (speed_y > 0) {
                    block_speed_y = 1;
                } else {
                    block_speed_y = -1;
                }
            }
        }
    }

    if (_ghost_move_speed_reducer > 0) {
        bool test_x_move = test_change_position(block_speed_x, 0);
        bool test_y_move = test_change_position(0, block_speed_y);


        if (test_x_move == false) {
            speed_x = block_speed_x;
        }
        if (test_y_move == false) {
            speed_y = block_speed_y;
        }
    }


    if (dest_point.x > position.x) {
        xinc = speed_x;
    } else if (dest_point.x < position.x) {
        xinc = -speed_x;
    }

    if (dest_point.y > position.y) {
        yinc = speed_y;
    } else if (dest_point.y < position.y) {
        yinc = -speed_y;
    }

    //std::cout << ">> AI::move_to_point - xinc: " << xinc << ", yinc: " << yinc << std::endl;

    // checking
    bool can_move_x = true;
    bool can_move_y = true;
    if (can_pass_walls == false) {
        can_move_x = test_change_position(xinc, 0);
        can_move_y = test_change_position(0, yinc);
    }




    if (xinc == 0 && yinc == 0) {
        return true;
    }


    // if is walking check for holes on the path
    int type = get_ai_type();



    // check that we are not in a infinite loop of walking, because if we do, we don't stop moving
    if (_always_move_ahead == false) {
        if (type == AI_ACTION_WALK && can_fly == false && can_move_x == true && xinc != 0 && yinc == 0) {
            st_position map_point(position.x/TILESIZE, (position.y + frameSize.height + 3)/TILESIZE);
            if (state.direction == ANIM_DIRECTION_RIGHT) {
                map_point.x = (position.x + frameSize.width)/TILESIZE;
            }
            int map_lock = map->getMapPointLock(map_point);
            //std::cout << "AI::move_to_point - HOLE check: " << map_lock << " - direction: " << state.direction << std::endl;
            if (map_lock == TERRAIN_UNBLOCKED || map_lock == TERRAIN_WATER) {
                //std::cout << "AI::move_to_point - HOLE AHEAD - direction: " << state.direction << std::endl;
                return true;
            }
        }
    // always ahead will try to jump over obstables checking them a whole TILE ahead of time
    } else if (xinc != 0) {
        int xinc2 = xinc + TILESIZE;
        if (xinc < 0) {
            xinc2 = xinc - TILESIZE;
        }

        st_position map_point_ahead((position.x+xinc2)/TILESIZE, (position.y + frameSize.height-2)/TILESIZE);
        int map_lock_ahead = map->getMapPointLock(map_point_ahead);
        st_position map_point_top((position.x+xinc2)/TILESIZE, (position.y - TILESIZE + frameSize.height-2)/TILESIZE);
        int map_lock_top = map->getMapPointLock(map_point_top);



        //std::cout << "pos.x/TILESIZE: " << (position.x/TILESIZE) << ", map_point_ahead.x: " << map_point_ahead.x << ", map_point_ahead.y: " << map_point_ahead.y << ", map_lock_ahead: " << map_lock_ahead << ", map_lock_top: " << map_lock_top << std::endl;
        if (hit_ground() == true && speed_y == 0 && speed_x != 0) { // check if is trying to move on X axis only
            if ((map_lock_ahead != TERRAIN_WATER && map_lock_ahead != TERRAIN_UNBLOCKED) && (map_lock_top == TERRAIN_WATER || map_lock_top == TERRAIN_UNBLOCKED)) { // check that the terrain over the block is free
                std::cout << ">> AI::move_to_point - TRY TO JUMP <<" << std::endl;
                /// @TODO - implement have a way to change AI type only for a short period then return to the current one
                _current_ai_type = AI_ACTION_JUMP;
                _parameter = AI_ACTION_JUMP_OPTION_ONCE;
                _ai_state.sub_status = IA_ACTION_STATE_INITIAL;
                _ai_state.main_status = 0;
                return false;
            }
        }
    }

    if ((can_move_x == false && can_move_y == false) || (can_move_x == false && yinc == 0) || (can_move_y == false && xinc == 0)) {
        return true;
    } else {
        if (can_move_x == true) {
            //std::cout << ">> artificial_inteligence::move_to_point - xinc" << std::endl;
            position.x += xinc;
        }
        if (can_move_y == true) {
            position.y += yinc;
        }
    }
    return false;
}

void artificial_inteligence::randomize_x_point(int max_adjust)
{
    int rand_x = rand() % max_adjust*2;
    //std::cout << ">>artificial_inteligence::randomize_x_point - max_adjust: " << max_adjust << ", start_point.x: " << start_point.x << ", rand_x: " << rand_x << std::endl;
    position.x = position.x + rand_x - max_adjust;
}

int artificial_inteligence::create_rand_x_point(int max_range)
{
    bool keep_going = true;
    int rand_x = 0;
    int scroll_x = map->getMapScrolling().x;
    while (keep_going) {
        rand_x = position.x + rand() % max_range*2 - max_range;
        if (rand_x < scroll_x+TILESIZE || rand_x+frameSize.width > scroll_x+RES_W-TILESIZE) {
            continue;
        }
        int point_lock = map->getMapPointLock(st_position((rand_x+frameSize.width/2)/TILESIZE, (position.y+frameSize.height/2)/TILESIZE));
        if (point_lock == TERRAIN_WATER || point_lock == TERRAIN_UNBLOCKED) {
            keep_going = false;
        }
    }
    return rand_x;
}

int artificial_inteligence::create_rand_y_point(int max_range)
{
    bool keep_going = true;
    int rand_y = 0;
    while (keep_going) {
        rand_y = position.y + rand() % max_range*2 - max_range;
        if (rand_y < 0 || rand_y+frameSize.height > RES_H-TILESIZE) {
            continue;
        }
        int point_lock = map->getMapPointLock(st_position((position.x+frameSize.width/2)/TILESIZE, (rand_y+frameSize.height/2)/TILESIZE));
        if (point_lock == TERRAIN_WATER || point_lock == TERRAIN_UNBLOCKED) {
            keep_going = false;
        }
    }
    return rand_y;
}

st_position artificial_inteligence::create_rand_point(int max_range)
{
    bool keep_going = true;
    int rand_x = 0;
    int rand_y = 0;
    int scroll_x = map->getMapScrolling().x;
    while (keep_going) {
        rand_x = position.x + rand() % max_range*2 - max_range;
        rand_y = position.y + rand() % max_range*2 - max_range;
        // TODO: check if new position X is out of visible screen
        if (rand_x < scroll_x+TILESIZE || rand_x+frameSize.width > scroll_x+RES_W-TILESIZE) {
            continue;
        }

        // check if new position Y is out of visible screen
        if (rand_y < 0 || rand_y+frameSize.height > RES_H-TILESIZE) {
            continue;
        }
        int point_lock = map->getMapPointLock(st_position((rand_x+frameSize.width/2)/TILESIZE, (rand_y+frameSize.height/2)/TILESIZE));
        if (point_lock == TERRAIN_WATER || point_lock == TERRAIN_UNBLOCKED) {
            keep_going = false;
        }
    }
    return st_position(rand_x, rand_y);
}

void artificial_inteligence::execute_ai_step_jump()
{
    //std::cout << "AI::execute_ai_step_jump" << std::endl;
/*
enum AI_ACTION_JUMP_OPTION_LIST {
    AI_ACTION_JUMP_OPTION_LEFT,
    AI_ACTION_JUMP_OPTION_RIGHT,
    AI_ACTION_JUMP_OPTION_UP,
    AI_ACTION_JUMP_OPTION_TO_PLAYER,
    AI_ACTION_JUMP_OPTION_TO_ROOF,
    AI_ACTION_JUMP_OPTION_TO_SAVED_POINT };
*/
    if (_parameter == AI_ACTION_JUMP_OPTION_TO_ROOF) {
        ia_action_jump_to_roof();
    } else if (_parameter == AI_ACTION_JUMP_OPTION_TO_PLAYER) {
        ia_action_jump_to_player();
    } else if (_parameter == AI_ACTION_JUMP_OPTION_AHEAD) {
        ia_action_jump_ahead();
    } else if (_parameter == AI_ACTION_JUMP_OPTION_TO_RANDOM_POINT) {
        ia_action_jump_to_random();
    } else if (_parameter == AI_ACTION_JUMP_OPTION_ONCE) {
        ia_action_jump_once();
    } else {
        std::cout << "*********** artificial_inteligence::execute_ai_step_jump - extra-parameter _parameter[" << _parameter << "] not implemented ******" << std::endl;
    }

}

int artificial_inteligence::find_wall(float initial_x, int direction)
{
    int ini_x = initial_x / TILESIZE;
    int pos_x = -1;
    if (direction == ANIM_DIRECTION_LEFT) {
        pos_x = map->get_first_lock_on_left(ini_x);
    } else {
        pos_x = map->get_first_lock_on_right(ini_x);
    }
    std::cout << "AI::find_wall - pos_x: " << pos_x << std::endl;
    return pos_x;
}





void artificial_inteligence::execute_ai_step_jump_to_wall()
{
    if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {
        std::cout << "AI::execute_ai_step_jump_to_wall - INIT" << std::endl;
        struct_player_dist dist_players = dist_npc_players();
        if (dist_players.pObj->getPosition().x > position.x) {
            std::cout << "AI::execute_ai_step_jump_to_wall - face RIGHT" << std::endl;
            state.direction = ANIM_DIRECTION_RIGHT;
        } else {
            std::cout << "AI::execute_ai_step_jump_to_wall - face LEFT" << std::endl;
            state.direction = ANIM_DIRECTION_LEFT;
        }
        int pos_x = find_wall(position.x, state.direction);
        if (pos_x == -1) { // no wall found to grab
            std::cout << "AI::execute_ai_step_jump_to_wall - no wall found" << std::endl;
            _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
        }
        _dest_point.x = pos_x;
        _dest_point.y = RES_H/2;

        int dist_x = _dest_point.x - position.x;
        int dist_y = _dest_point.y - position.y;
        _diagonal_speed.x = move_speed*2;
        _diagonal_speed.y = (_diagonal_speed.x * dist_y) / dist_x;
        std::cout << ">>>>> AI::execute_ai_step_jump_to_wall - dist_x: " << dist_x << ", _diagonal_speed.x: " << _diagonal_speed.x << ", _diagonal_speed.y: " << _diagonal_speed.y << std::endl;
        if (_diagonal_speed.y < 0) { // move_to_point always use positive values, and adjust depending on target itself
            _diagonal_speed.y = _diagonal_speed.y * -1;
        }
        _ignore_gravity = true; // disable gravity
        _ai_state.sub_status = IA_ACTION_STATE_EXECUTING;
        set_animation_type(ANIM_TYPE_JUMP);
        state.animation_state = 0;
    } else if (_ai_state.sub_status == IA_ACTION_STATE_EXECUTING) {
        if (move_to_point(_dest_point, _diagonal_speed.x, _diagonal_speed.y, is_ghost) == true) {
            std::cout << ">>>>> AI::execute_ai_step_jump_to_wall - FINISHED" << std::endl;
            state.animation_state = 0;
            set_animation_type(ANIM_TYPE_WALK_AIR);
            _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            state.direction = !state.direction;
        }
    }
}


void artificial_inteligence::execute_ai_step_spawn_npc()
{
    if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {
        if (state.animation_type == ANIM_TYPE_JUMP) {
            set_animation_type(ANIM_TYPE_JUMP_ATTACK);
        } else {
            set_animation_type(ANIM_TYPE_ATTACK);
        }
        classnpc* temp;
        if (name == "Top Hat") {
            temp = map->spawn_map_npc(_parameter, st_position(position.x, position.y), state.direction, false, true);
        } else {
            temp = map->spawn_map_npc(_parameter, st_position(position.x, position.y+frameSize.height/2), state.direction, false, false);
        }
        // is executing reaction and is dying and is map-boss -> set child as new map-boss
        if (_reaction_state == 1 && _reaction_type == 3 && _is_stage_boss == true) {
            _is_stage_boss = false;
            temp->set_stage_boss(true);
        }
        _ai_state.sub_status = IA_ACTION_STATE_EXECUTING;
    } else {
        _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
    }
}

void artificial_inteligence::ia_action_teleport()
{
    // go teleporting
    if (_ai_state.sub_status == IA_ACTION_STATE_INITIAL) {
        if (state.animation_type != ANIM_TYPE_SPECIAL_ATTACK) { /// @TODO - must use teleport
            //std::cout << ">> AI::ia_action_teleport(INIT) - ANIM_TYPE_SPECIAL_ATTACK <<" << std::endl;
            set_animation_type(ANIM_TYPE_SPECIAL_ATTACK);
        } else {
            if (_was_animation_reset == true) { // finished special_attack animation
                //std::cout << ">> AI::ia_action_teleport(INIT) - CHANGE TO EXEC - animation_state: " << state.animation_state << ", animation_type: " << state.animation_type << std::endl;
                _ai_state.sub_status = IA_ACTION_STATE_EXECUTING;
                state.invisible = true;
                if (_parameter == AI_ACTION_TELEPORT_OPTION_LEFT) {
                    position.x -= walk_range;
                } else if (_parameter == AI_ACTION_TELEPORT_OPTION_RIGHT) {
                    position.x += walk_range;
                } else if (_parameter == AI_ACTION_TELEPORT_OPTION_TO_PLAYER) {
                    struct_player_dist dist_npc_player = dist_npc_players();
                    position.x = dist_npc_player.pObj->getPosition().x;
                } else if (_parameter == AI_ACTION_TELEPORT_OPTION_RANDOM_X) {
                    //std::cout << "#1 - AI::AI_ACTION_TELEPORT_OPTION_RANDOM_X - x: " << position.x << std::endl;
                    position.x = create_rand_x_point(walk_range);
                    //std::cout << "#2 - AI::AI_ACTION_TELEPORT_OPTION_RANDOM_X - x: " << position.x << std::endl;
                } else if (_parameter == AI_ACTION_TELEPORT_OPTION_RANDOM_Y) {
                    //std::cout << "#1 - AI::AI_ACTION_TELEPORT_OPTION_RANDOM_Y - y: " << position.x << std::endl;
                    position.y = create_rand_y_point(walk_range);
                    //std::cout << "#2 - AI::AI_ACTION_TELEPORT_OPTION_RANDOM_Y - y: " << position.x << std::endl;
                } else if (_parameter == AI_ACTION_TELEPORT_OPTION_RANDOM_POINT) {
                    //std::cout << "#1 - AI::AI_ACTION_TELEPORT_OPTION_RANDOM_POINT- x: " << position.x << ", y: " << position.y << std::endl;
                    position = create_rand_point(walk_range);
                    //std::cout << "#2 - AI::AI_ACTION_TELEPORT_OPTION_RANDOM_POINT - x: " << position.x << ", y: " << position.y << std::endl;
                } else {
                    std::cout << "AI::TELEPORT  unknown parameter #" << _parameter << std::endl;
                }
                _ai_timer = timer.getTimer() + 600;
                _was_animation_reset = false;
                _ignore_gravity = true;
                state.animation_state = 0;
            }
        }
    // return from teleporting
    } else {
        if (state.invisible == true) {
            //std::cout << ">> AI::ia_action_teleport - EXEC - MAKE VISIBLE  - animation_type: " << state.animation_type << " <<" << std::endl;
            state.invisible = false;
            state.animation_inverse = true;
            advance_to_last_frame(); // always call this once setting animation_inverse to true to avoid false _was_animation_reset
        }
        if (_was_animation_reset == true) {
            //std::cout << ">> AI::ia_action_teleport - FINISH <<" << std::endl;
            set_animation_type(ANIM_TYPE_STAND);
            _ai_state.sub_status = IA_ACTION_STATE_FINISHED;
            _ignore_gravity = false;
            state.animation_inverse = false;
        }
    }
}


int artificial_inteligence::get_ai_type() {
    int type = -1;

    if (_reaction_state == 0) {
        type = game_data.ai_types[_ai_id].states[_ai_chain_n].action;
        _parameter = game_data.ai_types[_ai_id].states[_ai_chain_n].extra_parameter;
        //std::cout << ">> AI::get_ai_type - _ai_id: " << _ai_id << ", _ai_chain_n: " << _ai_chain_n << ", action: " << type << ", extra_parameter: " << _parameter << std::endl;
    } else {
        type = game_data.game_npcs[_ai_id].sprites[ANIM_TYPE_TELEPORT][_reaction_type].colision_rect.x;
        _parameter = game_data.game_npcs[_ai_id].sprites[ANIM_TYPE_TELEPORT][_reaction_type].colision_rect.y;
        //std::cout << ">> AI::execute_ai_step - REACTION-MODE - _ai_id: " << _ai_id << ", _reaction_type: " << _reaction_type << ", type: " << type << ", _parameter: " << _parameter << std::endl;
    }
    return type;
}

bool artificial_inteligence::always_move_ahead() const
{
    if (game_data.ai_types[game_data.game_npcs[_number].gravity_level].states[_ai_chain_n].go_to-1 == _ai_chain_n) {
        return true;
    }
    return false;
}
