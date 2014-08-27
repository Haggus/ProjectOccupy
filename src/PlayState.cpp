#include "PlayState.h"
#include <iostream>

PlayState PlayState::thePlayState;

void PlayState::init(Game* gamer) {
	game = gamer;
	for(int i=0; i<PLAYER_COUNT; i++) {
		players.push_back(Player());
	}

	back = new Sprite(FileUtils::getImagePath() + "back.png", 0, 0, 1280, 720);
	cursor = new Sprite(FileUtils::getImagePath() + "cursor.png", 0, 0, 20, 20);
	map = new Map(350, 232);
	map->loadMap();
	select = new Selector(map);
	gui = new HUD(game->getWidth(), game->getHeight(), &players, select);
	mouseX = 0;
	mouseY = 0;

	currentPlayer = 0;
	turnCount = 1;

	std::cout << "Play state init >> DONE" << std::endl;
}

void PlayState::endTurn() {
	currentPlayer++;
	if(currentPlayer == PLAYER_COUNT) {
		turnCount++;
		currentPlayer = 0;
	}
	gui->playerChange(currentPlayer);
}

void PlayState::clean() {
	back->clean();
	cursor->clean();
	select->clean();
	gui->clean();
	std::cout << "Play state clean >> DONE" << std::endl;
}

void PlayState::pause() {
	std::cout << "Play state pause >> DONE" << std::endl;
}

void PlayState::resume() {
	std::cout << "Play state resume >> DONE" << std::endl;
}

void PlayState::handleEvents() {
	SDL_GetMouseState(&mouseX, &mouseY);
	while(SDL_PollEvent(game->getMainEvent())) {
		switch(game->getMainEvent()->type) {
			case SDL_QUIT:
				game->quit();
				break;
			case SDL_MOUSEMOTION:
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch(game->getMainEvent()->button.button) {
					case SDL_BUTTON_LEFT:
						if(gui->isWindowShown()) {
							if(gui->isWindowInbound(mouseX, mouseY)) {
								//clicked inside the window
								std::cout << "mouseXY: " << mouseX << ", " << mouseY << std::endl;
								if(mouseX > 150 && mouseX < 182) {
									if(mouseY > 150 && mouseY < 182) {
										gui->showMissionWindow(false);
									}
								}
							}
						} else if(gui->isPanelShown()) {
							// for(int i=0; i<select->getSelected()->getMissionCount(); i++) {
							// 	if(select->getSelected()->getMission(i)->collision(mouseX, mouseY)) {
							// 		std::cout << "Mission: " << select->getSelected()->getMission(i)->getName() << std::endl;
							// 		//show mission screen here!
							// 		gui->showMissionWindow(true);
							// 	}
							// }
						}
						if(select->select()) {
							select->getSelected()->addMembers(10, currentPlayer);
							gui->showMissionPanel(true, select->getSelected());
						} else {
							gui->showMissionPanel(false, nullptr);
						}
						break;
					default:
						break;
				}
			case SDL_KEYDOWN:
				switch(game->getMainEvent()->key.keysym.sym) {
					case SDLK_SPACE:
						std::cout << "End turn" << std::endl;
						endTurn();
						break;
					case SDLK_c:
						std::cout << "C pressed" << std::endl;
						break;
					default:
						break;
				}
			default:
				break;
		}
		gui->handleEvent(game->getMainEvent(), mouseX, mouseY);
	}
}

void PlayState::update() {
	cursor->setPosition(mouseX, mouseY);
	if(!gui->isWindowShown()) {
		select->update(mouseX, mouseY);
	}
	map->update();
	gui->update(turnCount);
}

void PlayState::render() {
	back->draw(game->getRenderer());
	map->render(game->getRenderer());
	//everything after background and map

	gui->draw(game->getRenderer());

	//cursor and selector always last
	select->draw(game->getRenderer());
	cursor->draw(game->getRenderer());
}
