//
// Created by sw1ssyy on 27/09/2026.
//
#include "Player.h"

#include <cmath>

#include "../Constants/AssetConstants.h"
#include "../Map/TileMap.h"
#include "../Utils/SoundManager.h"

Player::Player(const CharacterAnimations &animations) : Character(animations)
{
}

int Player::GetCurrentAmmo() const
{
    return _currentAmmo;
}

void Player::Update(const PlayerInput &input, const Vector2 worldMousePos, TileMap &map)
{
    UpdateState(input);
    HandleMovement(input, map);
    UpdateAnimations();

    const Vector2 diff = {worldMousePos.x - _characterRect.x, worldMousePos.y - _characterRect.y};

    _rotation = atan2f(diff.y, diff.x) * RAD2DEG;
}

void Player::UpdateState(const PlayerInput &input)
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
    } else if (!input.aim)
    {
        SetState(CharacterState::Idle);
    } else if (input.fire && _currentAmmo > 0)
    {
        // Each shot restarts the timer and the animation, even while already shooting.
        _shootTimer = GameConstants::SHOOT_TIME_SECONDS;
        SetState(CharacterState::Shoot);
        _animations.shootAnimation.Reset();
        HandleShoot();
    } else if (input.fire && _currentAmmo == 0)
    {
        SoundManager::GetInstance().PlayIfIdle(AssetConstants::SOUND_EMPTY_GUN);
    } else
    {
        SetState(CharacterState::Aim);
    }
}

void Player::UpdateAnimations()
{
    Character::UpdateAnimations();

    if (_state == CharacterState::Reload && _animations.reloadAnimation.IsFinished())
    {
        _currentAmmo = _magazineSize;
        SetState(CharacterState::Idle);
    }
}

void Player::HandleMovement(const PlayerInput &input, TileMap &map)
{
    if (input.move.x == 0.0f && input.move.y == 0.0f)
    {
        return;
    }

    const float speed = input.sprint ? GameConstants::PLAYER_SPRINT_SPEED : GameConstants::PLAYER_WALK_SPEED;
    const Vector2 previousPosition = {_characterRect.x, _characterRect.y};

    const float nextX = _characterRect.x + input.move.x * speed;
    if (map.IsMoveAllowed(nextX + _characterRect.width / 2, _characterRect.y + _characterRect.height / 2))
    {
        _characterRect.x = nextX;
    }

    const float nextY = _characterRect.y + input.move.y * speed;
    if (map.IsMoveAllowed(_characterRect.x + _characterRect.width / 2, nextY + _characterRect.height / 2))
    {
        _characterRect.y = nextY;
    }

    const bool hasMoved = _characterRect.x != previousPosition.x || _characterRect.y != previousPosition.y;

    TileTypes type = map.GetTile((nextX + _characterRect.width / 2) / 128, (nextY + _characterRect.height / 2) / 128).
            GetTileType();

    if (hasMoved)
    {
        SoundManager::GetInstance().PlayIfIdle(type == PAVEMENT
                                                   ? AssetConstants::SOUND_PAVEMENT_STEP
                                                   : AssetConstants::SOUND_GRASS_STEP);
    }
}

void Player::HandleShoot()
{
    if (_currentAmmo <= 0)
    {
        TraceLog(LOG_INFO, "Character: out of ammo");
        return;
    }

    SoundManager::GetInstance().Play(AssetConstants::SOUND_GUNSHOT_SOUND);


    _currentAmmo--;
}
