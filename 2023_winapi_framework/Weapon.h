#pragma once
#include"Object.h"
#include "Player.h"
class Projectile;
class Weapon
	:public Object
{
public:
	virtual void Update();
	virtual void Render(HDC _dc);
	void Upgrade();
public:
	Player * owner;
public:
	vector<Projectile*> vecProjectiles;

public:
	float cooltime;
	float power;
	float duration;
	float bulletSize;
	int projectileCnt;
	int level;
};

