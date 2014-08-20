#include "SDL2/SDL.h"
#include "Game.h"
#include "MenuState.h"
#include <iostream>

int main(int argc, char *argv[]) {
	Game resistance;

	const int SCREEN_FPS = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

	resistance.init("Resistance | early prototype", 1280, 720);
	resistance.changeState(MenuState::instance());

	long timer = SDL_GetTicks();
	int frames = 0;

	while(resistance.running()) {

		resistance.handleEvents();
		resistance.update();
		resistance.render();
		frames++;

		if(SDL_GetTicks() - timer > 1000) {
			timer += 1000;
			//std::cout << "fps: " << frames << std::endl;
			frames = 0;
		}
	}

	resistance.clean();
	return 0;
}
