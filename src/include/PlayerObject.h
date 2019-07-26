#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H
#include "PlayerCursor.h"
#include "SDL.h"



class PlayerObject
{
    public:
        PlayerObject(int,int,int,SDL_Renderer*);
        virtual ~PlayerObject();
        bool isActive;
        PlayerCursor* cursor;
        SDL_GameController* controller;
        int ID;
        //Character Texture

    protected:

    private:
};

#endif // PLAYEROBJECT_H
