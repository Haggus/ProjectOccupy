#include "Mission.h"

Mission::Mission() {
	difficulty = 7;
	name = "Occupy Tile";
	description = "Occupants are gathering at the square!";
	button = new Button("button.png", 0, 0, 128, 32);
	label = new Text(0, 0, name);
}

void Mission::clean() {
	label->clean();
}

int Mission::getDifficulty() {
	return difficulty;
}

std::string Mission::getName() {
	return name;
}

std::string Mission::getDescription() {
	return description;
}

Button* Mission::getButton() {
	return button;
}

void Mission::setX(int x) {
	button->setX(x);
	label->setX(x);
}

void Mission::setY(int y) {
	button->setY(y);
	label->setY(y);
}

bool Mission::collision(int x, int y) {
	int Xmin = label->getX();
	int Xmax = label->getX() + 100;
	int Ymin = label->getY();
	int Ymax = label->getY() + 32;
	if(x > Xmin && x < Xmax) {
		if(y > Ymin && y < Ymax) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

void Mission::draw(SDL_Renderer* renderer) {
	button->draw(renderer);
	label->draw(renderer);
}