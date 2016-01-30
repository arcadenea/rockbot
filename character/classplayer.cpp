#include <sstream>
#include <list>
#include <math.h>

#include "classplayer.h"
#include "inputlib.h"
extern inputLib input;
#include "class_config.h"

#include "soundlib.h"
extern soundLib soundManager;

#include "game.h"
extern game gameControl;

extern CURRENT_FILE_FORMAT::file_game game_data;

extern CURRENT_FILE_FORMAT::st_save game_save;

extern FREEZE_EFFECT_TYPES freeze_weapon_effect;

#define PLAYER_MOVE_SPEED_INT_PART 2 // higher is faster
#define PLAYER_MOVE_SPEED_FLOAT_PART 4 // lower is faster


#include "classmap.h"

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
classPlayer::classPlayer(std::string set_name, int playerNumber) : teleporter_n(-1), selected_weapon(WEAPON_DEFAULT), l_key_released(true), r_key_released(true)
{
    _number = playerNumber;
    if (_number == 3 || _number == 0) {
        _obj_jump.set_jump_acceleration(0.95);
        _obj_jump.set_jump_limit(50);
    }
	max_projectiles = game_data.players[_number].max_shots;
    std::cout << "###### classPlayer::classPlayer[" << _number << "] - max_projectiles: " << max_projectiles << std::endl;
    position.y = -TILESIZE;
	position.x = 80;
    hit_duration = 2000;
	//hitPoints.total = game_data.players[_number].HP;
	hitPoints.total = PLAYER_INITIAL_HP;
	hitPoints.current = hitPoints.total;
	name = set_name;
	add_graphic();
	init_weapon_colors();
	initFrames();
	shield_type = SHIELD_FRONT; /// @TODO: from editor
	// load items from save
	if (game_data.players[_number].can_slide == true) {
		slide_type = 1;
	}
    move_speed = PLAYER_MOVE_SPEED_INT_PART;
    _fractional_move_speed = PLAYER_MOVE_SPEED_FLOAT_PART;

    _charged_shot_projectile_id = game_data.players[_number].full_charged_projectile_id;

    //std::cout << ">>> p[" << _number << "]._charged_shot_projectile_id: " << _charged_shot_projectile_id << std::endl;

    _simultaneous_shots = game_data.players[_number].simultaneous_shots;
    //std::cout << "classjump::set_acceleration - player[" << name << "], accel[" << game_data.players[_number].jump_gravity << "]" << std::endl;
    if (can_double_jump() == true) {
        _jumps_number = 2;
    } else {
        _jumps_number = 1;
    }
    _damage_modifier = game_data.players[_number].damage_modifier;
    update_armor_properties();
}


void classPlayer::init_weapon_colors()
{
	for (int i=0; i<3; i++) {
		color_keys[i] = game_data.players[_number].color_keys[i];
	}
	for (int i=0; i<MAX_WEAPON_N; i++) {
		weapon_colors[i] = game_data.players[_number].weapon_colors[i];
	}
}

bool classPlayer::get_item(object_colision &obj_info)
{
    if (state.animation_type == ANIM_TYPE_TELEPORT) {
        return false;
    }
	if (character::get_item(obj_info)) {
		return true;
	}

	bool res = false;
	// deal with non-blocking items
	if (obj_info._object != NULL && obj_info._object->finished() == false) {
		//std::cout << "classPlayer::get_item" << std::endl;
		switch (obj_info._object->get_type()) {
		case OBJ_ENERGY_TANK:
            if (game_save.items.energy_tanks < 9) { // max 9
                game_save.items.energy_tanks++;
            }
			obj_info._object->set_finished(true);
			soundManager.play_sfx(SFX_GOT_ITEM);
            res = true;
			break;
		case OBJ_WEAPON_TANK:
            game_save.items.weapon_tanks = 1; // max 1
			obj_info._object->set_finished(true);
			soundManager.play_sfx(SFX_GOT_ITEM);
            res = true;
			break;
        case OBJ_SPECIAL_TANK:
            game_save.items.special_tanks = 1; // max 1
            obj_info._object->set_finished(true);
            soundManager.play_sfx(SFX_GOT_ITEM);
            res = true;
            break;
        case OBJ_LIFE:
            game_save.items.lifes++;
            if (game_save.items.lifes > 9) {
                game_save.items.lifes = 9;
            }
			obj_info._object->set_finished(true);
			soundManager.play_sfx(SFX_GOT_ITEM);
            res = true;
			break;
		case OBJ_WEAPON_PILL_BIG:
			obj_info._object->set_finished(true);
			recharge(ENERGY_TYPE_WEAPON, ENERGY_ITEM_BIG);
            res = true;
			break;
		case OBJ_WEAPON_PILL_SMALL:
			obj_info._object->set_finished(true);
			recharge(ENERGY_TYPE_WEAPON, ENERGY_ITEM_SMALL);
            res = true;
			break;
        case OBJ_ARMOR_ARMS:
            obj_info._object->set_finished(true);
            soundManager.play_sfx(SFX_GOT_ITEM);
            game_save.armor_pieces[ARMOR_ARMS] = true;
            show();
            gameControl.showGotArmorDialog(ARMOR_ARMS);
            update_armor_properties();
            break;
        case OBJ_ARMOR_BODY:
            obj_info._object->set_finished(true);
            soundManager.play_sfx(SFX_GOT_ITEM);
            game_save.armor_pieces[ARMOR_BODY] = true;
            show();
            gameControl.showGotArmorDialog(ARMOR_BODY);
            update_armor_properties();
            break;
        case OBJ_ARMOR_LEGS:
            obj_info._object->set_finished(true);
            soundManager.play_sfx(SFX_GOT_ITEM);
            game_save.armor_pieces[ARMOR_LEGS] = true;
            show();
            gameControl.showGotArmorDialog(ARMOR_LEGS);
            update_armor_properties();
            break;
        default:
			//std::cout << "classPlayer::get_item - unknown item type: " << obj_info._object->get_type() << std::endl;
			break;
		}
	}
	return res;
}

void classPlayer::recharge(e_energy_types _en_type, int value)
{
	if (_en_type == ENERGY_TYPE_HP) {
		character::recharge(_en_type, value);
	} else if (_en_type == ENERGY_TYPE_WEAPON) {
        if (game_save.items.weapons[selected_weapon] < PLAYER_INITIAL_HP) {
            if (game_save.items.weapons[selected_weapon] + value <= PLAYER_INITIAL_HP) {
                game_save.items.weapons[selected_weapon] += value;
			} else {
                game_save.items.weapons[selected_weapon] = PLAYER_INITIAL_HP;
			}
			soundManager.play_sfx(SFX_GOT_ENERGY);
			if (value > ENERGY_ITEM_SMALL) {
				soundManager.play_sfx(SFX_GOT_ENERGY);
			}
		}
	}
}


bool classPlayer::shoryuken()
{
    // trying to start command (can only start if standing)

    //std::cout << ">> SHOURYUKEN - up: " << moveCommands.up << ", dash: " << moveCommands.dash << ", jump: " << moveCommands.jump << std::endl;

    if (moveCommands.up != 0 && moveCommands.dash != 0 && state.animation_type == ANIM_TYPE_STAND)  {
        state.animation_type = ANIM_TYPE_SPECIAL_ATTACK;
        std::cout << ">>>>>>>>>>>>>>>>>>>> SHORYUKEN::START" << std::endl;
        soundManager.play_sfx(SFX_SHORYUKEN_GIRL);
        _obj_jump.start(true);
        return true;
    // is executing
    } else if (state.animation_type == ANIM_TYPE_SPECIAL_ATTACK) {
        std::cout << ">>>>>>>>>>>>>>>>>>>> SHORYUKEN::EXECUTE" << std::endl;
        //position.y -= move_speed;
        _obj_jump.execute();
        int jump_speed = _obj_jump.get_speed();
        bool jump_moved = false;

        // check collision
        for (int i=abs((float)jump_speed); i>0; i--) {
            int speed_y = 0;
            if (jump_speed > 0) {
                speed_y = i;
            } else {
                speed_y = i*-1;
            }
            st_map_colision map_col = map_colision(0, speed_y, map->getMapScrolling());
            int map_lock = map_col.block;
            //std::cout << "jump::check_collision - i[" << i << "], map_lock["  << map_lock << "]" << std::endl;

            if (map_lock == BLOCK_UNBLOCKED || map_lock == BLOCK_WATER) {
                //std::cout << "jump.speed[" << speed_y << "]" << std::endl;
                position.y += speed_y;
                jump_moved = true;
                break;
            }
        }
        if (jump_speed != 0 && jump_moved == false) {
            //std::cout << "chat::jump - must interrupt because a collision happened" << std::endl;
            if (jump_speed < 0) {
                _obj_jump.interrupt();
            } else {
                _obj_jump.finish();
                state.animation_type = ANIM_TYPE_STAND;
            }
        }



        if (_obj_jump.is_started() == false) {
            return false;
        }
        return true;
    }
    return false;
}

void classPlayer::consume_weapon(int value)
{
    if (game_save.items.weapons[selected_weapon] - value < 0) {
        game_save.items.weapons[selected_weapon] = 0;
    } else {
        game_save.items.weapons[selected_weapon] -= value;
    }
}


void classPlayer::attack(bool dont_update_colors)
{
    UNUSED(dont_update_colors);
    st_position proj_pos;


    //std::cout << ">> classPlayer::attack() - selected_weapon: " << selected_weapon << std::endl;


    if (state.animation_type == ANIM_TYPE_HIT) { // can't fire when hit
        return;
    }

    if (get_projectile_max_shots() <= projectile_list.size()) {
        return;
    }

    bool auto_charged = false;
    if (game_save.armor_pieces[ARMOR_ARMS] == true && game_data.armor_pieces[ARMOR_ARMS].special_ability[_number] == ARMOR_ABILITY_ARMS_ALWAYSCHARGED) {
        auto_charged = true;
    }

    if (selected_weapon == WEAPON_DEFAULT) {
        /// @NOTE: desabilitei o tiro em diagonal pois vai precisar mudanças no sistema de arquivos para ocmportar as poses/frames
        /// de ataque para cima e para baixo
        //std::cout << ">> classPlayer::attack() - NORMAL" << std::endl;
        bool is_on_ground = hit_ground();
        if (can_shoot_diagonal() == true && moveCommands.up != 0 && is_on_ground == true) {
            character::attack(false, 1, auto_charged);
        } else if (can_shoot_diagonal() == true && moveCommands.down != 0 && is_on_ground == true) {
            character::attack(false, -1, auto_charged);
        } else {
            character::attack(false, 0, auto_charged);
        }
        return;
    } else if (game_save.items.weapons[selected_weapon] <= 0) {
        std::cout << "invalid weapon" << std::endl;
        return;
    }

    if (moveCommands.attack == 0 && attack_button_released == false) {
        attack_button_released = true;
        return;
    }

    int effect_type = is_executing_effect_weapon();
    int used_weapon = selected_weapon;
    if (effect_type == TRAJECTORY_FREEZE) { // freeze can shoot normal projectiles
        if (max_projectiles > get_projectile_count()) {
            //std::cout << "TRAJECTORY_FREEZE weapon detected!" << std::endl;
            character::attack(true, 0, auto_charged);
        }
        return;
    } else if (effect_type != -1) {
        if (moveCommands.attack != 0 && (timer.getTimer()-state.attack_timer) > 100 && attack_button_released == true) {
            //std::cout << ">> classPlayer::attack() - already using an effect weapon" << std::endl;
            inc_effect_weapon_status(); // this method have a filter to inc only the types that are effect (centered, bomb, etc)
        }
        return;
    }
    if (max_projectiles <= get_projectile_count()) {
        return;
    }

    if (moveCommands.attack != 0 && (timer.getTimer()-state.attack_timer) > 100 && attack_button_released == true) {
        attack_button_released = false;


        if (state.direction == ANIM_DIRECTION_LEFT) {
            proj_pos = st_position(position.x, position.y+frameSize.height/2);
        } else {
            proj_pos = st_position(position.x+frameSize.width-TILESIZE*2, position.y+frameSize.height/2);
        }

        short int weapon_id = 0;


        if (used_weapon == WEAPON_ITEM_COIL) {
            add_coil_object();
        } else if (used_weapon == WEAPON_ITEM_JET) {
            add_jet_object();
        } else {
            weapon_id = used_weapon;
        }

        if (weapon_id == 0) { /// @TODO - this is a temporary exit to handle incomplete weapons
            return;
        }

        // check if projectiles limit from weapon/projectile os not reached
        if (projectile_list.size() >= game_data.projectiles[game_data.weapons[weapon_id].id_projectile].max_shots) {
            std::cout << "#### PLAYER::ATTACK - can't shot, weapon number reached ###" << std::endl;
            return;
        }


        soundManager.play_sfx(SFX_PLAYER_SHOT);

        projectile_list.push_back(projectile(game_data.weapons[weapon_id].id_projectile, state.direction, proj_pos, map, is_player()));
        projectile &temp_proj = projectile_list.back();
        temp_proj.set_is_permanent();
        temp_proj.set_weapon_id(weapon_id);


        //std::cout << "weapon_id: " << weapon_id << ", projectile_id: " << game_data.weapons[weapon_id].id_projectile << std::endl;

        int weapon_trajectory = game_data.projectiles[game_data.weapons[weapon_id].id_projectile].trajectory;
        if (weapon_trajectory == TRAJECTORY_CENTERED) {
            temp_proj.set_owner_direction(&state.direction);
            temp_proj.set_owner_position(&position);
        } else if (weapon_trajectory == TRAJECTORY_CHAIN) {
            temp_proj.set_owner_position(&position);
            temp_proj.set_owner_direction(&state.direction);
        } else if (weapon_trajectory == TRAJECTORY_FOLLOW) {
            classnpc* temp = find_nearest_npc();
            if (temp != NULL) {
                //std::cout << "PLAYER::attack - could not find target" << std::endl;
                temp_proj.set_target_position(temp->get_position_ref());
            }
        }

        //std::cout << "Added projectile - id: " << game_data.weapons[weapon_id].id_projectile << std::endl;

        if (selected_weapon != WEAPON_DEFAULT) {
            if (weapon_trajectory == TRAJECTORY_QUAKE) {
                consume_weapon(4);
            } else if (weapon_trajectory == TRAJECTORY_FREEZE) {
                consume_weapon(2);
            } else {
                consume_weapon(1);
            }
        }


        attack_state = ATTACK_START;
        state.attack_timer = timer.getTimer();
        if (state.animation_type == ANIM_TYPE_STAND) {
            set_animation_type(ANIM_TYPE_ATTACK);
        } else if (state.animation_type == ANIM_TYPE_JUMP) {
            set_animation_type(ANIM_TYPE_JUMP_ATTACK);
        } else if (state.animation_type == ANIM_TYPE_STAIRS || state.animation_type == ANIM_TYPE_STAIRS_SEMI || state.animation_type == ANIM_TYPE_STAIRS_MOVE) {
            set_animation_type(ANIM_TYPE_STAIRS_ATTACK);
        } else if (state.animation_type == ANIM_TYPE_WALK) {
            set_animation_type(ANIM_TYPE_WALK_ATTACK);
        }
    }
}

void classPlayer::damage_ground_npcs()
{
	/// @TODO - this part must be done only ONCE
	// find quake in projectiles list
	int projectile_n = -1;
    for (int i =0; i<FS_MAX_PROJECTILES; i++) {
		if (game_data.projectiles[i].trajectory == TRAJECTORY_QUAKE) {
			projectile_n = i;
			break;
		}
	}
	if (projectile_n == -1) {
		std::cout << "damage_ground_npcs - could not find projectile of QUAKE trajectory type" << std::endl;
		return;
	}
	// find quake weapon in weapons list
	int weapon_n = -1;
	for (int i = 0; i<MAX_WEAPON_N; i++) {
		if (game_data.weapons[i].id_projectile == projectile_n) {
			weapon_n = i;
			break;
		}
	}
	// could not find the weapon
	if (weapon_n == -1) {
		std::cout << "damage_ground_npcs - could not find weapon with projectile of id '" << weapon_n << "'" << std::endl;
		return;
	}
    std::vector<classnpc*>::iterator enemy_it;
	for (enemy_it=map->_npc_list.begin(); enemy_it != map->_npc_list.end(); enemy_it++) {
        if ((*enemy_it)->is_on_visible_screen() == false) {
			continue;
		}

		// check if NPC is vulnerable to quake (all bosses except the one with weakness are not)
		short damage = game_data.game_npcs[(*enemy_it)->get_number()].weakness[weapon_n].damage_multiplier;

		// check if NPC is on ground
        st_position npc_pos((*enemy_it)->getPosition().x, (*enemy_it)->getPosition().y);
		npc_pos.x = (npc_pos.x + (*enemy_it)->get_size().width/2)/TILESIZE;
        npc_pos.y = (npc_pos.y + (*enemy_it)->get_size().height)/TILESIZE;
		int lock = map->getMapPointLock(npc_pos);
		//std::cout << "damage_ground_npcs - NPC[" << (*enemy_it)->getName() << "].lock: " << lock << ", x: " << npc_pos.x << ", y: " << npc_pos.y << std::endl;
		if (lock == TERRAIN_UNBLOCKED || lock == TERRAIN_STAIR || lock == TERRAIN_WATER) {
			continue;
		} else {
            //std::cout << "&&&&&&&&&&&&& damage_ground_npcs - DAMAGING NPC[" << (*enemy_it)->getName() << "]" << std::endl;
            (*enemy_it)->damage(damage, false);
		}
	}
}



// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void classPlayer::initFrames()
{
	frameSize.width = 29;
    frameSize.height = 29;

	graphicsLib_gSurface playerSpriteSurface;
	std::stringstream filename;
    //filename << FILEPATH << "/data/images/sprites/p" << (_number+1) << ".png";
    filename << FILEPATH << "/data/images/sprites/" << game_data.players[_number].graphic_filename;
	graphLib.surfaceFromFile(filename.str(), &playerSpriteSurface);
	if (playerSpriteSurface.gSurface == NULL) {
		std::cout << "initFrames - Error loading player surface from file\n";
		return;
	}

	// STAND
    addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_STAND, 3, 0, playerSpriteSurface, 5000);
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_STAND, 4, 0, playerSpriteSurface, 150);
    addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_STAND, 3, 1, playerSpriteSurface, 5000);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_STAND, 4, 1, playerSpriteSurface, 150);
	// WALK
    addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_WALK, 6, 0, playerSpriteSurface, WALK_FRAME_DELAY);
    addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_WALK, 7, 0, playerSpriteSurface, WALK_FRAME_DELAY);
    addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_WALK, 8, 0, playerSpriteSurface, WALK_FRAME_DELAY);
    addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_WALK, 7, 0, playerSpriteSurface, WALK_FRAME_DELAY);
    addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_WALK, 6, 1, playerSpriteSurface, WALK_FRAME_DELAY);
    addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_WALK, 7, 1, playerSpriteSurface, WALK_FRAME_DELAY);
    addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_WALK, 8, 1, playerSpriteSurface, WALK_FRAME_DELAY);
    addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_WALK, 7, 1, playerSpriteSurface, WALK_FRAME_DELAY);
	// JUMP
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_JUMP, 9, 0, playerSpriteSurface, 150);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_JUMP, 9, 1, playerSpriteSurface, 150);
	// ATTACK
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_ATTACK, 11, 0, playerSpriteSurface, 150);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_ATTACK, 11, 1, playerSpriteSurface, 150);
	// ATTACK + JUMP
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_JUMP_ATTACK, 10, 0, playerSpriteSurface, 80);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_JUMP_ATTACK, 10, 1, playerSpriteSurface, 80);
	// ATTACK + WALK
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_WALK_ATTACK, 12, 0, playerSpriteSurface, 150);
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_WALK_ATTACK, 13, 0, playerSpriteSurface, 150);
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_WALK_ATTACK, 14, 0, playerSpriteSurface, 150);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_WALK_ATTACK, 12, 1, playerSpriteSurface, 150);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_WALK_ATTACK, 13, 1, playerSpriteSurface, 150);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_WALK_ATTACK, 14, 1, playerSpriteSurface, 150);
	// HIT
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_HIT, 15, 1, playerSpriteSurface, 150);
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_HIT, 15, 0, playerSpriteSurface, 150);
	// TELEPORT
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_TELEPORT, 0, 0, playerSpriteSurface, 750);
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_TELEPORT, 1, 0, playerSpriteSurface, 300);
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_TELEPORT, 2, 0, playerSpriteSurface, 150);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_TELEPORT, 0, 1, playerSpriteSurface, 750);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_TELEPORT, 1, 1, playerSpriteSurface, 300);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_TELEPORT, 2, 1, playerSpriteSurface, 150);
	// STAIRS
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_STAIRS, 17, 0, playerSpriteSurface, 5000);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_STAIRS, 17, 1, playerSpriteSurface, 5000);
	// stairs semi
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_STAIRS_SEMI, 18, 0, playerSpriteSurface, 5000);
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_STAIRS_SEMI, 18, 1, playerSpriteSurface, 5000);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_STAIRS_SEMI, 18, 0, playerSpriteSurface, 5000);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_STAIRS_SEMI, 18, 1, playerSpriteSurface, 5000);
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_STAIRS, 17, 0, playerSpriteSurface, 5000);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_STAIRS, 17, 1, playerSpriteSurface, 5000);
	// stairs + move
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_STAIRS_MOVE, 17, 0, playerSpriteSurface, 200);
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_STAIRS_MOVE, 17, 1, playerSpriteSurface, 200);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_STAIRS_MOVE, 17, 0, playerSpriteSurface, 200);
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_STAIRS_MOVE, 17, 1, playerSpriteSurface, 200);
	// stairs + attack
    addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_STAIRS_ATTACK, 19, 1, playerSpriteSurface, 500);
    addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_STAIRS_ATTACK, 19, 0, playerSpriteSurface, 500);

    // slide
    addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_SLIDE, 20, 1, playerSpriteSurface, 1000);
    addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_SLIDE, 20, 0, playerSpriteSurface, 1000);

    // throw
    //addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_THROW, 21, 1, playerSpriteSurface, 1000);
    //addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_THROW, 21, 0, playerSpriteSurface, 1000);


	// shield
	addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_SHIELD, 22, 1, playerSpriteSurface, 100);
	addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_SHIELD, 22, 0, playerSpriteSurface, 100);

    // shoot-diagonal-up
    addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_ATTACK_DIAGONAL_UP, 23, 1, playerSpriteSurface, 100);
    addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_ATTACK_DIAGONAL_UP, 23, 0, playerSpriteSurface, 100);

    // shoot-diagonal-down
    addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_ATTACK_DIAGONAL_DOWN, 24, 1, playerSpriteSurface, 100);
    addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_ATTACK_DIAGONAL_DOWN, 24, 0, playerSpriteSurface, 100);

    // special-attack
    addSpriteFrame(ANIM_DIRECTION_LEFT, ANIM_TYPE_SPECIAL_ATTACK, 25, 1, playerSpriteSurface, 100);
    addSpriteFrame(ANIM_DIRECTION_RIGHT, ANIM_TYPE_SPECIAL_ATTACK, 25, 0, playerSpriteSurface, 100);

    playerSpriteSurface.freeGraphic();
}


void classPlayer::execute()
{
    if (freeze_weapon_effect != FREEZE_EFFECT_PLAYER || timer.getTimer() < hit_duration+last_hit_time) {
        move();
    } else {
        clear_move_commands();
        input.clean();
    }
    if (have_shoryuken() == true && shoryuken() == true) { // while doing shoryuken won't move
        return;
    }
    charMove();
    attack();
}

void classPlayer::execute_projectiles()
{
    // animate projectiles
    vector<projectile>::iterator it;
    bool ignore_hit_timer = false;
    if (_simultaneous_shots > 1) {
        ignore_hit_timer = true;
    }

    for (it=projectile_list.begin(); it<projectile_list.end(); it++) {
        if ((*it).is_finished == true) {
            projectile_list.erase(it);
            break;
        }
        st_size moved = (*it).move();

        //std::cout << "projectile.move_type: " << (*it)->get_move_type() << std::endl;

        /// @TODO projectiles that are tele-guided
        if ((*it).get_move_type() == TRAJECTORY_QUAKE) {
            damage_ground_npcs();
            continue;
        }
        (*it).draw();
        if ((*it).is_reflected == true) {
            continue;
        }
        // check colision agains enemies
        std::vector<classnpc*>::iterator enemy_it;
        for (enemy_it=map->_npc_list.begin(); enemy_it != map->_npc_list.end(); enemy_it++) {
            if ((*it).is_finished == true) {
                projectile_list.erase(it);
                break;
            }
            if ((*enemy_it)->is_on_visible_screen() == false) {
                continue;
            }
            if ((*enemy_it)->is_dead() == true) {
                continue;
            }



            //classnpc* enemy = (*enemy_it);
            if ((*it).check_colision(st_rectangle((*enemy_it)->getPosition().x, (*enemy_it)->getPosition().y, (*enemy_it)->get_size().width, (*enemy_it)->get_size().height), st_position(moved.width, moved.height)) == true) {
                if ((*enemy_it)->is_shielded((*it).get_direction()) == true) { // shielded NPC -> reflects shot
                    if ((*it).get_trajectory() == TRAJECTORY_CHAIN) {
                        (*it).consume_projectile();
                    } else {
                        (*it).reflect();
                    }
                    continue;
                }
                if ((*enemy_it)->is_invisible() == true) { // invisible NPC -> ignore shot
                    continue;
                }

                // check if have hit area, and if hit it
                st_rectangle enemy_hit_area = (*enemy_it)->get_hit_area();
                st_size enemy_size = (*enemy_it)->get_size();
                enemy_hit_area.x += (*enemy_it)->getPosition().x-1;
                enemy_hit_area.y += (*enemy_it)->getPosition().y;

                //std::cout << ">> PLAYER::execute_projectiles[" << (*enemy_it)->getName() << "] - npc.h: " << enemy_size.height << ", hit_area.h: " << enemy_hit_area.h << std::endl;
                if (enemy_hit_area.w != enemy_size.width || enemy_hit_area.h != enemy_size.height) {
                    //std::cout << ">> PLAYER::execute_projectiles[" << (*enemy_it)->getName() << "] - use hit_area" << std::endl;
                    if ((*it).check_colision(enemy_hit_area, st_position(moved.width, moved.height)) == false) { // hit body, but not the hit area -> reflect
                        //std::cout << ">> PLAYER::execute_projectiles[" << (*enemy_it)->getName() << "]Projectile missed - enemy_hit_area.w: " << enemy_hit_area.w << ", enemy_hit_area.h: " << enemy_hit_area.h << std::endl;
                        (*it).consume_projectile();
                        continue;
                    }
                //} else {
                    //std::cout << ">> PLAYER::execute_projectiles[" << (*enemy_it)->getName() << "] - DONT use hit_area" << std::endl;
                }

                short wpn_id = (*it).get_weapon_id();

                //std::cout << "******* wpn_id: " << wpn_id << std::endl;
                if (wpn_id < 0) {
                    wpn_id = 0;
                }

                //std::cout << ">> player weapon damage #1" << std::endl;
                //std::cout << "******* (*enemy_it)->is_using_circle_weapon(): " << (*enemy_it)->is_using_circle_weapon() << ", (*it)->get_trajectory(): " << (*it)->get_trajectory() << ", TRAJECTORY_CHAIN: " << TRAJECTORY_CHAIN << std::endl;
                // NPC using cicrcle weapon, is only be destroyed by CHAIN, but NPC won't take damage
                if ((*enemy_it)->is_using_circle_weapon() == true) {
                    if ((*it).get_trajectory() == TRAJECTORY_CHAIN) {
                        //std::cout << "PLAYER projectile hit NPC centered-weapon" << std::endl;
                        (*enemy_it)->consume_projectile();
                    }
                    (*it).consume_projectile();
                    return;
                }

                if ((*it).get_damage() > 0) {
                    int multiplier = game_data.game_npcs[(*enemy_it)->get_number()].weakness[wpn_id].damage_multiplier;
                    if (multiplier <= 0) {
                        multiplier = 1;
                    }
                    (*enemy_it)->damage((*it).get_damage() * multiplier, ignore_hit_timer);
                }
                if ((*it).get_damage() > 0) {
                    (*it).consume_projectile();
                    soundManager.play_sfx(SFX_NPC_HIT);
                }
            }
        }


        // if projectile is a bomb, check colision against objects
        if ((*it).get_effect_n() == 1 && ((*it).get_move_type() == TRAJECTORY_BOMB || (*it).get_move_type() == TRAJECTORY_FALL_BOMB)) {
            //std::cout << "PLAYER::execute_projectiles - Have exploding bomb, checking objects that collide..." << std::endl;
            std::vector<object*> res_obj = map->check_collision_with_objects((*it).get_area());
            if (res_obj.size() > 0) {
                //std::cout << "PLAYER::execute_projectiles - Found objects (" << res_obj.size() << ") that collides with bomb!" << std::endl;
                for (int i=0; i<res_obj.size(); i++) {
                    object* temp_obj = res_obj.at(i);
                    //std::cout << "PLAYER::execute_projectiles - OBJ[" << temp_obj->get_name() << "].type: " << temp_obj->get_type() << ", OBJ_DESTRUCTIBLE_WALL: " << OBJ_DESTRUCTIBLE_WALL << std::endl;
                    if (temp_obj->get_type() == OBJ_DESTRUCTIBLE_WALL) {
                        //std::cout << "PLAYER::execute_projectiles - Found destructible block!!!!" << std::endl;
                        temp_obj->set_finished(true);
                    }
                }
            }
        }
    }
}

void classPlayer::move()
{
	if (input.p1_input[BTN_DOWN] == 1) {
		moveCommands.down = 1;
	} else {
		moveCommands.down = 0;
	}
	if (input.p1_input[BTN_UP] == 1) {
		moveCommands.up = 1;
	} else {
		moveCommands.up = 0;
	}
	if (input.p1_input[BTN_LEFT] == 1) {
		moveCommands.left = 1;
	} else {
		moveCommands.left = 0;
	}
	if (input.p1_input[BTN_RIGHT] == 1) {
		moveCommands.right = 1;
	} else {
		moveCommands.right = 0;
	}
	if (input.p1_input[BTN_JUMP] == 1) {
		moveCommands.jump = 1;
	} else {
		moveCommands.jump = 0;
	}
	if (input.p1_input[BTN_ATTACK] == 1) {
		moveCommands.attack = 1;
	} else {
		moveCommands.attack = 0;
	}
	if (input.p1_input[BTN_SHIELD] == 1) {
		moveCommands.shield = 1;
	} else {
		moveCommands.shield = 0;
	}
	if (input.p1_input[BTN_DASH] == 1) {
		moveCommands.dash = 1;
	} else {
		moveCommands.dash = 0;
	}

    // players that shoot on diagonal can't move shile attacking
    if (can_shoot_diagonal()) {
        if (is_on_attack_frame() && state.animation_type != ANIM_TYPE_JUMP_ATTACK) {
            //state.animation_type = ANIM_TYPE_ATTACK;
            moveCommands.left = 0;
            moveCommands.right = 0;
        }
    }

	if (input.p1_input[BTN_L] != 1 && l_key_released == false) {
		l_key_released = true;
	}
	int wpn_max = WEAPON_COUNT;
    //wpn_max--;
	if (input.p1_input[BTN_L] == 1 && l_key_released == true) {
		int selected_weapon_c = selected_weapon;
		selected_weapon_c = find_next_weapon(selected_weapon, -1);
        if (selected_weapon_c != -1) {
            set_weapon((WEAPON_ICONS_ENUM)selected_weapon_c);
        }
		l_key_released = false;
        //std::cout << ">>> LBUTTON - selected_weapon: " << selected_weapon << ", selected_weapon_c: " << selected_weapon_c << ", WEAPON_COUNT: " << WEAPON_COUNT << std::endl;
	}

	if (input.p1_input[BTN_R] != 1 && r_key_released == false) {
		r_key_released = true;
	}
	if (input.p1_input[BTN_R] == 1 && r_key_released == true) {
		int selected_weapon_c = selected_weapon;
		selected_weapon_c = find_next_weapon(selected_weapon, 1);
		if (selected_weapon_c >= wpn_max) {
			selected_weapon_c = WEAPON_DEFAULT;
		}
        if (selected_weapon_c != -1) {
            set_weapon((WEAPON_ICONS_ENUM)selected_weapon_c);
        }
		r_key_released = false;
        //std::cout << ">>> RBUTTON - selected_weapon: " << selected_weapon << ", selected_weapon_c: " << selected_weapon_c << ", WEAPON_COUNT: " << WEAPON_COUNT << std::endl;
	}


	// send commands to the platform in special cases
	if (_platform != NULL) {
		if (_platform->get_type() == OBJ_ITEM_FLY && timer.getTimer() > _platform->get_timer()) {
            consume_weapon(1);
            if (game_save.items.weapons[selected_weapon] == 0) {
                _platform->set_finished(true);
                _platform = NULL;
                return;
            }
            _platform->set_timer(timer.getTimer()+240);
		}
		//std::cout << ">>> PLAYER SEND COMMAND FOR " << _platform->get_name() << ", type: " << _platform->get_type() << std::endl;
		if (moveCommands.up == 1) {
			_platform->command_up();
		}
		if (moveCommands.down == 1) {
			_platform->command_down();
		}
	}

    if (game_data.players[_number].have_shield == true && moveCommands.up == 0 && moveCommands.down == 0 && moveCommands.left == 0 && moveCommands.right == 0 && moveCommands.jump == 0 && moveCommands.attack == 0 && moveCommands.shield == 1) {
		if (state.animation_type != ANIM_TYPE_SHIELD) {
			std::cout << "playerClass::initShield CHANGE anim_type: " << state.animation_type << " to " << ANIM_TYPE_SHIELD << std::endl;
            set_animation_type(ANIM_TYPE_SHIELD);
			state.animation_timer = 0;
			state.animation_state = 0;
		}
		return;
	} else if (state.animation_type == ANIM_TYPE_SHIELD) {
		//std::cout << "playerClass::initShield REMOVE shield" << std::endl;
		if (is_player()) std::cout << "********* reset to STAND #15 **********" << std::endl;
        set_animation_type(ANIM_TYPE_STAND);
	}
    execute_projectiles();
}


void classPlayer::set_teleporter(int n)
{
	//std::cout << "******** classPlayer::set_teleporter - current: " << teleporter_n << ", new: " << n << std::endl;
	teleporter_n = n;
}

int classPlayer::get_teleporter()
{
	return teleporter_n;
}



void classPlayer::teleport_stand()
{
	unsigned int waitTimer = timer.getTimer()+500;
	state.animation_state = ANIM_TYPE_TELEPORT;
	/*
	if (p2Obj) {
		p2Obj->sprite->anim_type = ANIM_TELEPORT;
	}
	*/
	soundManager.play_sfx(SFX_TELEPORT);
	while (waitTimer > timer.getTimer()) {
        draw_lib.update_screen();
		show();
		/*
		if (p2Obj) {
			show_sprite(p2Obj->sprite, game_screen);
		}
		*/
		//drawMap3rdLevel(game_screen);
		//updateScreen(game_screen);
		input.waitTime(20);
	}
}

void classPlayer::death()
{
    std::cout << "PLAYER::death" << std::endl;
    map->print_objects_number();
    reset_charging_shot();
	map->clear_animations();
    map->print_objects_number();
    map->reset_objects();
    map->print_objects_number();
	dead = true;
    _obj_jump.interrupt();
    _obj_jump.finish();
    //std::cout << "[[[freeze_weapon_effect(RESET #1)]]]" << std::endl;
    freeze_weapon_effect = FREEZE_EFFECT_NONE;
    change_player_color(true);
    set_weapon(WEAPON_DEFAULT);
    _inertia_obj.stop();
    clear_move_commands();
	input.clean();
	state.direction = ANIM_DIRECTION_RIGHT;
    gameControl.remove_current_teleporter_from_list();
    gameControl.draw_explosion(realPosition.x, realPosition.y, false);
    if (game_save.items.lifes == 0) {
        game_save.items.lifes = 3;
        std::cout << "GAME OVER" << std::endl;
        gameControl.game_over();
        return;
    }
    game_save.items.lifes--;
}

void classPlayer::reset_hp()
{
	hitPoints.current = hitPoints.total;
}

void classPlayer::change_player_color(bool full_change)
{
    //std::cout << "PLAYER::change_player_color - selected_weapon: " << selected_weapon << std::endl;
	if (full_change == false) {
		graphLib.change_surface_color(color_keys[0], weapon_colors[selected_weapon].color1, &(character_graphics_list.find(name)->second)[state.direction][state.animation_type][state.animation_state].frameSurface);
		graphLib.change_surface_color(color_keys[0], weapon_colors[selected_weapon].color2, &(character_graphics_list.find(name)->second)[state.direction][state.animation_type][state.animation_state].frameSurface);
		graphLib.change_surface_color(color_keys[0], weapon_colors[selected_weapon].color3, &(character_graphics_list.find(name)->second)[state.direction][state.animation_type][state.animation_state].frameSurface);
	} else {
        for (int i=0; i<CHAR_ANIM_DIRECTION_COUNT; i++) {
			for (int j=0; j<ANIM_TYPE_COUNT; j++) {
				for (int k=0; k<ANIM_FRAMES_COUNT; k++) {
					if (weapon_colors[selected_weapon].color1.r != -1) {
						graphLib.change_surface_color(color_keys[0], weapon_colors[selected_weapon].color1, &(character_graphics_list.find(name)->second)[i][j][k].frameSurface);
					}
					if (weapon_colors[selected_weapon].color2.r != -1) {
						graphLib.change_surface_color(color_keys[1], weapon_colors[selected_weapon].color2, &(character_graphics_list.find(name)->second)[i][j][k].frameSurface);
					}
					if (weapon_colors[selected_weapon].color3.r != -1) {
						graphLib.change_surface_color(color_keys[2], weapon_colors[selected_weapon].color3, &(character_graphics_list.find(name)->second)[i][j][k].frameSurface);
					}
				}
			}
		}
	}
    //static std::map<std::string, st_spriteFrame[CHAR_ANIM_DIRECTION_COUNT][ANIM_TYPE_COUNT][ANIM_FRAMES_COUNT]> character_graphics_list;

}

void classPlayer::set_weapon(short weapon_n)
{
	selected_weapon = weapon_n;
	change_player_color(true);
}

short classPlayer::get_weapon_value(int weapon_n)
{
	if (weapon_n == 0) {
		return hitPoints.current;
	}
    return game_save.items.weapons[weapon_n];
}

void classPlayer::set_weapon_value(Uint8 weapon_n, Uint8 value)
{
    game_save.items.weapons[weapon_n] = value;
}



CURRENT_FILE_FORMAT::file_weapon_colors classPlayer::get_weapon_colors(short int weapon_n)
{
	return weapon_colors[weapon_n];
}

short classPlayer::get_selected_weapon()
{
	return selected_weapon;
}

void classPlayer::refill_weapons()
{
	for (int i=0; i<WEAPON_COUNT; i++) {
        game_save.items.weapons[i] = PLAYER_INITIAL_HP;
	}
}

void classPlayer::set_teleport_minimal_y(int y)
{
    std::cout << "######### classPlayer::set_teleport_minimal_y - y: " << y << std::endl;
    _teleport_minimal_y = y;
}

bool classPlayer::can_fly()
{
    return false;
}


void classPlayer::add_coil_object()
{
    if (map->have_player_object() == true) { // check if any other special item is present on screen
        return;
    }
    if (game_save.items.weapons[selected_weapon] > 0) {
        //std::cout << ">>>>>>> adding coil object" << std::endl;
		st_position obj_pos;
        obj_pos.y = position.y;
		if (state.direction == ANIM_DIRECTION_LEFT) {
            obj_pos.x = position.x - 2;
		} else {
            obj_pos.x = position.x + frameSize.width + 2;
		}

        object temp_obj(game_data.player_items[0], this->map, st_position(position.x/TILESIZE, position.y/TILESIZE), st_position(-1, -1), -1); /// @TODO - remove hardcoded number
        temp_obj.set_precise_position(obj_pos, state.direction);
		temp_obj.set_duration(2500);
        temp_obj.use_teleport_in_out();
        temp_obj.set_colision_mode(COLISION_MODE_Y);
        temp_obj.set_direction(state.direction);
		map->add_object(temp_obj);
        consume_weapon(1);
    }
}

void classPlayer::add_jet_object()
{
    if (map->have_player_object() == true) {
        return;
    }
    if (game_save.items.weapons[selected_weapon] > 0) {
        //std::cout << ">>>>>>> adding JET object" << std::endl;
		st_position obj_pos;
        obj_pos.y = position.y;
        if (state.direction == ANIM_DIRECTION_LEFT) {
            obj_pos.x = position.x - 2;
        } else {
            obj_pos.x = position.x + frameSize.width + 2;
        }
        object temp_obj(game_data.player_items[1], this->map, st_position(position.x/TILESIZE, position.y/TILESIZE), st_position(-1, -1), -1);
        temp_obj.set_precise_position(obj_pos, state.direction);
        temp_obj.use_teleport_in_out();
		temp_obj.set_duration(4500);
		temp_obj.set_direction(state.direction);
		map->add_object(temp_obj);
	}
}

classnpc *classPlayer::find_nearest_npc()
{
    int lower_dist = 9999;
	classnpc* ret = NULL;
    std::vector<classnpc*>::iterator enemy_it;

    for (enemy_it=map->_npc_list.begin(); enemy_it != map->_npc_list.end(); enemy_it++) {
        if ((*enemy_it)->is_on_visible_screen() == false) {
			continue;
		}
        if ((*enemy_it)->is_dead() == true) {
            continue;
        }

        st_position npc_pos((*enemy_it)->getPosition().x*TILESIZE, (*enemy_it)->getPosition().y*TILESIZE);
		npc_pos.x = (npc_pos.x + (*enemy_it)->get_size().width/2)/TILESIZE;
        npc_pos.y = (npc_pos.y + (*enemy_it)->get_size().height)/TILESIZE;

        // pitagoras: raiz[ (x2-x1)^2 + (y2-y1)^2 ]
        int dist = sqrt(pow((float)(position.x - npc_pos.x), (float)2) + pow((float)(position.y - npc_pos.y ), (float)2));
        if (dist < lower_dist) {
            //std::cout << "PLAYER::find_nearest_npc - found NPC[" << (*enemy_it)->getName() << "], dist: " << dist << std::endl;
            lower_dist = dist;
			ret = (*enemy_it);
        }
    }
	return ret;
}

int classPlayer::find_next_weapon(int current, int move)
{
    class_config config_manager;
    int res = config_manager.find_next_weapon(current, move);
    //std::cout << "PLAYER::find_next_weapon - res: " << res << std::endl;
    return res;
}

void classPlayer::show_hp()
{
    if (_show_hp == false) {
        return;
    }
    graphLib.draw_hp_bar(get_current_hp(), get_number(), WEAPON_DEFAULT);
    if (get_selected_weapon() != WEAPON_DEFAULT) {
        graphLib.draw_hp_bar(get_weapon_value(get_selected_weapon()),get_number(), get_selected_weapon());
    }
}

void classPlayer::clean_move_commands()
{
    moveCommands.attack = 0;
    moveCommands.dash = 0;
    moveCommands.down = 0;
    moveCommands.jump = 0;
    moveCommands.left = 0;
    moveCommands.right = 0;
    moveCommands.shield = 0;
    moveCommands.start = 0;
    moveCommands.up = 0;
}

bool classPlayer::can_shoot_diagonal()
{
    if (game_data.players[_number].can_shot_diagonal) {
        return true;
    }
    // armor-pieces checking


    return false;
}

bool classPlayer::can_double_jump()
{
    if (game_data.players[_number].can_double_jump) {
        return true;
    }
    // -------------------- armor-pieces checking -------------------- //
    if (game_save.armor_pieces[ARMOR_LEGS] == true && game_data.armor_pieces[ARMOR_LEGS].special_ability[_number] == ARMOR_ABILITY_LEGS_DOUBLEJUMP) {
        return true;
    }
    return false;
}

bool classPlayer::can_air_dash()
{
    if (game_data.players[_number].can_air_dash == true) {
        return true;
    }

    if (game_save.armor_pieces[ARMOR_LEGS] == true && game_data.armor_pieces[ARMOR_LEGS].special_ability[_number] == ARMOR_ABILITY_LEGS_AIRDASH) {
        return true;
    }
    return false;
}

void classPlayer::damage(unsigned int damage_points, bool ignore_hit_timer)
{
    int new_damage_points = damage_points;
    if (game_save.armor_pieces[ARMOR_BODY] == true && game_data.armor_pieces[ARMOR_BODY].special_ability[_number] == ARMOR_ABILITY_BODY_HALFDAMAGE) {
        new_damage_points = damage_points/2;
        if (damage_points > 0 && new_damage_points <= 0) {
            new_damage_points = 1;
        }
        character::damage(new_damage_points, ignore_hit_timer);
        return;
    }
    if (damage_points == SPIKES_DAMAGE && game_save.armor_pieces[ARMOR_BODY] == true && game_data.armor_pieces[ARMOR_BODY].special_ability[_number] == ARMOR_ABILITY_BODY_SPIKESIMMMUNE) {
        return;
    }
    character::damage(damage_points, ignore_hit_timer);
}

int classPlayer::get_hit_push_back_n()
{
    if (game_save.armor_pieces[ARMOR_BODY] == true && game_data.armor_pieces[ARMOR_BODY].special_ability[_number] == ARMOR_ABILITY_BODY_NOPUSHBACK) {
        return 0;
    } else {
        return character::get_hit_push_back_n();
    }
}

bool classPlayer::have_super_shot()
{
    if (game_save.armor_pieces[ARMOR_ARMS] == true && game_data.armor_pieces[ARMOR_ARMS].special_ability[_number] == ARMOR_ABILITY_ARMS_SUPERSHOT) {
        return true;
    }
    return false;
}

bool classPlayer::have_laser_shot()
{
    if (game_save.armor_pieces[ARMOR_ARMS] == true && game_data.armor_pieces[ARMOR_ARMS].special_ability[_number] == ARMOR_ABILITY_ARMS_LASERBEAM) {
        return true;
    }
    return false;
}

bool classPlayer::have_shoryuken()
{
    if (game_save.armor_pieces[ARMOR_LEGS] == true && game_data.armor_pieces[ARMOR_LEGS].special_ability[_number] == ARMOR_ABILITY_LEGS_SHORYUKEN) {
        return true;
    }
    return false;
}

void classPlayer::update_armor_properties()
{
    if (can_double_jump() == true && _jumps_number == 1) {
        _jumps_number = 2;
    }
    if (game_save.armor_pieces[ARMOR_BODY] == true && game_data.armor_pieces[ARMOR_BODY].special_ability[_number] == ARMOR_ABILITY_BODY_EXTENDEDIMMUNITY) {
        hit_duration = 4000;
    }
    if (have_laser_shot() == true) {
        _charged_shot_projectile_id = 21;
    }
    if (game_save.armor_pieces[ARMOR_ARMS] == true && game_data.armor_pieces[ARMOR_ARMS].special_ability[_number] == ARMOR_ABILITY_ARMS_MISSILE) {
        _charged_shot_projectile_id = 22;
    }
}


void classPlayer::reset_charging_shot()
{
    if (selected_weapon != WEAPON_DEFAULT) { // only do this, if using normal weapon
        return;
    }
    state.attack_timer = 0;
    attack_button_released = true;
    soundManager.stop_repeated_sfx();
    if (color_keys[0].r != -1) {
        change_char_color(color_keys[0], color_keys[0], true);
    }
    if (color_keys[1].r != -1) {
        change_char_color(color_keys[1], color_keys[1], true);
    }
    // also reset slide/dash
    if (state.animation_type == ANIM_TYPE_SLIDE) {
        set_animation_type(ANIM_TYPE_WALK);
        state.slide_distance = 0;
    }
}

bool classPlayer::is_teleporting()
{
    if (state.animation_type == ANIM_TYPE_TELEPORT) {
        return true;
    }
    return false;
}


