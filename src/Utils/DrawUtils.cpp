//
// Created by sw1ssyy on 28/09/2026.
//
#include "DrawUtils.h"

void DrawUtils::DrawAnimationFrame(const Animation2D& animation, int frameIndex, Vector2 position, float rotation)
{
    const Texture2D* texture = animation.GetTexture();

    const Rectangle sourceRect = animation.GetSourceRect(frameIndex);

    const Rectangle destRect = { position.x, position.y, sourceRect.width, sourceRect.height };

    const Vector2 origin = { sourceRect.width / 2, sourceRect.height / 2 };

    DrawTexturePro(*texture, sourceRect, destRect, origin, rotation, WHITE);
}
