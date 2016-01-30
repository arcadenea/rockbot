#include "fio_scenes.h"

namespace format_v_3_0_1 {
    fio_scenes::fio_scenes()
    {

    }

    std::vector<file_scene_list> fio_scenes::load_scenes()
    {
        return load_from_disk<file_scene_list>("scenes_list.dat");
    }

    std::vector<file_scene_clear_area> fio_scenes::load_scenes_clear_area()
    {
        return load_from_disk<file_scene_clear_area>("scenes_clear_area.dat");
    }

    std::vector<file_scene_play_music> fio_scenes::load_scenes_play_music()
    {
        return load_from_disk<file_scene_play_music>("scenes_play_music.dat");
    }

    std::vector<file_scene_play_sfx> fio_scenes::load_scenes_play_sfx()
    {
        return load_from_disk<file_scene_play_sfx>("scenes_play_sfx.dat");
    }

    std::vector<file_scene_show_animation> fio_scenes::load_scenes_show_animation()
    {
        return load_from_disk<file_scene_show_animation>("scenes_show_animation.dat");
    }

    std::vector<file_scene_show_image> fio_scenes::load_scenes_show_image()
    {
        return load_from_disk<file_scene_show_image>("scenes_show_image.dat");
    }

    std::vector<file_scene_show_text> fio_scenes::load_scenes_show_text()
    {
        return load_from_disk<file_scene_show_text>("scenes_show_text.dat");
    }

    void fio_scenes::save_scenes_show_image(std::vector<file_scene_show_image> data)
    {
        save_data_to_disk<file_scene_show_image>("scenes_show_image.dat", data);
    }

    template <class T> std::vector<T> fio_scenes::load_from_disk(std::string file)
    {
        std::string filename = std::string(FILEPATH) + "data/scenes/" + file;
        std::vector<T> res;
        FILE *fp = fopen(filename.c_str(), "rb");
        if (!fp) {
            std::cout << ">>file_io::load_from_disk - file '" << filename << "' not found." << std::endl;
            return res;
        }

        while (!feof(fp) && !ferror(fp)) {
            T out;
            int res_read = fread(&out, sizeof(T), 1, fp);
            std::cout << ">>file_io::load_from_disk - res_read '" << res_read << "'." << std::endl;
            if (res_read == -1) {
                std::cout << ">>file_io::load_from_disk - Error reading data from scenes_list file '" << filename << "'." << std::endl;
                exit(-1);
            } else if (res_read == 1) {
                res.push_back(out);
            }
        }
        std::cout << ">>file_io::load_from_disk - size: " << res.size() << std::endl;
        fclose(fp);
        return res;
    }

    template <class T> void fio_scenes::save_data_to_disk(std::string file, std::vector<T> data)
    {
        std::string filename = std::string(FILEPATH) + "data/scenes/" + file;
        std::cout << ">> file_io::save_data_to_disk - filename: '" << filename << "'." << std::endl;
        FILE *fp = fopen(filename.c_str(), "wb");
        if (!fp) {
            std::cout << ">> file_io::save_data_to_disk - file '" << filename << "' not found." << std::endl;
            return;
        }

        std::cout << ">>file_io::save_data_to_disk - size: " << data.size() << std::endl;

        for (int i=0; i<data.size(); i++) {
            int block_size = sizeof(T);
            T data_in = data.at(i);
            fwrite(&data_in, block_size, 1, fp);
        }
        fclose(fp);
    }

}
