#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>
#include <fstream>

#include "logger.hpp"

class Camera{
public:
	Camera();
	~Camera();
	void render();
private:
	//void log(std::string message);
	int m_screen_width;
	int m_screen_height;
	SDL_Window * m_sdl_window = nullptr;
	SDL_Surface * m_sdl_surface = nullptr;
	std::string m_window_name = "Muh Window Name";
	std::string m_logfile_name = "log_camera.txt";
	Logger * m_log;
};
