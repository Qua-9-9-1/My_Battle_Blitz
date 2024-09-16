/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** Renderer
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "IObject.hpp"

namespace ware {
    class ARenderer : public IObject {
        public:
            ARenderer() = default;
            ~ARenderer() = default;
            void update(sf::RenderWindow& window, float deltaTime) = 0;
            virtual void loadFile(const std::string filePath) = 0;
            virtual void disappear() = 0;
            virtual void setPosition(sf::Vector2f pos) = 0;
            virtual void setScale(sf::Vector2f scale) = 0;
            virtual void setRotation(float angle) = 0;
    };

    class Sprite : public ARenderer {
        public:
            Sprite(const std::string filePath);
            ~Sprite();
            void update(sf::RenderWindow& window, float deltaTime) override;
            void loadFile(const std::string filePath) override;
            void reloadSprite();
            void disappear() override;
            void setPosition(sf::Vector2f pos) override;
            void setScale(sf::Vector2f scale) override;
            void setRotation(float angle) override;
            void setTextureRect(sf::Vector2f start_pos, int width, int height);
            void setColor(sf::Color color);
            void colorize(sf::Color colorToReplace, sf::Color playerColor);
            void setPlayerColor(sf::Color skinColor, sf::Color clothesColor);
        private:
            sf::Sprite _sprite;
            sf::Texture _texture;
            sf::Image _image;
    };

    class Text : public ARenderer {
        public:
            Text(const std::string text, const std::string fontPath);
            ~Text();
            void update(sf::RenderWindow& window, float deltaTime) override;
            void loadFile(const std::string filePath) override;
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