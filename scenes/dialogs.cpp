#include <cstring>
#include "dialogs.h"


extern std::string FILEPATH;

#include "graphicslib.h"
extern graphicsLib graphLib;

#include "inputlib.h"
extern inputLib input;

#include "graphic/draw.h"
extern draw draw_lib;

#include "graphic/option_picker.h"


extern CURRENT_FILE_FORMAT::st_game_config game_config;

extern CURRENT_FILE_FORMAT::file_game game_data;
extern CURRENT_FILE_FORMAT::file_stage stage_data;
extern CURRENT_FILE_FORMAT::st_save game_save;

dialogs::dialogs() : is_showing_dialog_bg(false)
{
    /// @TODO - temporary configurations should not be placed in st_config
    //if (game_config.two_players == 2 || game_config.selected_player == 1) {
    if (game_save.selected_player == 1) {
		player_name = "Rockbot";
		player_face = "rockbot.png";
	} else {
		player_name = "Betabot";
		player_face = "betabot.png";
	}
}


void dialogs::show_stage_dialog()
{
    //std::cout << "DEBUG - dialogs::show_stage_dialog::stage: " << stage << ", player_n: " << (game_config.selected_player-1) << std::endl;
    if (strlen(stage_data.intro_dialog.face_graphics_filename) <= 0) {
		return;
	}

    if (strlen(stage_data.intro_dialog.line1[0]) <= 0) {
        return;
    }

	std::string lines[3];
	for (int i=0; i<3; i++) {
        lines[i] = std::string(stage_data.intro_dialog.line1[i]);
	}
    show_dialog(stage_data.intro_dialog.face_graphics_filename, stage_data.intro_dialog.top_side, lines, true);
	for (int i=0; i<3; i++) {
        lines[i] = std::string(stage_data.intro_dialog.answer1[game_save.selected_player-1][i]);
	}
    show_dialog(game_data.players[game_save.selected_player-1].face_filename, stage_data.intro_dialog.top_side, lines, true); /// @TODO: create "extern" for player number
    if (strlen(stage_data.intro_dialog.line2[0]) > 0) {
		for (int i=0; i<3; i++) {
            lines[i] = std::string(stage_data.intro_dialog.line2[i]);
		}
        show_dialog(stage_data.intro_dialog.face_graphics_filename, stage_data.intro_dialog.top_side, lines, true);
	}
}



void dialogs::show_boss_dialog()
{
    if (strlen(stage_data.intro_dialog.face_graphics_filename) <= 0) {
		return;
	}
	std::string lines[3];
	for (int i=0; i<3; i++) {
        lines[i] = std::string(stage_data.boss_dialog.line1[i]);
	}
    //std::cout << "stage: " << stage << ", boss_face: '" << stage_data.boss.face_graphics_filename << "'" << std::endl;
    if (strlen(stage_data.boss.face_graphics_filename) <= 0) {
        sprintf(stage_data.boss.face_graphics_filename, "%s", "dr_kanotus.png");
	}
    show_dialog(stage_data.boss.face_graphics_filename, stage_data.boss_dialog.top_side, lines, true);

    for (int i=0; i<3; i++) {
        lines[i] = std::string(stage_data.boss_dialog.answer1[game_save.selected_player-1][i]);
	}

    if (lines[0].size() > 0) {
        show_dialog(game_data.players[game_save.selected_player-1].face_filename, stage_data.boss_dialog.top_side, lines, true); /// @TODO: create "extern" for player number
    } else {
        return;
    }

    if (strlen(stage_data.boss_dialog.line2[0]) > 0) {
		for (int i=0; i<3; i++) {
            lines[i] = std::string(stage_data.boss_dialog.line2[i]);
		}
        show_dialog(stage_data.boss.face_graphics_filename, stage_data.boss_dialog.top_side, lines, true);
	}
}

void dialogs::show_dialog(std::string face_file, bool top_side, std::string lines[3], bool show_btn=true)
{
    UNUSED(top_side);
	std::string temp_text;
	char temp_char;

    if (lines[0].size() < 1) {
        return;
    }

	draw_dialog_bg(show_btn);
    draw_lib.update_screen();
	st_position dialog_pos = graphLib.get_dialog_pos();
	graphLib.place_face(face_file, st_position(dialog_pos.x+16, dialog_pos.y+16));
    draw_lib.update_screen();

	/// @TODO: usar show_config_bg e hide_config_bg da graphLib - modificar para aceitar centered (que é o atual) ou top ou bottom
	for (int i=0; i<3; i++) {
		for (unsigned int j=0; j<lines[i].size(); j++) {
			temp_char = lines[i].at(j);
			temp_text = "";
			temp_text += temp_char;

			graphLib.draw_text(j*9+(dialog_pos.x+52), i*11+(dialog_pos.y+16), temp_text);
            draw_lib.update_screen();
			input.waitTime(15);
		}
	}

    input.wait_keypress();
}

bool dialogs::show_leave_game_dialog() const
{
    bool res = false;
    bool repeat_menu = true;
    int picked_n = -1;

    graphicsLib_gSurface bgCopy;
    graphLib.initSurface(st_size(RES_W, RES_H), &bgCopy);
    graphLib.copyArea(st_position(0, 0), &graphLib.gameScreen, &bgCopy);

    graphLib.show_dialog(0, false);
    st_position dialog_pos = graphLib.get_dialog_pos();
    graphLib.draw_text(dialog_pos.x+30, dialog_pos.y+16, "QUIT GAME?");
    std::vector<std::string> item_list;
    item_list.push_back("YES");
    item_list.push_back("NO");
    option_picker main_picker(false, st_position(dialog_pos.x+40, dialog_pos.y+16+11), item_list, false);
    draw_lib.update_screen();
    while (repeat_menu == true) {
        picked_n = main_picker.pick();
        if (picked_n == 0) {
            res = true;
            repeat_menu = false;
        } else if (picked_n == 1) {
            res = false;
            repeat_menu = false;
        } else {
            main_picker.draw();
        }
    }
    input.clean();
    input.waitTime(200);
    graphLib.copyArea(st_position(0, 0), &bgCopy, &graphLib.gameScreen);
    draw_lib.update_screen();
    return res;
}

void dialogs::show_timed_dialog(std::string face_file, bool is_left, std::string lines[], short timer, bool show_btn=true)
{
    UNUSED(is_left);
	std::string temp_text;
	char temp_char;

	draw_dialog_bg(show_btn);
    draw_lib.update_screen();
	st_position dialog_pos = graphLib.get_dialog_pos();
    graphLib.place_face(face_file, st_position(dialog_pos.x+16, dialog_pos.y+16));
    draw_lib.update_screen();

	/// @TODO: usar show_config_bg e hide_config_bg da graphLib - modificar para aceitar centered (que é o atual) ou top ou bottom
	for (int i=0; i<3; i++) {
        for (unsigned int j=0; j<lines[i].size(); j++) {
			temp_char = lines[i].at(j);
			temp_text = "";
			temp_text += temp_char;

            graphLib.draw_text(j*9+(dialog_pos.x+52), i*11+(dialog_pos.y+16), temp_text);
			//graphLib.draw_text(j*9+53, i*11+9, "A");
            draw_lib.update_screen();
			input.waitTime(15);
		}
	}
	input.waitTime(timer);
}




void dialogs::draw_dialog_bg(bool show_btn=true)
{
	if (is_showing_dialog_bg == true) {
		return;
	}
	graphLib.show_dialog(1, show_btn);
}

