/* *CopyRight 2018, Anthony Logan Mitchell, All rights reserved.
   *Holy war is my personal programming project and all artwork
   *and high level programming outside of SDL2 framework, openGL,
   *and c++ api are my original work in progress.
   *Unauthorized copying of this file, via any medium is strictly prohibited
   *Proprietary and confidential
   *Written by Logan Mitchell <loganmitchell2011@gmail.com>
*/
#include "CharacterObject.h"
#include "CharacterTexture.h"

CharacterObject::CharacterObject(std::string Name,int8_t Health,SDL_Renderer* renderer)
{
    this->name=Name;
    this->health = Health;
    this->selfHitBoxOffsetX =0;
    this->selfHitBoxOffsetY = 0;
    this->selfHitBoxOffsetWidth =0;
    this->selfHitBoxOffsetHeight = 0;
    this->attackHitBoxOffsetX =0;
    this->attackHitBoxOffsetY = 0;
    this->attackHitBoxOffsetWidth =0;
    this->attackHitBoxOffsetHeight = 0;
    this->const_x_offset=0;
    this->InitializeCharacter(Name,renderer);
    this->fluct_velx =0;
    this->fluct_vely =0;
    this->posX=0;
    this->posY=0;
    this->isJumping = false;
    this->isMovingLeft = false;
    this->isMovingRight = false;
    this->isFalling = true;
    this->isHoldingReg = false;
    this->isHoldingStrong =false;
    this->isColliding = false;
    this->isAttackingReg = false;
    this->regAttackCount = 0;
    this->StrongAttackCount = 0;
    this->jumpBlock = 0;
    this->regAttackLastPress = SDL_GetTicks();
    this->strongAttackLastPress = SDL_GetTicks();
    this->lastDirection = "LEFT";
    this->attack = NULL;
    this->self = NULL;
}

CharacterObject::~CharacterObject()
{

}

void CharacterObject::InitializeHitBoxes(int scale)
{
    this->attack = new Hitbox(this->posX,\
                              this->posY,\
                              (this->char_textures->idleClips[0].w*scale)+this->attackHitBoxOffsetWidth,\
                              (this->char_textures->idleClips[0].h*scale)+this->attackHitBoxOffsetHeight);

    this->self = new Hitbox(this->posX,\
                            this->posY, \
                            (this->char_textures->idleClips[0].w*scale)+this->selfHitBoxOffsetWidth,\
                            (this->char_textures->idleClips[0].h*scale)+this->selfHitBoxOffsetHeight);
    this->self->isAlpha = true;
    this->attack->isAlpha = true;
}

void CharacterObject::InitializeCharacter(std::string Name,SDL_Renderer* renderer)
{
    //For Sanities sake while doing these.
    //TotalClip numbers parameter structure in CharacterTextures.
    //(IdleClips,JumpingClips,FallingClips,MovementClips,RegularAttackClips,RegularAttackClips2,StrongAttackClips,Name,renderer)
    if(Name == "Horus")
    {
        CharacterTexture* char_ptr = new CharacterTexture(18,11,6,17,14,16,13,0,Name,renderer);
        this->char_textures = char_ptr;
        this->char_textures->idleMod = 4;
        this->char_textures->jumpingMod = 2;
        this->char_textures->moveMod = 2;
        this->char_textures->attackRegMod = 1;
        this->char_textures->attackRegMod2 = 1;
        this->char_textures->fallingMod = 2;
        this->char_textures->attackRegJumpingMod=1;
        this->const_x_offset = 9;
        this->attackHitBoxOffsetHeight = -25;
        this->attackHitBoxOffsetY = 28;
        char_ptr = NULL;
        delete(char_ptr);
    }
}

void CharacterObject::Move()
{

    if(!this->isColliding)
    {
        if(this->isJumping || this->isFalling)
        {
            this->CalculateGravity();
        }
        if(this->fluct_vely >=0)
        {
            this->isFalling = true;
            this->isJumping = false;
        }
    }
    this->posY += this->fluct_vely;
    this->posX += this->fluct_velx;
}

void CharacterObject::CalculateGravity()
{
    this->fluct_vely+=2;
}
