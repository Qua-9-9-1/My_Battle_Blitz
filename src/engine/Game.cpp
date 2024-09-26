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
    _view2()
    {
        _window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "my_MicroGames");
        _window.setFramerateLimit(60);
        _view1.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
        _view1.setCenter(0, 0);
        //_view1.setCenter(_window.getSize().x / 2.f, _window.getSize().y / 2.f);
        _deltaTime = 0;
        _isMinigameRunning = false;
        _oneTimeArrows = true;
        _oneTimeButtons = true;
        _pause = false;
        _separatedViews = false;
        _window.setKeyRepeatEnabled(false);
        _luaManager = std::make_shared<LuaManager>();
        _luaMenuManager = std::make_shared<LuaManager>();
        _oneTimeArrows = false;
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
}