#include "BottomBar.h"

BottomBar::BottomBar(int xPos, int yPos) {
    x = xPos;
    y = yPos;
    bottombar = new Sprite(FileUtils::getImagePath() + "bottombar.png", x, y, 500, 80);
    btnAttack = new Button("btnAttack.png", x + 5, y + 5, 64, 64);
    btnDefense = new Button("btnDefense.png", x + 80, y + 5, 64, 64);
}

void BottomBar::clean() {
    bottombar->clean();
}

void BottomBar::handleEvent(SDL_Event* e, int mouseX, int mouseY) {
    btnAttack->handleEvent(e, mouseX, mouseY);
    if(btnAttack->isButtonPressed()) {
        std::cout << "attack pressed" << std::endl;
    }
    btnDefense->handleEvent(e, mouseX, mouseY);
    if(btnDefense->isButtonPressed()) {
        std::cout << "defense pressed" << std::endl;
    }
}

void BottomBar::draw(SDL_Renderer* renderer) {
    bottombar->draw(renderer);
    btnAttack->draw(renderer);
    btnDefense->draw(renderer);
}
