#define B sp[i - b]
#define D sp[i - (i>0?1:0)]
#define F sp[i + (i<wd?1:0)]
#define H sp[i + h]
#define E  sp[i]
#define E0 tp[i*2]
#define E1 tp[i*2 + 1]
#define E2 tp[i*2 + tpitch]
#define E3 tp[i*2 + 1 + tpitch]

#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;


#include "defines.h"

extern string FILEPATH;

#include "inputlib.h"
extern inputLib input;

#include "timerlib.h"
extern timerLib timer;

#include "soundlib.h"
extern soundLib soundManager;


#include "graphicslib.h"

#include "file/format.h"
extern CURRENT_FILE_FORMAT::st_save game_save;

extern CURRENT_FILE_FORMAT::file_game game_data;

extern CURRENT_FILE_FORMAT::st_game_config game_config;

extern graphicsLib_gSurface _explosion_surface;

#include "file/file_io.h"

#include "class_config.h"


graphicsLib::graphicsLib() : _show_stars(false), game_screen(NULL), _explosion_animation_timer(0), _explosion_animation_pos(0), _must_set_colors(true), _timer(0)
{

	tileset = NULL;
	stars_timer = 0;

    colormap[0].r = 97;
    colormap[0].g = 97;
    colormap[0].b = 97;
    colormap[1].r = 39;
    colormap[1].g = 27;
    colormap[1].b = 143;
    colormap[2].r = 0;
    colormap[2].g = 0;
    colormap[2].b = 171;
    colormap[3].r = 71;
    colormap[3].g = 0;
    colormap[3].b = 159;
    colormap[4].r = 143;
    colormap[4].g = 0;
    colormap[4].b = 119;
    colormap[5].r = 171;
    colormap[5].g = 0;
    colormap[5].b = 19;
    colormap[6].r = 167;
    colormap[6].g = 0;
    colormap[6].b = 0;
    colormap[7].r = 127;
    colormap[7].g = 11;
    colormap[7].b = 0;
    colormap[8].r = 67;
    colormap[8].g = 47;
    colormap[8].b = 0;
    colormap[9].r = 0;
    colormap[9].g = 71;
    colormap[9].b = 0;
    colormap[10].r = 0;
    colormap[10].g = 81;
    colormap[10].b = 0;
    colormap[11].r = 0;
    colormap[11].g = 63;
    colormap[11].b = 23;
    colormap[12].r = 27;
    colormap[12].g = 63;
    colormap[12].b = 95;
    colormap[13].r = 0;
    colormap[13].g = 0;
    colormap[13].b = 0;
    colormap[14].r = 196;
    colormap[14].g = 93;
    colormap[14].b = 0;
    colormap[15].r = 255;
    colormap[15].g = 153;
    colormap[15].b = 102;
    colormap[16].r = 188;
    colormap[16].g = 188;
    colormap[16].b = 188;
    colormap[17].r = 0;
    colormap[17].g = 115;
    colormap[17].b = 239;
    colormap[18].r = 35;
    colormap[18].g = 59;
    colormap[18].b = 239;
    colormap[19].r = 131;
    colormap[19].g = 0;
    colormap[19].b = 243;
    colormap[20].r = 191;
    colormap[20].g = 0;
    colormap[20].b = 191;
    colormap[21].r = 231;
    colormap[21].g = 0;
    colormap[21].b = 91;
    colormap[22].r = 219;
    colormap[22].g = 43;
    colormap[22].b = 0;
    colormap[23].r = 203;
    colormap[23].g = 79;
    colormap[23].b = 15;
    colormap[24].r = 139;
    colormap[24].g = 115;
    colormap[24].b = 0;
    colormap[25].r = 0;
    colormap[25].g = 151;
    colormap[25].b = 0;
    colormap[26].r = 0;
    colormap[26].g = 171;
    colormap[26].b = 0;
    colormap[27].r = 0;
    colormap[27].g = 147;
    colormap[27].b = 59;
    colormap[28].r = 0;
    colormap[28].g = 131;
    colormap[28].b = 139;
    colormap[29].r = 255;
    colormap[29].g = 102;
    colormap[29].b = 0;
    colormap[30].r = 255;
    colormap[30].g = 51;
    colormap[30].b = 0;
    colormap[31].r = 204;
    colormap[31].g = 204;
    colormap[31].b = 0;
    colormap[32].r = 235;
    colormap[32].g = 235;
    colormap[32].b = 235;
    colormap[33].r = 63;
    colormap[33].g = 191;
    colormap[33].b = 255;
    colormap[34].r = 95;
    colormap[34].g = 151;
    colormap[34].b = 255;
    colormap[35].r = 167;
    colormap[35].g = 139;
    colormap[35].b = 253;
    colormap[36].r = 247;
    colormap[36].g = 123;
    colormap[36].b = 255;
    colormap[37].r = 255;
    colormap[37].g = 119;
    colormap[37].b = 183;
    colormap[38].r = 255;
    colormap[38].g = 119;
    colormap[38].b = 99;
    colormap[39].r = 255;
    colormap[39].g = 155;
    colormap[39].b = 59;
    colormap[40].r = 243;
    colormap[40].g = 191;
    colormap[40].b = 63;
    colormap[41].r = 131;
    colormap[41].g = 211;
    colormap[41].b = 19;
    colormap[42].r = 79;
    colormap[42].g = 223;
    colormap[42].b = 75;
    colormap[43].r = 88;
    colormap[43].g = 248;
    colormap[43].b = 152;
    colormap[44].r = 0;
    colormap[44].g = 235;
    colormap[44].b = 219;
    colormap[45].r = 102;
    colormap[45].g = 51;
    colormap[45].b = 204;
    colormap[46].r = 51;
    colormap[46].g = 102;
    colormap[46].b = 255;
    colormap[47].r = 81;
    colormap[47].g = 81;
    colormap[47].b = 81;
    colormap[48].r = 230;
    colormap[48].g = 255;
    colormap[48].b = 0;
    colormap[49].r = 171;
    colormap[49].g = 231;
    colormap[49].b = 255;
    colormap[50].r = 199;
    colormap[50].g = 215;
    colormap[50].b = 255;
    colormap[51].r = 215;
    colormap[51].g = 203;
    colormap[51].b = 255;
    colormap[52].r = 255;
    colormap[52].g = 199;
    colormap[52].b = 255;
    colormap[52].r = 255;
	colormap[53].r = 255;
    colormap[53].g = 199;
    colormap[53].b = 219;
    colormap[54].r = 255;
    colormap[54].g = 191;
    colormap[54].b = 179;
    colormap[55].r = 255;
    colormap[55].g = 219;
    colormap[55].b = 171;
    colormap[56].r = 255;
    colormap[56].g = 231;
    colormap[56].b = 163;
    colormap[57].r = 227;
    colormap[57].g = 255;
    colormap[57].b = 163;
    colormap[58].r = 171;
    colormap[58].g = 243;
    colormap[58].b = 191;
    colormap[59].r = 179;
    colormap[59].g = 255;
    colormap[59].b = 207;
    colormap[60].r = 159;
    colormap[60].g = 255;
    colormap[60].b = 243;
    colormap[61].r = 112;
    colormap[61].g = 110;
    colormap[61].b = 110;
    colormap[62].r = 255;
    colormap[62].g = 192;
    colormap[62].b = 0;
    colormap[63].r = 255;
    colormap[63].g = 234;
    colormap[63].b = 0;
    colormap[64].r = 55;
    colormap[64].g = 255;
    colormap[64].b = 0;
    colormap[65].r = 255;
    colormap[65].g = 0;
    colormap[65].b = 255;
    colormap[66].r = 0;
    colormap[66].g = 255;
    colormap[66].b = 255;
    // colorkey (transparent)
    colormap[67].r = COLORKEY_R;
    colormap[67].g = COLORKEY_G;
    colormap[67].b = COLORKEY_B;

	for (int i=0; i<COLOR_COUNT; i++) {
		colormap_original[i] = colormap[i];
	}

	for (int i=0; i<COLOR_COUNT; i++) {
		//c =  ((r * 61) + (g * 174) + (b * 21)) / 256;
        //int color_med = (colormap[i].r + colormap[i].g + colormap[i].b)/3;
        colormap_white[i].r = 235;
        colormap_white[i].g = 235;
        colormap_white[i].b = 235;
	}


	RES_DIFF_W = 0;
	RES_DIFF_H = 0;
    _debug_msg_pos = 0;
}

graphicsLib::~graphicsLib()
{
}


bool graphicsLib::initGraphics()
{
	string filename;
    _video_filter = game_config.video_filter;

#ifdef DREAMCAST
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK|SDL_INIT_TIMER) < 0 ) {
        std::cout << "SDL Error" << std::endl;
        std::cout << "Unable to init SDL. Error: " << SDL_GetError() << std::endl;
        std::fflush(stdout);
		exit(-1);
    }
#else
	// GRAPHIC LIB
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK|SDL_INIT_TIMER|SDL_INIT_AUDIO) < 0 ) {
        std::cout << "SDL Error" << std::endl;
        std::cout << "Unable to init SDL. Error: " << SDL_GetError() << std::endl;
        std::fflush(stdout);
		exit(-1);
    }
#endif
	atexit(SDL_Quit);


    printf("INFO: There are %d joysticks attached\n", SDL_NumJoysticks());
#if defined(PLAYSTATION2) || defined(WII)
    if (SDL_NumJoysticks() <= 0) {
        std::cout << "No joysticks found" << std::endl;
        exit(-1);
    }
#endif
	input.init_joystick();
	// FONT
	TTF_Init();
	filename = FILEPATH + "data/fonts/pressstart2p.ttf";

	char *buffer = new char[filename.size()+1];
	std::strcpy(buffer, filename.c_str());
	SDL_RWops *fileRW;
	fileRW = SDL_RWFromFile(buffer, "rb");
	if (!fileRW) {
		printf("ERROR::initGraphics - could not open '%s' font\n", buffer);
        delete[] buffer;
		return false;
	} else {
        font = TTF_OpenFontRW(fileRW, 1, FONT_SIZE);
	}
    delete[] buffer;

	// GAME SCREEN
	SDL_ShowCursor( SDL_DISABLE );
#ifdef PC
    SDL_WM_SetCaption("Rockbot Game", "Rockbot Game");
#endif
    set_video_mode();
#ifdef PC
    std::string icon_filename = FILEPATH + "data/images/faces/rockbot.png";
    SDL_RWops *rwop = SDL_RWFromFile(icon_filename.c_str(), "rb");
    if (rwop) {
        SDL_Surface* icon_img = IMG_Load_RW(rwop, 1);
        if (icon_img != NULL) {
            SDL_WM_SetIcon(icon_img, NULL);
        }
    } else {
        std::cout << "rwop is NULL " << std::endl;
    }
#endif
	// other loading methods


    return true;
}

void graphicsLib::preload()
{
    load_icons();
    loadTileset();
    preload_faces();
    preload_images();
}


void graphicsLib::updateScreen()
{
    unsigned int now_timer = timer.getTimer() ;

    //std::cout << "graphicsLib::updateScreen - now_timer: " << now_timer << ", " << _timer << ", total(<20): " << now_timer - _timer << std::endl;

    /*
    if (now_timer - _timer < 20) {
        return;
    }
    _timer = timer.getTimer();
    */


	if (!game_screen) {
        std::cout << "FATAL-ERROR::updateScreen game_screen is NULL\n";
		return;
    }


    if (_show_stars == true) {
        anim_stars(); /// @TODO - move to draw class
    }


    colorcycle_manager.execute();

    // clear non-used areas
    if (game_screen->w > RES_W) {
        clear_area_no_adjust(0, 0, _screen_resolution_adjust.x, game_screen->h, 0, 0, 0);
        clear_area_no_adjust(_screen_resolution_adjust.x+RES_W, 0, _screen_resolution_adjust.x, game_screen->h, 0, 0, 0);
    }
    if (game_screen->h > RES_H) {
        clear_area_no_adjust(0, 0, game_screen->w, _screen_resolution_adjust.y, 0, 0, 0);
        clear_area_no_adjust(0, _screen_resolution_adjust.y + RES_H, game_screen->w, _screen_resolution_adjust.y, 0, 0, 0);
    }


    if (_video_filter == VIDEO_FILTER_NOSCALE) {
        //std::cout << "GRAPH::updateScreen NO SCALE" << std::endl;
        if (_must_set_colors == true) {
            //std::cout << "** graphicsLib::updateScreen - _must_set_colors(TRUE) **" << std::endl;
            update_surface_colormap(game_screen, colormap);
            update_surface_colormap(tileset, colormap);
            _must_set_colors = false;
        }
        SDL_Flip(game_screen);
    } else {
        //std::cout << "GRAPH::updateScreen SCALE" << std::endl;
        if (_video_filter == VIDEO_FILTER_BITSCALE) {
            scale2x(game_screen, game_screen_scaled, false);
        } else if (_video_filter == VIDEO_FILTER_SCALE2x) {
            scale2x(game_screen, game_screen_scaled, true);
        } else {
            copySDLArea(st_rectangle(0, 0, RES_W, RES_H), st_position(0, 0), game_screen, game_screen_scaled, true);
        }
        if (_must_set_colors == true) {
            update_surface_colormap(tileset, colormap);
            _must_set_colors = false;
        }
        SDL_Flip(game_screen_scaled);
    }
}



SDL_Surface *graphicsLib::SDLSurfaceFromFile(string filename)
{
	SDL_RWops *rwop;
	SDL_Surface *spriteCopy;
	SDL_Surface *display_surface;

    rwop=SDL_RWFromFile(filename.c_str(), "rb");

    if (!rwop) {
        std::cout << "DEBUG.loadSpriteFile - Error in graphicsLib::SDLSurfaceFromFile - file '" << filename << "' not found\n";
		return NULL;
	}
	spriteCopy = IMG_Load_RW(rwop, 1);
    if (spriteCopy == NULL) {
        std::cout << "[graphicsLib::SDLSurfaceFromFile] Error on IMG_Load_RW, could not load image '" << filename << "'" << std::endl;
        printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
    }

    display_surface = SDL_DisplayFormat(spriteCopy);
    if (display_surface == NULL) {
        printf("SDL_DisplayFormat: %s\n", IMG_GetError());
    }

    SDL_FreeSurface(spriteCopy);
    update_surface_colormap(display_surface, colormap_original);

    return display_surface;
}


void graphicsLib::surfaceFromFile(string filename, struct graphicsLib_gSurface* res)
{
    res->freeGraphic();
	res->gSurface = SDLSurfaceFromFile(filename);
	if (res->gSurface == NULL) {
        std::cout << "surfaceFromFile - error loading file: '" << filename << "'" << std::endl;
        _debug_msg_pos = 1;
        show_debug_msg(filename);
        _debug_msg_pos = 0;
        printf("graphicsLib::surfaceFromFile - error loading SDL surface from file '%s'.\n", filename.c_str());
        fflush(stdout);
        timer.delay(1000);
        show_debug_msg("EXIT #05");
        exit(-1);
	} else {
		res->width = res->gSurface->w;
		res->height = res->gSurface->h;
	}
}

int graphicsLib::get_colorkey_n(COLOR_KEYS key)
{
    return color_keys[key];
}

void graphicsLib::loadTileset()
{
	string filename = FILEPATH + "data/images/tilesets/default.png";

	tileset = SDLSurfaceFromFile(filename);
	if (tileset == NULL) {
		cout << "ERROR: Could not find file '" << filename << "'\n";
        show_debug_msg("EXIT #06");
		exit(-1);
	}

	color_keys[COLOR_KEY_GREEN] = SDL_MapRGB(game_screen->format, 55, 255, 0);
    colorcycle_manager.set_color_key_number(COLOR_KEY_GREEN, color_keys[COLOR_KEY_GREEN]);

	color_keys[COLOR_KEY_PURPLE] = SDL_MapRGB(game_screen->format, 255, 0, 255);
    colorcycle_manager.set_color_key_number(COLOR_KEY_PURPLE, color_keys[COLOR_KEY_PURPLE]);

	color_keys[COLOR_KEY_CYAN] = SDL_MapRGB(game_screen->format, 0, 255, 255);
    colorcycle_manager.set_color_key_number(COLOR_KEY_CYAN, color_keys[COLOR_KEY_CYAN]);

}

void graphicsLib::copySDLArea(struct st_rectangle origin_rectangle, struct st_position destiny_pos, SDL_Surface* surfaceOrigin, SDL_Surface* surfaceDestiny, bool fix_colors=true)
{
    UNUSED(fix_colors);
    if (!surfaceDestiny) {
        std::cout << "copySDLArea - ERROR surfaceDestiny is NULL - ignoring..." << std::endl;
        show_debug_msg("EXIT #21.1");
        exit(-1);
    }
    copySDLPortion(origin_rectangle, st_rectangle(destiny_pos.x, destiny_pos.y, origin_rectangle.w, origin_rectangle.h), surfaceOrigin, surfaceDestiny);
}

void graphicsLib::copySDLPortion(st_rectangle original_rect, st_rectangle destiny_rect, SDL_Surface *surfaceOrigin, SDL_Surface *surfaceDestiny)
{
    SDL_Rect src, dest;
    src.x = original_rect.x;
    src.y = original_rect.y;
    src.w = original_rect.w;
    src.h = original_rect.h;
    dest.x = destiny_rect.x;
    dest.y = destiny_rect.y;
    dest.w = destiny_rect.w;
    dest.h = destiny_rect.h;

    if (!surfaceOrigin) {
        cout << "copySDLArea - ERROR surfaceOrigin is NULL\n";
        show_debug_msg("EXIT #20");
        exit(-1);
    }
    if (!surfaceDestiny) {
        std::cout << "copySDLPortion - ERROR surfaceDestiny is NULL - ignoring..." << std::endl;
        show_debug_msg("EXIT #21");
        exit(-1);
    }

    if (surfaceDestiny == game_screen) { // if painting on game_screen, use position adjusts
        dest.x += _screen_resolution_adjust.x;
        dest.y += _screen_resolution_adjust.y;
        //std::cout << "graphicsLib::copySDLPortion - dest.x: " << dest.x << ", dest.w: " << dest.w << std::endl;
    }

    //std::cout << ">> graphicsLib::copySDLPortion- origin.w: " << surfaceOrigin->w << ", origin.h: " << surfaceOrigin->h << ", src.x: " << src.x << ", src.y: " << src.y << std::endl;

    SDL_BlitSurface(surfaceOrigin, &src, surfaceDestiny, &dest);
}

void graphicsLib::copy_gamescreen_area(st_rectangle origin_rectangle, st_position pos, graphicsLib_gSurface *surfaceDestiny)
{
    origin_rectangle.x += _screen_resolution_adjust.x;
    origin_rectangle.y += _screen_resolution_adjust.y;
    copyArea(origin_rectangle, pos, &gameScreen, surfaceDestiny);
}

void graphicsLib::copyArea(struct st_rectangle origin_rectangle, struct st_position pos, struct graphicsLib_gSurface* surfaceOrigin, struct graphicsLib_gSurface* surfaceDestiny)
{
    if (!surfaceDestiny->gSurface) {
        std::cout << "copyArea - ERROR surfaceDestiny is NULL - ignoring..." << std::endl;
        show_debug_msg("EXIT #21.3");
        exit(-1);
    }
    copySDLArea(origin_rectangle, pos, surfaceOrigin->gSurface, surfaceDestiny->gSurface);
}

void graphicsLib::copy_area_with_colormap_update(struct st_rectangle origin_rectangle, struct st_position pos, struct graphicsLib_gSurface* surfaceOrigin, struct graphicsLib_gSurface* surfaceDestiny)
{
    if (!surfaceDestiny->gSurface) {
        std::cout << "copyArea - ERROR surfaceDestiny is NULL - ignoring..." << std::endl;
        show_debug_msg("EXIT #21.3");
        exit(-1);
    }
    //update_surface_colormap(surfaceOrigin->gSurface);
    //update_surface_colormap(surfaceDestiny->gSurface, colormap_original);
    //update_surface_colormap(tileset, colormap);
    update_surface_colormap(surfaceOrigin->gSurface, colormap);
    copySDLArea(origin_rectangle, pos, surfaceOrigin->gSurface, surfaceDestiny->gSurface);
}

void graphicsLib::copyArea(struct st_position pos, struct graphicsLib_gSurface* surfaceOrigin, struct graphicsLib_gSurface* surfaceDestiny)
{
    if (!surfaceDestiny->gSurface) {
        std::cout << "copyArea - ERROR surfaceDestiny is NULL - ignoring..." << std::endl;
        show_debug_msg("EXIT #21.4");
        exit(-1);
    }
    st_rectangle origin_rectangle(0, 0, surfaceOrigin->width, surfaceOrigin->height);
    copySDLArea(origin_rectangle, pos, surfaceOrigin->gSurface, surfaceDestiny->gSurface);
}

void graphicsLib::copyAreaWithAdjust(struct st_position pos, struct graphicsLib_gSurface* surfaceOrigin, struct graphicsLib_gSurface* surfaceDestiny)
{
    if (!surfaceDestiny->gSurface) {
        std::cout << "copyAreaWithAdjust - ERROR surfaceDestiny is NULL - ignoring..." << std::endl;
        show_debug_msg("EXIT #21.4");
        exit(-1);
    }
    int w = surfaceOrigin->width;
    int h = surfaceOrigin->height;
    st_rectangle origin_rectangle(0, 0, w, h);
    pos.x += _screen_adjust.x;
    //pos.x += _screen_resolution_adjust.x;
    //pos.y += _screen_resolution_adjust.y;

    update_surface_colormap(surfaceOrigin->gSurface, colormap);
    copySDLArea(origin_rectangle, pos, surfaceOrigin->gSurface, surfaceDestiny->gSurface);
}

void graphicsLib::placeTile(struct st_position pos_origin, struct st_position pos_destiny, struct graphicsLib_gSurface* gSurface)
{
    if (!gSurface->gSurface) {
        std::cout << "placeTile - ERROR surfaceDestiny is NULL - ignoring..." << std::endl;
        show_debug_msg("EXIT #21.5");
        exit(-1);
    }
    struct st_rectangle origin_rectangle;

	origin_rectangle.x = pos_origin.x * TILESIZE;
	origin_rectangle.y = pos_origin.y * TILESIZE;

	origin_rectangle.w = TILESIZE;
    origin_rectangle.h = TILESIZE;


    pos_destiny.x += _screen_adjust.x;
    copySDLArea(origin_rectangle, pos_destiny, tileset, gSurface->gSurface);
}

void graphicsLib::place_3rd_level_tile(int origin_x, int origin_y, int dest_x, int dest_y)
{
    struct st_rectangle origin_rectangle(origin_x*TILESIZE, origin_y*TILESIZE, TILESIZE, TILESIZE);
    st_position pos_destiny(dest_x+_screen_adjust.x, dest_y);

    copySDLArea(origin_rectangle, pos_destiny, tileset, game_screen);
}



void graphicsLib::showSurface(struct graphicsLib_gSurface* surfaceOrigin)
{
    if (!game_screen) {
        std::cout << "showSurface - ERROR surfaceDestiny is NULL - ignoring..." << std::endl;
        show_debug_msg("EXIT #21.6");
        exit(-1);
    }
	struct st_rectangle origin_rectangle;
	struct st_position pos_destiny;

	origin_rectangle.x = 0;
	origin_rectangle.y = 0;
	origin_rectangle.w = RES_W;
	origin_rectangle.h = RES_H;
	pos_destiny.x = 0;
	pos_destiny.y = 0;
    //copySDLArea(origin_rectangle, pos_destiny, surfaceOrigin->gSurface, game_screen);
    showSurfacePortion(surfaceOrigin, origin_rectangle, st_rectangle(_screen_adjust.x, _screen_adjust.y, surfaceOrigin->width, surfaceOrigin->height));
}

void graphicsLib::showMapSurfaceRegion(graphicsLib_gSurface *surfaceOrigin, st_rectangle origin_rectangle)
{
	if (_screen_adjust.x < 0) {
		origin_rectangle.w += abs(_screen_adjust.x);
	}
    update_surface_colormap(surfaceOrigin->gSurface, colormap);
    copySDLPortion(origin_rectangle, st_rectangle(_screen_adjust.x, 0, RES_W, RES_H), surfaceOrigin->gSurface, game_screen);
}

void graphicsLib::showSurfaceRegion(struct graphicsLib_gSurface* surfaceOrigin, const struct st_rectangle origin_rectangle)
{
	struct st_position pos_destiny;

	pos_destiny.x = 0;
	pos_destiny.y = 0;
	showSurfaceRegionAt(surfaceOrigin, origin_rectangle, pos_destiny);
}

void graphicsLib::showSurfaceRegionAt(struct graphicsLib_gSurface* surfaceOrigin, const struct st_rectangle origin_rectangle, struct st_position pos_destiny)
{
    if (!game_screen) {
        std::cout << "showSurfaceRegionAt - ERROR surfaceDestiny is NULL - ignoring..." << std::endl;
        show_debug_msg("EXIT #21.4");
        exit(-1);
    }
    copySDLArea(origin_rectangle, pos_destiny, surfaceOrigin->gSurface, game_screen);
}

void graphicsLib::showSurfacePortion(graphicsLib_gSurface *surfaceOrigin, const st_rectangle origin_rect, st_rectangle destiny_rect)
{
    if (!game_screen) {
        std::cout << "showSurfacePortion - ERROR surfaceDestiny is NULL - ignoring..." << std::endl;
        show_debug_msg("EXIT #21.2");
        exit(-1);
    }
    copySDLPortion(origin_rect, destiny_rect, surfaceOrigin->gSurface, game_screen);
}

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void graphicsLib::showSurfaceAt(struct graphicsLib_gSurface* surfaceOrigin, struct st_position pos, bool fix_colors=true)
{
    if (!game_screen) {
        std::cout << "showSurfaceAt - ERROR surfaceDestiny is NULL - ignoring..." << std::endl;
        show_debug_msg("EXIT #21.7");
        exit(-1);
    }

	struct st_rectangle origin_rectangle;
	struct st_position pos_destiny;

	if (!surfaceOrigin->gSurface) {
		std::cout << "Error: no data in surfaceOrigin at graphicsLib::showSurfaceAt." << std::endl;
		//exit(-1);
		return;
	}

	origin_rectangle.x = 0;
	origin_rectangle.y = 0;
	origin_rectangle.w = surfaceOrigin->gSurface->w;
	origin_rectangle.h = surfaceOrigin->gSurface->h;
	pos_destiny.x = pos.x;
	pos_destiny.y = pos.y;

    copySDLArea(origin_rectangle, pos_destiny, surfaceOrigin->gSurface, game_screen, fix_colors);
}

void graphicsLib::show_white_surface_at(graphicsLib_gSurface *surfaceOrigin, st_position pos)
{
    // create a new surface
    struct graphicsLib_gSurface tmp;
    initSurface(st_size(surfaceOrigin->width, surfaceOrigin->height), &tmp);
    copyArea(st_position(0, 0), surfaceOrigin, &tmp);
    set_colormap_white(&tmp);
    //struct st_position pos, struct graphicsLib_gSurface* surfaceOrigin, struct graphicsLib_gSurface* surfaceDestiny
    showSurfaceAt(&tmp, pos, false);
}

void graphicsLib::initSurface(struct st_size size, struct graphicsLib_gSurface* gSurface)
{
    if (game_screen == NULL) {
        return;
    }
    gSurface->freeGraphic();
    SDL_Surface* temp_surface = SDL_CreateRGBSurface(SDL_SWSURFACE , size.width, size.height, 8, 0, 0, 0, 0);

    if (!temp_surface) {
        show_debug_msg("EXIT #21.INIT #1");
        exit(-1);
    }


    update_surface_colormap(temp_surface, colormap_original);
    SDL_FillRect(temp_surface, NULL, SDL_MapRGB(game_screen->format, COLORKEY_R, COLORKEY_G, COLORKEY_B));
    SDL_SetColorKey(temp_surface, SDL_SRCCOLORKEY, SDL_MapRGB(game_screen->format, COLORKEY_R, COLORKEY_G, COLORKEY_B));

    gSurface->gSurface = SDL_DisplayFormat(temp_surface);


    if (!gSurface->gSurface) {
        //show_debug_msg("EXIT #21.INIT #2");
        std::cout << "GRAPH::initSurface WARNING - can't convert to screen-format" << std::endl;
        #ifdef PSP
        std::cout << "GRAPH::initSurface - SDL_DisplayFormat failed. RAM='" << _ram_counter.ramAvailable() << "'" << std::endl;
        #endif
        gSurface->gSurface = temp_surface; // stay with the original file in case of error (should fix PSP crash issues)
    } else {
        SDL_FreeSurface(temp_surface); // free the original
    }
	gSurface->width = size.width;
    gSurface->height = size.height;
}


struct graphicsLib_gSurface graphicsLib::surfaceFromRegion(struct st_rectangle rect_origin, struct graphicsLib_gSurface& originalSurface)
{

	struct st_position destiny_pos;

	destiny_pos.x = 0;
	destiny_pos.y = 0;
	struct graphicsLib_gSurface res;
	initSurface(st_size(rect_origin.w, rect_origin.h), &res);

    if (!res.gSurface) {
        std::cout << "surfaceFromRegion - ERROR surfaceDestiny is NULL - ignoring..." << std::endl;
        show_debug_msg("EXIT #21.8");
        exit(-1);
    }

    /// @NOTE: removed for optimization test
    update_surface_colormap(res.gSurface, colormap_original);
	copySDLArea(rect_origin, destiny_pos, originalSurface.gSurface, res.gSurface);
    /// @NOTE: removed for optimization test
    update_surface_colormap(originalSurface.gSurface, colormap_original);
	return res;
}



void graphicsLib::blank_screen() {
	SDL_FillRect(game_screen, NULL, SDL_MapRGB(game_screen->format, 0, 0, 0));
}

void graphicsLib::blank_surface(graphicsLib_gSurface &surface)
{
	SDL_FillRect(surface.gSurface, NULL, SDL_MapRGB(game_screen->format, 0, 0, 0));
}

void graphicsLib::blank_area(short int x, short int y, short int w, short int h) {
    clear_area(x, y, w, h, 0, 0, 0);
}

void graphicsLib::blank_area(short x, short y, short w, short h, graphicsLib_gSurface &surface)
{
    clear_surface_area(x, y, w, h, 0, 0, 0, surface);
}


int graphicsLib::draw_progressive_text(short int x, short int y, string text, bool interrupt) {
    UNUSED(interrupt);
	//SDL_Color font_color = {255,255,255};
	string temp_text;
	char temp_char;
	int text_x = 0;
	int text_y = 0;
	unsigned int i;

	if (!font) {
		printf("ERROR - no fount found - TTF_OpenFont: %s\n", TTF_GetError());
        show_debug_msg("EXIT #09");
		exit(-1);
	}


	for (i=0; i<text.size(); i++) {
		temp_char = text.at(i);

		temp_text = "";
		temp_text += temp_char;

		draw_text(text_x*9+x, text_y*11+y, temp_text);
		text_x++;
		if (temp_char == '\n') {
				text_x = 0;
				text_y++;
		}
		updateScreen();
		/*
        if (interrupt) {
			cut = input.waitScapeTime(5);
			if (cut) { return 1; }
		} else {
			input.waitTime(5);
		}
		*/
		timer.delay(15);
	}
	return 0;
}




void graphicsLib::draw_text(short int x, short int y, string text) {
	if (text.length() <= 0) {
		return;
	}
	SDL_Color font_color;
	font_color.r = 255;
	font_color.g = 255;
	font_color.b = 255;
    x += _screen_resolution_adjust.x;
    y += _screen_resolution_adjust.y;
	SDL_Rect text_pos={x, y, 0, 0};
	if (!font) {
		printf("graphicsLib::draw_text - TTF_OpenFont: %s\n", TTF_GetError());
        show_debug_msg("EXIT #10");
		exit(-1);
		// handle error
	}
	SDL_Surface* textSF = TTF_RenderText_Solid(font, text.c_str(), font_color);
    if (!textSF) {
        return;
    }
	SDL_Surface* textSF_format = SDL_DisplayFormat(textSF);
    SDL_FreeSurface(textSF);

    if (!textSF_format) {
        return;
    }
    SDL_BlitSurface(textSF_format, 0, game_screen, &text_pos);
    SDL_FreeSurface(textSF_format);
}

void graphicsLib::draw_text(short x, short y, string text, graphicsLib_gSurface &surface)
{
	SDL_Color font_color;
	font_color.r = 255;
	font_color.g = 255;
	font_color.b = 255;
	SDL_Rect text_pos={x, y, 0, 0};
	if (!font) {
		printf("graphicsLib::draw_text - TTF_OpenFont: %s\n", TTF_GetError());
        show_debug_msg("EXIT #11");
		exit(-1);
		// handle error
	}
    text_pos.x += _screen_resolution_adjust.x;
    text_pos.y += _screen_resolution_adjust.y;
    SDL_Surface* textSF = TTF_RenderText_Solid(font, text.c_str(), font_color);
    SDL_Surface* textSF_format = SDL_DisplayFormat(textSF);
	SDL_FreeSurface(textSF);
	SDL_BlitSurface(textSF_format, 0, surface.gSurface, &text_pos);
	SDL_FreeSurface(textSF_format);
}

void graphicsLib::draw_centered_text(short y, string text, st_color font_color)
{
    draw_centered_text(y, text, gameScreen, font_color);
}

void graphicsLib::draw_centered_text(short y, string text, graphicsLib_gSurface &surface, st_color temp_font_color)
{
	SDL_Color font_color;
    font_color.r = temp_font_color.r;
    font_color.g = temp_font_color.g;
    font_color.b = temp_font_color.b;
	SDL_Rect text_pos={0, y, 0, 0};
	if (!font) {
		printf("graphicsLib::draw_text - TTF_OpenFont: %s\n", TTF_GetError());
        show_debug_msg("EXIT #12");
		exit(-1);
		// handle error
	}
	SDL_Surface* textSF = TTF_RenderText_Solid(font, text.c_str(), font_color);
	if (textSF == NULL) {
		return;
	}
	if (text.size() > 0) {
		text_pos.x = RES_W/2 - textSF->w/2;
	}
    //text_pos.x += _screen_resolution_adjust.x;
    //text_pos.y += _screen_resolution_adjust.y;
    SDL_Surface* textSF_format = SDL_DisplayFormat(textSF);
	SDL_FreeSurface(textSF);
	SDL_BlitSurface(textSF_format, 0, surface.gSurface, &text_pos);
	SDL_FreeSurface(textSF_format);
}



int graphicsLib::getColorNumber(int r, int g, int b) {
	return SDL_MapRGB(game_screen->format, r, g, b);
}


void graphicsLib::drawCursor(st_position pos) {
	draw_text(pos.x, pos.y, ">");
}

void graphicsLib::eraseCursor(st_position pos) {
	blank_area(pos.x, pos.y, CURSOR_SPACING, CURSOR_SPACING);
}

void graphicsLib::blink_screen(int r, int g, int b) {
	int i;
    struct graphicsLib_gSurface screen_copy;

	initSurface(st_size(gameScreen.width, gameScreen.height), &screen_copy);
	copyArea(st_position(0, 0), &gameScreen, &screen_copy);

	for (i=0; i<4; i++) {
        SDL_FillRect(game_screen, 0, SDL_MapRGB(game_screen->format, r, g, b));

		updateScreen();
		input.waitTime(80);

		SDL_BlitSurface(screen_copy.gSurface, 0, game_screen, 0);
		updateScreen();
		input.waitTime(80);
    }
}

void graphicsLib::blink_surface_into_screen(struct graphicsLib_gSurface &surface)
{
    st_color color_white(235, 235, 235);
    st_color color_black(0, 0, 0);

    Uint32 key_n = SDL_MapRGB(tileset->format, color_black.r, color_black.g, color_black.b);
    for (int i=0; i<5; i++) {
        change_surface_color(key_n, color_white, &surface);
        showSurface(&surface);
        wait_and_update_screen(100);
        change_surface_color(key_n, color_black, &surface);
        showSurface(&surface);
        wait_and_update_screen(100);
    }
}

void graphicsLib::load_icons()
{
	struct graphicsLib_gSurface tmp;
	std::string filename = FILEPATH + "data/images/items.png";

	surfaceFromFile(filename, &tmp);
	for (int i=0; i<(tmp.width/16); i++) {
		item_icons.push_back(graphicsLib_gSurface());
		initSurface(st_size(16, 16), &item_icons.at(item_icons.size()-1));
		copyArea(st_rectangle(i*16, 0, 16, 16), st_position(0, 0), &tmp, &(item_icons.at(item_icons.size()-1)));
	}

	// big icon
	filename = FILEPATH + "data/images/icons.png";
	surfaceFromFile(filename, &tmp);
	for (int i=0; i<(tmp.width/14); i++) {
		weapon_icons.push_back(graphicsLib_gSurface());
		initSurface(st_size(14, 28), &weapon_icons.at(weapon_icons.size()-1));
		copyArea(st_rectangle(i*14, 0, 14, 28), st_position(0, 0), &tmp, &(weapon_icons.at(weapon_icons.size()-1)));
	}

	// small icons
	filename = FILEPATH + "data/images/icons_small.png";
	surfaceFromFile(filename, &tmp);
	for (int i=0; i<(tmp.width/8); i++) {
		small_weapon_icons.push_back(graphicsLib_gSurface());
		initSurface(st_size(8, 8), &small_weapon_icons.at(small_weapon_icons.size()-1));
		copyArea(st_rectangle(i*8, 0, 8, 8), st_position(0, 0), &tmp, &(small_weapon_icons.at(small_weapon_icons.size()-1)));
	}



	filename = FILEPATH + "data/images/backgrounds/config_fg.png";
	surfaceFromFile(filename, &config_menu);

	_config_menu_pos.x = (RES_W-config_menu.width)*0.5;

	filename = FILEPATH + "data/images/backgrounds/dialog.png";
	surfaceFromFile(filename, &dialog_surface);

	filename = FILEPATH + "data/images/backgrounds/weapon_menu.png";
	surfaceFromFile(filename, &ingame_menu);

    filename = FILEPATH + "data/images/backgrounds/btn_a.png";
    surfaceFromFile(filename, &_btn_a_surface);

}


void graphicsLib::draw_item_icon(enum ITEM_ICONS_ENUM item_n, st_position pos)
{
	showSurfaceAt(&(item_icons.at(item_n)), pos);
}


void graphicsLib::draw_weapon_icon(short wpn_n, st_position point, bool active)
{
    st_position pos;

    if (point.x == 0) {
        pos.x = WPN_COLUMN1_X;
    } else {
        pos.x = WPN_COLUMN2_X;
    }

    pos.y = WPN_COLUMN_Y-3+point.y*16;

    //std::cout << "### GRAPH::draw_weapon_icon - wpn_n: " << wpn_n<< ", point.x: " << point.x << ", point.y: " << point.y << ", pos.x: " << pos.x << ", pos.y: " << pos.y << std::endl;

    clear_area(pos.x, pos.y, 14, 16, 0, 0, 0);
    if (active == true) {
        showSurfaceRegionAt(&weapon_icons.at(wpn_n), st_rectangle(0, 0, 14, 14), pos);
    } else {
        showSurfaceRegionAt(&weapon_icons.at(wpn_n), st_rectangle(0, 14, 14, 14), pos);
    }
}

void graphicsLib::draw_menu_item(int x_pos)
{
	graphicsLib_gSurface* spriteCopy;
    int x;

	if (x_pos == 0) {
        spriteCopy = &e_tank[0];
        x = 93;
	} else if (x_pos == 1) {
        spriteCopy = &w_tank[0];
        x = 117;
	} else {
        spriteCopy = &s_tank[0];
        x = 142;
	}
    copyArea(st_rectangle(0, 0, TILESIZE, TILESIZE), st_position(x, 196), spriteCopy, &gameScreen);
    //copyArea(st_position(x, 196), spriteCopy, &gameScreen);
}

void graphicsLib::erase_menu_item(int x_pos)
{
	graphicsLib_gSurface* spriteCopy;
	int x;

	if (x_pos == 0) {
		spriteCopy = &e_tank[1];
        x = 93;
	} else if (x_pos == 1) {
		spriteCopy = &w_tank[1];
        x = 117;
	} else {
		spriteCopy = &s_tank[1];
        x = 142;
	}
    copyArea(st_rectangle(0, 0, TILESIZE, TILESIZE), st_position(x, 196), spriteCopy, &gameScreen);
    //copyArea(st_position(x, 196), spriteCopy, &gameScreen);
}

void graphicsLib::draw_weapon_menu_bg(Uint8 current_hp, graphicsLib_gSurface* player_frame) {
	showSurfaceAt(&ingame_menu, st_position((RES_W-ingame_menu.width)*0.5, (RES_H-ingame_menu.height)*0.5));

	showSurfaceRegionAt(&weapon_icons.at(0), st_rectangle(0, 14, 14, 14), st_position(WPN_COLUMN1_X, 50));
	draw_horizontal_hp_bar(WPN_COLUMN_Y, 2, current_hp);

    for (int i=1; i<6; i++) {
        if (game_save.stages[i] == 1) {
            //std::cout << ">> #1 graphicsLib::draw_weapon_menu_bg - stage[" << i << "]: " << game_save.stages[i] << std::endl;
            showSurfaceRegionAt(&weapon_icons.at(i), st_rectangle(0, 14, 14, 14), st_position(WPN_COLUMN1_X, 50+(i)*16));
            draw_horizontal_hp_bar(WPN_COLUMN_Y+(i)*WEAPON_SPACING, 2, game_save.items.weapons[i]);
		}
    }

    for (int i=6; i<=9; i++) {
        if (game_save.stages[i] == 1) {
            //std::cout << ">> #3 graphicsLib::draw_weapon_menu_bg - stage[" << i << "]: " << game_save.stages[i] << std::endl;
            showSurfaceRegionAt(&weapon_icons.at(i), st_rectangle(0, 14, 14, 14), st_position(182, 50+(i-5)*16));
            draw_horizontal_hp_bar(WPN_COLUMN_Y+(i-5)*WEAPON_SPACING, 3, game_save.items.weapons[i]);
		}
	}

    // coil and jet
    if (game_save.stages[COIL_GOT_STAGE] == 1) {
        int wpn_icon_n = 9;
        int menu_row = 4;
        showSurfaceRegionAt(&weapon_icons.at(wpn_icon_n), st_rectangle(0, 14, 14, 14), st_position(182, 50+(menu_row)*16));
        draw_horizontal_hp_bar(WPN_COLUMN_Y+(menu_row)*WEAPON_SPACING, 3, game_save.items.weapons[wpn_icon_n]);
    }
    if (game_save.stages[JET_GOT_STAGE] == 1) {
        int wpn_icon_n = 10;
        int menu_row = 5;
        showSurfaceRegionAt(&weapon_icons.at(wpn_icon_n), st_rectangle(0, 14, 14, 14), st_position(182, 50+(menu_row)*16));
        draw_horizontal_hp_bar(WPN_COLUMN_Y+(menu_row)*WEAPON_SPACING, 3, game_save.items.weapons[wpn_icon_n]);
    }



	copyArea(st_position(26, 190), player_frame, &gameScreen);

	std::stringstream ss;
	int item_text_pos = 217;

	ss.str(std::string());
    ss << "0" << (short)game_save.items.lifes;
    draw_text(58, item_text_pos, ss.str());


	ss.str(std::string());
    ss << "0" << (short)game_save.items.energy_tanks;
    draw_text(93, item_text_pos, ss.str());

	ss.str(std::string());
    ss << "0" << (short)game_save.items.weapon_tanks;
    draw_text(117, item_text_pos, ss.str());

	ss.str(std::string());
    ss << "0" << (short)game_save.items.special_tanks;
    draw_text(142, item_text_pos, ss.str());


	ss.str(std::string());
    ss << "0" << (int)game_save.items.bolts;
    draw_text(273, item_text_pos, ss.str());

	//std::cout << "item_ref->energy_tanks: " << item_ref->energy_tanks << ", item_ref->weapon_tanks: " << item_ref->weapon_tanks << std::endl;

	//if (item_ref->balancer > 0) {
	if (true) {
        copyArea(st_position(245, 196), &energy_balancer, &gameScreen);
	}

    if (game_save.armor_pieces[ARMOR_ARMS] == true) {
        copyArea(st_position(198, 197), &armor_icon_arms, &gameScreen);
    }
    if (game_save.armor_pieces[ARMOR_BODY] == true) {
        copyArea(st_position(221, 197), &armor_icon_body, &gameScreen);
    }
    if (game_save.armor_pieces[ARMOR_LEGS] == true) {
        copyArea(st_position(175, 197), &armor_icon_legs, &gameScreen);
    }

	updateScreen();
}


void graphicsLib::scale2x(SDL_Surface* surface, SDL_Surface* dest, bool smooth_scale) const
{
    register int i, j;
	int b, h;
	int bpp = surface->format->BytesPerPixel;
	if (SDL_MUSTLOCK(dest) != 0)
	{
	 if (SDL_LockSurface(dest) < 0)
	 {
	   fprintf(stderr, "dest locking failedn");
	   return;
	 }
	}

	const int wd = ((dest->w / 2) < (surface->w)) ? (dest->w / 2) : (surface->w);
	const int hg = ((dest->h) < (surface->h*2)) ? (dest->h / 2) : (surface->h);

	switch (bpp)
	{
	case 1:
	{
		int tpitch = dest->pitch;
		int spitch = surface->pitch;
		Uint8* tp = (Uint8*) dest->pixels;
		Uint8* sp = (Uint8*) surface->pixels;

		for (j = 0; j < hg; ++j)
		{
			b = j>0?spitch:0;
			h = j<hg?spitch:0;

			for (i = 0; i < wd; ++i)
			{
				if (B != H && D != F) {
					if (smooth_scale == true) {
						E0 = D == B ? D : E;
						E1 = B == F ? F : E;
						E2 = D == H ? D : E;
						E3 = H == F ? F : E;
					} else {
						E0 = E;
						E1 = E;
						E2 = E;
						E3 = E;
					}
				} else {
					E0 = E;
					E1 = E;
					E2 = E;
					E3 = E;
				}
			}
			tp += 2*tpitch;
			sp += spitch;
		}

		break;
	}

	 case 2:
	 {
	   int tpitch = dest->pitch / 2;
	   int spitch = surface->pitch / 2;
	   Uint16* tp = (Uint16*) dest->pixels;
	   Uint16* sp = (Uint16*) surface->pixels;

	   for (j = 0; j < hg; ++j)
	   {
		b = j>0?spitch:0;
		h = j<hg?spitch:0;
		 for (i = 0; i < wd; ++i)
		 {
			   if (B != H && D != F) {
					   E0 = D == B ? D : E;
					   E1 = B == F ? F : E;
					   E2 = D == H ? D : E;
					   E3 = H == F ? F : E;
			   } else {
					   E0 = E;
					   E1 = E;
					   E2 = E;
					   E3 = E;
			   }
		 }
		 tp += 2*tpitch;
		 sp += spitch;
	   }

	   break;
	 }
	 case 4:
	 {
	   int tpitch = dest->pitch / 4;
	   int spitch = surface->pitch / 4;
	   Uint32* tp = (Uint32*) dest->pixels;
	   Uint32* sp = (Uint32*) surface->pixels;

	   for (j = 0; j < hg; ++j)
	   {
		b = j>0?spitch:0;
		h = j<hg?spitch:0;
		 for (i = 0; i < wd; ++i)
		 {
			   if (B != H && D != F) {
					   E0 = D == B ? D : E;
					   E1 = B == F ? F : E;
					   E2 = D == H ? D : E;
					   E3 = H == F ? F : E;
			   } else {
					   E0 = E;
					   E1 = E;
					   E2 = E;
					   E3 = E;
			   }
		 }
		 tp += 2*tpitch;
		 sp += spitch;
	   }

	   break;
	 }
	 default:
	   std::cout << "Unsupported bitdepth.n(" << bpp << ")" << std::endl;
	   break;
	}


	if (SDL_MUSTLOCK(dest) != 0)
	{
	 SDL_UnlockSurface(dest);
	}
}


void graphicsLib::change_colormap(unsigned int color_key, st_color new_color)
{
	if (!game_screen) {
		std::cout << "graphicsLib::change_colormap - LEAVE because there is no game_screen" << std::endl;
		return;
	}
    if (new_color.r < 0 || new_color.g < 0 || new_color.b < 0) { // not a valid color, ignore
        return;
    }
	colormap[color_keys[color_key]].r = new_color.r;
	colormap[color_keys[color_key]].g = new_color.g;
	colormap[color_keys[color_key]].b = new_color.b;
	//std::cout << "change_colormap - color_key: " << color_key << ", res: " << res << std::endl;
}

void graphicsLib::draw_hp_bar(short int hp, short int player_n, short int weapon_n)
{
	short int y, i;

	st_color color1(255, 51, 0);
	if (weapon_n == -1) {
		color1.r = 127;
		color1.g = 11;
		color1.b = 0;
	} else if (weapon_n == WEAPON_DEFAULT) {
		if (player_n == 0) {
			color1.r = 127;
			color1.g = 11;
			color1.b = 0;
		}
	} else {
		color1.r = game_data.players[player_n].weapon_colors[weapon_n].color1.r;
		color1.g = game_data.players[player_n].weapon_colors[weapon_n].color1.g;
		color1.b = game_data.players[player_n].weapon_colors[weapon_n].color1.b;
	}
	st_color color2(188, 188, 188);
	st_color color3(235, 235, 235);

	if (weapon_n == WEAPON_MUMMYBOT || weapon_n == WEAPON_ITEM_JET) {
		color2.r = 97;
		color2.g = 97;
		color2.b = 97;
		color3.r = 188;
		color3.g = 188;
		color3.b = 188;
	}
	if (weapon_n == WEAPON_APEBOT) {
		color1.r = 255;
		color1.g = 100;
		color1.b = 100;
	}

	st_position bar_pos(1, 2);
	if (player_n == -1) {
		bar_pos.x = RES_W-15;
	} else if (weapon_n != WEAPON_DEFAULT) {
		bar_pos.x = 10;
	}


	clear_area(bar_pos.x, bar_pos.y, 8, 57, color1.r, color1.g, color1.b);

	if (weapon_n != -1) {
		showSurfaceRegionAt(&small_weapon_icons.at(weapon_n), st_rectangle(0, 0, 8, 8), st_position(bar_pos.x, 59));
	} else {
        showSurfaceRegionAt(&small_weapon_icons.at(WEAPON_COUNT), st_rectangle(0, 0, 8, 8), st_position(bar_pos.x, 59));
	}


	for (i=0; i<hp; i++) {
		y = ((28-i)*2+1)+bar_pos.y-2;
		clear_area(bar_pos.x+1, y, 2, 1, color2.r, color2.g, color2.b);
		clear_area(bar_pos.x+3, y, 2, 1, color3.r, color3.g, color3.b);
		clear_area(bar_pos.x+5, y, 2, 1, color2.r, color2.g, color2.b);
	}
}

void graphicsLib::clear_area(short int x, short int y, short int w, short int h, short int r, short int g, short int b) {
    //std::cout << ">> graphicsLib::clear_area - x: " << x << ", w: " << w << std::endl;
	SDL_Rect dest;
    dest.x = x + _screen_resolution_adjust.x;
    dest.y = y + _screen_resolution_adjust.y;
	dest.w = w;
	dest.h = h;
    SDL_FillRect(game_screen, &dest, SDL_MapRGB(game_screen->format, r, g, b));
}

void graphicsLib::clear_area_no_adjust(short x, short y, short w, short h, short r, short g, short b)
{
    //std::cout << ">> graphicsLib::clear_area - x: " << x << ", w: " << w << std::endl;
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;
    SDL_FillRect(game_screen, &dest, SDL_MapRGB(game_screen->format, r, g, b));
}

void graphicsLib::clear_surface_area(short int x, short int y, short int w, short int h, short int r, short int g, short int b, struct graphicsLib_gSurface& surface) const {
	SDL_Rect dest;
    if (surface.gSurface == gameScreen.gSurface) {
        dest.x = x + _screen_resolution_adjust.x;
        dest.y = y + _screen_resolution_adjust.y;
    } else {
        dest.x = x;
        dest.y = y;
    }
	dest.w = w;
	dest.h = h;
    //int color_n = SDL_MapRGB(surface.gSurface->format, r, g, b);
    SDL_FillRect(surface.gSurface, &dest, SDL_MapRGB(surface.gSurface->format, r, g, b));
}

void graphicsLib::set_colormap(int map_n) {
    // set new colormap
    reset_colormap();

    colorcycle_manager.set_colormap(map_n);
}

void graphicsLib::execute_colorcycle()
{
    colorcycle_manager.execute();
}

void graphicsLib::reset_colormap()
{
    //std::cout << "graphicsLib::reset_colormap" << std::endl;
    change_colormap(COLOR_KEY_GREEN, st_color(55, 255, 0));
	change_colormap(COLOR_KEY_PURPLE, st_color(255, 0, 255));
	change_colormap(COLOR_KEY_CYAN, st_color(0, 255, 255));

    if (tileset != NULL) {
        update_surface_colormap(tileset, colormap_original);
    }
    update_surface_colormap(game_screen, colormap_original);
}

void graphicsLib::reset_image_colormap(graphicsLib_gSurface &surface)
{
    change_surface_color(graphLib.get_colorkey_n(COLOR_KEY_GREEN), st_color(55, 255, 0), &surface);
    change_surface_color(graphLib.get_colorkey_n(COLOR_KEY_PURPLE), st_color(255, 0, 255), &surface);
    change_surface_color(graphLib.get_colorkey_n(COLOR_KEY_CYAN), st_color(0, 255, 255), &surface);
}

void graphicsLib::show_config_bg(int position) // 0 - centered, 1 - top, 2 - bottom
{
	if (position == 0) {
		_config_menu_pos.y = (RES_H-config_menu.height)*0.5;
	} else if (position == 1) {
		_config_menu_pos.y = 3;
	} else {
		_config_menu_pos.y = RES_H - config_menu.height - 25;
	}

	st_position bg_pos(_config_menu_pos.x, _config_menu_pos.y);

	copyArea(bg_pos, &config_menu, &gameScreen);
}


// position - 0: center, 1: top, 2: bottom
void graphicsLib::show_dialog(int position, bool show_btn)
{
	int posX = (RES_W-dialog_surface.width)*0.5;
	int posY;

	if (position == 0) {
		posY = (RES_H-dialog_surface.height)*0.5;
	} else if (position == 1) {
		posY = 3;
	} else {
		posY = RES_H - dialog_surface.height - 25;
	}

	_dialog_pos.x = posX;
	_dialog_pos.y = posY;

	st_position bg_pos(posX, posY);
	copyArea(bg_pos, &dialog_surface, &gameScreen);
    if (show_btn == true) {
        show_btn_a(st_position(posX+dialog_surface.width-_btn_a_surface.width-2-TILESIZE, posY+dialog_surface.height-_btn_a_surface.height-TILESIZE/2));
    }
}

st_position graphicsLib::get_dialog_pos() const {
	return _dialog_pos;
}

void graphicsLib::draw_horizontal_hp_bar(short int y_adjust, short int right, short int hp, short int player_n) {
	short int x;
	short int r, g, b;
	// armas - coluna1: 42, 26, 182, coluna2: 26

	if (right == 0) {
		x = WPN_COLUMN1_X+18;
		r = 127;
		g = 11;
		b = 0;
	} else if (right == 1) {
		x = WPN_COLUMN2_X+18;
		r = 255;
		g = 102;
		b = 0;
	} else if (right == 2) {
		x = WPN_COLUMN1_X+18;
		r = 0;
		g = 0;
		b = 0;
	} else {
		x = WPN_COLUMN2_X+18;
		r = 0;
		g = 0;
		b = 0;
	}
	// border
	/*
	clear_area(weapon_menu_surface, x+1, y_adjust, 61, 2, 188, 188, 188);
	clear_area(weapon_menu_surface, x+1, y_adjust+7, 61, 2, 188, 188, 188);

	clear_area(weapon_menu_surface, x+1, y_adjust, 2, 9, 188, 188, 188);
	clear_area(weapon_menu_surface, x+60, y_adjust, 2, 9, 188, 188, 188);
	*/


	if (right < 2) {
		clear_area(x+1, 1+y_adjust, 61, 9, r, g, b);
	}

	draw_horizontal_hp_bar(st_position(x, y_adjust), hp, player_n);

}

void graphicsLib::draw_explosion(st_position pos)
{
	st_size explosion_size(56, 56);
	int max_frames = 7;

	if (_explosion_animation_pos >= max_frames) {
		_explosion_animation_pos = 0;
	}

	int anim_pos = _explosion_animation_pos*explosion_size.width;

    showSurfaceRegionAt(&bomb_explosion_surface, st_rectangle(anim_pos, 0, explosion_size.width, explosion_size.height), pos);

	if (_explosion_animation_timer < timer.getTimer()) {
		_explosion_animation_pos++;
		_explosion_animation_timer = timer.getTimer() + PROJECTILE_DEFAULT_ANIMATION_TIME;
	}

}

void graphicsLib::show_debug_msg(string msg)
{
    std::cout << "GRAPH::show_debug_msg - msg: " << msg << std::endl;
    std::fflush(stdout);

    clear_area(0, 0, RES_W, 50, 50, 50, 50);
    draw_text(10, _debug_msg_pos*12+10, msg, gameScreen);
    updateScreen();
    input.waitTime(3000);
}

void graphicsLib::reset_tileset_colormap()
{
    update_surface_colormap(tileset, colormap_original);
}

void graphicsLib::draw_path(st_position initial_point, st_position final_point, short duration)
{
    short move_step = 1;
    // calculate distance
    int distance = 0;
    int mode = 0;

    // add four because of the curve ahead
    if (initial_point.x > final_point.x) {
        final_point.x -= 4;
    } else if (initial_point.x < final_point.x) {
        final_point.x += 4;
    }

    if (initial_point.x != final_point.x) {
        distance = final_point.x - initial_point.x;
    } else {
        distance = initial_point.y - final_point.y;
        mode = 1;
    }
    // calculate time for each part, being  (move_step)2 pixels each
    int part_duration = duration / (distance/move_step);
    if (distance == 0) {
        return;
    }
    if (distance < 0) {
        move_step = -move_step;
    }
    if (duration > 0) {
        for (int i=0; i<abs(distance/move_step); i++) {
            if (mode == 0) {
                clear_area(initial_point.x + i*move_step, initial_point.y, abs(move_step), 4, 255, 255, 255);
            } else {
                clear_area(initial_point.x, initial_point.y - (i+1)*move_step, 4, abs(move_step), 255, 255, 255);
            }
            updateScreen();
            input.waitTime(part_duration);
        }
    } else {
        if (mode == 0) {
            clear_area(initial_point.x, initial_point.y, abs(distance), 4, 255, 255, 255);
        } else {
            clear_area(initial_point.x, initial_point.y-distance, 4, abs(distance), 255, 255, 255);
        }
        updateScreen();
    }
}

void graphicsLib::add_stage_colorcycle(short stage_n, CURRENT_FILE_FORMAT::file_colorcycle& colorcycle)
{
    colorcycle_manager.add_stage_colorcycle(stage_n, colorcycle);
}


void graphicsLib::draw_horizontal_hp_bar(st_position pos, short int hp, short player_n) {
	for (int i=0; i<hp; i++) {
		int y = ((i-28)*2+1);
		short int pos_x = pos.x+y+58;
		if (player_n == 0) {
			clear_area(pos_x, 2+pos.y, 1, 2, 27, 63, 95);
			clear_area(pos_x, 4+pos.y, 1, 2, 0, 131, 139);
			clear_area(pos_x, 6+pos.y, 1, 2, 27, 63, 95);
		} else if (player_n == 1) {
			clear_area(pos_x, 2+pos.y, 1, 2, 203, 79, 15);
			clear_area(pos_x, 4+pos.y, 1, 2, 255, 155, 59);
			clear_area(pos_x, 6+pos.y, 1, 2, 203, 79, 15);
		} else {
			clear_area(pos_x, 2+pos.y, 1, 2, 188, 188, 188);
			clear_area(pos_x, 4+pos.y, 1, 2, 255, 255, 255);
			clear_area(pos_x, 6+pos.y, 1, 2, 188, 188, 188);
		}
	}
}





void graphicsLib::draw_weapon_cursor(st_position pos, short int hp, short int player_n)
{
    //std::cout << "&&GRAPH::draw_weapon_cursor - pos.x: " << pos.x << ", pos.y: " << pos.y << std::endl;
	int pos_y, pos_x;

	if (pos.x == 0) {
		pos_x = WPN_COLUMN1_X + 18;
	} else {
		pos_x = WPN_COLUMN2_X + 18;
	}



	if (pos.y == 0) {
		pos_y = WPN_COLUMN_Y;
	} else if (pos.y == 6 && pos.x == 0) {
		pos_y = 134;
		pos_x = 196;
	} else if (pos.y == 6 && pos.x == 1) {
		pos_y = 159;
		pos_x = 196;
	} else if (pos.y == 6 && pos.x == 2) {
		pos_y = 183;
		pos_x = 196;
	} else {
		pos_y = WEAPON_SPACING*pos.y + 53;
	}
	if (pos.y != 6) {
		draw_horizontal_hp_bar(st_position(pos_x, pos_y), hp, player_n);
	}
	updateScreen();
}


void graphicsLib::draw_star(short int x, short int y, int size) {
	clear_area(x, y, size, size, 188, 188, 188);
}

void graphicsLib::erase_star(short int x, short int y, int size) {
	clear_area(x, y, size, size, 0, 0, 0);
}


// random a position for each star
void graphicsLib::init_stars() {
	int i;
	for (i=0; i<INTRO_STARS_NUMBER; i++) {
		star_list[i].x = rand() % 320;
		if (i % 2 == 0) {
			star_list[i].y = rand() % 78;
		} else {
			star_list[i].y = rand() % 78 + 162;
		}
	}
	for (i=0; i<INTRO_STARS_NUMBER; i++) {
		small_star_list[i].x = rand() % 320;
		if (i % 2 == 0) {
			small_star_list[i].y = rand() % 78;
		} else {
			small_star_list[i].y = rand() % 78 + 162;
		}
	}
	for (i=0; i<INTRO_STARS_NUMBER/2; i++) {
		big_star_list[i].x = rand() % 320;
		if (i % 2 == 0) {
			big_star_list[i].y = rand() % 78;
		} else {
			big_star_list[i].y = rand() % 78 + 162;
		}
	}
}

void graphicsLib::anim_stars() {
	int i;

	/// @TODO - add timer to control stars speed
	if (stars_timer > timer.getTimer()) {
		return;
	}

    for (i=0; i<INTRO_STARS_NUMBER; i++) {
		erase_star(star_list[i].x, star_list[i].y, 2);
		erase_star(small_star_list[i].x, small_star_list[i].y, 1);
		star_list[i].x -= ANIM_STARS_STEP;
		if (star_list[i].x <= 0) {
			star_list[i].x = 320+ANIM_STARS_STEP;
			if (i % 2 == 0) {
				star_list[i].y = rand() % 78;
			} else {
				star_list[i].y = rand() % 78 + 162;
			}
		}
		small_star_list[i].x -= ANIM_STARS_SMALL_STEP;
		if (small_star_list[i].x <= 0) {
			small_star_list[i].x = 320+ANIM_STARS_SMALL_STEP;
			if (i % 2 == 0) {
				small_star_list[i].y = rand() % 78;
			} else {
				small_star_list[i].y = rand() % 78 + 162;
			}
		}
	}

	for (i=0; i<INTRO_STARS_NUMBER/2; i++) {
		erase_star(big_star_list[i].x, big_star_list[i].y, 3);
		big_star_list[i].x -= ANIM_STARS_BIG_STEP;
		if (big_star_list[i].x <= 0) {
			big_star_list[i].x = 320+ANIM_STARS_BIG_STEP;
			if (i % 2 == 0) {
				big_star_list[i].y = rand() % 78;
			} else {
				big_star_list[i].y = rand() % 78 + 162;
			}
		}
	}

	for (i=0; i<INTRO_STARS_NUMBER; i++) {
		draw_star(star_list[i].x, star_list[i].y, 2);
		draw_star(small_star_list[i].x, small_star_list[i].y, 1);
	}
	for (i=0; i<INTRO_STARS_NUMBER/2; i++) {
		draw_star(big_star_list[i].x, big_star_list[i].y, 3);
	}
    stars_timer = timer.getTimer()+10;
}

void graphicsLib::set_video_mode()
{
#ifdef DINGUX
    game_screen = SDL_SetVideoMode(RES_W, RES_H, 8, SDL_SWSURFACE);
#elif defined(OPEN_PANDORA)
    game_screen = SDL_SetVideoMode(RES_W, RES_H, 8, SDL_HWSURFACE | SDL_DOUBLEBUF);
#elif defined(ANDROID)
    game_screen = SDL_SetVideoMode(RES_W, RES_H, 8, SDL_SWSURFACE);
#elif defined(WII)
    game_screen = SDL_SetVideoMode(RES_W, RES_H, 8, SDL_HWSURFACE);
#elif defined(PSP)
    if (game_config.video_fullscreen == false) {
        game_screen = SDL_SetVideoMode(480, 272, 8, SDL_SWSURFACE | SDL_FULLSCREEN | SDL_RESIZABLE);
    } else {
        game_screen = SDL_SetVideoMode(RES_W, RES_H, 8, SDL_SWSURFACE | SDL_FULLSCREEN | SDL_RESIZABLE);
    }
#elif defined(DREAMCAST)
    game_screen = SDL_SetVideoMode(320, 240, 8, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
#elif defined(PLAYSTATION2)
    game_screen = SDL_SetVideoMode(RES_W, RES_H, 8, SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
    /*
    256, 224 - good
    288, 224 - good (strange colors?)
    256x256 -
    320x200 - distortion
    320x240 - distortion
    320x256 - distortion (small)
    400x256 - distortion
    512x448 - good but small
    */
#else

    if (_video_filter == VIDEO_FILTER_NOSCALE) {
        if (game_config.video_fullscreen == false) {
            game_screen = SDL_SetVideoMode(RES_W, RES_H, 8, SDL_HWSURFACE | SDL_DOUBLEBUF);
        } else {
            game_screen = SDL_SetVideoMode(RES_W, RES_H, 8, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
        }
        //game_screen = SDL_SetVideoMode(480, 272, 8, SDL_HWSURFACE | SDL_DOUBLEBUF); // used for testing centered screen
    } else {
        /// @TODO - do we need scale on fullscreen if no filter?
        if (game_config.video_fullscreen == false) {
            game_screen_scaled = SDL_SetVideoMode(RES_W*2, RES_H*2, 8, SDL_HWSURFACE|SDL_DOUBLEBUF);
        } else {
            game_screen_scaled = SDL_SetVideoMode(RES_W*2, RES_H*2, 8, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
        }
        update_surface_colormap(game_screen_scaled, colormap_original);
        if (game_screen != NULL) {
            SDL_FreeSurface(game_screen);
        }
        SDL_Surface* temp_surface = SDL_CreateRGBSurface(SDL_SWSURFACE, RES_W, RES_H, 8, 0, 0, 0, 255);
        game_screen = SDL_DisplayFormat(temp_surface);
        SDL_FreeSurface(temp_surface);
    }
#endif

    update_surface_colormap(game_screen, colormap_original);
	if (!game_screen) {
        std::cout << "FATAL-ERROR::initGraphics Could not create game_screen" << std::endl;
        show_debug_msg("EXIT #13");
		exit(-1);
	}
	gameScreen.gSurface = game_screen;
    gameScreen.video_screen = true;
	screen_pixel_format = *game_screen->format;

    gameScreen.width = game_screen->w;
    gameScreen.height = game_screen->h;
    _screen_resolution_adjust.x = (game_screen->w - RES_W)/2;
    _screen_resolution_adjust.y = (game_screen->h - RES_H)/2;

}

void graphicsLib::preload_images()
{
	// explision used in death and bosses
	std::string filename = FILEPATH + "data/images/tilesets/explosion_boss.png";
	surfaceFromFile(filename, &small_explosion);

	// projectile images
    for (int i=0; i<FS_MAX_PROJECTILES; i++) {
		std::string filename(game_data.projectiles[i].graphic_filename);
		filename = FILEPATH + "data/images/projectiles/" + filename;
		if (filename.length() > 0 && filename.find(".png") != std::string::npos) {
			surfaceFromFile(filename, &projectile_surface[i]);
		}
	}

	// bomb explosion
	filename = FILEPATH + std::string("/data/images/tilesets/big_boss_explosion.png");
	surfaceFromFile(filename, &bomb_explosion_surface);

	// --- ITEMS --- //
	filename = FILEPATH + "data/images/sprites/objects/energy_tank.png";
	surfaceFromFile(filename, &e_tank[0]);
	filename = FILEPATH + "data/images/sprites/objects/weapons_tank.png";
	surfaceFromFile(filename, &w_tank[0]);
	filename = FILEPATH + "data/images/sprites/objects/special_tank.png";
	surfaceFromFile(filename, &s_tank[0]);
	filename = FILEPATH + "data/images/sprites/objects/gray_energy_tank.png";
	surfaceFromFile(filename, &e_tank[1]);
	filename = FILEPATH + "data/images/sprites/objects/gray_weapons_tank.png";
	surfaceFromFile(filename, &w_tank[1]);
	filename = FILEPATH + "data/images/sprites/objects/gray_special_tank.png";
	surfaceFromFile(filename, &s_tank[1]);
	filename = FILEPATH + "data/images/sprites/objects/energy_balancer.png";
	surfaceFromFile(filename, &energy_balancer);

	filename = FILEPATH + "data/images/tilesets/explosion_32.png";
	surfaceFromFile(filename, &explosion32);
	filename = FILEPATH + "data/images/tilesets/explosion_16.png";
	surfaceFromFile(filename, &explosion16);

	filename = FILEPATH + "data/images/tilesets/dash_dust.png";
	surfaceFromFile(filename, &dash_dust);
	filename = FILEPATH + "data/images/tilesets/hit.png";
	surfaceFromFile(filename, &hit);

    filename = FILEPATH + "data/images/tilesets/water_splash.png";
	surfaceFromFile(filename, &water_splash);

    filename = FILEPATH + "data/images/sprites/objects/armor_arms.png";
    surfaceFromFile(filename, &armor_icon_arms);

    filename = FILEPATH + "data/images/sprites/objects/armor_body.png";
    surfaceFromFile(filename, &armor_icon_body);

    filename = FILEPATH + "data/images/sprites/objects/armor_legs.png";
    surfaceFromFile(filename, &armor_icon_legs);

}

void graphicsLib::update_surface_colormap(SDL_Surface *display_surface, SDL_Color set_colormap[])
{
#ifdef WIN32
    SDL_SetColors(display_surface, set_colormap, 0, COLOR_COUNT);
#else
    SDL_SetPalette(display_surface, SDL_LOGPAL, set_colormap, 0, COLOR_COUNT);
#endif
}

void graphicsLib::update_surface_colormap(graphicsLib_gSurface *display_surface)
{
    update_surface_colormap(display_surface->gSurface, colormap);
}



void graphicsLib::show_btn_a(st_position btn_pos)
{
    showSurfaceAt(&_btn_a_surface, btn_pos, false);
}

void graphicsLib::set_screen_adjust(st_position adjust)
{
    _screen_adjust.x = adjust.x;
    _screen_adjust.y = adjust.y;
}





// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void graphicsLib::preload_faces() const {

	/// @TODO: do this from directory listing
	/*
	string filename;
	int i;

	for (i=0; i<FACES_COUNT; i++) {
		filename = FILEPATH + "data/images/faces/" + face_name[i];
		surfaceFromFile(filename, FACES_SURFACES[i]);
	}
	*/
}

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void graphicsLib::unload_faces() const {
	/*
	std::map<std::string, graphicsLib_gSurface>::iterator it;

	for (it = FACES_SURFACES.begin(); it != FACES_SURFACES.end(); it++) {
		delete (*it).second;
		FACES_SURFACES.erase(it);
	}
	*/
}



//void stage_select::place_face(int face_n, char botname[20], short int posx, short int posy) {
void graphicsLib::place_face(std::string face_file, st_position pos) {
	if (face_file == "") {
		return;
	}
	std::map<std::string, graphicsLib_gSurface>::iterator it;

	it = FACES_SURFACES.find(face_file);

	if (it == FACES_SURFACES.end()) {
		std::string filename = FILEPATH + "data/images/faces/" + face_file;
		surfaceFromFile(filename, &FACES_SURFACES[face_file]);
	}
	copyArea(st_position(pos.x, pos.y), &FACES_SURFACES[face_file], &gameScreen);
}

void graphicsLib::change_surface_color(st_color key, st_color new_color, struct graphicsLib_gSurface* surface)
{
	if (!surface->gSurface) {
		return;
	}
    SDL_Color new_colormap[COLOR_COUNT];
	for (int i=0; i<COLOR_COUNT; i++) {
        new_colormap[i] = surface->gSurface->format->palette->colors[i];
    }
    Uint32 key_n = SDL_MapRGB(tileset->format, key.r, key.g, key.b);
    if (key_n > COLOR_COUNT) {
        return;
    }
    //std::cout << "key_n: " << key_n << std::endl;
	new_colormap[key_n].r = new_color.r;
	new_colormap[key_n].g = new_color.g;
    new_colormap[key_n].b = new_color.b;
    update_surface_colormap(surface->gSurface, new_colormap);
}

void graphicsLib::change_surface_color(int key_n, st_color new_color, graphicsLib_gSurface *surface)
{
    if (key_n > COLOR_COUNT || key_n < 0) {
        return;
    }
    SDL_Color new_colormap[COLOR_COUNT];
    for (int i=0; i<COLOR_COUNT; i++) { // copy current colormap
        new_colormap[i] = surface->gSurface->format->palette->colors[i];
    }
    //std::cout << "change_surface_color.key_n: " << key_n << std::endl;
    new_colormap[key_n].r = new_color.r;
    new_colormap[key_n].g = new_color.g;
    new_colormap[key_n].b = new_color.b;
    update_surface_colormap(surface->gSurface, new_colormap);
}




void graphicsLib::wait_and_update_screen(int period)
{
	unsigned int wait_time = timer.getTimer()+period;
	while (timer.getTimer() < wait_time) {
		updateScreen();
		timer.delay(10);
	}
}

st_position graphicsLib::get_config_menu_pos() const
{
	return _config_menu_pos;
}

st_size graphicsLib::get_config_menu_size()
{
	return st_size(config_menu.width, config_menu.height);
}




void graphicsLib::set_colormap_white(graphicsLib_gSurface *surface)
{
    update_surface_colormap(surface->gSurface, colormap_white);
}

void graphicsLib::set_colormap_original(graphicsLib_gSurface *surface)
{
    update_surface_colormap(surface->gSurface, colormap_original);
}

void graphicsLib::set_colormap_current(graphicsLib_gSurface *surface)
{
    update_surface_colormap(surface->gSurface, colormap);
}

void graphicsLib::set_colormap_current_tileset()
{
    update_surface_colormap(tileset, colormap);
}

void graphicsLib::set_colormap_original_tileset()
{
    update_surface_colormap(tileset, colormap_original);
}



void graphicsLib::start_stars_animation()
{
    init_stars();
    _show_stars = true;
}


void graphicsLib::stop_stars_animation()
{
    _show_stars = false;
}

void graphicsLib::update_colors()
{
    _must_set_colors = true;
}

