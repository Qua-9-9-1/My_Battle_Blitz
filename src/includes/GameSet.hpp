/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** GameSet
*/

#pragma once

#include "Player.hpp"
#include <queue>

namespace ware {
    class GameSet {
        public:
            GameSet();
            ~GameSet();
            void setNewParams(int const winScore, bool const rules, std::vector<sf::Color> colors);
            void storeMinigameInQueue();
        private:
            Player                                      _player1;
            Player                                      _player2;
            std::queue<std::pair<int, std::string>>     _minigameQueue;
            bool                                        _rules;
            int                                         _winScore;

    };
}