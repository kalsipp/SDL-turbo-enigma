#include <SDL.h>
#include <SDL_opengl.h>

#include "camera.hpp"
#include "logger.hpp"

int main(){
	Camera g;
	Logger mylog("mainlog.txt");
	if(g.init_successful()){
		bool running = true;
		SDL_Event events;
		SDL_StartTextInput();
		//mylog.log(SDL_TEXTINPUT);
		while(running){

			while(SDL_PollEvent(&events) != 0){ 
				switch(events.type){

					case SDL_QUIT:
						running = false;
						break;
					case SDL_TEXTINPUT:
					int x = 0, y = 0;
					SDL_GetMouseState(&x, &y); //doesn't use this atm contains mousepos

					mylog.log("keys " + std::string(events.text.text));// << events.text.text[0] << std::endl;
					
					if(events.text.text[0] == 'q'){
						running = false;
					}
				}
			}

			g.render();
			g.update();
		}
		SDL_StopTextInput();
	}
}