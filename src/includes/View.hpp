#include <SFML/Graphics.hpp>
#include "IObject.hpp"

namespace ware {
    class View : public IObject {
        public:
            View();
            ~View();
            void update(sf::RenderWindow& window);
            void setPosition(sf::Vector2f pos);
            void setScale(sf::Vector2f scale);
            void setRotation(float angle);
            void setViewport(sf::FloatRect viewport);
            void setSize(sf::Vector2f size);
            void setCenter(sf::Vector2f center);
        private:
            sf::View _view;
    };
}