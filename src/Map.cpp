#include "Map.h"
#include <iostream>

Map::Map(int xOffset, int yOffset) {
	tileCount = 5;
	currentPlayer = 0;
	this->xOffset = xOffset;
	this->yOffset = yOffset;
	for(int i=0; i<tileCount; i++) {
		tiles.push_back(0);
	}
}

void Map::setTile(int x, Tile* tile) {
	tiles[x] = tile;
}

Tile* Map::getTile(int x) {
	return tiles[x];
}

void Map::loadMap() {
	int temp;
	Tile* test;
	test = new Tile(xOffset + 0, yOffset + 100, 100, 150);
	setTile(0, test);
	test = new Tile(xOffset + 100, yOffset + 25, 200, 160);
	setTile(1, test);
	test = new Tile(xOffset + 300, yOffset + 80, 180, 140);
	setTile(2, test);
	test = new Tile(xOffset + 310, yOffset + 0, 140, 80);
	setTile(3, test);
	test = new Tile(xOffset + 480, yOffset + 25, 100, 170);
	setTile(4, test);
}

int Map::getXoffset() {
	return xOffset;
}

int Map::getYoffset() {
	return yOffset;
}

void Map::update(int currentP) {
	currentPlayer = currentP;
	for(int i=0; i<tileCount; i++) {
		getTile(i)->update(currentPlayer);
	}
}

void Map::render(SDL_Renderer* renderer) {
	for(int i=0; i<tileCount; i++) {
		getTile(i)->draw(renderer);
	}
}

int Map::getTileCount() {
	return tileCount;
}

int Map::getAgentCount(int type) {
	int count = 0;
	for(int i=0; i<tileCount; i++) {
		count += getTile(i)->getMembers(currentPlayer, type);
	}
	return count;
}
