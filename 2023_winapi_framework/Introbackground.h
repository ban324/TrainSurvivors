#pragma once
#pragma once
#include "Object.h"
class Texture;
class Introbackground :
    public Object
{
public:
    Introbackground(Texture* tex);
    ~Introbackground();
public:
    void Update() override;
    void Render(HDC _dc) override;
private:
    Texture* m_pTex;
};