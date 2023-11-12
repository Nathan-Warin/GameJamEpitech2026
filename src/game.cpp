#include "../include/game.hpp"

Game::Game()
{
    MustachTexture.loadFromFile("assets/mustach.png");
    backgroundTexture.loadFromFile("assets/background.jpg");
    LifeRazorTexture.loadFromFile("assets/razor.png");
    fireBallTexture.loadFromFile("assets/fireball.png");
    font.loadFromFile("assets/arial.ttf");
    firstBackground.setTexture(backgroundTexture);
    secondBackground.setTexture(backgroundTexture);
    MustachSprite.setTexture(MustachTexture);
    LifeRazorSprite1.setTexture(LifeRazorTexture);
    fireBallSprite1.setTexture(fireBallTexture);
    fireBallSprite2.setTexture(fireBallTexture);
    fireBallSprite3.setTexture(fireBallTexture);
    MustachSprite.setScale(0.8, 0.8);
    LifeRazorSprite1.setScale(0.5, 0.5);
    score.setString("SCORE: " + std::to_string(Score));
    score.setFont(font);
    score.setFillColor(sf::Color::White);
    score.setCharacterSize(20);
    score.setPosition(20, 80);
    MustachSprite.setOrigin(70, 23);
    gameLoop();
}

void Game::gameLoop(void)
{
    _window.create(sf::VideoMode(800, 600), "running mustach");

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
        if (timejump <= 750 && mustachpos > (base - 145))
            mustachpos -= 0.09;
        if (timejump > 750 && mustachpos < 495)
            mustachpos += 0.07;
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            _window.close();
            break;
        }
        timings();
        checkCase();
        setImagePos();
        displayGame();
    }
}

void Game::setImagePos(void)
{
    LifeRazorSprite1.setPosition(10, 10);
    firstBackground.setPosition(pos, 0);
    secondBackground.setPosition(s_pos, 0);
    MustachSprite.setPosition(95, mustachpos);
    fireBallSprite1.setPosition(basefireballY1, 435);
    fireBallSprite2.setPosition(basefireballY2, 435);
    fireBallSprite3.setPosition(basefireballY3, 435);
}

void Game::handleEvent(void)
{
    _window.pollEvent(event);
    if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            _window.close();
    pos -= 0.08;
    s_pos -= 0.08;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        jumping();
}

void Game::checkCase(void)
{
    if (pos <= -800)
        pos = 0;
    if (s_pos <= 0)
        s_pos = 800;
    MustachSprite.rotate(rotation);
    if (((mustachpos + 20) > 450 && basefireballY1 < 95 && basefireballY1 > 80) || ((mustachpos + 20) > 450 && basefireballY2 < 95 && basefireballY2 > 80) || ((mustachpos + 20) > 450 && basefireballY3 < 95 && basefireballY3 > 80))
        life--;
    if (life == 0)
        _window.close();
}

void Game::displayGame(void)
{
    _window.clear();
    _window.draw(firstBackground);
    _window.draw(secondBackground);
    _window.draw(MustachSprite);
    _window.draw(score);
    _window.draw(fireBallSprite1);
    _window.draw(fireBallSprite2);
    _window.draw(fireBallSprite3);
    if (life == 1)
        _window.draw(LifeRazorSprite1);
    _window.display();
}

void Game::timings(void)
{
    if (timeEvent.getElapsedTime().asSeconds() > 1) {
        if (random >= 1)
            basefireballY1 -= 0.3;
        if (random >= 2)
            basefireballY2 -= 0.3;
        if (random >= 3)
            basefireballY3 -= 0.3;
    }   
    if (basefireballY1 < -100) {
        basefireballY1 = 799;
        basefireballY2 = 930;
        basefireballY3 = 1080;
        if (random == 1)
            Score += 100;
        else if (random == 2)
            Score += 200;
        else if (random == 3)
            Score += 300;
        score.setString("SCORE: " + std::to_string(Score));
        timeEvent.restart();
        random = (rand() % 3) + 1;
    }
}