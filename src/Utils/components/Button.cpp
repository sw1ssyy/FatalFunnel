//
// Created by sw1ssyy on 27/09/2026.
//

#include "Button.h"

#include "../FontManager.h"
#include "../../Constants/AssetConstants.h"

namespace
{
    constexpr float FONT_SIZE = 64.0f;
    constexpr float FONT_SPACING = 1.0f;
}

Button::Button(const float x, const float y, const float width, const float height, std::string label): _buttonRect(x,y,width,height), _label(std::move(label))
{}

Rectangle Button::GetButtonRect() const
{
    return _buttonRect;
}

bool Button::IsClicked() const
{
    return _clicked;
}

void Button::ResetClicked()
{
    _clicked = false;
}

void Button::Draw()
{
    _clicked = false;

    if (ButtonCollision())
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            OnClick();
        }
        else
        {
            OnHover();
        }
    }
    else
    {
        DrawRectangleRounded(_buttonRect,15,20 ,_defaultColour);
    }

    Font& font = FontManager::GetInstance().Get(AssetConstants::FONT_MAIN);
    Vector2 textSize = MeasureTextEx(font, _label.c_str(), FONT_SIZE, FONT_SPACING);
    Vector2 textPos = {
        _buttonRect.x + (_buttonRect.width - textSize.x) / 2.0f,
        _buttonRect.y + (_buttonRect.height - textSize.y) / 2.0f
    };

    DrawTextEx(font, _label.c_str(), textPos, FONT_SIZE, FONT_SPACING, WHITE);
}

void Button::OnHover()
{
    DrawRectangleRounded(_buttonRect,15,20 ,_hoveredColour);
}

void Button::OnClick()
{
    TraceLog(LOG_INFO,  (_label + " Button Clicked").c_str());

    _clicked = true;

    DrawRectangleRounded(_buttonRect,15,20 ,_clickedColour);
}

bool Button::ButtonCollision()
{
    return CheckCollisionPointRec(GetMousePosition(), _buttonRect);
}
