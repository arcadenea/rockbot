#pragma GCC diagnostic ignored "-Wreorder"

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <map>

// local includes
#include "st_hitPoints.h"
#include "st_common.h"
#include "st_characterState.h"
#include "graphicslib.h"
#include "projectilelib.h"

extern graphicsLib graphLib; /**< TODO */

class object; // forward declaration

/**
 * @brief
 *
 */
enum ATTACK_STATES {
	ATTACK_NOT,
	ATTACK_START,
	ATTACK_WAIT
};

class classMap;		// advance declaration
struct object_colision;

/**
 * @brief
 *
 */
struct st_spriteFrame {
    unsigned short int delay; // time in milisseconds this frame will be shown /**< TODO */
    graphicsLib_gSurface frameSurface; /**< TODO */
	st_spriteFrame() {
		frameSurface.gSurface = NULL;
		delay = 20;
	}
    /**
     * @brief
     *
     * @param newDelay
     */
    void setDelay(int newDelay)
	{
		delay = newDelay;
	}
    /**
     * @brief
     *
     * @param newSurface
     */
    void setSurface(graphicsLib_gSurface newSurface)
	{
		graphLib.initSurface(st_size(newSurface.width, newSurface.height), &frameSurface);
		graphLib.copyArea(st_position(0, 0), &newSurface, &frameSurface);
	}
};


/**
 * @brief
 *
 */
struct st_characterMovements { // this instruction holds commands passed from player (joystick) and npc (AI) and is used to execute basic movements
    short up; /**< TODO */
    short down; /**< TODO */
    short left; /**< TODO */
    short right; /**< TODO */
    short attack; /**< TODO */
    short jump; /**< TODO */
    short start; /**< TODO */
    short dash; /**< TODO */
    short shield; /**< TODO */
	st_characterMovements()
	{
		up = 0;
		down = 0;
		left = 0;
		right = 0;
		attack = 0;
		jump = 0;
/**
 * @brief
 *
 */
        start = 0;
		dash = 0;
		shield = 0;
	}
};



/**
 * @brief
 *
 */
class character
{
public:
	character();
    /**
     * @brief
     *
     */
    /**
     * @brief
     *
     */
    virtual ~character();
    /**
     * @brief
     *
     * @param std::string
     */
    void setName(std::string);
    /**
     * @brief
     *
     * @return std::string
     */
    std::string getName(void) const;
    /**
     * @brief
     *
     * @param st_hit_points
     */
    void setHitPoints(st_hit_points);
    /**
     * @brief
     *
     */
    virtual void initFrames() = 0; // pure virtual
    /**
     * @brief
     *
     */
    virtual void execute() = 0; // pure virtual
    /**
     * @brief
     *
     * @return st_position
     */
    st_float_position getPosition() const;
    /**
     * @brief
     *
     * @return st_position
     */
    struct st_position get_real_position() const;
    /**
     * @brief
     *
     * @param st_position
     */
    void set_position(struct st_position);
    /**
     * @brief
     *
     * @param int
     * @param int
     * @param int
     * @param int
     * @param
     * @param int
     */
    void addSpriteFrame(int, int, int, int, graphicsLib_gSurface&, int);
    /**
     * @brief
     *
     * @param set_map
     */
    void set_map(classMap *set_map);
    /**
     * @brief
     *
     * @return classMap
     */
    classMap *get_map();
    /**
     * @brief
     *
     * @param set_player
     */
    void set_is_player(bool set_player);
    /**
     * @brief
     *
     * @return bool
     */
    bool is_player() const;
    /**
     * @brief
     *
     */
    void advance_frameset(); // changes the state for the next (or previous) frame
    /**
     * @brief
     *
     */
    void show();


    /**
     * @brief
     *
     */
    void show_sprite();

    /**
     * @brief
     *
     * @param direction
     * @param type
     * @param n
     */
    void show_sprite_graphic(short direction, short type, short n);

    /**
     * @brief
     *
     * @return st_size
     */
    st_size get_size() const;
    /**
     * @brief
     *
     * @param
     */
    void set_platform(object*);
    /**
     * @brief
     *
     * @return object
     */
    object* get_platform();
    /**
     * @brief
     *
     * @return int
     */
    int get_direction() const;
    /**
     * @brief
     *
     * @param direction
     */
    void set_direction(int direction);
    classMap *map;										// reference to the map this npc is in /**< TODO */
    /**
     * @brief
     *
     */
    void clean_projectiles();
    /**
     * @brief
     *
     */
    void char_update_real_position();
    /**
     * @brief
     *
     * @param damage_points
     */
    void damage(unsigned int damage_points, bool ignore_hit_timer);
    /**
     * @brief
     *
     * @return bool
     */
    bool is_dead() const;
    /**
     * @brief
     *
     * @return st_hit_points
     */
    st_hit_points get_hp() const;
    /**
     * @brief
     *
     * @return unsigned short
     */
    unsigned short int get_current_hp() const;
    /**
     * @brief
     *
     * @param inc
     */
    void set_current_hp(unsigned short int inc);
    /**
     * @brief
     *
     */
    void execute_jump();								// execute a complete jump
    /**
     * @brief
     *
     */
    void execute_jump_up();					// execute jump until reaches the maximum height
    /**
     * @brief
     *
     */
    void fall();								// falls until reaching ground or leaving screen /// @TODO
    /**
     * @brief
     *
     */
    void teleport_out();

    /**
     * @brief
     *
     * @param xinc
     * @param yinc
     * @return bool
     */
    bool change_position(short int xinc, short int yinc);


    /**
     * @brief
     *
     * @param xinc
     * @return bool
     */
    int change_position_x(short int xinc);

    /**
     * @brief
     *
     * @param yinc
     * @return bool
     */
    int change_position_y(short int yinc);

    /**
     * @brief
     *
     * @param xinc
     * @param yinc
     * @return bool
     */
    bool test_change_position(short int xinc, short int yinc);
    /**
     * @brief
     *
     * @param xinc
     * @param yinc
     * @return bool
     */
    bool test_change_position_debug(short int xinc, short int yinc);
    /**
     * @brief
     *
     * @param projectile_direction
     * @return bool
     */
    bool is_shielded(int projectile_direction) const;
    /**
     * @brief
     *
     * @return short
     */
    short get_anim_type() const;
    /**
     * @brief
     *
     * @param direction
     * @param type
     * @param frame
     * @return graphicsLib_gSurface
     */
    graphicsLib_gSurface* get_char_frame(int direction, int type, int frame);
    /**
     * @brief
     *
     * @param key_n
     * @return st_color
     */
    st_color get_color_key(short int key_n) const;
    /**
     * @brief
     *
     * @return short
     */
    short int get_number() const;
    /**
     * @brief
     *
     */
    void charMove();
    /**
     * @brief
     *
     */
    void clear_move_commands();
    /**
     * @brief
     *
     * @param boss_demo_mode
     * @return bool
     */
    bool gravity(bool boss_demo_mode);							// returns true if finished (reached ground)
    /**
     * @brief
     *
     * @return bool
     */
    const bool hit_ground() const;
    /**
     * @brief
     *
     * @return bool
     */

    bool will_hit_ground(int y_change) const;

    bool is_on_screen(); // indicates if the character is inside screen area
    /**
     * @brief
     *
     * @return bool
     */
    bool is_on_visible_screen(); // ignore if near, only return true for 0-RES_W
    /**
     * @brief
     *
     * @return bool
     */
    bool is_invisible() const;

    /**
     * @brief
     *
     */
    void activate_super_jump();
    /**
     * @brief
     *
     */
    void activate_force_jump();
    /**
     * @brief
     *
     * @return st_position
     */
    st_float_position *get_position_ref();
    /**
     * @brief
     *
     */
    void reset_jump();


    /**
     * @brief remove the first projectile from the list
     *
     */
    void consume_projectile();

    /**
     * @brief identifies if the player is using some kind of cicle weapon (TRAJECTORY_CENTERED), so enemy projectiles will damage the player projectile, not himself
     * @return bool true if using circle-type weapon
     */
    bool is_using_circle_weapon();


    void set_animation_type(enum ANIM_TYPE type);

    void set_show_hp(bool show);

    void set_progressive_appear_pos(int pos);

    void set_progressive_appear_direction(int direction);

    /**
     * @brief
     *
     * @return bool
     */
    bool is_stage_boss();

    void clean_character_graphics_list();


protected:
    /**
     * @brief
     *
     */
    virtual void attack(bool dont_update_colors = false);
    /**
     * @brief
     *
     * @param key
     * @param new_color
     * @param full_change
     */
    void change_char_color(st_color key, st_color new_color, bool full_change);

    /**
     * @brief
     *
     * @param mapScrolling
     * @return bool
     */
    bool slide(st_position mapScrolling);
    /**
     * @brief
     *
     * @param int
     * @param st_position
     * @return bool
     */
    bool jump(int, st_position);


    /**
     * @brief
     *
     * @param incx
     * @param incy
     * @param mapScrolling
     * @return short
     */
    short int map_colision(const short int incx, const short int incy, st_position mapScrolling);
    /**
     * @brief
     *
     * @param map_block
     * @param new_map_lock
     * @param mode_xy
     * @param map_pos
     */
    void check_map_colision_point(int &map_block, int &new_map_lock, int mode_xy, st_position map_pos) const;
    /**
     * @brief
     *
     * @param map_lock
     * @param incx
     * @param incy
     * @param map_pos
     * @return bool
     */
    bool process_special_map_points(int map_lock, int incx, int incy, st_position map_pos);

    /**
     * @brief
     *
     */
    void add_graphic();
    /**
     * @brief
     *
     */
    virtual void death() = 0;
    /**
     * @brief
     *
     * @return bool
     */
    bool have_frame_graphics();



    /**
     * @brief
     *
     * @return bool
     */
    bool have_background_graphics();
    /**
     * @brief
     *
     * @param direction
     * @param type
     * @param pos
     * @return bool
     */
    bool have_frame_graphic(int direction, int type, int pos);  // indicates if the given frame graphic exits
    /**
     * @brief
     *
     * @return bool
     */
    bool is_in_stairs_frame() const; // indicates if the character is on some of the STAIRS animation types
    /**
     * @brief
     *
     * @param _en_type
     * @param value
     */
    virtual void recharge(e_energy_types _en_type, int value);
    /**
     * @brief
     *
     * @param obj_info
     * @return bool
     */
    virtual bool get_item(object_colision& obj_info);
    /**
     * @brief
     *
     * @return unsigned int
     */
    unsigned int get_projectile_count(); // returns the number of projectiles (some special attacks count as max)
    /**
     * @brief
     *
     * @return int
     */
    int frames_count(); // find out the number of frames in the current direction/type
    /**
     * @brief
     *
     */
    void advance_to_last_frame();

    virtual void show_hp(); // player nad boss will implement this

    int is_executing_effect_weapon(); // returns type, or -1 if none




// members
public:
	// projectile list
    std::vector<projectile> projectile_list; /**< TODO */
	//struct st_spriteFrame sprite_list[ANIM_DIRECTION_COUNT][ANIM_TYPE_COUNT][ANIM_FRAMES_COUNT]; // TODO - move to protected


protected:
	// members static that can be moved to use game_data
    std::string name; /**< TODO */
    struct st_size frameSize; /**< TODO */
    int max_jump; // maximum reach of the jump /**< TODO */
    unsigned int max_projectiles; // maximum number of simultaneuous projectiles the character can shot /**< TODO */
    short move_speed; // how many pixels the character moves by cycle (default value) /**< TODO */
    short _fractional_move_speed; // indicates we need to move an extra pixel even "n" times
    short _fractional_move_speed_counter; // stores the value of times we moved, used by _fractional_move_speed above

	// dynamic members
    st_hit_points hitPoints; /**< TODO */
    unsigned int last_hit_time; /// time of last being hit /**< TODO */
    unsigned int hit_duration; /// time the character is intangible after being hit (in milisseconds) /**< TODO */
    unsigned int hit_animation_timer; /// used to control "blinking" effect when hit /**< TODO */
    st_float_position position; /**< TODO */
    st_position realPosition; /**< TODO */
    unsigned int last_execute_time; /**< TODO */
    struct st_characterMovements moveCommands; /**< TODO */

	// characteristics members
    float accel_speed_y; // used for acceleration in jump/gravity /**< TODO */
    float gravity_y; // used for acceleration in jump/gravity /**< TODO */
    float max_speed; // used for acceleration in jump/gravity /**< TODO */
    bool can_fly;                       // indicates if the character can fly in order to not be affected by gravity /**< TODO */
    bool _ignore_gravity;               // ignore gravity while this flag is true
    unsigned int attack_state; // indicates if the player is attacking and what is the stage of the attack /**< TODO */
    bool attack_button_released; // indicates if attack button was released between shots /**< TODO */
    int charging_color_n; // holds information used when changing char colors on charging shot /**< TODO */
    unsigned int charging_color_timer; // holds information used when changing char colors on charging shot /**< TODO */
    bool jump_button_released; // indicates if jump button was released between jumps /**< TODO */
    /**
     * @brief
     *
     * @param pos
     * @return st_position
     */
    st_position is_on_stairs(st_rectangle pos);		// check is character in over a staircase

	// control members
    st_characterState state; /**< TODO */
    bool is_player_type; // used for some small tweaks /**< TODO */


	// DEBUG
    int jump_steps; /**< TODO */
    int hit_moved_back_n; /**< TODO */
	// external members

	// TODO - graphics list map, used in order to avoid duplication of graphics
    static std::map<std::string, st_spriteFrame[ANIM_DIRECTION_COUNT][ANIM_TYPE_COUNT][ANIM_FRAMES_COUNT]> character_graphics_list; /**< TODO */
    static std::map<std::string, graphicsLib_gSurface> _character_graphics_background_list; /**< TODO */
    static std::map<std::string, bool> _character_have_right_graphic; /**< TODO */

    object* _platform; // used to move player when object moves /**< TODO */

    bool dead; /**< TODO */

    st_color color_keys[3]; /**< TODO */

    short int       shield_type;                        // same as for NPC, 0->no-shield, 1->full_shield, 2->front-shield /**< TODO */

    unsigned int    _moving_platform_timer;             // used to control character movement when is over a moving platform /**< TODO */

    int             _number;                            // used for player or npc_id /**< TODO */

    bool            _super_jump;                        // indicates if the jump is super high /**< TODO */
    bool            _force_jump;                        // when character is catapulted by an object, ignores jump button state until jump is finished (no matter if the jump button is released in the middle of jump, it will jump until reaching top) /**< TODO */
    std::string     _debug_char_name; /**< TODO */

    int             _teleport_minimal_y;                // do not stop teleport before reaching this point. (used on player's death) /**< TODO */

    int             _projectile_type_id;				// indicates the projectile ID (relation with file_projectile) /**< TODO */

    bool _is_falling; /**< TODO */

    int _dead_state; // 0 - alive, 1 - just died, 2 dead /**< TODO */
    short slide_type; // 0 - dash (24 px height), 1 - slide (16px height) /**< TODO */
    bool _water_splash;									// used to prevent making a new splash until completaly inside or outside water /**< TODO */
    bool _has_background; /**< TODO */
    st_position _frame_pos_adjust; /**< TODO */
    bool _have_right_direction_graphics; /**< TODO */
    short _stairs_stopped_count; // used to prevent stopping stairs animation because of a single frame without player input /**< TODO */
    float _jump_accel; // used to determine acceleration of jump. players use the jump_gravity property for this, NPCs can change this according to it's AI jump type
    int _touch_damage_reductor;
    short _charged_shot_projectile_id;
    short _hit_move_back_dist;
    bool _was_animation_reset;                               // inform that animation "looped" once
    bool _is_last_frame;
    bool _was_hit;                                           // indicates if the character was hit during the current cicle/loop
    short int _simultaneous_shots;                            // how many shots at a time the character can fire
    bool _is_boss;
    bool _show_hp;                                          // show or hide the HP bat
    bool _always_move_ahead;                                // indicates to character class that the AI is to always move on
    bool _check_always_move_ahead;                          // used to prevent setting _always_move_ahead each time we can AI exec
    int _progressive_appear_pos;                            // used by spawn-npc to show just a part of the NPC
    int _progressive_appear_direction;                      // direction the NPC will appear from-to
    bool _is_stage_boss;                                    // used in NPC class. Indicates if this is the stage-boss
    bool _dropped_from_stairs;                              // used to avoid grabbing stairs again when dropped from it

};

#endif // CHARACTER_H
