//
// Created by sw1ssyy on 28/09/2026.
//
#include "Animation2D.h"

#include "../Constants/GameConstants.h"


Animation2D::Animation2D(Texture2D* texture, int maxFrames, float tickRate, int columns, int rows)
    : texture(texture), maxFrames(maxFrames),frameIndex(0),deltaTime(0),isStarted(false), tickRate(tickRate),sheetColumns(columns), sheetRows(rows)
{}

Rectangle Animation2D::GetSourceRect(int frameIndex) const
{
    const int column = frameIndex % sheetColumns;
    const int row = frameIndex / sheetColumns;
    const float frameWidth = static_cast<float>(texture->width) / sheetColumns;
    const float frameHeight = static_cast<float>(texture->height) / sheetRows;

    return Rectangle{ column * frameWidth, row * frameHeight, frameWidth, frameHeight };
}

Texture2D* Animation2D::GetTexture() const
{
    return texture;
}

int Animation2D::GetMaxFrames() const
{
    return maxFrames;
}

int Animation2D::GetFrameIndex() const
{
    return frameIndex;
}

void Animation2D::Start()
{
    isStarted = true;

    Interpolate();
}

void Animation2D::Stop()
{
    isStarted = false;
}

void Animation2D::Reset()
{
    frameIndex = 0;
    deltaTime = 0;
}

void Animation2D::Interpolate()
{
    if (isStarted)
    {
        deltaTime += GetFrameTime();

        if (deltaTime > tickRate)
        {
            deltaTime = 0;
            frameIndex++;
        }
        if (frameIndex > maxFrames)
        {
            frameIndex = 0;
        }
    }
}
