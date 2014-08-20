#pragma once
#include "Game.h"

class GameState {

	public:
		virtual void init(Game* game) = 0;
		virtual void clean() = 0;
		virtual void pause() = 0;
		virtual void resume() = 0;
		virtual void handleEvents() = 0;
		virtual void update() = 0;
		virtual void render() = 0;
		void changeState(Game* game, GameState* state) {
			game->changeState(state);
		}

	protected:
		GameState() {
		}
};
