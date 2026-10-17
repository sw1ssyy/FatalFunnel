//
// Created by sw1ssyy on 26/09/2026.
//
#include "FontManager.h"

#include "../Constants/AssetConstants.h"
#include "raylib.h"

Font& FontManager::Get(const std::string& assetId)
{
    return _cache[assetId];
}

void FontManager::Load(const std::string& assetId, int fontSize)
{
    if (_cache.find(assetId) == _cache.end())
    {
        TraceLog(LOG_INFO, "Font Loaded: %s", assetId.c_str());
        Font font = LoadFontEx(assetId.c_str(), fontSize, nullptr, 0);
        SetTextureFilter(font.texture, TEXTURE_FILTER_ANISOTROPIC_8X);
        _cache[assetId] = font;
    }
}

void FontManager::LoadAll()
{
    // Bake at the largest size any UI text will be drawn at; DrawTextEx
    // downscales cleanly but upscaling a small atlas looks blurry/pixelated.
    Load(AssetConstants::FONT_MAIN, 96);
}

void FontManager::UnloadAll()
{
    for (auto& pair : _cache)
    {
        UnloadFont(pair.second);
    }
    _cache.clear();
}
