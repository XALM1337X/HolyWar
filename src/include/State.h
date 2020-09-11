/* *CopyRight 2018, Anthony Logan Mitchell, All rights reserved.
   *Holy war is my personal programming project and all artwork
   *and high level programming outside of SDL2 framework, openGL,
   *and c++ api are my original work in progress.
   *Unauthorized copying of this file, via any medium is strictly prohibited
   *Proprietary and confidential
   *Written by Logan Mitchell <loganmitchell2011@gmail.com>
*/
#ifndef STATE_H
#define STATE_H
#include <string>
class MainMenuOptions;
class State
{
public:
    State();
    virtual ~State();
    bool onMainMenuStart;
    bool onOptionSelection;
    bool onLevelSelection;
    bool onCharacterSelection;
    bool onRunningMatch;
    bool transition;
    bool quit_program;
    MainMenuOptions* mainMenuOps;
    std::string levelName;

private:
};

#endif // STATE_H
