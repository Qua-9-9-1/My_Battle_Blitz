/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
*/

#include "GameSet.hpp"

namespace ware {
    GameSet::GameSet()
    {
        _rules = false;
        _winScore = 5;
    }

    GameSet::~GameSet()
    {
    }

    void GameSet::setNewParams(int const winScore, bool const rules, std::vector<sf::Color> colors)
    {
        _winScore = winScore;
        _rules = rules;
        _player1.setPlayer(0, colors[0], colors[1]);
        _player2.setPlayer(0, colors[2], colors[3]);
    }
}