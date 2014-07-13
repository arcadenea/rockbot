#ifndef ENUM_NAMES_H
#define ENUM_NAMES_H

#include <vector>

std::vector<std::string> PROJECTILE_TRAJECTORIES_NAMES = {
	std::string("TRAJECTORY_LINEAR"),
	std::string("TRAJECTORY_ARC"),
    std::string("TRAJECTORY_SIN"),
	std::string("TRAJECTORY_CHAIN"),
	std::string("TRAJECTORY_QUAKE"),
	std::string("TRAJECTORY_BOMB"),
	std::string("TRAJECTORY_FOLLOW"),
	std::string("TRAJECTORY_PROGRESSIVE"),
	std::string("TRAJECTORY_FREEZE"),
	std::string("TRAJECTORY_DIAGONAL_UP"),
	std::string("TRAJECTORY_DIAGONAL_DOWN"),
	std::string("TRAJECTORY_CENTERED"),
	std::string("TRAJECTORY_ZIGZAG"),
    std::string("TRAJECTORY_TARGET_DIRECTION"),
    std::string("TRAJECTORY_ARC_TO_TARGET"),
    std::string("TRAJECTORY_TARGET_EXACT"),
    std::string("TRAJECTORY FALL BOMB")
};


std::vector<std::string> AI_ACTION_NAMES = {
	// from basic AI types
	std::string("WALK"), // OPTION LEFT, RIGHT, TO-PLAYER, TO-SAVED-POINT
	std::string("FLY"), // OPTION LEFT, RIGHT, UP, DOWN, TO-PLAYER, TO-SAVED-POINT
	std::string("JUMP"), // OPTION UP, LEFT, RIGHT, TO-PLAYER, TO-ROOF
	std::string("WAIT UNTIL PLAYER IS IN RANGE"),
	std::string("SAVE POINT"),
	// from boss AI
	std::string("SHOT PROJECTILE #1"),
	std::string("SHOT PROJECTILE #2"),
	std::string("SHOT PROJECTILE #1 (INVERT DIRECTION)"),
	std::string("AIR WALK"), // OPTIONS LEFT, RIGHT, TO-PLAYER
	std::string("FALL TO GROUND"),
	std::string("TELEPORT"), // OPTIONS LEFT, RIGHT, TO-PLAYER
	std::string("DASH"), // OPTION LEFT, RIGHT, PLAYER
	std::string("GRAB WALL"), // OPTIONS LEFT, RIGHT
    std::string("SPAWN NPC") // OPTIONS, in this case, is a list of NPCs
};


std::vector<std::string> AI_ACTION_SHOT_OPTIONS = {
    std::string("FACE PLAYER"),
    std::string("AHEAD")
};


std::vector<std::string> AI_ACTION_WALK_OPTIONS = {
    std::string("HORIZONTAL AHEAD"),
    std::string("HORIZONTAL TURN"),
	std::string("TO PLAYER"),
    std::string("TO SAVED POINT"),
    std::string("TURN TO PLAYER"),
};

std::vector<std::string> AI_ACTION_FLY_OPTIONS = {
    std::string("AHEAD"),
    std::string("TURN"),
	std::string("UP"),
	std::string("DOWN"),
	std::string("TO PLAYER"),
    std::string("TO SAVED POINT"),
    std::string("TO RANDOM POINT"),
    std::string("FALL"),
    std::string("DRILL DOWN"),
    std::string("VERTICAL CENTER"),
    std::string("PLAYER DIRECTION"),
    std::string("TO OPOSITE WALL"),
    std::string("TO OPOSITE (SHOOT #1)"),
    std::string("TO PLAYER X"),
    std::string("TO PLAYER Y"),
    std::string("AHEAD [Y-ZIG-ZAG]"),
};


std::vector<std::string> AI_ACTION_JUMP_OPTIONS = {
    std::string("AHEAD"),
    std::string("TO RANDOM POINT"),
	std::string("UP"),
	std::string("TO PLAYER"),
	std::string("TO ROOF"),
    std::string("TO SAVED POINT"),
    std::string("JUMP ONCE AHEAD")
};


std::vector<std::string> AI_ACTION_AIR_WALK_OPTIONS = {
	std::string("LEFT"),
	std::string("RIGHT"),
	std::string("TO PLAYER")
};

std::vector<std::string> AI_ACTION_TELEPORT_OPTIONS = {
	std::string("LEFT"),
	std::string("RIGHT"),
    std::string("TO PLAYER"),
    std::string("RANDOM X"),
    std::string("RANDOM Y"),
    std::string("RANDOM POINT")
};

std::vector<std::string> AI_ACTION_DASH_OPTIONS = {
	std::string("LEFT"),
	std::string("RIGHT"),
	std::string("TO PLAYER")
};

std::vector<std::string> AI_ACTION_GRAB_WALL_OPTIONS = {
	std::string("LEFT"),
	std::string("RIGHT")
};

#endif // ENUM_NAMES_H
