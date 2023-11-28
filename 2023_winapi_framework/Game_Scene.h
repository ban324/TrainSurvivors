#pragma once
#include "Scene.h"
class Game_Scene :
    public Scene
{
    virtual void Init() override;
    virtual void Render(HDC _dc) override;

public :
    
};

