#ifndef INC_TOPDOWNSHOOTER_ANIMATION2D_H
#define INC_TOPDOWNSHOOTER_ANIMATION2D_H

#include "raylib.h"

class Animation2D
{
public:
    Animation2D(Texture2D* texture, int maxFrames, float tickRate, int columns, int rows);

    Rectangle GetSourceRect(int frameIndex) const;
    Texture2D* GetTexture() const;
    int GetMaxFrames() const;
    int GetFrameIndex()const;
    void Interpolate();
    void Start();
    void Stop();
    void Reset();

private:
    Texture2D* texture;
    int maxFrames;
    float deltaTime;
    int frameIndex;
    bool isStarted;
    float tickRate;
    int sheetColumns;
    int sheetRows;
};

#endif //INC_TOPDOWNSHOOTER_ANIMATION2D_H
