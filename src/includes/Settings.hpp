#pragma once

namespace ware {
enum Graphics {
    LOW,
    MEDIUM,
    HIGH,
};

enum Language {
    ENGLISH,
    FRENCH,
    SPANISH,
    GERMAN,
    ITALIAN,
    DUTCH,
    PORTUGUESE,
};

class Settings {
  public:
    bool isFullScreen;
    bool fullScreen;
    int  musicVolume;
    int  soundVolume;
    int  graphics;
    int  language;
    bool beginnerMode;
};
} // namespace ware
