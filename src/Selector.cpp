#include "Selector.h"
#include <iostream>

Selector::Selector(Map* mapper) {
	map = mapper;
	this->xOffset = map->getXoffset();
	this->yOffset = map->getYoffset();
	image = new Sprite(FileUtils::getImagePath() + "select.png", 0, 0, 64, 64);
	isBounds = false;
	xTile = 0;
}

void Selector::clean() {
	image->clean();
}

void Selector::update(int mX, int mY) {
	if(mX < xOffset || mY < yOffset) {
		isBounds = false;
	} else {
		for(int i=0; i<map->getTileCount(); i++) {
			if(mX > map->getTile(i)->getX() && mY > map->getTile(i)->getY()) {
				if(mX < map->getTile(i)->getX() + map->getTile(i)->getWidth() && mY < map->getTile(i)->getY() + map->getTile(i)->getHeight()) {
					// std::cout << "ja pierdole jest kolizja! -> " << i << std::endl;
					xTile = i;
					isBounds = true;
					image->setX(map->getTile(i)->getX());
					image->setY(map->getTile(i)->getY());
					image->setW(map->getTile(i)->getWidth());
					image->setH(map->getTile(i)->getHeight());
					break;
				} else {
					isBounds = false;
				}
			} else {
				isBounds = false;
			}
		}
	}
}

bool Selector::inBound() {
	return isBounds;
}

int Selector::getXTile() {
	return xTile;
}

void Selector::draw(SDL_Renderer* renderer) {
	if(isBounds) {
		image->draw(renderer);
	}
}

bool Selector::select() {
	if(isBounds) {
		selected = map->getTile(xTile);
		return true;
	} else {
		return false;
	}
}

Tile* Selector::getSelected() {
	return selected;
}
