#include <cstdlib>
#include "stage_select.h"

#include <string>

#include "file/format.h"

// INTERNAL GLOBALS
extern timerLib timer;
extern inputLib input;
extern soundLib soundManager;
extern graphicsLib graphLib;
extern std::string FILEPATH;
extern CURRENT_FILE_FORMAT::st_save game_save;
extern CURRENT_FILE_FORMAT::st_game_config game_config;

extern CURRENT_FILE_FORMAT::file_game game_data;

#include "graphic/draw.h"
extern draw draw_lib;

#include "game.h"
extern game gameControl;


stage_select::stage_select(graphicsLib_gSurface stage_ref[STAGE_SELECT_COUNT]) :
    highlight_animation_white(false), timer_intro(0), highlight_pos(135-graphLib.RES_DIFF_W, 88)
{
	int i;
	for (i=0; i<STAGE_SELECT_COUNT; i++) {
		STAGE_SELECT_SURFACES[i] = &stage_ref[i];
	}
    load_graphics();
}

short stage_select::finished_stages() const
{
    short total_stages = 0;
    for (int i=0; i<STAGE_COUNT; i++) {
        if (game_save.stages[i] == 1) {
            total_stages++;
        }
    }
    //std::cout << "stage_select::finished_stages: " << total_stages << std::endl;
    return total_stages;
}

void stage_select::load_graphics() {
	std::string filename;
	filename = FILEPATH + "data/images/backgrounds/stage_select_highlighted.png";
	graphLib.surfaceFromFile(filename, &s_light);

	filename = FILEPATH + "data/images/backgrounds/stage_select_darkned.png";
	graphLib.surfaceFromFile(filename, &s_dark);

    if (game_save.selected_player == 1) {
		filename = FILEPATH + "data/images/faces/rockbot_eyes.png";
	} else {
		filename = FILEPATH + "data/images/faces/betabot_eyes.png";
	}

	graphLib.surfaceFromFile(filename, &eyes_surface);

	filename = FILEPATH + "data/images/backgrounds/stage_select.png";
	graphLib.surfaceFromFile(filename, &background);
}



void stage_select::move_highlight(short int x_inc, short int y_inc) {
	graphLib.copyArea(highlight_pos, &s_dark, &graphLib.gameScreen);
	highlight_pos.x += x_inc;
	highlight_pos.y += y_inc;
	graphLib.copyArea(highlight_pos, &s_light, &graphLib.gameScreen);
    draw_lib.update_screen();
}


void stage_select::show_highlight() {
	graphLib.copyArea(highlight_pos, light_mode, &graphLib.gameScreen);
    draw_lib.update_screen();
}


//void stage_select::place_face(int face_n, char botname[20], short int posx, short int posy) {
void stage_select::place_face(std::string face_file, std::string botname, st_position pos) const {
	// TODO - calculate the text position according to it's strlen
	int txtPosX, txtPosY;

    //std::cout << "stage_select::place_face - face_file: " << face_file << std::endl;

	if (face_file.size() > 0) {
        graphLib.place_face(face_file, st_position(pos.x*80+63, pos.y*68+28));
    }
    txtPosX = pos.x*80+76-(botname.size()*7)*0.5;
    txtPosY = pos.y*68+71;
	graphLib.draw_text(txtPosX, txtPosY, botname);
}


void stage_select::animate_highlight() {
	if (timer.getTimer() > timer_intro) {
		if (light_mode == &s_light) {
			light_mode = &s_dark;
		} else {
			light_mode = &s_light;
		}
		show_highlight();
		timer_intro = timer.getTimer()+200;
	}
}

void stage_select::draw_eyes(int x, int y, bool erase_eyes) {
	int posX, posY;
	if (x == 1) {
		posX = 11;
	} else if (x == 0) {
		posX = 10;
	} else {
		posX = 12;
	}
	if (y == 1) {
		posY = 18;
	} else if (y == 0) {
		posY = 17;
	} else {
		posY = 19;
	}
	/*
	if (game_config.selected_player == 2) {
		posY -= 3;
	}
	*/
    posX = posX+80+63;
    posY = posY+64+32;
	if (erase_eyes) {
        if (game_save.selected_player == 1) {
			place_face("rockbot_no_eyes.png", "", st_position(1, 1));
		} else {
			place_face("betabot_no_eyes.png", "", st_position(1, 1));
		}
	} else {
        if (game_save.selected_player == 1) {
			graphLib.copyArea(st_position(posX, posY), &eyes_surface, &graphLib.gameScreen);
		} else {
			graphLib.copyArea(st_position(posX, posY-2), &eyes_surface, &graphLib.gameScreen);
		}
	}
}

struct st_position stage_select::select() {
	//SDL_Surface *spriteCopy, *s_light=NULL, *s_dark, *eyes_surface, *eyes_bg, *light_mode;
	struct st_position spacing, highlight_pos;
	int selection_end=0;

	soundManager.load_music("menu.mod");
	soundManager.play_music();
	input.clean();
	input.waitTime(300);

	select_pos.x = 1;
	select_pos.y = 1;
	spacing.x = 80;
    spacing.y = 68;
    highlight_pos.x = 135;
    highlight_pos.y = 88;
	graphLib.blank_screen();
	light_mode = &s_light;

	graphLib.copyArea(st_position(0, 0), &background, &graphLib.gameScreen);

	if (game_save.stages[APEBOT] == 0) {
        place_face(game_data.stage_face_filename[APEBOT], "APE", st_position(0, 0));
	} else {
		place_face(std::string(""), "APE", st_position(0, 0));
	}

	if (game_save.stages[DAISIEBOT] == 0) {
        place_face(game_data.stage_face_filename[DAISIEBOT], "DAISIE", st_position(1, 0));
	} else {
		place_face(std::string(""), "DAISIE", st_position(1, 0));
	}

	if (game_save.stages[SEAHORSEBOT] == 0) {
        place_face(game_data.stage_face_filename[SEAHORSEBOT], "SEAHORSE", st_position(2, 0));
	} else {
		place_face(std::string(""), "SEAHORSE", st_position(2, 0));
	}

	if (game_save.stages[MUMMYBOT] == 0) {
        place_face(game_data.stage_face_filename[MUMMYBOT], "MUMMY", st_position(0, 1));
	} else {
		place_face(std::string(""), "MUMMY", st_position(0, 1));
	}

	if (game_save.stages[MAGEBOT] == 0) {
        place_face(game_data.stage_face_filename[MAGEBOT], "MAGE", st_position(2, 1));
	} else {
		place_face(std::string(""), "MAGE", st_position(2, 1));
	}

	if (game_save.stages[DYNAMITEBOT] == 0) {
        place_face(game_data.stage_face_filename[DYNAMITEBOT], "DYNAMITE", st_position(0, 2));
	} else {
		place_face(std::string(""), "DYNAMITE", st_position(0, 2));
	}

	if (game_save.stages[SPIKEBOT] == 0) {
        place_face(game_data.stage_face_filename[SPIKEBOT], "SPIKE", st_position(1, 2));
	} else {
		place_face(std::string(""), "SPIKE", st_position(1, 2));
	}

	if (game_save.stages[TECHNOBOT] == 0) {
        place_face(game_data.stage_face_filename[TECHNOBOT], "TECHNO", st_position(2, 2));
	} else {
		place_face(std::string(""), "TECHNO", st_position(2, 2));
	}

    if (finished_stages() < 9) {
        if (game_save.selected_player == 1) {
			place_face("rockbot_no_eyes.png", "", st_position(1, 1));
		} else {
			place_face("betabot_no_eyes.png", "", st_position(1, 1));
		}
	} else {
		place_face("dr_destrin.png", "Dr. D.", st_position(1, 1));
	}

	light_mode = &s_light;

	graphLib.copyArea(st_position(highlight_pos.x, highlight_pos.y), &s_light, &graphLib.gameScreen);
    draw_lib.update_screen();
    std::string press_start_string = "STAGE SELECT - PRESS START";
    graphLib.draw_text(RES_W*0.5-(FONT_SIZE*press_start_string.length())/2, 227, press_start_string);

	input.clean();
    if (finished_stages() < 9) {
		draw_eyes(select_pos.x, select_pos.y, false);
	}
	input.waitTime(200);

	while (selection_end == 0) {
		input.readInput();

		if (input.p1_input[BTN_QUIT] || input.p2_input[BTN_QUIT]) {
#if !defined(PLAYSTATION2) && !defined(PSP) && !defined(WII) && !defined(DREAMCAST)
            std::cout << "LEAVE #7" << std::endl;
            std::fflush(stdout);
            gameControl.leave_game();
#endif
		}

		if (select_pos.y < 2 && (input.p1_input[BTN_DOWN] || input.p2_input[BTN_DOWN])) {
            if (finished_stages() < 9) {
                draw_eyes(select_pos.x, select_pos.y, true);
            }
            select_pos.y++;
            if (finished_stages() < 9) {
                draw_eyes(select_pos.x, select_pos.y, false);
            }
            soundManager.play_sfx(SFX_CURSOR);
            move_highlight(0, spacing.y);
            input.waitTime(200);
            input.clean();
		} else if (select_pos.y > 0 && (input.p1_input[BTN_UP] || input.p2_input[BTN_UP])) {
            if (finished_stages() < 9) {
                draw_eyes(select_pos.x, select_pos.y, true);
            }
            select_pos.y--;
            if (finished_stages() < 9) {
                draw_eyes(select_pos.x, select_pos.y, false);
            }
            soundManager.play_sfx(SFX_CURSOR);
            move_highlight(0, -spacing.y);
            input.waitTime(200);
            input.clean();
		} else if (select_pos.x > 0 && (input.p1_input[BTN_LEFT] || input.p2_input[BTN_LEFT])) {
            if (finished_stages() < 9) {
                draw_eyes(select_pos.x, select_pos.y, true);
            }
            select_pos.x--;
            if (finished_stages() < 9) {
                draw_eyes(select_pos.x, select_pos.y, false);
            }
            soundManager.play_sfx(SFX_CURSOR);
            move_highlight(-spacing.x, 0);
            input.waitTime(200);
            input.clean();
		} else if (select_pos.x < 2 && (input.p1_input[BTN_RIGHT] || input.p2_input[BTN_RIGHT])) {
            if (finished_stages() < 9) {
                draw_eyes(select_pos.x, select_pos.y, true);
            }
            select_pos.x++;
            if (finished_stages() < 9) {
                draw_eyes(select_pos.x, select_pos.y, false);
            }
            soundManager.play_sfx(SFX_CURSOR);
            move_highlight(spacing.x, 0);
            input.waitTime(200);
            input.clean();
        } else if ((input.p1_input[BTN_START] || input.p2_input[BTN_START]) && finished_stages() < 9 && (select_pos.x != 1 || select_pos.y != 1)) {
			selection_end = 1;
        } else if ((input.p1_input[BTN_START] || input.p2_input[BTN_START]) && finished_stages() >= 9) {
			selection_end = 1;
		}
		animate_highlight();
		input.waitTime(10);
	}

    //std::cout << "stage_select::select - c.x: " << select_pos.x << ", c.y: " << select_pos.y << std::endl;

	graphLib.blink_screen(255, 255, 255);
	return select_pos;
}
