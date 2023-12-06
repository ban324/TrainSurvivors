#pragma once
#include "Object.h"
class Weapon;
class Texture;
class Player :
    public Object
{
public:
    Player();
    ~Player();
public:
    void Update() override;
    void Render(HDC _dc) override;
private:
    void CreateBullet();
private:
    bool isRight;
private:
    Texture* m_pTex;
public :
    float GetHP()
    {
        return currentHP;
    }
public:
    vector<Weapon *> weapons;
public:
    Vec2 dir;
public:
    float maxHP;
    float currentHP;
    float speed;
    float power;
    float duration;
    float bulletSize;
    float coolTimePercent;
};

