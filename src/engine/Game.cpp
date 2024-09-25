/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
*/

#include "Game.hpp"

#include "Audio.hpp"
namespace ware {
    Game::Game():
    _clock(),
    _view1(),
    _view2()
    {
        _window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "my_MicroGames");
        _window.setFramerateLimit(60);
        _view1.setSize(_window.getSize().x, _window.getSize().y);
        _view1.setCenter(_window.getSize().x / 2.f, _window.getSize().y / 2.f);
        _deltaTime = 0;
        _isMinigameRunning = false;
        _oneTimeArrows = true;
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
            _window.clear(sf::Color(40, 40, 0));
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

    void Game::handleEvents()
    {
        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                _window.close();
            if (_event.type == sf::Event::Resized)
                resizeViews(_event.size.width, _event.size.height);
            if (_event.type == sf::Event::KeyPressed) {
                if (_event.key.code == sf::Keyboard::C) {
                    doInput("onP1_1");
                }
                if (_event.key.code == sf::Keyboard::V) {
                    doInput("onP1_2");
                }
                if (_event.key.code == sf::Keyboard::B) {
                    doInput("onP1_3");
                }
                if (_event.key.code == sf::Keyboard::Numpad1) {
                    doInput("onP2_1");
                }
                if (_event.key.code == sf::Keyboard::Numpad2) {
                    doInput("onP2_2");
                }
                if (_event.key.code == sf::Keyboard::Numpad3) {
                    doInput("onP2_3");
                }
                if (_oneTimeArrows) {
                    if (_event.key.code == sf::Keyboard::Z)
                        doInput("onP1Up");
                    if (_event.key.code == sf::Keyboard::S)
                        doInput("onP1Down");
                    if (_event.key.code == sf::Keyboard::D)
                        doInput("onP1Right");
                    if (_event.key.code == sf::Keyboard::Q)
                        doInput("onP1Left");
                    if (_event.key.code == sf::Keyboard::Up)
                        doInput("onP2Up");
                    if (_event.key.code == sf::Keyboard::Down)
                        doInput("onP2Down");
                    if (_event.key.code == sf::Keyboard::Right)
                        doInput("onP2Right");
                    if (_event.key.code == sf::Keyboard::Left)
                        doInput("onP2Left");
                }
            }
        }
        if (!_oneTimeArrows) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                doInput("onP1Up");
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                doInput("onP1Down");
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                doInput("onP1Right");
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                doInput("onP1Left");
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                doInput("onP2Up");
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                doInput("onP2Down");
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                doInput("onP2Right");
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                doInput("onP2Left");
        }
    }

    void Game::setOneTimeArrows(bool oneTimeArrows)
    {
        _oneTimeArrows = oneTimeArrows;
    }

    void Game::resizeViews(int width, int height)
    {
        float aspectRatio = static_cast<float>(width) / static_cast<float>(height);

        if (aspectRatio > 1.0f) {
            _view1.setSize(WINDOW_WIDTH * aspectRatio, WINDOW_HEIGHT);
        } else {
            _view1.setSize(WINDOW_WIDTH, WINDOW_HEIGHT / aspectRatio);
        }
        _view1.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    }
}