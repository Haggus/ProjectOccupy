#include "PlayState.h"
#include <iostream>

PlayState PlayState::thePlayState;

void PlayState::init(Game* gamer) {
	game = gamer;
	for(int i=0; i<PLAYER_COUNT; i++) {
		players.push_back(Player());
	}

	back = new Sprite(FileUtils::getImagePath() + "back.bmp", 0, 0, 1280, 720);
	unit = new Sprite(FileUtils::getImagePath() + "unit.png", 300, 500, 100, 100);
	cursor = new Sprite(FileUtils::getImagePath() + "cursor.png", 0, 0, 20, 20);
	map = new Map(350, 232);
	map->loadMap();
	select = new Selector(map);
	gui = new HUD(&players, select);
	tooltip = new Tooltip();
	tooltip->init();
	testButton = new Button("agent.png", 50, 50, 64, 64);
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
	unit->clean();
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
				if(getChosenAgent(mouseX, mouseY) != nullptr) {
					tooltip->update(mouseX, mouseY, getChosenAgent(mouseX, mouseY));
				} else {
					tooltip->showTip(false);
				}
				testButton->handleEvent(game->getMainEvent(), mouseX, mouseY);
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch(game->getMainEvent()->button.button) {
					case SDL_BUTTON_LEFT:
						unit->setX(unit->getX() + 1);
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
							if(getChosenAgent(mouseX, mouseY) != nullptr) {
								//add clicked agent to mission queue
								gui->addAgentToMish(getChosenAgent(mouseX, mouseY));
							}
						} else if(gui->isPanelShown()) {
							for(int i=0; i<select->getSelected()->getMissionCount(); i++) {
								if(select->getSelected()->getMission(i)->collision(mouseX, mouseY)) {
									std::cout << "Mission: " << select->getSelected()->getMission(i)->getName() << std::endl;
									//show mission screen here!
									gui->showMissionWindow(true);
								}
							}
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
						players[1].getAgent(2)->addXp(10);
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

Agent* PlayState::getChosenAgent(int x, int y) {
	for(int i=0; i<players[currentPlayer].getAgentCount(); i++) {
		if(players[currentPlayer].getAgent(i)->getButton()->isMouseOver()) {
			return players[currentPlayer].getAgent(i);
		}
	}
	return nullptr;
}

void PlayState::update() {
	cursor->setPosition(mouseX, mouseY);
	if(!gui->isWindowShown()) {
		select->update(mouseX, mouseY);
	}
	map->update();
	gui->update(turnCount, currentPlayer,  players[currentPlayer].getAgentCount());
}

void PlayState::render() {
	back->draw(game->getRenderer());
	map->render(game->getRenderer());
	//everything after background and map

	unit->draw(game->getRenderer());
	gui->draw(game->getRenderer());
	tooltip->draw(game->getRenderer());
	testButton->draw(game->getRenderer());

	//cursor and selector always last
	select->draw(game->getRenderer());
	cursor->draw(game->getRenderer());
}
