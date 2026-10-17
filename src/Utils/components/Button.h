//
// Created by sw1ssyy on 27/09/2026.
//

#ifndef TOPDOWNSHOOTER_BUTTON_H
#define TOPDOWNSHOOTER_BUTTON_H
#include "raylib.h"
#include <string>


class Button
{
public:
    Button(float x, float y, float width, float height, std::string label = "");

    Rectangle GetButtonRect() const;

    bool IsClicked() const;

    void ResetClicked();

    void Draw();

    void OnHover();

    void OnClick();

protected:

    Rectangle _buttonRect = {};

    std::string _label = {};

    bool _clicked = false;

    Color _hoveredColour = BLUE;

    Color _clickedColour = SKYBLUE;

    Color _defaultColour = DARKBLUE;

private:

    bool ButtonCollision();
};


#endif //TOPDOWNSHOOTER_BUTTON_H
