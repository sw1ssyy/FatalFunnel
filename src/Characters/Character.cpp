//
// Created by sw1ssyy on 27/09/2026.
//
#include "Character.h"

#include <cmath>

#include "../Utils/DrawUtils.h"
#include "../Utils/InputManager.h"

CharacterAnimations::CharacterAnimations(Animation2D idleAnim, Animation2D aimAnim,Animation2D shootAnim, Animation2D runAnim, Animation2D reloadAnim)
    : idleAnimation(idleAnim), aimAnimation(aimAnim),shootAnimation(shootAnim),runAnimation(runAnim), reloadAnimation(reloadAnim)
{}

Character::Character(const CharacterAnimations& animations): animations(animations), characterRect({}), movementSpeed(0)
{
}

Rectangle Character::GetRect() const
{
    return this->characterRect;
}

void Character::SetPosition(const float x, const float y)
{
    characterRect.x = x;
    characterRect.y = y;
}

CharacterAnimations Character::GetCharacterAnimations() const
{
    return animations;
}


void Character::Draw()
{
    if (InputManager::GetInstance().IsAimHeld())
    {
        if (InputManager::GetInstance().IsShooting())
        {
            DrawShoot(animations.shootAnimation.GetFrameIndex());
        }
        else
        {
            DrawAim(animations.aimAnimation.GetFrameIndex());
        }
    }
    else
    {
        DrawIdle(animations.idleAnimation.GetFrameIndex());
    }

}

void Character::Update(Vector2 worldMousePos)
{
    if (InputManager::GetInstance().IsAimHeld())
    {
        animations.idleAnimation.Stop();

        if (InputManager::GetInstance().IsShooting())
        {
            animations.shootAnimation.Start();
        }
        else
        {
            animations.aimAnimation.Start();
        }
    }
    if (InputManager::GetInstance().IsPlayerMoving())
    {
        HandleMovement();
    }
    else
    {
        animations.idleAnimation.Start();
    }

    Vector2 diff = {worldMousePos.x - characterRect.x, worldMousePos.y - characterRect.y};

    rotation = atan2f(diff.y, diff.x) * RAD2DEG;
}

void Character::HandleMovement()
{
    Vector2 direction = InputManager::GetInstance().GetPlayerMovementDirection();

    bool isSprinting = InputManager::GetInstance().IsPlayerSprinting();

    movementSpeed = isSprinting? 6.5f : 4.0f;

    characterRect.x += direction.x * movementSpeed;
    characterRect.y += direction.y * movementSpeed;
}

void Character::DrawIdle(int index) const
{
    DrawUtils::DrawAnimationFrame(animations.idleAnimation, index, { characterRect.x, characterRect.y }, rotation);
}

void Character::DrawAim(int index) const
{
    DrawUtils::DrawAnimationFrame(animations.aimAnimation, index, { characterRect.x, characterRect.y }, rotation);
}

void Character::DrawShoot(int index) const
{
    DrawUtils::DrawAnimationFrame(animations.shootAnimation, index, { characterRect.x, characterRect.y }, rotation);
}

