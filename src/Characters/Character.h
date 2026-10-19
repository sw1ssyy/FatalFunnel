//
// Created by sw1ssyy on 27/09/2026.
//

#ifndef TOPDOWNSHOOTER_ICHARACTER
#define TOPDOWNSHOOTER_ICHARACTER

#include "raylib.h"
#include "../Constants/GameConstants.h"
#include "../Map/TileMap.h"
#include "../Utils/Animation2D.h"
#include "../Utils/InputManager.h"

struct CharacterAnimations
{
    Animation2D idleAnimation;

    Animation2D aimAnimation;

    Animation2D shootAnimation;

    Animation2D reloadAnimation;

    CharacterAnimations(Animation2D idleAnim, Animation2D aimAnim, Animation2D shootAnim, Animation2D reloadAnim);
};

enum class CharacterState
{
    Idle,
    Aim,
    Shoot,
    Reload
};

class Character
{
public:
    explicit Character(const CharacterAnimations &animations);

    Rectangle GetRect() const;

    Vector2 GetBodyCenter() const;

    void SetPosition(float x, float y);

    CharacterAnimations GetCharacterAnimations() const;

    CharacterState GetState() const;

    int GetCurrentAmmo() const;

    void Update(const PlayerInput &input, Vector2 worldMousePos, TileMap& map);

    void Draw();

    void DrawIdle(int index) const;

    void DrawAim(int index) const;

    void DrawShoot(int index) const;

    void DrawReload(int index) const;

    float GetRotation() const;

private:
    void UpdateState(const PlayerInput &input);

    void SetState(CharacterState newState);

    void UpdateAnimations();

    Animation2D &GetAnimation(CharacterState characterState);

    void HandleMovement(const PlayerInput &input, TileMap &map);

    void HandleShoot();

    CharacterAnimations _animations;

    CharacterState _state = CharacterState::Idle;

    Rectangle _characterRect = {};

    float _rotation = 0.0f;

    float _shootTimer = 0.0f;

    int _magazineSize = GameConstants::DEFAULT_MAGAZINE_SIZE;

    int _currentAmmo = GameConstants::DEFAULT_MAGAZINE_SIZE;
};

#endif //TOPDOWNSHOOTER_ICHARACTER
