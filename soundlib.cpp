#include <cstdlib>
#include "soundlib.h"

extern string FILEPATH;

#include "file/format.h"
extern struct CURRENT_FILE_FORMAT::st_game_config game_config;

soundLib::soundLib() : _repeated_sfx_channel(-1), _repeated_sfx(-1)
{
	music = NULL;
	boss_music = NULL;
}

soundLib::~soundLib()
{
	close_audio();
}

void soundLib::init_audio_system()
{
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024) < 0) {
        std::cout << "Couldn't open audio. Error: " << SDL_GetError() << std::endl;
        std::fflush(stdout);
        exit(-1);
    } else {
        std::cout << "Audio initialized" << std::endl;
    }
	load_all_sfx();
}


void soundLib::play_sfx(int sfx) {
	if (game_config.sound_enabled == false) {
        return;
	}

	if (sfx_list[sfx] != NULL) {
        Mix_PlayChannel(-1, sfx_list[sfx], 0);
	} else {
		cout << "Error: soundLib::play_sfx - null sfx\n";
	}
}

void soundLib::play_repeated_sfx(int sfx, int loops) {
	if (game_config.sound_enabled == false) {
        return;
	}

    if (sfx_list[sfx] != NULL) {
		if (is_playing_repeated_sfx()) {
			stop_repeated_sfx();
		}
		_repeated_sfx = sfx;
		_repeated_sfx_channel = Mix_PlayChannel(-1, sfx_list[sfx], loops);
    } else {
        cout << "Error: soundLib::play_sfx - null sfx\n";
	}
}

void soundLib::stop_repeated_sfx()
{
    //std::cout << ">>>>>> soundLib::stop_repeated_sfx._repeated_sfx_channel: " << _repeated_sfx_channel << std::endl;
    if (_repeated_sfx_channel == -1) {
        return;
    }
	Mix_HaltChannel(_repeated_sfx_channel);
	_repeated_sfx = -1;
	_repeated_sfx_channel = -1;
}

bool soundLib::is_playing_repeated_sfx() const
{
	if (_repeated_sfx_channel == -1) {
		return false;
	}
	return true;
}

int soundLib::get_repeated_sfx_n() const
{
	return _repeated_sfx;
}


void soundLib::play_timed_sfx(int sfx, int time) {
	if (game_config.sound_enabled == false) {
        return;
	}

	if (sfx_list[sfx] != NULL) {
		Mix_PlayChannelTimed(-1, sfx_list[sfx], -1 , time);
	}
}

// must follow the oders defined in enum SFX_LIST (types.h)
void soundLib::load_all_sfx() {
	int i = 0;
	string filename;

	filename = FILEPATH + "data/sfx/npc_hit.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/npc_killed.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/player_hit.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/player_shot.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/player_jump.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/cursor.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/stage_selected.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/got_energy_pill.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/got_item.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/shot_reflected.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/door_open.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/got_weapon.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/teleport.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/implosion.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/player_death.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/destrin_ship.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/train_chunk.wav";
	sfx_list[i] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/skull_castle_intro.wav";
	sfx_list[SFX_SKULL_CASTLE_INTRO] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/charged_shot.wav";
	sfx_list[SFX_PLAYER_CHARGED_SHOT] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/charging1.wav";
	sfx_list[SFX_CHARGING1] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/charging2.wav";
	sfx_list[SFX_CHARGING2] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/big_explosion.wav";
	sfx_list[SFX_BIG_EXPLOSION] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/water_enter.wav";
	sfx_list[SFX_WATER_ENTER] = Mix_LoadWAV(filename.c_str());
	i++;

	filename = FILEPATH + "data/sfx/water_leave.wav";
	sfx_list[SFX_WATER_LEAVE] = Mix_LoadWAV(filename.c_str());
	i++;


    filename = FILEPATH + "data/sfx/disappearning_block.wav";
    sfx_list[SFX_DISAPPEARING_BLOCK] = Mix_LoadWAV(filename.c_str());
    i++;

    filename = FILEPATH + "data/sfx/hadouken_girl.wav";
    sfx_list[SFX_HADOUKEN_GIRL] = Mix_LoadWAV(filename.c_str());
    i++;

    filename = FILEPATH + "data/sfx/shoryuken_girl.wav";
    sfx_list[SFX_SHORYUKEN_GIRL] = Mix_LoadWAV(filename.c_str());
    i++;

    filename = FILEPATH + "data/sfx/beam.wav";
    sfx_list[SFX_BEAM] = Mix_LoadWAV(filename.c_str());
    i++;



    /*
    for (int j=0; j<i; j++) {
        Mix_VolumeChunk(sfx_list[j], MIX_MAX_VOLUME);
    }
    */
    Mix_Volume(-1, MIX_MAX_VOLUME);

    // preload boss music
}



void soundLib::load_music(std::string music_file) {
	string filename;

	unload_music();
	filename = FILEPATH + "data/music/" + music_file;
    //std::cout << "soundLib::load_music - filename: " << filename << std::endl;
	music = Mix_LoadMUS(filename.c_str());
	if (!music) {
        std::cout << "Error in soundLib::load_music::Mix_LoadMUS('" << filename << "': '" << Mix_GetError() << "'\n";
        std::fflush(stdout);
		exit(-1);
	}
}

void soundLib::load_boss_music(string music_file) {
	string filename;

	if (boss_music != NULL) {
		Mix_HaltMusic();
		Mix_FreeMusic(boss_music);
        boss_music = NULL;
	}
	filename = FILEPATH + "data/music/" + music_file;
	//std::cout << "soundLib::load_boss_music - filename: " << filename << std::endl;
	boss_music = Mix_LoadMUS(filename.c_str());
	if (!boss_music) {
        std::cout << "Error in soundLib::load_boss_music::Mix_LoadMUS('" << filename << "': '" << Mix_GetError() << "'\n";
        std::fflush(stdout);
		exit(-1);
	}
}

void soundLib::unload_music()
{
	if (music != NULL) {
		Mix_HaltMusic();
		Mix_FreeMusic(music);
		music = NULL;
	}
}



void soundLib::play_music() {
	if (game_config.sound_enabled == false) {
        return;
	}
	// toca a música
	if (music) {
		if (Mix_PlayMusic(music, -1) == -1) {
            std::cout << "<<<<<<<<<<<<< Mix_PlayMusic Error: " << Mix_GetError() << std::endl;
            std::fflush(stdout);
			exit(-1);
		}
        //std::cout << "SOUNDLIB::play_music" << std::endl;
        //Mix_VolumeMusic(MIX_MAX_VOLUME/2);
	} else {
		std::cout << ">> play_music ERROR: music is null" << std::endl;
	}
}

void soundLib::play_boss_music() {
	if (game_config.sound_enabled == false) {
        return;
	}
	// toca a música
	if (boss_music) {
		if (Mix_PlayMusic(boss_music, -1) == -1) {
            std::cout << "<<<<<<<<<<<<< Mix_PlayMusic, Error: " << Mix_GetError() << std::endl;
            std::fflush(stdout);
			exit(-1);
		}
        //std::cout << "SOUNDLIB::play_boss_music" << std::endl;
        //Mix_VolumeMusic(MIX_MAX_VOLUME/2);
	} else {
		printf(">> play_boss_music ERROR: boss_music is null\n");
	}
}

void soundLib::load_stage_music(std::string filename) {
    //std::cout << "soundLib::load_stage_music - filename: " << filename << std::endl;
    if (filename.length() > 0) {
        load_music(filename);
	} else {
        std::cout << "soundLib::load_stage_music - USE DEFAULT" << std::endl;
		load_music("bgmusic.mod");
    }
}

void soundLib::restart_music()
{
    //std::cout << "SOUNDLIB::restart_music" << std::endl;
    Mix_HaltMusic();
    play_music();
}


void soundLib::stop_music() const {
    //std::cout << "SOUNDLIB::stop_music" << std::endl;
	Mix_HaltMusic();
}

void soundLib::close_audio() {
	Mix_FreeMusic(music);
	Mix_CloseAudio();
}

void sound_loop() {}

void soundLib::disable_sound() const
{
    game_config.sound_enabled = false;
	stop_music();
}

void soundLib::enable_sound()
{
	game_config.sound_enabled = true;
	play_music();
}

