//
// Created by sw1ssyy on 28/09/2026.
//
#include "Animation2D.h"

#include "TextureManager.h"
#include "../Constants/GameConstants.h"


Animation2D::Animation2D(const char* texture, int maxFrames, float tickRate, int columns, int rows)
    : _texture(&TextureManager::GetInstance().Get(texture)), _maxFrames(maxFrames), _frameIndex(0), _deltaTime(0), _isStarted(false), _isFinished(false), _tickRate(tickRate), _sheetColumns(columns), _sheetRows(rows)
{}

Rectangle Animation2D::GetSourceRect(int frameIndex) const
{
    const int column = frameIndex % _sheetColumns;
    const int row = frameIndex / _sheetColumns;
    const float frameWidth = static_cast<float>(_texture->width) / _sheetColumns;
    const float frameHeight = static_cast<float>(_texture->height) / _sheetRows;

    return Rectangle{ column * frameWidth, row * frameHeight, frameWidth, frameHeight };
}

Texture2D* Animation2D::GetTexture() const
{
    return _texture;
}

int Animation2D::GetMaxFrames() const
{
    return _maxFrames;
}

int Animation2D::GetFrameIndex() const
{
    return _frameIndex;
}

bool Animation2D::IsFinished() const
{
    return _isFinished;
}

void Animation2D::Start()
{
    _isStarted = true;

    Interpolate();
}

void Animation2D::Stop()
{
    _isStarted = false;
}

void Animation2D::Reset()
{
    _frameIndex = 0;
    _deltaTime = 0;
    _isFinished = false;
}

void Animation2D::Interpolate()
{
    if (_isStarted)
    {
        _deltaTime += GetFrameTime();

        if (_deltaTime > _tickRate)
        {
            _deltaTime = 0;
            _frameIndex++;
        }
        if (_frameIndex >= _maxFrames)
        {
            _frameIndex = 0;
            _isFinished = true;
        }
    }
}
