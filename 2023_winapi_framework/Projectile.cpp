#include "pch.h"
#include "Projectile.h"
#include "Res.h"
#include "Texture.h"
#include "ResMgr.h"
#include "TimeMgr.h"
Projectile::Projectile()
	:m_pTex(nullptr),
	_speed(120.f)
{
}

Projectile::~Projectile()
{
}

void Projectile::Update()
{
	Vec2 vPos = GetPos();
	vPos.x += GetDir().x * fDT * 200;
	SetPos(vPos);
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
	, Width, Height, m_pTex->GetDC()
	, 0, 0, Width,Height, RGB(255,0,255));

}
