//
// Created by sw1ssyy on 27/09/2026.
//

#ifndef TOPDOWNSHOOTER_ICHARACTER
#define TOPDOWNSHOOTER_ICHARACTER

#include "raylib.h"
#include "../Constants/GameConstants.h"
#include "../Utils/Animation2D.h"
#include "../Utils/InputManager.h"

struct CharacterAnimations
{
    Animation2D idleAnimation;
    Animation2D aimAnimation;
    Animation2D shootAnimation;
    Animation2D runAnimation;
    Animation2D reloadAnimation;

    CharacterAnimations(Animation2D idleAnim, Animation2D aimAnim, Animation2D shootAnim, Animation2D runAnim,
                        Animation2D reloadAnim);
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

    void SetPosition(float x, float y);

    CharacterAnimations GetCharacterAnimations() const;
    CharacterState GetState() const;
    int GetCurrentAmmo() const;

    void Update(const PlayerInput &input, Vector2 worldMousePos);

    void Draw();
    void DrawIdle(int index) const;
    void DrawAim(int index) const;
    void DrawShoot(int index) const;
    void DrawReload(int index) const;

private:
    void UpdateState(const PlayerInput &input);
    void SetState(CharacterState newState);
    void UpdateAnimations();
    Animation2D &GetAnimation(CharacterState characterState);

    void HandleMovement(const PlayerInput &input);
    void HandleShoot();

    CharacterAnimations animations;
    CharacterState state = CharacterState::Idle;

    Rectangle characterRect = {};
    float rotation = 0.0f;

    float reloadTimer = 0.0f;
    float shootTimer = 0.0f;

    int magazineSize = GameConstants::DEFAULT_MAGAZINE_SIZE;
    int currentAmmo = GameConstants::DEFAULT_MAGAZINE_SIZE;
};

#endif //TOPDOWNSHOOTER_ICHARACTER
