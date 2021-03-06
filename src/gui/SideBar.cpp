#include "SideBar.h"

SideBar::SideBar(Map* mapper, int xPos, int yPos) {
    x = xPos;
    y = yPos;
    width = 80;
    height = 500;
    map = mapper;
    sidebar = new Sprite(FileUtils::getImagePath() + "sidebar.png", x, y, width, height);
    mishAttack = new Sprite(FileUtils::getImagePath() + "markers.png", x + 5, y + 5, 32, 32);
    mishAttack->crop(16, 0, 0);
    mishAttackText = new Text(x + 45, y + 8, "3");
    mishDefense = new Sprite(FileUtils::getImagePath() + "markers.png", x + 5, y + 55, 32, 32);
    mishDefense->crop(16, 1, 0);
    mishDefenseText = new Text(x + 45, y + 58, "7");
    mishRecruit = new Sprite(FileUtils::getImagePath() + "markers.png", x + 5, y + 105, 32, 32);
    mishRecruit->crop(16, 2, 0);
    mishRecruitText = new Text(x + 45, y + 108, "15");
    mishHelp = new Sprite(FileUtils::getImagePath() + "markers.png", x + 5, y + 155, 32, 32);
    mishHelp->crop(16, 3, 0);
    mishHelpText = new Text(x + 45, y + 158, "2");
}

void SideBar::clean() {
    sidebar->clean();
    mishAttack->clean();
    mishAttackText->clean();
    mishDefense->clean();
    mishDefenseText->clean();
    mishRecruit->clean();
    mishRecruitText->clean();
    mishHelp->clean();
    mishHelpText->clean();
}

void SideBar::update() {
    std::string s = std::to_string(map->getAgentCount(0));
    mishAttackText->updateText(s);
    s = std::to_string(map->getAgentCount(1));
    mishDefenseText->updateText(s);
    s = std::to_string(map->getAgentCount(2));
    mishRecruitText->updateText(s);
    s = std::to_string(map->getAgentCount(3));
    mishHelpText->updateText(s);
}

void SideBar::draw(SDL_Renderer* renderer) {
    sidebar->draw(renderer);
    mishAttack->draw(renderer);
    mishAttackText->draw(renderer);
    mishDefense->draw(renderer);
    mishDefenseText->draw(renderer);
    mishRecruit->draw(renderer);
    mishRecruitText->draw(renderer);
    mishHelp->draw(renderer);
    mishHelpText->draw(renderer);
}

int SideBar::getWidth() {
    return width;
}

int SideBar::getHeight() {
    return height;
}
