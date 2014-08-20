#pragma once
#include "FileUtils.h"
#include "Sprite.h"
#include "Map.h"
#include "Tile.h"

class Selector {

	public:
		Selector(Map* mapper);
		void clean();
		void update(int mX, int mY);
		bool inBound();
		int getXTile();
		void draw(SDL_Renderer* renderer);
		bool select();
		Tile* getSelected();

	private:
		Sprite* image;
		Tile* selected;
		Map* map;
		int xOffset;
		int yOffset;
		int mapWidth;
		int mapHeight;
		bool isBounds;
		int xTile;
};
