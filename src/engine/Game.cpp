/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
*/

#include "Game.hpp"
#include <filesystem>

namespace ware {
    Game::Game():
    _clock(),
    _view1(sf::FloatRect(0, 0, 800, 600)),
    _view2(sf::FloatRect(0, 0, 800, 600))
    {
        _window.create(sf::VideoMode(800, 600), "my_MicroGames");
        _window.setFramerateLimit(60);
        _deltaTime = 0;
        _isMinigameRunning = false;
        _oneTimeArrows = true;
        _window.setKeyRepeatEnabled(false);
        _luaManager = std::make_shared<LuaManager>();
        _oneTimeArrows = false;
        startMinigame("game_menu");
    }

    Game::~Game()
    {
    }

    void Game::run()
    {
        while (_window.isOpen()) {
            handleEvents();
            _deltaTime = _clock.restart().asSeconds();
            _window.clear(sf::Color(40, 40, 0));
            _luaFunctions["update"](_window, _deltaTime);
            // if (_separatedViews) {
            //     _window.setView(_view1);
            //     // appeller la fonction du code lua pour update p1
            //     _sprite.update(_window, 0.1);
            //     _text.update(_window, 0.1);
            //     _window.setView(_view2);
            //     // appeller la fonction du code lua pour update p2
            //     _sprite.update(_window, 0.1);
            //     _text.update(_window, 0.1);
            // } else {
            //     _window.setView(_view1);
            //     // appeller la fonction du code lua pour update
            //     _luaFunctions["draw"]();
            // }
            _window.display();
        }
    }

    void Game::handleEvents()
    {
        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                _window.close();
            if (_event.type == sf::Event::KeyPressed) {
                if (_event.key.code == sf::Keyboard::C) {
                    _luaFunctions["onP1_1"]();
                }
                if (_event.key.code == sf::Keyboard::V) {
                    _luaFunctions["onP1_2"]();
                }
                if (_event.key.code == sf::Keyboard::B) {
                    _luaFunctions["onP1_3"]();
                }
                if (_event.key.code == sf::Keyboard::Numpad1) {
                    _luaFunctions["onP2_1"]();
                }
                if (_event.key.code == sf::Keyboard::Numpad2) {
                    _luaFunctions["onP2_2"]();
                }
                if (_event.key.code == sf::Keyboard::Numpad3) {
                    _luaFunctions["onP2_3"]();
                }
                if (_oneTimeArrows) {
                    if (_event.key.code == sf::Keyboard::Z)
                        _luaFunctions["onP1Up"]();
                    if (_event.key.code == sf::Keyboard::S)
                        _luaFunctions["onP1Down"]();
                    if (_event.key.code == sf::Keyboard::D)
                        _luaFunctions["onP1Right"]();
                    if (_event.key.code == sf::Keyboard::Q)
                        _luaFunctions["onP1Left"]();
                    if (_event.key.code == sf::Keyboard::Up)
                        _luaFunctions["onP2Up"]();
                    if (_event.key.code == sf::Keyboard::Down)
                        _luaFunctions["onP2Down"]();
                    if (_event.key.code == sf::Keyboard::Right)
                        _luaFunctions["onP2Right"]();
                    if (_event.key.code == sf::Keyboard::Left)
                        _luaFunctions["onP2Left"]();
                }
            }
        }
        if (!_oneTimeArrows) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                _luaFunctions["onP1Up"]();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                _luaFunctions["onP1Down"]();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                _luaFunctions["onP1Right"]();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                _luaFunctions["onP1Left"]();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                _luaFunctions["onP2Up"]();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                _luaFunctions["onP2Down"]();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                _luaFunctions["onP2Right"]();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                _luaFunctions["onP2Left"]();
        }
    }

    void Game::startMinigame(const std::string minigameName)
    {
        _isMinigameRunning = true;
        if (loadMinigame(minigameName) != 0) {
                _luaManager->unloadScript();
                _isMinigameRunning = false;
                exit(1);
        }
    }

    int Game::loadMinigame(const std::string minigameName)
    {
        std::vector<std::string> requiredFunctions = {
            "update", "onP1Left", "onP1Right", "onP1Up", "onP1Down",
            "onP2Left", "onP2Right", "onP2Up", "onP2Down", "onP1_1", "onP1_2",
            "onP1_3", "onP2_1", "onP2_2", "onP2_3"
        };

        _luaFunctions.clear();
        _luaManager->loadScript("/scripts/" + minigameName + ".lua");
        _luaFunctions["init"] = _luaManager->getFunction("init");
        if (!_luaFunctions["init"].valid()) {
            std::cerr << "Failed to get Lua function init" << std::endl;
            return 1;
        }
        try {
            sol::protected_function_result result = _luaFunctions["init"]();
            if (!result.valid() || result.get<bool>() == false) {
                sol::error err = result;
                std::cerr << "Error initializing game: " << err.what() << std::endl;
                return 1;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error initializing game: " << e.what() << std::endl;
            return 1;
        }
        _luaFunctions["update"] = _luaManager->getFunction("update");
        _luaFunctions["onP1Left"] = _luaManager->getFunction("on_P1_left");
        _luaFunctions["onP1Right"] = _luaManager->getFunction("on_P1_right");
        _luaFunctions["onP1Up"] = _luaManager->getFunction("on_P1_up");
        _luaFunctions["onP1Down"] = _luaManager->getFunction("on_P1_down");
        _luaFunctions["onP2Left"] = _luaManager->getFunction("on_P2_left");
        _luaFunctions["onP2Right"] = _luaManager->getFunction("on_P2_right");
        _luaFunctions["onP2Up"] = _luaManager->getFunction("on_P2_up");
        _luaFunctions["onP2Down"] = _luaManager->getFunction("on_P2_down");
        _luaFunctions["onP1_1"] = _luaManager->getFunction("on_P1_1");
        _luaFunctions["onP1_2"] = _luaManager->getFunction("on_P1_2");
        _luaFunctions["onP1_3"] = _luaManager->getFunction("on_P1_3");
        _luaFunctions["onP2_1"] = _luaManager->getFunction("on_P2_1");
        _luaFunctions["onP2_2"] = _luaManager->getFunction("on_P2_2");
        _luaFunctions["onP2_3"] = _luaManager->getFunction("on_P2_3");
        for (const auto& func : requiredFunctions)
            if (!_luaFunctions[func].valid())
                return 1;
        return 0;
    }

    // void Game::separateViews()
    // {
    //     if (_separatedViews)
    //         return;
    //     _view1.setViewport(sf::FloatRect(0, 0, 0.5f, 1));
    //     _view2.setViewport(sf::FloatRect(0.5f, 0, 0.5f, 1));
    //     _view1.setSize(_window.getSize().x / 2.f, _window.getSize().y);
    //     _view2.setSize(_window.getSize().x / 2.f, _window.getSize().y);
    //     _separatedViews = true;
    // }

    // void Game::unifyViews()
    // {
    //     if (!_separatedViews)
    //         return;
    //      _view1.setViewport(sf::FloatRect(0, 0, 1, 1));
    //     _view1.setCenter(_window.getSize().x / 2.f, _window.getSize().y / 2.f);
    //     _view1.setSize(_window.getSize().x, _window.getSize().y);
    //     _separatedViews = false;
    // }

    void Game::setOneTimeArrows(bool oneTimeArrows)
    {
        _oneTimeArrows = oneTimeArrows;
    }
}