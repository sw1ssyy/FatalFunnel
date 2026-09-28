//
// Created by johnc on 26/09/2026.
//

#ifndef TOPDOWNSHOOTER_MENUSTATE
#define TOPDOWNSHOOTER_MENUSTATE

#include "IState.h"
#include "../Utils/components/Button.h"

class MenuState : public IState
{
public:
    explicit MenuState(StateManager *manager): IState(manager){}

    void Draw() override;
    void Update() override;
    void OnEnter() override;
    void OnExit() override;

private:

    Button startButton = {100,200, 600,100, "START"};
    Button helpButton = {100,400, 600,100, "HELP"};
    Button exitButton = {100,600, 600,100, "EXIT"};
};

#endif //TOPDOWNSHOOTER_MENUSTATE
