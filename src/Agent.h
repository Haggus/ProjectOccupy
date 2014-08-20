#pragma once
#include "SDL2/SDL.h"
#include "Sprite.h"
#include "Button.h"

class Agent {

	public:
		Agent();
		void clean();
		void addXp(int amount);
		int getXp();
		bool isAssigned();
		void update();
		void setPosition(int x, int y);
		void draw(SDL_Renderer* renderer);
		Button* getButton();

	private:
		Sprite* sprite;
		Button* button;
		int xp;
		bool assigned;
};