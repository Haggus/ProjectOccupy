#include "MenuState.h"
#include <iostream>

MenuState MenuState::theMenuState;

void MenuState::init(Game* gamer) {
	game = gamer;

	back = new Sprite(FileUtils::getImagePath() + "back.bmp", 0, 0, 1280, 720);
	cursor = new Sprite(FileUtils::getImagePath() + "cursor.png", 0, 0, 20, 20);
	mouseX = 0;
	mouseY = 0;

	std::cout << "Menu state init >> DONE" << std::endl;
}

void MenuState::clean() {
	std::cout << "Menu state clean >> DONE" << std::endl;
}

void MenuState::pause() {
	std::cout << "Menu state pause >> DONE" << std::endl;
}

void MenuState::resume() {
	std::cout << "Menu state resume >> DONE" << std::endl;
}

void MenuState::handleEvents() {
	SDL_GetMouseState(&mouseX, &mouseY);
	while(SDL_PollEvent(game->getMainEvent())) {
		switch(game->getMainEvent()->type) {
			case SDL_QUIT:
				game->quit();
				break;
			case SDL_KEYDOWN:
				switch(game->getMainEvent()->key.keysym.sym) {
					case SDLK_n:
						std::cout << "Switching states to start new game" << std::endl;
						game->changeState(PlayState::instance());
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
	}
}

void MenuState::update() {
	//sd update here
}

void MenuState::render() {
	back->draw(game->getRenderer());
	cursor->setPosition(mouseX, mouseY);
	cursor->draw(game->getRenderer());
}
