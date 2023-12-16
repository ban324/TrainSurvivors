#include "pch.h"
#include "Texture.h"
#include "Sprinkler.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Game_Scene.h"
#include "Projectile.h"
#include "ResMgr.h"
#include "Collider.h"
#include "EventMgr.h"
Sprinkler::Sprinkler()
	:
	_currentTime(0),
	_fieldDelay(0),
	m_FieldTexture(0)
{
	SetName(L"Sprinkler");
	m_FieldTexture = ResMgr::GetInst()->TexLoad(L"MachineGunProjectile", L"Texture\\Projectile\\Sprinkler.bmp");
	CreateCollider();
}

Sprinkler::~Sprinkler()
{
}

void Sprinkler::Update()
{
}

void Sprinkler::Render(HDC _dc)
{
	Vec2 vpos = GetPos();
	Vec2 vscale = GetScale();
	int Width = m_FieldTexture->GetWidth();
	int Height = m_FieldTexture->GetHeight();

	TransparentBlt(_dc
		, (int)(vpos.x - vscale.x / 2)
		, (int)(vpos.y - vscale.y / 2)
		, vscale.x, vscale.y, m_FieldTexture->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));

	Component_Render(_dc);

}

void Sprinkler::EnterCollision(Collider* _pOther)
{

}

void Sprinkler::StayCollision(Collider* _pOther)
{

}
