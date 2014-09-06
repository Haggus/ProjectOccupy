#include "Sprite.h"

Sprite::Sprite(std::string filePath, int x, int y, int width, int height) {
	image = NULL;
	texture = NULL;
	image = IMG_Load(filePath.c_str());
	if(image == NULL) {
		std::cout << "Couldnt load " << filePath.c_str() << std::endl;
	}

	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	rcrop.x = 0;
	rcrop.y = 0;
	rcrop.w = 0;
	rcrop.h = 0;
}

void Sprite::clean() {
	SDL_FreeSurface(image);
}

void Sprite::crop(int size, int x, int y) {
	rcrop.x = size * x;
	rcrop.y = size * y;
	rcrop.w = size;
	rcrop.h = size;
}

void Sprite::draw(SDL_Renderer* renderer) {
	if(texture != NULL) {
		if(rcrop.x == 0 && rcrop.y == 0 && rcrop.w == 0 && rcrop.h == 0) {
			SDL_RenderCopy(renderer, texture, NULL, &rect);
		} else {
			SDL_RenderCopy(renderer, texture, &rcrop, &rect);
		}
	} else {
		texture = SDL_CreateTextureFromSurface(renderer, image);
	}
}

void Sprite::setX(int x) {
	rect.x = x;
}

void Sprite::setY(int y) {
	rect.y = y;
}

void Sprite::setW(int w) {
	rect.w = w;
}

void Sprite::setH(int h) {
	rect.h = h;
}

void Sprite::setPosition(int x, int y) {
	rect.x = x;
	rect.y = y;
}

int Sprite::getX() {
	return rect.x;
}

int Sprite::getY() {
	return rect.y;
}

int Sprite::getW() {
	return rect.w;
}

int Sprite::getH() {
	return rect.h;
}
