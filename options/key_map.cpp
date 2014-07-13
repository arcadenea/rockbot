#include "key_map.h"

#include "graphicslib.h"
extern graphicsLib graphLib;

#include "inputlib.h"
extern inputLib input;

#include "soundlib.h"
extern soundLib soundManager;

#include "graphic/draw.h"
extern draw draw_lib;

#include "graphic/option_picker.h"

#include "defines.h"


extern CURRENT_FILE_FORMAT::st_game_config game_config;

key_map::key_map()
{
    _keys_list.push_back(std::string("JUMP: "));
    _keys_list.push_back(std::string("SHOT: "));
    _keys_list.push_back(std::string("DASH: "));
    _keys_list.push_back(std::string("SHIELD: "));
    _keys_list.push_back(std::string("L: "));
    _keys_list.push_back(std::string("R: "));
    _keys_list.push_back(std::string("START: "));
}


void key_map::draw_screen()
{
    bool finished = false;
    st_position config_text_pos;
    st_position cursor_pos;
    short _pick_pos = 0;

    config_text_pos.x = graphLib.get_config_menu_pos().x + 74;
    config_text_pos.y = graphLib.get_config_menu_pos().y + 40;
    cursor_pos = config_text_pos;

    graphLib.clear_area(config_text_pos.x-1, config_text_pos.y-1, 180,  180, 0, 0, 0);
    input.clean();
    input.waitTime(300);

    for (unsigned int i=0; i<_keys_list.size(); i++) {
        graphLib.draw_text(config_text_pos.x, config_text_pos.y + i*CURSOR_SPACING, _keys_list[i].c_str());
        redraw_line(i);
    }
    graphLib.draw_text(config_text_pos.x, config_text_pos.y + _keys_list.size()*CURSOR_SPACING, "RETURN");
    draw_lib.update_screen();

    //cout << "scenesLib::option_picker::START\n";
    graphLib.drawCursor(st_position(cursor_pos.x-CURSOR_SPACING, cursor_pos.y+(_pick_pos*CURSOR_SPACING)));

    while (finished == false) {
        input.readInput();
        if (input.p1_input[BTN_START]) {
            if (_pick_pos == (short)_keys_list.size()) {
                std::cout << "key_map::draw_screen - FINISHED #1" << std::endl;
                finished = true;
            } else {
                graphLib.draw_text(config_text_pos.x, config_text_pos.y + _keys_list.size()*CURSOR_SPACING+CURSOR_SPACING*2, "PRESS NEW KEY/BUTTON"); //input code (number)
                draw_lib.update_screen();
                //format_v_2_1_1::st_key_config new_key = input.get_pressed_key();
                graphLib.clear_area(config_text_pos.x, config_text_pos.y + _keys_list.size()*CURSOR_SPACING+CURSOR_SPACING*2-1, 180,  CURSOR_SPACING+1, 0, 0, 0);
                ///@TODO - key_config[_pick_pos].key_type = new_key.key_type;
                ///@TODO - key_config[_pick_pos].key_number = new_key.key_number;
                redraw_line(_pick_pos);
                draw_lib.update_screen();
            }
        }
        if (input.p1_input[BTN_DOWN]) {
                soundManager.play_sfx(SFX_CURSOR);
                graphLib.eraseCursor(st_position(cursor_pos.x-CURSOR_SPACING, cursor_pos.y+(_pick_pos*CURSOR_SPACING)));
                _pick_pos++;
                if (_pick_pos >= (short)_keys_list.size()+1) {
                    _pick_pos = 0;
                }
                graphLib.drawCursor(st_position(cursor_pos.x-CURSOR_SPACING, cursor_pos.y+(_pick_pos*CURSOR_SPACING)));
        }
        if (input.p1_input[BTN_UP]) {
                soundManager.play_sfx(SFX_CURSOR);
                graphLib.eraseCursor(st_position(cursor_pos.x-CURSOR_SPACING, cursor_pos.y+(_pick_pos*CURSOR_SPACING)));
                _pick_pos--;
                if (_pick_pos < 0) {
                    _pick_pos = _keys_list.size();
                }
                graphLib.drawCursor(st_position(cursor_pos.x-CURSOR_SPACING, cursor_pos.y+(_pick_pos*CURSOR_SPACING)));
        }
        if (input.p1_input[BTN_QUIT]) {
            std::cout << "key_map::draw_screen - FINISHED #2" << std::endl;
            finished = true;
        }
        input.clean();
        input.waitTime(10);
        draw_lib.update_screen();
    }
}

void key_map::redraw_line(short line) const
{
    std::cout << "******* key_map::redraw_line - line: " << line << std::endl;
    st_position config_text_pos;
    config_text_pos.x = graphLib.get_config_menu_pos().x + 74;
    config_text_pos.y = graphLib.get_config_menu_pos().y + 40;
    graphLib.clear_area(config_text_pos.x+70-1, config_text_pos.y-1 + line*CURSOR_SPACING, 110,  CURSOR_SPACING+1, 0, 0, 0);
    ///@TODO -
    /*
    if (key_config[line].key_type == 0) {
        graphLib.draw_text(config_text_pos.x + 70, config_text_pos.y + line*CURSOR_SPACING, "JOYSTICK"); // input type (joystick/keyboard)
    } else {
        graphLib.draw_text(config_text_pos.x + 70, config_text_pos.y + line*CURSOR_SPACING, "KEYBOARD"); // input type (joystick/keyboard)
    }
    */

    std::stringstream key_n_ss;
    ///@TODO - key_n_ss << key_config[line].key_number;

    graphLib.draw_text(config_text_pos.x + 140, config_text_pos.y + line*CURSOR_SPACING, key_n_ss.str()); //input code (number)
}














int key_map::draw_config_keys() const
{
    st_position config_text_pos;
    config_text_pos.x = graphLib.get_config_menu_pos().x + 74;
    config_text_pos.y = graphLib.get_config_menu_pos().y + 40;
    input.clean();
    input.waitTime(100);
    input.clean();
    input.waitTime(100);

    graphLib.clear_area(config_text_pos.x, config_text_pos.y, 180,  180, 0, 0, 0);
    std::vector<std::string> options;
    options.push_back("RESET TO DEFAULT");
    options.push_back("SET JUMP");
    options.push_back("SET ATTACK");
    options.push_back("SET SHIELD");
    options.push_back("SET DASH");
    options.push_back("SET L");
    options.push_back("SET R");
    options.push_back("SET START");

    // -- NEW -- //
    if (game_config.input_mode == INPUT_MODE_DIGITAL) {
        options.push_back("DIRECTIONAL: DIGITAL");
    } else {
        options.push_back("DIRECTIONAL: ANALOG");
    }
    // -- NEW --//



    short selected_option = 0;
    option_picker main_config_picker(false, config_text_pos, options, true);
    selected_option = main_config_picker.pick();
    std::cout << "key_map::draw_config_keys - selected_option: " << selected_option << std::endl;
    return selected_option;
}





void key_map::config_input() const
{

    int selected_option = 0;
    while (selected_option != -1) {
        selected_option = draw_config_keys();

        std::cout << "key_map::config_input - selected_option: " << selected_option << std::endl;

        if (selected_option == 0) {
            game_config.set_default_keys();
            std::cout << "key_map::config_input - LEAVE #1" << std::endl;
        } else if (selected_option == -1) {
            std::cout << "key_map::config_input - LEAVE #2" << std::endl;
            return;

        // -- NEW -- //
        } else if (selected_option == 8) {
            if (game_config.input_mode == INPUT_MODE_DIGITAL) {
                game_config.input_mode = INPUT_MODE_ANALOG;
            } else {
                game_config.input_mode = INPUT_MODE_DIGITAL;
            }
        // -- NEW -- //


        } else {
            std::cout << "key_map::config_input - PICK KEY #1" << std::endl;
            INPUT_COMMANDS selected_key = BTN_JUMP;
            if (selected_option == 1) {
                selected_key = BTN_JUMP;
            } else if (selected_option == 2) {
                selected_key = BTN_ATTACK;
            } else if (selected_option == 3) {
                selected_key = BTN_SHIELD;
            } else if (selected_option == 4) {
                selected_key = BTN_DASH;
            } else if (selected_option == 5) {
                selected_key = BTN_L;
            } else if (selected_option == 6) {
                selected_key = BTN_R;
            } else if (selected_option == 7) {
                selected_key = BTN_START;
            }

            st_position menu_pos(graphLib.get_config_menu_pos().x + 74, graphLib.get_config_menu_pos().y + 40);
            graphLib.clear_area(menu_pos.x, menu_pos.y, 180,  180, 0, 0, 0);
            graphLib.draw_text(menu_pos.x, menu_pos.y, "PRESS A KEY OR BUTTON");
            input.clean();
            input.waitTime(20);
            std::cout << "key_map::config_input - PICK KEY #2" << std::endl;
            input.pick_key_or_button(selected_key);
            std::cout << "key_map::config_input - PICK KEY #3" << std::endl;
        }
    }
}





