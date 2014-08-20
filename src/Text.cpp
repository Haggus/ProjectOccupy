#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "Text.h"

Text::Text(int x, int y, std::string msg) {
	this->x = x;
	this->y = y;
	message = msg;
	color = {255, 255, 255};
	font = TTF_OpenFont("res/Petitinho.ttf", 20);
}

void Text::clean() {
	TTF_CloseFont(font);
	delete this;
}

void Text::setX(int x) {
	this->x = x;
}

void Text::setY(int y) {
	this->y = y;
}

int Text::getX() {
	return x;
}

int Text::getY() {
	return y;
}

void Text::draw(SDL_Renderer* renderer) {
	surface = TTF_RenderText_Solid(font, message.c_str(), color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	rect = {x, y, texW, texH};
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_DestroyTexture(texture);
}

void Text::updateText(std::string msg) {
	message = msg;
}
