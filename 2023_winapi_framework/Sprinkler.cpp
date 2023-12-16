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
#include "Monster.h"
Sprinkler::Sprinkler()
	:
	_currentTime(0),
	_fieldDelay(0),
	m_FieldTexture(0)
{
	m_wpType = WEAPON_TYPE::SPRINKLER;
	SetName(L"Sprinkler");
	m_FieldTexture = ResMgr::GetInst()->TexLoad(L"Sprinkler", L"Texture\\Projectile\\Sprinkler.bmp");
	CreateCollider();
}

Sprinkler::~Sprinkler()
{
}

void Sprinkler::Update()
{
	SetPos(owner->GetPos());
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

void Sprinkler::Upgrade()
{
	if (level <= 1)
	{
		owner->AddWeapon(m_wpType);
	}
	++level;

	Vec2 sc = GetScale();
	sc.x += 1;
	sc.y += 1;
	power + 1;
	SetScale(sc);
	GetCollider()->SetScale(sc);

}

void Sprinkler::EnterCollision(Collider* _pOther)
{

}

void Sprinkler::StayCollision(Collider* _pOther)
{

}
