#include "SDL2/SDL.h"
#include "Tile.h"

Tile::Tile(int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	image = new Sprite("res/tiles.png", x, y, w, h);
	image->crop(64, 0, 0);

	memberCount[0] = 0;
	memberCount[1] = 0;
}

void Tile::clean() {
	image->clean();
	delete this;
}

void Tile::update() {
	if(memberCount[0] > memberCount[1]) {
		image->crop(64, 2, 0);
	} else if(memberCount[0] < memberCount[1]) {
		image->crop(64, 1, 0);
	} else {
		image->crop(64, 0, 0);
	}
}

void Tile::draw(SDL_Renderer* renderer) {
	image->draw(renderer);
}

void Tile::addMembers(int amount, int type) {
	memberCount[type] += 10;
}

void Tile::addMission() {
	missions.push_back(new Mission());
}

Mission* Tile::getMission(int i) {
	return missions.at(i);
}

int Tile::getMissionCount() {
	return missions.size();
}

int Tile::getMembers(int type) {
	return memberCount[type];
}

int Tile::getWidth() {
	return w;
}

int Tile::getHeight() {
	return h;
}

int Tile::getX() {
	return x;
}

int Tile::getY() {
	return y;
}

Button* Tile::getButton() {
	return button;
}
