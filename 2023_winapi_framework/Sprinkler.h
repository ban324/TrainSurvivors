#pragma once
#include "Weapon.h"
class Sprinkler :
    public Weapon
{
public:
	Sprinkler();
	~Sprinkler();
public:
	void Update() override;
	void Render(HDC _dc) override;
public:
	void EnterCollision(Collider* _pOther) override;
	void StayCollision(Collider* _pOther) override;

private:
	Texture* m_FieldTexture;
public:
	void SetDelay(float val) { _fieldDelay = val; };
private:
	float _currentTime;
	float _fieldDelay;

};

