//
// Created by sw1ssyy on 31/10/2026.
//

#ifndef TOPDOWNSHOOTER_CHARACTER
#define TOPDOWNSHOOTER_CHARACTER

#include "../Utils/Animation2D.h"

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

    Character(const CharacterAnimations &animations);

    void Draw();

    void DrawIdle(int index);

    void DrawAim(int index);

    void DrawShoot(int index);

    void DrawReload(int index);

    void SetPosition(float x, float y);

    Animation2D &GetAnimation(CharacterState characterState);

    float GetRotation() const;

    Rectangle GetRect() const;

    Vector2 GetBodyCenter() const;

    CharacterAnimations GetCharacterAnimations() const;

    CharacterState GetState() const;

protected:
    CharacterAnimations _animations;

    float _rotation = 0.0f;

    CharacterState _state = CharacterState::Idle;

    Rectangle _characterRect = {};
};


#endif //TOPDOWNSHOOTER_CHARACTER
