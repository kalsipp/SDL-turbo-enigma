

#include "gameobject.hpp"

Gameobject::Gameobject(Canvas * c){
	m_canvas = c;
	m_rect = new SDL_Rect{0,0,0,0};
}
void Gameobject::move(int x, int y){
	if(m_rect != NULL){
		m_rect->x += x;
		m_rect->y += y;
		m_texture->setPosition(m_rect->x, m_rect->y);
	}
}

void Gameobject::moveToTarget(){
	if(m_targetPosition != NULL){
		int x = m_rect->x;
		int y = m_rect->y;
	    x = m_targetPosition->first-x; //Diffposition
	    y = m_targetPosition->second-y;
	    x = x/(x*x+y*y); //Normalized direction
	    y = y/(x*x + y*y);
	    x = round(x*m_speed);
	    y = round(y*m_speed);
	    printf("%d\n",x);
	    move(x,y);
	}

}
void Gameobject::setPosition(int x, int y){
	if(m_rect != NULL){
		m_rect->x = x;
		m_rect->y = y;
		if(m_texture != NULL){
			m_texture->setPosition(m_rect->x, m_rect->y);
		}

	}else{
		printf("Rect is null\n");
	}
}

void Gameobject::setTargetPosition(int x, int y){
	m_targetPosition = new std::pair<int, int>(x,y);
}

void Gameobject::setSpeed(float x){
	m_speed = x;
}
void Gameobject::loadImage(const std::string & path){
	if(m_texture == NULL){
		m_texture = new Texture(m_canvas);
	}
	m_texture->loadFromFile(path);
	m_texture->setPosition(m_rect->x, m_rect->y);
}
void Gameobject::setImage(const Texture & tex){
	if(m_texture != NULL){
		delete m_texture;
		m_texture = NULL;
	}
	m_texture = new Texture(tex);
}

Gameobject::~Gameobject(){
	if(m_texture != NULL){
		delete m_texture;
		m_texture = NULL;
	}
	if(m_rect != NULL){
		delete m_rect;
		m_rect = NULL;
	}
}

SDL_Rect * Gameobject::getRect(){
	return m_rect;
}

Texture * Gameobject::getTexture(){
	return m_texture;
}