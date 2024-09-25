/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "IObject.hpp"
#include "utils.hpp"

#include <iostream>

namespace ware {
    class ARenderer : public IObject {
        public:
            ARenderer() = default;
            ~ARenderer() = default;
            void update(sf::RenderWindow& window) = 0;
            virtual void disappear() = 0;
            virtual void setPosition(float x, float y) = 0;
            virtual void setScale(float x, float y) = 0;
            virtual void setRotation(float angle) = 0;
    };

    class Image {
        public:
            Image(const std::string filePath);
            ~Image();
            sf::Image getImage() { return _image; }
            void loadFile(const std::string filePath);
            void colorize(sf::Color colorToReplace, sf::Color playerColor);
            void setPlayerColor(sf::Color skinColor, sf::Color clothesColor);
            void setPlayer2Color(sf::Color skinColor, sf::Color clothesColor);
            void flipImage(bool horizontal, bool vertical);
        private:
            sf::Image _image;
    };

    class Sprite : public ARenderer {
        public:
            Sprite(sf::Image image);
            ~Sprite();
            void update(sf::RenderWindow& window) override;
            void loadImage(sf::Image image);
            void reloadSprite();
            void disappear() override;
            void setPosition(float x, float y) override;
            void move(float x, float y);
            void setScale(float x, float y) override;
            void setRotation(float angle) override;
            void rotate(float angle);
            void setTextureRect(int start_x, int start_y, int width, int height);
            void setColor(sf::Color color);
            void setPlayerColor(sf::Color skinColor, sf::Color clothesColor);
            void flip(bool invert);
        private:
            sf::Sprite  _sprite;
            sf::Texture _texture;
            bool        _flipped;
    };

    class Text : public ARenderer {
        public:
            Text(const std::string text, const std::string fontPath);
            ~Text();
            void update(sf::RenderWindow& window) override;
            void loadFile(const std::string filePath);
            void disappear() override;
            void setPosition(float x, float y) override;
            void move(float x, float y);
            void setScale(float x, float y) override;
            void setRotation(float angle) override;
            void rotate(float angle);
            void setColor(sf::Color color);
            void setBorderColor(sf::Color color);
            void setString(const std::string text);
            void setCharacterSize(int size);
        private:
            sf::Text _text;
            sf::Font _font;
    };

    class Button : public ARenderer {
        public:
            Button(const std::string text, const std::string fontPath, float x, float y);
            ~Button();
            void update(sf::RenderWindow& window) override;
            void disappear() override;
            void setCentered();
            void setPosition(float x, float y) override;
            void move(float x, float y);
            void setScale(float x, float y) override;
            void setRotation(float angle) override;
            void rotate(float angle);
            void setColor(float r, float g, float b, float a);
            void setBorderColor(float r, float g, float b, float a);
            void setTextColor(float r, float g, float b, float a);
            void setString(const std::string text);
            void setSize(int size);
            void setPadding(float x, float y);
            void setBorder(float thickness);            
            void setTexture(const std::string filePath);
            void setTextureRect(int start_x, int start_y, int width, int height);
            void centerText();
        private:
            sf::Text            _text;
            sf::Font            _font;
            sf::RectangleShape  _button;
            sf::Texture         _buttonTexture;
            sf::Color           _color;
            sf::Color           _borderColor;
            sf::Color           _textColor;
            int                 _size;
            sf::Vector2f        _padding;
    };
}