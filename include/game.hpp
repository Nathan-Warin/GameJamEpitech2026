#ifndef GAME_HPP_
    #define GAME_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>
#include <stdbool.h>

class Game {
    private:
        sf::RenderWindow _window;
        sf::Texture MustachTexture;
        sf::Texture backgroundTexture;
        sf::Sprite MustachSprite;
        sf::Sprite firstBackground;
        sf::Sprite secondBackground;
        sf::Event event;
        sf::Time timeEvent;
        float pos = 0;
        float s_pos = 800;
        float mustachpos = 510;
        int life = 3;
    public:
        Game();
        void gameLoop(void);
        void jumping(void);
        void setImagePos(void);
        void handleEvent(void);
        void checkCase(void);
        void displayGame(void);
        void timings(void);
};

#endif