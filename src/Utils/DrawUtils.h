#ifndef TOPDOWNSHOOTER_DRAWUTILS
#define TOPDOWNSHOOTER_DRAWUTILS
#include "raylib.h"
#include "Animation2D.h"

class DrawUtils
{
public:
    static void DrawAnimationFrame(const Animation2D& animation, int frameIndex, Vector2 position, float rotation);
};

#endif //TOPDOWNSHOOTER_DRAWUTILS
