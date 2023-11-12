#include "../include/game.hpp"

Game::Game()
{
    MustachTexture.loadFromFile("assets/mustach.png");
    backgroundTexture.loadFromFile("assets/background.jpg");
    firstBackground.setTexture(backgroundTexture);
    secondBackground.setTexture(backgroundTexture);
    MustachSprite.setTexture(MustachTexture);
    MustachSprite.setScale(0.8, 0.8);
    gameLoop();
}

void Game::gameLoop(void)
{
    _window.create(sf::VideoMode(800, 600), "Moustachio");

    while (_window.isOpen()) {
        setImagePos();
        handleEvent();
        checkCase();
        timings();
        displayGame();
    }
}

void Game::jumping(void)
{
    sf::Clock timer;
    int base = mustachpos;
    sf::Time timeLimit = sf::seconds(1.5f);

    while (timer.getElapsedTime().asSeconds() < timeLimit.asSeconds()) {
        pos -= 0.08;
        s_pos -= 0.08;
        int timejump = timer.getElapsedTime().asMilliseconds();
        if (timejump <= 750 && mustachpos > (base - 65))
            mustachpos -= 0.07;
        if (timejump > 750 && mustachpos < 510)
            mustachpos += 0.07;
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            _window.close();
            break;
        }
        setImagePos();
        displayGame();
    }
}

void Game::setImagePos(void)
{
    firstBackground.setPosition(pos, 0);
    secondBackground.setPosition(s_pos, 0);
    MustachSprite.setPosition(20, mustachpos);
}

void Game::handleEvent(void)
{
    _window.pollEvent(event);
    if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            _window.close();
    pos -= 0.08;
    s_pos -= 0.08;
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
        jumping();
    }
}

void Game::checkCase(void)
{
    if (pos <= -800)
        pos = 0;
    if (s_pos <= 0)
        s_pos = 800;
}

void Game::displayGame(void)
{
    _window.clear();
    _window.draw(firstBackground);
    _window.draw(secondBackground);
    _window.draw(MustachSprite);
    _window.display();
}

void Game::timings(void)
{

}