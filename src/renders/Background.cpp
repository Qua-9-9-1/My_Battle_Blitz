#include "Renderer.hpp"

namespace ware {
    SolidColorBackground::SolidColorBackground(float r, float g, float b, float a)
    {
        setPosition(0, 0);
        setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
        _shape.setFillColor(sf::Color(r, g, b, a));
    }

    void SolidColorBackground::update(sf::RenderWindow& window)
    {
        window.draw(_shape);
    }

    void SolidColorBackground::setPosition(float x, float y)
    {
        _shape.setPosition(x, y);
    }

    void SolidColorBackground::setSize(float x, float y)
    {
        _shape.setSize(sf::Vector2f(x, y));
    }

    void SolidColorBackground::setScale(float x, float y)
    {
        _shape.setScale(x, y);
    }

    void SolidColorBackground::setRotation(float angle)
    {
        _shape.setRotation(angle);
    }

    void SolidColorBackground::setColor(const sf::Color& color)
    {
        _shape.setFillColor(color);
    }

    ScrollingBackground::ScrollingBackground(const std::string& filePath)
    {
        _texture.loadFromFile(filePath);
        _texture.setSmooth(true);
        _texture.setRepeated(true);
        _sprite.setTextureRect(sf::IntRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
        _sprite.setTexture(_texture);
        setPosition(0, 0);
        _rect = _sprite.getTextureRect();
        _speed = 1;
        _angle = 45;
    }

    void ScrollingBackground::update(sf::RenderWindow& window)
    {
        _sprite.move(_speed * cos(_angle), _speed * sin(_angle));
        if (_sprite.getPosition().x >= (_texture.getSize().x * cos(_angle))
        && _sprite.getPosition().y >= (_texture.getSize().y * sin(_angle))) {
            _sprite.setPosition(0, 0);
        }
        window.draw(_sprite);
    }

    void ScrollingBackground::setPosition(float x, float y)
    {
        _sprite.setPosition(x, y);
    }

    void ScrollingBackground::setSize(float x, float y)
    {
        _sprite.setScale(x, y);
        setPosition(0, 0);
    }

    void ScrollingBackground::setScale(float x, float y)
    {
        _sprite.setScale(x, y);
        setPosition(0, 0);
    }

    void ScrollingBackground::setRotation(float angle)
    {
        _sprite.setRotation(angle);
    }

    void ScrollingBackground::setSpriteRect(int posX, int posY, int sizeX, int sizeY)
    {
        _rect.left = posX;
        _rect.top = posY;
        _rect.width = sizeX;
        _rect.height = sizeY;
        _sprite.setTextureRect(_rect);
    }

    void ScrollingBackground::setSpeed(float speed)
    {
        _speed = speed;
        setPosition(0, 0);
    }

    void ScrollingBackground::setDirection(float angle)
    {
        _angle = angle;
        setPosition(0, 0);
    }

    ImageBackground::ImageBackground(const std::string& filePath)
    {
        _texture.loadFromFile(filePath);
        _sprite.setTexture(_texture);
        _rect = _sprite.getTextureRect();
    }

    void ImageBackground::update(sf::RenderWindow& window)
    {
        window.draw(_sprite);
    }

    void ImageBackground::setPosition(float x, float y)
    {
        _sprite.setPosition(x, y);
    }

    void ImageBackground::setSize(float x, float y)
    {
        _rect.width = x;
        _rect.height = y;
        _sprite.setTextureRect(_rect);
    }

    void ImageBackground::setScale(float x, float y)
    {
        _sprite.setScale(x, y);
    }

    void ImageBackground::setSpriteRect(int posX, int posY, int sizeX, int sizeY)
    {
        _rect.left = posX;
        _rect.top = posY;
        _rect.width = sizeX;
        _rect.height = sizeY;
        _sprite.setTextureRect(_rect);
    }


    void ImageBackground::setRotation(float angle)
    {
        _sprite.setRotation(angle);
    }

    ParallaxBackground::ParallaxBackground(const std::vector<std::string>& filePaths)
    {
        for (const auto& filePath : filePaths) {
            sf::Texture texture;
            texture.loadFromFile(filePath);
            _textures.push_back(texture);
        }
        _selected_sprite = 0;
    }

    void ParallaxBackground::update(sf::RenderWindow& window)
    {
        for (const auto& texture : _textures) {
            sf::Sprite sprite(texture);
            sprite.setPosition(_position);
            window.draw(sprite);
        }
    }

    void ParallaxBackground::setPosition(float x, float y)
    {
        _position = sf::Vector2f(x, y);
    }

    void ParallaxBackground::setSize(float x, float y)
    {
        for (auto& texture : _textures) {
            texture.setSmooth(true);
        }
    }

    void ParallaxBackground::setScale(float x, float y)
    {
        for (auto& texture : _textures) {
            texture.setSmooth(true);
        }
    }

    void ParallaxBackground::setRotation(float angle)
    {
        for (auto& texture : _textures) {
            texture.setSmooth(true);
        }
    }

    void ParallaxBackground::setSpeeds(float Xspeed, float Yspeed)
    {
        for (auto& texture : _textures) {
            texture.setSmooth(true);
        }
    }

    void ParallaxBackground::setDirection(float angle)
    {
        for (auto& texture : _textures) {
            texture.setSmooth(true);
        }
    }

}