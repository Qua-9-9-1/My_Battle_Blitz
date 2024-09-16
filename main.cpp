/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** main
*/

#include "Game.hpp"
#include "ErrorHandler.hpp"
#include <iostream>

int main(void)
{
    errorHandler();
    ware::Game game;
    game.run();
    return 0;
}