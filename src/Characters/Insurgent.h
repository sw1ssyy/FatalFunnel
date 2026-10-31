//
// Created by sw1ssyy on 31/10/2026.
//

#ifndef TOPDOWNSHOOTER_INSURGENT
#define TOPDOWNSHOOTER_INSURGENT
#include "Character.h"


class Insurgent : public Character
{
public:
    explicit Insurgent(const CharacterAnimations &animations);

    void SetRotation(float rotation);

    void Update();
};


#endif //TOPDOWNSHOOTER_INSURGENT
