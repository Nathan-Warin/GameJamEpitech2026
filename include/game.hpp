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
        sf::Clock timeEvent;
        sf::Texture LifeRazorTexture;
        sf::Sprite LifeRazorSprite1;
        sf::Texture fireBallTexture;
        sf::Sprite fireBallSprite1;
        sf::Sprite fireBallSprite2;
        sf::Sprite fireBallSprite3;
        sf::Font font;
        sf::Text score;
        float pos = 0;
        float s_pos = 800;
        float mustachpos = 495;
        int life = 1;
        int Score = 0;
        float rotation = 0.2;
        float basefireballY1 = 799;
        float basefireballY2 = 899;
        float basefireballY3 = 999;
        int random = 1;
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