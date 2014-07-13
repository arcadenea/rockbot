#include "draw.h"

#define RAIN_DELAY 160

extern graphicsLib graphLib;

#include "timerlib.h"
extern timerLib timer;

extern CURRENT_FILE_FORMAT::file_game game_data;

#include "game.h"
extern game gameControl;

#include "inputlib.h"
extern inputLib input;


draw::draw() : _rain_pos(0), _rain_timer(0), _rain_enabled(false)
{
}

void draw::preload()
{
    std::string filename = FILEPATH + "data/images/tilesets/ready.png";
    graphLib.surfaceFromFile(filename, &ready_message);

    filename = FILEPATH + "data/images/sprites/teleport_small.png";
    graphLib.surfaceFromFile(filename, &_teleport_small_gfx);

    // DROPABLE OBJECT GRAPHICS
    for (int i=0; i<GAME_MAX_OBJS; i++) {
        for (int j=0; j<DROP_ITEM_COUNT; j++) {
            short obj_type_n = gameControl.get_drop_item_id(j);
            if (obj_type_n != -1) {
                get_object_graphic(obj_type_n);
            }
        }
    }
}

void draw::update_screen()
{
    if (_rain_enabled == true) {
        show_rain();
    }
    graphLib.updateScreen();
}

void draw::update_colorcycle() const
{
    graphLib.execute_colorcycle();
}

void draw::set_rain_enabled(bool enabled)
{
    _rain_enabled = enabled;
}

void draw::show_rain()
{
    if (rain_obj.gSurface == NULL) {
        // load rain
        std::string filename = FILEPATH + "/data/images/tilesets/rain.png";
        graphLib.surfaceFromFile(filename, &rain_obj);
    }
    for (int i=0; i<MAP_W; i++) {
        for (int j=0; j<MAP_H; j++) {
            graphLib.showSurfaceRegionAt(&rain_obj, st_rectangle(_rain_pos*TILESIZE, 0, TILESIZE, TILESIZE), st_position(i*TILESIZE, j*TILESIZE));
        }
    }
    if (timer.getTimer() > _rain_timer) {
        _rain_pos++;
        if (_rain_pos > 2) {
            _rain_pos = 0;
        }
        _rain_timer = timer.getTimer() + RAIN_DELAY;
    }
}

void draw::show_boss_intro_sprites(short boss_id, bool show_fall)
{
    UNUSED(show_fall);
    unsigned int intro_frames_n = 0;
    //int intro_frames_rollback = 0;
    st_position boss_pos(20, -37);
    st_position sprite_size;
    graphicsLib_gSurface bgCopy, boss_graphics;


    std::string graph_filename = FILEPATH + "data/images/sprites/enemies/" + std::string(game_data.game_npcs[boss_id].graphic_filename);
    sprite_size.x = game_data.game_npcs[boss_id].frame_size.width;
    sprite_size.y = game_data.game_npcs[boss_id].frame_size.height;
    graphLib.surfaceFromFile(graph_filename.c_str(), &boss_graphics);

    graphLib.initSurface(st_size(RES_W, RES_H), &bgCopy);
    graph_filename = FILEPATH + "data/images/backgrounds/stage_boss_intro.png";
    graphLib.surfaceFromFile(graph_filename.c_str(), &bgCopy);
    st_position bg_pos(0, (RES_H/2)-(bgCopy.height/2));
    graphLib.copyArea(bg_pos, &bgCopy, &graphLib.gameScreen);

    update_screen();

    int sprite_pos_y = RES_H/2 - sprite_size.y/2;

    for (int i=0; i<ANIM_FRAMES_COUNT; i++) {
        if (game_data.game_npcs[boss_id].sprites[ANIM_TYPE_INTRO][i].used == true) {
            intro_frames_n++;
        }
    }

    // fall into position
    while (boss_pos.y < sprite_pos_y) {
        boss_pos.y += 4;
        graphLib.copyArea(bg_pos, &bgCopy, &graphLib.gameScreen);
        graphLib.copyArea(st_rectangle(0, 0, sprite_size.x, sprite_size.y), st_position(boss_pos.x, boss_pos.y), &boss_graphics, &graphLib.gameScreen);
        graphLib.wait_and_update_screen(5);
    }
    graphLib.wait_and_update_screen(500);


    // show intro sprites
    if (intro_frames_n > 1) {
        for (int i=0; i<ANIM_FRAMES_COUNT; i++) {
            if (game_data.game_npcs[boss_id].sprites[ANIM_TYPE_INTRO][i].used == true) {
                //std::cout << "i: " << i << ", used: " << game_data.game_npcs[boss_id].sprites[ANIM_TYPE_INTRO][i].used << ", duration: " << game_data.game_npcs[boss_id].sprites[ANIM_TYPE_INTRO][i].duration << std::endl;
                graphLib.copyArea(bg_pos, &bgCopy, &graphLib.gameScreen);
                graphLib.copyArea(st_rectangle(sprite_size.x * game_data.game_npcs[boss_id].sprites[ANIM_TYPE_INTRO][i].sprite_graphic_pos_x, 0, sprite_size.x, sprite_size.y), st_position(boss_pos.x, boss_pos.y), &boss_graphics, &graphLib.gameScreen);
                graphLib.wait_and_update_screen(game_data.game_npcs[boss_id].sprites[ANIM_TYPE_INTRO][i].duration);
            }
        }
    } else { // just frow first sprite
        graphLib.copyArea(bg_pos, &bgCopy, &graphLib.gameScreen);
        graphLib.copyArea(st_rectangle(0, 0, sprite_size.x, sprite_size.y), st_position(boss_pos.x, boss_pos.y), &boss_graphics, &graphLib.gameScreen);
        graphLib.wait_and_update_screen(200);
    }
}

void draw::show_ready()
{
    st_position dest_pos((RES_W/2)-26, (RES_H/2)-6);
    graphLib.copyArea(dest_pos, &ready_message, &graphLib.gameScreen);
    graphLib.updateScreen();
}

void draw::show_bubble(int x, int y)
{
    if (_bubble_gfx.gSurface == NULL) {
        std::string filename = FILEPATH + "/data/images/tilesets/bubble.png";
        graphLib.surfaceFromFile(filename, &_bubble_gfx);
    }
    graphLib.showSurfaceAt(&_bubble_gfx, st_position(x, y), false);
}

void draw::reset_teleporter_colors()
{
    graphLib.reset_image_colormap(_teleport_small_gfx);
}

void draw::set_teleport_small_colors(st_color color1, st_color color2)
{
    graphLib.change_surface_color(graphLib.get_colorkey_n(COLOR_KEY_GREEN), color1, &_teleport_small_gfx);
    graphLib.change_surface_color(graphLib.get_colorkey_n(COLOR_KEY_PURPLE), color2, &_teleport_small_gfx);
}

void draw::show_teleport_small(int x, int y)
{
    graphLib.showSurfaceAt(&_teleport_small_gfx, st_position(x+_teleport_small_gfx.width/2, y+_teleport_small_gfx.height/2), false);
}

void draw::show_credits()
{
    int line_n=0;
    unsigned int scrolled=0;
    int posY = -RES_H;
    st_rectangle dest;
    graphicsLib_gSurface credits_surface;

    graphLib.initSurface(st_size(RES_W, RES_H+12), &credits_surface);
    graphLib.blank_surface(credits_surface);
    graphLib.blank_screen();


    // add the initial lines to screen
    create_credits_text(credits_surface);

    update_screen();

    // scroll the lines
    while (scrolled < (credits_list.size()*12)+RES_H/2+46) {
        graphLib.copyArea(st_rectangle(0, posY, RES_W, RES_H), st_position(0, 0), &credits_surface, &graphLib.gameScreen);
        update_screen();
        timer.delay(60);
        posY++;
        scrolled++;
        if (posY > 12) {
            graphLib.copyArea(st_rectangle(0, posY, credits_surface.width, RES_H), st_position(0, 0), &credits_surface, &credits_surface);
            // scroll the lines
            dest.x = 0;
            dest.y = RES_H;
            dest.w = RES_W;
            dest.h = 12;
            graphLib.blank_area(dest.x, dest.y, dest.w, dest.h, credits_surface);
            draw_credit_line(credits_surface, line_n+21);
            posY = 0;
            line_n++;
        }
    }
    update_screen();
}

void draw::create_credits_text(graphicsLib_gSurface &surface)
{
    if (credits_list.size() > 0) {
        return;
    }
    credits_list.push_back("--- COPYRIGHT NOTICE ---");
    credits_list.push_back("MEGAMAN AND ROCKMAN ARE TRADEMARKS");
    credits_list.push_back("OF CAPCOM INC. SOME OF THE GRAPHICS");
    credits_list.push_back("AND SOUND EFFECTS USED IN THIS GAME");
    credits_list.push_back("ARE PROPERTY OF CAPCOM INC.");
    credits_list.push_back("");
    credits_list.push_back("THIS FANGAME IS A TRIBUTE TO MEGAMAN,");
    credits_list.push_back("FREE AND OPEN-SOURCE");
    credits_list.push_back("");
    credits_list.push_back("WE THANK CAPCOM FOR CREATING MEGAMAN");
    credits_list.push_back("AND ITS CLASSIC GAMES, ALSO FOR");
    credits_list.push_back("BEING FRIENDLY TOWARDS FANGAMES.");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");


    credits_list.push_back("--- PLANNER ---");
    credits_list.push_back("IURI FIEDORUK");
    credits_list.push_back("");


    credits_list.push_back("--- CHARACTER DESIGN ---");
    credits_list.push_back("IURI FIEDORUK");
    credits_list.push_back("ARIS KSF");
    credits_list.push_back("");

    credits_list.push_back("--- PIXEL GRAPHICS ---");
    credits_list.push_back("IURI FIEDORUK");
    credits_list.push_back("GIO AKIRA FAGANELLO");
    credits_list.push_back("RODRIGO M. HAHN");
    credits_list.push_back("HUNTER TRAMMELL");
    credits_list.push_back("BOBERATU");
    credits_list.push_back("PROF. CHRIS");
    credits_list.push_back("");


    credits_list.push_back("--- DERIVATED GRAPHICS ---");
    credits_list.push_back("CAPCOM");
    credits_list.push_back("");


    credits_list.push_back("--- ILLUSTRATION ---");
    credits_list.push_back("IURI FIEDORUK");
    credits_list.push_back("ARIS KSF");
    credits_list.push_back("");

    credits_list.push_back("--- MUSIC COMPOSE ---");
    credits_list.push_back("MODARCHIVE.ORG");
    credits_list.push_back("");

    credits_list.push_back("--- SOUND EFFECTS ---");
    credits_list.push_back("CAPCOM");
    credits_list.push_back("");


    credits_list.push_back("--- PROGRAMMER ---");
    credits_list.push_back("IURI FIEDORUK");
    credits_list.push_back("DEMETRIO NETO");
    credits_list.push_back("");

    credits_list.push_back("--- PORTING ---");
    credits_list.push_back("DINGUX: SHIN-NIL");
    credits_list.push_back("PANDORA: SIGMA NL");
    credits_list.push_back("PS2: RAGNAROK2040");
    credits_list.push_back("PS2: WOON-YUNG LIU");
    credits_list.push_back("PS2: SP193");
    credits_list.push_back("ANDROID: PELYA");
    credits_list.push_back("");

    credits_list.push_back("--- TESTING ---");
    credits_list.push_back("IURI FIEDORUK");
    credits_list.push_back("ARIS KSF");
    credits_list.push_back("LUIS AGUIRRE");
    credits_list.push_back("BENOITREN (PSP)");
    credits_list.push_back("BATANEN (PSP)");
    credits_list.push_back("SAIYAN X (PSP)");
    credits_list.push_back("AGENT 13 (PS2)");
    credits_list.push_back("MK2ESCORT (PS2)");
    credits_list.push_back("FOUADTJUHMASTER (ANDROID)");
    credits_list.push_back("");

    credits_list.push_back("--- SPECIAL THANKS ---");
    credits_list.push_back("FREE SDK DEVELOPERS");
    credits_list.push_back("LIBSDL PORTERS");
    credits_list.push_back("DEVIANTART COMMUNITY");
    credits_list.push_back("PIXELJOIN COMMUNITY");
    credits_list.push_back("VENOM");
    credits_list.push_back("JERONIMO");
    credits_list.push_back("");

    credits_list.push_back("--- DEVELOPMENT TOOLS ---");
    credits_list.push_back("LIBSDL");
    credits_list.push_back("LIBQT4");
    credits_list.push_back("DIGIA QT");
    credits_list.push_back("QT CREATOR");
    credits_list.push_back("UBUNTU LINUX");
    credits_list.push_back("GIMP");
    credits_list.push_back("PAINT TOOL SAI");
    credits_list.push_back("COREL DRAW");
    credits_list.push_back("SIMPLE SCREEN RECORD");

    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("");
    credits_list.push_back("--- PRESENTED BY ---");
    credits_list.push_back("UPPERLAND STUDIOS");
    credits_list.push_back("GREENNEKO WEB & DESIGN");

    for (unsigned int i=0; i<=RES_H/12 && i<credits_list.size(); i++) {
        std::size_t found = credits_list.at(i).find("--- ");
        if (found != std::string::npos) {
            graphLib.draw_centered_text(12*i, credits_list.at(i), surface, st_color(95, 151, 255));
        } else {
            graphLib.draw_centered_text(12*i, credits_list.at(i), surface, st_color(235, 235, 235));
        }
    }
}


void draw::draw_credit_line(graphicsLib_gSurface &surface, unsigned short initial_line)
{
    if (initial_line < credits_list.size()) {
        std::size_t found = credits_list.at(initial_line).find("--- ");
        if (found != std::string::npos) {
            graphLib.draw_centered_text(RES_H, credits_list.at(initial_line), surface, st_color(95, 151, 255));
        } else {
            graphLib.draw_centered_text(RES_H, credits_list.at(initial_line), surface, st_color(235, 235, 235));
        }
    }
}














graphicsLib_gSurface *draw::get_object_graphic(int obj_id)
{
    std::map<unsigned int, graphicsLib_gSurface>::iterator it;
    graphicsLib_gSurface temp_sprite;

    it = objects_sprite_list.find(obj_id);
    if (it == objects_sprite_list.end()) { // there is no graphic with this key yet, add it
        std::string graphic_filename(game_data.objects[obj_id].graphic_filename);
        std::string complete_filename(FILEPATH + "data/images/sprites/objects/" + graphic_filename);
        graphLib.surfaceFromFile(complete_filename, &temp_sprite);
        objects_sprite_list.insert(std::pair<unsigned int, graphicsLib_gSurface>(obj_id, temp_sprite));
    } else {
        return &(*it).second;
    }
}

void draw::remove_object_graphic(int obj_id)
{
    std::map<unsigned int, graphicsLib_gSurface>::iterator it;
    it = objects_sprite_list.find(obj_id);
    if (it != objects_sprite_list.end()) {
        objects_sprite_list.erase(obj_id);
    }
}

void draw::show_ingame_warning(std::vector<std::string> message)
{
    graphLib.show_dialog(0, true);
    st_position dialog_pos = graphLib.get_dialog_pos();
    for (unsigned int i=0; i<message.size(); i++) {
        graphLib.draw_text(dialog_pos.x+20, dialog_pos.y+16+(12*i), message[i]);
    }
    input.clean();
    input.wait_keypress();
}


