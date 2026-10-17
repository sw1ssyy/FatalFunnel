//
// Created by sw1ssyy on 17/10/2026.
//

#ifndef TOPDOWNSHOOTER_TILES
#define TOPDOWNSHOOTER_TILES
#include "raylib.h"

enum TileTypes
{
    BRICK,
    GRASS,
    PAVEMENT,
};


class Tiles
{
public:

    Tiles(int type, int row, int column);

    void SetupTile();

    bool IsSolid() const;

    void Draw();

private:
    int _type;

    int _row;

    int _column;

    Rectangle _textureRect;

    Rectangle _positonRect;


};


#endif //TOPDOWNSHOOTER_TILES
