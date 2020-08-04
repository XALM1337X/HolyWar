/* *CopyRight 2018, Anthony Logan Mitchell, All rights reserved.
   *Holy war is my personal programming project and all artwork
   *and high level programming outside of SDL2 framework, openGL,
   *and c++ api are my original work in progress.
   *Unauthorized copying of this file, via any medium is strictly prohibited
   *Proprietary and confidential
   *Written by Logan Mitchell <loganmitchell2011@gmail.com>
*/


#ifndef PROJECTILETEXTURE_H
#define PROJECTILETEXTURE_H
#include "Texture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include <iostream>
    class ProjectileTexture : public Texture {
        
        public: 
            void Free_Texture();
            int  GetWidth();
            int  GetHeight();
            void SetWidth(int);
            void SetHeight(int);
            void SetFrameCount(int);
            int  GetFrameCount();
            int  GetXPos();
            int  GetYPos();
            void SetXPos(int);
            void SetYPos(int);
            bool loadProjectileFromFile(std::string,SDL_Renderer*);
            bool loadProjectileMedia(SDL_Renderer*);
            void render(SDL_Renderer*, int, int, int, int, int, SDL_Rect*, SDL_RendererFlip);

            SDL_Texture* texture;
            SDL_Rect* clips;
        private:
            std::string name;
            int width;
            int height;
            int xposition;
            int yposition;
            int frameCount;
    };
#endif