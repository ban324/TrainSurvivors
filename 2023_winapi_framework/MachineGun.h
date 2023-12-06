#pragma once
#include "Weapon.h"
class Texture;
class MachineGun
	:public Weapon
{
public:
	MachineGun();
	~MachineGun();
public:
	void Update() override;
	void Render(HDC _dc) override;
private:
	Texture * m_projectileTex;
private:
	float _bulletSpeed;
	float _currentTime;
	float _bulletDelay;
};

