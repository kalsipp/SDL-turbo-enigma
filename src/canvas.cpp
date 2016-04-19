#include "canvas.hpp"

Canvas::Canvas(){
	bool success = true;
	m_log = new Logger("canvas.txt");
	m_log->log("Canvas created");
	if(init()){

	}else{
		success = false;
	}

	if(!success){
		m_log->log("Canvas failed to be created properly.");
	}else{
		m_log->log("Canvas created properly");
	}
}

Canvas::~Canvas(){
	if(m_surface != NULL){
		SDL_FreeSurface(m_surface);
		m_surface = NULL;
	}
	if(m_window != NULL){
		SDL_DestroyWindow(m_window);
		m_window = NULL;
	}
	if(m_renderer != NULL){
		SDL_DestroyRenderer( m_renderer );
		m_renderer = NULL;
	}
	
	IMG_Quit();
	SDL_Quit();

}
bool Canvas::init(){
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		m_window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_screen_width, m_screen_height, SDL_WINDOW_SHOWN );
		if( m_window == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			m_renderer = SDL_CreateRenderer( m_window, -1, SDL_RENDERER_ACCELERATED );
			if( m_renderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( m_renderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}
/*
bool Canvas::init(){
	m_log->log("Canvas init started");
	bool success = true;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) { 
		m_log->log( "SDL could not initialize! SDL_Error: %s\n" + std::string(SDL_GetError())); 
		success = false; 
	} else { 
		m_window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_screen_width, m_screen_height, SDL_WINDOW_SHOWN ); 
		if( m_window == NULL ) { 
			m_log->log( "Window could not be created! SDL_Error: %s\n"+ std::string(SDL_GetError() ) ); 
			success = false; 
		} else { 
			int imgFlags = IMG_INIT_PNG; 
			if( !( IMG_Init( imgFlags ) & imgFlags ) ) { 
				m_log->log( "SDL_image could not initialize! SDL_image Error: " + std::string(IMG_GetError()) ); 
				success = false; 
			} else { 
				m_surface = SDL_GetWindowSurface( m_window ); 
			}
		} 
	}
	m_log->log("Canvas init completed with success: " + std::to_string(success));
	return success;
}
*/
SDL_Surface * Canvas::getSurface(){
	return m_surface;
}
SDL_Renderer * Canvas::getRenderer(){
	return m_renderer;
}
void Canvas::clear(){
	SDL_RenderClear( m_renderer );
}
void Canvas::paint(){
	SDL_RenderPresent( m_renderer );
}

void Canvas::addTexture(Texture *text){
	SDL_RenderCopy( m_renderer, text->getTexture(), NULL, text->getRect() );
}