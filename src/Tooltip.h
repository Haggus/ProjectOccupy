#pragma once
#include "SDL2/SDL.h"
#include "Text.h"
#include "Agent.h"

class Tooltip {

	public:
		void init();
		void showTip(bool doesShow);
		void update(int x, int y, Agent* agent);
		void draw(SDL_Renderer* renderer);

	private:
		SDL_Rect frame;
		bool show;
		int x, y;
		Text* agentName;
};
