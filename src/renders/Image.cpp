#include "Renderer.hpp"

namespace ware {

Image::Image(const std::string filePath) { loadFile(filePath); }

Image::~Image() {}

void Image::loadFile(const std::string filePath) { _image.loadFromFile(filePath); }

void Image::colorize(sf::Color colorToReplace, sf::Color playerColor) {
    sf::Vector2u size = _image.getSize();

    for (unsigned int x = 0; x < size.x; ++x) {
        for (unsigned int y = 0; y < size.y; ++y) {
            if (_image.getPixel(x, y) == colorToReplace) {
                _image.setPixel(x, y, playerColor);
            }
        }
    }
}

void Image::setPlayerColor(sf::Color skinColor, sf::Color clothesColor) {
    colorize(sf::Color(234, 72, 234), skinColor);
    colorize(sf::Color(181, 56, 181), darkenColor(skinColor, 150));
    colorize(sf::Color(167, 255, 58), clothesColor);
    colorize(sf::Color(132, 198, 45), darkenColor(clothesColor, 150));
    colorize(sf::Color(208, 255, 147), lightenColor(clothesColor, 200));
}

void Image::setPlayer2Color(sf::Color skinColor, sf::Color clothesColor) {
    colorize(sf::Color(234, 72, 234), skinColor);
    colorize(sf::Color(181, 56, 181), darkenColor(skinColor, 150));
    colorize(sf::Color(167, 255, 58), clothesColor);
    colorize(sf::Color(132, 198, 45), darkenColor(clothesColor, 150));
    colorize(sf::Color(208, 255, 147), lightenColor(clothesColor, 200));
}

void Image::flipImage(bool horizontal, bool vertical) {
    if (horizontal)
        _image.flipHorizontally();
    if (vertical)
        _image.flipVertically();
}
} // namespace ware