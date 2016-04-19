#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <math.h>
#include "canvas.hpp"
class Canvas;
class Texture{
public:
	Texture(Canvas *);
	~Texture();
	void loadFromFile(const std::string & filename);
	void setPosition(int x, int y);
	void scale(float x, float y);

	SDL_Texture * getTexture();
	const SDL_Texture * getTexture()const;
	SDL_Rect * getRect();
private:
	SDL_Texture * m_texture = NULL;
	Canvas * m_canvas = NULL;
	SDL_Rect * m_rect = NULL;
};