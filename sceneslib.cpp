#include <cstdlib>
#include "sceneslib.h"
#include "soundlib.h"

extern string FILEPATH;
extern soundLib soundManager;

#include "graphicslib.h"
extern graphicsLib graphLib;

#include "inputlib.h"
extern inputLib input;

#include "soundlib.h"
extern soundLib soundManager;

#include "graphic/draw.h"
extern draw draw_lib;


#include "stage_select.h"
#include "graphic/option_picker.h"
#include "file/file_io.h"

#include "options/key_map.h"

#include "graphic/animation.h"

#include "game.h"
extern game gameControl;

extern CURRENT_FILE_FORMAT::st_game_config game_config;
extern CURRENT_FILE_FORMAT::st_save game_save;
extern CURRENT_FILE_FORMAT::file_stage stage_data;
extern CURRENT_FILE_FORMAT::file_game game_data;
extern CURRENT_FILE_FORMAT::file_io fio;

extern timerLib timer;

extern bool have_save;


#define TIME_SHORT 120
#define TIME_LONG 300
#define INTRO_DIALOG_DURATION_TIME 4000

// ********************************************************************************************** //
// ScenesLib handles all scinematic like intro and ending                                         //
// ********************************************************************************************** //
scenesLib::scenesLib() : _timer(0), _state(0)
{
    //preloadScenes();
	for (int i=0; i<PASSWORD_GRID_SIZE; i++) {
		for (int j=0; j<PASSWORD_GRID_SIZE; j++) {
			_password_selected_balls[i][j] = -1;
		}
	}
}

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void scenesLib::preloadScenes() const
{
	//graphLib.draw_text(RES_W*0.5-45-graphLib.RES_DIFF_W, RES_H*0.5-15,"LOADING...");
	preload_stage_select();
	soundManager.load_boss_music("boss_battle.mod");
}

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void scenesLib::preload_intro() { /// @TODO: check is memory is being freed, otherwise, use local variables and load on-the-fly

	std::string filename;

	filename = FILEPATH + "data/images/presents.png";
    graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_PRESENTS]);

    filename = FILEPATH + "data/images/upperland.png";
    graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_UPPERLAND]);

    filename = FILEPATH + "data/images/scenes/city_bg.png";
	graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_CITY_BG]);

	filename = FILEPATH + "data/images/sprites/canotus.png";
	graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_KANOTUS]);

	filename = FILEPATH + "data/images/sprites/p1.png";
	graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_ROCKBOT]);

	filename = FILEPATH + "data/images/sprites/p2.png";
	graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_BETABOT]);

	filename = FILEPATH + "data/images/scenes/lab_intro1.png";
	graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_LAB_BG]);

	filename = FILEPATH + "data/images/logo.png";
	graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_INTRO_SCREEN]);

	filename = FILEPATH + "data/images/backgrounds/player_select.png";
	graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_PLAYER_SELECT_BG]);

	filename = FILEPATH + "data/images/backgrounds/lights.png";
	graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_PLAYER_SELECT_LIGHTS]);

	filename = FILEPATH + "data/images/backgrounds/capsules.png";
	graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_CAPSULES]);

	filename = FILEPATH + "data/images/scenes/rockbot.png";
	graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_ROCKBOT_BIG]);

	filename = FILEPATH + "data/images/scenes/rockbot_half_sleep.png";
	graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_ROCKBOT_BIG_HALF_SLEEP]);

	filename = FILEPATH + "data/images/scenes/rockbot_full_sleep.png";
	graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_ROCKBOT_BIG_FULL_SLEEP]);

	filename = FILEPATH + "data/images/scenes/betabot.png";
	graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_BETABOT_BIG]);

	filename = FILEPATH + "data/images/scenes/kanotus.png";
	graphLib.surfaceFromFile(filename, &INTRO_SURFACES[INTRO_SURFACES_KANOTUS_BIG]);

	soundManager.load_music("opening.mod");

}

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void scenesLib::preload_stage_select() const {
	//backgrounds/stage_select.png
	//backgrounds/stage_select_darkned.png
	//backgrounds/stage_select_highlighted.png
	//backgrounds/stage_select_highlighted_yellow.png
	//backgrounds/stage_select_item.png
	//backgrounds/stage_boss_intro.png
}









// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void scenesLib::unload_intro() {
	int i;

	for (i=0; i<INTRO_SURFACES_COUNT; i++) {
		INTRO_SURFACES[i].freeGraphic();
	}
}

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void scenesLib::unload_stage_select() {
	int i;

	for (i=0; i<STAGE_SELECT_COUNT; i++) {
		if (STAGE_SELECT_SURFACES[i].gSurface) {
			SDL_FreeSurface(STAGE_SELECT_SURFACES[i].gSurface);
		}
	}
}


// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void scenesLib::intro()
{
    // @todo - BETTER WAY TO HANDLE START/ESC CUTTING SCENE
    int cut=0;

	preload_intro();
    intro_presents();

	// do not cut here because we need to load the music
	graphLib.draw_progressive_text(RES_W*0.5-45-graphLib.RES_DIFF_W, RES_H*0.5-15, "20XX AD.", false);
	input.waitScapeTime(2000);
	soundManager.play_music();

    graphLib.set_colormap_original(&INTRO_SURFACES[INTRO_SURFACES_CITY_BG]);

    graphLib.blank_screen();

    graphLib.set_colormap(-2);

    draw_lib.update_screen();

    graphLib.set_colormap_current(&INTRO_SURFACES[INTRO_SURFACES_CITY_BG]);
    graphLib.copyArea(st_rectangle(0,  INTRO_SURFACES[INTRO_SURFACES_CITY_BG].gSurface->h-100, INTRO_SURFACES[INTRO_SURFACES_CITY_BG].gSurface->w, 100), st_position(10, 20), &INTRO_SURFACES[INTRO_SURFACES_CITY_BG], &graphLib.gameScreen);

    draw_lib.update_screen();


	int line_position_y[] = {140, 155, 170, 185, 200};

    cut = graphLib.draw_progressive_text(10, line_position_y[0],"IN THE YEAR 20XX...", true);
    if (cut) { return; } cut = input.waitScapeTime(100); if (cut) { return; }

    cut = graphLib.draw_progressive_text(10, line_position_y[1],"STORM RAGES IN TOKYO, WITH EVIL", true);
    if (cut) { return; } cut = input.waitScapeTime(100); if (cut) { return; }

    cut = graphLib.draw_progressive_text(10, line_position_y[2],"FORCES CAUSING ROBOTS GO BERSEK.", true);
    if (cut) { return; } cut = input.waitScapeTime(2000); if (cut) { return; }

    cut = input.waitScapeTime(INTRO_DIALOG_DURATION_TIME);
    graphLib.blank_area(0, 120, RES_W, 100);


    cut = graphLib.draw_progressive_text(10, line_position_y[0],"IN KYOTO PEACE LASTS,", true);
    if (cut) { return; } cut = input.waitScapeTime(100); if (cut) { return; }

    cut = graphLib.draw_progressive_text(10, line_position_y[1],"BUT FEAR RAISES WITH", true);
    if (cut) { return; } cut = input.waitScapeTime(100); if (cut) { return; }

    cut = graphLib.draw_progressive_text(10, line_position_y[2],"RUMORS OF A REBELION.", true);
    if (cut) { return; } cut = input.waitScapeTime(100); if (cut) { return; }

    cut = graphLib.draw_progressive_text(10, line_position_y[4],"FINALLY, ONE NIGHT...", true);
    if (cut) { return; } cut = input.waitScapeTime(100); if (cut) { return; }


    int posy = INTRO_SURFACES[INTRO_SURFACES_CITY_BG].gSurface->h-100;
    for (int i=0; i<50; i++) {
        graphLib.set_colormap_current(&INTRO_SURFACES[INTRO_SURFACES_CITY_BG]);
        graphLib.copyArea(st_rectangle(0,  posy, INTRO_SURFACES[INTRO_SURFACES_CITY_BG].gSurface->w, 100), st_position(10, 20), &INTRO_SURFACES[INTRO_SURFACES_CITY_BG], &graphLib.gameScreen);
        draw_lib.update_screen();
        cut = input.waitScapeTime(10);
        posy -= 1;
        if (cut) { return; }
    }

    graphLib.copyArea(st_rectangle(0,  posy, INTRO_SURFACES[INTRO_SURFACES_CITY_BG].gSurface->w, 100), st_position(10, 20), &INTRO_SURFACES[INTRO_SURFACES_CITY_BG], &graphLib.gameScreen);
    draw_lib.update_screen();


    graphLib.blank_area(0, 120, RES_W, 100);

    cut = graphLib.draw_progressive_text(10, line_position_y[0],"BATTLE REACHES THE CITY!", true);
	if (cut) { return; }
	cut = input.waitScapeTime(100);
	if (cut) { return; }

    cut = graphLib.draw_progressive_text(10, line_position_y[1],"A HORDE OF EVIL ROBOTS WAGE", true);
	if (cut) { return; }
	cut = input.waitScapeTime(100);
	if (cut) { return; }

    cut = graphLib.draw_progressive_text(10, line_position_y[2],"WAR AND BRING CHAOS!!", true);
	if (cut) { return; }

    soundManager.play_repeated_sfx(SFX_BIG_EXPLOSION, 2);
    simple_animation explosion_anim1(FILEPATH+"data/images/animations/city_explosion_left.png", 5, 40, 51, st_position(90, 60));
    for (int i=0; i<40; i++) {
        graphLib.copyArea(st_rectangle(0,  posy, INTRO_SURFACES[INTRO_SURFACES_CITY_BG].gSurface->w, 100), st_position(10, 20), &INTRO_SURFACES[INTRO_SURFACES_CITY_BG], &graphLib.gameScreen);
        explosion_anim1.execute();
        draw_lib.update_screen();
        cut = input.waitScapeTime(10);
    }
    soundManager.play_repeated_sfx(SFX_BIG_EXPLOSION, 2);
    explosion_anim1.set_position(st_position(37, 45));
    simple_animation explosion_anim2(FILEPATH+"data/images/animations/city_explosion_right.png", 5, 40, 51, st_position(177, 69));
    for (int i=0; i<40; i++) {
        graphLib.copyArea(st_rectangle(0,  posy, INTRO_SURFACES[INTRO_SURFACES_CITY_BG].gSurface->w, 100), st_position(10, 20), &INTRO_SURFACES[INTRO_SURFACES_CITY_BG], &graphLib.gameScreen);
        explosion_anim1.execute();
        explosion_anim2.execute();
        draw_lib.update_screen();
        cut = input.waitScapeTime(10);
    }

    for (int i=0; i<50; i++) {
        graphLib.set_colormap_current(&INTRO_SURFACES[INTRO_SURFACES_CITY_BG]);
        graphLib.copyArea(st_rectangle(0,  posy, INTRO_SURFACES[INTRO_SURFACES_CITY_BG].gSurface->w, 100), st_position(10, 20), &INTRO_SURFACES[INTRO_SURFACES_CITY_BG], &graphLib.gameScreen);
        draw_lib.update_screen();
        cut = input.waitScapeTime(10);
        posy -= 1;
        if (cut) { return; }
    }


	graphLib.blank_area(0, 120, RES_W, 100);

    cut = graphLib.draw_progressive_text(10, line_position_y[0],"POLICE IS UNABLE TO RESIST,", true);
	if (cut) { return; }
	cut = input.waitScapeTime(100);
	if (cut) { return; }

    cut = graphLib.draw_progressive_text(10, line_position_y[1],"AND WHEN ARMY IS NEAR DEFEAT,", true);
	if (cut) { return; }
	cut = input.waitScapeTime(100);
	if (cut) { return; }

    cut = graphLib.draw_progressive_text(10, line_position_y[2],"A TASKFORCE OF SCIENTISTS", true);
	if (cut) { return; }
    cut = input.waitScapeTime(100);
	if (cut) { return; }

    cut = graphLib.draw_progressive_text(10, line_position_y[3],"IS FORMED TO HELP OUT!", true);
    if (cut) { return; }
    cut = input.waitScapeTime(INTRO_DIALOG_DURATION_TIME);
    if (cut) { return; }


    graphLib.blank_area(0, 120, RES_W, 100);

	graphLib.blank_screen();

    graphLib.set_colormap(-1);
    draw_lib.update_screen();

    graphLib.copyArea(st_rectangle(0, 10, INTRO_SURFACES[INTRO_SURFACES_CAPSULES].width, 90), st_position(60, 20), &INTRO_SURFACES[INTRO_SURFACES_CAPSULES], &graphLib.gameScreen);
    draw_lib.update_screen();
    graphLib.draw_progressive_text(10, line_position_y[0],"INSPIRATED BY THE METAL HEROES", true);
    graphLib.draw_progressive_text(10, line_position_y[1],"FROM TOKYO, A YOUNG PROFESSOR", true);
    graphLib.draw_progressive_text(10, line_position_y[2],"DECIDES TO CREATE NEW POLICEMEN", true);
    graphLib.draw_progressive_text(10, line_position_y[3],"MADE OF ELECTRONICS AND STEEL.", true);
    //graphLib.draw_progressive_text(10, line_position_y[4],"", true);

    cut = input.waitScapeTime(INTRO_DIALOG_DURATION_TIME);
	if (cut) { return; }

    graphLib.set_colormap(-3);
    graphLib.blank_screen();
    graphLib.set_colormap_current(&INTRO_SURFACES[INTRO_SURFACES_LAB_BG]);
	graphLib.copyArea(st_rectangle(0, 0, INTRO_SURFACES[INTRO_SURFACES_LAB_BG].gSurface->w, INTRO_SURFACES[INTRO_SURFACES_LAB_BG].gSurface->h), st_position(10-graphLib.RES_DIFF_W, 10-graphLib.RES_DIFF_H+13), &INTRO_SURFACES[INTRO_SURFACES_LAB_BG], &graphLib.gameScreen);

	graphLib.copyArea(st_rectangle(0, 0, 21, 24), st_position(226-graphLib.RES_DIFF_W, 95), &INTRO_SURFACES[INTRO_SURFACES_KANOTUS], &graphLib.gameScreen);

    draw_lib.update_screen();


    cut = graphLib.draw_progressive_text(10, line_position_y[0],"HIS FIRST CREATION IS CALLED", true);
	if (cut) { return; }
	cut = input.waitScapeTime(100);
	if (cut) { return; }

    cut = graphLib.draw_progressive_text(10, line_position_y[1],"BETABUT, BUT IS UNSTABLE.", true);
	if (cut) { return; }
	cut = input.waitScapeTime(100);
	if (cut) { return; }

    cut = graphLib.draw_progressive_text(10, line_position_y[2],"IMPROVING THE PROJECT, HE BUILDS", true);
	if (cut) { return; }
	cut = input.waitScapeTime(500);
	if (cut) { return; }

	graphLib.copyArea(st_rectangle(43, 0, 21, INTRO_SURFACES[INTRO_SURFACES_KANOTUS].gSurface->h), st_position(226-graphLib.RES_DIFF_W, 95), &INTRO_SURFACES[INTRO_SURFACES_KANOTUS], &graphLib.gameScreen);

    cut = graphLib.draw_progressive_text(10, line_position_y[3],"A SECOND ONE, CALLED ROCKBOT.", true);
	if (cut) { return; }
	cut = input.waitScapeTime(100);
	if (cut) { return; }

    cut = graphLib.draw_progressive_text(10, line_position_y[4],"NOW BOTH WILL FIGHT TOGETHER.", true);
	if (cut) { return; }
    cut = input.waitScapeTime(INTRO_DIALOG_DURATION_TIME);
	if (cut) { return; }

	graphLib.blank_area(0, 120, RES_W, 120);

	graphLib.clear_area(10, 20, 300, 103, 27, 63, 95);
	graphLib.copyArea(st_position(220, 57), &INTRO_SURFACES[INTRO_SURFACES_KANOTUS_BIG], &graphLib.gameScreen);
	graphLib.copyArea(st_position(30, 60), &INTRO_SURFACES[INTRO_SURFACES_BETABOT_BIG], &graphLib.gameScreen);
	graphLib.copyArea(st_position(80, 60), &INTRO_SURFACES[INTRO_SURFACES_ROCKBOT_BIG_FULL_SLEEP], &graphLib.gameScreen);
    draw_lib.update_screen();


	//graphLib.copyArea(st_rectangle(88, 9, 19, 24), st_position(158-graphLib.RES_DIFF_W, 83), &INTRO_SURFACES[INTRO_SURFACES_BETABOT], &graphLib.gameScreen);

    cut = graphLib.draw_progressive_text(10, line_position_y[0],"KYOTO'S SINGLE HOPE AGAINST", true);
	if (cut) { return; }
	cut = input.waitScapeTime(100);
	if (cut) { return; }

    cut = graphLib.draw_progressive_text(10, line_position_y[1],"THE ENEMY ARMY RESIDES ON THE", true);
	if (cut) { return; }
	cut = input.waitScapeTime(100);
	if (cut) { return; }

    cut = graphLib.draw_progressive_text(10, line_position_y[2],"HANDS OF TWO UNEXPERIENCED", true);
	if (cut) { return; }
	cut = input.waitScapeTime(100);
	if (cut) { return; }


    cut = graphLib.draw_progressive_text(10, line_position_y[3],"AND UNTESTED ROBOTS...", true);
    if (cut) { return; }
    cut = input.waitScapeTime(100);
    if (cut) { return; }



	graphLib.copyArea(st_position(80, 60), &INTRO_SURFACES[INTRO_SURFACES_ROCKBOT_BIG_HALF_SLEEP], &graphLib.gameScreen);
    draw_lib.update_screen();
	input.waitScapeTime(TIME_SHORT);
	graphLib.copyArea(st_position(80, 60), &INTRO_SURFACES[INTRO_SURFACES_ROCKBOT_BIG_FULL_SLEEP], &graphLib.gameScreen);
    draw_lib.update_screen();
	input.waitScapeTime(TIME_LONG);

	graphLib.copyArea(st_position(80, 60), &INTRO_SURFACES[INTRO_SURFACES_ROCKBOT_BIG_HALF_SLEEP], &graphLib.gameScreen);
    draw_lib.update_screen();
	input.waitScapeTime(TIME_LONG);
	graphLib.copyArea(st_position(80, 60), &INTRO_SURFACES[INTRO_SURFACES_ROCKBOT_BIG_FULL_SLEEP], &graphLib.gameScreen);
    draw_lib.update_screen();
	input.waitScapeTime(TIME_SHORT);

	graphLib.copyArea(st_position(80, 60), &INTRO_SURFACES[INTRO_SURFACES_ROCKBOT_BIG_HALF_SLEEP], &graphLib.gameScreen);
    draw_lib.update_screen();
	input.waitScapeTime(TIME_LONG);
	graphLib.copyArea(st_position(80, 60), &INTRO_SURFACES[INTRO_SURFACES_ROCKBOT_BIG], &graphLib.gameScreen);
    draw_lib.update_screen();
	input.waitScapeTime(2000);


    cut = graphLib.draw_progressive_text(10, line_position_y[4],"BETABOT AND ROCKBOT!!!", true);
	if (cut) { return; }
    cut = input.waitScapeTime(INTRO_DIALOG_DURATION_TIME);
	if (cut) { return; }
}




// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void scenesLib::intro_presents() {

    graphLib.blank_screen();
    draw_lib.update_screen();

    st_position logo_pos(RES_W/2 - (INTRO_SURFACES[INTRO_SURFACES_UPPERLAND].width/6)/2, RES_H/2 - INTRO_SURFACES[INTRO_SURFACES_UPPERLAND].height/2);
    graphLib.copyArea(st_rectangle(0, 0, INTRO_SURFACES[INTRO_SURFACES_PRESENTS].width, INTRO_SURFACES[INTRO_SURFACES_PRESENTS].height), st_position(RES_W*0.5-INTRO_SURFACES[INTRO_SURFACES_PRESENTS].width*0.5, logo_pos.y + INTRO_SURFACES[INTRO_SURFACES_UPPERLAND].height + 7), &INTRO_SURFACES[INTRO_SURFACES_PRESENTS], &graphLib.gameScreen);
    draw_lib.update_screen();


    //std::cout << ">> logo_pos.x: " << logo_pos.x << ", logo_pos.y: " << logo_pos.y << std::endl;
    graphLib.copyArea(st_rectangle(0, 0, INTRO_SURFACES[INTRO_SURFACES_UPPERLAND].width/6, INTRO_SURFACES[INTRO_SURFACES_UPPERLAND].height), logo_pos, &INTRO_SURFACES[INTRO_SURFACES_UPPERLAND], &graphLib.gameScreen);
    draw_lib.update_screen();
    input.waitScapeTime(400);
    for (int i=1; i<6; i++) {
        graphLib.copyArea(st_rectangle((INTRO_SURFACES[INTRO_SURFACES_UPPERLAND].width/6)*i, 0, INTRO_SURFACES[INTRO_SURFACES_UPPERLAND].width/6, INTRO_SURFACES[INTRO_SURFACES_UPPERLAND].height), logo_pos, &INTRO_SURFACES[INTRO_SURFACES_UPPERLAND], &graphLib.gameScreen);
        draw_lib.update_screen();
        input.waitScapeTime(30);
    }
    graphLib.copyArea(st_rectangle(0, 0, INTRO_SURFACES[INTRO_SURFACES_UPPERLAND].width/6, INTRO_SURFACES[INTRO_SURFACES_UPPERLAND].height), logo_pos, &INTRO_SURFACES[INTRO_SURFACES_UPPERLAND], &graphLib.gameScreen);
    draw_lib.update_screen();

    input.waitScapeTime(1000);

    graphLib.blank_screen();

    graphLib.draw_centered_text(30, "NOTICE", graphLib.gameScreen, st_color(199, 215, 255));
    int pos_x = 70;
    graphLib.draw_text(pos_x, 60, "THIS GAME WAS BEEN", graphLib.gameScreen);
    graphLib.draw_text(pos_x, 80, "DEVELOPED BY FANS ", graphLib.gameScreen);
    graphLib.draw_text(pos_x, 100, "OF THE MEGAMAN SERIES", graphLib.gameScreen);
    graphLib.draw_text(pos_x, 120, "AND IS NOT RELATED", graphLib.gameScreen);
    graphLib.draw_text(pos_x, 140, "THE OFFICIAL SERIES", graphLib.gameScreen);
    graphLib.draw_text(pos_x, 160, "ALL MEGAMAN RIGHTS", graphLib.gameScreen);
    graphLib.draw_text(pos_x, 180, "ARE PROPERTY OF CAPCOM.", graphLib.gameScreen);

    draw_lib.update_screen();
    input.waitScapeTime(3000);

    graphLib.blank_screen();
}


void scenesLib::draw_main()
{
	graphLib.blank_screen();
    draw_lib.update_screen();

	// PARTE 1 - TITLE SCREEN
	graphLib.copyArea(st_position(-graphLib.RES_DIFF_W, -graphLib.RES_DIFF_H+20), &INTRO_SURFACES[INTRO_SURFACES_INTRO_SCREEN], &graphLib.gameScreen);

    graphLib.draw_text(8, 70,"Kyoto Evolution!!");
    graphLib.draw_text(220, 12,"V1.0.1");

	options.push_back("NEW GAME");
	options.push_back("LOAD GAME");
	options.push_back("PASSWORD");
	options.push_back("OPTIONS");
    options.push_back("CREDITS");

    std::string text("\xA9 2009-2014 UPPERLAND STUDIOS");
	graphLib.draw_text(40-graphLib.RES_DIFF_W, (RES_H-35), text);
}

// ********************************************************************************************** //
// mostra tela de introdução, até alguém apertar start/enter
// a partir daí, mostra tela de seleção de personagem
// ********************************************************************************************** //
void scenesLib::main_screen()
{

	draw_main();
    option_picker main_picker(false, st_position(40-graphLib.RES_DIFF_W, (RES_H*0.5)-graphLib.RES_DIFF_H), options, false);


    int picked_n = 1;

    if (have_save) {
		main_picker.set_picker_initial_pos(1);
    } else {
        main_picker.set_picker_initial_pos(0);
    }
	bool repeat_menu = true;
	while (repeat_menu == true) {
		picked_n = main_picker.pick();
		if (picked_n == -1) {
#if !defined(PLAYSTATION2) && !defined(PSP) && !defined(WII) && !defined(DREAMCAST)
            std::cout << "LEAVE #5" << std::endl;
            std::fflush(stdout);
            gameControl.leave_game();
            return;
#endif
        } else if (picked_n == 0) { // NEW GAME
			repeat_menu = false;
        } else if (picked_n == 1) { // LOAD GAME
            if (have_save == true) {
				fio.read_save(game_save);
				repeat_menu = false;
			}
		} else if (picked_n == 2) {
            if (show_password_input() == true) {
				repeat_menu = false;
			} else {
				draw_main();
				main_picker.draw();
			}
		} else if (picked_n == 3) {
            show_main_config(0);
			draw_main();
			main_picker.draw();
        } else if (picked_n == 4) {
            draw_lib.show_credits();
            input.wait_keypress();
            draw_main();
            main_picker.draw();
        }
	}

    draw_lib.update_screen();


	// TODO - select_load_game();
    if (picked_n == 0) {
        game_save.selected_player = select_player();
    }
	// TODO - select_player();

}

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
short scenesLib::pick_stage() {
	graphLib.blank_screen();
	stage_select selection(STAGE_SELECT_SURFACES);

	selected_stage = selection.select();


	int pos_n = selected_stage.x + 1 + selected_stage.y*3;
    if (pos_n == 5) { // hack for skullcastle position
        pos_n = SKULLCASTLE1;
    } else if (pos_n >= 6) {
        pos_n--;
    }

    //std::cout << "scenesLib::pick_stage - pos_n: " << pos_n << ", c.x: " << selected_stage.x << ", c.y: " << selected_stage.y << std::endl;

    if (pos_n == SKULLCASTLE1) { // look for the actual stage in skullcastle
        for (int i=SKULLCASTLE1; i<SKULLCASTLE5; i++) {
            std::cout << "Check stage[" << i << "]: " << game_save.stages[i] << std::endl;
            if (game_save.stages[i] == 0) {
                break;
            }
            pos_n = i+1;
        }
    }
	input.waitTime(100);
    return pos_n;
}




short scenesLib::show_main_config(short stage_finished) // returns 1 if must leave stage, 0 if nothing
{
    short res = 0;
    st_position config_text_pos;
    std::vector<std::string> options;

	graphLib.show_config_bg(0);
    draw_lib.update_screen();
	input.clean();
	input.waitTime(300);
    int return_option = 2;

	options.push_back("AUDIO");
	options.push_back("INPUT");
#if defined(PC) || defined (PSP)
    options.push_back("VIDEO");
    return_option = 3;
#endif
    if (stage_finished) {
        options.push_back("LEAVE STAGE");
    }


	config_text_pos.x = graphLib.get_config_menu_pos().x + 74;
	config_text_pos.y = graphLib.get_config_menu_pos().y + 40;

	short selected_option = 0;
	while (selected_option != -1) {
        option_picker main_config_picker(false, config_text_pos, options, true);
		selected_option = main_config_picker.pick();
        std::cout << "#1.2 - KEY CONFIG - LEAVE 0" << std::endl;
		if (selected_option == -1) {
			break;
		}
		graphLib.clear_area(config_text_pos.x-1, config_text_pos.y-1, 180,  180, 0, 0, 0);
        draw_lib.update_screen();
		if (selected_option == 0) {
			show_config_audio();
		} else if (selected_option == 1) {
            std::cout << "#1.1 - KEY CONFIG" << std::endl;
            key_map key_mapper;
            key_mapper.config_input();
        } else if (selected_option == 2) {
            if (return_option == 3) {
#ifdef PC
                show_config_video();
#elif PSP
                show_config_video_PSP();
#endif
                graphLib.show_config_bg(0);
            } else {
                std::cout << "#1.2 - KEY CONFIG - LEAVE 1.2" << std::endl;
                res = 1;
                break;
            }
        } else if (selected_option == 3) {
            res = 1;
            std::cout << "#1.2 - KEY CONFIG - LEAVE 1.3" << std::endl;
            break;
        }
        std::cout << "#1.2 - KEY CONFIG - LEAVE 2 - selected_option: " << selected_option << std::endl;
        fio.save_config(game_config);

		graphLib.clear_area(config_text_pos.x-1, config_text_pos.y-1, 180,  180, 0, 0, 0);
        draw_lib.update_screen();
	}
    return res;
}






void scenesLib::show_config_video()
{
	st_position config_text_pos;
	config_text_pos.x = graphLib.get_config_menu_pos().x + 74;
	config_text_pos.y = graphLib.get_config_menu_pos().y + 40;
	input.clean();
	input.waitTime(300);

	std::vector<std::string> options;
	if (game_config.video_fullscreen == true) {
		options.push_back("WINDOWED");
	} else {
		options.push_back("FULLSCREEN");
	}

    if (game_config.video_filter == VIDEO_FILTER_NOSCALE) {
        options.push_back("NO SCALE  [X]");
        options.push_back("SIZE2X    [ ]");
        options.push_back("SCALE2X   [ ]");
    } else if (game_config.video_filter == VIDEO_FILTER_BITSCALE) {
        options.push_back("NO SCALE  [ ]");
        options.push_back("SIZE2X    [X]");
        options.push_back("SCALE2X   [ ]");
    } else if (game_config.video_filter == VIDEO_FILTER_SCALE2x) {
        options.push_back("NO SCALE  [ ]");
        options.push_back("SIZE2X    [ ]");
        options.push_back("SCALE2X   [X]");
    }

	short selected_option = 0;
    option_picker main_config_picker(false, config_text_pos, options, true);
	selected_option = main_config_picker.pick();
	if (selected_option == 0) {
        game_config.video_fullscreen = !game_config.video_fullscreen;
    } else if (selected_option == 1) {
        std::cout << "SET video_filter to VIDEO_FILTER_NOSCALE" << std::endl;
        game_config.video_filter = VIDEO_FILTER_NOSCALE;
	} else if (selected_option == 2) {
        std::cout << "SET video_filter to VIDEO_FILTER_BITSCALE" << std::endl;
        game_config.video_filter = VIDEO_FILTER_BITSCALE;
	} else if (selected_option == 3) {
        std::cout << "SET video_filter to VIDEO_FILTER_SCALE2x" << std::endl;
        game_config.video_filter = VIDEO_FILTER_SCALE2x;
    } else {
        std::cout << "SET video_filter - UNKNOWN mode!!" << std::endl;
    }
    if (selected_option != -1) {
        fio.save_config(game_config);
        input.clean();
        input.waitTime(300);
        st_position menu_pos(graphLib.get_config_menu_pos().x + 74, graphLib.get_config_menu_pos().y + 40);
        graphLib.clear_area(menu_pos.x, menu_pos.y, 180,  180, 0, 0, 0);
        graphLib.draw_text(menu_pos.x, menu_pos.y, "PLEASE RESTART THE GAME");
        graphLib.draw_text(menu_pos.x, menu_pos.y+10, "FOR THE CONFIGURATION");
        graphLib.draw_text(menu_pos.x, menu_pos.y+20, "TO TAKE EFFECT.");
        graphLib.draw_text(menu_pos.x, menu_pos.y+40, "PRESS A KEY TO RETURN");
        input.wait_keypress();
    }
}

void scenesLib::show_config_video_PSP()
{
    st_position config_text_pos;
    config_text_pos.x = graphLib.get_config_menu_pos().x + 74;
    config_text_pos.y = graphLib.get_config_menu_pos().y + 40;
    input.clean();
    input.waitTime(300);

    std::vector<std::string> options;
    if (game_config.video_fullscreen == true) {
        options.push_back("WINDOWED");
    } else {
        options.push_back("FULLSCREEN");
    }
    short selected_option = 0;
    option_picker main_config_picker(false, config_text_pos, options, true);
    selected_option = main_config_picker.pick();
    if (selected_option == 0) {
        game_config.video_fullscreen = !game_config.video_fullscreen;
    }
    if (selected_option != -1) {
        fio.save_config(game_config);
        input.clean();
        input.waitTime(300);
        st_position menu_pos(graphLib.get_config_menu_pos().x + 74, graphLib.get_config_menu_pos().y + 40);
        graphLib.clear_area(menu_pos.x, menu_pos.y, 180,  180, 0, 0, 0);
        graphLib.draw_text(menu_pos.x, menu_pos.y, "PLEASE RESTART THE GAME");
        graphLib.draw_text(menu_pos.x, menu_pos.y+10, "FOR THE CONFIGURATION");
        graphLib.draw_text(menu_pos.x, menu_pos.y+20, "TO TAKE EFFECT.");
        graphLib.draw_text(menu_pos.x, menu_pos.y+40, "PRESS A KEY TO RETURN");
        input.wait_keypress();
    }
}

void scenesLib::show_config_audio()
{
	st_position config_text_pos;
	config_text_pos.x = graphLib.get_config_menu_pos().x + 74;
	config_text_pos.y = graphLib.get_config_menu_pos().y + 40;
	input.clean();
	input.waitTime(300);

	std::vector<std::string> options;
	options.push_back("ENABLED");
	options.push_back("DISABLED");


	short selected_option = 0;
    option_picker main_config_picker(false, config_text_pos, options, true);
	selected_option = main_config_picker.pick();
	if (selected_option == 0) {
		soundManager.enable_sound();
	} else if (selected_option == 1) {
		soundManager.disable_sound();
	}
}

bool scenesLib::password_ball_selector()
{
	int selected_ball = 0; // blue, 1 is red
	st_position blue_ball_pos(236, 60);
	st_position red_ball_pos(252, 60);
	graphLib.copyArea(st_rectangle(0, 0, _password_selector.gSurface->w, _password_selector.gSurface->h/2), blue_ball_pos, &_password_selector, &graphLib.gameScreen);
    draw_lib.update_screen();

	input.clean();
	input.waitTime(200);
	//int display_timer = timer.getTimer() + 100;
	while (true) {
		input.clean();
		input.readInput();
		if (input.p1_input[BTN_LEFT] == 1 || input.p1_input[BTN_RIGHT] == 1) {
			soundManager.play_sfx(SFX_CURSOR);
			if (selected_ball == 0) {
				// erase mark on blue
				graphLib.copyArea(st_rectangle(0, _password_selector.gSurface->h/2, _password_selector.gSurface->w, _password_selector.gSurface->h), blue_ball_pos, &_password_selector, &graphLib.gameScreen);
				// draw mark on red
				graphLib.copyArea(st_rectangle(0, 0, _password_selector.gSurface->w, _password_selector.gSurface->h/2), red_ball_pos, &_password_selector, &graphLib.gameScreen);
				selected_ball = 1;
			} else {
				// erase mark on red
				graphLib.copyArea(st_rectangle(0, _password_selector.gSurface->h/2, _password_selector.gSurface->w, _password_selector.gSurface->h), red_ball_pos, &_password_selector, &graphLib.gameScreen);
				// draw mark on blue
				graphLib.copyArea(st_rectangle(0, 0, _password_selector.gSurface->w, _password_selector.gSurface->h/2), blue_ball_pos, &_password_selector, &graphLib.gameScreen);
				selected_ball = 0;
			}
		} else if (input.p1_input[BTN_JUMP] == 1) {
			graphLib.copyArea(st_rectangle(0, _password_selector.gSurface->h/2, _password_selector.gSurface->w, _password_selector.gSurface->h), red_ball_pos, &_password_selector, &graphLib.gameScreen);
			graphLib.copyArea(st_rectangle(0, _password_selector.gSurface->h/2, _password_selector.gSurface->w, _password_selector.gSurface->h), blue_ball_pos, &_password_selector, &graphLib.gameScreen);
			password_number_selector(selected_ball);
			if (selected_ball == 0) {
				graphLib.copyArea(st_rectangle(0, 0, _password_selector.gSurface->w, _password_selector.gSurface->h/2), blue_ball_pos, &_password_selector, &graphLib.gameScreen);
			} else {
				graphLib.copyArea(st_rectangle(0, 0, _password_selector.gSurface->w, _password_selector.gSurface->h/2), red_ball_pos, &_password_selector, &graphLib.gameScreen);
			}
		} else if (input.p1_input[BTN_ATTACK] == 1 || input.p1_input[BTN_START] == 1 || input.p1_input[BTN_DOWN]) {
			graphLib.copyArea(st_rectangle(0, _password_selector.gSurface->h/2, _password_selector.gSurface->w, _password_selector.gSurface->h), red_ball_pos, &_password_selector, &graphLib.gameScreen);
			graphLib.copyArea(st_rectangle(0, _password_selector.gSurface->h/2, _password_selector.gSurface->w, _password_selector.gSurface->h), blue_ball_pos, &_password_selector, &graphLib.gameScreen);
			return password_end_selector();
		}
        draw_lib.update_screen();
		timer.delay(20);
	}
}

bool scenesLib::password_set()
{
	// @TODO - save_game.reset
	/*
	for (int y=0; y<PASSWORD_GRID_SIZE; y++) {
		for (int x=0; x<PASSWORD_GRID_SIZE; x++) {
			std::cout << "[";
			if (_password_selected_balls[x][y] == -1) {
				std::cout << " ";
			} else if (_password_selected_balls[x][y] == 0) {
				std::cout << "B";
			} else if (_password_selected_balls[x][y] == 1) {
				std::cout << "R";
			}
			std::cout << "]";
		}
		std::cout << std::endl;
	}
	*/


	for (int y=0; y<PASSWORD_GRID_SIZE; y++) {
		for (int x=0; x<PASSWORD_GRID_SIZE; x++) {
			if (_password_selected_balls[x][y] != -1) {
				std::cout << "password at[" << x << "][" << y << "]: " << _password_selected_balls[x][y] << std::endl;
			}
            /*
            [3, 5]d6 blue -> techno - OK
            [5, 5]f6 blue -> daisie - OK
            [2, 3]c4 blue -> mummy - OK
            [5, 4]f5 blue -> spike - OK

                [0, 0]a1 -> castle #1
                [1, 1]b2 -> castle #2
                [4, 0]e1 -> castle #3
                [4, 2]e3 -> castle #4


            */
			if (_password_selected_balls[x][y] == 0) { // blue
				if (x == 3 && y == 5) {
					game_save.stages[TECHNOBOT] = 1;
				} else if (x == 5 && y == 5) {
					game_save.stages[DAISIEBOT] = 1;
				} else if (x == 2 && y == 3) {
					game_save.stages[MUMMYBOT] = 1;
				} else if (x == 5 && y == 4) {
					game_save.stages[SPIKEBOT] = 1;

                } else if (x == 0 && y == 0) {
                    game_save.stages[SKULLCASTLE1] = 1;
                } else if (x == 1 && y == 1) {
                    game_save.stages[SKULLCASTLE2] = 1;
                } else if (x == 4 && y == 0) {
                    game_save.stages[SKULLCASTLE3] = 1;
                } else if (x == 4 && y == 2) {
                    game_save.stages[SKULLCASTLE4] = 1;


				} else {
					std::cout << "password error at blue[" << x << "][" << y << "]" << std::endl;
					return false;
				}
			} else if (_password_selected_balls[x][y] == 1) { // red
				/*
				[2, 0]c1 red  -> initial-stage
				[0, 2]a3 red  -> magebot
				[1, 4]b5 red  -> dynamite
				[3, 2]d3 red  -> seahorse
				[5, 3]f4 red  -> apebot


				*/
				if (x == 2 && y == 0) {
					game_save.stages[INTRO_STAGE] = 1;
					std::cout << "scenesLib::password_set - game_save.stages[INTRO_STAGE]: " << game_save.stages[INTRO_STAGE] << std::endl;
				} else if (x == 0 && y == 2) {
					game_save.stages[MAGEBOT] = 1;
				} else if (x == 1 && y == 4) {
					game_save.stages[DYNAMITEBOT] = 1;
				} else if (x == 3 && y == 2) {
					game_save.stages[SEAHORSEBOT] = 1;
				} else if (x == 5 && y == 3) {
					game_save.stages[APEBOT] = 1;
				// energy tanks
				/*
				[4, 5]E6 = Start with 1
				[4, 3]E4 = Start with 2
				[1, 3]B4 = Start with 3
				[0, 4]A5 = Start with 4
				[2, 4]C5 = Start with 5
				[3, 1]D2 = Start with 6
				[2, 2]C3 = Start with 7
                [5, 1]F2 = Start with 8
				[0, 5]A6 = Start with 9
				*/
				} else if (x == 4 && y == 5) {
					game_save.items.energy_tanks = 1;
				} else if (x == 4 && y == 3) {
					game_save.items.energy_tanks = 2;
				} else if (x == 1 && y == 3) {
					game_save.items.energy_tanks = 3;
				} else if (x == 0 && y == 4) {
					game_save.items.energy_tanks = 4;
				} else if (x == 2 && y == 4) {
					game_save.items.energy_tanks = 5;
				} else if (x == 3 && y == 1) {
					game_save.items.energy_tanks = 6;
				} else if (x == 2 && y == 2) {
					game_save.items.energy_tanks = 7;
				} else if (x == 5 && y == 1) {
					game_save.items.energy_tanks = 8;
				} else if (x == 0 && y == 5) {
					game_save.items.energy_tanks = 9;
				// weapon tanks
				// special tanks
				} else {
					std::cout << "password error at red[" << x << "][" << y << "]" << std::endl;
					return false;
				}
			}
		}
	}

	/*

	// ENERGY TANKS






	*/

	return true;
}

bool scenesLib::password_end_selector()
{
	st_position end_pos1(235, 124);
	st_position end_pos2(258, 124);
	graphLib.copyArea(st_rectangle(0, 0, _password_selector.gSurface->w/2, _password_selector.gSurface->h/2), end_pos1, &_password_selector, &graphLib.gameScreen);
	graphLib.copyArea(st_rectangle( _password_selector.gSurface->w/2, 0, _password_selector.gSurface->w, _password_selector.gSurface->h/2), end_pos2, &_password_selector, &graphLib.gameScreen);
    draw_lib.update_screen();
	while (true) {
		input.clean();
		input.readInput();
		if (input.p1_input[BTN_UP] == 1) {
			graphLib.copyArea(st_rectangle(0, _password_selector.gSurface->h/2, _password_selector.gSurface->w/2, _password_selector.gSurface->h), end_pos1, &_password_selector, &graphLib.gameScreen);
			graphLib.copyArea(st_rectangle( _password_selector.gSurface->w/2, _password_selector.gSurface->h/2, _password_selector.gSurface->w, _password_selector.gSurface->h), end_pos2, &_password_selector, &graphLib.gameScreen);
			password_ball_selector();
		} else if (input.p1_input[BTN_ATTACK] == 1) {
			return false;
		} else if (input.p1_input[BTN_JUMP] == 1 || input.p1_input[BTN_START] == 1) {

			if (password_set() == false) { // show an error and keep trying

			} else {
				return true;
			}
		}
        draw_lib.update_screen();
		timer.delay(20);
	}
}




void scenesLib::password_number_selector(int ball_type)
{
	graphicsLib_gSurface ball_img;
	st_position selected_number(0, 0);
	st_rectangle point_zero(60, 52, 16, 16);

	graphLib.copyArea(st_rectangle(0, 0, _password_selector.gSurface->w, _password_selector.gSurface->h/2), st_position(point_zero.x, point_zero.y), &_password_selector, &graphLib.gameScreen);

	std::string filename;
	if (ball_type == 0) {
		filename = FILEPATH + "data/images/backgrounds/password_blue_ball.png";
	} else {
		filename = FILEPATH + "data/images/backgrounds/password_red_ball.png";
	}
	graphLib.surfaceFromFile(filename, &ball_img);

	input.clean();
	input.waitTime(200);

	while (true) {
		input.clean();
		input.readInput();
		if (input.p1_input[BTN_LEFT] == 1) {
			graphLib.copyArea(st_rectangle(0, _password_selector.gSurface->h/2, _password_selector.gSurface->w, _password_selector.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x, selected_number.y*point_zero.h + point_zero.y), &_password_selector, &graphLib.gameScreen);
			selected_number.x--;
			if (selected_number.x < 0) {
				selected_number.x = 5;
			}
			graphLib.copyArea(st_rectangle(0, 0, _password_selector.gSurface->w, _password_selector.gSurface->h/2), st_position(selected_number.x*point_zero.w + point_zero.x, selected_number.y*point_zero.h + point_zero.y), &_password_selector, &graphLib.gameScreen);
		} else if (input.p1_input[BTN_RIGHT] == 1) {
			graphLib.copyArea(st_rectangle(0, _password_selector.gSurface->h/2, _password_selector.gSurface->w, _password_selector.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x, selected_number.y*point_zero.h + point_zero.y), &_password_selector, &graphLib.gameScreen);
			selected_number.x++;
			if (selected_number.x > 5) {
				selected_number.x = 0;
			}
			graphLib.copyArea(st_rectangle(0, 0, _password_selector.gSurface->w, _password_selector.gSurface->h/2), st_position(selected_number.x*point_zero.w + point_zero.x, selected_number.y*point_zero.h + point_zero.y), &_password_selector, &graphLib.gameScreen);
		} else if (input.p1_input[BTN_UP] == 1) {
			graphLib.copyArea(st_rectangle(0, _password_selector.gSurface->h/2, _password_selector.gSurface->w, _password_selector.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x, selected_number.y*point_zero.h + point_zero.y), &_password_selector, &graphLib.gameScreen);
			selected_number.y--;
			if (selected_number.y < 0) {
				selected_number.y = 5;
			}
			graphLib.copyArea(st_rectangle(0, 0, _password_selector.gSurface->w, _password_selector.gSurface->h/2), st_position(selected_number.x*point_zero.w + point_zero.x, selected_number.y*point_zero.h + point_zero.y), &_password_selector, &graphLib.gameScreen);
		} else if (input.p1_input[BTN_DOWN] == 1) {
			graphLib.copyArea(st_rectangle(0, _password_selector.gSurface->h/2, _password_selector.gSurface->w, _password_selector.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x, selected_number.y*point_zero.h + point_zero.y), &_password_selector, &graphLib.gameScreen);
			selected_number.y++;
			if (selected_number.y > 5) {
				selected_number.y = 0;
			}
			graphLib.copyArea(st_rectangle(0, 0, _password_selector.gSurface->w, _password_selector.gSurface->h/2), st_position(selected_number.x*point_zero.w + point_zero.x, selected_number.y*point_zero.h + point_zero.y), &_password_selector, &graphLib.gameScreen);
		} else if (input.p1_input[BTN_JUMP] == 1) {
			if (_password_selected_balls[selected_number.y][selected_number.x] == -1) {
				graphLib.copyArea(st_rectangle(0, 0, ball_img.gSurface->w, ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &ball_img, &graphLib.gameScreen);
				_password_selected_balls[selected_number.y][selected_number.x] = ball_type;
				std::cout << "set password[" << selected_number.y << "][" << selected_number.x << "] to " << ball_type << std::endl;
			} else {
				graphLib.blank_area(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2, ball_img.gSurface->w, ball_img.gSurface->h, graphLib.gameScreen);
				_password_selected_balls[selected_number.y][selected_number.x] = -1;
			}
		} else if (input.p1_input[BTN_ATTACK] == 1) {
			graphLib.copyArea(st_rectangle(0, _password_selector.gSurface->h/2, _password_selector.gSurface->w, _password_selector.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x, selected_number.y*point_zero.h + point_zero.y), &_password_selector, &graphLib.gameScreen);
			break;
		}
        draw_lib.update_screen();
		timer.delay(20);
	}
}




bool scenesLib::show_password_input()
{
	graphicsLib_gSurface password_screen;
	std::string filename = FILEPATH + "data/images/backgrounds/password.png";
	graphLib.surfaceFromFile(filename, &password_screen);
	graphLib.copyArea(st_rectangle(0, 0, password_screen.gSurface->w, password_screen.gSurface->h), st_position(0, 0), &password_screen, &graphLib.gameScreen);

	filename = FILEPATH + "data/images/backgrounds/password_selector.png";
	graphLib.surfaceFromFile(filename, &_password_selector);

    draw_lib.update_screen();

    return password_end_selector();
}

void scenesLib::show_password()
{
    graphicsLib_gSurface password_screen;
    std::string filename = FILEPATH + "data/images/backgrounds/password.png";
    graphLib.surfaceFromFile(filename, &password_screen);
    graphLib.copyArea(st_rectangle(0, 0, password_screen.gSurface->w, password_screen.gSurface->h), st_position(0, 0), &password_screen, &graphLib.gameScreen);

    filename = FILEPATH + "data/images/backgrounds/password_selector.png";
    graphLib.surfaceFromFile(filename, &_password_selector);
    // add balls
    graphicsLib_gSurface red_ball_img, blue_ball_img;
    st_position selected_number(0, 0);
    st_rectangle point_zero(60, 52, 16, 16);
    filename = FILEPATH + "data/images/backgrounds/password_blue_ball.png";
    graphLib.surfaceFromFile(filename, &blue_ball_img);
    filename = FILEPATH + "data/images/backgrounds/password_red_ball.png";
    graphLib.surfaceFromFile(filename, &red_ball_img);

    if (game_save.stages[TECHNOBOT] == 1) {
        selected_number.x = 5;
        selected_number.y = 3;
        graphLib.copyArea(st_rectangle(0, 0, blue_ball_img.gSurface->w, blue_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &blue_ball_img, &graphLib.gameScreen);
    }
    if (game_save.stages[DAISIEBOT] == 1) {
        selected_number.x = 5;
        selected_number.y = 5;
        graphLib.copyArea(st_rectangle(0, 0, blue_ball_img.gSurface->w, blue_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &blue_ball_img, &graphLib.gameScreen);
    }
    if (game_save.stages[MUMMYBOT] == 1) {
        selected_number.x = 3;
        selected_number.y = 2;
        graphLib.copyArea(st_rectangle(0, 0, blue_ball_img.gSurface->w, blue_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &blue_ball_img, &graphLib.gameScreen);
    }
    if (game_save.stages[SPIKEBOT] == 1) {
        selected_number.x = 4;
        selected_number.y = 5;
        graphLib.copyArea(st_rectangle(0, 0, blue_ball_img.gSurface->w, blue_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &blue_ball_img, &graphLib.gameScreen);
    }


    if (game_save.stages[SKULLCASTLE1] == 1) {
        selected_number.x = 0;
        selected_number.y = 0;
        graphLib.copyArea(st_rectangle(0, 0, blue_ball_img.gSurface->w, blue_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &blue_ball_img, &graphLib.gameScreen);
    }
    if (game_save.stages[SKULLCASTLE2] == 1) {
        selected_number.x = 1;
        selected_number.y = 1;
        graphLib.copyArea(st_rectangle(0, 0, blue_ball_img.gSurface->w, blue_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &blue_ball_img, &graphLib.gameScreen);
    }
    if (game_save.stages[SKULLCASTLE3] == 1) {
        selected_number.x = 4;
        selected_number.y = 0;
        graphLib.copyArea(st_rectangle(0, 0, blue_ball_img.gSurface->w, blue_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &blue_ball_img, &graphLib.gameScreen);
    }
    if (game_save.stages[SKULLCASTLE4] == 1) {
        selected_number.x = 4;
        selected_number.y = 2;
        graphLib.copyArea(st_rectangle(0, 0, blue_ball_img.gSurface->w, blue_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &blue_ball_img, &graphLib.gameScreen);
    }

    if (game_save.stages[INTRO_STAGE] == 1) {
        selected_number.x = 0;
        selected_number.y = 2;
        graphLib.copyArea(st_rectangle(0, 0, red_ball_img.gSurface->w, red_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &red_ball_img, &graphLib.gameScreen);
    }
    if (game_save.stages[MAGEBOT] == 1) {
        selected_number.x = 2;
        selected_number.y = 0;
        graphLib.copyArea(st_rectangle(0, 0, red_ball_img.gSurface->w, red_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &red_ball_img, &graphLib.gameScreen);
    }
    if (game_save.stages[DYNAMITEBOT] == 1) {
        selected_number.x = 4;
        selected_number.y = 1;
        graphLib.copyArea(st_rectangle(0, 0, red_ball_img.gSurface->w, red_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &red_ball_img, &graphLib.gameScreen);
    }
    if (game_save.stages[SEAHORSEBOT] == 1) {
        selected_number.x = 2;
        selected_number.y = 3;
        graphLib.copyArea(st_rectangle(0, 0, red_ball_img.gSurface->w, red_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &red_ball_img, &graphLib.gameScreen);
    }
    if (game_save.stages[APEBOT] == 1) {
        selected_number.x = 3;
        selected_number.y = 5;
        graphLib.copyArea(st_rectangle(0, 0, red_ball_img.gSurface->w, red_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &red_ball_img, &graphLib.gameScreen);
    }

    if (game_save.items.energy_tanks == 1) {
        selected_number.x = 5;
        selected_number.y = 4;
        graphLib.copyArea(st_rectangle(0, 0, red_ball_img.gSurface->w, red_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &red_ball_img, &graphLib.gameScreen);
    } else if (game_save.items.energy_tanks == 2) {
        selected_number.x = 3;
        selected_number.y = 4;
        graphLib.copyArea(st_rectangle(0, 0, red_ball_img.gSurface->w, red_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &red_ball_img, &graphLib.gameScreen);
    } else if (game_save.items.energy_tanks == 3) {
        selected_number.x = 3;
        selected_number.y = 1;
        graphLib.copyArea(st_rectangle(0, 0, red_ball_img.gSurface->w, red_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &red_ball_img, &graphLib.gameScreen);
    } else if (game_save.items.energy_tanks == 4) {
        selected_number.x = 0;
        selected_number.y = 4;
        graphLib.copyArea(st_rectangle(0, 0, red_ball_img.gSurface->w, red_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &red_ball_img, &graphLib.gameScreen);
    } else if (game_save.items.energy_tanks == 5) {
        selected_number.x = 4;
        selected_number.y = 2;
        graphLib.copyArea(st_rectangle(0, 0, red_ball_img.gSurface->w, red_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &red_ball_img, &graphLib.gameScreen);
    } else if (game_save.items.energy_tanks == 6) {
        selected_number.x = 1;
        selected_number.y = 3;
        graphLib.copyArea(st_rectangle(0, 0, red_ball_img.gSurface->w, red_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &red_ball_img, &graphLib.gameScreen);
    } else if (game_save.items.energy_tanks == 7) {
        selected_number.x = 2;
        selected_number.y = 2;
        graphLib.copyArea(st_rectangle(0, 0, red_ball_img.gSurface->w, red_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &red_ball_img, &graphLib.gameScreen);
    } else if (game_save.items.energy_tanks == 8) {
        selected_number.x = 1;
        selected_number.y = 5;
        graphLib.copyArea(st_rectangle(0, 0, red_ball_img.gSurface->w, red_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &red_ball_img, &graphLib.gameScreen);
    } else if (game_save.items.energy_tanks == 9) {
        selected_number.x = 5;
        selected_number.y = 0;
        graphLib.copyArea(st_rectangle(0, 0, red_ball_img.gSurface->w, red_ball_img.gSurface->h), st_position(selected_number.x*point_zero.w + point_zero.x+2, selected_number.y*point_zero.h + point_zero.y+2), &red_ball_img, &graphLib.gameScreen);
    }


    graphLib.draw_text(112, 190, ">PRESS START", graphLib.gameScreen);

    /// @TODO

    draw_lib.update_screen();
    input.wait_keypress();
    password_screen.freeGraphic();

}

void scenesLib::draw_lights_select_player(graphicsLib_gSurface& lights, int selected, int adjustX, int adjustY) {
	int posX, invPosX;

	invPosX = 0;

	if (_timer < timer.getTimer()) {
		_timer = timer.getTimer()+200;
		if (_state == 0) {
			_state = 1;
		} else {
			_state = 0;
		}
	}
	if (_state != 0) {
		posX = 6;
	} else {
		posX = 0;
	}

	//printf(">>draw_lights_select_player - game_config.selected_player: %d, adjustX: %d, adjustY: %d\n", game_config.selected_player, adjustX, adjustY);

	if (selected == 2) {
		// light for p1
		graphLib.copyArea(st_rectangle(posX, 0, lights.height, lights.height), st_position(adjustX+2, adjustY+2), &lights, &graphLib.gameScreen);
		graphLib.copyArea(st_rectangle(posX, 0, lights.height, lights.height), st_position(adjustX+2, adjustY+88), &lights, &graphLib.gameScreen);
		graphLib.copyArea(st_rectangle(posX, 0, lights.height, lights.height), st_position(adjustX+248, adjustY+2), &lights, &graphLib.gameScreen);
		graphLib.copyArea(st_rectangle(posX, 0, lights.height, lights.height), st_position(adjustX+248, adjustY+88), &lights, &graphLib.gameScreen);
		// black for p2
        graphLib.copyArea(st_rectangle(invPosX, 0, lights.height, lights.height), st_position(adjustX+2, adjustY+114), &lights, &graphLib.gameScreen);
        graphLib.copyArea(st_rectangle(invPosX, 0, lights.height, lights.height), st_position(adjustX+2, adjustY+200), &lights, &graphLib.gameScreen);
        graphLib.copyArea(st_rectangle(invPosX, 0, lights.height, lights.height), st_position(adjustX+248, adjustY+114), &lights, &graphLib.gameScreen);
        graphLib.copyArea(st_rectangle(invPosX, 0, lights.height, lights.height), st_position(adjustX+248, adjustY+200), &lights, &graphLib.gameScreen);
	} else {
		// light for p2
        graphLib.copyArea(st_rectangle(posX, 0, lights.height, lights.height), st_position(adjustX+2, adjustY+114), &lights, &graphLib.gameScreen);
        graphLib.copyArea(st_rectangle(posX, 0, lights.height, lights.height), st_position(adjustX+2, adjustY+200), &lights, &graphLib.gameScreen);
        graphLib.copyArea(st_rectangle(posX, 0, lights.height, lights.height), st_position(adjustX+248, adjustY+114), &lights, &graphLib.gameScreen);
        graphLib.copyArea(st_rectangle(posX, 0, lights.height, lights.height), st_position(adjustX+248, adjustY+200), &lights, &graphLib.gameScreen);
		// black for p1
		graphLib.copyArea(st_rectangle(invPosX, 0, lights.height, lights.height), st_position(adjustX+2, adjustY+2), &lights, &graphLib.gameScreen);
		graphLib.copyArea(st_rectangle(invPosX, 0, lights.height, lights.height), st_position(adjustX+2, adjustY+88), &lights, &graphLib.gameScreen);
		graphLib.copyArea(st_rectangle(invPosX, 0, lights.height, lights.height), st_position(adjustX+248, adjustY+2), &lights, &graphLib.gameScreen);
		graphLib.copyArea(st_rectangle(invPosX, 0, lights.height, lights.height), st_position(adjustX+248, adjustY+88), &lights, &graphLib.gameScreen);
	}
    draw_lib.update_screen();
}





unsigned short int scenesLib::select_player() {
	int adjustX, adjustY;
	int selected = 2;

	graphLib.blank_screen();
    adjustX = (RES_W-256)*0.5;
    adjustY = (RES_H-208)*0.5;

    graphLib.copyArea(st_position(0, 0), &INTRO_SURFACES[INTRO_SURFACES_PLAYER_SELECT_BG], &graphLib.gameScreen);
    draw_lib.update_screen();

	input.clean();
	input.waitTime(200);
    while (true) {
		input.readInput();
        if (input.p1_input[BTN_DOWN] == 1 || input.p1_input[BTN_UP] == 1) {
            soundManager.play_sfx(SFX_CURSOR);
            if (selected == 2) {
                selected = 1;
            } else {
                selected = 2;
            }
        } else if (input.p1_input[BTN_QUIT] == 1 || input.p2_input[BTN_QUIT] == 1) {
#if !defined(PLAYSTATION2) && !defined(PSP) && !defined(WII) && !defined(DREAMCAST)
            graphLib.show_debug_msg("LEAVE #6");
            gameControl.leave_game();
#endif
        } else if (input.p1_input[BTN_START] == 1 || input.p2_input[BTN_START] == 1) {
            input.clean();
            draw_lib.update_screen();
            timer.delay(80);
            break;
        }
		draw_lights_select_player(INTRO_SURFACES[INTRO_SURFACES_PLAYER_SELECT_LIGHTS], selected, adjustX, adjustY);
        input.clean();
        draw_lib.update_screen();
        timer.delay(80);
	}
    //printf(">> select_player.END, n: %d\n", selected);
	return selected;
}


void scenesLib::boss_intro(int pos_n) const {
    graphicsLib_gSurface spriteCopy;
    unsigned int intro_frames_n = 1;
    int text_x = RES_W*0.5 - 60;
    unsigned int i;
    std::string filename;
    std::string botname;

    //std::cout << "#1 - scenesLib::boss_intro::pos_n: " << pos_n << std::endl;


    // set skullcastole number accoring to the save
    if (pos_n == SKULLCASTLE1) {
        if (game_save.stages[SKULLCASTLE5] != 0 || game_save.stages[SKULLCASTLE4] != 0) {
            pos_n = SKULLCASTLE5;
        } else if (game_save.stages[SKULLCASTLE3] != 0) {
            pos_n = SKULLCASTLE4;
        } else if (game_save.stages[SKULLCASTLE2] != 0) {
            pos_n = SKULLCASTLE3;
        } else if (game_save.stages[SKULLCASTLE1] != 0) {
            pos_n = SKULLCASTLE2;
        }
    }

    //pos_n = SKULLCASTLE5; ///@DEBUG


    if (pos_n == SKULLCASTLE1) {
        graphLib.blank_screen();
        show_destrin_ship_intro();
    }

    botname = game_data.game_npcs[stage_data.boss.id_npc].name;

    intro_frames_n = 0;
    for (int i=0; i<ANIM_FRAMES_COUNT; i++) {
        if (game_data.game_npcs[stage_data.boss.id_npc].sprites[ANIM_TYPE_INTRO][i].used == true) {
            intro_frames_n++;
        }
    }


    //std::cout << "#2 - scenesLib::boss_intro::pos_n: " << pos_n << std::endl;

    if (pos_n == SKULLCASTLE1 || pos_n >= SKULLCASTLE2) {
        filename = FILEPATH + "data/images/backgrounds/skull_castle.png";
        graphLib.surfaceFromFile(filename, &spriteCopy);
        graphLib.copyArea(st_position(0, 0), &spriteCopy, &graphLib.gameScreen);

        graphLib.wait_and_update_screen(500);
        graphLib.blink_surface_into_screen(spriteCopy);

        graphicsLib_gSurface castle_point;
        filename = FILEPATH + "data/images/backgrounds/castle_point.png";
        graphLib.surfaceFromFile(filename, &castle_point);
        graphLib.copyArea(st_position(74, 228), &castle_point, &graphLib.gameScreen);



        if (pos_n == SKULLCASTLE2) {
            graphLib.copyArea(st_position(109, 150), &castle_point, &graphLib.gameScreen);
        } else if (pos_n == SKULLCASTLE3) {
            draw_castle_path(true, st_position(76, 228), st_position(105, 152), 0);
            graphLib.copyArea(st_position(109, 150), &castle_point, &graphLib.gameScreen);
            graphLib.copyArea(st_position(177, 138), &castle_point, &graphLib.gameScreen);
        } else if (pos_n == SKULLCASTLE4) {
            draw_castle_path(true, st_position(76, 228), st_position(105, 152), 0);
            draw_castle_path(false, st_position(117, 152), st_position(179, 140), 0);
            graphLib.copyArea(st_position(109, 150), &castle_point, &graphLib.gameScreen);
            graphLib.copyArea(st_position(177, 138), &castle_point, &graphLib.gameScreen);
            graphLib.copyArea(st_position(195, 110), &castle_point, &graphLib.gameScreen);
        } else if (pos_n == SKULLCASTLE5) {
            draw_castle_path(true, st_position(76, 228), st_position(105, 152), 0);
            draw_castle_path(false, st_position(117, 152), st_position(179, 146), 0);
            draw_castle_path(true, st_position(179, 138), st_position(191, 112), 0);
            graphLib.copyArea(st_position(109, 150), &castle_point, &graphLib.gameScreen);
            graphLib.copyArea(st_position(177, 138), &castle_point, &graphLib.gameScreen);
            graphLib.copyArea(st_position(195, 110), &castle_point, &graphLib.gameScreen);
            graphicsLib_gSurface castle_skull_point;
            filename = FILEPATH + "data/images/backgrounds/castle_skull_point.png";
            graphLib.surfaceFromFile(filename, &castle_skull_point);
            graphLib.copyArea(st_position(167, 42), &castle_skull_point, &graphLib.gameScreen);
        }

        soundManager.play_sfx(SFX_SKULL_CASTLE_INTRO);
        draw_lib.update_screen();
        input.waitTime(7550);


        /// @TODO - instant path for drawing previous ones (do not need a for-loop)
        if (pos_n == SKULLCASTLE2) {
            draw_castle_path(true, st_position(76, 228), st_position(105, 152), 1000);
        } else if (pos_n == SKULLCASTLE3) {
            draw_castle_path(false, st_position(117, 152), st_position(179, 146), 1000);
        } else if (pos_n == SKULLCASTLE4) {
            draw_castle_path(true, st_position(179, 138), st_position(191, 112), 1000);
        } else if (pos_n == SKULLCASTLE5) {
            draw_castle_path(true, st_position(197, 110), st_position(186, 47), 1000);
        }
        input.waitTime(1500);
        return;
    } else if (game_save.stages[pos_n] != 0) {
        std::cout << "boss_intro - stage already finished" << std::endl;
        //return;
    }


    soundManager.play_sfx(SFX_STAGE_SELECTED);
    graphLib.blank_screen();


    graphLib.start_stars_animation();

    draw_lib.show_boss_intro_sprites(stage_data.boss.id_npc, true);

    for (i=0; i<botname.size(); i++) {
        graphLib.wait_and_update_screen(100);
        // convert name to uppercase
        std::string str = &botname.at(i);
        std::locale settings;
        std::string boss_name;
        for(short i = 0; i < str.size(); ++i) {
            boss_name += (std::toupper(str[i], settings));
        }

        graphLib.draw_text(text_x, 118, boss_name);
        text_x += 8;
    }
    graphLib.wait_and_update_screen(2500);
    graphLib.stop_stars_animation();

}


void scenesLib::draw_castle_path(bool vertical_first, st_position initial_point, st_position final_point, short total_duration) const
{
    if (total_duration > 0) {
        soundManager.play_sfx(SFX_CHARGING2);
    }
    st_position middle_point(final_point.x, initial_point.y);
    if (vertical_first == true) {
        middle_point.x = initial_point.x;
        middle_point.y = final_point.y;
    }
    graphLib.draw_path(initial_point, middle_point, total_duration/2);
    graphLib.draw_path(middle_point, final_point, total_duration/2);
}

void scenesLib::show_destrin_ship_intro() const
{
    graphicsLib_gSurface destrin_ship;
    st_size ship_size(56, 46);

    std::string filename = FILEPATH + "data/images/sprites/enemies/destrin_capsule_small.png";
    graphLib.surfaceFromFile(filename, &destrin_ship);
    graphLib.start_stars_animation();

    std::cout << "graphicsLib::show_destrin_ship_intro::START" << std::endl;


    int ship_pos_x = RES_W + ship_size.width-TILESIZE;
    int ship_pos_y = RES_H/2 - ship_size.height/2;
    // show ship coming from right
    int move_speed = 2;
    while (ship_pos_x > RES_W/2) {
        //std::cout << ">> #1 ship_pos_x: " << ship_pos_x << std::endl;
        ship_pos_x -= move_speed;
        graphLib.clear_area(ship_pos_x, ship_pos_y, ship_size.width+move_speed, ship_size.height, 0, 0, 0);
        graphLib.showSurfaceRegionAt(&destrin_ship, st_rectangle(0, 0, ship_size.width, ship_size.height), st_position(ship_pos_x, ship_pos_y));
        graphLib.wait_and_update_screen(20);
    }
    // show eyebrows animation
    graphLib.wait_and_update_screen(2000);

    for (int i=0; i<4; i++) {
        graphLib.clear_area(ship_pos_x, ship_pos_y, ship_size.width+move_speed, ship_size.height, 0, 0, 0);
        graphLib.showSurfaceRegionAt(&destrin_ship, st_rectangle(ship_size.width, 0, ship_size.width, ship_size.height), st_position(ship_pos_x, ship_pos_y));
        graphLib.wait_and_update_screen(200);
        graphLib.clear_area(ship_pos_x, ship_pos_y, ship_size.width+move_speed, ship_size.height, 0, 0, 0);
        graphLib.showSurfaceRegionAt(&destrin_ship, st_rectangle(ship_size.width*2, 0, ship_size.width, ship_size.height), st_position(ship_pos_x, ship_pos_y));
        graphLib.wait_and_update_screen(200);
    }
    graphLib.clear_area(ship_pos_x, ship_pos_y, ship_size.width+move_speed, ship_size.height, 0, 0, 0);
    graphLib.showSurfaceRegionAt(&destrin_ship, st_rectangle(0, 0, ship_size.width, ship_size.height), st_position(ship_pos_x, ship_pos_y));
    graphLib.wait_and_update_screen(1000);


    // show ship parting to left
    move_speed = 6;
    while (ship_pos_x > -(ship_size.width+TILESIZE)) {
        //std::cout << ">> #2 ship_pos_x: " << ship_pos_x << std::endl;
        graphLib.clear_area(ship_pos_x, ship_pos_y, ship_size.width+move_speed, ship_size.height, 0, 0, 0);
        graphLib.showSurfaceRegionAt(&destrin_ship, st_rectangle(0, 0, (ship_size.width), ship_size.height), st_position(ship_pos_x, ship_pos_y));
        draw_lib.update_screen();
        graphLib.wait_and_update_screen(20);
        ship_pos_x -= move_speed;
    }

    graphLib.stop_stars_animation();
}

