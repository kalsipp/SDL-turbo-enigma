#include <SDL.h>
#include <SDL_opengl.h>

#include "camera.hpp"


int main(){
	Camera g;
	while(true){
		g.render();
		SDL_Delay(2000);
		break;
	}
}