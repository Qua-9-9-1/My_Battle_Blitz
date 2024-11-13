/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
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

    void Player::update()
    {
    }

    void Player::setPlayer(int score, sf::Color skinColor, sf::Color clothesColor)
    {
        _score = score;
        _skinColor = skinColor;
        _clothesColor = clothesColor;
    }
}