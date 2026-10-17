//
// Created by sw1ssyy on 27/09/2026.
//
#include "Character.h"

#include <cmath>
#include <string>

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
    : _animations(animations)
{
    _characterRect.width = GameConstants::CHARACTER_WIDTH;
    _characterRect.height = GameConstants::CHARACTER_HEIGHT;
}

Rectangle Character::GetRect() const
{
    return _characterRect;
}

void Character::SetPosition(const float x, const float y)
{
    _characterRect.x = x - _characterRect.width / 2;
    _characterRect.y = y - _characterRect.height / 2;
}

CharacterAnimations Character::GetCharacterAnimations() const
{
    return _animations;
}

CharacterState Character::GetState() const
{
    return _state;
}

int Character::GetCurrentAmmo() const
{
    return _currentAmmo;
}

void Character::Update(const PlayerInput& input, const Vector2 worldMousePos)
{
    UpdateState(input);
    HandleMovement(input);
    UpdateAnimations();

    const Vector2 diff = {worldMousePos.x - _characterRect.x, worldMousePos.y - _characterRect.y};

    _rotation = atan2f(diff.y, diff.x) * RAD2DEG;
}

void Character::UpdateState(const PlayerInput& input)
{
    if (_state == CharacterState::Reload)
    {
        return;
    }

    const bool wantsReload = input.reload && _currentAmmo < _magazineSize;

    if (_state == CharacterState::Shoot && !wantsReload)
    {
        _shootTimer -= GetFrameTime();

        if (_shootTimer > 0.0f)
        {
            return;
        }
    }

    if (wantsReload)
    {
        SetState(CharacterState::Reload);
    }
    else if (!input.aim)
    {
        SetState(CharacterState::Idle);
    }
    else if (input.fire && _currentAmmo > 0)
    {
        // Each shot restarts the timer and the animation, even while already shooting.
        _shootTimer = GameConstants::SHOOT_TIME_SECONDS;
        SetState(CharacterState::Shoot);
        _animations.shootAnimation.Reset();
        HandleShoot();
    }
    else
    {
        SetState(CharacterState::Aim);
    }
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

void Character::UpdateAnimations()
{
    _animations.idleAnimation.Stop();
    _animations.aimAnimation.Stop();
    _animations.shootAnimation.Stop();
    _animations.reloadAnimation.Stop();

    GetAnimation(_state).Start();

    if (_state == CharacterState::Reload && _animations.reloadAnimation.IsFinished())
    {
        _currentAmmo = _magazineSize;
        SetState(CharacterState::Idle);
    }
}

Animation2D& Character::GetAnimation(const CharacterState characterState)
{
    switch (characterState)
    {
        case CharacterState::Aim:    return _animations.aimAnimation;
        case CharacterState::Shoot:  return _animations.shootAnimation;
        case CharacterState::Reload: return _animations.reloadAnimation;
        case CharacterState::Idle:
        default:                     return _animations.idleAnimation;
    }
}

void Character::HandleMovement(const PlayerInput& input)
{
    const float speed = input.sprint ? GameConstants::PLAYER_SPRINT_SPEED : GameConstants::PLAYER_WALK_SPEED;

    _characterRect.x += input.move.x * speed;
    _characterRect.y += input.move.y * speed;
}

void Character::HandleShoot()
{
    if (_currentAmmo <= 0)
    {
        TraceLog(LOG_INFO, "Character: out of ammo");
        return;
    }

    _currentAmmo--;
}

void Character::Draw()
{
    switch (_state)
    {
        case CharacterState::Idle:   DrawIdle(GetAnimation(_state).GetFrameIndex());   break;
        case CharacterState::Aim:    DrawAim(GetAnimation(_state).GetFrameIndex());    break;
        case CharacterState::Shoot:  DrawShoot(GetAnimation(_state).GetFrameIndex());  break;
        case CharacterState::Reload: DrawReload(GetAnimation(_state).GetFrameIndex()); break;
    }

    DrawRectangleLinesEx(GetRect(),3,YELLOW);
}

void Character::DrawIdle(const int index) const
{
    DrawUtils::DrawAnimation(_animations.idleAnimation, index, {_characterRect.x + GameConstants::CHARACTER_WIDTH / 2, _characterRect.y + GameConstants::CHARACTER_HEIGHT / 2}, _rotation);
}

void Character::DrawAim(const int index) const
{
    DrawUtils::DrawAnimation(_animations.aimAnimation, index, {_characterRect.x + GameConstants::CHARACTER_WIDTH / 2, _characterRect.y + GameConstants::CHARACTER_HEIGHT / 2}, _rotation);
}

void Character::DrawShoot(const int index) const
{
    DrawUtils::DrawAnimation(_animations.shootAnimation, index, {_characterRect.x + GameConstants::CHARACTER_WIDTH / 2, _characterRect.y + GameConstants::CHARACTER_HEIGHT / 2}, _rotation);
}

void Character::DrawReload(const int index) const
{
    DrawUtils::DrawAnimation(_animations.reloadAnimation, index, {_characterRect.x + GameConstants::CHARACTER_WIDTH / 2, _characterRect.y + GameConstants::CHARACTER_HEIGHT / 2}, _rotation);
}
