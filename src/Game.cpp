/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** Game
*/

#include "Game.hpp"
#include <filesystem>

namespace ware {
    Game::Game():
    _image(std::filesystem::current_path().string() + "/assets/sprites/" + "chains_race.png"),
    _sprite(_image.getImage()),
    _text("Hello World", std::filesystem::current_path().string() + "/assets/font/Mario-Kart-DS.ttf"),
    _sound(std::filesystem::current_path().string() + "/assets/sounds/random.ogg"),
    _music(std::filesystem::current_path().string() + "/assets/music/menu.ogg"),
    _clock(),
    _view1(sf::FloatRect(0, 0, 800, 600)),
    _view2(sf::FloatRect(0, 0, 800, 600)),
    _luaManager()
    {
        _window.create(sf::VideoMode(800, 600), "my_MicroGames");
        _window.setFramerateLimit(60);
        _deltaTime = 0;
        _separatedViews = false;
        _sprite.setPosition(sf::Vector2f(0, 0));
        _sprite.setPosition(static_cast<sf::Vector2f>(_window.getSize()) / 2.f);
        _text.setPosition(sf::Vector2f(100, 100));
    }

    Game::~Game()
    {
    }

    void Game::run()
    {
        _music.play();

        while (_window.isOpen()) {
            while (_window.pollEvent(_event)) {
                if (_event.type == sf::Event::Closed)
                    _window.close();
                if (_event.type == sf::Event::KeyPressed) {
                    if (_event.key.code == sf::Keyboard::Escape)
                        _window.close();
                    if (_event.key.code == sf::Keyboard::Space) {
                        _sound.play();
                    }
                    if (_event.key.code == sf::Keyboard::A) {
                        _sprite.disappear();
                        _text.disappear();
                        _sound.setVolume(10);
                    }
                    if (_event.key.code == sf::Keyboard::B) {
                        _text.setColor(sf::Color::Red);
                        _image.setPlayerColor(sf::Color::Red, sf::Color::Blue);
                        _image.flipImage(true, true);
                        _sprite.loadImage(_image.getImage());
                    }
                    if (_event.key.code == sf::Keyboard::C) {
                        separateViews();
                    }
                    if (_event.key.code == sf::Keyboard::D) {
                        unifyViews();
                    }
                }
            }
            _deltaTime = _clock.restart().asSeconds();
            _window.clear(sf::Color(40, 40, 0));
            if (_separatedViews) {
                // Dessiner les éléments pour la première vue
                _window.setView(_view1);
                _sprite.update(_window, 0.1);
                _text.update(_window, 0.1);

                // Dessiner les éléments pour la deuxième vue
                _window.setView(_view2);
                _sprite.update(_window, 0.1);
                _text.update(_window, 0.1);
            } else {
                // Dessiner les éléments pour la vue unifiée
                _window.setView(_view1);
                _sprite.update(_window, 0.1);
                _text.update(_window, 0.1);
            }
            _window.display();
        }
    }

    void Game::handleEvents(bool oneTimeArrows)
    {
        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed)
                _window.close();
            if (_event.type == sf::Event::KeyPressed) {
                if (_event.key.code == sf::Keyboard::Space) {

                }
            }
        }

    }

    void Game::startMinigame(const std::string minigameName)
    {
       _luaManager.loadScript("scripts/" + minigameName + ".lua");
    } 

    void Game::separateViews()
    {
        if (_separatedViews)
            return;

        _view1.setViewport(sf::FloatRect(0, 0, 0.5f, 1));
        _view2.setViewport(sf::FloatRect(0.5f, 0, 0.5f, 1));
        _view1.setSize(_window.getSize().x / 2.f, _window.getSize().y);
        _view2.setSize(_window.getSize().x / 2.f, _window.getSize().y);
        _separatedViews = true;
}

    void Game::unifyViews()
    {
        if (!_separatedViews)
            return;
         _view1.setViewport(sf::FloatRect(0, 0, 1, 1));
        _view1.setCenter(_window.getSize().x / 2.f, _window.getSize().y / 2.f);
        _view1.setSize(_window.getSize().x, _window.getSize().y);
        _separatedViews = false;
    }
    
}