#include "Player.h"
#include <iostream>

Player::Player() {
	srand(time(0));
	int random_id = rand() % 100;
	std::cout << "Player: " << random_id << " created" << std::endl;
	Agent* temp;
	for(int i=0; i<3; i++) {
		agents.push_back(new Agent());
	}
}

void Player::addAgent() {
	agents.push_back(new Agent());
}

Agent* Player::getAgent(int index) {
	return agents.at(index);
}

int Player::getAgentCount() {
	return agents.size();
}
