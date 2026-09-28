//
// Created by sw1ssyy on 26/09/2026.
//
#include "TextureManager.h"

#include "../Constants/AssetConstants.h"
#include "raylib.h"

Texture2D& TextureManager::Get(const std::string& assetId)
{
    return cache[assetId];
}


void TextureManager::Load(const std::string& assetId)
{
    if (cache.find(assetId) == cache.end())
    {
        TraceLog(LOG_INFO, "Texture Loaded: %s", assetId.c_str());
        cache[assetId] = LoadTexture(assetId.c_str());
    }
}

void TextureManager::LoadAll()
{
    Load(AssetConstants::OPERATOR_NVG_EQUIPPED);
    Load(AssetConstants::OPERATOR_NVG_STOWED);
    Load(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_WALK_AIM);
    Load(AssetConstants::ANIM_OPERATOR_NVG_EQUIPPED_WALK_LOW);
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
}

void TextureManager::UnloadAll()
{
    for (auto& pair : cache)
    {
        UnloadTexture(pair.second);
    }
    cache.clear();
}
