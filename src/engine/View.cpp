#include "View.hpp"

namespace ware {
    View::View()
    {
        _view = sf::View();
    }

    View::~View()
    {   
    }

    void View::update(sf::RenderWindow& window)
    {
        (void)window;
    }

    void View::setPosition(float x, float y)
    {
        _view.setCenter(x, y);
    }

    void View::setScale(float x, float y)
    {
        _view.setSize(x, y);
    }

    void View::setRotation(float angle)
    {
        _view.setRotation(angle);
    }

    void View::setViewport(float x, float y, float width, float height)
    {
        _view.setViewport(sf::FloatRect(x, y, width, height));
    }

    void View::setSize(float x, float y)
    {
        _view.setSize(x, y);
    }

    void View::setCenter(float x, float y)
    {
        _view.setCenter(x, y);
    }
}