//
// Created by sw1ssyy on 26/09/2026.
//

#include "StateManager.h"

#include "GameState.h"
#include "MenuState.h"

IState& StateManager::GetCurrentState()
{
    return *_states.at(_statePointer);
}

void StateManager::Init()
{
    SetupStates();

    _statePointer = MENU;

    _states.at(_statePointer)->OnEnter();
}

void StateManager::SetState(StateID state)
{
    _states.at(_statePointer)->OnExit();

    _statePointer = state;

    _states.at(_statePointer)->OnEnter();
}

void StateManager::SetupStates()
{
    _states[MENU] = std::make_unique<MenuState>(this);
    _states[GAME] = std::make_unique<GameState>(this);
}

void StateManager::RequestQuit()
{
    _quitRequested = true;
}

bool StateManager::ShouldQuit() const
{
    return _quitRequested;
}
