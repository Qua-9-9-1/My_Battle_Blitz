/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** View
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "IObject.hpp"

namespace ware {
    class View : public IObject {
        public:
            View();
            ~View();
            void update(sf::RenderWindow& window, float deltaTime) override;
            void separateViews();
            void unifyViews();
            void setViewCenter(float x, float y, bool view1);
            void setViewSize(float x, float y, bool view1);
            void setViewRotation(float angle, bool view1);
            void setViewViewport(float x, float y, float width, float height, bool view1);            
        private:
            sf::View _view1;
            sf::View _view2;
            bool _separatedViews;
    };
}