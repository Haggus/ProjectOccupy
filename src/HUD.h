#pragma once
#include "FileUtils.h"
#include "Sprite.h"
#include "Text.h"
#include "Player.h"
#include "Selector.h"
#include "Button.h"
#include "Mission.h"
#include <sstream>
#include <vector>

class HUD {

	public:
		HUD(std::vector<Player>* playaz, Selector* select);
		void clean();
		void update(int turnCount);
		void handleEvent(SDL_Event* e, int mouseX, int mouseY);
		void draw(SDL_Renderer* renderer);
		void playerChange(int currentP);
		void showMissionPanel(bool show, Tile* chosen);
		bool isPanelShown();
		void showMissionWindow(bool show);
		bool isWindowShown();
		bool isWindowInbound(int x, int y);

	private:
		std::vector<Player>* players;
		Sprite* topbar;
		Text* toptext;
		Sprite* sidebar;
		Sprite* bottombar;
		int currentPlayer;
		Selector* selector;

		SDL_Rect rectPanel;
		Text* label;
		bool showPanel;
		Tile* chosenTile;

		SDL_Rect mishWindow;
		bool showMishWindow;
};
