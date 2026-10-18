//
// Created by sw1ssyy on 17/10/2026.
//
#include "SoundManager.h"

#include "../Constants/AssetConstants.h"
#include "raylib.h"

#include <stdexcept>

Sound& SoundManager::Get(const std::string& assetId)
{
    const auto it = _cache.find(assetId);

    if (it == _cache.end())
    {
        TraceLog(LOG_ERROR, "Sound not loaded: %s", assetId.c_str());
        throw std::out_of_range("Sound not loaded: " + assetId);
    }

    return it->second;
}

void SoundManager::Play(const std::string& assetId)
{
    PlaySound(Get(assetId));
}

void SoundManager::PlayIfIdle(const std::string& assetId)
{
    if (!IsPlaying(assetId))
    {
        Play(assetId);
    }
}

bool SoundManager::IsPlaying(const std::string& assetId)
{
    return IsSoundPlaying(Get(assetId));
}

void SoundManager::Load(const std::string& assetId)
{
    if (_cache.find(assetId) == _cache.end())
    {
        TraceLog(LOG_INFO, "Sound Loaded: %s", assetId.c_str());
        _cache[assetId] = LoadSound(assetId.c_str());
    }
}

void SoundManager::LoadAll()
{
    Load(AssetConstants::SOUND_GRASS_STEP);
    Load(AssetConstants::SOUND_PAVEMENT_STEP);
    Load(AssetConstants::SOUND_GUNSHOT_SOUND);
    Load(AssetConstants::SOUND_EMPTY_GUN);
}

void SoundManager::UnloadAll()
{
    for (auto& pair : _cache)
    {
        UnloadSound(pair.second);
    }
    _cache.clear();
}
