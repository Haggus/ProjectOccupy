#pragma once
#include "SDL2/SDL.h"
#include "Game.h"
#include "GameState.h"
#include "PlayState.h"
#include "FileUtils.h"
#include "Sprite.h"

class MenuState : public GameState {

	public:
		void init(Game* gamer);
		void clean();
		void pause();
		void resume();
		void handleEvents();
		void update();
		void render();
		//singleton
		static MenuState* instance() {
			return &theMenuState;
		}

	protected:
		MenuState() {
		}

	private:
		static MenuState theMenuState;
		Game* game;

		Sprite* back;
		Sprite* unit;
		Sprite* cursor;

		int mouseX;
		int mouseY;
};
