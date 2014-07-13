#include <cstdlib>
#include <sstream>
#include "classnpc.h"
#include "graphicslib.h"
#include "stage.h"
#include "classplayer.h"
#include "classmap.h"
#include <math.h>
#include <string.h>

#include "inputlib.h"
extern inputLib input;


extern std::string FILEPATH;

extern CURRENT_FILE_FORMAT::file_game game_data;
extern CURRENT_FILE_FORMAT::file_stage stage_data;

extern FREEZE_EFFECT_TYPES freeze_weapon_effect;
extern int freeze_weapon_id;

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
classnpc::classnpc() : graphic_filename(), first_run(true), _is_player_friend(false)
{
	add_graphic();
	hit_duration = 500;
	clean_projectiles();
    facing = 0;
    _is_spawn = false;
}



classnpc::classnpc(int stage_id, int map_id, int main_id, int id) : _is_player_friend(false) // map-loaded npc
{
    build_basic_npc(stage_id, map_id, main_id);
    facing = stage_data.maps[map_id].map_npcs[id].direction;
    state.direction = facing;
    start_point.x = stage_data.maps[map_id].map_npcs[id].start_point.x * TILESIZE;
    start_point.y = stage_data.maps[map_id].map_npcs[id].start_point.y * TILESIZE;
    position.x = start_point.x;
    position.y = start_point.y;
    _is_spawn = false;
}

classnpc::classnpc(int stage_id, int map_id, int main_id, st_position npc_pos, short int direction, bool player_friend) // spawned npc
{
    build_basic_npc(stage_id, map_id, main_id);
    _is_player_friend = player_friend;
    facing = direction;
    state.direction = direction;
    start_point.x = npc_pos.x;
    start_point.y = npc_pos.y;
    position.x = npc_pos.x;
    position.y = npc_pos.y;
    _is_spawn = true;
}




// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
classnpc::classnpc(std::string set_name) : graphic_filename(), first_run(true), _is_player_friend(false)
{
	name = set_name;
	hit_duration = HIT_BLINK_ANIMATION_LAPSE;
	add_graphic();
    facing = 0;
    _is_spawn = false;
}


// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
classnpc::~classnpc()
{
}

void classnpc::build_basic_npc(int stage_id, int map_id, int main_id)
{
    UNUSED(stage_id);
    UNUSED(map_id);
    //std::cout << "classnpc::build_basic_npc" << std::endl;
	_number = main_id;
	// TODO - usar operador igual e também para cópia de toda a classe para ela mesma
	graphicsLib_gSurface npc_sprite_surface;


	//std::cout << "NPC 1 - stage_id: " << stage_id << ", map_id: " << map_id << ", main_id: " << main_id << ", id: " << id << std::endl;

    name = std::string(game_data.game_npcs[main_id].name);

	add_graphic();



	// set sprites to be persistent. they will be freed only by game.cpp
	for (int i=0; i<ANIM_DIRECTION_COUNT; i++) {
		for (int j=0; j<ANIM_TYPE_COUNT; j++) {
			for (int k=0; k<ANIM_FRAMES_COUNT; k++) {
				(character_graphics_list.find(name)->second)[i][j][k].frameSurface.persistent = true;
			}
		}
	}



	hitPoints.total = game_data.game_npcs[main_id].hp.total;
	hitPoints.current = hitPoints.total;

	if (state.direction < 0 || state.direction > ANIM_DIRECTION_COUNT) {
		state.direction = ANIM_DIRECTION_RIGHT;
	}

	move_speed = game_data.game_npcs[main_id].speed;
	walk_range = game_data.game_npcs[main_id].walk_range;
	if (walk_range < 0 || walk_range > 1000) { // fix data errors by setting value to default
		walk_range = TILESIZE*6;
	}



	graphic_filename = game_data.game_npcs[main_id].graphic_filename;


	frameSize.width = game_data.game_npcs[main_id].frame_size.width;
    frameSize.height = game_data.game_npcs[main_id].frame_size.height;
    is_ghost = (game_data.game_npcs[main_id].is_ghost != 0);
	shield_type = game_data.game_npcs[main_id].shield_type;
	_is_boss = false;

	IA_type = game_data.game_npcs[main_id].IA_type;


    // TODO - this logic can be passed to the editor
    if (game_data.game_npcs[main_id].fly_flag != 0) {
        //std::cout << "******** classnpc::set_file_data - npc: " << name << ", canfly: " << can_fly << std::endl;
        can_fly = true;
    }
    _projectile_type_id = game_data.game_npcs[main_id].projectile_id[0];

	realPosition.x = 0;
	realPosition.y = 0;

	max_jump = 20;					// hardcoded, fix this in editor
	max_projectiles = 1;			// hardcoded, fix this in editor
	//move_speed = 6;					// hardcoded, fix this in editor
	attack_state = 0;
	last_execute_time = 0;


	// only add graphics if there is no graphic for this NPC yet
	if (have_frame_graphics() == false) {
		// load the graphic from file and set it into frameset


        std::string temp_filename = FILEPATH + "data/images/sprites/enemies/" + graphic_filename;
        //printf(">> temp_filename: '%s'\n", temp_filename.c_str());

        graphLib.surfaceFromFile(temp_filename, &npc_sprite_surface);
		if (npc_sprite_surface.gSurface == NULL) {
			std::cout << "initFrames - Error loading player surface from file\n";
			return;
		}

        // @204
        for (int i=0; i<ANIM_TYPE_COUNT; i++) {
            for (int j=0; j<ANIM_FRAMES_COUNT; j++) {
                if (game_data.game_npcs[main_id].sprites[i][j].used == true) {
                    //void character::addSpriteFrame(int anim_direction, int anim_type, int posX, int posY, graphicsLib_gSurface &spritesSurface, int delay)
                    addSpriteFrame(ANIM_DIRECTION_LEFT, i, game_data.game_npcs[main_id].sprites[i][j].sprite_graphic_pos_x, 0, npc_sprite_surface, game_data.game_npcs[main_id].sprites[i][j].duration);
                    if (npc_sprite_surface.height < game_data.game_npcs[main_id].frame_size.height*2) {
                        _character_have_right_graphic.insert(std::pair<std::string, bool>(name, false));
                        _have_right_direction_graphics = false;
                    } else {
                        _character_have_right_graphic.insert(std::pair<std::string, bool>(name, true));
                        addSpriteFrame(ANIM_DIRECTION_RIGHT, i, game_data.game_npcs[main_id].sprites[i][j].sprite_graphic_pos_x, 1, npc_sprite_surface, game_data.game_npcs[main_id].sprites[i][j].duration);
                    }
                }
            }
        }
    } else {
        _have_right_direction_graphics = _character_have_right_graphic.find(name)->second;
        //std::cout << "$$$$$$$ NPC (" << name << ") - _have_right_direction_graphics: " << _have_right_direction_graphics << std::endl;
    }


    if (have_background_graphics() == false) {
        graphicsLib_gSurface bg_surface;
        std::string bg_filename(game_data.game_npcs[main_id].bg_graphic_filename);
        //std::cout << ">>>>>>>>> NPC[" << name << "].bg_filename: '" << bg_filename << "', length: " << bg_filename.length() << ", size: " << bg_filename.size() << std::endl;
        if (bg_filename.size() > 0) {
            std::string full_bggraphic_filename = FILEPATH + "data/images/sprites/backgrounds/" + bg_filename;
            std::cout << ">>>>>>>>> NPC[" << name << "].bg_filename: " << bg_filename << std::endl;
            graphLib.surfaceFromFile(full_bggraphic_filename, &bg_surface);
            if (bg_surface.gSurface == NULL) {
                std::cout << "initFrames - Error loading NPC background surface from file '" << full_bggraphic_filename << std::endl;
                return;
            }
            _character_graphics_background_list.insert(std::pair<std::string, graphicsLib_gSurface>(name, bg_surface));
            _has_background = true;
            _frame_pos_adjust.x = game_data.game_npcs[main_id].sprites_pos_bg.x;
            _frame_pos_adjust.y = game_data.game_npcs[main_id].sprites_pos_bg.y;
        }
    }

    //std::cout << "end" << std::endl;
}

bool classnpc::is_weak_to_freeze()
{
    if (freeze_weapon_id == -1) {
        return false;
    }
    int wpn_id = -1;
    for (int i=0; i<MAX_WEAPON_N; i++) {
        if (game_data.weapons[i].id_projectile == freeze_weapon_id) {
            wpn_id = i;
        }
    }
    if (wpn_id == -1) {
        return false;
    }
    if (game_data.game_npcs[_number].weakness[wpn_id].damage_multiplier == 0) {
        return false;
    }
    return true;
}

bool classnpc::is_able_to_fly()
{
    return can_fly;
}

bool classnpc::is_spawn()
{
    return _is_spawn;
}




// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void classnpc::initFrames()
{
}

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void classnpc::execute()
{
    if (freeze_weapon_effect == FREEZE_EFFECT_NPC && is_weak_to_freeze() == true) {
        return;
    }
    move();
	charMove();
}



void classnpc::copy(classnpc *from)
{
	int i;

	facing = from->facing;
	start_point = from->start_point;

	walk_range = from->walk_range;
	graphic_filename = from->graphic_filename;
	for (i=0; i<ANIM_DIRECTION_COUNT; i++) {
		for (int j=0; j<ANIM_TYPE_COUNT; j++) {
			for (int k=0; k<ANIM_FRAMES_COUNT; k++) {
				(character_graphics_list.find(name)->second)[i][j][k] = from->character_graphics_list.find(name)->second[i][j][k];
			}
		}
	}
    is_ghost = from->is_ghost;
	shield_type = from->shield_type;

	_is_boss = from->_is_boss;
	IA_type = from->IA_type;
    _projectile_type_id = from->_projectile_type_id;

	hitPoints = from->hitPoints;
	name = from->name;
	position = from->position;
	realPosition = from->realPosition;
	last_execute_time = 0;
	frameSize = from->frameSize;
	moveCommands = from->moveCommands;
	max_jump = from->max_jump;
	max_projectiles = from->max_projectiles;
	move_speed = from->move_speed;
    can_fly = from->can_fly;
    attack_state = 0;
	state = from->state;
	jump_steps = 0;

	/*
	for (i=0; i<ANIM_DIRECTION_COUNT; i++) {
		for (int j=0; j<ANIM_TYPE_COUNT; j++) {
			for (int k=0; k<ANIM_FRAMES_COUNT; k++) {
				(character_graphics_list.find(name)->second)[i][j][k].frameSurface = from->character_graphics_list.find(name)->second[i][j][k].frameSurface;
			}
		}
	}
	*/
}



void classnpc::move_projectiles()
{
	//int i = 0;
	// animate projectiles
    //if (name == "Dynamite Bot") std::cout << "******* NPC::move_projectiles - projectile_list.size: " << projectile_list.size() << std::endl;
    std::vector<projectile>::iterator it;
	for (it=projectile_list.begin(); it<projectile_list.end(); it++) {
        (*it).draw();
        st_size moved = (*it).move();
		// check colision agains players

        if ((*it).is_reflected == true) {
			continue;
		}

        if (_is_player_friend == false) { // NPC attacking players

            if ((*it).is_finished == true) {
                projectile_list.erase(it);
                break;
            }
            if ((*it).get_move_type() == TRAJECTORY_QUAKE) {
                ground_damage_players();
                continue;
            }

            std::vector<classPlayer*>::iterator enemy_it;
			for (enemy_it=map->_player_list.begin(); enemy_it != map->_player_list.end(); enemy_it++) {
                if ((*it).check_colision(st_rectangle((*enemy_it)->getPosition().x, (*enemy_it)->getPosition().y, (*enemy_it)->get_size().width, (*enemy_it)->get_size().height), st_position(moved.width, moved.height)) == true) {
                    if ((*enemy_it)->is_shielded((*it).get_direction()) == true) {
                        (*it).reflect();
                    } else if ((*enemy_it)->is_using_circle_weapon() == true) {
                        std::cout << "NPC projectile hit player centered-weapon" << std::endl;
                        (*enemy_it)->consume_projectile();
					} else {
                        int damage_pts = (*it).get_damage();
                        if (damage_pts < 2) {
                            damage_pts = 2;
                        }
                        (*enemy_it)->damage(damage_pts, false);
                        (*it).consume_projectile();
					}
				}
			}
        } else { // NPC attacking other NPCs
            std::vector<classnpc*>::iterator enemy_it;
			for (enemy_it=map->_npc_list.begin(); enemy_it != map->_npc_list.end(); enemy_it++) {
				//classnpc* enemy = (*enemy_it);
                if ((*it).check_colision(st_rectangle((*enemy_it)->getPosition().x, (*enemy_it)->getPosition().y, (*enemy_it)->get_size().width, (*enemy_it)->get_size().height), st_position(moved.width, moved.height)) == true) {
					//std::cout << "is_shielded::CALL 2" << std::endl;
                    if ((*enemy_it)->is_shielded((*it).get_direction()) == true) {
                        (*it).reflect();
					} else {
                        (*enemy_it)->damage((*it).get_damage(), false);
                        if ((*it).get_move_type() != TRAJECTORY_CHAIN) { /// @TODO non-destructable types
                            (*it).consume_projectile();
						}
					}
				}
                if ((*it).is_finished == true) {
					projectile_list.erase(it);
					break;
				}
			}
		}
	}
}


// executes the NPC sub-IA behavior
void classnpc::move() {




    if (state.direction < 0 || state.direction > ANIM_DIRECTION_COUNT-1) {
        state.direction = ANIM_DIRECTION_LEFT;
    }


	int mapScrollX = map->getMapScrolling().x;

	// only move npcs that are in the current screen and are alive
	//mapScrollX = -map_pos_x;


	/// @TODO: this check must be placed in game.cpp and npc must have a set_frozen() method, for individual effect


	move_projectiles();


	if (last_execute_time > timer.getTimer()) {
		return;
	}

	if (state.frozen == true) {
		return;
	}


	//std::cout << "classnpc::move()::START::name: " << name << ", hitPoints.current: " << hitPoints.current << ", position.x: " << position.x << ", mapScrollX: " << mapScrollX << std::endl;

    if (hitPoints.current > 0 && position.x+frameSize.width >= mapScrollX-TILESIZE*2 && position.x <= mapScrollX+RES_W+TILESIZE*2) {
        //std::cout << "classnpc::move(" << name << ")::IA_type: " << IA_type << std::endl;
		execute_ai();
	}

    //std::cout << "classnpc::move - position.y: " << position.y << std::endl;

    if (can_fly == false && position.y >= RES_H+1) {
        // death because felt in a hole
        damage(999, true);
        position.x = start_point.x;
        position.y = start_point.y;
        //std::cout << "classnpc::move - FELT IN HOLE - DEATH - pos.x: " << position.x << ", pos.y: " << position.y << std::endl;
        return;
    }

}



// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //



short classnpc::get_dead_state()
{
    if (hitPoints.current > 0) {
        _dead_state = 0;
    } else {
        if (_dead_state == 0) {
            death();
            _dead_state = 1;
        } else if (_dead_state == 1) {
            _dead_state = 2;
        }
    }
    return _dead_state;
}

st_rectangle classnpc::get_hit_area()
{
    st_rectangle res(game_data.game_npcs[_number].sprites[ANIM_TYPE_TELEPORT][0].colision_rect.x, game_data.game_npcs[_number].sprites[ANIM_TYPE_TELEPORT][0].colision_rect.y, game_data.game_npcs[_number].sprites[ANIM_TYPE_TELEPORT][0].colision_rect.w, game_data.game_npcs[_number].sprites[ANIM_TYPE_TELEPORT][0].colision_rect.h);
    if (state.direction == ANIM_DIRECTION_RIGHT && _have_right_direction_graphics == true) {
        res.x = frameSize.width - res.w - res.x;
    }
    //std::cout << "NPC::get_hit_area - res.x: " << res.x << ", res.y: " << res.y << ", res.w: " << res.w << ", res.h: " << res.h << ", w: " << frameSize.width << ", h: " << frameSize.height << std::endl;
    return res;
}

void classnpc::death()
{
	state.jump_state = NO_JUMP;
	dead = true;
	//std::cout << "classnpc::death" << std::endl;
    if (_ai_state.main_status == IA_STATE_QUAKE_ATTACK) {
        graphLib.set_screen_adjust(st_position(0, 0));
    }
}

bool classnpc::is_boss()
{
	return _is_boss;
}




void classnpc::set_is_boss(bool set_boss)
{
    _is_boss = set_boss;
}

bool classnpc::is_player_friend()
{
	return _is_player_friend;
}

void classnpc::set_stage_boss(bool boss_flag)
{
    _is_boss = boss_flag;
    _is_stage_boss = boss_flag;
    if (boss_flag == true) {
        hitPoints.total = PLAYER_INITIAL_HP;
        hitPoints.current = hitPoints.total;
    }
}

void classnpc::revive()
{
    //std::cout << "**** classnpc::revive[" << name << " ****" << std::endl;
	//position.x = start_point.x;
	//position.y = start_point.y;
    if (game_data.ai_types[game_data.game_npcs[_number].gravity_level].states[_ai_chain_n].extra_parameter == AI_ACTION_FLY_OPTION_DRILL_DOWN) {
        position.y = -TILESIZE;
    }
	hitPoints.current = hitPoints.total;
}





void classnpc::invert_direction()
{
	if (state.direction == ANIM_DIRECTION_LEFT) {
		state.direction = ANIM_DIRECTION_RIGHT;
	} else {
		state.direction = ANIM_DIRECTION_LEFT;
	}
	_ai_state.main_status = IA_STAND;
}




