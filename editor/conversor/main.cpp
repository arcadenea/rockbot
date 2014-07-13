#include <string>
#include "../../file/format.h"
#include "../../file/file_io.h"
#include <fstream>
#include <iostream>
#include <sstream>

//format_v2_0::file_game game_data;
//format_v_2_0_1::file_game new_game_data;
format_v_2_0_2::file_game game_data_v202;
format_v_2_0_3::file_game game_data_v203;
format_v_2_0_4::file_game game_data_v204;
std::string FILEPATH;


format_v_2_1::file_game game_data_v21;
format_v_2_1_1::file_game game_data_v211;

format_v_2_1_1::file_stages v211_stages;

int sprite_n=0;

std::string cent_number(int n) {
	std::stringstream ss;

	if (n < 10) {
		ss << "00" << n;
	} else if (n < 100) {
		ss << "0" << n;
	} else {
		ss << n;
	}
	return ss.str();
}

void convert_game_npcs() {
    format_v2_0::file_game game_data;
	std::ifstream fp;
	struct format_v1_0::st_file_npc temp_npc;
	std::string filename = FILEPATH + "data/game/game_001/main_list.npc";
	int i = 0;

	fp.open(filename.c_str(), std::ios::in | std::ios::binary | std::ios::app);
	if (!fp.is_open()) {
		std::cout << "ERROR::convert_game_npcs - could not load file '" << filename << std::endl;
		return;
	}

	while (!fp.eof() && i < GAME_MAX_OBJS) {
		fp.read(reinterpret_cast<char *>(&temp_npc), sizeof(temp_npc));
		game_data.game_npcs[i].id = i;
		game_data.game_npcs[i].can_shoot = temp_npc.can_shoot;
		game_data.game_npcs[i].direction = temp_npc.direction;
		game_data.game_npcs[i].facing = temp_npc.facing;
		for (int j=0; j<NPC_FRAME_NUMBER; j++) {
			game_data.game_npcs[i].frames[j].state = static_cast<format_v2_0::ANIM_STATES>(temp_npc.frameset[j]);
			game_data.game_npcs[i].frames[j].duration = temp_npc.frameset_time[j];
		}
		game_data.game_npcs[i].frame_size.width = temp_npc.framesize_w;
		game_data.game_npcs[i].frame_size.heigth = temp_npc.framesize_h;
		//std::cout << "1. convert_game_npcs - i: " << i << ", temp_npc.graphic_filename: " << temp_npc.graphic_filename << std::endl;
		sprintf(game_data.game_npcs[i].graphic_filename, "%s", temp_npc.graphic_filename);
		game_data.game_npcs[i].hp = temp_npc.hp;
		game_data.game_npcs[i].IA_type = temp_npc.IA_type;
		//game_data.game_npcs[i].name = temp_npc.name;
		//std::cout << "2. convert_game_npcs - i: " << i << ", temp_npc.name: " << temp_npc.name << std::endl;
		sprintf(game_data.game_npcs[i].name, "%s", temp_npc.name);
		std::cout << "3. convert_game_npcs - game_data.game_npcs[" << i << "].name: " << game_data.game_npcs[i].name << ", temp_npc.name: " << temp_npc.name << std::endl;
		game_data.game_npcs[i].projectile_id[0] = temp_npc.projectile_type_id;
		game_data.game_npcs[i].shield_type = temp_npc.shield_type;
		game_data.game_npcs[i].speed = temp_npc.speed;
		game_data.game_npcs[i].start_point.x = temp_npc.start_point.x;
		game_data.game_npcs[i].start_point.y = temp_npc.start_point.y;
		game_data.game_npcs[i].walk_range = temp_npc.walk_range;
		i++;
	}
	fp.close();
}

void convert_game_objects() {
    format_v2_0::file_game game_data;
	std::string filename;
	std::ifstream fp;
	//object new_obj;
	struct format_v1_0::st_object temp_obj;
	int obj_n = 0;

	for (int i=1; i<999; i++) {
		filename = FILEPATH + "data/game/game_001/" + cent_number(i) + ".obj";
		fp.open(filename.c_str(), std::ios::out | std::ios::binary);

		if (!fp.is_open()) {
			std::cout << "ERROR::game::load_game_objects - could not load file '" + filename + "'\n";
			return;
		}

		//while (!fp.eof() && i < GAME_MAX_OBJS) {
			fp.read(reinterpret_cast<char *>(&temp_obj), sizeof(temp_obj));
			game_data.objects[obj_n].id = obj_n;
			game_data.objects[obj_n].direction = temp_obj.direction;
			game_data.objects[obj_n].distance = temp_obj.distance;
			sprintf(game_data.objects[obj_n].graphic_filename, "%s", temp_obj.filename);
			game_data.objects[obj_n].frame = temp_obj.frame;
			game_data.objects[obj_n].limit = temp_obj.limit;
			sprintf(game_data.objects[obj_n].name, "%s", temp_obj.name);
			game_data.objects[obj_n].size.width = temp_obj.framesize_w;
			game_data.objects[obj_n].size.heigth = temp_obj.framesize_h;
			game_data.objects[obj_n].speed = temp_obj.speed;
			game_data.objects[obj_n].timer = temp_obj.timer;
			game_data.objects[obj_n].type = temp_obj.type;
			std::cout << "Added object[" << obj_n << "] called '" << temp_obj.name << "'" << std::endl;
			obj_n++;
		//}
		fp.close();
	}
}


void convert_links() {
    format_v2_0::file_game game_data;
	struct format_v1_0::st_map_link link;
	std::ifstream fp;
	std::string filename;
	int link_n[MAX_STAGES];
	for (int i=0; i<MAX_STAGES; i++) {
		link_n[i] = 0;
	}

	filename = FILEPATH + "data/game/game_001/map_links.dat";
	fp.open(filename.c_str(), std::ios::out | std::ios::binary);
	if (!fp.is_open()) {
		std::cout << "ERROR::game::load_map_links - could not load file '" + filename + "'\n";
		return;
	}

	while (!fp.eof()) {
		fp.read(reinterpret_cast<char *>(&link), sizeof(link));
		if (link.link_bidi==1) {
			game_data.stages[link.stage].links[link_n[link.stage]].bidirecional = true;
		} else {
			game_data.stages[link.stage].links[link_n[link.stage]].bidirecional = false;
		}
		game_data.stages[link.stage].links[link_n[link.stage]].id_map_destiny = link.map_dest;
		game_data.stages[link.stage].links[link_n[link.stage]].id_map_origin = link.map_origin;
		game_data.stages[link.stage].links[link_n[link.stage]].is_door = link.is_door;
		game_data.stages[link.stage].links[link_n[link.stage]].pos_destiny.x = link.link_dest.x;
		game_data.stages[link.stage].links[link_n[link.stage]].pos_destiny.y = link.link_dest.y;
		game_data.stages[link.stage].links[link_n[link.stage]].pos_origin.x = link.link_pos.x;
		game_data.stages[link.stage].links[link_n[link.stage]].pos_origin.y = link.link_pos.y;
		game_data.stages[link.stage].links[link_n[link.stage]].size = link.link_size;
		game_data.stages[link.stage].links[link_n[link.stage]].type = link.link_type;
		link_n[link.stage]++;
	}
	fp.close();
}

void convert_map_npcs(int stage_n, int map_n) {
    format_v2_0::file_game game_data;
	std::stringstream full_filename;
	int i =0;
	struct format_v1_0::st_file_map_npc temp_map_npc;

	full_filename << FILEPATH << "data/game/game_001/stage_" << cent_number(stage_n) << "/map_" << cent_number(map_n) << "_npc_list.dat";

	std::ifstream fp;
	fp.open(full_filename.str().c_str(), std::ios::out | std::ios::binary);
	if (!fp.is_open()) {
		std::cout << "ERROR::convert_map_npcs - could not load file '" << full_filename.str() << "'\n";
		return;
	}

	while (!fp.eof() && i < GAME_MAX_OBJS) {
		fp.read(reinterpret_cast<char *>(&temp_map_npc), sizeof(struct format_v1_0::st_file_map_npc));
		if (temp_map_npc.id > GAME_MAX_OBJS) {
			continue;
		}
		if (game_data.game_npcs[temp_map_npc.id].id == -1) {
			//std::cout << "ERROR::convert_map_npcs - NPC with ID " << temp_map_npc.id << " not found in game NPC list." << std::endl;
			continue;
		}
		if (temp_map_npc.start_point.y > 15) {
			//std::cout << "ERROR: NPC with ID " << temp_map_npc.id << " out of map, y: " << temp_map_npc.start_point.y << std::endl;
			continue;
		}
		game_data.stages[stage_n].maps[map_n].map_npcs[i].id_npc = temp_map_npc.id;
		game_data.stages[stage_n].maps[map_n].map_npcs[i].direction = temp_map_npc.direction;
		game_data.stages[stage_n].maps[map_n].map_npcs[i].start_point.x = temp_map_npc.start_point.x;
		game_data.stages[stage_n].maps[map_n].map_npcs[i].start_point.y = temp_map_npc.start_point.y;
		i++;
	}
}


void convert_map_objects(int stage_n, int map_n) {
	int i =0;
	struct format_v1_0::st_file_object temp_map_obj;
    format_v2_0::file_game game_data;

	// load from file
	std::stringstream full_filename;
	full_filename << FILEPATH << "data/game/game_001/stage_" << cent_number(stage_n) << "/" << cent_number(map_n) << ".map.obj";

	//std::cout << "classMap::load_map_objects - filename: " << full_filename.str() << std::endl;

	std::ifstream fp;
	fp.open(full_filename.str().c_str(), std::ios::out | std::ios::binary);
	if (!fp.is_open()) {
		std::cout << "ERROR::convert_map_objects - could not load file '" << full_filename.str() << "'\n";
		return;
	}

	while (!fp.eof()) {
		fp.read(reinterpret_cast<char *>(&temp_map_obj), sizeof(struct format_v1_0::st_file_object));
		int int_id = atoi(temp_map_obj.id);
		int_id--; // adjustment because old system numbering starts in ONE instead of ZERO
		if (int_id == -1 || int_id > MAX_MAP_NPC_N || temp_map_obj.id[0] != '0') {
			//std::cout << "ERROR::convert_map_objects - Object with ID " << temp_map_obj.id << " not found in game Object list." << std::endl;
			continue;
		}
		std::cout << ">> map_obj.id: " << int_id << ", stage_n: " << stage_n << ", map_n: " << map_n << ", temp_map_obj.id: " << temp_map_obj.id << ", x: " << temp_map_obj.start_point.x << ", y: " << temp_map_obj.start_point.y << std::endl;
		game_data.stages[stage_n].maps[map_n].map_objects[i].id_object = int_id;
		game_data.stages[stage_n].maps[map_n].map_objects[i].direction = ANIM_DIRECTION_LEFT;
		game_data.stages[stage_n].maps[map_n].map_objects[i].start_point.x = temp_map_obj.start_point.x;
		game_data.stages[stage_n].maps[map_n].map_objects[i].start_point.y = temp_map_obj.start_point.y;
		i++;
	}
}

void convert_map(int stage_n, int map_n) {
    format_v2_0::file_game game_data;
	std::stringstream full_filename;
	struct format_v1_0::file_map_v1 map_tiles;

	full_filename << FILEPATH << "data/game/game_001/stage_" << cent_number(stage_n) << "/" << cent_number(map_n) << "_map.dat";

	std::ifstream fp;
	fp.open(full_filename.str().c_str(), std::ios::out | std::ios::binary);
	if (!fp.is_open()) {
		std::cout << "ERROR::convert_map_objects - could not load file '" << full_filename.str() << "'\n";
		return;
	}

	fp.read(reinterpret_cast<char *>(&map_tiles), sizeof(struct format_v1_0::file_map_v1));
	game_data.stages[stage_n].maps[map_n].id = map_n;
	for (int i=0; i<MAP_W; i++) {
		for (int j=0; j<MAP_H; j++) {
			game_data.stages[stage_n].maps[map_n].tiles[i][j].id = j*MAP_H+i;
			game_data.stages[stage_n].maps[map_n].tiles[i][j].locked = map_tiles.tiles[i][j].locked;
			game_data.stages[stage_n].maps[map_n].tiles[i][j].tile1.x = map_tiles.tiles[i][j].tile1.x;
			game_data.stages[stage_n].maps[map_n].tiles[i][j].tile1.y = map_tiles.tiles[i][j].tile1.y;
			game_data.stages[stage_n].maps[map_n].tiles[i][j].tile2.x = map_tiles.tiles[i][j].tile2.x;
			game_data.stages[stage_n].maps[map_n].tiles[i][j].tile2.y = map_tiles.tiles[i][j].tile2.y;
			game_data.stages[stage_n].maps[map_n].tiles[i][j].tile3.x = map_tiles.tiles[i][j].tile3.x;
			game_data.stages[stage_n].maps[map_n].tiles[i][j].tile3.y = map_tiles.tiles[i][j].tile3.y;
		}
	}
	fp.close();

}


void convert_stages() {
    format_v2_0::file_game game_data;
	std::string filename = FILEPATH + "/data/game/game_001/stages.dat";
	std::ifstream fp;
	int i = 0;
	format_v1_0::st_file_stage temp_stage;

	fp.open(filename.c_str(), std::ios::out | std::ios::binary);
	if (!fp.is_open()) {
		std::cout << "ERROR::convert_stages - could not load file '" + filename + "'\n";
		return;
	}

	while (!fp.eof()) {
		fp.read(reinterpret_cast<char *>(&temp_stage), sizeof(format_v1_0::st_file_stage));
		game_data.stages[i].id = i;
		std::cout << "Converting stage #" << i << std::endl;
		sprintf(game_data.stages[i].bgmusic_filename, "%s", temp_stage.bg_music_filename);
		/// @TODO: game_data.stages[i].boss = temp_stage.;
		/// @TODO: game_data.stages[i].boss_dialog = temp_stage.;
		for (int j=0; j<3; j++) {
			for (int k=0; k<format_v2_0::COLOR_KEY_LENGTH; k++) {
				game_data.stages[i].colorcycle.color[j][k].r = temp_stage.colorcycle[k].current_color[j].r;
				game_data.stages[i].colorcycle.color[j][k].g = temp_stage.colorcycle[k].current_color[j].g;
				game_data.stages[i].colorcycle.color[j][k].b = temp_stage.colorcycle[k].current_color[j].b;
				game_data.stages[i].colorcycle.duration[j][k] = temp_stage.colorcycle[k].current_color[j].duration;
			}
		}
		/// @TODO: game_data.stages[i].intro_dialog = temp_stage.;
		for (int j=0; j<3; j++) {
			game_data.stages[i].maps[j].id = j;
			convert_map(i, j);
			convert_map_npcs(i, j);
			convert_map_objects(i, j);
		}
		sprintf(game_data.stages[i].name, "%s", temp_stage.stage_name);
		i++;
	}
	fp.close();
}

/// @NOTE: direction will be handled by the game itself, we do not need to store data about it
void add_player_sprite(int player_n, int state, int pos_x, int duration)
{
    format_v2_0::file_game game_data;
	game_data.players[player_n].sprites[sprite_n].id = sprite_n;
	game_data.players[player_n].sprites[sprite_n].state = state;
	game_data.players[player_n].sprites[sprite_n].duration = duration;
	game_data.players[player_n].sprites[sprite_n].sprite_pos_x = pos_x;
	sprite_n++;
}


void fill_player_sprites(int player_n) {
	add_player_sprite(player_n, ANIM_TYPE_STAND, 3, 5000);
	add_player_sprite(player_n, ANIM_TYPE_STAND, 4, 150);
	// WALK
	add_player_sprite(player_n, ANIM_TYPE_WALK, 6, 150);
	add_player_sprite(player_n, ANIM_TYPE_WALK, 7, 150);
	add_player_sprite(player_n, ANIM_TYPE_WALK, 8, 150);
	// JUMP
	add_player_sprite(player_n, ANIM_TYPE_JUMP, 9, 150);
	// ATTACK
	add_player_sprite(player_n, ANIM_TYPE_ATTACK, 11, 150);
	// ATTACK + JUMP
	add_player_sprite(player_n, ANIM_TYPE_JUMP_ATTACK, 10, 80);
	// ATTACK + WALK
	add_player_sprite(player_n, ANIM_TYPE_WALK_ATTACK, 12, 150);
	add_player_sprite(player_n, ANIM_TYPE_WALK_ATTACK, 13, 150);
	add_player_sprite(player_n, ANIM_TYPE_WALK_ATTACK, 14, 150);
	// HIT
	add_player_sprite(player_n, ANIM_TYPE_HIT, 15, 150);
	// TELEPORT
	add_player_sprite(player_n, ANIM_TYPE_TELEPORT, 0, 750);
	add_player_sprite(player_n, ANIM_TYPE_TELEPORT, 1, 300);
	add_player_sprite(player_n, ANIM_TYPE_TELEPORT, 2, 150);
	// STAIRS
	add_player_sprite(player_n, ANIM_TYPE_STAIRS, 17, 5000); /// @TODO: animation of stairs must switch between left/right sprites
	// stairs semi
	add_player_sprite(player_n, ANIM_TYPE_STAIRS_SEMI, 18, 5000); /// @TODO: animation of stairs must switch between left/right sprites
	// stairs + move
	add_player_sprite(player_n, ANIM_TYPE_STAIRS_MOVE, 17, 200);
	// stairs + attack
	add_player_sprite(player_n, ANIM_TYPE_STAIRS_ATTACK, 19, 200);
    // slide/dash
    add_player_sprite(player_n, ANIM_TYPE_SLIDE, 20, 200);
}

void fill_players_weapon_colors() {
    format_v2_0::file_game game_data;
	// APEBOT PLAYER #1
	game_data.players[0].weapon_colors[WEAPON_APEBOT].color1.r = 139;
	game_data.players[0].weapon_colors[WEAPON_APEBOT].color1.g = 115;
	game_data.players[0].weapon_colors[WEAPON_APEBOT].color1.b = 0;
	game_data.players[0].weapon_colors[WEAPON_APEBOT].color2.r = 196;
	game_data.players[0].weapon_colors[WEAPON_APEBOT].color2.g = 93;
	game_data.players[0].weapon_colors[WEAPON_APEBOT].color2.b = 0;
	// APEBOT PLAYER #2
	game_data.players[1].weapon_colors[WEAPON_APEBOT].color1.r = 139; // laranja claro
	game_data.players[1].weapon_colors[WEAPON_APEBOT].color1.g = 115;
	game_data.players[1].weapon_colors[WEAPON_APEBOT].color1.b = 0;
	game_data.players[1].weapon_colors[WEAPON_APEBOT].color2.r = 67; // laranja escuro
	game_data.players[1].weapon_colors[WEAPON_APEBOT].color2.g = 47;
	game_data.players[1].weapon_colors[WEAPON_APEBOT].color2.b = 0;
	game_data.players[1].weapon_colors[WEAPON_APEBOT].color3.r = 255; // amarelo
	game_data.players[1].weapon_colors[WEAPON_APEBOT].color3.g = 231;
	game_data.players[1].weapon_colors[WEAPON_APEBOT].color3.b = 163;

	// DAISIEBOT PLAYER #1
	game_data.players[0].weapon_colors[WEAPON_DAISIEBOT].color1.r = 79;
	game_data.players[0].weapon_colors[WEAPON_DAISIEBOT].color1.g = 223;
	game_data.players[0].weapon_colors[WEAPON_DAISIEBOT].color1.b = 75;
	game_data.players[0].weapon_colors[WEAPON_DAISIEBOT].color2.r = 255;
	game_data.players[0].weapon_colors[WEAPON_DAISIEBOT].color2.g = 119;
	game_data.players[0].weapon_colors[WEAPON_DAISIEBOT].color2.b = 183;
	// DAISIEBOT PLAYER #2
	game_data.players[1].weapon_colors[WEAPON_DAISIEBOT].color1.r = 79; // laranja claro
	game_data.players[1].weapon_colors[WEAPON_DAISIEBOT].color1.g = 233;
	game_data.players[1].weapon_colors[WEAPON_DAISIEBOT].color1.b = 75;
	game_data.players[1].weapon_colors[WEAPON_DAISIEBOT].color2.r = 0; // laranja escuro
	game_data.players[1].weapon_colors[WEAPON_DAISIEBOT].color2.g = 147;
	game_data.players[1].weapon_colors[WEAPON_DAISIEBOT].color2.b = 59;
	game_data.players[1].weapon_colors[WEAPON_DAISIEBOT].color3.r = 255; // amarelo
	game_data.players[1].weapon_colors[WEAPON_DAISIEBOT].color3.g = 119;
	game_data.players[1].weapon_colors[WEAPON_DAISIEBOT].color3.b = 183;

	// DYNAMITEBOT PLAYER #1
	game_data.players[0].weapon_colors[WEAPON_DYNAMITEBOT].color1.r = 188;
	game_data.players[0].weapon_colors[WEAPON_DYNAMITEBOT].color1.g = 188;
	game_data.players[0].weapon_colors[WEAPON_DYNAMITEBOT].color1.b = 188;
	game_data.players[0].weapon_colors[WEAPON_DYNAMITEBOT].color2.r = 0;
	game_data.players[0].weapon_colors[WEAPON_DYNAMITEBOT].color2.g = 171;
	game_data.players[0].weapon_colors[WEAPON_DYNAMITEBOT].color2.b = 0;
	// player 2
	game_data.players[1].weapon_colors[WEAPON_DYNAMITEBOT].color1.r = 188; // laranja claro
	game_data.players[1].weapon_colors[WEAPON_DYNAMITEBOT].color1.g = 188;
	game_data.players[1].weapon_colors[WEAPON_DYNAMITEBOT].color1.b = 188;
	game_data.players[1].weapon_colors[WEAPON_DYNAMITEBOT].color2.r = 81; // laranja escuro
	game_data.players[1].weapon_colors[WEAPON_DYNAMITEBOT].color2.g = 81;
	game_data.players[1].weapon_colors[WEAPON_DYNAMITEBOT].color2.b = 81;
	game_data.players[1].weapon_colors[WEAPON_DYNAMITEBOT].color3.r = 0; // amarelo
	game_data.players[1].weapon_colors[WEAPON_DYNAMITEBOT].color3.g = 171;
	game_data.players[1].weapon_colors[WEAPON_DYNAMITEBOT].color3.b = 0;

	// MUMMYBOT
	game_data.players[0].weapon_colors[WEAPON_MUMMYBOT].color1.r = 255;
	game_data.players[0].weapon_colors[WEAPON_MUMMYBOT].color1.g = 255;
	game_data.players[0].weapon_colors[WEAPON_MUMMYBOT].color1.b = 255;
	game_data.players[0].weapon_colors[WEAPON_MUMMYBOT].color2.r = 0;
	game_data.players[0].weapon_colors[WEAPON_MUMMYBOT].color2.g = 115;
	game_data.players[0].weapon_colors[WEAPON_MUMMYBOT].color2.b = 239;
	// player 2
	game_data.players[1].weapon_colors[WEAPON_MUMMYBOT].color1.r = 255; // laranja claro
	game_data.players[1].weapon_colors[WEAPON_MUMMYBOT].color1.g = 255;
	game_data.players[1].weapon_colors[WEAPON_MUMMYBOT].color1.b = 255;
	game_data.players[1].weapon_colors[WEAPON_MUMMYBOT].color2.r = 63; // laranja escuro
	game_data.players[1].weapon_colors[WEAPON_MUMMYBOT].color2.g = 191;
	game_data.players[1].weapon_colors[WEAPON_MUMMYBOT].color2.b = 255;
	game_data.players[1].weapon_colors[WEAPON_MUMMYBOT].color3.r = 171; // amarelo
	game_data.players[1].weapon_colors[WEAPON_MUMMYBOT].color3.g = 231;
	game_data.players[1].weapon_colors[WEAPON_MUMMYBOT].color3.b = 255;

	// SPIKEBOT
	game_data.players[0].weapon_colors[WEAPON_SPIKEBOT].color1.r = 81;
	game_data.players[0].weapon_colors[WEAPON_SPIKEBOT].color1.g = 81;
	game_data.players[0].weapon_colors[WEAPON_SPIKEBOT].color1.b = 81;
	game_data.players[0].weapon_colors[WEAPON_SPIKEBOT].color2.r = 0;
	game_data.players[0].weapon_colors[WEAPON_SPIKEBOT].color2.g = 235;
	game_data.players[0].weapon_colors[WEAPON_SPIKEBOT].color2.b = 219;
	// player 2
	game_data.players[1].weapon_colors[WEAPON_SPIKEBOT].color1.r = 167; // laranja claro
	game_data.players[1].weapon_colors[WEAPON_SPIKEBOT].color1.g = 139;
	game_data.players[1].weapon_colors[WEAPON_SPIKEBOT].color1.b = 253;
	game_data.players[1].weapon_colors[WEAPON_SPIKEBOT].color2.r = 131; // laranja escuro
	game_data.players[1].weapon_colors[WEAPON_SPIKEBOT].color2.g = 0;
	game_data.players[1].weapon_colors[WEAPON_SPIKEBOT].color2.b = 243;
	game_data.players[1].weapon_colors[WEAPON_SPIKEBOT].color3.r = 0; // amarelo
	game_data.players[1].weapon_colors[WEAPON_SPIKEBOT].color3.g = 235;
	game_data.players[1].weapon_colors[WEAPON_SPIKEBOT].color3.b = 219;

	// TECHNOBOT
	game_data.players[0].weapon_colors[WEAPON_TECHNOBOT].color1.r = 219;
	game_data.players[0].weapon_colors[WEAPON_TECHNOBOT].color1.g = 43;
	game_data.players[0].weapon_colors[WEAPON_TECHNOBOT].color1.b = 0;
	game_data.players[0].weapon_colors[WEAPON_TECHNOBOT].color2.r = 243;
	game_data.players[0].weapon_colors[WEAPON_TECHNOBOT].color2.g = 191;
	game_data.players[0].weapon_colors[WEAPON_TECHNOBOT].color2.b = 63;
	// player 2
	game_data.players[1].weapon_colors[WEAPON_TECHNOBOT].color1.r = 167; // laranja claro
	game_data.players[1].weapon_colors[WEAPON_TECHNOBOT].color1.g = 0;
	game_data.players[1].weapon_colors[WEAPON_TECHNOBOT].color1.b = 0;
	game_data.players[1].weapon_colors[WEAPON_TECHNOBOT].color2.r = 127; // laranja escuro
	game_data.players[1].weapon_colors[WEAPON_TECHNOBOT].color2.g = 11;
	game_data.players[1].weapon_colors[WEAPON_TECHNOBOT].color2.b = 0;
	game_data.players[1].weapon_colors[WEAPON_TECHNOBOT].color3.r = 255; // amarelo
	game_data.players[1].weapon_colors[WEAPON_TECHNOBOT].color3.g = 102;
	game_data.players[1].weapon_colors[WEAPON_TECHNOBOT].color3.b = 0;

	// MAGEBOT
	game_data.players[0].weapon_colors[WEAPON_MAGEBOT].color1.r = 191;
	game_data.players[0].weapon_colors[WEAPON_MAGEBOT].color1.g = 0;
	game_data.players[0].weapon_colors[WEAPON_MAGEBOT].color1.b = 191;
	game_data.players[0].weapon_colors[WEAPON_MAGEBOT].color2.r = 255;
	game_data.players[0].weapon_colors[WEAPON_MAGEBOT].color2.g = 192;
	game_data.players[0].weapon_colors[WEAPON_MAGEBOT].color2.b = 0;
	// player 2
	game_data.players[1].weapon_colors[WEAPON_MAGEBOT].color1.r = 191; // laranja claro
	game_data.players[1].weapon_colors[WEAPON_MAGEBOT].color1.g = 0;
	game_data.players[1].weapon_colors[WEAPON_MAGEBOT].color1.b = 191;
	game_data.players[1].weapon_colors[WEAPON_MAGEBOT].color2.r = 143; // laranja escuro
	game_data.players[1].weapon_colors[WEAPON_MAGEBOT].color2.g = 0;
	game_data.players[1].weapon_colors[WEAPON_MAGEBOT].color2.b = 119;
	game_data.players[1].weapon_colors[WEAPON_MAGEBOT].color3.r = 255; // amarelo
	game_data.players[1].weapon_colors[WEAPON_MAGEBOT].color3.g = 192;
	game_data.players[1].weapon_colors[WEAPON_MAGEBOT].color3.b = 0;

	// SEAHORSEBOT
	game_data.players[0].weapon_colors[WEAPON_SEAHORSEBOT].color1.r = 0;
	game_data.players[0].weapon_colors[WEAPON_SEAHORSEBOT].color1.g = 131;
	game_data.players[0].weapon_colors[WEAPON_SEAHORSEBOT].color1.b = 139;
	game_data.players[0].weapon_colors[WEAPON_SEAHORSEBOT].color2.r = 219;
	game_data.players[0].weapon_colors[WEAPON_SEAHORSEBOT].color2.g = 43;
	game_data.players[0].weapon_colors[WEAPON_SEAHORSEBOT].color2.b = 0;
	// player 2
	game_data.players[1].weapon_colors[WEAPON_SEAHORSEBOT].color1.r = 171; // laranja claro
	game_data.players[1].weapon_colors[WEAPON_SEAHORSEBOT].color1.g = 243;
	game_data.players[1].weapon_colors[WEAPON_SEAHORSEBOT].color1.b = 191;
	game_data.players[1].weapon_colors[WEAPON_SEAHORSEBOT].color2.r = 0; // laranja escuro
	game_data.players[1].weapon_colors[WEAPON_SEAHORSEBOT].color2.g = 131;
	game_data.players[1].weapon_colors[WEAPON_SEAHORSEBOT].color2.b = 139;
	game_data.players[1].weapon_colors[WEAPON_SEAHORSEBOT].color3.r = 219; // amarelo
	game_data.players[1].weapon_colors[WEAPON_SEAHORSEBOT].color3.g = 43;
	game_data.players[1].weapon_colors[WEAPON_SEAHORSEBOT].color3.b = 0;

	// ITEM_COIL
	game_data.players[0].weapon_colors[WEAPON_ITEM_COIL].color1.r = 255;
	game_data.players[0].weapon_colors[WEAPON_ITEM_COIL].color1.g = 51;
	game_data.players[0].weapon_colors[WEAPON_ITEM_COIL].color1.b = 0;
	game_data.players[0].weapon_colors[WEAPON_ITEM_COIL].color2.r = 235;
	game_data.players[0].weapon_colors[WEAPON_ITEM_COIL].color2.g = 235;
	game_data.players[0].weapon_colors[WEAPON_ITEM_COIL].color2.b = 235;
	// player 2
	game_data.players[1].weapon_colors[WEAPON_ITEM_COIL].color1.r = 255; // laranja claro
	game_data.players[1].weapon_colors[WEAPON_ITEM_COIL].color1.g = 51;
	game_data.players[1].weapon_colors[WEAPON_ITEM_COIL].color1.b = 0;
	game_data.players[1].weapon_colors[WEAPON_ITEM_COIL].color2.r = 219; // laranja escuro
	game_data.players[1].weapon_colors[WEAPON_ITEM_COIL].color2.g = 43;
	game_data.players[1].weapon_colors[WEAPON_ITEM_COIL].color2.b = 0;
	game_data.players[1].weapon_colors[WEAPON_ITEM_COIL].color3.r = 235; // amarelo
	game_data.players[1].weapon_colors[WEAPON_ITEM_COIL].color3.g = 235;
	game_data.players[1].weapon_colors[WEAPON_ITEM_COIL].color3.b = 235;

	// ITEM_JET
	game_data.players[0].weapon_colors[WEAPON_ITEM_JET].color1.r = 235;
	game_data.players[0].weapon_colors[WEAPON_ITEM_JET].color1.g = 235;
	game_data.players[0].weapon_colors[WEAPON_ITEM_JET].color1.b = 235;
	game_data.players[0].weapon_colors[WEAPON_ITEM_JET].color2.r = 255;
	game_data.players[0].weapon_colors[WEAPON_ITEM_JET].color2.g = 51;
	game_data.players[0].weapon_colors[WEAPON_ITEM_JET].color2.b = 0;
	// player 2
	game_data.players[1].weapon_colors[WEAPON_ITEM_JET].color1.r = 235; // laranja claro
	game_data.players[1].weapon_colors[WEAPON_ITEM_JET].color1.g = 235;
	game_data.players[1].weapon_colors[WEAPON_ITEM_JET].color1.b = 235;
	game_data.players[1].weapon_colors[WEAPON_ITEM_JET].color2.r = 188; // laranja escuro
	game_data.players[1].weapon_colors[WEAPON_ITEM_JET].color2.g = 188;
	game_data.players[1].weapon_colors[WEAPON_ITEM_JET].color2.b = 188;
	game_data.players[1].weapon_colors[WEAPON_ITEM_JET].color3.r = 255; // amarelo
	game_data.players[1].weapon_colors[WEAPON_ITEM_JET].color3.g = 51;
	game_data.players[1].weapon_colors[WEAPON_ITEM_JET].color3.b = 0;

	// DEFAULT COLORS
	game_data.players[0].weapon_colors[WEAPON_DEFAULT].color1.r = 143;
	game_data.players[0].weapon_colors[WEAPON_DEFAULT].color1.g = 0;
	game_data.players[0].weapon_colors[WEAPON_DEFAULT].color1.b = 119;
	game_data.players[0].weapon_colors[WEAPON_DEFAULT].color2.r = 0;
	game_data.players[0].weapon_colors[WEAPON_DEFAULT].color2.g = 115;
	game_data.players[0].weapon_colors[WEAPON_DEFAULT].color2.b = 239;
	// player 2
	game_data.players[1].weapon_colors[WEAPON_DEFAULT].color1.r = 255; // laranja claro
	game_data.players[1].weapon_colors[WEAPON_DEFAULT].color1.g = 102;
	game_data.players[1].weapon_colors[WEAPON_DEFAULT].color1.b = 0;
	game_data.players[1].weapon_colors[WEAPON_DEFAULT].color2.r = 255; // laranja escuro
	game_data.players[1].weapon_colors[WEAPON_DEFAULT].color2.g = 51;
	game_data.players[1].weapon_colors[WEAPON_DEFAULT].color2.b = 0;
	game_data.players[1].weapon_colors[WEAPON_DEFAULT].color3.r = 230; // amarelo
	game_data.players[1].weapon_colors[WEAPON_DEFAULT].color3.g = 255;
	game_data.players[1].weapon_colors[WEAPON_DEFAULT].color3.b = 0;




}


void fill_players() {
	// ROCKBOT
    format_v2_0::file_game game_data;
	game_data.players[0].id = 0;
	sprintf(game_data.players[0].name, "%s", "Rockbot");
	sprintf(game_data.players[0].graphic_filename, "%s", "p1.png");
	sprintf(game_data.players[0].face_filename, "%s", "rockbot.png");
	game_data.players[0].have_shield = false;
	game_data.players[0].HP = 28;
	game_data.players[0].jump_initial_speed = 9;
	game_data.players[0].jump_gravity = 0.12;
	game_data.players[0].max_shots = 3;
	game_data.players[0].simultaneous_shots = 1;
	game_data.players[0].fall_gravity = 0.25;
	game_data.players[0].move_speed = 3;
	game_data.players[0].sprite_hit_area.x = 4; /// @TODO: change graphics, so the sprite is centered to match the hit-area
	game_data.players[0].sprite_hit_area.y = 8;
	game_data.players[0].sprite_hit_area.w = 21;
	game_data.players[0].sprite_hit_area.h = 24;
	game_data.players[0].sprite_size.width = 29;
	game_data.players[0].sprite_size.heigth = 32;


	// BETABOT
	game_data.players[0].id = 1;
	sprintf(game_data.players[1].name, "%s", "Betabot");
	sprintf(game_data.players[1].graphic_filename, "%s", "p2.png");
	sprintf(game_data.players[1].face_filename, "%s", "betabot.png");
	game_data.players[1].have_shield = false;
	game_data.players[1].HP = 28;
	game_data.players[1].jump_initial_speed = 11;
	game_data.players[1].jump_gravity = 0.18;
	game_data.players[1].max_shots = 2;
	game_data.players[1].simultaneous_shots = 2;
	game_data.players[1].fall_gravity = 0.35;
	game_data.players[1].move_speed = 2;
	game_data.players[1].sprite_hit_area.x = 4; /// @TODO: change graphics, so the sprite is centered to match the hit-area
	game_data.players[1].sprite_hit_area.y = 8;
	game_data.players[1].sprite_hit_area.w = 21;
	game_data.players[1].sprite_hit_area.h = 24;
	game_data.players[1].sprite_size.width = 29;
	game_data.players[1].sprite_size.heigth = 32;

	// weapon colors
	game_data.players[0].color_keys[0].r = 143;
	game_data.players[0].color_keys[0].g = 0;
	game_data.players[0].color_keys[0].b = 119;
	game_data.players[0].color_keys[1].r = 0;
	game_data.players[0].color_keys[1].g = 115;
	game_data.players[0].color_keys[1].b = 239;

	game_data.players[1].color_keys[0].r = 255;
	game_data.players[1].color_keys[0].g = 102;
	game_data.players[1].color_keys[0].b = 0;
	game_data.players[1].color_keys[1].r = 255;
	game_data.players[1].color_keys[1].g = 51;
	game_data.players[1].color_keys[1].b = 0;
	game_data.players[1].color_keys[2].r = 230;
	game_data.players[1].color_keys[2].g = 255;
	game_data.players[1].color_keys[2].b = 0;

	fill_players_weapon_colors();

	// fill sprites for all players
	for (int i=0; i<MAX_FILE_PLAYERS; i++) {
		sprite_n = 0;
		fill_player_sprites(i);
	}
}

int find_npc_id_by_name(std::string name, int stage_n) {
    format_v2_0::file_game game_data;
	for (int i=0; i<STAGE_MAX_MAPS; i++) {
		for (int j=0; j<MAX_MAP_NPC_N; j++) {
			if (game_data.stages[stage_n].maps[i].map_npcs[j].id_npc != 1) {
				if (!strcmp(game_data.game_npcs[game_data.stages[stage_n].maps[i].map_npcs[j].id_npc].name, name.c_str())) {
					return game_data.stages[stage_n].maps[i].map_npcs[j].id_npc;
				}
			}
		}
	}
	return -1;
}

void fill_bosses() {
    format_v2_0::file_game game_data;
	//std::string boss_names[STAGE_COUNT] = {"Intro Boss", "Apbe Bot", "Daisie Bot", "Seahorse Bot", "Mummy Bot", "Skill Castle Boss", "Mage Bot", "Dynamite Bot", "Spike Bot", "Techno Bot", "Skull Castle 2 Boss", , "Skull Castle 3 Boss", "Skull Castle 4 Boss"};
	//INTRO_STAGE, APEBOT, DAISIEBOT, SEAHORSEBOT, MUMMYBOT, SKULLCASTLE1, MAGEBOT, DYNAMITEBOT, SPIKEBOT, TECHNOBOT, SKULLCASTLE2, SKULLCASTLE3, SKULLCASTLE4, STAGE_COUNT
	int npc_n;

	npc_n = find_npc_id_by_name("Ape Bot", APEBOT);
	game_data.stages[INTRO_STAGE].boss.id_npc = npc_n;
	sprintf(game_data.stages[INTRO_STAGE].boss.face_graphics_filename, "%s", "apebot.png");
	game_data.stages[INTRO_STAGE].boss.id_weapon = WEAPON_APEBOT;
	sprintf(game_data.stages[INTRO_STAGE].boss.name, "%s", "Ape Bot");

	npc_n = find_npc_id_by_name("Ape Bot", APEBOT);
	game_data.stages[APEBOT].boss.id_npc = npc_n;
	sprintf(game_data.stages[APEBOT].boss.face_graphics_filename, "%s", "apebot.png");
	game_data.stages[APEBOT].boss.id_weapon = WEAPON_APEBOT;
	sprintf(game_data.stages[APEBOT].boss.name, "%s", "Ape Bot");

	npc_n = find_npc_id_by_name("Daisie Bot", DAISIEBOT);
	game_data.stages[DAISIEBOT].boss.id_npc = npc_n;
	sprintf(game_data.stages[DAISIEBOT].boss.face_graphics_filename, "%s", "daisiebot.png");
	game_data.stages[DAISIEBOT].boss.id_weapon = WEAPON_DAISIEBOT;
	sprintf(game_data.stages[DAISIEBOT].boss.name, "%s", "Daisie Bot");

	npc_n = find_npc_id_by_name("Seahorse Bot", SEAHORSEBOT);
	game_data.stages[SEAHORSEBOT].boss.id_npc = npc_n;
	sprintf(game_data.stages[SEAHORSEBOT].boss.face_graphics_filename, "%s", "seahorsebot.png");
	game_data.stages[SEAHORSEBOT].boss.id_weapon = WEAPON_SEAHORSEBOT;
	sprintf(game_data.stages[SEAHORSEBOT].boss.name, "%s", "Seahorse Bot");

	npc_n = find_npc_id_by_name("Mummy Bot", MUMMYBOT);
	game_data.stages[MUMMYBOT].boss.id_npc = npc_n;
	sprintf(game_data.stages[MUMMYBOT].boss.face_graphics_filename, "%s", "mummybot.png");
	game_data.stages[MUMMYBOT].boss.id_weapon = WEAPON_MUMMYBOT;
	sprintf(game_data.stages[MUMMYBOT].boss.name, "%s", "Mummy Bot");

	npc_n = find_npc_id_by_name("Mage Bot", MAGEBOT);
	game_data.stages[MAGEBOT].boss.id_npc = npc_n;
	sprintf(game_data.stages[MAGEBOT].boss.face_graphics_filename, "%s", "magebot.png");
	game_data.stages[MAGEBOT].boss.id_weapon = WEAPON_MAGEBOT;
	sprintf(game_data.stages[MAGEBOT].boss.name, "%s", "Mage Bot");

	npc_n = find_npc_id_by_name("Dynamite Bot", DYNAMITEBOT);
	game_data.stages[DYNAMITEBOT].boss.id_npc = npc_n;
	sprintf(game_data.stages[DYNAMITEBOT].boss.face_graphics_filename, "%s", "dynamitebot.png");
	game_data.stages[DYNAMITEBOT].boss.id_weapon = WEAPON_DYNAMITEBOT;
	sprintf(game_data.stages[DYNAMITEBOT].boss.name, "%s", "Dynamite Bot");

	npc_n = find_npc_id_by_name("Spike Bot", SPIKEBOT);
	game_data.stages[SPIKEBOT].boss.id_npc = npc_n;
	sprintf(game_data.stages[SPIKEBOT].boss.face_graphics_filename, "%s", "spikebot.png");
	game_data.stages[SPIKEBOT].boss.id_weapon = WEAPON_SPIKEBOT;
	sprintf(game_data.stages[SPIKEBOT].boss.name, "%s", "Spike Bot");

	npc_n = find_npc_id_by_name("Techno Bot", TECHNOBOT);
	game_data.stages[TECHNOBOT].boss.id_npc = npc_n;
	sprintf(game_data.stages[TECHNOBOT].boss.face_graphics_filename, "%s", "technobot.png");
	game_data.stages[TECHNOBOT].boss.id_weapon = WEAPON_TECHNOBOT;
	sprintf(game_data.stages[TECHNOBOT].boss.name, "%s", "Techno Bot");

	npc_n = find_npc_id_by_name("Destrin Tank", SKULLCASTLE1);
	game_data.stages[SKULLCASTLE1].boss.id_npc = npc_n;
	sprintf(game_data.stages[SKULLCASTLE1].boss.face_graphics_filename, "%s", "dr_destrin.png");
	game_data.stages[SKULLCASTLE1].boss.id_weapon = -1;
	sprintf(game_data.stages[SKULLCASTLE1].boss.name, "%s", "Dr. Destrin");

	npc_n = find_npc_id_by_name("Destrin Tank", SKULLCASTLE2);
	game_data.stages[SKULLCASTLE2].boss.id_npc = npc_n;
	sprintf(game_data.stages[SKULLCASTLE2].boss.face_graphics_filename, "%s", "dr_destrin.png");
	game_data.stages[SKULLCASTLE2].boss.id_weapon = -1;
	sprintf(game_data.stages[SKULLCASTLE2].boss.name, "%s", "Dr. Destrin");

	npc_n = find_npc_id_by_name("Destrin Tank", SKULLCASTLE3);
	game_data.stages[SKULLCASTLE3].boss.id_npc = npc_n;
	sprintf(game_data.stages[SKULLCASTLE3].boss.face_graphics_filename, "%s", "dr_destrin.png");
	game_data.stages[SKULLCASTLE3].boss.id_weapon = -1;
	sprintf(game_data.stages[SKULLCASTLE3].boss.name, "%s", "Dr. Destrin");

	npc_n = find_npc_id_by_name("Destrin Ship", SKULLCASTLE4);
	game_data.stages[SKULLCASTLE4].boss.id_npc = npc_n;
	sprintf(game_data.stages[SKULLCASTLE4].boss.face_graphics_filename, "%s", "dr_destrin.png");
	game_data.stages[SKULLCASTLE4].boss.id_weapon = -1;
	sprintf(game_data.stages[SKULLCASTLE4].boss.name, "%s", "Dr. Destrin");

}

void fill_dialogs()
{
    format_v2_0::file_game game_data;
	sprintf(game_data.stages[INTRO_STAGE].intro_dialog.face_graphics_filename, "%s", "canotus_face.png");
	sprintf(game_data.stages[INTRO_STAGE].intro_dialog.line1[0], "%s", "THE CITY IS UNDER");
	sprintf(game_data.stages[INTRO_STAGE].intro_dialog.line1[1], "%s", "ATTACK. YOU NEED TO");
	sprintf(game_data.stages[INTRO_STAGE].intro_dialog.line1[2], "%s", "FIND WHO IS DOING IT.");
	sprintf(game_data.stages[INTRO_STAGE].intro_dialog.answer1[0][0], "%s", "RIGHT. SO LET");
	sprintf(game_data.stages[INTRO_STAGE].intro_dialog.answer1[0][1], "%s", "THE FUN BEGIN!");
	sprintf(game_data.stages[INTRO_STAGE].intro_dialog.answer1[0][2], "%s", "ROCKBOT OFF TO DUTY.");
	sprintf(game_data.stages[INTRO_STAGE].intro_dialog.answer1[1][0], "%s", "ROGER THAT.");
	sprintf(game_data.stages[INTRO_STAGE].intro_dialog.answer1[1][1], "%s", "NO ONE WILL STAY");
	sprintf(game_data.stages[INTRO_STAGE].intro_dialog.answer1[1][2], "%s", "ON MY WAY.");


	//intro_dialog.id = APEBOT;
	sprintf(game_data.stages[APEBOT].intro_dialog.face_graphics_filename, "%s", "apebot.png");
	sprintf(game_data.stages[APEBOT].intro_dialog.line1[0], "%s", "OOK! OOK! WELCOME TO");
	sprintf(game_data.stages[APEBOT].intro_dialog.line1[1], "%s", "AFRICAN SAVANAS.");
	sprintf(game_data.stages[APEBOT].intro_dialog.line1[2], "%s", "OOK!");
	sprintf(game_data.stages[APEBOT].intro_dialog.answer1[0][0], "%s", "I HOPE YOU HAVE SOME");
	sprintf(game_data.stages[APEBOT].intro_dialog.answer1[0][1], "%s", "BANANAS WITH YOU,");
	sprintf(game_data.stages[APEBOT].intro_dialog.answer1[0][2], "%s", "'CAUSE I'LL TAKE IT!");
	sprintf(game_data.stages[APEBOT].intro_dialog.answer1[1][0], "%s", "SORRY LITTLE MONKEY.");
	sprintf(game_data.stages[APEBOT].intro_dialog.answer1[1][1], "%s", "BUT I HAVE TO BURN");
	sprintf(game_data.stages[APEBOT].intro_dialog.answer1[1][2], "%s", "IT, IF NEEDED TO WIN.");

	sprintf(game_data.stages[DAISIEBOT].intro_dialog.face_graphics_filename, "%s", "daisiebot.png");
	sprintf(game_data.stages[DAISIEBOT].intro_dialog.line1[0], "%s", "YOU ARE BRAVE, BUT");
	sprintf(game_data.stages[DAISIEBOT].intro_dialog.line1[1], "%s", "MY FLOWERS' POWDER");
	sprintf(game_data.stages[DAISIEBOT].intro_dialog.line1[2], "%s", "WILL MAKE YOU SLEEP.");
	sprintf(game_data.stages[DAISIEBOT].intro_dialog.answer1[0][0], "%s", "THEN I SHALL");
	sprintf(game_data.stages[DAISIEBOT].intro_dialog.answer1[0][1], "%s", "AWAKE AND KILL");
	sprintf(game_data.stages[DAISIEBOT].intro_dialog.answer1[0][2], "%s", "THE PRINCESS.");
	sprintf(game_data.stages[DAISIEBOT].intro_dialog.answer1[1][0], "%s", "I DO NOT BREATHE.");
	sprintf(game_data.stages[DAISIEBOT].intro_dialog.answer1[1][1], "%s", "I DO NOT LIKE");
	sprintf(game_data.stages[DAISIEBOT].intro_dialog.answer1[1][2], "%s", "YOUR FLOWERS.");
	sprintf(game_data.stages[DAISIEBOT].intro_dialog.line2[0], "%s", "YOU UGLY BOY!");
	sprintf(game_data.stages[DAISIEBOT].intro_dialog.line2[1], "%s", "NATURE WILL PREVAIL");
	sprintf(game_data.stages[DAISIEBOT].intro_dialog.line2[2], "%s", "OVER TECHNOLOGY.");

	sprintf(game_data.stages[SEAHORSEBOT].intro_dialog.face_graphics_filename, "%s", "seahorsebot.png");
	sprintf(game_data.stages[SEAHORSEBOT].intro_dialog.line1[0], "%s", "CAN YOU PLEASE");
	sprintf(game_data.stages[SEAHORSEBOT].intro_dialog.line1[1], "%s", "JUST SINK TO THE");
	sprintf(game_data.stages[SEAHORSEBOT].intro_dialog.line1[2], "%s", "SEA BOTTOM?");
	sprintf(game_data.stages[SEAHORSEBOT].intro_dialog.answer1[0][0], "%s", "I CAN'T SWIM INDEED.");
	sprintf(game_data.stages[SEAHORSEBOT].intro_dialog.answer1[0][1], "%s", "BUT I'LL TRY ANYWAY.");
	sprintf(game_data.stages[SEAHORSEBOT].intro_dialog.answer1[1][0], "%s", "EVEN IF I DO,");
	sprintf(game_data.stages[SEAHORSEBOT].intro_dialog.answer1[1][1], "%s", "I COULD WALK UNTIL");
	sprintf(game_data.stages[SEAHORSEBOT].intro_dialog.answer1[1][2], "%s", "I REACH YOU.");

	sprintf(game_data.stages[MUMMYBOT].intro_dialog.face_graphics_filename, "%s", "mummybot.png");
	sprintf(game_data.stages[MUMMYBOT].intro_dialog.line1[0], "%s", "THE DESERT SUN");
	sprintf(game_data.stages[MUMMYBOT].intro_dialog.line1[1], "%s", "WILL MELT YOUR");
	sprintf(game_data.stages[MUMMYBOT].intro_dialog.line1[2], "%s", "CIRCUITS SOON.");
	sprintf(game_data.stages[MUMMYBOT].intro_dialog.answer1[0][0], "%s", "NO WAY!");
	sprintf(game_data.stages[MUMMYBOT].intro_dialog.answer1[0][1], "%s", "THERE ARE SOME");
	sprintf(game_data.stages[MUMMYBOT].intro_dialog.answer1[0][2], "%s", "OASIS I CAN USE.");
	sprintf(game_data.stages[MUMMYBOT].intro_dialog.answer1[1][0], "%s", "I AM MADE OF CERAMIC");
	sprintf(game_data.stages[MUMMYBOT].intro_dialog.answer1[1][1], "%s", "AND CAN'T MELT.");
	sprintf(game_data.stages[MUMMYBOT].intro_dialog.line2[0], "%s", "THEN, THE DANGERS");
	sprintf(game_data.stages[MUMMYBOT].intro_dialog.line2[1], "%s", "OF SAND WILL");
	sprintf(game_data.stages[MUMMYBOT].intro_dialog.line2[2], "%s", "FINISH YOU OUT.");

	sprintf(game_data.stages[MAGEBOT].intro_dialog.face_graphics_filename, "%s", "magebot.png");
	sprintf(game_data.stages[MAGEBOT].intro_dialog.line1[0], "%s", "CAN YOU FIND");
	sprintf(game_data.stages[MAGEBOT].intro_dialog.line1[1], "%s", "THE WHITE RABBIT?");
	sprintf(game_data.stages[MAGEBOT].intro_dialog.line1[2], "%s", "SURPRISE, SURPRISE!");
	sprintf(game_data.stages[MAGEBOT].intro_dialog.answer1[0][0], "%s", "YOU ARE MAKING");
	sprintf(game_data.stages[MAGEBOT].intro_dialog.answer1[0][1], "%s", "NO SENSE MAN!");
	sprintf(game_data.stages[MAGEBOT].intro_dialog.answer1[0][2], "%s", "CHILL OUT.");
	sprintf(game_data.stages[MAGEBOT].intro_dialog.answer1[1][0], "%s", "I WILL.");
	sprintf(game_data.stages[MAGEBOT].intro_dialog.answer1[1][1], "%s", "AND THEN WILL");
	sprintf(game_data.stages[MAGEBOT].intro_dialog.answer1[1][2], "%s", "FIND YOU TOO.");

	sprintf(game_data.stages[DYNAMITEBOT].intro_dialog.face_graphics_filename, "%s", "dynamitebot.png");
	sprintf(game_data.stages[DYNAMITEBOT].intro_dialog.line1[0], "%s", "COME! I'LL SHOW YOU");
	sprintf(game_data.stages[DYNAMITEBOT].intro_dialog.line1[1], "%s", "SOME NICE FIREWORKS.");
	sprintf(game_data.stages[DYNAMITEBOT].intro_dialog.answer1[0][0], "%s", "YOU WANT TO CELEBRATE");
	sprintf(game_data.stages[DYNAMITEBOT].intro_dialog.answer1[0][1], "%s", "MY VICTORY?");
	sprintf(game_data.stages[DYNAMITEBOT].intro_dialog.answer1[0][2], "%s", "HOW NICE.");
	sprintf(game_data.stages[DYNAMITEBOT].intro_dialog.answer1[1][0], "%s", "NOT IF I BLOW");
	sprintf(game_data.stages[DYNAMITEBOT].intro_dialog.answer1[1][1], "%s", "YOUR HEAD FIRST.");

	sprintf(game_data.stages[SPIKEBOT].intro_dialog.face_graphics_filename, "%s", "spikebot.png");
	sprintf(game_data.stages[SPIKEBOT].intro_dialog.line1[0], "%s", "TO REACH ME, YOU'LL");
	sprintf(game_data.stages[SPIKEBOT].intro_dialog.line1[1], "%s", "HAVE TO AVOID THE");
	sprintf(game_data.stages[SPIKEBOT].intro_dialog.line1[2], "%s", "DEADLY TRAPS.");
	sprintf(game_data.stages[SPIKEBOT].intro_dialog.answer1[0][0], "%s", "YOU CAN'T TRAP ME.");
	sprintf(game_data.stages[SPIKEBOT].intro_dialog.answer1[0][1], "%s", "I'LL FIND YOU AND");
	sprintf(game_data.stages[SPIKEBOT].intro_dialog.answer1[0][2], "%s", "YOU'LL BECOME MY TOY.");
	sprintf(game_data.stages[SPIKEBOT].intro_dialog.answer1[1][0], "%s", "I'M NO GINEA PIG,");
	sprintf(game_data.stages[SPIKEBOT].intro_dialog.answer1[1][1], "%s", "TO PLAY IN YOUR MAZE.");
	sprintf(game_data.stages[SPIKEBOT].intro_dialog.answer1[1][2], "%s", "I'LL SCAPE AND WIN.");

	sprintf(game_data.stages[TECHNOBOT].intro_dialog.face_graphics_filename, "%s", "technobot.png");
	sprintf(game_data.stages[TECHNOBOT].intro_dialog.line1[0], "%s", "101010101010101010");
	sprintf(game_data.stages[TECHNOBOT].intro_dialog.line1[1], "%s", "010010001001110010.");
	sprintf(game_data.stages[TECHNOBOT].intro_dialog.answer1[0][0], "%s", "YOU WHAT??");
	sprintf(game_data.stages[TECHNOBOT].intro_dialog.answer1[0][1], "%s", "SORRY PAL, BUT I DO");
	sprintf(game_data.stages[TECHNOBOT].intro_dialog.answer1[0][2], "%s", "NOT UNDERSTAND THAT.");
	sprintf(game_data.stages[TECHNOBOT].intro_dialog.answer1[1][0], "%s", "YES. I'VE COME TO");
	sprintf(game_data.stages[TECHNOBOT].intro_dialog.answer1[1][1], "%s", "FIGHT YOU, 0101.");

	sprintf(game_data.stages[SKULLCASTLE1].intro_dialog.face_graphics_filename, "%s", "dr_destrin.png");
	sprintf(game_data.stages[SKULLCASTLE1].intro_dialog.line1[0], "%s", "SO, KANOTUS THINK");
	sprintf(game_data.stages[SKULLCASTLE1].intro_dialog.line1[1], "%s", "YOU CAN DEFEAT ME? ME?");
	sprintf(game_data.stages[SKULLCASTLE1].intro_dialog.line1[2], "%s", "BWAHAHAHAHA!!!");
	sprintf(game_data.stages[SKULLCASTLE1].intro_dialog.answer1[0][0], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE1].intro_dialog.answer1[0][1], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE1].intro_dialog.answer1[0][2], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE1].intro_dialog.answer1[1][0], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE1].intro_dialog.answer1[1][1], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE1].intro_dialog.answer1[1][2], "%s", "EMPTY");

	sprintf(game_data.stages[SKULLCASTLE2].intro_dialog.face_graphics_filename, "%s", "dr_destrin.png");
	sprintf(game_data.stages[SKULLCASTLE2].intro_dialog.line1[0], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE2].intro_dialog.line1[1], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE2].intro_dialog.line1[2], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE2].intro_dialog.answer1[0][0], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE2].intro_dialog.answer1[0][1], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE2].intro_dialog.answer1[0][2], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE2].intro_dialog.answer1[1][0], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE2].intro_dialog.answer1[1][1], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE2].intro_dialog.answer1[1][2], "%s", "EMPTY");

	sprintf(game_data.stages[SKULLCASTLE3].intro_dialog.face_graphics_filename, "%s", "dr_destrin.png");
	sprintf(game_data.stages[SKULLCASTLE3].intro_dialog.line1[0], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE3].intro_dialog.line1[1], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE3].intro_dialog.line1[2], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE3].intro_dialog.answer1[0][0], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE3].intro_dialog.answer1[0][1], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE3].intro_dialog.answer1[0][2], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE3].intro_dialog.answer1[1][0], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE3].intro_dialog.answer1[1][1], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE3].intro_dialog.answer1[1][2], "%s", "EMPTY");

	sprintf(game_data.stages[SKULLCASTLE4].intro_dialog.face_graphics_filename, "%s", "dr_destrin.png");
	sprintf(game_data.stages[SKULLCASTLE4].intro_dialog.line1[0], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE4].intro_dialog.line1[1], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE4].intro_dialog.line1[2], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE4].intro_dialog.answer1[0][0], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE4].intro_dialog.answer1[0][1], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE4].intro_dialog.answer1[0][2], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE4].intro_dialog.answer1[1][0], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE4].intro_dialog.answer1[1][1], "%s", "EMPTY");
	sprintf(game_data.stages[SKULLCASTLE4].intro_dialog.answer1[1][2], "%s", "EMPTY");

}

void fill_stages()
{
    format_v2_0::file_game game_data;
	//INTRO_STAGE, APEBOT, DAISIEBOT, SEAHORSEBOT, MUMMYBOT, SKULLCASTLE1, MAGEBOT, DYNAMITEBOT, SPIKEBOT, TECHNOBOT, SKULLCASTLE2, SKULLCASTLE3, SKULLCASTLE4, STAGE_COUNT
	sprintf(game_data.stages[INTRO_STAGE].name, "Chaos City");
	sprintf(game_data.stages[APEBOT].name, "Deep Jungle");
	sprintf(game_data.stages[DAISIEBOT].name, "Flower Fields");
	sprintf(game_data.stages[SEAHORSEBOT].name, "Atlantida");
	sprintf(game_data.stages[MUMMYBOT].name, "Sun-God Realm");
	sprintf(game_data.stages[MAGEBOT].name, "Tricky Castle");
	sprintf(game_data.stages[DYNAMITEBOT].name, "Dark Mine");
	sprintf(game_data.stages[SPIKEBOT].name, "Steel Maze");
	sprintf(game_data.stages[TECHNOBOT].name, "Infoway");
	sprintf(game_data.stages[SKULLCASTLE1].name, "Skull Castle #1");
	sprintf(game_data.stages[SKULLCASTLE2].name, "Skull Castle #2");
	sprintf(game_data.stages[SKULLCASTLE3].name, "Skull Castle #3");
	sprintf(game_data.stages[SKULLCASTLE4].name, "Skull Castle #4");
}


void fill_projectiles()
{
   format_v2_0::file_game game_data;
	// NORMAL
	game_data.projectiles[0].id = 0;
	sprintf(game_data.projectiles[0].graphic_filename, "projectile_normal.png");
	sprintf(game_data.projectiles[0].name, "Normal");
	game_data.projectiles[0].size.width = 6;
	game_data.projectiles[0].size.heigth = 6;

	// DESERT SCORPION
	game_data.projectiles[1].id = 4;
	sprintf(game_data.projectiles[1].graphic_filename, "desert_scorpion.png");
	sprintf(game_data.projectiles[1].name, "Scorpion");
	game_data.projectiles[1].size.width = 12;
	game_data.projectiles[1].size.heigth = 12;
	game_data.projectiles[1].projectile_type = TRAJECTORY_FOLLOW;

	// DYNAMITE
	game_data.projectiles[2].id = 2;
	sprintf(game_data.projectiles[2].graphic_filename, "dynamite.png");
	sprintf(game_data.projectiles[2].name, "Dynamite");
	game_data.projectiles[2].size.width = 20;
	game_data.projectiles[2].size.heigth = 20;
	game_data.projectiles[2].projectile_type = TRAJECTORY_FREEZE;

	// FLOWER
	game_data.projectiles[1].id = 3;
	sprintf(game_data.projectiles[3].graphic_filename, "flower.png");
	sprintf(game_data.projectiles[3].name, "Flower");
	game_data.projectiles[3].size.width = 11;
	game_data.projectiles[3].size.heigth = 14;
	game_data.projectiles[3].projectile_type = TRAJECTORY_PROGRESSIVE;

	// STAR
	game_data.projectiles[4].id = 4;
	sprintf(game_data.projectiles[4].graphic_filename, "magic_star.png");
	sprintf(game_data.projectiles[4].name, "Star");
	game_data.projectiles[4].size.width = 7;
	game_data.projectiles[4].size.heigth = 7;
	game_data.projectiles[4].projectile_type = TRAJECTORY_SIN;

	// FISH
	game_data.projectiles[5].id = 5;
	sprintf(game_data.projectiles[5].graphic_filename, "palometa_fish.png");
	sprintf(game_data.projectiles[5].name, "Fish");
	game_data.projectiles[5].size.width = 12;
	game_data.projectiles[5].size.heigth = 12;
	game_data.projectiles[5].projectile_type = TRAJECTORY_LINEAR;

	// RAINBOW
	game_data.projectiles[6].id = 6;
	sprintf(game_data.projectiles[6].graphic_filename, "rainbow.png");
	sprintf(game_data.projectiles[6].name, "Normal");
	game_data.projectiles[6].size.width = 16;
	game_data.projectiles[6].size.heigth = 16;
	game_data.projectiles[6].projectile_type = TRAJECTORY_ARC;

	// CHAIN
	game_data.projectiles[7].id = 7;
	sprintf(game_data.projectiles[7].graphic_filename, "spiked_chain.png");
	sprintf(game_data.projectiles[7].name, "Chain");
	game_data.projectiles[7].size.width = 50;
	game_data.projectiles[7].size.heigth = 7;
	game_data.projectiles[7].projectile_type = TRAJECTORY_CHAIN;

	// BOMB
	game_data.projectiles[8].id = 8;
	sprintf(game_data.projectiles[8].graphic_filename, "timer_bomb.png");
	sprintf(game_data.projectiles[8].name, "Bomb");
	game_data.projectiles[8].size.width = 16;
	game_data.projectiles[8].size.heigth = 16;
	game_data.projectiles[8].projectile_type = TRAJECTORY_BOMB;

	// EARTHQUAKE
	game_data.projectiles[9].id = 9;
	sprintf(game_data.projectiles[9].graphic_filename, "projectile_normal.png"); /// @TODO: must not load graphic if there is no need for it
	sprintf(game_data.projectiles[9].name, "Quake");
	game_data.projectiles[9].projectile_type = TRAJECTORY_QUAKE;

    // NORMAL CHARGED
    game_data.projectiles[10].id = 10;
    sprintf(game_data.projectiles[10].graphic_filename, "charged_shot.png");
    sprintf(game_data.projectiles[10].name, "Charged");
    game_data.projectiles[10].size.width = 31;
    game_data.projectiles[10].size.heigth = 30;

    // NORMAL SEMI-CHARGED
    game_data.projectiles[11].id = 11;
    sprintf(game_data.projectiles[11].graphic_filename, "charged_semi.png");
    sprintf(game_data.projectiles[11].name, "Semi-Charged");
    game_data.projectiles[11].size.width = 16;
    game_data.projectiles[11].size.heigth = 16;
}

void fill_weapons()
{
	fill_projectiles();
    format_v2_0::file_game game_data;

	game_data.weapons[0].id = 0;
	game_data.weapons[0].id_projectile = 0;
	game_data.weapons[0].damage = 1;
	sprintf(game_data.weapons[0].name, "Normal Weapon");

	game_data.weapons[1].id = 1;
	game_data.weapons[1].id_projectile = 9;
	game_data.weapons[1].damage = 1;
	sprintf(game_data.weapons[1].name, "Ape Quake");

	game_data.weapons[2].id = 2;
	game_data.weapons[2].id_projectile = 6;
	game_data.weapons[2].damage = 1;
	sprintf(game_data.weapons[2].name, "Petals Rainbow");

	game_data.weapons[3].id = 3;
	game_data.weapons[3].id_projectile = 2;
	game_data.weapons[3].damage = 1;
	sprintf(game_data.weapons[3].name, "Dynamite Flash");

	game_data.weapons[4].id = 4;
	game_data.weapons[4].id_projectile = 1;
	game_data.weapons[4].damage = 1;
	sprintf(game_data.weapons[1].name, "Desert Scorpion");

	game_data.weapons[5].id = 5;
	game_data.weapons[5].id_projectile = 7;
	game_data.weapons[5].damage = 1;
	sprintf(game_data.weapons[5].name, "Spiked Chain");

	game_data.weapons[6].id = 6;
	game_data.weapons[6].id_projectile = 8;
	game_data.weapons[6].damage = 1;
	sprintf(game_data.weapons[6].name, "Timed Bomb");

	game_data.weapons[7].id = 7;
	game_data.weapons[7].id_projectile = 4;
	game_data.weapons[7].damage = 1;
	sprintf(game_data.weapons[7].name, "Magic Star");

	game_data.weapons[8].id = 8;
	game_data.weapons[8].id_projectile = 5;
	game_data.weapons[8].damage = 1;
	sprintf(game_data.weapons[8].name, "Palometa Fish");
}

void set_hardcoded_parts() {
    format_v2_0::file_game game_data;
	/// *** hardcoded parts *** ///
	// game
	game_data.version = 1;
	sprintf(game_data.name, "%s", "Rockbot");

	// players
	fill_players();

	// stages
	fill_stages();

	// bosses
	fill_bosses();

	// stage.bgmusic_filename

	// intro_dialog[5]
	// boss_dialog[5]
	fill_dialogs();

	// colorcycle

	//game_data.projectiles

	//game_data.weapons
	fill_weapons();
}

void convert_10_to_200()
{
    format_v2_0::file_game game_data;
	file_io fio;
	std::cout << "Converting data..." << std::endl;

	// HARDCODED PARTS FOR THE NEW SAVE FORMAT
	sprintf(game_data.name, "%s", "Rockbot");

	// CONVERT OLD DATA TO NEW FORMAT
	convert_game_npcs();
	convert_game_objects();
	convert_links();
	convert_stages();
	set_hardcoded_parts();

	std::cout << "done!" << std::endl;

	// SAVE DATA INTO NEW FORMAT FILE
	fio.write_game(game_data);
	std::cout << "Data written to file." << std::endl;
}

void convert_200_to_201()
{
    format_v_2_0_1::file_game new_game_data;
    format_v2_0::file_game game_data;
	format_v_2_0_1::file_io fio_new;
	file_io fio_old;
	std::cout << "Converting data..." << std::endl;
	fio_old.read_game(game_data);

	// conversion
	new_game_data.version = 0.91;

/*
format_v2_0::file_npc game_npcs[GAME_MAX_OBJS]; // 60 enemy types is more than good enought
format_v2_0::file_object objects[GAME_MAX_OBJS];
format_v2_0::file_projectile projectiles[MAX_FILE_PROJECTILES];
format_v2_0::file_weapon weapons[MAX_WEAPON_N]; // 8 stage-bosses and 3 item-like
format_v2_0::file_player players[MAX_FILE_PLAYERS]; // up to 5 different players the user can select from
file_stage stages[MAX_STAGES];
format_v2_0::file_artificial_inteligence ai_types[MAX_AI_TYPES];
*/

	for (int i=0; i<GAME_MAX_OBJS; i++) {
		new_game_data.game_npcs[i] = game_data.game_npcs[i];
		new_game_data.objects[i] = game_data.objects[i];
	}
	for (int i=0; i<MAX_FILE_PROJECTILES; i++) {
		new_game_data.projectiles[i] = game_data.projectiles[i];
	}
	for (int i=0; i<MAX_WEAPON_N; i++) {
		new_game_data.weapons[i] = game_data.weapons[i];
	}
	for (int i=0; i<MAX_FILE_PLAYERS; i++) {
		new_game_data.players[i] = game_data.players[i];
	}
	for (int i=0; i<MAX_AI_TYPES; i++) {
		new_game_data.ai_types[i] = game_data.ai_types[i];
	}


/*
short id;
char name[CHAR_NAME_SIZE];
char bgmusic_filename[CHAR_FILENAME_SIZE];
file_map maps[STAGE_MAX_MAPS];
format_v2_0::file_link links[STAGE_MAX_LINKS];
format_v2_0::file_boss boss;
format_v2_0::file_dialog intro_dialog;
format_v2_0::file_dialog boss_dialog;
format_v2_0::file_colorcycle colorcycle;
*/
	// enter into data that will be converted...
	for (int i=0; i<MAX_STAGES; i++) {
		new_game_data.stages[i].id = game_data.stages[i].id;
		sprintf(new_game_data.stages[i].name, "%s", game_data.stages[i].name);
		sprintf(new_game_data.stages[i].bgmusic_filename, "%s", game_data.stages[i].bgmusic_filename);
		for (int j=0; j<STAGE_MAX_LINKS; j++) {
			new_game_data.stages[i].links[j] = game_data.stages[i].links[j];
		}
		new_game_data.stages[i].boss = game_data.stages[i].boss;
		new_game_data.stages[i].intro_dialog = game_data.stages[i].intro_dialog;
		new_game_data.stages[i].boss_dialog = game_data.stages[i].boss_dialog;
		new_game_data.stages[i].colorcycle = game_data.stages[i].colorcycle;
		// real conversion happens here...
		for (int j=0; j<STAGE_MAX_MAPS; j++) { /// @TODO - this must be done as a copy operator...
/*
short id;
st_map_background backgrounds[2];
st_color background_color;
format_v2_0::map_tile tiles[MAP_W][MAP_H];		// map tiles
format_v2_0::file_map_npc map_npcs[MAX_MAP_NPC_N];
format_v2_0::file_map_object map_objects[MAX_MAP_NPC_N];
*/
			new_game_data.stages[i].maps[j].id = game_data.stages[i].maps[j].id;
			for (int k=0; k<MAP_W; k++) {
				for (int l=0; l<MAP_H; l++) {
					new_game_data.stages[i].maps[j].tiles[k][l] = game_data.stages[i].maps[j].tiles[k][l];
				}
			}
			for (int k=0; k<MAX_MAP_NPC_N; k++) {
				new_game_data.stages[i].maps[j].map_npcs[k] = game_data.stages[i].maps[j].map_npcs[k];
				new_game_data.stages[i].maps[j].map_objects[k] = game_data.stages[i].maps[j].map_objects[k];
			}
		}
	}


	fio_new.write_game(new_game_data);
	std::cout << "Data written to file." << std::endl;
}


void convert_201_to_202()
{
    format_v_2_0_1::file_game new_game_data;
	format_v_2_0_2::file_io fio_new;
	format_v_2_0_1::file_io fio_old;
	std::cout << "Converting data from 2.0.1 to 2.0.2 ..." << std::endl;
	fio_old.read_game(new_game_data);

	// conversion
	game_data_v202.version = 0.92;

	for (int i=0; i<GAME_MAX_OBJS; i++) {
		/// @BEGIN - real conversion on this part
        //game_data_v202.game_npcs[i] = game_data.game_npcs[i];
        for (int i=0; i<GAME_MAX_OBJS; i++) {
            //game_data_v202.game_npcs[i]. = new_game_data.game_npcs[i].;
            //sprintf(game_data_v202.game_npcs[i]., "%s", new_game_data.game_npcs[i].);
            game_data_v202.game_npcs[i].can_shoot = new_game_data.game_npcs[i].can_shoot;
			game_data_v202.game_npcs[i].death_spawn = new_game_data.game_npcs[i].death_spawn;
			game_data_v202.game_npcs[i].direction = new_game_data.game_npcs[i].direction;
			game_data_v202.game_npcs[i].facing = new_game_data.game_npcs[i].facing;
			for (int j=0; j<NPC_FRAME_NUMBER; j++) {
				game_data_v202.game_npcs[i].frames[j].duration = new_game_data.game_npcs[i].frames[j].duration;
				game_data_v202.game_npcs[i].frames[j].id = new_game_data.game_npcs[i].frames[j].id;
				game_data_v202.game_npcs[i].frames[j].sprite_pos_x = new_game_data.game_npcs[i].frames[j].sprite_pos_x;
				game_data_v202.game_npcs[i].frames[j].state = new_game_data.game_npcs[i].frames[j].state;
			}
			game_data_v202.game_npcs[i].frame_size = new_game_data.game_npcs[i].frame_size;
			sprintf(game_data_v202.game_npcs[i].graphic_filename, "%s", new_game_data.game_npcs[i].graphic_filename);
			game_data_v202.game_npcs[i].hp = new_game_data.game_npcs[i].hp;
			game_data_v202.game_npcs[i].IA_type = new_game_data.game_npcs[i].IA_type;
			game_data_v202.game_npcs[i].id = new_game_data.game_npcs[i].id;
			sprintf(game_data_v202.game_npcs[i].name, "%s", new_game_data.game_npcs[i].name);
			for (int j=0; j<2; j++) {
				game_data_v202.game_npcs[i].projectile_id[j] = new_game_data.game_npcs[i].projectile_id[j];
			}
			game_data_v202.game_npcs[i].shield_type = new_game_data.game_npcs[i].shield_type;
			game_data_v202.game_npcs[i].speed = new_game_data.game_npcs[i].speed;
			game_data_v202.game_npcs[i].start_point = new_game_data.game_npcs[i].start_point;
			game_data_v202.game_npcs[i].walk_range = new_game_data.game_npcs[i].walk_range;
		}
		/// @END - real conversion on this part
		game_data_v202.objects[i] = new_game_data.objects[i];
	}
	for (int i=0; i<MAX_FILE_PROJECTILES; i++) {
		game_data_v202.projectiles[i] = new_game_data.projectiles[i];
	}
	for (int i=0; i<MAX_WEAPON_N; i++) {
		game_data_v202.weapons[i] = new_game_data.weapons[i];
	}
	for (int i=0; i<MAX_FILE_PLAYERS; i++) {
		game_data_v202.players[i] = new_game_data.players[i];
	}
	for (int i=0; i<MAX_AI_TYPES; i++) {
		game_data_v202.ai_types[i] = new_game_data.ai_types[i];
	}
	for (int i=0; i<MAX_STAGES; i++) {
		game_data_v202.stages[i] = new_game_data.stages[i];
	}

	fio_new.write_game(game_data_v202);
	std::cout << "Data written to file." << std::endl;
}





// ------------------------------------------ 203 ----------------------------------------------- //
void convert_202_to_203()
{
	format_v_2_0_3::file_io fio_new;
	format_v_2_0_2::file_io fio_old;
	std::cout << "Converting data from 2.0.2 to 2.0.3 ..." << std::endl;
	fio_old.read_game(game_data_v202);

	// conversion
	game_data_v203.version = 0.93;

	for (int i=0; i<GAME_MAX_OBJS; i++) {
		/// @BEGIN - real conversion on this part
		game_data_v203.game_npcs[i].can_shoot = game_data_v202.game_npcs[i].can_shoot;
		game_data_v203.game_npcs[i].death_spawn = game_data_v202.game_npcs[i].death_spawn;
		game_data_v203.game_npcs[i].direction = game_data_v202.game_npcs[i].direction;
		game_data_v203.game_npcs[i].facing = game_data_v202.game_npcs[i].facing;
		for (int j=0; j<NPC_FRAME_NUMBER; j++) {
			game_data_v203.game_npcs[i].frames[j].duration = game_data_v202.game_npcs[i].frames[j].duration;
			game_data_v203.game_npcs[i].frames[j].id = game_data_v202.game_npcs[i].frames[j].id;
			game_data_v203.game_npcs[i].frames[j].sprite_pos_x = game_data_v202.game_npcs[i].frames[j].sprite_pos_x;
			game_data_v203.game_npcs[i].frames[j].state = game_data_v202.game_npcs[i].frames[j].state;
			game_data_v203.game_npcs[i].frames[j].colision_rect.x = 0;
			game_data_v203.game_npcs[i].frames[j].colision_rect.y = 0;
			game_data_v203.game_npcs[i].frames[j].colision_rect.w = game_data_v202.game_npcs[i].frame_size.width;
			game_data_v203.game_npcs[i].frames[j].colision_rect.h = game_data_v202.game_npcs[i].frame_size.heigth;
		}
		game_data_v203.game_npcs[i].frame_size = game_data_v202.game_npcs[i].frame_size;
		sprintf(game_data_v203.game_npcs[i].graphic_filename, "%s", game_data_v202.game_npcs[i].graphic_filename);
		game_data_v203.game_npcs[i].hp = game_data_v202.game_npcs[i].hp;
		game_data_v203.game_npcs[i].IA_type = game_data_v202.game_npcs[i].IA_type;
		game_data_v203.game_npcs[i].id = game_data_v202.game_npcs[i].id;
		sprintf(game_data_v203.game_npcs[i].name, "%s", game_data_v202.game_npcs[i].name);
		for (int j=0; j<2; j++) {
			game_data_v203.game_npcs[i].projectile_id[j] = game_data_v202.game_npcs[i].projectile_id[j];
		}
		game_data_v203.game_npcs[i].shield_type = game_data_v202.game_npcs[i].shield_type;
		game_data_v203.game_npcs[i].speed = game_data_v202.game_npcs[i].speed;
		game_data_v203.game_npcs[i].start_point.x = game_data_v202.game_npcs[i].start_point.x;
		if (i == 0 && game_data_v202.game_npcs[i].start_point.y != 0) { std::cout << "name: " << game_data_v203.game_npcs[i].name << ", game_data_v202.game_npcs[i].start_point.y: " << game_data_v202.game_npcs[i].start_point.y << std::endl; }
		game_data_v203.game_npcs[i].start_point = game_data_v202.game_npcs[i].start_point;
		/// @END - real conversion on this part
		game_data_v203.objects[i] = game_data_v202.objects[i];
	}
	for (int i=0; i<MAX_FILE_PROJECTILES; i++) {
		game_data_v203.projectiles[i] = game_data_v202.projectiles[i];
	}
	for (int i=0; i<MAX_WEAPON_N; i++) {
		game_data_v203.weapons[i] = game_data_v202.weapons[i];
	}

	for (int i=0; i<MAX_FILE_PLAYERS; i++) {
		//game_data_v203.players[i] = game_data_v202.players[i];
		game_data_v203.players[i].can_charge_shot = game_data_v202.players[i].can_charge_shot;
		game_data_v203.players[i].can_slide = game_data_v202.players[i].can_slide;
		for (int j=0; j<3; j++) {
			game_data_v203.players[i].color_keys[j].r = game_data_v202.players[i].color_keys[j].r;
			game_data_v203.players[i].color_keys[j].g = game_data_v202.players[i].color_keys[j].g;
			game_data_v203.players[i].color_keys[j].b = game_data_v202.players[i].color_keys[j].b;
		}
		game_data_v203.players[i].double_jump = game_data_v202.players[i].double_jump;
		sprintf(game_data_v203.players[i].face_filename, "%s", game_data_v202.players[i].face_filename);
		game_data_v203.players[i].fall_gravity = game_data_v202.players[i].fall_gravity;
		sprintf(game_data_v203.players[i].graphic_filename, "%s", game_data_v202.players[i].graphic_filename);
		game_data_v203.players[i].have_shield = game_data_v202.players[i].have_shield;
		game_data_v203.players[i].HP = game_data_v202.players[i].HP;
		game_data_v203.players[i].id = game_data_v202.players[i].id;
		game_data_v203.players[i].jump_gravity = game_data_v202.players[i].jump_gravity;
		game_data_v203.players[i].jump_initial_speed = game_data_v202.players[i].jump_initial_speed;
		game_data_v203.players[i].max_shots = game_data_v202.players[i].max_shots;
		game_data_v203.players[i].move_speed = game_data_v202.players[i].move_speed;
		sprintf(game_data_v203.players[i].name, "%s", game_data_v202.players[i].name);
		game_data_v203.players[i].simultaneous_shots = game_data_v202.players[i].simultaneous_shots;
		for (int j=0; j<MAX_PLAYER_SPRITES; j++) {
			game_data_v203.players[i].sprites[j].duration = game_data_v202.players[i].sprites[j].duration;
			game_data_v203.players[i].sprites[j].id = game_data_v202.players[i].sprites[j].id;
			game_data_v203.players[i].sprites[j].sprite_pos_x = game_data_v202.players[i].sprites[j].sprite_pos_x;
			game_data_v203.players[i].sprites[j].state = game_data_v202.players[i].sprites[j].state;
			game_data_v203.players[i].sprites[j].colision_rect.x = 0;
			game_data_v203.players[i].sprites[j].colision_rect.y = 0;
			game_data_v203.players[i].sprites[j].colision_rect.w = game_data_v202.players[i].sprite_size.width;
			game_data_v203.players[i].sprites[j].colision_rect.h = game_data_v202.players[i].sprite_size.heigth;
		}



		game_data_v203.players[i].sprite_hit_area = game_data_v202.players[i].sprite_hit_area;
		game_data_v203.players[i].sprite_size = game_data_v202.players[i].sprite_size;
		for (int j=0; j<MAX_WEAPON_N; j++) {
			game_data_v203.players[i].weapon_colors[j] = game_data_v202.players[i].weapon_colors[j];
		}

	}


	for (int i=0; i<MAX_AI_TYPES; i++) {
		game_data_v203.ai_types[i] = game_data_v202.ai_types[i];
	}


	for (int i=0; i<MAX_STAGES; i++) {
		game_data_v203.stages[i] = game_data_v202.stages[i];
	}

	fio_new.write_game(game_data_v203);
	std::cout << "Data written to file." << std::endl;
}


// ------------------------------------------ 204 ----------------------------------------------- //
void convert_203_to_204()
{
    format_v_2_0_4::file_io fio_new;
    format_v_2_0_3::file_io fio_old;
    std::cout << "Converting data from 2.0.3 to 2.0.4 ..." << std::endl;
    fio_old.read_game(game_data_v203);

    // conversion
    game_data_v204.version = 0.93;

    for (int i=0; i<GAME_MAX_OBJS; i++) {
        if (game_data_v203.game_npcs[i].id != -1) {
            /// @BEGIN - real conversion on this part
            game_data_v204.game_npcs[i].can_shoot = game_data_v203.game_npcs[i].can_shoot;
            game_data_v204.game_npcs[i].death_spawn = game_data_v203.game_npcs[i].death_spawn;
            game_data_v204.game_npcs[i].direction = game_data_v203.game_npcs[i].direction;
            game_data_v204.game_npcs[i].facing = game_data_v203.game_npcs[i].facing;

            // frames conversion
            for (int j=0; j<NPC_FRAME_NUMBER; j++) {
                int anim_type = game_data_v203.game_npcs[i].frames[j].state;
                if (anim_type != -1 && anim_type < ANIM_TYPE_COUNT) {
                    // find first empty slot
                    bool found_slot = false;
                    for (int k=0; k<ANIM_FRAMES_COUNT; k++) {
                        if (game_data_v204.game_npcs[i].sprites[anim_type][k].used == false) {
                            std::cout << "INFO: NPC[" << game_data_v203.game_npcs[i].name << "][" << game_data_v203.game_npcs[i].id << "] - sprite[" << anim_type << "][" << k << "] added with sprite_pos_x: " << game_data_v203.game_npcs[i].frames[j].sprite_pos_x << "." << std::endl;
                            //std::cout << "name : " << game_data_v203.game_npcs[i].name << ", j: " << j << ", pos_x: " << game_data_v203.game_npcs[i].frames[j].sprite_pos_x << ", id: " << game_data_v203.game_npcs[i].frames[j].id << ", state: " << game_data_v203.game_npcs[i].frames[j].state << std::endl;
                            found_slot = true;
                            game_data_v204.game_npcs[i].sprites[anim_type][k].used = true;
                            game_data_v204.game_npcs[i].sprites[anim_type][k].colision_rect = game_data_v203.game_npcs[i].frames[j].colision_rect;
                            game_data_v204.game_npcs[i].sprites[anim_type][k].duration = game_data_v203.game_npcs[i].frames[j].duration;
                            game_data_v204.game_npcs[i].sprites[anim_type][k].sprite_graphic_pos_x = game_data_v203.game_npcs[i].frames[j].sprite_pos_x;
                            break;
                        }
                    }
                    if (found_slot == false) {
                        std::cout << "ERROR: NPC[" << game_data_v203.game_npcs[i].name << "] - sprite[" << anim_type << "] - Could not find an empty slot to add NPC graphic frame!" << std::endl;
                    }
                }
            }

            game_data_v204.game_npcs[i].frame_size = game_data_v203.game_npcs[i].frame_size;
            sprintf(game_data_v204.game_npcs[i].graphic_filename, "%s", game_data_v203.game_npcs[i].graphic_filename);
            game_data_v204.game_npcs[i].hp = game_data_v203.game_npcs[i].hp;
            game_data_v204.game_npcs[i].IA_type = game_data_v203.game_npcs[i].IA_type;
            game_data_v204.game_npcs[i].id = game_data_v203.game_npcs[i].id;
            sprintf(game_data_v204.game_npcs[i].name, "%s", game_data_v203.game_npcs[i].name);
            for (int j=0; j<2; j++) {
                game_data_v204.game_npcs[i].projectile_id[j] = game_data_v203.game_npcs[i].projectile_id[j];
            }
            game_data_v204.game_npcs[i].shield_type = game_data_v203.game_npcs[i].shield_type;
            game_data_v204.game_npcs[i].speed = game_data_v203.game_npcs[i].speed;
            game_data_v204.game_npcs[i].start_point.x = game_data_v203.game_npcs[i].start_point.x;
            if (i == 0 && game_data_v203.game_npcs[i].start_point.y != 0) { std::cout << "name: " << game_data_v204.game_npcs[i].name << ", game_data_v203.game_npcs[i].start_point.y: " << game_data_v203.game_npcs[i].start_point.y << std::endl; }
            game_data_v204.game_npcs[i].start_point = game_data_v203.game_npcs[i].start_point;
            /// @END - real conversion on this part
        }
        game_data_v204.objects[i] = game_data_v203.objects[i];
    }
    for (int i=0; i<MAX_FILE_PROJECTILES; i++) {
        game_data_v204.projectiles[i] = game_data_v203.projectiles[i];
    }
    for (int i=0; i<MAX_WEAPON_N; i++) {
        game_data_v204.weapons[i] = game_data_v203.weapons[i];
    }

    for (int i=0; i<MAX_FILE_PLAYERS; i++) {
        //game_data_v204.players[i] = game_data_v203.players[i];
        game_data_v204.players[i].can_charge_shot = game_data_v203.players[i].can_charge_shot;
        game_data_v204.players[i].can_slide = game_data_v203.players[i].can_slide;
        for (int j=0; j<3; j++) {
            game_data_v204.players[i].color_keys[j].r = game_data_v203.players[i].color_keys[j].r;
            game_data_v204.players[i].color_keys[j].g = game_data_v203.players[i].color_keys[j].g;
            game_data_v204.players[i].color_keys[j].b = game_data_v203.players[i].color_keys[j].b;
        }
        game_data_v204.players[i].double_jump = game_data_v203.players[i].double_jump;
        sprintf(game_data_v204.players[i].face_filename, "%s", game_data_v203.players[i].face_filename);
        game_data_v204.players[i].fall_gravity = game_data_v203.players[i].fall_gravity;
        sprintf(game_data_v204.players[i].graphic_filename, "%s", game_data_v203.players[i].graphic_filename);
        game_data_v204.players[i].have_shield = game_data_v203.players[i].have_shield;
        game_data_v204.players[i].HP = game_data_v203.players[i].HP;
        game_data_v204.players[i].id = game_data_v203.players[i].id;
        game_data_v204.players[i].jump_gravity = game_data_v203.players[i].jump_gravity;
        game_data_v204.players[i].jump_initial_speed = game_data_v203.players[i].jump_initial_speed;
        game_data_v204.players[i].max_shots = game_data_v203.players[i].max_shots;
        game_data_v204.players[i].move_speed = game_data_v203.players[i].move_speed;
        sprintf(game_data_v204.players[i].name, "%s", game_data_v203.players[i].name);
        game_data_v204.players[i].simultaneous_shots = game_data_v203.players[i].simultaneous_shots;


        // frames conversion
        for (int j=0; j<NPC_FRAME_NUMBER; j++) {
            int anim_type = game_data_v203.players[i].sprites[j].state;
            if (anim_type != -1 && anim_type < ANIM_TYPE_COUNT) {
                // find first empty slot
                bool found_slot = false;
                for (int k=0; k<ANIM_FRAMES_COUNT; k++) {
                    if (game_data_v204.players[i].sprites[anim_type][k].used == false) {
                        //std::cout << "INFO: PLAYER[" << game_data_v203.players[i].name << "] - sprite[" << anim_type << "][" << k << "] added." << std::endl;
                        found_slot = true;
                        game_data_v204.players[i].sprites[anim_type][k].used = true;
                        game_data_v204.players[i].sprites[anim_type][k].colision_rect = game_data_v203.players[i].sprites[j].colision_rect;
                        game_data_v204.players[i].sprites[anim_type][k].duration = game_data_v203.players[i].sprites[j].duration;
                        game_data_v204.players[i].sprites[anim_type][k].sprite_graphic_pos_x = game_data_v203.players[i].sprites[j].sprite_pos_x;
                        break;
                    }
                }
                if (found_slot == false) {
                    std::cout << "ERROR: PLAYER[" << game_data_v203.players[i].name << "] - sprite[" << anim_type << "]pos_x[" << game_data_v203.players[i].sprites[j].sprite_pos_x << "] - Could not find an empty slot to add PLAYER graphic frame!" << std::endl;
                }
            }
        }

        game_data_v204.players[i].sprite_hit_area = game_data_v203.players[i].sprite_hit_area;
        game_data_v204.players[i].sprite_size = game_data_v203.players[i].sprite_size;
        for (int j=0; j<MAX_WEAPON_N; j++) {
            game_data_v204.players[i].weapon_colors[j] = game_data_v203.players[i].weapon_colors[j];
        }

    }


    for (int i=0; i<MAX_AI_TYPES; i++) {
        game_data_v204.ai_types[i] = game_data_v203.ai_types[i];
    }


    for (int i=0; i<MAX_STAGES; i++) {
        game_data_v204.stages[i] = game_data_v203.stages[i];
    }

    std::cout << "p[0] name: " << game_data_v204.players[0].name << std::endl;
    fio_new.write_game(game_data_v204);
    std::cout << "Data written to file." << std::endl;
}



// ------------------------------------------ 2.1 ----------------------------------------------- //
// MUST CONVERT: game_npcs, objects, projectiles, ai_types
void convert_204_to_21()
{
    //format_v_2_0_4::file_game game_data_v204;
    //format_v_2_1::file_game game_data_v21;

    format_v_2_1::file_io fio_new;
    format_v_2_0_4::file_io fio_old;
    std::cout << "Converting data from 2.0.4 to 2.1 ..." << std::endl;
    fio_old.read_game(game_data_v204);

    // conversion
    game_data_v21.version = 1.0;

    // NPCS CONVERSION
    for (int i=0; i<GAME_MAX_OBJS; i++) {
        if (game_data_v204.game_npcs[i].id != -1) {
            /// @BEGIN - real conversion on this part
            game_data_v21.game_npcs[i].can_shoot = game_data_v204.game_npcs[i].can_shoot;
            game_data_v21.game_npcs[i].death_spawn = game_data_v204.game_npcs[i].death_spawn;
            game_data_v21.game_npcs[i].direction = game_data_v204.game_npcs[i].direction;
            game_data_v21.game_npcs[i].facing = game_data_v204.game_npcs[i].facing;

            // frames conversion

            for (int j=0; j<ANIM_TYPE_COUNT; j++) {
                for (int k=0; k<ANIM_FRAMES_COUNT; k++) {
                    game_data_v21.game_npcs[i].sprites[j][k].colision_rect = game_data_v204.game_npcs[i].sprites[j][k].colision_rect;
                    game_data_v21.game_npcs[i].sprites[j][k].duration = game_data_v204.game_npcs[i].sprites[j][k].duration;
                    game_data_v21.game_npcs[i].sprites[j][k].sprite_graphic_pos_x = game_data_v204.game_npcs[i].sprites[j][k].sprite_graphic_pos_x;
                    game_data_v21.game_npcs[i].sprites[j][k].used = game_data_v204.game_npcs[i].sprites[j][k].used;
                }
            }

            game_data_v21.game_npcs[i].frame_size = game_data_v204.game_npcs[i].frame_size;
            sprintf(game_data_v21.game_npcs[i].graphic_filename, "%s", game_data_v204.game_npcs[i].graphic_filename);
            game_data_v21.game_npcs[i].hp = game_data_v204.game_npcs[i].hp;
            game_data_v21.game_npcs[i].IA_type = game_data_v204.game_npcs[i].IA_type;
            game_data_v21.game_npcs[i].id = game_data_v204.game_npcs[i].id;
            sprintf(game_data_v21.game_npcs[i].name, "%s", game_data_v204.game_npcs[i].name);
            for (int j=0; j<2; j++) {
                game_data_v21.game_npcs[i].projectile_id[j] = game_data_v204.game_npcs[i].projectile_id[j];
            }
            game_data_v21.game_npcs[i].shield_type = game_data_v204.game_npcs[i].shield_type;
            game_data_v21.game_npcs[i].speed = game_data_v204.game_npcs[i].speed;
            game_data_v21.game_npcs[i].start_point.x = game_data_v204.game_npcs[i].start_point.x;
            if (i == 0 && game_data_v204.game_npcs[i].start_point.y != 0) { std::cout << "name: " << game_data_v21.game_npcs[i].name << ", game_data_v204.game_npcs[i].start_point.y: " << game_data_v204.game_npcs[i].start_point.y << std::endl; }
            game_data_v21.game_npcs[i].start_point = game_data_v204.game_npcs[i].start_point;
            game_data_v21.game_npcs[i].walk_range = game_data_v204.game_npcs[i].walk_range;
            /// @END - real conversion on this part
        }
    }

    // OBJECTS CONVERSION
    for (int i=0; i<GAME_MAX_OBJS; i++) {
        // animation_auto_start, animation_loop and animation_started use default values
        game_data_v21.objects[i].direction = game_data_v204.objects[i].direction;
        game_data_v21.objects[i].distance = game_data_v204.objects[i].distance;
        game_data_v21.objects[i].frame = game_data_v204.objects[i].frame;
        sprintf(game_data_v21.objects[i].graphic_filename, "%s", game_data_v204.objects[i].graphic_filename);
        game_data_v21.objects[i].id = game_data_v204.objects[i].id;
        game_data_v21.objects[i].limit = game_data_v204.objects[i].limit;
        sprintf(game_data_v21.objects[i].name, "%s", game_data_v204.objects[i].name);
        game_data_v21.objects[i].size = game_data_v204.objects[i].size;
        game_data_v21.objects[i].speed = game_data_v204.objects[i].speed;
        game_data_v21.objects[i].timer = game_data_v204.objects[i].timer;
        game_data_v21.objects[i].type = game_data_v204.objects[i].type;
    }

    // PROJECTILES CONVERSION
    for (int i=0; i<MAX_FILE_PROJECTILES; i++) {
        game_data_v21.projectiles[i].damage = PROJECTILE_DEFAULT_DAMAGE;
        sprintf(game_data_v21.projectiles[i].graphic_filename, "%s", game_data_v204.projectiles[i].graphic_filename);
        game_data_v21.projectiles[i].hp = game_data_v204.projectiles[i].hp;
        game_data_v21.projectiles[i].id = game_data_v204.projectiles[i].id;
        game_data_v21.projectiles[i].is_destructible = game_data_v204.projectiles[i].is_destructible;
        game_data_v21.projectiles[i].max_shots = game_data_v204.projectiles[i].max_shots;
        sprintf(game_data_v21.projectiles[i].name, "%s", game_data_v204.projectiles[i].name);
        game_data_v21.projectiles[i].size = game_data_v204.projectiles[i].size;
        game_data_v21.projectiles[i].speed = PROJECTILE_DEFAULT_SPEED;
        game_data_v21.projectiles[i].trajectory = TRAJECTORY_LINEAR;
    }

    // AI TYPES CONVERSION
    for (int i=0; i<MAX_AI_TYPES; i++) {
        game_data_v21.ai_types[i].id = game_data_v204.ai_types[i].id;
        sprintf(game_data_v21.ai_types[i].name, "%s", game_data_v204.ai_types[i].name);
        // don't conver states, as they were completaly reformuled
    }


	// COPY OTHER/UNCHANGED
    for (int i=0; i<MAX_WEAPON_N; i++) {
        game_data_v21.weapons[i] = game_data_v204.weapons[i];
    }

    for (int i=0; i<MAX_STAGES; i++) {
        game_data_v21.stages[i] = game_data_v204.stages[i];
    }

	for (int i=0; i<MAX_FILE_PLAYERS; i++) {
        game_data_v21.players[i] = game_data_v204.players[i];
	}


    std::cout << "p[0] name: " << game_data_v21.players[0].name << std::endl;
    fio_new.write_game(game_data_v21);
    std::cout << "Data written to file." << std::endl;
}


void convert_21_to_211()
{
    format_v_2_1::file_io fio_v21;
    format_v_2_1_1::file_io fio_v211;
    std::cout << "Converting data from 2.1 to 2.1.1 ..." << std::endl;
    fio_v21.read_game(game_data_v21);

    for (int i=0; i<GAME_MAX_OBJS; i++) {
        game_data_v211.game_npcs[i] = game_data_v21.game_npcs[i];
        game_data_v211.objects[i] = game_data_v21.objects[i];
    }
    for (int i=0; i<MAX_FILE_PROJECTILES; i++) {
        game_data_v211.projectiles[i] = game_data_v21.projectiles[i];
    }
    for (int i=0; i<MAX_WEAPON_N; i++) {
        game_data_v211.weapons[i] = game_data_v21.weapons[i];
    }
    for (int i=0; i<MAX_FILE_PLAYERS; i++) {
        game_data_v211.players[i] = game_data_v21.players[i];
    }
    for (int i=0; i<MAX_AI_TYPES; i++) {
		game_data_v211.ai_types[i].id = game_data_v21.ai_types[i].id;
		sprintf(game_data_v211.ai_types[i].name, "%s", game_data_v21.ai_types[i].name);
		for (int j=0; j<4; j++) {
			game_data_v211.ai_types[i].states[j] = game_data_v21.ai_types[i].states[j];
		}
    }
    game_data_v211.version = 1.0;
    sprintf(game_data_v211.name, "%s", "Rockbot");
    game_data_v211.semi_charged_projectile_id = 0;
    game_data_v211.player_items[0] = 0;
    game_data_v211.player_items[1] = 0;

    for (int i=0; i<MAX_STAGES; i++) {
        sprintf(game_data_v211.stage_face_filename[i], "%s", game_data_v21.stages[i].boss.face_graphics_filename);
        std::cout << "stage[" << i << "] - boss_name: " << game_data_v21.stages[i].boss.name << ", boss_face: " << game_data_v21.stages[i].boss.face_graphics_filename << ", game.face: " << game_data_v211.stage_face_filename[i] << std::endl;
        v211_stages.stages[i] = game_data_v21.stages[i];
    }


    fio_v211.write_game(game_data_v211);
    fio_v211.write_all_stages(v211_stages);
    std::cout << "Data written to file." << std::endl;
}



int main(int argc, char *argv[])
{
	std::string EXEC_NAME("conversor");

#ifndef WIN32
	EXEC_NAME = "conversor";
#else
	EXEC_NAME = "conversor.exe";
#endif

	std::string argvString = std::string(argv[0]);
	FILEPATH = argvString.substr(0, argvString.size()-EXEC_NAME.size());

	//std::cout << "Conversion disabled until implementing new 2.0 to 2.0.1 conversion option (command-line parameter)" << std::endl;
	//convert_200_to_201();
	//convert_201_to_202();
    //convert_202_to_203();
    //convert_203_to_204();
    //convert_204_to_21();
    convert_21_to_211();
}
