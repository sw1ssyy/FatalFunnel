//
// Created by sw1ssyy on 18/10/2026.
//

#ifndef TOPDOWNSHOOTER_VISION_CONE
#define TOPDOWNSHOOTER_VISION_CONE
#include "raylib.h"


class VisionCone
{
public:
    VisionCone();

    void Update(Vector2 position, float rotation);

    bool IsObjectVisible(Vector2 target);

    void Draw();

private:
    Vector2 _centrePosition;

    float _fov;

    float _rotation;

    float _sizeOffset;
};


#endif //TOPDOWNSHOOTER_VISION_CONE
