#pragma once
#include "SDL2/SDL.h"
#include "FileUtils.h"
#include "Sprite.h"
#include <vector>

class Tile {

	public:
		Tile(int x, int y, int w, int h);
		void clean();
		void update();
		void draw(SDL_Renderer* renderer);
		void addMembers(int amount, int type);
		int getMembers(int type);
		int getMembersTotal();
		int getWidth();
		int getHeight();
		int getX();
		int getY();

	private:
		Sprite* image;
		int x, y;
		int w, h;
		int memberCount[2];
		int totalMembers;
};
