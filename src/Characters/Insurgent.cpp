//
// Created by sw1ssyy on 31/10/2026.
//

#include "Insurgent.h"

Insurgent::Insurgent(const CharacterAnimations &animations) : Character(animations)
{
}

void Insurgent::SetRotation(float rotation)
{
    _rotation = rotation;
}

void Insurgent::Update()
{
    SetRotation(90);
    GetAnimation(_state).Start();
}
