#include <SFML/Graphics.hpp>
#include "IObject.hpp"

namespace ware {
    class View : public IObject {
        public:
            View();
            ~View();
            void update();
            sf::View getView() { return _view; }
            void setPosition(float x, float y);
            void setScale(float x, float y);
            void setRotation(float angle);
            void setViewport(float x, float y, float width, float height);
            void setSize(float x, float y);
            void setCenter(float x, float y);
        private:
            sf::View _view;
    };
}