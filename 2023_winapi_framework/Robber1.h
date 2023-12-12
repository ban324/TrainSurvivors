#pragma once
#include "Monster.h"
class Texture;
class Robber1 :
    public Monster
{
public:
    virtual void SpriteFlip() override;
};