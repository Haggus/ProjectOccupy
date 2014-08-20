#pragma once
#include "Tile.h"
#include <vector>

class Map {
	
	public:
		Map(int xOffset, int yOffset);
		void setTile(int x, Tile* tile);
		Tile* getTile(int x);
		void loadMap();
		int getXoffset();
		int getYoffset();
		void update();
		void render(SDL_Renderer* render);
		int getTileCount();

	private:
		std::vector<Tile*> tiles;
		int tileCount;
		int xOffset;
		int yOffset;
};