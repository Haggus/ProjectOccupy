#include "Player.h"
#include <iostream>

Player::Player() {
	agents = 10;
	agentsMax = 10;
}

void Player::addAgent() {
	agents++;
}

bool Player::removeAgent() {
	if(agents > 0) {
		agents--;
		return true;
	} else {
		std::cout << "No more agents to assign" << std::endl;
		return false;
	}
}

int Player::getAgentCount() {
	return agents;
}

int Player::getAgentMax() {
	return agentsMax;
}
