#include "HUD.h"
#include <iostream>

HUD::HUD(int w, int h, std::vector<Player>* playaz, Selector* select) {
	width = w;
	height = h;
	players = playaz;
	tb = new TopBar();
	sb = new SideBar(width - 80, 0);

	bottombar = new Sprite(FileUtils::getImagePath() + "bottombar.png", 390, 640, 500, 80);
	currentPlayer = 0;
	selector = select;

	rectPanel = {50, 100, 200, 500};
	label = new Text(60, 110, "missions: ");
	showPanel = false;

	mishWindow = {100, 100, 1000, 500};
	showMishWindow = false;
}

void HUD::clean() {
	tb->clean();
	sb->clean();
	bottombar->clean();
	label->clean();
}

void HUD::update(int turnCount) {
	tb->update(turnCount, currentPlayer, players->at(currentPlayer).getAgentCount(), players->at(currentPlayer).getAgentMax());
}

void HUD::handleEvent(SDL_Event* e, int mouseX, int mouseY) {
	if (chosenTile != nullptr)
	{
		for (int i = 0; i < chosenTile->getMissionCount(); ++i)
		{
			chosenTile->getMission(i)->getButton()->handleEvent(e, mouseX, mouseY);
		}
	}
}

void HUD::draw(SDL_Renderer* renderer) {
	tb->draw(renderer);
	sb->draw(renderer);

	// for(int i=0; i<4; i++) { // << there are 4 activities so far, update for more
	// 	if(players->at(currentPlayer).getActivity(i) > 0) {
	// 		std::cout << "Activity " << i << ": " << players->at(currentPlayer).getActivity(i) << std::endl;
	// 	}
	// }

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
