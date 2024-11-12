#include "Game.hpp"

namespace ware {
    void Game::doInput(const std::string& input)
    {
        if (_isMinigameRunning && !_pause) {
            _luaFunctions[input]();
        } else {
            _luaMenuFunctions[input]();
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
                if (_event.key.code == sf::Keyboard::Tab) {
                    _luaMenuFunctions["onP1Start"](_isMinigameRunning, _pause);
                    _pause = _isMinigameRunning ? !_pause : false;
                }
                if (_event.key.code == sf::Keyboard::Enter) {
                    _luaMenuFunctions["onP2Start"](_isMinigameRunning, _pause);
                    _pause = _isMinigameRunning ? !_pause : false;
                }
                if (_event.key.code == sf::Keyboard::Space) {
                    if (_separatedViews)
                        unifyViews();
                    else
                        separateViews();
                }
                handleOneTimeKeys();
            }
        }
        handleMutipleTimeKeys();
    }

    void Game::handleOneTimeKeys()
    {
        if (_oneTimeButtons) {
            if (_event.key.code == sf::Keyboard::C)
                doInput("onP1_1");
            if (_event.key.code == sf::Keyboard::V)
                doInput("onP1_2");
            if (_event.key.code == sf::Keyboard::B)
                doInput("onP1_3");
            if (_event.key.code == sf::Keyboard::Numpad1)
                doInput("onP2_1");
            if (_event.key.code == sf::Keyboard::Numpad2)
                doInput("onP2_2");
            if (_event.key.code == sf::Keyboard::Numpad3)
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

    void Game::handleMutipleTimeKeys()
    {
        if (!_oneTimeButtons) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                doInput("onP1_1");
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
                doInput("onP1_2");
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
                doInput("onP1_3");
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
                doInput("onP2_1");
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
                doInput("onP2_2");
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
                doInput("onP2_3");
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
}