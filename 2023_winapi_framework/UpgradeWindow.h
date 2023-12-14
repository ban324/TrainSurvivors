#pragma once
#include "Object.h"
#include "Vec2.h"
#include "Weapon.h"

class UpgradeWindow :
    public Object
{
public://������, �Ҹ���
    UpgradeWindow(Weapon* playerWeapon);
    ~UpgradeWindow();
public://�Լ�
    bool IsRange(const POINT mousePoint);
    void UpgradeWeapon();
public://�Լ�
    Weapon* weapon;
    int weaponLevel;
};