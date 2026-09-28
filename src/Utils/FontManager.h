#ifndef INC_TOPDOWNSHOOTER_FONTMANAGER_H
#define INC_TOPDOWNSHOOTER_FONTMANAGER_H

#include "raylib.h"
#include <unordered_map>
#include <string>

class FontManager {
public:
    static FontManager& GetInstance() {
        static FontManager instance;
        return instance;
    }

    Font& Get(const std::string& assetId);

    void LoadAll();
    void UnloadAll();

private:
    FontManager() = default;
    ~FontManager() = default;
    void Load(const std::string& assetId, int fontSize = 32);

    // Delete copy/move semantics
    FontManager(const FontManager&) = delete;
    FontManager(FontManager&&) = delete;
    FontManager& operator=(const FontManager&) = delete;
    FontManager& operator=(FontManager&&) = delete;

    std::unordered_map<std::string, Font> cache;
};

#endif //INC_TOPDOWNSHOOTER_FONTMANAGER_H
