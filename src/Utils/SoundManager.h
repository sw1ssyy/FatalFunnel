#ifndef INC_TOPDOWNSHOOTER_SOUNDMANAGER_H
#define INC_TOPDOWNSHOOTER_SOUNDMANAGER_H

#include "raylib.h"
#include <unordered_map>
#include <string>

class SoundManager {
public:
    static SoundManager& GetInstance() {
        static SoundManager instance;
        return instance;
    }

    Sound& Get(const std::string& assetId);

    void LoadAll();

    void UnloadAll();

private:
    SoundManager() = default;

    ~SoundManager() = default;

    void Load(const std::string& assetId);

    // Delete copy/move semantics
    SoundManager(const SoundManager&) = delete;

    SoundManager(SoundManager&&) = delete;

    SoundManager& operator=(const SoundManager&) = delete;

    SoundManager& operator=(SoundManager&&) = delete;

    std::unordered_map<std::string, Sound> _cache;
};

#endif //INC_TOPDOWNSHOOTER_SOUNDMANAGER_H
