//
// Created by sw1ssyy on 18/10/2026.
//

#include "VisionCone.h"

#include "../Utils/InputManager.h"

VisionCone::VisionCone(): _centrePosition({}), _fov(50), _rotation(0), _sizeOffset(10)
{
}

void VisionCone::Update(Vector2 position, float rotation)
{
    _centrePosition = position;

    _rotation = rotation;

    if (InputManager::GetInstance().Get().aim)
    {
        _sizeOffset = 25;
    }
    else
    {
        _sizeOffset = 60;
    }
}

bool VisionCone::IsObjectVisible(Vector2 target)
{
    return false;
}

void VisionCone::Draw()
{
    DrawCircleSectorLines(_centrePosition, 1000,_rotation - _sizeOffset,_rotation + _sizeOffset, 6 ,RED);
}
