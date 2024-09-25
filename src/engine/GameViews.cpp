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
        resizeViews(_window.getSize().x, _window.getSize().y);
        _separatedViews = true;
    }

    void Game::unifyViews()
    {
        if (!_separatedViews)
            return;
        _view1.setViewport(0, 0, 1, 1);
        _view1.setCenter(_window.getSize().x / 2.f, _window.getSize().y / 2.f);
        _view1.setSize(_window.getSize().x, _window.getSize().y);
        resizeViews(_window.getSize().x, _window.getSize().y);
        _separatedViews = false;
    }

    void Game::resizeViews(int width, int height)
    {
        float windowAspectRatio = static_cast<float>(width) / static_cast<float>(height);
        float viewAspectRatio = static_cast<float>(WINDOW_WIDTH) / static_cast<float>(WINDOW_HEIGHT);

        if (_separatedViews) {
            float newWidth = WINDOW_HEIGHT * windowAspectRatio / 2.0f;
            float newHeight = (WINDOW_WIDTH / 2.0f) / windowAspectRatio;
            float viewportX = (1.0f - (WINDOW_WIDTH / newWidth)) / 2.0f;
            float viewportY = (1.0f - (WINDOW_HEIGHT / newHeight)) / 2.0f;
            if (windowAspectRatio > viewAspectRatio) {
                _view1.setSize(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT);
                _view1.setViewport(viewportX / 2.0f, 0.0f, WINDOW_WIDTH / newWidth / 2.0f, 1.0f);
            } else {
                _view1.setSize(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT);
                _view1.setViewport(0.0f, viewportY, 0.5f, WINDOW_HEIGHT / newHeight);
            }
            _view1.setCenter(WINDOW_WIDTH / 4.0f, WINDOW_HEIGHT / 2.0f);
            if (windowAspectRatio > viewAspectRatio) {
                _view2.setSize(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT);
                _view2.setViewport(0.5f + viewportX / 2.0f, 0.0f, WINDOW_WIDTH / newWidth / 2.0f, 1.0f);
            } else {
                _view2.setSize(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT);
                _view2.setViewport(0.5f, viewportY, 0.5f, WINDOW_HEIGHT / newHeight);
            }
            _view2.setCenter(3 * WINDOW_WIDTH / 4.0f, WINDOW_HEIGHT / 2.0f);
        } else {
            float newWidth = WINDOW_HEIGHT * windowAspectRatio;
            float viewportX = (1.0f - (WINDOW_WIDTH / newWidth)) / 2.0f;
            float newHeight = WINDOW_WIDTH / windowAspectRatio;
            float viewportY = (1.0f - (WINDOW_HEIGHT / newHeight)) / 2.0f;

            if (windowAspectRatio > viewAspectRatio) {
                _view1.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
                _view1.setViewport(viewportX, 0.0f, WINDOW_WIDTH / newWidth, 1.0f);
            } else {
                _view1.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
                _view1.setViewport(0.0f, viewportY, 1.0f, WINDOW_HEIGHT / newHeight);
            }
            _view1.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
        }
    }
}