//
// Created by sw1ssyy on 26/09/2026.
//
#include "TextureManager.h"

#include "../Constants/AssetConstants.h"
#include "raylib.h"

#include <stdexcept>

Texture2D& TextureManager::Get(const std::string& assetId)
{
    const auto it = _cache.find(assetId);

    if (it == _cache.end())
    {
        TraceLog(LOG_ERROR, "Texture not loaded: %s", assetId.c_str());
        throw std::out_of_range("Texture not loaded: " + assetId);
    }

    return it->second;
}


void TextureManager::Load(const std::string& assetId)
{
    if (_cache.find(assetId) == _cache.end())
    {
        TraceLog(LOG_INFO, "Texture Loaded: %s", assetId.c_str());
        _cache[assetId] = LoadTexture(assetId.c_str());
        SetTextureFilter(_cache[assetId], TEXTURE_FILTER_BILINEAR);
    }
}

void TextureManager::LoadAll()
{
    Load(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_WALK_AIM);
    Load(AssetConstants::ANIM_OPERATOR_NVG_STOWED_WALK_AIM);
    Load(AssetConstants::ANIM_OPERATOR_NVG_STOWED_WALK_LOW);
    Load(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_IDLE);
    Load(AssetConstants::ANIM_OPERATOR_NVG_STOWED_IDLE);
    Load(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_IDLE_LOW);
    Load(AssetConstants::ANIM_OPERATOR_NVG_STOWED_IDLE_LOW);
    Load(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_FIRE_WITH_FLASH);
    Load(AssetConstants::ANIM_OPERATOR_NVG_STOWED_FIRE_WITH_FLASH);
    Load(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_RELOAD);
    Load(AssetConstants::ANIM_OPERATOR_NVG_STOWED_RELOAD);
    Load(AssetConstants::MAP_TILESET);
}

void TextureManager::UnloadAll()
{
    for (auto& pair : _cache)
    {
        UnloadTexture(pair.second);
    }
    _cache.clear();
}
