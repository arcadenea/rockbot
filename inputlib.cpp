#include "inputlib.h"

#include <SDL/SDL_joystick.h>

extern SDL_Event event;

#include "timerlib.h"
extern timerLib timer;

#include "graphicslib.h"
extern graphicsLib graphLib;

#include "game.h"
extern game gameControl;

extern CURRENT_FILE_FORMAT::st_game_config game_config;

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
inputLib::inputLib() : _used_keyboard(false)
{
	for (int i=0; i<BTN_COUNT; i++) {
		p1_input[i] = 0;
		p2_input[i] = 0;
	}
    _show_btn_debug = false;
}

void inputLib::init_joystick()
{
	SDL_JoystickEventState(SDL_ENABLE);
	joystick1 = SDL_JoystickOpen(0);
    joystick2 = SDL_JoystickOpen(1);
// gamecube controller init
#ifdef WII
    for (int i=7; i>= 4; i--) {
        SDL_Joystick *joy = SDL_JoystickOpen(i);
        if (joy) {
            printf(">>>>>>>>>>>>>>>>>> init controller #%d <<<<<<<<<<<<<<<<<<<<<<\n", i);
        }
    }
#endif
}

// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void inputLib::clean()
{
	for (int i=0; i<BTN_COUNT; i++) {
		p1_input[i] = 0;
		p2_input[i] = 0;
	}
    while (SDL_PollEvent(&event)) {
        SDL_PumpEvents(); // check keyboard events
    }

}


// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //

void inputLib::readInput()
{
    _used_keyboard = false;
    while (SDL_PollEvent(&event)) {

        if (_show_btn_debug == false) {
            _show_btn_debug = true;
        }

        if (game_config.input_type == INPUT_TYPE_DOUBLE || game_config.input_type == INPUT_TYPE_KEYBOARD) {
            if (event.type == SDL_KEYDOWN) {
                for (int i=0; i<BTN_COUNT; i++) {
                    if (game_config.keys_codes[i] != -1 && game_config.keys_codes[i] == event.key.keysym.sym) {
                        p1_input[i] = 1;
                        _used_keyboard = true;
                        if (i == BTN_JUMP) {
                            p1_input[BTN_JUMP_TIMER] = timer.getTimer();
                        }
                    }
                }
            } else if (event.type == SDL_KEYUP) {
                for (int i=0; i<BTN_COUNT; i++) {
                    if (game_config.keys_codes[i] != -1 && game_config.keys_codes[i] == event.key.keysym.sym) {
                        p1_input[i] = 0;
                        _used_keyboard = true;
                        if (i == BTN_JUMP) {
                            p1_input[BTN_JUMP_TIMER] = 0;
                        }
                    }
                }
            }
            SDL_PumpEvents(); // check keyboard events
#if !defined(PLAYSTATION2) && !defined(PSP) && !defined(WII) && !defined(DREAMCAST)
            if (event.type == SDL_QUIT) {
                std::cout << "LEAVE #1" << std::endl;
                std::fflush(stdout);
                gameControl.leave_game();
            }
#endif
        }
        if (_used_keyboard == true) { // next commands are all joystick only
            return;
        }
        if (game_config.input_type == INPUT_TYPE_DOUBLE || game_config.input_type == INPUT_TYPE_JOYSTICK) {
            if (event.type == SDL_JOYBUTTONDOWN) {
                //std::cout << "#1 INPUT::readInput - joystick button[" << (int)event.jbutton.button << "] pressed." << std::endl;
                for (int i=0; i<BTN_COUNT; i++) {
                    //std::cout << "#1 INPUT::readInput - button_codes[" << i << "]: " << game_config.button_codes[i] << std::endl;
                    if (game_config.button_codes[i] != -1 && game_config.button_codes[i] == event.jbutton.button) {
                        //std::cout << "#1 INPUT::readInput - FOUND ACTION for i: " << i << std::endl;
                        p1_input[i] = 1;
                        if (i == BTN_JUMP) {
                            p1_input[BTN_JUMP_TIMER] = timer.getTimer();
                        }
                        //break;
                    }
                }
            } else if (event.type == SDL_JOYBUTTONUP) {
                //std::cout << "#2 INPUT::readInput - joystick button[" << event.jbutton.button << "] released" << std::endl;
                for (int i=0; i<BTN_COUNT; i++) {
                    if (game_config.button_codes[i] != -1 && game_config.button_codes[i] == event.jbutton.button) {
                        p1_input[i] = 0;
                        if (i == BTN_JUMP) {
                            p1_input[BTN_JUMP_TIMER] = 0;
                        }
                        break;
                    }
                }
            }
        }
        if ((game_config.input_mode == INPUT_MODE_ANALOG || game_config.input_mode == INPUT_MODE_DOUBLE) && event.type == SDL_JOYAXISMOTION) {
            if (event.jaxis.axis == 0) {
                if (event.jaxis.value < -JOYVAL) {
                    p1_input[BTN_RIGHT] = 0;
                    p1_input[BTN_LEFT] = 1;
                    _used_keyboard = false;
                } else if (event.jaxis.value > JOYVAL) {
                    p1_input[BTN_RIGHT] = 1;
                    p1_input[BTN_LEFT] = 0;
                    _used_keyboard = false;
                } else if ((event.jaxis.value < JOYVAL || event.jaxis.value > -JOYVAL) && _used_keyboard == false) {
                    p1_input[BTN_RIGHT] = 0;
                    p1_input[BTN_LEFT] = 0;
                }
            }
            if (event.jaxis.axis == 1) {
                if (event.jaxis.value < -JOYVAL) {
                    p1_input[BTN_DOWN] = 0;
                    p1_input[BTN_UP] = 1;
                    _used_keyboard = false;
                } else if (event.jaxis.value > JOYVAL) {
                    p1_input[BTN_DOWN] = 1;
                    p1_input[BTN_UP] = 0;
                    _used_keyboard = false;
                } else if ((event.jaxis.value < JOYVAL || event.jaxis.value > -JOYVAL) && _used_keyboard == false) {
                    p1_input[BTN_DOWN] = 0;
                    p1_input[BTN_UP] = 0;
                }
            }
        }
        if ((game_config.input_mode == INPUT_MODE_DIGITAL || game_config.input_mode == INPUT_MODE_DOUBLE) && event.type == SDL_JOYHATMOTION) {
            // CODES: up - 1, right: 2, down: 4, left: 8
#ifdef DREAMCAST

            if (event.jhat.value == 14) { // up

                p1_input[BTN_DOWN] = 0;
                p1_input[BTN_UP] = 1;
                _used_keyboard = false;
            }
            if (event.jhat.value == 13) { // right
                p1_input[BTN_RIGHT] = 1;
                p1_input[BTN_LEFT] = 0;
                _used_keyboard = false;
            }
            if (event.jhat.value == 11) { // down
                p1_input[BTN_DOWN] = 1;
                p1_input[BTN_UP] = 0;
                _used_keyboard = false;
            }
            if (event.jhat.value == 7) { // left
                p1_input[BTN_LEFT] = 1;
                p1_input[BTN_RIGHT] = 0;
                _used_keyboard = false;
            }
            if (event.jhat.value == 15 && _used_keyboard == false) {
                p1_input[BTN_LEFT] = 0;
                p1_input[BTN_RIGHT] = 0;
                p1_input[BTN_DOWN] = 0;
                p1_input[BTN_UP] = 0;
            }

#else

            if (event.jhat.value == 1 || event.jhat.value == 3 || event.jhat.value == 9) { // up
                p1_input[BTN_DOWN] = 0;
                p1_input[BTN_UP] = 1;
                _used_keyboard = false;
            }
            if (event.jhat.value == 2 || event.jhat.value == 3 || event.jhat.value == 6) { // right
                p1_input[BTN_RIGHT] = 1;
                p1_input[BTN_LEFT] = 0;
                _used_keyboard = false;
            }
            if (event.jhat.value == 4 || event.jhat.value == 6 || event.jhat.value == 12) { // down
                p1_input[BTN_DOWN] = 1;
                p1_input[BTN_UP] = 0;
                _used_keyboard = false;
            }
            if (event.jhat.value == 8 || event.jhat.value == 9 || event.jhat.value == 12) { // left
                p1_input[BTN_LEFT] = 1;
                p1_input[BTN_RIGHT] = 0;
                _used_keyboard = false;
            }
            if (event.jhat.value == 0 && _used_keyboard == false) {
                p1_input[BTN_LEFT] = 0;
                p1_input[BTN_RIGHT] = 0;
                p1_input[BTN_DOWN] = 0;
                p1_input[BTN_UP] = 0;
            }

#endif
        }
    }
}



// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
void inputLib::waitTime(int wait_period) const {
    /*
#ifdef PLAYSTATION2
    if (wait_period < 20) {
        return;
    }
#endif
    */
	int now_time=0;
	now_time = timer.getTimer();
	wait_period = now_time + wait_period;
	while (now_time < wait_period) {
		now_time = timer.getTimer();
		SDL_Delay(1);
		#ifdef PLAYSTATION
			RotateThreadReadyQueue(_MIXER_THREAD_PRIORITY);
		#endif
        graphLib.updateScreen();
	}
}


// ********************************************************************************************** //
//                                                                                                //
// ********************************************************************************************** //
int inputLib::waitScapeTime(int wait_period) {
	int now_time = 0;

	waitTime(50);
	now_time = timer.getTimer();
	wait_period = now_time + wait_period;

	while (now_time < wait_period) {
		readInput();
		if (p1_input[BTN_START] == 1 || p2_input[BTN_START] == 1) {
			return 1;
        } else if (p1_input[BTN_QUIT] == 1 || p2_input[BTN_QUIT] == 1) {
#if !defined(PLAYSTATION2) && !defined(PSP) && !defined(WII) && !defined(DREAMCAST)
            std::cout << "LEAVE #2" << std::endl;
            std::fflush(stdout);
            gameControl.leave_game();
#endif
		}
		now_time = timer.getTimer();
		#ifdef PLAYSTATION
			RotateThreadReadyQueue(_MIXER_THREAD_PRIORITY);
		#endif
        SDL_Delay(5);
	}
	return 0;
}

void inputLib::wait_keypress()
{
    bool fim = false;
    while (!fim) {
        readInput();
		if (p1_input[BTN_START] == 1 || p2_input[BTN_JUMP] == 1 || p1_input[BTN_JUMP] == 1 || p2_input[BTN_JUMP]) {
            fim = true;
        }
        graphLib.updateScreen();
        waitTime(50);
    }
    clean();
}

// returns false for keyboard, true for joysticks
bool inputLib::pick_key_or_button(CURRENT_FILE_FORMAT::st_game_config &game_config_copy, INPUT_COMMANDS key)
{
    clean();
    waitTime(50);
    while (true) { // keep reading until a key is found
        while (SDL_PollEvent(&event)) {
            if (game_config.input_type == INPUT_TYPE_DOUBLE || game_config.input_type == INPUT_TYPE_KEYBOARD) {
                if (event.type == SDL_KEYDOWN) {
                    std::cout << "BEFORE keys_codes[" << key << "]: " << game_config_copy.keys_codes[key] << std::endl;
                    game_config_copy.keys_codes[key] = event.key.keysym.sym;
                    std::cout << "AFTER keys_codes[" << key << "]: " << game_config_copy.keys_codes[key] << std::endl;
                    return false;
                }
                SDL_PumpEvents();
            }
            if (game_config.input_type == INPUT_TYPE_DOUBLE || game_config.input_type == INPUT_TYPE_JOYSTICK) {
                if (event.type == SDL_JOYBUTTONDOWN) {
                    game_config_copy.button_codes[key] = event.jbutton.button;
                    return true;
                }
            }
        }
        waitTime(5);
    }
    return false;
}
