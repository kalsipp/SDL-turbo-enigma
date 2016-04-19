#pragma once
#include "canvas.hpp"
#include "texture.hpp"
#include "gameobject.hpp"
class Game{
public:
	Game();
	void run();
private:
	Canvas * m_canvas = NULL;
};