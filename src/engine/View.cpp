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

    void View::setPosition(sf::Vector2f pos)
    {
        _view.setCenter(pos);
    }

    void View::setScale(sf::Vector2f scale)
    {
        _view.setSize(scale);
    }

    void View::setRotation(float angle)
    {
        _view.setRotation(angle);
    }

    void View::setViewport(sf::FloatRect viewport)
    {
        _view.setViewport(viewport);
    }

    void View::setSize(sf::Vector2f size)
    {
        _view.setSize(size);
    }

    void View::setCenter(sf::Vector2f center)
    {
        _view.setCenter(center);
    }
}