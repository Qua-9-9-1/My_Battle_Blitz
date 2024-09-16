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
    _sprite(std::filesystem::current_path().string() + "/assets/sprites/" + "stomp.png"),
    _text("Hello World", std::filesystem::current_path().string() + "/assets/font/Mario-Kart-DS.ttf"),
    _sound(std::filesystem::current_path().string() + "/assets/sounds/random.ogg"),
    _music(std::filesystem::current_path().string() + "/assets/music/menu.ogg"),
    _luaManager()
    {
        _window.create(sf::VideoMode(800, 600), "my_MicroGames");
        _window.setFramerateLimit(60);
        _deltaTime = 0;
        _view = std::make_shared<ware::View>();
        _view->separateViews();
        // _sprite = ware::Sprite::Sprite("../assets/sprites/thumb_wrestling.png");
        _sprite.setPosition(static_cast<sf::Vector2f>(_window.getSize()) / 2.f);
        // _sound = ware::Sound::Sound("../assets/sounds/random.ogg");
        // _text = ware::Text::Text("Hello World", "../assets/fonts/Mario-Kart-DS.ttf");
        _text.setPosition(sf::Vector2f(100, 100));
        // _music = ware::Music::Music("../assets/music/menu.ogg");
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
                        _sprite.setPlayerColor(sf::Color::Red, sf::Color::Blue);
                    }
                }
            }
            _window.clear();
            // Draw here
            _sprite.update(_window, 0.1);
            _text.update(_window, 0.1);
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
        _view->separateViews();
    }
}