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
public:
	Weapon * owner;
public:
	float GetSpeed() { return _speed; }
	void SetSpeed(float val) { _speed = val; }
	Texture* GetTexture() { return m_pTex; }
	void SetTexutre(Texture* val) { m_pTex = val; }
	Vec2 GetDir() { return _dir; }
	void SetDir(Vec2 val) { _dir = val; }
private:
	float _lifeTime = 3.f;
	float _curLT = 0;
	Vec2 _dir;
	float _speed;
	Texture * m_pTex;
};