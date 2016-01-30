#ifndef CLASSNPC_H
#define CLASSNPC_H

#include <string>
#include "character.h"
#include "file/format.h"
#include "character/artificial_inteligence.h"

class classPlayer;


/**
 * @brief
 *
 */
struct npc_frameset {
    int frameset;				// holds information about the type of this frame /**< TODO */
    unsigned int frameset_time;		// the number of milisseconds this frame leasts /**< TODO */
    struct st_size framesize; /**< TODO */
};




/**
 * @brief
 *
 */
class classnpc : public artificial_inteligence
{
public:
	classnpc();
    ~classnpc();
/**
 * @brief
 *
 * @param set_name
 */
    classnpc(std::string set_name);
/**
 * @brief
 *
 * @param stage_id
 * @param map_id
 * @param main_id
 * @param id
 */
    classnpc(int stage_id, int map_id, int main_id, int id); // load data from game_data and create a new npc
/**
 * @brief
 *
 * @param stage_id
 * @param map_id
 * @param main_id
 * @param npc_pos
 * @param direction
 */
    classnpc(int stage_id, int map_id, int main_id, st_position npc_pos, short int direction, bool player_friend); // spawned npc
    /**
     * @brief
     *
     */
    /**
     * @brief
     *
     * @return bool
     */
    void initFrames();
    /**
     * @brief
     *
     */
    void execute();
    /**
     * @brief
     *
     * @param from
     */
    void copy(classnpc *from);
    /**
     * @brief
     *
     */
    void move();
    /**
     * @brief
     *
     */
    void move_projectiles();
    /**
     * @brief
     *
     * @return bool
     */
    virtual bool is_boss();

    /**
     * @brief
     *
     * @param set_boss
     */
    void set_is_boss(bool set_boss);
    /**
     * @brief
     *
     * @return bool
     */
    bool is_player_friend();
    /**
     * @brief
     *
     */
    void set_stage_boss(bool boss_flag);
    /**
     * @brief
     *
     */
    void revive();
    /**
     * @brief
     *
     * @return short
     */
    short get_dead_state();
    /**
     * @brief
     *
     * @return st_rectangle
     */
    st_rectangle get_hit_area();

    bool is_able_to_fly();

    bool is_spawn();

    bool is_subboss();

    void reset_position();

    st_position get_start_position();




protected:
    /**
     * @brief
     *
     */
    void death();
    /**
     * @brief
     *
     */
    void invert_direction();
    /**
     * @brief
     *
     * @param stage_id
     * @param map_id
     * @param main_id
     */
    void build_basic_npc(int stage_id, int map_id, int main_id);



protected:
	// W A R N I N G -----------------> new members must be reflected in copy() method
    short int facing;									// defines the side npc is facing before start moving (also used by LINEWALK behavior) /**< TODO */
    std::string graphic_filename;						// graphic file used on it /**< TODO */
    bool first_run; /**< TODO */
    bool _is_player_friend;								// player spawned npcs must not hit him, but other npcs instead /**< TODO */
    bool _is_spawn;                                     // indicates that is a spawn, so won't drop items, etc

};

#endif // CLASSNPC_H
