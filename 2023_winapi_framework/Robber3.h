#pragma once
#include "Monster.h"
class Texture;
class Robber3 :
    public Monster
{
public:
    virtual void SpriteFlip() override;
};