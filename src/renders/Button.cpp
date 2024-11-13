#include "Renderer.hpp"

namespace ware {
    
    Button::Button(const std::string text, const std::string fontPath, float x, float y)
    {
        _padding = {0, 0};
        _font.loadFromFile(fontPath);
        _text.setFont(_font);
        setString(text);
        _text.setFillColor(sf::Color::Black);
        _button.setFillColor(sf::Color::White);
        _button.setOutlineColor(sf::Color::Black);
        _button.setOutlineThickness(2);
        centerText();
        setCentered();
        setPosition(x, y);
    }

    Button::~Button()
    {
    }

    void Button::update()
    {
    }

    void Button::draw(sf::RenderWindow& window)
    {
        window.draw(_button);
        window.draw(_text);
    }

    void Button::disappear()
    {
        _text.setFillColor(sf::Color::Transparent);
        _button.setFillColor(sf::Color::Transparent);
        _button.setOutlineColor(sf::Color::Transparent);
    }

    void Button::setCentered()
    {
        _text.setOrigin(_text.getLocalBounds().width / 2.0f, _text.getLocalBounds().height / 2.0f);
        _button.setOrigin(_button.getLocalBounds().width / 2.0f, _button.getLocalBounds().height / 2.0f);
    }

    void Button::setPosition(float x, float y)
    {
        _button.setPosition(x, y);
        setCentered();
        centerText();
    }

    void Button::move(float x, float y)
    {
        _text.move(x, y);
        _button.move(x, y);
    }

    void Button::setScale(float x, float y)
    {
        _text.setScale(x, y);
        _button.setScale(x, y);
        setCentered();
        centerText();
    }

    void Button::setRotation(float angle)
    {
        _text.setRotation(angle);
        _button.setRotation(angle);
    }

    void Button::rotate(float angle)
    {
        _text.rotate(angle);
        _button.rotate(angle);
    }

    void Button::setColor(float r, float g, float b, float a)
    {
        _button.setFillColor(sf::Color(r, g, b, a));
    }

    void Button::setBorderColor(float r, float g, float b, float a)
    {
        _button.setOutlineColor(sf::Color(r, g, b, a));
    }

    void Button::setTextColor(float r, float g, float b, float a)
    {
        _text.setFillColor(sf::Color(r, g, b, a));
    }

    void Button::setString(const std::string text)
    {
        _text.setString(text);
        _button.setSize(sf::Vector2f(_text.getLocalBounds().width, _text.getLocalBounds().height));
        setCentered();
        centerText();
    }

    void Button::setSize(float x, float y)
    {
        _button.setSize(sf::Vector2f(x, y));
        setCentered();
        centerText();
    }

    void Button::setTextSize(int size)
    {
        _text.setCharacterSize(size);
        setCentered();
        centerText();
    }

    void Button::setBorder(float thickness)
    {
        _button.setOutlineThickness(thickness);
    }

    void Button::setTexture(const std::string filePath)
    {
        _buttonTexture.loadFromFile(filePath);
        _button.setTexture(&_buttonTexture);
    }

    void Button::setTextureRect(int start_x, int start_y, int width, int height)
    {
        _button.setTextureRect(sf::IntRect(start_x, start_y, width, height));
    }

    void Button::centerText()
    {
        sf::FloatRect buttonBounds = _button.getGlobalBounds();
        sf::FloatRect textBounds = _text.getLocalBounds();
        _text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        _text.setPosition(buttonBounds.left + buttonBounds.width / 2.0f, buttonBounds.top + buttonBounds.height / 2.0f);
    }
}