//
// Created by sw1ssyy on 27/09/2026.
//

#ifndef TOPDOWNSHOOTER_GAMECONSTANTS
#define TOPDOWNSHOOTER_GAMECONSTANTS

struct GameConstants
{
    static constexpr int SCREEN_WIDTH = 800;
    static constexpr int SCREEN_HEIGHT = 800;

    static constexpr const char* GAME_NAME = "Fatal Funnel";

    static constexpr int CHARACTER_WIDTH = 160;
    static constexpr int CHARACTER_HEIGHT = 160;

    static constexpr float FRAME_TIME_60 = 0.0167;
    static constexpr float FRAME_TIME_120 = 0.00835;
    static constexpr float FRAME_TIME_240 = 0.004175;

    static constexpr int DEFAULT_MAGAZINE_SIZE = 20;

    static constexpr float PLAYER_WALK_SPEED = 4.0f;
    static constexpr float PLAYER_SPRINT_SPEED = 6.5f;

    static constexpr float SHOOT_TIME_SECONDS = FRAME_TIME_240 * 30;

    static constexpr float CAMERA_ZOOM_DEFAULT = 0.7f;
    static constexpr float CAMERA_ZOOM_AIM = 0.5f;
};

#endif //TOPDOWNSHOOTER_GAMECONSTANTS
