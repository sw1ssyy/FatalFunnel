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
    StateManager() = default;

    IState& GetCurrentState();

    void Init();

    void SetState(StateID state);

    void RequestQuit();

    bool ShouldQuit() const;

private:
    void SetupStates();

    std::array<std::unique_ptr<IState>, COUNT> _states;

    int _statePointer = 0;

    bool _quitRequested = false;
};


#endif //TOPDOWNSHOOTER_STATEMANAGER
