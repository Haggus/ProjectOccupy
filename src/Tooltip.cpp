#include "Tooltip.h"

void Tooltip::init() {
	x = 0;
	y = 0;
	frame = {x, y, 100, 250};
	show = false;
	agentName = new Text(0, 0, "Agent");
}

void Tooltip::showTip(bool doesShow) {
	show = doesShow;
}

void Tooltip::update(int x, int y, Agent* agent) {
	this->x = x - 100;
	this->y = y + 5;
	frame = {this->x, this->y, 100, 250};
	agentName->setX(this->x);
	agentName->setY(this->y);
	agentName->updateText("Agent");
	show = true;
}

void Tooltip::draw(SDL_Renderer* renderer) {
	if(show) {
		SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
		SDL_RenderFillRect(renderer, &frame);
		agentName->draw(renderer);
	}
}
