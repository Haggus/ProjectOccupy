#include "HUD.h"
#include "Mission.h"
#include <sstream>
#include <iostream>

HUD::HUD(std::vector<Player>* playaz, Selector* select) {
	players = playaz;
	topbar = new Sprite("res/topbar.png", 0, 0, 500, 40);
	toptext = new Text(10, 10, "hello");
	sidebar = new Sprite("res/sidebar.png", 1200, 0, 80, 500);
	bottombar = new Sprite("res/bottombar.png", 390, 640, 500, 80);
	currentPlayer = 0;
	selector = select;

	rectPanel = {50, 100, 200, 500};
	label = new Text(60, 110, "missions: ");
	showPanel = false;

	mishWindow = {100, 100, 1000, 500};
	showMishWindow = false;
	for(int i=0; i<5; i++) {
		mishAgents.push_back(nullptr);
	}
}

void HUD::clean() {
	topbar->clean();
	toptext->clean();
	sidebar->clean();
	bottombar->clean();
	label->clean();
}

void HUD::update(int turnCount, int currentP, int agentCount) {
	for(int i=0; i<players->at(currentPlayer).getAgentCount(); i++) {
		players->at(currentPlayer).getAgent(i)->setPosition(1208, 8 + (72 * i));
	}
	std::stringstream ss;
	if(currentP == 0) {
		ss << "Turn " << turnCount << " | Player " << currentP << " (MIL) | Agents: " << agentCount;
	} else {
		ss << "Turn " << turnCount << " | Player " << currentP << " (RES) | Agents: " << agentCount;
	}
	toptext->updateText(ss.str());
}

void HUD::handleEvent(SDL_Event* e, int mouseX, int mouseY) {
	for(int i=0; i<players->at(currentPlayer).getAgentCount(); i++) {
		players->at(currentPlayer).getAgent(i)->getButton()->handleEvent(e, mouseX, mouseY);
	}
	if (chosenTile != nullptr)
	{
		for (int i = 0; i < chosenTile->getMissionCount(); ++i)
		{
			chosenTile->getMission(i)->getButton()->handleEvent(e, mouseX, mouseY);
		}
	}
}

void HUD::draw(SDL_Renderer* renderer) {
	topbar->draw(renderer);
	toptext->draw(renderer);
	sidebar->draw(renderer);

	for(int i=0; i<players->at(currentPlayer).getAgentCount(); i++) {
		players->at(currentPlayer).getAgent(i)->draw(renderer);
	}
	bottombar->draw(renderer);

	if(showMishWindow) {
		SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
		SDL_RenderFillRect(renderer, &mishWindow);
		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
		SDL_Rect tempRect = {200, 200, 64, 64};
		SDL_RenderFillRect(renderer, &tempRect);
		tempRect = {300, 200, 64, 64};
		SDL_RenderFillRect(renderer, &tempRect);
		tempRect = {400, 200, 64, 64};
		SDL_RenderFillRect(renderer, &tempRect);
		tempRect = {500, 200, 64, 64};
		SDL_RenderFillRect(renderer, &tempRect);
		tempRect = {600, 200, 64, 64};
		SDL_RenderFillRect(renderer, &tempRect);
		//progress bar
		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
		tempRect = {200, 300, 300, 32};
		SDL_RenderFillRect(renderer, &tempRect);
		SDL_SetRenderDrawColor(renderer, 200, 100, 50, 255);
		tempRect = {201, 301, chosenTile->getMembers(0), 30};
		SDL_RenderFillRect(renderer, &tempRect);
		//close button
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		tempRect = {150, 150, 32, 32};
		SDL_RenderFillRect(renderer, &tempRect);
		//fill agents (if any in queue)
		for(int i=0; i<5; i++) {
			if(mishAgents.at(i) != nullptr) {
				mishAgents.at(i)->setPosition(200 + (i*100), 200);
				mishAgents.at(i)->draw(renderer);
			}
		}
	}

	if(showPanel) {
		SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
		SDL_RenderFillRect(renderer, &rectPanel);
		label->draw(renderer);
		int count = chosenTile->getMissionCount();
		for(int i=0; i<count; i++) {
			Mission* mish = chosenTile->getMission(i);
			mish->setX(60);
			mish->setY((30 * i) + 140);
			mish->draw(renderer);
		}
	}
}

void HUD::playerChange(int currentP) {
	currentPlayer = currentP;
}

void HUD::showMissionPanel(bool show, Tile* chosen) {
	showPanel = show;
	if(chosen != nullptr) {
		chosenTile = chosen;
	}
}

bool HUD::isPanelShown() {
	return showPanel;
}

void HUD::showMissionWindow(bool show) {
	showMishWindow = show;
}

bool HUD::isWindowShown() {
	return showMishWindow;
}

bool HUD::isWindowInbound(int x, int y) {
	int Xwin = mishWindow.x;
	int Ywin = mishWindow.y;
	int Wwin = mishWindow.w;
	int Hwin = mishWindow.h;
	if(x > Xwin && x < Wwin) {
		if(y > Ywin && y < Hwin) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

void HUD::addAgentToMish(Agent* agent) {
	bool doesExist = false;
	for(int i=0; i<5; i++) {
		if(mishAgents.at(i) == agent) {
			doesExist = true;
		}
	}
	if(!doesExist) {
		std::cout << "does not exist, adding agent" << std::endl;
		for(int i=0; i<5; i++) {
			if(mishAgents.at(i) == nullptr) {
				mishAgents.at(i) = agent;
				std::cout << "ADDING AGENT MADAFAKA!" << std::endl;
				break;
			}
		}
	} else {
		std::cout << "AGENT already exists!" << std::endl;
	}
	std::cout << "VECTOR SIZE: " << mishAgents.size() << std::endl;
}
