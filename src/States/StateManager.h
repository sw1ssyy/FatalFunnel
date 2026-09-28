//
// Created by johnc on 26/09/2026.
//

#ifndef TOPDOWNSHOOTER_STATEMANAGER
#define TOPDOWNSHOOTER_STATEMANAGER
#include <array>
#include <memory>

#include "IState.h"
#include "StateID.h"


class StateManager
{
public:

    StateManager();

    IState& GetCurrentState();

    void SetState(StateID state);

    void SetupStates();

    void RequestQuit();

    bool ShouldQuit() const;

private:
    std::array<std::unique_ptr<IState>, COUNT> states;

    int statePointer = 0;

    bool quitRequested = false;
};


#endif //TOPDOWNSHOOTER_STATEMANAGER
