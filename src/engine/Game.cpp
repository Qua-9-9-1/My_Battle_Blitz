/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
*/

#include "Game.hpp"

namespace ware {
    Game::Game():
    _clock(),
    _view1(),
    _view2(),
    _fullScreen(false),
    _deltaTime(0),
    _isMinigameRunning(false),
    _oneTimeArrows(true),
    _oneTimeButtons(true),
    _pause(false),
    _separatedViews(false)
    {
        createWindow();
        _view1.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
        _view1.setCenter(0, 0);
        _window.setKeyRepeatEnabled(false);
        _luaManager = std::make_shared<LuaManager>();
        _luaMenuManager = std::make_shared<LuaManager>();
        launchMenu();
    }

    Game::~Game()
    {
    }

    void Game::run()
    {
        while (_window.isOpen()) {
            handleEvents();
            _deltaTime = _clock.restart().asSeconds();
            _window.clear();
            _window.setView(_view1.getView());
            _luaMenuFunctions["update"](_window, _deltaTime);
            if (_isMinigameRunning) {
                _luaFunctions["update"](_deltaTime);
                if (_separatedViews) {
                    _window.setView(_view1.getView());
                    _luaFunctions["draw"](_window, true); //p1
                    _window.setView(_view2.getView());
                    _luaFunctions["draw"](_window, false); //p2
                } else {
                    _window.setView(_view1.getView());
                    _luaFunctions["draw"](_window);
                }
            }
            _window.display();
        }
    }

    void Game::createWindow()
    {
        sf::Image icon;
        icon.loadFromFile("assets/sprites/game_logo.png");
        if (_fullScreen) {
            _window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "my_MicroGames", sf::Style::Fullscreen);
        } else {
            _window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "my_MicroGames");
        }
        _window.setFramerateLimit(60);
        _window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
        _window.setMouseCursorVisible(false);
    }
}