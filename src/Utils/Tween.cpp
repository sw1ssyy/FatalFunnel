//
// Created by sw1ssyy on 01/11/2026.
//

#include "Tween.h"

#include "raylib.h"
#include "raymath.h"

Tween::Tween(const float duration) : _duration(duration)
{
}

void Tween::Start(const float from, const float to, bool loop)
{
    _to = to;

    _from = from;

    _elapsed = 0.0f;

    _isRunning = true;

    _isFinished = false;

    _isLooping = loop;

    _value = _from;
}

void Tween::Update()
{
    if (!_isRunning)
    {
        return;
    }

    if (_duration <= 0.0f)
    {
        _value = _to;

        _isRunning = false;

        _isFinished = true;

        return;
    }

    _elapsed += GetFrameTime();

    const float amount = Clamp(_elapsed / _duration, 0.0f,1.0f);

    _value = Lerp(_from, _to, amount);

    if (amount >= 1)
    {
        if (_isLooping)
        {
            _elapsed -= _duration;
            return;
        }

        _isRunning = false;

        _isFinished = true;
    }
}

void Tween::Stop()
{
    _isRunning = false;
}

void Tween::Reset()
{
    _value = _from;

    _elapsed = 0.0f;

    _isFinished = false;
}

float Tween::GetValue() const
{
    return _value;
}

bool Tween::IsFinished() const
{
    return _isFinished;
}

bool Tween::IsRunning() const
{
    return _isRunning;
}
