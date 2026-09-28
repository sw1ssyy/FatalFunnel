//
// Created by johnc on 26/09/2026.
//

#ifndef TOPDOWNSHOOTER_ISTATE
#define TOPDOWNSHOOTER_ISTATE
class StateManager;

class IState
{
public:
    IState(StateManager* manager): stateManager(manager) {}

    virtual void Draw() = 0;
    virtual void Update() = 0;
    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;

    virtual ~IState() = default;

protected:
    StateManager* stateManager;
};



#endif //TOPDOWNSHOOTER_ISTATE
