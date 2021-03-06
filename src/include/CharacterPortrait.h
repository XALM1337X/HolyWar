/* *CopyRight 2018, Anthony Logan Mitchell, All rights reserved.
   *Holy war is my personal programming project and all artwork
   *and high level programming outside of SDL2 framework, openGL,
   *and c++ api are my original work in progress.
   *Unauthorized copying of this file, via any medium is strictly prohibited
   *Proprietary and confidential
   *Written by Logan Mitchell <loganmitchell2011@gmail.com>
*/
#ifndef CHARACTERPORTRAIT_H
#define CHARACTERPORTRAIT_H
#include "GeneralTexture.h"
#include "string"
#include <vector>

class CharacterPortrait
{
    public:
        CharacterPortrait(int,std::string,std::string,SDL_Renderer*);
        static std::vector<CharacterPortrait*>* InitCharacterPortraits(SDL_Renderer*);
        virtual ~CharacterPortrait();


        GeneralTexture* avatar;
        std::string CharacterName;

    private:
};

#endif // CHARACTERPORTRAIT_H
