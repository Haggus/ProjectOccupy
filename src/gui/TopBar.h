#pragma once
#include "../Sprite.h"
#include "../Text.h"
#include <sstream>

class TopBar {

    public:
        TopBar();
        void clean();
        void update(int turnCount, int currentPlayer, int agentCount, int agentMax);
        void draw(SDL_Renderer* renderer);

    private:
        Sprite* topbar;
        Sprite* clockIcon;
        Text* clockText;
        Sprite* teamIcon;
        Text* teamText;
        Sprite* agentIcon;
        Text* agentText;
};
