//
// Created by sw1ssyy on 17/10/2026.
//

#ifndef TOPDOWNSHOOTER_TILEMAP
#define TOPDOWNSHOOTER_TILEMAP

#include <string>
#include <vector>

#include "Tiles.h"

class TileMap
{
public:
    TileMap();

    bool IsMoveAllowed(float x, float y);

    void Draw();

    Tiles GetTile(int x, int y) const;

private:
    std::vector<Tiles> _tiles;

    void LoadFromCsv(const std::string& path);

    const int _tileMaxSize = 10;
};


#endif //TOPDOWNSHOOTER_TILEMAP
