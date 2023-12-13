#pragma once
#include "Weapon.h"
class Turret :
    public Weapon
{
public:
	Turret();
	~Turret();
public:
	void Update() override;
	void Render(HDC _dc) override;
private:
	Texture* m_projectileTex;
private:
	float _bulletSpeed;
	float _currentTime;
	float _bulletDelay;
};

