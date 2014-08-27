#include "Player.h"
#include <iostream>

Player::Player() {
	activities[0] = 3;
	activities[1] = 2;
	activities[2] = 0;
	activities[3] = 1;
	agents = 3;
	agentsMax = 10;
}

void Player::addAgent() {
	agents++;
}

void Player::removeAgent() {
	agents--;
}

int Player::getAgentCount() {
	return agents;
}

int Player::getAgentMax() {
	return agentsMax;
}

int Player::getActivity(int number) {
	return activities[number];
}

int* Player::getActivities() {
	return activities;
}
