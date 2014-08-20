#pragma once
#include "SDL2/SDL.h"
#include "Sprite.h"
#include <string>

class Button {

	public:
		Button(std::string filename, int x, int y, int width, int height);
		void setPosition(int x, int y);
		void setX(int x);
		void setY(int y);
		void handleEvent(SDL_Event* e, int mouseX, int mouseY);
		bool isButtonPressed();
		bool isMouseOver();
		void draw(SDL_Renderer* renderer);

	private:
		SDL_Point position;
		Sprite* sprite;
		int width, height;
		bool isClicked;
		bool isOver;
};