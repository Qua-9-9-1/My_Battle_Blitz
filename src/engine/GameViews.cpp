#include "Game.hpp"

namespace ware {

    void Game::separateViews()
    {
        if (_separatedViews)
            return;
        _view1.setViewport(0, 0, 0.5f, 1);
        _view2.setViewport(0.5f, 0, 0.5f, 1);
        _view1.setSize(_window.getSize().x / 2.f, _window.getSize().y);
        _view2.setSize(_window.getSize().x / 2.f, _window.getSize().y);
        _separatedViews = true;
    }

    void Game::unifyViews()
    {
        if (!_separatedViews)
            return;
        _view1.setViewport(0, 0, 1, 1);
        _view1.setCenter(_window.getSize().x / 2.f, _window.getSize().y / 2.f);
        _view1.setSize(_window.getSize().x, _window.getSize().y);
        _separatedViews = false;
    }
}