#include "Button.h"
#include <iostream>

Button::Button(std::string filename, int x, int y, int width, int height) {
	position.x = x;
	position.y = y;
	this->width = width;
	this->height = height;
	sprite = new Sprite(FileUtils::getImagePath() + filename, position.x, position.y, width, height);
	sprite->crop(width, 0, 0);
	isClicked = false;
	isOver = false;
}

void Button::setPosition(int x, int y) {
	position.x = x;
	position.y = y;
	sprite->setX(x);
	sprite->setY(y);
}

void Button::setX(int x) {
	position.x = x;
	sprite->setX(x);
}

void Button::setY(int y) {
	position.y = y;
	sprite->setY(y);
}

void Button::handleEvent(SDL_Event* e, int mouseX, int mouseY) {
	if(e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
		bool inside = true;
		if(mouseX < position.x) {
			inside = false;
		} else if(mouseX > position.x + width) {
			inside = false;
		} else if(mouseY < position.y) {
			inside = false;
		} else if(mouseY > position.y + height) {
			inside = false;
		}

		if(!inside) {
			sprite->crop(width, 0, 0);
			isOver = false;
		} else {
			switch(e->type) {
				case SDL_MOUSEMOTION:
					sprite->crop(width, 1, 0);
					isOver = true;
					break;
				case SDL_MOUSEBUTTONDOWN:
					isClicked = true;
					std::cout << "button down" << std::endl;
					break;
				case SDL_MOUSEBUTTONUP:
					isClicked = false;
					std::cout << "button up" << std::endl;
					break;
				default:
					break;
			}
		}
	}
}

bool Button::isButtonPressed() {
	return isClicked;
}

bool Button::isMouseOver() {
	return isOver;
}

void Button::draw(SDL_Renderer* renderer) {
	sprite->draw(renderer);
}
