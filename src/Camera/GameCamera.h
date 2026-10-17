//
// Created by sw1ssyy on 17/10/2026.
//

#ifndef TOPDOWNSHOOTER_GAMECAMERA
#define TOPDOWNSHOOTER_GAMECAMERA

#include "raylib.h"

class GameCamera
{
public:
    void Init(Vector2 target);
    void Update(Vector2 target, bool aiming);

    void Begin() const;
    void End() const;

    void Shake() const;

    Vector2 ScreenToWorld(Vector2 screenPos) const;
    Camera2D& Get();

private:
    Camera2D camera = {};
};

#endif //TOPDOWNSHOOTER_GAMECAMERA
