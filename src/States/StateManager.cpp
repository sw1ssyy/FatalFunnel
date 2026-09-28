//
// Created by sw1ssyy on 26/09/2026.
//

#include "StateManager.h"

#include "GameState.h"
#include "MenuState.h"

StateManager::StateManager()
{
    SetupStates();
}

IState& StateManager::GetCurrentState()
{
    return *states.at(statePointer);
}

void StateManager::SetState(StateID state)
{
    statePointer = state;

    states.at(statePointer)->OnEnter();
}

void StateManager::SetupStates()
{
    states[MENU] = std::make_unique<MenuState>(this);
    states[GAME] = std::make_unique<GameState>(this);
}

void StateManager::RequestQuit()
{
    quitRequested = true;
}

bool StateManager::ShouldQuit() const
{
    return quitRequested;
}
