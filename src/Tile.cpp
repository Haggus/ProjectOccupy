#include "Tile.h"

Tile::Tile(int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	image = new Sprite(FileUtils::getImagePath() + "tiles.png", x, y, w, h);
	image->crop(64, 0, 0);

	memberCount[0] = 0;
	memberCount[1] = 0;
	totalMembers = 20;

	mishAttack = new Sprite(FileUtils::getImagePath() + "markers.png", x + 5, y + 5, 16, 16);
	mishAttack->crop(16, 0, 0);
	mishAttackText = new Text(x + 5, y + 25, "3");
	mishDefense = new Sprite(FileUtils::getImagePath() + "markers.png", x + 25, y + 5, 16, 16);
	mishDefense->crop(16, 1, 0);
	mishDefenseText = new Text(x + 25, y + 25, "7");
	mishRecruit = new Sprite(FileUtils::getImagePath() + "markers.png", x + 45, y + 5, 16, 16);
	mishRecruit->crop(16, 2, 0);
	mishRecruitText = new Text(x + 45, y + 25, "9");
	mishHelp = new Sprite(FileUtils::getImagePath() + "markers.png", x + 65, y + 5, 16, 16);
	mishHelp->crop(16, 3, 0);
	mishHelpText = new Text(x + 65, y + 25, "1");
}

void Tile::clean() {
	image->clean();
	mishAttack->clean();
	mishAttackText->clean();
	mishDefense->clean();
	mishDefenseText->clean();
	mishRecruit->clean();
	mishRecruitText->clean();
	mishHelp->clean();
	mishHelpText->clean();
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
	mishAttack->draw(renderer);
	mishAttackText->draw(renderer);
	mishDefense->draw(renderer);
	mishDefenseText->draw(renderer);
	mishRecruit->draw(renderer);
	mishRecruitText->draw(renderer);
	mishHelp->draw(renderer);
	mishHelpText->draw(renderer);
}

void Tile::addMembers(int amount, int type) {
	memberCount[type] += amount;
}

int Tile::getMembers(int type) {
	return memberCount[type];
}

int Tile::getMembersTotal() {
	return totalMembers;
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
