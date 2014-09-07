#include "Tile.h"

Tile::Tile(int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	image = new Sprite(FileUtils::getImagePath() + "tiles.png", x, y, w, h);
	image->crop(64, 0, 0);

	for(int i=0; i<missionTypes; i++) {
		memberCount[0][i] = 0;
		memberCount[1][i] = 0;
	}
	currentPlayer = 0;

	title = new Text(x + (w/2), y + (h/2), "Zone");

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
	title->clean();
	mishAttack->clean();
	mishAttackText->clean();
	mishDefense->clean();
	mishDefenseText->clean();
	mishRecruit->clean();
	mishRecruitText->clean();
	mishHelp->clean();
	mishHelpText->clean();
}

void Tile::update(int currentP) {
	currentPlayer = currentP;
	std::string s = std::to_string(memberCount[currentPlayer][0]);
	mishAttackText->updateText(s);
	s = std::to_string(memberCount[currentPlayer][1]);
	mishDefenseText->updateText(s);
	s = std::to_string(memberCount[currentPlayer][2]);
	mishRecruitText->updateText(s);
	s = std::to_string(memberCount[currentPlayer][3]);
	mishHelpText->updateText(s);
	if(getMembersTotal(0) > getMembersTotal(1)) {
		image->crop(64, 2, 0);
	} else if(getMembersTotal(0) < getMembersTotal(1)) {
		image->crop(64, 1, 0);
	} else {
		image->crop(64, 0, 0);
	}
}

void Tile::draw(SDL_Renderer* renderer) {
	image->draw(renderer);
	title->draw(renderer);
	if(memberCount[currentPlayer][0] > 0) {
		mishAttack->draw(renderer);
		mishAttackText->draw(renderer);
	}
	if(memberCount[currentPlayer][1] > 0) {
		mishDefense->draw(renderer);
		mishDefenseText->draw(renderer);
	}
	if(memberCount[currentPlayer][2] > 0) {
		mishRecruit->draw(renderer);
		mishRecruitText->draw(renderer);
	}
	if(memberCount[currentPlayer][3] > 0) {
		mishHelp->draw(renderer);
		mishHelpText->draw(renderer);
	}
}

void Tile::addMembers(int amount, int currentPlayer, int type) {
	memberCount[currentPlayer][type] += amount;
}

int Tile::getMembers(int currentPlayer, int type) {
	return memberCount[currentPlayer][type];
}

int Tile::getMembersTotal(int playerNumber) {
	int count = 0;
	for(int i=0; i<missionTypes; i++) {
		count += memberCount[playerNumber][i];
	}
	return count;
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
