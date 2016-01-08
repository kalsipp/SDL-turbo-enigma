#pragma once
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
	void update();
	bool init_successful();
private:
	//void log(std::string message);
	bool init_gl();
	bool m_successful_init = true;
	int m_screen_width = 640;
	int m_screen_height = 480;
	SDL_Window * m_sdl_window = nullptr;
	SDL_Surface * m_sdl_surface = nullptr;
	SDL_GLContext m_sdl_glcontext;
	std::string m_window_name = "Muh Window Name";
	std::string m_logfile_name = "log_camera.txt";
	Logger * m_log;
};
