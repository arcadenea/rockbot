#ifndef FILE_IO_H
#define FILE_IO_H

#include "format.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#ifdef WII
#include <fat.h>
#endif


extern std::string FILEPATH; /**< TODO */


/**
 * @brief
 *
 */
class file_io
{
public:


};




namespace format_v_2_1_1 {
    /**
     * @brief
     *
     */
    class file_io
    {
    public:
/**
 * @brief
 *
 */
        file_io();
        /**
         * @brief
         *
         * @param data_out
         */
        void read_game(format_v_2_1_1::file_game& data_out) const;
        /**
         * @brief
         *
         * @param data_in
         */
        void write_game(format_v_2_1_1::file_game& data_in) const;

        /**
         * @brief
         *
         * @param stages_data_in
         */
        void write_all_stages(format_v_2_1_1::file_stages& stages_data_in) const;
        /**
         * @brief
         *
         * @param stages_data_out
         */
        void read_all_stages(format_v_2_1_1::file_stages& stages_data_out) const;
        /**
         * @brief
         *
         * @param stages_data_out
         * @param stage_n
         */
        void read_stage(format_v_2_0_3::file_stage& stages_data_out, short stage_n) const;
    };
}




namespace format_v_2_1_2 {
    /**
     * @brief
     *
     */
    class file_io
    {
    public:
/**
 * @brief
 *
 */
        file_io();
        /**
         * @brief
         *
         * @param data_out
         */
        void read_game(format_v_2_1_2::file_game& data_out) const;
        /**
         * @brief
         *
         * @param data_in
         */
        void write_game(format_v_2_1_2::file_game& data_in) const;

        /**
         * @brief
         *
         * @param stages_data_in
         */
        void write_all_stages(format_v_2_1_2::file_stages& stages_data_in) const;
        /**
         * @brief
         *
         * @param stages_data_out
         */
        void read_all_stages(file_stages &stages_data_out);
        /**
         * @brief
         *
         * @param stages_data_out
         * @param stage_n
         */
        void read_stage(file_stage& stages_data_out, short stage_n);

        bool file_exists(std::string filename) const;

        void check_conversion() const;

        bool write_save(format_v_2_1_2::st_save& data_in);
        void read_save(format_v_2_1_2::st_save& data_out) const;
        bool save_exists() const;

        void load_config(st_game_config &config);
        void save_config(st_game_config &config) const;

        int read_stage_boss_id(int stage_n);

    };
}


#endif // FILE_IO_H
