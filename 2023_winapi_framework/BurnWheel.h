#pragma once
#include "Weapon.h"
class BurnWheel :
    public Weapon
{
public:
	BurnWheel();
	~BurnWheel();
public:
	void Update() override;
	void Render(HDC _dc) override;
private:
	Texture* m_projectileTex;
public:
	void SetSpeed(float val) { _bulletSpeed = val; }
	float GetSpeed() { return _bulletDelay; }
private:
	float _bulletSpeed;
	float _currentTime;
	float _bulletDelay;

};

