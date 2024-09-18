/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
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