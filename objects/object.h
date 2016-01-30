#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <map>
#include "graphicslib.h"

class classMap; // forward declaration


enum e_object_teleport_states {
    e_object_teleport_state_initial,
    e_object_teleport_state_teleport_in,
    e_object_teleport_state_waiting,
    e_object_teleport_state_teleport_out
};

/**
 * @brief
 *
 */
class object
{
public:
	//object(int id, struct format_v_2_1::file_object temp_obj); // game object constructor
    object(int _id, classMap *set_map, st_position map_pos, st_position teleporter_dest, int map_dest); // map object constructor
    ~object();
    /**
     * @brief
     *
    */
    void reset();
    /**
     * @brief
     *
     */
    void show(int adjust_y=0, int adjust_x=0);


    void show_vertical_ray(int adjust_y=0);
    void show_horizontal_ray(int adjust_y=0);
    void show_track_platform(int adjust_y=0);

    void show_deathray_vertical(int adjust_y=0);
    void show_deathray_horizontal(int adjust_y=0);

    /**
     * @brief
     *
     */
    void move(bool paused);

    void reset_animation();

    void stop();

    /**
     * @brief
     *
     */
    void execute(bool paused);


    /**
     * @brief
     *
     * @return st_position
     */
    st_position get_position() const;


    st_rectangle get_area();

    /**
     * @brief
     *
     * @return st_size
     */
    st_size get_size();
    /**
     * @brief
     *
     * @return short
     */
    short int get_type() const;


    short int get_id() const;

    /**
     * @brief
     *
     * @return int
     */
    int get_direction() const;
    /**
     * @brief
     *
     * @param int
     */
    void set_direction(int);
    /**
     * @brief
     *
     * @return int
     */
    int get_distance() const;
    /**
     * @brief
     *
     * @param int
     */
    void set_distance(int);
    /**
     * @brief
     *
     * @param int
     */
    void set_timer(int);
    /**
     * @brief
     *
     * @return unsigned int
     */
    unsigned int get_timer() const;
    /**
     * @brief
     *
     * @return bool
     */
    bool finished() const;
    /**
     * @brief
     *
     * @param is_finished
     */
    void set_finished(bool is_finished);
    /**
     * @brief
     *
     */
    void invert_direction_x();
    /**
     * @brief
     *
     */
    void invert_direction_y();
    /**
     * @brief
     *
     * @param obj_state
     */
    void set_state(short obj_state);
    /**
     * @brief
     *
     * @return short
     */
    short get_state() const;
    /**
     * @brief
     *
     * @param duration
     */
    void set_duration(int duration);
    /**
     * @brief
     *
     */
    void start();
    /**
     * @brief
     *
     */
    void command_up();															// some objects can be controlled by the player
    /**
     * @brief
     *
     */
    void command_down();														// some objects can be controlled by the player
    /**
     * @brief
     *
     * @return std::string
     */
    std::string get_name() const;
    /**
     * @brief
     *
     * @return bool
     */
    bool is_hidden() const;
    /**
     * @brief
     *
     * @return bool
     */
    bool is_started() const;
    /**
     * @brief
     *
     * @return bool
     */
    bool is_on_screen();

    bool is_on_visible_screen();


    void set_colision_mode(enum colision_modes colision_mode); // if player uses this as platform, move him

    enum colision_modes get_colision_mode() const;

    void reset_timers();

    void use_teleport_in_out();                                 // when called, will se object to be teleported in/out

    bool is_consumable();                                       // if item is a energy, tank, life, that player can get


    void set_precise_position(st_position pos, int direction);                                // used to get a fine-tuning positioning instead of map-position

    void remove_graphic();

    st_position get_boss_teleporter_dest();

    int get_boss_teleport_map_dest();

    int get_obj_map_id();

    void set_obj_map_id(int id);


private:
    /**
     * @brief
     *
     */
    void add_graphic();
    /**
     * @brief
     *
     */
    void gravity();
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
     */
    void check_player_move(int xinc, int yinc) const; // if player uses this as platform, move him




private:
    unsigned int _id;
    std::string name;
    std::string graphic_filename;												// graphic file used on it
    short int type;
    unsigned int obj_timer;														// used as time for disapearing block
    unsigned int _obj_frame_timer;
    int speed;																	// used as speed for moving platform
    int limit;																	// used as range (pixels) for moving platform, visible time for disapearing block
    int direction;																// used to check if moving away from oiginalpoint or moving to it
    int distance;
    int framesize_w;
    int framesize_h;
    int frame;																	// indicates what is the used frame
    struct st_position start_point;
    struct st_position position;
    classMap *map;																// reference to the map this object is in
    bool _started;																// some object types will only start to act/move after player interaction
    unsigned int _start_timer;                                                           // holds the time of the activation (used for initial delay)
    bool _finished;																// indicates to map->show() that the object must be deleted
    short _state;
    unsigned int _duration;
    unsigned int _timer_limit;
    bool _command_up;
    bool _command_down;
    bool _animation_finished;
    bool _animation_reversed;
    bool _hidden;
    enum colision_modes _colision_mode;
    bool _must_play_appearing_sfx;                                              // used by disappearing blocks to play the sfx just once
    bool _must_teleport_in;                                                     // if set, the object will teleport in when added and out when finished
    int _teleport_state;                                                        // used to control when start/finish the teleport
    st_position _boss_teleporter_dest;
    int _boss_teleporter_map_dest;
    int _obj_map_id;                                                            // used for map-objects, so we can get them in stage_data.objects[N]
    bool _expanding;
    int _size;
};

#endif // OBJECT_H
