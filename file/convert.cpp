#include "convert.h"
#include "file_io.h"

format_v_2_1_1::file_game game_data_v211;
format_v_2_1_1::file_stages v211_stages;

format_v_2_1_2::file_game game_data_v212;
format_v_2_1_2::file_stages v212_stages;


convert::convert()
{
}

void convert::v211_to_v212() const
{
    format_v_2_1_2::file_io fio_v212;
    format_v_2_1_1::file_io fio_v211;
    std::cout << "Converting data from 2.1.1 to 2.1.2 ..." << std::endl;
    fio_v211.read_game(game_data_v211);
    fio_v211.read_all_stages(v211_stages);

    /// @TODO - convert gravity back to AI
    for (int i=0; i<GAME_MAX_OBJS; i++) {
        game_data_v212.game_npcs[i] = game_data_v211.game_npcs[i];
        game_data_v212.objects[i] = game_data_v211.objects[i];
    }
    for (int i=0; i<MAX_FILE_PROJECTILES; i++) {
        game_data_v212.projectiles[i] = game_data_v211.projectiles[i];
    }
    for (int i=0; i<MAX_WEAPON_N; i++) {
        game_data_v212.weapons[i] = game_data_v211.weapons[i];
    }
    for (int i=0; i<MAX_FILE_PLAYERS; i++) {
        game_data_v212.players[i] = game_data_v211.players[i];
    }
    for (int i=0; i<MAX_AI_TYPES; i++) {
        game_data_v212.ai_types[i].id = game_data_v211.ai_types[i].id;
        sprintf(game_data_v212.ai_types[i].name, "%s", game_data_v211.ai_types[i].name);
        for (int j=0; j<4; j++) {
            game_data_v212.ai_types[i].states[j] = game_data_v211.ai_types[i].states[j];
        }
        for (int j=0; j<MAX_AI_REACTIONS; j++) {
            game_data_v212.ai_types[i].reactions[j].action = game_data_v212.game_npcs[i].sprites[ANIM_TYPE_TELEPORT][j+1].colision_rect.x;
            game_data_v212.ai_types[i].reactions[j].extra_parameter = game_data_v212.game_npcs[i].sprites[ANIM_TYPE_TELEPORT][j+1].colision_rect.y;
        }
    }
    game_data_v212.version = 1.0;
    sprintf(game_data_v212.name, "%s", "Rockbot");
    game_data_v212.semi_charged_projectile_id = 0;
    game_data_v212.player_items[0] = 0;
    game_data_v212.player_items[1] = 0;

    for (int i=0; i<MAX_STAGES; i++) {
        sprintf(game_data_v212.stage_face_filename[i], "%s", game_data_v211.stage_face_filename[i]);
        /// @REDO
        //v212_stages.stages[i] = v211_stages.stages[i];
    }


    fio_v212.write_game(game_data_v212);
    fio_v212.write_all_stages(v212_stages);
    std::cout << "Data written to file." << std::endl;
}
