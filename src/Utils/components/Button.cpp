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

Button::Button(const float x, const float y, const float width, const float height, std::string label): buttonRect(x,y,width,height), label(std::move(label))
{}

Rectangle Button::GetButtonRect() const
{
    return buttonRect;
}

bool Button::IsClicked() const
{
    return clicked;
}

void Button::Draw()
{
    clicked = false;

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
        DrawRectangleRounded(buttonRect,15,20 ,defaultColour);
    }

    Font& font = FontManager::GetInstance().Get(AssetConstants::FONT_MAIN);
    Vector2 textSize = MeasureTextEx(font, label.c_str(), FONT_SIZE, FONT_SPACING);
    Vector2 textPos = {
        buttonRect.x + (buttonRect.width - textSize.x) / 2.0f,
        buttonRect.y + (buttonRect.height - textSize.y) / 2.0f
    };

    DrawTextEx(font, label.c_str(), textPos, FONT_SIZE, FONT_SPACING, WHITE);
}

void Button::OnHover()
{
    DrawRectangleRounded(buttonRect,15,20 ,hoveredColour);
}

void Button::OnClick()
{
    TraceLog(LOG_INFO,  (label + " Button Clicked").c_str());

    clicked = true;

    DrawRectangleRounded(buttonRect,15,20 ,clickedColour);
}

bool Button::ButtonCollision()
{
    return CheckCollisionPointRec(GetMousePosition(), buttonRect);
}
