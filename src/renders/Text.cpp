#include "Renderer.hpp"

namespace ware {

    Text::Text(const std::string text, const std::string fontPath)
    {
        loadFile(fontPath);
        setString(text);
    }

    Text::~Text()
    {
    }

    void Text::update(sf::RenderWindow& window)
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

    void Text::setPosition(float x, float y)
    {
        _text.setPosition(x, y);
    }

    void Text::move(float x, float y)
    {
        _text.move(x, y);
    }

    void Text::setScale(float x, float y)
    {
        _text.setScale(x, y);
    }

    void Text::setRotation(float angle)
    {
        _text.setRotation(angle);
    }

    void Text::rotate(float angle)
    {
        _text.rotate(angle);
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