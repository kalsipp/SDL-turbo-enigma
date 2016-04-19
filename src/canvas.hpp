#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "logger.hpp"
#include "texture.hpp"
class Texture;
class Canvas{
public:
	Canvas();
	~Canvas();
	void addTexture(Texture * );
	void paint();
	void clear();
	SDL_Surface * getSurface();
	SDL_Renderer * getRenderer();
private:
	bool init();
	Logger * m_log = NULL;
	SDL_Window * m_window = NULL;
	SDL_Surface * m_surface = NULL;
	SDL_Renderer * m_renderer = NULL;
	int m_screen_width = 1000;
	int m_screen_height = 1000;
};