#include "Agent.h"
#include <iostream>

Agent::Agent() {
	button = new Button("agent.png", 0, 0, 64, 64);
	srand(time(NULL));
	xp = rand() % 10000;
	std::cout << "Agent " << xp << " created." << std::endl;
	assigned = false;
}

void Agent::clean() {
	delete this;
}

void Agent::addXp(int amount) {
	xp += amount;
}

int Agent::getXp() {
	return xp;
}

bool Agent::isAssigned() {
	return assigned;
}

void Agent::update() {
}

void Agent::setPosition(int x, int y) {
	button->setPosition(x, y);
}

void Agent::draw(SDL_Renderer* renderer) {
	button->draw(renderer);
}

Button* Agent::getButton() {
	return button;
}
