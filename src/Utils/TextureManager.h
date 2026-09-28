#ifndef INC_TOPDOWNSHOOTER_TEXTUREMANAGER_H
#define INC_TOPDOWNSHOOTER_TEXTUREMANAGER_H

#include "raylib.h"
#include <unordered_map>
#include <string>

class TextureManager {
public:
    static TextureManager& GetInstance() {
        static TextureManager instance;
        return instance;
    }

    Texture2D& Get(const std::string& assetId);

    void LoadAll();
    void UnloadAll();

private:
    TextureManager() = default;
    ~TextureManager() = default;
    void Load(const std::string& assetId);

    // Delete copy/move semantics
    TextureManager(const TextureManager&) = delete;
    TextureManager(TextureManager&&) = delete;
    TextureManager& operator=(const TextureManager&) = delete;
    TextureManager& operator=(TextureManager&&) = delete;

    std::unordered_map<std::string, Texture2D> cache;
};

#endif //INC_TOPDOWNSHOOTER_TEXTUREMANAGER_H
