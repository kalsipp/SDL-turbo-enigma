#include "game.hpp"

Game::Game(){
	m_canvas = new Canvas();
}

void Game::run(){
	Texture text(m_canvas);
	SDL_Event event;
	bool running = true;
	text.loadFromFile("media/test.png");
	text.scale(2, 2);
	int mouseX = 0;
	int mouseY = 0;
	Gameobject go(m_canvas);
	go.setImage(text);
	go.setSpeed(1);
	while(running){ 
		
		while( SDL_PollEvent( &event ) != 0 ) { 
			switch( event.type ){
            /* Look for a keypress */
				case SDL_QUIT:
				running = false;
				break;

				case SDL_KEYDOWN:
				switch( event.key.keysym.sym ){

					case SDLK_q:
					running = false;

				}
				break;

				case SDL_KEYUP:
				switch( event.key.keysym.sym ){
					
				}
				break;

				case SDL_MOUSEBUTTONDOWN:
				SDL_GetMouseState(&mouseX, &mouseY);
				printf("Click at (%d, %d)\n", mouseX, mouseY);
				go.setTargetPosition(mouseX, mouseY);
				break;

			}
		}

		go.moveToTarget();
		m_canvas->clear();
		m_canvas->addTexture(go.getTexture());
		m_canvas->paint();

	}

	delete m_canvas;

}