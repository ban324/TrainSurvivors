#pragma once
#include "Object.h"
class Texture;
class Weapon;
class Projectile
	:public Object
{
public:
	Projectile();
	~Projectile();
public:
	virtual void Update()override;
	virtual void Render(HDC _Dc)override;
	void EnterCollision(Collider* _pOther) override;
public:
	Weapon * owner;
public:
	float GetSpeed() { return _speed; }
	void SetSpeed(float val) { _speed = val; }
	Texture* GetTexture() { return m_pTex; }
	void SetTexutre(Texture* val) { m_pTex = val; }
	Vec2 GetDir() { return _dir; }
	void SetDir(Vec2 val) { _dir = val; }
	void SetDuration(float val) { _lifeTime = val; }
public:
	int power;
	bool isCactus;
private:
	float _lifeTime = 3.f;
	float _curLT = 0;
	float _speed;
	Vec2 _dir;
	Texture * m_pTex;
};