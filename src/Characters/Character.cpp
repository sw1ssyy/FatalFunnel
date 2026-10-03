//
// Created by sw1ssyy on 27/09/2026.
//
#include "Character.h"

#include <cmath>

#include "../Utils/DrawUtils.h"

CharacterAnimations::CharacterAnimations(Animation2D idleAnim, Animation2D aimAnim, Animation2D shootAnim,
                                         Animation2D runAnim, Animation2D reloadAnim)
    : idleAnimation(idleAnim)
    , aimAnimation(aimAnim)
    , shootAnimation(shootAnim)
    , runAnimation(runAnim)
    , reloadAnimation(reloadAnim)
{}

Character::Character(const CharacterAnimations& animations)
    : animations(animations)
{}

Rectangle Character::GetRect() const
{
    return characterRect;
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

CharacterState Character::GetState() const
{
    return state;
}

int Character::GetCurrentAmmo() const
{
    return currentAmmo;
}

void Character::Update(const PlayerInput& input, const Vector2 worldMousePos)
{
    UpdateState(input);
    HandleMovement(input);
    UpdateAnimations();

    const Vector2 diff = {worldMousePos.x - characterRect.x, worldMousePos.y - characterRect.y};

    rotation = atan2f(diff.y, diff.x) * RAD2DEG;
}

void Character::UpdateState(const PlayerInput& input)
{
    if (state == CharacterState::Reload)
    {
        reloadTimer -= GetFrameTime();

        if (reloadTimer > 0.0f)
        {
            return;
        }

        currentAmmo = magazineSize;
        SetState(CharacterState::Idle);
    }

    const bool wantsReload = input.reload && currentAmmo < magazineSize;

    if (state == CharacterState::Shoot && !wantsReload)
    {
        shootTimer -= GetFrameTime();

        if (shootTimer > 0.0f)
        {
            return;
        }
    }

    if (wantsReload)
    {
        reloadTimer = GameConstants::RELOAD_TIME_SECONDS;
        SetState(CharacterState::Reload);
    }
    else if (!input.aim)
    {
        SetState(CharacterState::Idle);
    }
    else if (input.fire && currentAmmo > 0)
    {
        // Each shot restarts the timer and the animation, even while already shooting.
        shootTimer = GameConstants::SHOOT_TIME_SECONDS;
        SetState(CharacterState::Shoot);
        animations.shootAnimation.Reset();
        HandleShoot();
    }
    else
    {
        SetState(CharacterState::Aim);
    }
}

void Character::SetState(const CharacterState newState)
{
    if (newState == state)
    {
        return;
    }

    state = newState;
    GetAnimation(state).Reset();
}

void Character::UpdateAnimations()
{
    animations.idleAnimation.Stop();
    animations.aimAnimation.Stop();
    animations.shootAnimation.Stop();
    animations.reloadAnimation.Stop();

    GetAnimation(state).Start();
}

Animation2D& Character::GetAnimation(const CharacterState characterState)
{
    switch (characterState)
    {
        case CharacterState::Aim:    return animations.aimAnimation;
        case CharacterState::Shoot:  return animations.shootAnimation;
        case CharacterState::Reload: return animations.reloadAnimation;
        case CharacterState::Idle:
        default:                     return animations.idleAnimation;
    }
}

void Character::HandleMovement(const PlayerInput& input)
{
    const float speed = input.sprint ? GameConstants::PLAYER_SPRINT_SPEED : GameConstants::PLAYER_WALK_SPEED;

    characterRect.x += input.move.x * speed;
    characterRect.y += input.move.y * speed;
}

void Character::HandleShoot()
{
    if (currentAmmo <= 0)
    {
        TraceLog(LOG_INFO, "Character: out of ammo");
        return;
    }

    currentAmmo--;
}

void Character::Draw()
{
    switch (state)
    {
        case CharacterState::Idle:   DrawIdle(GetAnimation(state).GetFrameIndex());   break;
        case CharacterState::Aim:    DrawAim(GetAnimation(state).GetFrameIndex());    break;
        case CharacterState::Shoot:  DrawShoot(GetAnimation(state).GetFrameIndex());  break;
        case CharacterState::Reload: DrawReload(GetAnimation(state).GetFrameIndex()); break;
    }
}

void Character::DrawIdle(const int index) const
{
    DrawUtils::DrawAnimation(animations.idleAnimation, index, {characterRect.x, characterRect.y}, rotation);
}

void Character::DrawAim(const int index) const
{
    DrawUtils::DrawAnimation(animations.aimAnimation, index, {characterRect.x, characterRect.y}, rotation);
}

void Character::DrawShoot(const int index) const
{
    DrawUtils::DrawAnimation(animations.shootAnimation, index, {characterRect.x, characterRect.y}, rotation);
}

void Character::DrawReload(const int index) const
{
    DrawUtils::DrawAnimation(animations.reloadAnimation, index, {characterRect.x, characterRect.y}, rotation);
}
