#ifndef STATE_H
#define STATE_H
#include "MainMenuOptions.h"


class State
{
public:
    State();
    virtual ~State();
    bool onMainMenuStart;
    bool onOptionSelection;
    bool onLevelSelction;
    bool onCharacterSelection;
    bool onRunningMatch;
    bool transition;
    MainMenuOptions* mainMenuOps;

private:
};

#endif // STATE_H
