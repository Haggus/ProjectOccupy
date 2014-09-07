#include "BottomBar.h"

BottomBar::BottomBar(std::vector<Player>* playaz, Selector* selector, int xPos, int yPos) {
    x = xPos;
    y = yPos;
    width = 500;
    height = 80;
    select = selector;
    players = playaz;
    bottombar = new Sprite(FileUtils::getImagePath() + "bottombar.png", x, y, width, height);
    btnAttack = new Button("btnAttack.png", x + 5, y + 5, 64, 64);
    btnDefense = new Button("btnDefense.png", x + 80, y + 5, 64, 64);
}

void BottomBar::clean() {
    bottombar->clean();
}

void BottomBar::handleEvent(SDL_Event* e, int mouseX, int mouseY, int currentPlayer) {
    btnAttack->handleEvent(e, mouseX, mouseY);
    if(btnAttack->isButtonPressed()) {
        std::cout << "attack pressed" << std::endl;
        if(players->at(currentPlayer).removeAgent()) {
            select->getSelected()->addMembers(1, currentPlayer, 0);
        }
    }
    btnDefense->handleEvent(e, mouseX, mouseY);
    if(btnDefense->isButtonPressed()) {
        std::cout << "defense pressed" << std::endl;
        if(players->at(currentPlayer).removeAgent()) {
            select->getSelected()->addMembers(1, currentPlayer, 1);
        }
    }
}

bool BottomBar::collision(int xPos, int yPos) {
    if(xPos >= x && xPos <= (x + width)) {
        if(yPos >= y && yPos <= (y + height)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void BottomBar::draw(SDL_Renderer* renderer) {
    bottombar->draw(renderer);
    btnAttack->draw(renderer);
    btnDefense->draw(renderer);
}
