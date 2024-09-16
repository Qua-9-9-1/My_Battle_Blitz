/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** Renderer
*/

#include "Renderer.hpp"


namespace ware {
    Sprite::Sprite(const std::string filePath)
    {
        loadFile(filePath);
    }

    Sprite::~Sprite()
    {
    }

    void Sprite::loadFile(const std::string filePath)
    {
        _image.loadFromFile(filePath);
        reloadSprite();
    }

    void Sprite::reloadSprite()
    {
        _texture.loadFromImage(_image);
        _sprite.setTexture(_texture);
    }

    void Sprite::update(sf::RenderWindow& window, float deltaTime)
    {
        window.draw(_sprite);
    }

    void Sprite::disappear()
    {
        _sprite.setColor(sf::Color::Transparent);
    }

    void Sprite::setPosition(sf::Vector2f pos)
    {
        _sprite.setPosition(pos);
    }

    void Sprite::setScale(sf::Vector2f scale)
    {
        _sprite.setScale(scale);
    }

    void Sprite::setRotation(float angle)
    {
        _sprite.setRotation(angle);
    }

    void Sprite::setTextureRect(sf::Vector2f start_pos, int width, int height)
    {
        _sprite.setTextureRect(sf::IntRect(start_pos.x, start_pos.y, width, height));
    }

    void Sprite::setColor(sf::Color color)
    {
        _sprite.setColor(color);
    }

    void Sprite::colorize(sf::Color colorToReplace, sf::Color colorToApply)
    {
        sf::Vector2u size = _image.getSize();

        for (unsigned int x = 0; x < size.x; ++x) {
            for (unsigned int y = 0; y < size.y; ++y) {
                if (_image.getPixel(x, y) == colorToReplace) {
                    _image.setPixel(x, y, colorToApply);
                }
            }
        }
    }

    void Sprite::setPlayerColor(sf::Color skinColor, sf::Color clothesColor)
    {
        colorize(sf::Color(234, 72, 234), skinColor);
        colorize(sf::Color(181, 56, 181), skinColor); // with darker color
        colorize(sf::Color(167, 255, 58), clothesColor);
        colorize(sf::Color(132, 198, 45), clothesColor); // with darker color
        colorize(sf::Color(208, 255, 147), clothesColor); // with lighter color
        reloadSprite();
    }

    Text::Text(const std::string text, const std::string fontPath)
    {
        loadFile(fontPath);
        setString(text);
    }

    Text::~Text()
    {
    }

    void Text::update(sf::RenderWindow& window, float deltaTime)
    {
        window.draw(_text);
    }

    void Text::loadFile(const std::string filePath)
    {
        _font.loadFromFile(filePath);
        _text.setFont(_font);
    }

    void Text::disappear()
    {
        _text.setFillColor(sf::Color::Transparent);
    }

    void Text::setPosition(sf::Vector2f pos)
    {
        _text.setPosition(pos);
    }

    void Text::setScale(sf::Vector2f scale)
    {
        _text.setScale(scale);
    }

    void Text::setRotation(float angle)
    {
        _text.setRotation(angle);
    }

    void Text::setColor(sf::Color color)
    {
        _text.setFillColor(color);
    }

    void Text::setBorderColor(sf::Color color)
    {
        _text.setOutlineColor(color);
    }

    void Text::setString(const std::string text)
    {
        _text.setString(text);
    }

    void Text::setCharacterSize(int size)
    {
        _text.setCharacterSize(size);
    }
}