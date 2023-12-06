#pragma once
#include"Object.h"
#include "Player.h"
class Weapon
	:public Object
{
public:
	virtual void Update();
	virtual void Render(HDC _dc);
public:
	Player * owner;
public:
	float cooltime;
	float power;
	float duration;
	float bulletSize;
	int projectileCnt;
};

