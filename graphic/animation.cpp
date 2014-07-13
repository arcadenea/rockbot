#include "animation.h"

#include "timerlib.h"
extern timerLib timer;

extern graphicsLib graphLib;

extern std::string FILEPATH;


animation::animation(ANIMATION_TYPES pos_type, graphicsLib_gSurface* surface, const st_float_position &pos, st_position adjust_pos, unsigned int frame_time, unsigned int repeat_times, int direction, st_size framesize, st_position *map_scroll) : _finished(false), _repeated_times(0)
{
    _ref_pos = NULL;
    _pos_type = pos_type;
    if (_pos_type == ANIMATION_DYNAMIC) {
        _ref_pos = &pos;
    } else {
        _static_pos = pos;
    }
	_repeat_times = repeat_times;
	_frame_time = frame_time;
    _direction = direction;
	_framesize = framesize;
	_frames_number = surface->width/framesize.width;
	_max_repeat = repeat_times;
	_map_scroll = map_scroll;
	_adjust_pos = adjust_pos;
	_current_frame_timer = timer.getTimer() + _frame_time;
	_surface = surface;
	//std::cout << ">> animation::animation - surface.w: " << _surface->width << ", surface.h: " << _surface->height << std::endl;
    _current_frame = 0;
    _executed_times = 0;
}

animation::~animation()
{
}

st_float_position animation::get_position() const
{
    if (_pos_type == ANIMATION_DYNAMIC) {
        return *_ref_pos;
    } else {
        return _static_pos;
    }
}


bool animation::finished() const
{
    return _finished;
}

void animation::execute()
{
    int now_timer = timer.getTimer();
    //std::cout << ">> animation::execute - _current_frame_timer: <<" << _current_frame_timer << ", now_timer: " << now_timer << std::endl;
    st_rectangle g_rect(_current_frame*_framesize.width, 0, _framesize.width, _framesize.height);
	//std::cout << ">> animation::execute - grect - x: " << g_rect.x << ", y: " << g_rect.y << ", w: " << g_rect.w << ", h: " << g_rect.h << std::endl;
    graphLib.showSurfaceRegionAt(_surface, g_rect, st_position(get_position().x-_map_scroll->x+_adjust_pos.x, get_position().y+_adjust_pos.y));
    if (_current_frame_timer < now_timer) {
        _current_frame++;
        _current_frame_timer =now_timer + _frame_time;
        if (_current_frame > _frames_number) {
            _current_frame = 0;
            _repeated_times++;
            //std::cout << ">> animation::execute - _repeated_times: <<" << _repeated_times << std::endl;
            if (_repeated_times >= _max_repeat) {
                //std::cout << ">> animation::execute - FINISHED <<" << std::endl;
                _finished = true;
            }
        }
    }
}


simple_animation::simple_animation(std::string filename, int repeat_times, int delay, int width, st_position pos)
{
    graphLib.surfaceFromFile(filename, &_surface);
    _repeat_times = repeat_times;
    _delay = delay;
    _width = width;
    _timer = timer.getTimer() + _delay;
    _max_frames = _surface.width / _width;
    _frame_n = 0;
    _pos = pos;
}

void simple_animation::execute()
{
    graphLib.showSurfaceRegionAt(&_surface, st_rectangle(_width*_frame_n, 0, _width, _surface.height), _pos);
    if ((int)timer.getTimer() > _timer) {
        _timer = timer.getTimer() + _delay;
        _frame_n++;
        if (_frame_n >= _max_frames) {
            _frame_n = 0;
        }
    }
}

void simple_animation::set_position(st_position new_pos)
{
    _pos = new_pos;
}
