/*
** EPITECH PROJECT, 2024
** arcade-microGames
** File description:
** View
*/

#include "View.hpp"

namespace ware {
    View::View()
    {
        _separatedViews = false;
    }

    View::~View()
    {
    }

    void View::update(sf::RenderWindow& window, float deltaTime)
    {
        if (_separatedViews) {
            window.setView(_view1);
        } else {
            window.setView(window.getDefaultView());
        }
    }

    void View::separateViews()
    {
        if (!_separatedViews) {
            _separatedViews = true;
        }
    }

    void View::unifyViews()
    {
        if (_separatedViews) {
            _separatedViews = false;
        }
    }

    void View::setViewCenter(float x, float y, bool view1)
    {
        if (view1 || !_separatedViews) {
            _view1.setCenter(x, y);
        } else {
            _view2.setCenter(x, y);
        }
    }

    void View::setViewSize(float x, float y, bool view1)
    {
        if (view1 || !_separatedViews) {
            _view1.setSize(x, y);
        } else {
            _view2.setSize(x, y);
        }
    }

    void View::setViewRotation(float angle, bool view1)
    {
        if (view1 || !_separatedViews) {
            _view1.setRotation(angle);
        } else {
            _view2.setRotation(angle);
        }
    }

    void View::setViewViewport(float x, float y, float width, float height, bool view1)
    {
        if (view1 || !_separatedViews) {
            _view1.setViewport(sf::FloatRect(x, y, width, height));
        } else {
            _view2.setViewport(sf::FloatRect(x, y, width, height));
        }
    }
}
