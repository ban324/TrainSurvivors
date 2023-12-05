#pragma once
#include "Object.h"
class Texture {};
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
	float GetSpeed() { return _speed; }
	void SetSpeed(float val) { _speed = val; }
	Texture* GetTexture() { return m_pTex; }
	void SetTexutre(Texture* val) { m_pTex = val; }
	Vec2 GetDir() { return _dir; }
	void SetDir(Vec2 val) { _dir = val; }
private:
	Vec2 _dir;
	float _speed;
	Texture * m_pTex;
};