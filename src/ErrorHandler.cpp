/*
** Quentin Duval 2024
** Free Projects
** GitHub: @Qua-9-9-1
** Email:  quentduva@gmail.com
*/

#include "ErrorHandler.hpp"

const std::string textures[TEXTURES_SIZE] = {
    "judge",
    "parking",
    "mario"
};

void errorHandler(void)
{
    std::ifstream file;
    bool error = false;
    std::string basePath = std::filesystem::current_path().string() + "/assets/sprites/";

    for (int i = 0; i < TEXTURES_SIZE; i++) {
        file.open(basePath + textures[i] + ".png");
        if (!file) {
            std::cerr << "Error: one or more textures are missing re-dowload it." << std::endl;
            error = true;
            break;
        }
        file.close();
    }
    if (error) exit(1);
}