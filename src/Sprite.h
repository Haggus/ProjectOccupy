#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

class Sprite {

	public:
		Sprite(std::string filePath, int x, int y, int width, int height);
		void clean();
		void crop(int size, int x, int y);
		void draw(SDL_Renderer* renderer);
		void setX(int x);
		void setY(int y);
		void setW(int w);
		void setH(int h);
		void setPosition(int x, int y);
		int getX();
		int getY();
		int getW();
		int getH();

	private:
		SDL_Surface* image;
		SDL_Texture* texture;
		SDL_Rect rect;
		SDL_Rect rcrop;
};
