#include "texture.hpp"

Texture::Texture(Canvas * canv){
	m_canvas = canv;
	m_rect = new SDL_Rect{0,0,0,0};

}
Texture::~Texture(){

	if(m_texture != NULL){
		SDL_DestroyTexture(m_texture);
		m_texture = NULL;
	}
}
void Texture::setPosition(int x, int y){
	m_rect->x = x;
	m_rect->y = y;
}
void Texture::scale(float x, float y){
	m_rect->w = round(m_rect->w*x);
	m_rect->h = round(m_rect->h*x);
}
void Texture::loadFromFile(const std::string & path){

	if(m_texture != NULL) {
		SDL_DestroyTexture(m_texture);
		m_texture = NULL;
	}
    //The final texture 
	SDL_Texture* newTexture = NULL; 
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() ); 
	if( loadedSurface == NULL ) 
	{ 
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() ); 
	}
	else 
	{ 

		m_rect->w = loadedSurface->w;
		m_rect->h = loadedSurface->h;
		newTexture = SDL_CreateTextureFromSurface( m_canvas->getRenderer(), loadedSurface ); 
		if( newTexture == NULL ) 
		{ 
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() ); 
		}
		SDL_FreeSurface( loadedSurface ); 
	} 
	m_texture = newTexture;
}

SDL_Rect * Texture::getRect(){
	return m_rect;
}

SDL_Texture * Texture::getTexture(){
	return m_texture;
}
const SDL_Texture * Texture::getTexture()const{
	return m_texture;
}