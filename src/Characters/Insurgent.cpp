//
// Created by sw1ssyy on 31/10/2026.
//

#include "Insurgent.h"

Insurgent::Insurgent(const CharacterAnimations &animations) : Character(animations)
{
    SetRotation(0);
}

void Insurgent::Update()
{
    UpdateAnimations();
}

void Insurgent::UpdateAnimations()
{
    Character::UpdateAnimations();
}
