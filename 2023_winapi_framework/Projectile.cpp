#include "pch.h"
#include "Projectile.h"
#include "Res.h"
#include "Texture.h"
#include "ResMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "Object.h"
#include "Scene.h"
#include "Weapon.h"
#include "Collider.h"
Projectile::Projectile()
	:m_pTex(nullptr),
	_speed(120.f),
	owner(nullptr),
	power(0)
{
	CreateCollider();
}

Projectile::~Projectile()
{

}

void Projectile::Update()
{
	Vec2 vPos = GetPos();
	_curLT += fDT;
	vPos.x += GetDir().x * fDT * _speed;
	vPos.y += GetDir().y * fDT * _speed;
	SetPos(vPos);
	isCactus;
	if (_curLT >= _lifeTime)
	{
		m_IsAlive = false;

	}
}

void Projectile::Render(HDC _Dc)
{
	Vec2 vpos = GetPos();
	Vec2 vscale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	TransparentBlt(_Dc
	, (int)(vpos.x - vscale.x / 2)
	, (int)(vpos.y - vscale.y / 2)
	, vscale.x, vscale.y, m_pTex->GetDC()
	, 0, 0, Width,Height, RGB(255,0,255));

	Component_Render(_Dc);
}

void Projectile::EnterCollision(Collider* _pOther)
{
	if (isCactus )
	{
			if ((*_pOther->GetObj()->GetTag()) == TAG::ENEMY)
			{
				Vec2 dir = GetDir();
				dir.x *= -1;
				dir.y *= -1;
				SetDir(dir);
				bounded = true;
				boundCnt -= 4;
			}

	}
}

void Projectile::ExitCollision(Collider* _pOther)
{
	bounded = false;
	boundCnt = 0;
}
