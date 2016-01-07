#include "camera.hpp"

Camera::Camera(){ 

	m_log = new Logger(m_logfile_name);
	m_log->log("Initializing of " + m_window_name);

	m_screen_width = 640;
	m_screen_height = 480;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		m_log->log( "SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()) );
	}else{
		m_sdl_window = SDL_CreateWindow(
			m_window_name.c_str(), 
			SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED,
			m_screen_width, 
			m_screen_height, 
			SDL_WINDOW_SHOWN);
		if(m_sdl_window  == nullptr){
			m_log->log( "SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()) );
		}else{
			m_sdl_surface = SDL_GetWindowSurface(m_sdl_window);
		}
	}

	m_log->log("Done initializing of " + m_window_name);
}

Camera::~Camera(){

	m_log->log("Running destructor of " + m_window_name);

	SDL_DestroyWindow(m_sdl_window);
	SDL_Quit();

	delete m_log;

}
void Camera::render(){

	SDL_FillRect(m_sdl_surface, nullptr, SDL_MapRGB(m_sdl_surface->format, 255, 255, 255));
	SDL_UpdateWindowSurface(m_sdl_window);

}

