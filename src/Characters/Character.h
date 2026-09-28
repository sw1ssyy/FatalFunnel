//
// Created by sw1ssyy on 27/09/2026.
//

#ifndef TOPDOWNSHOOTER_ICHARACTER
#define TOPDOWNSHOOTER_ICHARACTER
#include "raylib.h"
#include "../Utils/Animation2D.h"

struct CharacterAnimations
{
    Animation2D idleAnimation;
    Animation2D aimAnimation;
    Animation2D shootAnimation;
    Animation2D runAnimation;
    Animation2D reloadAnimation;

    CharacterAnimations(Animation2D idleAnim, Animation2D aimAnim,Animation2D shootAnim, Animation2D runAnim, Animation2D reloadAnim);
};


class Character
{
public:
    Character(const CharacterAnimations &animations);
     Rectangle GetRect() const;
     void SetPosition(float x, float y);
    void Draw();
    void DrawIdle(int index) const;
    void DrawRun();
    void DrawAim(int index) const;

    void DrawShoot(int index) const;

    void DrawReload();
    void Update(Vector2 worldMousePos);

     CharacterAnimations GetCharacterAnimations() const;
protected:

private:

    CharacterAnimations animations;
    Rectangle characterRect = {};
    float rotation = {};
};


#endif //TOPDOWNSHOOTER_ICHARACTER
