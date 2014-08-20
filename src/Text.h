#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "FileUtils.h"
#include <iostream>

class Text {

	public:
		Text(int x, int y, std::string msg);
		void clean();
		void setX(int x);
		void setY(int y);
		int getX();
		int getY();
		void draw(SDL_Renderer* renderer);
		void updateText(std::string msg);

	private:
		int x;
		int y;
		std::string message;
		SDL_Color color;
		TTF_Font* font;
		SDL_Surface* surface;
		SDL_Texture* texture;
		SDL_Rect rect;
};
