#pragma once
#include "gui/TopBar.h"
#include "gui/SideBar.h"
#include "gui/BottomBar.h"
#include "Game.h"
#include "FileUtils.h"
#include "Sprite.h"
#include "Text.h"
#include "Player.h"
#include "Selector.h"
#include "Button.h"
#include <sstream>
#include <vector>

class HUD {

	public:
		HUD(int w, int h, std::vector<Player>* playaz, Selector* select, Map* mapper);
		void clean();
		void update(int turnCount);
		void handleEvent(SDL_Event* e, int mouseX, int mouseY);
		void draw(SDL_Renderer* renderer);
		void playerChange(int currentP);
		void showMissionPanel(bool show, Tile* chosen);
		bool isPanelShown();
		bool isPanelClicked(int x, int y);
		void showMissionWindow(bool show);
		bool isWindowShown();
		bool isWindowInbound(int x, int y);

	private:
		int width;
		int height;
		std::vector<Player>* players;
		TopBar* tb;
		SideBar* sb;
		BottomBar* bb;
		bool showPanel;

		//utils
		int currentPlayer;
		Map* map;
		Selector* selector;
		Tile* chosenTile;

		SDL_Rect mishWindow;
		bool showMishWindow;
};
