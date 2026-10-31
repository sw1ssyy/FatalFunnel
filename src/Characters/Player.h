//
// Created by sw1ssyy on 27/09/2026.
//

#ifndef TOPDOWNSHOOTER_PLAYER
#define TOPDOWNSHOOTER_PLAYER

#include "Character.h"
#include "raylib.h"
#include "../Constants/GameConstants.h"
#include "../Map/TileMap.h"
#include "../Utils/InputManager.h"

class Player : public Character
{
public:
    explicit Player(const CharacterAnimations &animations);

    int GetCurrentAmmo() const;

    void Update(const PlayerInput &input, Vector2 worldMousePos, TileMap& map);

private:
    void UpdateState(const PlayerInput &input);

    void SetState(CharacterState newState);

    void UpdateAnimations();

    void HandleMovement(const PlayerInput &input, TileMap &map);

    void HandleShoot();

    float _shootTimer = 0.0f;

    int _magazineSize = GameConstants::DEFAULT_MAGAZINE_SIZE;

    int _currentAmmo = GameConstants::DEFAULT_MAGAZINE_SIZE;
};

#endif //TOPDOWNSHOOTER_PLAYER
