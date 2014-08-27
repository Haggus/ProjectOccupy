#pragma once
#include "SDL2/SDL.h"
#include "Game.h"
#include "GameState.h"
#include "FileUtils.h"
#include "Sprite.h"
#include "Tile.h"
#include "Map.h"
#include "Selector.h"
#include "Text.h"
#include "Player.h"
#include "HUD.h"
#include "Button.h"
#include <vector>

class PlayState : public GameState {

	public:
		void init(Game* gamer);
		void endTurn();
		void clean();
		void pause();
		void resume();
		void handleEvents();
		void update();
		void render();
		//singleton
		static PlayState* instance() {
			return &thePlayState;
		}

	protected:
		PlayState() {
		}

	private:
		static PlayState thePlayState;
		Game* game;
		std::vector<Player> players;

		const int PLAYER_COUNT = 2;

		Sprite* back;
		Sprite* cursor;
		Selector* select;
		Map* map;
		HUD* gui;
		int mouseX;
		int mouseY;

		int currentPlayer;
		int turnCount;
};
