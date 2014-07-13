#ifndef KEY_MAP_H
#define KEY_MAP_H

#include <string>
#include <vector>


/**
 * @brief
 *
 */
class key_map
{
public:
/**
 * @brief
 *
 */
    key_map();
    /**
     * @brief
     *
     */


    /**
     * @brief
     *
     */
    void config_input() const;


private:
    /**
     * @brief
     *
     */
    void draw_screen();
    /**
     * @brief
     *
     * @param line
     */
    void redraw_line(short line) const;

    int draw_config_keys() const;




private:
    std::vector<std::string> _keys_list; /**< TODO */
};

#endif // KEY_MAP_H
