/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
*/

#pragma once

#include <SFML/Graphics.hpp>

namespace ware {
    class IObject {
        public:
            virtual ~IObject() = default;
            virtual void update() = 0;
    };
}