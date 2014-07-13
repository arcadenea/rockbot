#ifndef CLASSMAP_H
#define CLASSMAP_H


#include "defines.h"
#include "st_common.h"
#include "graphicslib.h"
#include "character/classnpc.h"
#include "objects/object.h"
#include "graphic/animation.h"
#include <list>
#include <vector>

#define EXPLOSION_ANIMATION_TIME 50

class classPlayer; // forward declaration

class character;

/**
 * @brief
 *
 */
struct object_colision {
    int _block;
    object* _object;
	object_colision(int set_block, object* set_object) {
		_block = set_block;
		_object = set_object;
	}
    object_colision() {
        _block = 0;
        _object = NULL;
    }
};

struct water_bubble {
    st_position pos;
    float x_adjust;
    int x_adjust_direction;
    unsigned int timer;
};


struct st_level3_tile {
    st_position tileset_pos;
    st_position map_position;
    st_level3_tile(st_position set_tileset_pos, st_position set_map_position)
    {
        tileset_pos = set_tileset_pos;
        map_position = set_map_position;
    }
    st_level3_tile()
    {
        tileset_pos = st_position(0, 0);
        map_position = st_position(0, 0);
    }

};


/**
 * @brief
 *
 */
class classMap
{
public:
	classMap();
    /**
     * @brief
     *
     */
    ~classMap();
    /**
     * @brief
     *
     * @param theElement
     * @return bool
     */
    static bool deleteAll( classMap* theElement );
    /**
     * @brief
     *
     * @param int
     */
    /**
     * @brief
     *
     */
    void setStageNumber(int);

    /**
     * @brief
     *
     * @return short
     */
    short get_number() const;
    /**
     * @brief
     *
     * @param int
     */
    void setMapNumber(int);
    /**
     * @brief
     *
     */
    void loadMap();
    /**
     * @brief
     *
     */
    void drawMap();
    /**
     * @brief
     *
     */
    void showMap();
    /**
     * @brief
     *
     * @param scroll_y
     */
    void showAbove(int scroll_y=0, int temp_scroll_x = -99999);
    /**
     * @brief
     *
     * @param pos
     * @return bool
     */
    bool is_point_solid(st_position pos) const;
    /**
     * @brief
     *
     * @param pos
     * @return int
     */
    int getMapPointLock(st_position pos) const;
    /**
     * @brief
     *
     * @param x
     * @return bool
     */
    bool get_map_point_wall_lock(int x) const;
    /**
     * @brief
     *
     * @param pos
     * @param check_lock
     */
    void changeScrolling(st_position pos, bool check_lock=true);
    /**
     * @brief
     *
     * @return st_position
     */
    st_position getMapScrolling() const;
    /**
     * @brief
     *
     * @return st_position
     */
    st_position get_last_scrolled() const;
    /**
     * @brief
     *
     */
    void reset_scrolled();
    /**
     * @brief
     *
     */
    void load_map_objects();



    int colision_rect_player_obj(character* playerObj, object* temp_obj, const short int x_inc, const short int y_inc, short int reduce_x, short int reduce_y, const short obj_xinc, const short obj_yinc);

    /**
     * @brief
     *
     * @param
     * @param short
     * @param short
     * @param short
     * @param short
     * @return object_colision
     */
    void colision_player_object(character*, const short int, const short int, short int, short int);
    /**
     * @brief
     *
     * @param
     * @param short
     * @param short
     * @param short
     * @param short
     * @return short
     */


    object_colision get_obj_colision();

    short int colision_player_npcs(character*, const short int, const short int, short int, short int);
    /**
     * @brief
     *
     */

    classnpc* find_nearest_npc(st_position pos);
    /**
     * @brief
     *
     */

    void clean_map_npcs_projectiles();
    /**
     * @brief
     *
     * @return graphicsLib_gSurface
     */
    graphicsLib_gSurface* get_map_surface();
    /**
     * @brief
     *
     * @param pos
     */
    void set_scrolling(st_position pos);

    void reset_scrolling();

    /**
     * @brief
     *
     * @param move_x
     * @param move_y
     */
    void move_map(const short int move_x, const short int move_y);
    /**
     * @brief
     *
     */
    void clean_map();
    /**
     * @brief
     *
     */
    void reset_map();
    /**
     * @brief
     *
     * @param is_close
     * @param nTiles
     * @param tileX
     * @param player_number
     */
    void redraw_boss_door(bool is_close, int nTiles, int tileX, int tileY, short player_number);
    /**
     * @brief
     *
     * @param pos_type
     * @param surface
     * @param pos
     * @param adjust_pos
     * @param frame_time
     * @param repeat_times
     * @param direction
     * @param framesize
     */
    void add_animation(ANIMATION_TYPES pos_type, graphicsLib_gSurface* surface, const st_float_position &pos, st_position adjust_pos, unsigned int frame_time, unsigned int repeat_times, int direction, st_size framesize);
    /**
     * @brief
     *
     */
    void clear_animations(); // remove all animations from map
    /**
     * @brief
     *
     * @param player_list
     */
    void set_player_list(std::vector<classPlayer*> player_list);
    /**
     * @brief
     *
     * @param npc_id
     * @param npc_pos
     * @param direction
     */
    classnpc *spawn_map_npc(short int npc_id, st_position npc_pos, short direction, bool player_friend, bool progressive_span);
    /**
     * @brief
     *
     */
    void move_npcs();
    /**
     * @brief
     *
     */
    void show_npcs();
    /**
     * @brief
     *
     */
    void move_objects();


    void show_objects();
    /**
     * @brief
     *
     * @return bool
     */
    bool boss_hit_ground();
    /**
     * @brief
     *
     */
    void reset_map_npcs();
    /**
     * @brief
     *
     * @param surface
     */
    void draw_dynamic_backgrounds_into_surface(graphicsLib_gSurface &surface, int x_adjust, int y_adjust);
    /**
     * @brief
     *
     * @param obj
     */
    void add_object(object obj);
    /**
     * @brief
     *
     * @param x_pos
     * @return int
     */
    int get_first_lock_on_left(int x_pos) const;

    /**
     * @brief
     *
     * @param x_pos
     * @return int
     */
    int get_first_lock_on_right(int x_pos) const;


    /**
     * @brief
     *
     * @param pos
     */
    void drop_item(st_position pos);

    void set_bg1_scroll(int scrollx);
    void set_bg2_scroll(int scrollx);
    int get_bg1_scroll() const;
    int get_bg2_scroll() const;

    void reset_objects_timers();

    // restore objects to their original position
    void reset_objects();

    void print_objects_number();


    void add_bubble_animation(st_position pos);

    bool have_player_object();

private:
    /**
     * @brief
     *
     */
    void load_map_npcs();
    /**
     * @brief
     *
     */
    void draw_dynamic_backgrounds();
    /**
     * @brief
     *
     * @param value
     * @param min
     * @param max
     * @return bool
     */
    bool value_in_range(int value, int min, int max) const;

    /**
     * @brief
     *
     */
    void create_dynamic_background_surfaces();

    /**
     * @brief
     *
     */
    void create_dynamic_background_surface(graphicsLib_gSurface& dest_surface, graphicsLib_gSurface& image_surface) const;

public:
    std::vector<classnpc*> _npc_list; // vector npcs
    std::vector<classPlayer*> _player_list; // vector players
    std::vector<animation> animation_list;
	// vector teleporters
	// vector objects
    int number;

private:
    int stage_number;
    graphicsLib_gSurface mapSurface;
    struct st_position scroll;
    st_position scrolled;						// stores the value the map scrolled in this cycle. used for character movement control (it should move taking the scroll in account)
    std::vector<object> object_list;
    bool wall_scroll_lock[MAP_W];
    float bg1_scroll;
    float bg2_scroll;
    graphicsLib_gSurface bg1_surface;
    graphicsLib_gSurface bg2_surface;
    short _platform_leave_counter;
    water_bubble _water_bubble;
    st_rectangle _3rd_level_ignore_area;
    object_colision _obj_colision;
    std::vector<st_level3_tile> _level3_tiles;
    bool _break_npc_loop;                       // used to prevent looping through the npc list after adding a new one (needed because using vector instead of list, because of old-Dingux crashes)
};



#endif // CLASSMAP_H
