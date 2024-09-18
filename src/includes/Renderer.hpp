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

namespace ware {
    class ARenderer : public IObject {
        public:
            ARenderer() = default;
            ~ARenderer() = default;
            void update(sf::RenderWindow& window, float deltaTime) = 0;
            virtual void disappear() = 0;
            virtual void setPosition(sf::Vector2f pos) = 0;
            virtual void setScale(sf::Vector2f scale) = 0;
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
            void update(sf::RenderWindow& window, float deltaTime) override;
            void loadImage(sf::Image image);
            void reloadSprite();
            void disappear() override;
            void setPosition(sf::Vector2f pos) override;
            void setScale(sf::Vector2f scale) override;
            void setRotation(float angle) override;
            void setTextureRect(sf::Vector2f start_pos, int width, int height);
            void setColor(sf::Color color);
            void setPlayerColor(sf::Color skinColor, sf::Color clothesColor);
        private:
            sf::Sprite _sprite;
            sf::Texture _texture;
    };

    class Text : public ARenderer {
        public:
            Text(const std::string text, const std::string fontPath);
            ~Text();
            void update(sf::RenderWindow& window, float deltaTime) override;
            void loadFile(const std::string filePath);
            void disappear() override;
            void setPosition(sf::Vector2f pos) override;
            void setScale(sf::Vector2f scale) override;
            void setRotation(float angle) override;
            void setColor(sf::Color color);
            void setBorderColor(sf::Color color);
            void setString(const std::string text);
            void setCharacterSize(int size);
        private:
            sf::Text _text;
            sf::Font _font;
    };
}