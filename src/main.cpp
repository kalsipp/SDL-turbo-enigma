#include <iostream>

#include "game.hpp"

int main(){
	std::cout << "Program started" << std::endl;
	Game g;
	g.run();
	std::cout << "Program ended" << std::endl;
	return 0;
}
