#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <cmath>
#include "texture.hpp"
#include "canvas.hpp"
class Gameobject{
public:
	Gameobject(Canvas *);
	~Gameobject();
	void move(int x, int y);
	void setPosition(int x, int y);
	void setTargetPosition(int x, int y);
	void setSpeed(float);
	void moveToTarget();
	void loadImage(const std::string &);
	void setImage(const Texture &);
	SDL_Rect * getRect();
	Texture * getTexture();
private:
	Texture * m_texture = NULL;
	SDL_Rect * m_rect = NULL;
	Canvas * m_canvas = NULL;
	std::pair<int, int> * m_targetPosition = NULL;
	float m_speed;
};