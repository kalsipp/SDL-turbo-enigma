#include "camera.hpp"

Camera::Camera(){ 

	m_log = new Logger(m_logfile_name);
	m_log->log("Initializing of " + m_window_name);

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
			m_sdl_glcontext = SDL_GL_CreateContext(m_sdl_window);
			if(m_sdl_glcontext == 0){
				m_log->log("OpenGL context could not be created! SDL Error: " + std::string(SDL_GetError()));
			}else{
				if(SDL_GL_SetSwapInterval(1) < 0){
					m_log->log("Warning: Unable to set VSync! SDL Error: " + std::string(SDL_GetError()) );
				}

				//if(!init_gl()){
				//	m_log->log("Unable to initialize OpenGL!");
				//}
			}
			m_sdl_surface = SDL_GetWindowSurface(m_sdl_window);
		}
	}
	m_successful_init = true;

	//Temp Getting image to show
	pelle  = SDL_LoadBMP("media/test.bmp");
	if(pelle == nullptr) assert(false);
	pelle = SDL_ConvertSurface(pelle, m_sdl_surface->format, 0);
	SDL_BlitSurface( pelle, NULL, m_sdl_surface, NULL );
	SDL_UpdateWindowSurface(m_sdl_window);

	//Temp
	m_log->log("Done initializing of " + m_window_name);
}
bool Camera::init_gl(){
	bool success = true;
	GLenum error = GL_NO_ERROR;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	error = glGetError();
	if(error != GL_NO_ERROR){
		success = false;
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	error = glGetError();
	if(error != GL_NO_ERROR){
		success = false;
	}

	glClearColor(0.f, 0.f, 0.f, 1.f);

	error = glGetError();
	if(error != GL_NO_ERROR){
		success = false;
	}

	return success;
}
Camera::~Camera(){

	m_log->log("Running destructor of " + m_window_name);
	SDL_FreeSurface(pelle);
	SDL_DestroyWindow(m_sdl_window);
	SDL_Quit();

	delete m_log;

}
bool Camera::init_successful(){
	return m_successful_init;
}
void Camera::render(){
    //Draw graphics here
}

void Camera::update(){
	//SDL_GL_SwapWindow(m_sdl_window);

}

