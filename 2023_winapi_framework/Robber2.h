#pragma once
#include "Monster.h"
class Texture;
class Robber2 :
    public Monster
{
public:
    virtual void SpriteFlip() override;
};