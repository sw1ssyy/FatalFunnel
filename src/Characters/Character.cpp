//
// Created by sw1ssyy on 31/10/2026.
//

#include "Character.h"

#include "../Constants/GameConstants.h"
#include "../Utils/DrawUtils.h"

CharacterAnimations::CharacterAnimations(Animation2D idleAnim, Animation2D aimAnim, Animation2D shootAnim,Animation2D reloadAnim)
    : idleAnimation(idleAnim)
    , aimAnimation(aimAnim)
    , shootAnimation(shootAnim)
    , reloadAnimation(reloadAnim)
{}

Character::Character(const CharacterAnimations& animations) :_animations(animations)
{
    _characterRect.width = GameConstants::CHARACTER_WIDTH;
    _characterRect.height = GameConstants::CHARACTER_HEIGHT;
}

void Character::Draw()
{
    switch (_state)
    {
        case CharacterState::Idle: DrawIdle(GetAnimation(_state).GetFrameIndex());
            break;
        case CharacterState::Aim: DrawAim(GetAnimation(_state).GetFrameIndex());
            break;
        case CharacterState::Shoot: DrawShoot(GetAnimation(_state).GetFrameIndex());
            break;
        case CharacterState::Reload: DrawReload(GetAnimation(_state).GetFrameIndex());
            break;
    }
}

Animation2D &Character::GetAnimation(const CharacterState characterState)
{
    switch (characterState)
    {
        case CharacterState::Aim: return _animations.aimAnimation;
        case CharacterState::Shoot: return _animations.shootAnimation;
        case CharacterState::Reload: return _animations.reloadAnimation;
        case CharacterState::Idle:
        default: return _animations.idleAnimation;
    }
}

void Character::DrawIdle(const int index)
{
    DrawUtils::DrawAnimation(_animations.idleAnimation, index, GetBodyCenter(), _rotation);
}

void Character::DrawAim(const int index)
{
    DrawUtils::DrawAnimation(_animations.aimAnimation, index, GetBodyCenter(), _rotation);
}

void Character::DrawShoot(const int index)
{
    DrawUtils::DrawAnimation(_animations.shootAnimation, index, GetBodyCenter(), _rotation);
}

void Character::DrawReload(const int index)
{
    DrawUtils::DrawAnimation(_animations.reloadAnimation, index, GetBodyCenter(), _rotation);
}

void Character::SetPosition(const float x, const float y)
{
    _characterRect.x = x - _characterRect.width / 2;
    _characterRect.y = y - _characterRect.height / 2;
}

Rectangle Character::GetRect() const
{
    return _characterRect;
}

Vector2 Character::GetBodyCenter() const
{
    return {_characterRect.x + _characterRect.width / 2, _characterRect.y + _characterRect.height / 2};
}

CharacterAnimations Character::GetCharacterAnimations() const
{
    return _animations;
}

CharacterState Character::GetState() const
{
    return _state;
}

void Character::SetState(const CharacterState newState)
{
    if (newState == _state)
    {
        return;
    }

    _state = newState;
    GetAnimation(_state).Reset();
}

float Character::GetRotation() const
{
    return _rotation;
}

void Character::SetRotation(float rotation)
{
    _rotation = rotation;
}
