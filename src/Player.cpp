/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** Player
*/

#include "Player.hpp"

namespace ware {
    Player::Player()
    {
        _score = 0;
        _skinColor = sf::Color::White;
        _clothesColor = sf::Color::White;
    }

    Player::~Player()
    {
    }

    void Player::update(sf::RenderWindow& window, float deltaTime)
    {
        (void)window;
        (void)deltaTime;
    }

    void Player::setPlayer(int score, sf::Color skinColor, sf::Color clothesColor)
    {
        _score = score;
        _skinColor = skinColor;
        _clothesColor = clothesColor;
    }
}