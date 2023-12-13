#pragma once
#include "Object.h"
#include "Vec2.h"
#include "Weapon.h"

class UpgradeWindow :
    public Object
{
public://생성자, 소멸자
    UpgradeWindow(Weapon* playerWeapon);
    ~UpgradeWindow();
public://함수
    bool IsRange(const POINT mousePoint);
    void UpgradeWeapon();
private://함수
    Weapon* weapon;
};