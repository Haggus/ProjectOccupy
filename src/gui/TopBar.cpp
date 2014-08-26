#include "TopBar.h"

TopBar::TopBar() {
    topbar = new Sprite(FileUtils::getImagePath() + "topbar.png", 0, 0, 500, 40);
    clockIcon = new Sprite(FileUtils::getImagePath() + "clock.png", 5, 5, 32, 32);
    clockText = new Text(45, 8, "0");
    teamIcon = new Sprite(FileUtils::getImagePath() + "teams.png", 100, 5, 32, 32);
    teamIcon->crop(32, 0, 0);
    teamText = new Text(145, 8, "Player 0");
    agentIcon = new Sprite(FileUtils::getImagePath() + "agent_small.png", 300, 5, 32, 32);
    agentText = new Text(340, 8, "0/10");
}

void TopBar::clean() {
    topbar->clean();
    clockIcon->clean();
    clockText->clean();
    teamIcon->clean();
    teamText->clean();
    agentIcon->clean();
    agentText->clean();
}

void TopBar::update(int turnCount, int currentPlayer, int agentCount, int agentMax) {
    std::string s = std::to_string(turnCount);
    clockText->updateText(s);
    s = std::to_string(currentPlayer);
    teamText->updateText("Player " + s);
    if(currentPlayer == 0) {
        teamIcon->crop(32, 0, 0);
    } else {
        teamIcon->crop(32, 1, 0);
    }
    std::stringstream ss;
    ss << agentCount << "/" << agentMax;
    agentText->updateText(ss.str());
}

void TopBar::draw(SDL_Renderer* renderer) {
    topbar->draw(renderer);
    clockIcon->draw(renderer);
    clockText->draw(renderer);
    teamIcon->draw(renderer);
    teamText->draw(renderer);
    agentIcon->draw(renderer);
    agentText->draw(renderer);
}
