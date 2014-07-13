#include <cstdlib>
#include "file_io.h"
#include "convert.h"
#include "timerlib.h"

#ifdef DREAMCAST
#include <kos.h>
#endif

extern std::string FILEPATH;
extern std::string SAVEPATH;

extern CURRENT_FILE_FORMAT::st_game_config game_config;

namespace format_v_2_1_1 {

    file_io::file_io()
    {
    }

    void file_io::write_game(format_v_2_1_1::file_game& data_in) const {
        std::ofstream fp;
        std::string filename = std::string(FILEPATH) + "data/game_v211.dat";

        fp.open(filename.c_str(), std::ios::out | std::ios::binary | std::ios::ate);
        if (!fp.is_open()) {
            std::cout << "ERROR::write_game - could not write to file '" << filename << std::endl;
            return;
        } else {
            std::cout << "fio::write_game - recorded to file '" << filename << std::endl;
        }

        fp.write(reinterpret_cast<char *>(&data_in), sizeof(struct format_v_2_1_1::file_game));
        fp.close();

        // ----------------------- STAGES ----------------------- //

    }

    void file_io::write_all_stages(format_v_2_1_1::file_stages &stages_data_in) const
    {
        std::ofstream fp;
        std::string filename = std::string(FILEPATH) + "data/stages_v211.dat";
        fp.open(filename.c_str(), std::ios::out | std::ios::binary | std::ios::ate);
        if (!fp.is_open()) {
            std::cout << "ERROR::write_game - could not write to file '" << filename << std::endl;
            return;
        } else {
            std::cout << "fio::write_game - recorded to file '" << filename << std::endl;
        }
        fp.write(reinterpret_cast<char *>(&stages_data_in), sizeof(struct format_v_2_1_1::file_stages));
        fp.close();
    }



    void file_io::read_game(format_v_2_1_1::file_game& data_out) const {
        FILE *fp;
        std::string filename = std::string(FILEPATH) + "data/game_v211.dat";
        fp = fopen(filename.c_str(), "rb");
        if (!fp) {
            std::cout << "ERROR: Could not read save 211" << std::endl;
            std::fflush(stdout);
            exit(-1);
        }
        int read_result = fread(&data_out, sizeof(struct format_v_2_1_1::file_game), 1, fp);
        if (read_result  == -1) {
            printf(">>file_io::read_game - Error reading struct data from game file '%s'.\n", filename.c_str());
            std::fflush(stdout);
            exit(-1);
        }
        fclose(fp);
    }


    void file_io::read_all_stages(format_v_2_1_1::file_stages& stages_data_out) const
    {
        FILE *fp;
        std::string filename = std::string(FILEPATH) + "data/stages_v211.dat";
        fp = fopen(filename.c_str(), "rb");
        if (!fp) {
            std::cout << "ERROR::read_game - could not load file '" << filename << std::endl;
            std::fflush(stdout);
            exit(-1);
        }
        fread(&stages_data_out, sizeof(format_v_2_1_1::file_stages), 1, fp);
        fclose(fp);
    }

    void file_io::read_stage(format_v_2_0_3::file_stage &stages_data_out, short stage_n) const
    {
        FILE *fp;
        std::string filename = std::string(FILEPATH) + "data/stages_v211.dat";
        fp = fopen(filename.c_str(), "rb");
        if (!fp) {
            std::cout << "ERROR: Could not read stages 211" << std::endl;
            std::fflush(stdout);
            exit(-1);
        }
        fseek(fp, sizeof(format_v_2_0_3::file_stage) * stage_n, SEEK_SET);
        int read_result = fread(&stages_data_out, sizeof(struct format_v_2_0_3::file_stage), 1, fp);
        if (read_result  == -1) {
            printf(">>file_io::read_game - Error reading struct data from game file '%s'.\n", filename.c_str());
            std::fflush(stdout);
            exit(-1);
        }
        fclose(fp);
    }


}



namespace format_v_2_1_2 {

    file_io::file_io()
    {

    }

#ifdef WII


    void short_to_little_endian(short &s)
    {
        s = (s>>8) | (s<<8);
    }

    void u_short_to_little_endian(unsigned short &s)
    {
        short temp_short = s;
        short_to_little_endian(temp_short);
        s = temp_short;
    }

    void int_to_little_endian(int &i)
    {
        i = (i<<24)|((i<<8)&0xFF0000)|((i>>8)&0xFF00)|(i>>24);
    }

    void u_int_to_little_endian(unsigned int &s)
    {
        int temp_int = s;
        int_to_little_endian(temp_int);
        s = temp_int;
    }

    void convert_game_data(format_v_2_1_2::file_game& game_data) {
        // convert NPCs
        for (int i=0; i<GAME_MAX_OBJS; i++) {
            short_to_little_endian(game_data.game_npcs[i].id);
            short_to_little_endian(game_data.game_npcs[i].projectile_id[0]);
            short_to_little_endian(game_data.game_npcs[i].projectile_id[1]);
            short_to_little_endian(game_data.game_npcs[i].direction);
            short_to_little_endian(game_data.game_npcs[i].speed);
            short_to_little_endian(game_data.game_npcs[i].walk_range);
            short_to_little_endian(game_data.game_npcs[i].facing);
            short_to_little_endian(game_data.game_npcs[i].shield_type);
            short_to_little_endian(game_data.game_npcs[i].IA_type);
            short_to_little_endian(game_data.game_npcs[i].fly_flag);
            short_to_little_endian(game_data.game_npcs[i].hp.current);
            short_to_little_endian(game_data.game_npcs[i].hp.total);
            short_to_little_endian(game_data.game_npcs[i].start_point.x);
            short_to_little_endian(game_data.game_npcs[i].start_point.y);
            for (int x=0; x<ANIM_TYPE_COUNT; x++) {
                for (int y=0; y<ANIM_FRAMES_COUNT; y++) {
                    short_to_little_endian(game_data.game_npcs[i].sprites[x][y].colision_rect.x);
                    short_to_little_endian(game_data.game_npcs[i].sprites[x][y].colision_rect.y);
                    short_to_little_endian(game_data.game_npcs[i].sprites[x][y].colision_rect.w);
                    short_to_little_endian(game_data.game_npcs[i].sprites[x][y].colision_rect.h);
                    u_short_to_little_endian(game_data.game_npcs[i].sprites[x][y].duration);
                    u_short_to_little_endian(game_data.game_npcs[i].sprites[x][y].sprite_graphic_pos_x);
                }
            }
            short_to_little_endian(game_data.game_npcs[i].frame_size.width);
            short_to_little_endian(game_data.game_npcs[i].frame_size.height);
            for (int j=0; j<9; j++) {
                short_to_little_endian(game_data.game_npcs[i].weakness[j].damage_multiplier);
                short_to_little_endian(game_data.game_npcs[i].weakness[j].weapon_id);
            }
            short_to_little_endian(game_data.game_npcs[i].sprites_pos_bg.x);
            short_to_little_endian(game_data.game_npcs[i].sprites_pos_bg.y);
            int_to_little_endian(game_data.game_npcs[i].gravity_level);
        }
        // objects
        for (int i=0; i<GAME_MAX_OBJS; i++) {
            short_to_little_endian(game_data.objects[i].id);
            short_to_little_endian(game_data.objects[i].type);
            int_to_little_endian(game_data.objects[i].timer);
            short_to_little_endian(game_data.objects[i].speed);
            short_to_little_endian(game_data.objects[i].limit);
            short_to_little_endian(game_data.objects[i].direction);
            short_to_little_endian(game_data.objects[i].distance);
            short_to_little_endian(game_data.objects[i].size.width);
            short_to_little_endian(game_data.objects[i].size.height);
            short_to_little_endian(game_data.objects[i].frame_duration);
        }
        // projectiles[MAX_FILE_PROJECTILES]
        for (int i=0; i<MAX_FILE_PROJECTILES; i++) {
            u_short_to_little_endian(game_data.projectiles[i].damage);
            u_short_to_little_endian(game_data.projectiles[i].hp);
            short_to_little_endian(game_data.projectiles[i].id);
            u_short_to_little_endian(game_data.projectiles[i].max_shots);
            short_to_little_endian(game_data.projectiles[i].size.width);
            short_to_little_endian(game_data.projectiles[i].size.height);
            u_short_to_little_endian(game_data.projectiles[i].speed);
            /// NOT NEEDED AS IT IS A enum? - short_to_little_endian(game_data.projectiles[i].trajectory);
        }
        // weapons[MAX_WEAPON_N]
        for (int i=0; i<MAX_WEAPON_N; i++) {
            u_int_to_little_endian(game_data.weapons[i].damage);
            short_to_little_endian(game_data.weapons[i].id);
            u_short_to_little_endian(game_data.weapons[i].id_projectile);
        }
        // players[MAX_FILE_PLAYERS]
        for (int i=0; i<MAX_FILE_PLAYERS; i++) {
            for (int j=0; j<3; j++) {
                short_to_little_endian(game_data.players[i].color_keys[j].r);
                short_to_little_endian(game_data.players[i].color_keys[j].g);
                short_to_little_endian(game_data.players[i].color_keys[j].b);
            }
            short_to_little_endian(game_data.players[i].full_charged_projectile_id);
            u_short_to_little_endian(game_data.players[i].HP);
            short_to_little_endian(game_data.players[i].id);
            u_short_to_little_endian(game_data.players[i].max_shots);
            u_short_to_little_endian(game_data.players[i].move_speed);
            u_short_to_little_endian(game_data.players[i].simultaneous_shots);
            for (int x=0; x<ANIM_TYPE_COUNT; x++) {
                for (int y=0; y<ANIM_FRAMES_COUNT; y++) {
                    short_to_little_endian(game_data.players[i].sprites[x][y].colision_rect.x);
                    short_to_little_endian(game_data.players[i].sprites[x][y].colision_rect.y);
                    short_to_little_endian(game_data.players[i].sprites[x][y].colision_rect.w);
                    short_to_little_endian(game_data.players[i].sprites[x][y].colision_rect.h);
                    u_short_to_little_endian(game_data.players[i].sprites[x][y].duration);
                    u_short_to_little_endian(game_data.players[i].sprites[x][y].sprite_graphic_pos_x);
                }
            }
            short_to_little_endian(game_data.players[i].sprite_hit_area.x);
            short_to_little_endian(game_data.players[i].sprite_hit_area.y);
            short_to_little_endian(game_data.players[i].sprite_hit_area.w);
            short_to_little_endian(game_data.players[i].sprite_hit_area.h);
            short_to_little_endian(game_data.players[i].sprite_size.width);
            short_to_little_endian(game_data.players[i].sprite_size.height);
            for (int j=0; j<MAX_WEAPON_N; j++) {
                short_to_little_endian(game_data.players[i].weapon_colors[j].id_weapon);
                short_to_little_endian(game_data.players[i].weapon_colors[j].color1.r);
                short_to_little_endian(game_data.players[i].weapon_colors[j].color1.g);
                short_to_little_endian(game_data.players[i].weapon_colors[j].color1.b);
                short_to_little_endian(game_data.players[i].weapon_colors[j].color2.r);
                short_to_little_endian(game_data.players[i].weapon_colors[j].color2.g);
                short_to_little_endian(game_data.players[i].weapon_colors[j].color2.b);
                short_to_little_endian(game_data.players[i].weapon_colors[j].color3.r);
                short_to_little_endian(game_data.players[i].weapon_colors[j].color3.g);
                short_to_little_endian(game_data.players[i].weapon_colors[j].color3.b);
            }
        }
        // ai_types[MAX_AI_TYPES]
        for (int i=0; i<MAX_AI_TYPES; i++) {
            short_to_little_endian(game_data.ai_types[i].id);
            for (int j=0; j<MAX_AI_REACTIONS; j++) {
                int_to_little_endian(game_data.ai_types[i].reactions[j].action);
                int_to_little_endian(game_data.ai_types[i].reactions[j].extra_parameter);
                int_to_little_endian(game_data.ai_types[i].reactions[j].go_to);
                int_to_little_endian(game_data.ai_types[i].reactions[j].go_to_delay);
            }
            for (int j=0; j<AI_MAX_STATES; j++) {
                int_to_little_endian(game_data.ai_types[i].states[j].action);
                int_to_little_endian(game_data.ai_types[i].states[j].chance);
                int_to_little_endian(game_data.ai_types[i].states[j].extra_parameter);
                int_to_little_endian(game_data.ai_types[i].states[j].go_to);
                int_to_little_endian(game_data.ai_types[i].states[j].go_to_delay);
            }
        }
    }

    void convert_stage_data(format_v_2_1_2::file_stage& stage_data) {
        // maps
        for (int i=0; i<STAGE_MAX_MAPS; i++) {
            short_to_little_endian(stage_data.maps[i].id);
            short_to_little_endian(stage_data.maps[i].background_color.r);
            short_to_little_endian(stage_data.maps[i].background_color.g);
            short_to_little_endian(stage_data.maps[i].background_color.b);
            // maps -convert backgrounds
            for (int j=0; j<2; j++) {
                short_to_little_endian(stage_data.maps[i].backgrounds[j].id);
                short_to_little_endian(stage_data.maps[i].backgrounds[j].adjust_y);
                short_to_little_endian(stage_data.maps[i].backgrounds[j].speed);
            }
            // maps -convert maps tiles
            for (int x=0; x<MAP_W; x++) {
                for (int y=0; y<MAP_H; y++) {
                    short_to_little_endian(stage_data.maps[i].tiles[x][y].id);
                    short_to_little_endian(stage_data.maps[i].tiles[x][y].locked);
                    short_to_little_endian(stage_data.maps[i].tiles[x][y].tile1.x);
                    short_to_little_endian(stage_data.maps[i].tiles[x][y].tile1.y);
                    short_to_little_endian(stage_data.maps[i].tiles[x][y].tile2.x);
                    short_to_little_endian(stage_data.maps[i].tiles[x][y].tile2.y);
                    short_to_little_endian(stage_data.maps[i].tiles[x][y].tile3.x);
                    short_to_little_endian(stage_data.maps[i].tiles[x][y].tile3.y);
                }
            }
            // maps -convert maps npcs
            for (int j=0; j<MAX_MAP_NPC_N; j++) {
                u_short_to_little_endian(stage_data.maps[i].map_npcs[j].direction);
                short_to_little_endian(stage_data.maps[i].map_npcs[j].id_npc);
                short_to_little_endian(stage_data.maps[i].map_npcs[j].start_point.x);
                short_to_little_endian(stage_data.maps[i].map_npcs[j].start_point.y);
            }
            // maps -convert map objects
            for (int j=0; j<MAX_MAP_NPC_N; j++) {
                short_to_little_endian(stage_data.maps[i].map_objects[j].id_object);
                u_short_to_little_endian(stage_data.maps[i].map_objects[j].direction);
                short_to_little_endian(stage_data.maps[i].map_objects[j].start_point.x);
                short_to_little_endian(stage_data.maps[i].map_objects[j].start_point.y);
            }
        }
        // links
        for (int i=0; i<STAGE_MAX_LINKS; i++) {
            short_to_little_endian(stage_data.links[i].id_map_destiny);
            short_to_little_endian(stage_data.links[i].id_map_origin);
            short_to_little_endian(stage_data.links[i].pos_destiny.x);
            short_to_little_endian(stage_data.links[i].pos_destiny.y);
            short_to_little_endian(stage_data.links[i].pos_origin.x);
            short_to_little_endian(stage_data.links[i].pos_origin.y);
            u_int_to_little_endian(stage_data.links[i].size);
            short_to_little_endian(stage_data.links[i].type);
        }
        // boss
        u_short_to_little_endian(stage_data.boss.id_npc);
        u_short_to_little_endian(stage_data.boss.id_weapon);
        // intro_dialog
        u_short_to_little_endian(stage_data.intro_dialog.id);
        // boss_dialog
        u_short_to_little_endian(stage_data.intro_dialog.id);
        // colorcycle
        short_to_little_endian(stage_data.colorcycle.id);
        for (int i=0; i<COLORCYCLE_MAX_ITEMS; i++) {
            for (int j=0; j<COLOR_KEY_LENGTH; j++) {
                short_to_little_endian(stage_data.colorcycle.duration[i][j]);
                short_to_little_endian(stage_data.colorcycle.color[i][j].r);
                short_to_little_endian(stage_data.colorcycle.color[i][j].g);
                short_to_little_endian(stage_data.colorcycle.color[i][j].b);
            }
        }
    }

    void convert_allstages_data(format_v_2_1_2::file_stages& data_in)
    {
        for (int i=0; i<MAX_STAGES; i++) {
            convert_stage_data(data_in.stages[i]);
        }
    }

#endif


    void file_io::write_game(format_v_2_1_2::file_game& data_in) const {
        std::ofstream fp;
        std::string filename = std::string(FILEPATH) + "data/game_v212.dat";

        fp.open(filename.c_str(), std::ios::out | std::ios::binary | std::ios::ate);
        if (!fp.is_open()) {
            std::cout << "ERROR::write_game - could not write to file '" << filename << std::endl;
            return;
        } else {
            std::cout << "fio::write_game - recorded to file '" << filename << std::endl;
        }

        fp.write(reinterpret_cast<char *>(&data_in), sizeof(struct format_v_2_1_2::file_game));
        fp.close();

        // ----------------------- STAGES ----------------------- //

    }

    void file_io::write_all_stages(format_v_2_1_2::file_stages &stages_data_in) const
    {
        std::ofstream fp;
        std::string filename = std::string(FILEPATH) + "data/stages_v212.dat";
        fp.open(filename.c_str(), std::ios::out | std::ios::binary | std::ios::ate);
        if (!fp.is_open()) {
            std::cout << "ERROR::write_game - could not write to file '" << filename << std::endl;
            return;
        } else {
            std::cout << "fio::write_game - recorded to file '" << filename << std::endl;
        }
        fp.write(reinterpret_cast<char *>(&stages_data_in), sizeof(struct format_v_2_1_2::file_stages));
        fp.close();
    }



    void file_io::read_game(format_v_2_1_2::file_game& data_out) const {
        FILE *fp;
        std::string filename = std::string(FILEPATH) + "data/game_v212.dat";
        fp = fopen(filename.c_str(), "rb");
        if (!fp) {
            std::cout << ">>file_io::read_game - file '" << filename << "' not found." << std::endl;
            std::fflush(stdout);
            exit(-1);
        }
        int read_result = fread(&data_out, sizeof(struct format_v_2_1_2::file_game), 1, fp);
        if (read_result  == -1) {
            std::cout << ">>file_io::read_game - Error reading struct data from game file '" << filename << "'." << std::endl;
            std::fflush(stdout);
            exit(-1);
        }
#ifdef WII
        convert_game_data(data_out);
#endif
        fclose(fp);
    }


    void file_io::read_all_stages(format_v_2_1_2::file_stages& stages_data_out)
    {
        FILE *fp;
        std::string filename = std::string(FILEPATH) + "data/stages_v212.dat";
        fp = fopen(filename.c_str(), "rb");
        if (!fp) {
            std::cout << "ERROR::read_game - could not load file '" << filename << std::endl;
            std::fflush(stdout);
            exit(-1);
        }
        fread(&stages_data_out, sizeof(format_v_2_1_2::file_stages), 1, fp);
        fclose(fp);
    }

    void file_io::read_stage(format_v_2_1_2::file_stage &stages_data_out, short stage_n)
    {
        FILE *fp;
        std::string filename = std::string(FILEPATH) + "data/stages_v212.dat";
        fp = fopen(filename.c_str(), "rb");
        if (!fp) {
            printf("ERROR.read_stage: Could not read stage '%s'\n", filename.c_str());
            std::fflush(stdout);
            exit(-1);
        }
        fseek(fp, sizeof(format_v_2_1_2::file_stage) * stage_n, SEEK_SET);
        int read_result = fread(&stages_data_out, sizeof(struct format_v_2_1_2::file_stage), 1, fp);
        if (read_result == -1) {
            printf(">>file_io::read_game - Error reading struct data from stage file.\n");
            std::fflush(stdout);
            exit(-1);
        }
#ifdef WII
        convert_stage_data(stages_data_out);
#endif
        fclose(fp);
    }

    bool file_io::file_exists(std::string filename) const
    {
        bool res = false;
        FILE *fp;
        fp = fopen(filename.c_str(), "rb");
        if (fp) {
            res = true;
            fclose(fp);
        }
        return res;
    }

    void file_io::check_conversion() const
    {
        std::string filename_v211 = std::string(FILEPATH) + "data/game_v211.dat";
        std::string filename_v212 = std::string(FILEPATH) + "data/game_v212.dat";
        if (file_exists(filename_v212) == false && file_exists(filename_v211) == true) {
            convert convert_obj;
            convert_obj.v211_to_v212();
        }
    }

    bool file_io::save_exists() const
    {
#ifdef DREAMCAST
	file_t f;
	vmu_pkg_t pkg;
    int filesize;
	uint8 *data;
    printf("Checking if exists save data\n");
	f = fs_open("/vmu/a1/rbsav", O_RDONLY);

    if(f<0) {
        printf("Error reading save data - save not exists\n");
        return false;
    }
    printf("Save data loaded!\n");
	return true;
#else

        std::string filename = std::string(SAVEPATH) + "/game212.sav";
        FILE *fp;
        fp = fopen(filename.c_str(), "rb");
        if (fp) {
            fclose(fp);
            return true;
        }
        return false;
#endif
    }

    void file_io::load_config(format_v_2_1_2::st_game_config& config)
    {

#ifdef DREAMCAST
	file_t f;
	vmu_pkg_t pkg;
    int filesize;
	uint8 *data;
    printf("Loading config data\n");
	f = fs_open("/vmu/a1/rbcfg", O_RDONLY);

    if(f<0) {
        printf("Error reading config data\n");
        return;
    }

	filesize = fs_total(f);
	data=(uint8 *)malloc(filesize);
	fs_read(f, data, filesize);
	vmu_pkg_parse(data, &pkg);
	memcpy(&config,pkg.data,sizeof(struct format_v_2_1_2::st_game_config));
	fs_close(f);

#else

        FILE *fp;
        std::string filename = std::string(SAVEPATH) + "/config_v212.sav";
        fp = fopen(filename.c_str(), "rb");
        if (!fp) {
            std::cout << "WARNING: Could not read config file '" << filename.c_str() << "'." << std::endl;
        } else {
            int read_result = fread(&config, sizeof(struct format_v_2_1_2::st_game_config), 1, fp);
            if (read_result  == -1) {
                printf(">>file_io::read_game - Error reading struct data from game file '%s'.\n", filename.c_str());
                std::fflush(stdout);
                exit(-1);
            }
            fclose(fp);
        }

#endif
        if (config.get_current_platform() != config.platform) {
            config.reset();
        }
#ifndef PC
        config.video_filter = VIDEO_FILTER_NOSCALE;
        std::cout << "IO::load_config - FORCE SET video_filter to " << VIDEO_FILTER_NOSCALE << ", value: " << config.video_filter << std::endl;
#endif
    }

    void file_io::save_config(st_game_config &config) const
    {

#ifdef DREAMCAST
	vmu_pkg_t pkg;
	uint8 *pkg_out;
	file_t f;
    int pkg_size;

    strcpy(pkg.desc_short, "Rockbot");
    strcpy(pkg.desc_long, "Rockbot config file");
    strcpy(pkg.app_id, "RB");
    pkg.icon_cnt = 0;
    pkg.icon_anim_speed = 0;
    pkg.eyecatch_type = VMUPKG_EC_NONE;
    pkg.data_len = sizeof(struct format_v_2_1_2::st_game_config);
    pkg.data = (uint8 *)&config;

    vmu_pkg_build(&pkg, &pkg_out, &pkg_size);
    fs_unlink("/vmu/a1/rbcfg");
    f = fs_open("/vmu/a1/rbcfg", O_WRONLY);

    if(!f) {
        printf("Error writing config file\n");
        return;
    }

    fs_write(f, pkg_out, pkg_size);
    fs_close(f);
#else
        FILE *fp;
        std::string filename = std::string(SAVEPATH) + "/config_v212.sav";
        fp = fopen(filename.c_str(), "wb");
        if (!fp) {
            std::cout << "Error: Could not open config file '" << filename << "'." << std::endl;
            std::fflush(stdout);
            exit(-1);
        }
        fwrite(&config, sizeof(struct format_v_2_1_2::st_game_config), 1, fp);
        fclose(fp);
#endif

    }

    int file_io::read_stage_boss_id(int stage_n)
    {
        FILE *fp;
        std::string filename = std::string(FILEPATH) + "data/stages_v212.dat";
        fp = fopen(filename.c_str(), "rb");
        if (!fp) {
            printf("ERROR.read_stage: Could not read stage '%s'\n", filename.c_str());
            std::fflush(stdout);
            exit(-1);
        }

        // WHY is it missing by 2 bytes?
        int extra_seek = 2 + sizeof(short) + sizeof(char)*CHAR_NAME_SIZE + sizeof(char)*CHAR_FILENAME_SIZE + sizeof(format_v_2_0_3::file_map)*STAGE_MAX_MAPS + sizeof(format_v2_0::file_link)*STAGE_MAX_LINKS;
        fseek(fp, sizeof(format_v_2_1_2::file_stage) * stage_n + extra_seek, SEEK_SET);
        format_v2_0::file_boss boss;
        int read_result = fread(&boss, sizeof(struct format_v2_0::file_boss), 1, fp);
        if (read_result == -1) {
            printf(">>file_io::read_game - Error reading struct data from stage file.\n");
            std::fflush(stdout);
            exit(-1);
        }
#ifdef WII
        u_short_to_little_endian(boss.id_npc);
#endif
        fclose(fp);
        return boss.id_npc;


    }



    void file_io::read_save(format_v_2_1_2::st_save& data_out) const
    {

#ifdef DREAMCAST
	file_t f;
	vmu_pkg_t pkg;
    int filesize;
	uint8 *data;
    printf("Loading save data\n");
	f = fs_open("/vmu/a1/rbsav", O_RDONLY);

    if(f<0) {
        printf("Error reading save data\n");
        return;
    }

	filesize = fs_total(f);
	data=(uint8 *)malloc(filesize);
	fs_read(f, data, filesize);
	vmu_pkg_parse(data, &pkg);
	memcpy(&data_out,pkg.data,sizeof(struct format_v_2_1_2::st_save));
	fs_close(f);

#else
        FILE *fp;
        std::string filename = std::string(SAVEPATH) + "/game212.sav";
        fp = fopen(filename.c_str(), "rb");
        if (!fp) {
            std::cout << "ERROR: Could not read save" << std::endl;
            std::fflush(stdout);
            exit(-1);
        }
        int read_result = fread(&data_out, sizeof(struct format_v_2_1_2::st_save), 1, fp);
        if (read_result  == -1) {
            printf(">>file_io::read_game - Error reading struct data from game file '%s'.\n", filename.c_str());
            std::fflush(stdout);
            exit(-1);
        }

#endif
// DEBUG //
        /*
        for (int i=0; i<STAGE_COUNT; i++) {
            data_out.stages[i] = 1;
        }
        data_out.stages[SKULLCASTLE4] = 0;
        data_out.stages[SKULLCASTLE5] = 0;
        */
// -- DEBUG -- //



        if (data_out.items.lifes > 9) {
            data_out.items.lifes = 3;
        }
#ifndef DREAMCAST
        fclose(fp);
#endif
    }

    bool file_io::write_save(format_v_2_1_2::st_save& data_in)
    {

#ifdef DREAMCAST
	vmu_pkg_t pkg;
	uint8 *pkg_out;
	file_t f;
    int pkg_size;

    strcpy(pkg.desc_short, "Rockbot");
    strcpy(pkg.desc_long, "Rockbot save file");
    strcpy(pkg.app_id, "RB");
    pkg.icon_cnt = 0;
    pkg.icon_anim_speed = 0;
    pkg.eyecatch_type = VMUPKG_EC_NONE;
    pkg.data_len = sizeof(struct format_v_2_1_2::st_save);
    pkg.data = (uint8 *)&data_in;

    vmu_pkg_build(&pkg, &pkg_out, &pkg_size);
    fs_unlink("/vmu/a1/rbsav");
    f = fs_open("/vmu/a1/rbsav", O_WRONLY);

    if(!f) {
        printf("Error writing save data\n");
        return false;
    }

    fs_write(f, pkg_out, pkg_size);
    fs_close(f);
	
	return true;
#else
        FILE *fp;
        std::string filename = std::string(SAVEPATH) + "/game212.sav";
        fp = fopen(filename.c_str(), "wb");
        if (!fp) {
            std::cout << "Error: Could not open save-file '" << filename << "'." << std::endl; std::fflush(stdout);
            return false;
        }
        fwrite(&data_in, sizeof(struct format_v_2_1_2::st_save), 1, fp);
        fclose(fp);
        return true;
#endif
    }
}


