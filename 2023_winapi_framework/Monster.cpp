#include "pch.h"
#include "Monster.h"
#include "TimeMgr.h"
#include "Collider.h"
#include "Object.h"
#include "EventMgr.h"
#include "SceneMgr.h"
#include "ResMgr.h"
#include "Texture.h"
#include "Projectile.h"
Monster::Monster()
	: playerObj(nullptr)
	, m_fSpeed(100.f)
	, m_fAttack(10)
	, m_fDelay(3)
	, m_fMaxDis(50.f)
	, m_vCenterPos(Vec2(10.f, 10.f))
	, m_fDirX(0.f)
	, m_fDirY(0.f)
	, m_iHp(5)
	, time(0)
	, m_pTex(nullptr)
{
	CreateCollider();
	m_pCollider->SetOffSetPos(Vec2(m_vCenterPos.x + 15, m_vCenterPos.y + 15));
}

Monster::~Monster()
{
}

void Monster::Update()
{
	//m_fDir = playerObj->GetPos().x > m_vCenterPos.x ? 1 : -1;
	Vec2 vCurPos = GetPos();

	Vec2 vec = Vec2(playerObj->GetPos().x - vCurPos.x, playerObj->GetPos().y - vCurPos.y).Normalize();
	
	int x = abs(vCurPos.x - playerObj->GetPos().x);
	int y = abs(vCurPos.y - playerObj->GetPos().y);
	int z = sqrt(pow(x, 2) + pow(y, 2));

	if (z > 65.f)
	{
		vCurPos.x += m_fSpeed * fDT * vec.x;
		vCurPos.y += m_fSpeed * fDT * vec.y;
	}

	//구버전
	/*if (abs(vCurPos.x - playerObj->GetPos().x) > 35.f)
		vCurPos.x += m_fSpeed * fDT * vec.x;
	if(abs(vCurPos.y - playerObj->GetPos().y) > 35.f)
		vCurPos.y += m_fSpeed * fDT * vec.y;*/

	SpriteFlip();

	SetPos(vCurPos);
}

void Monster::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	//ELLIPSE_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
	TransparentBlt(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, Width, Height, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));
	Component_Render(_dc);
}

void Monster::SpriteFlip()
{
	m_fDirX = playerObj->GetPos().x > m_vCenterPos.x ? 1 : -1;
	m_fDirY = playerObj->GetPos().y > m_vCenterPos.y ? 1 : -1;
	if (m_fDirX == 1)
	{
		m_pTex = ResMgr::GetInst()->TexLoad(L"Robber1_Right", L"Texture\\Robber1_Right.bmp");
	}
	else
	{
		m_pTex = ResMgr::GetInst()->TexLoad(L"Robber1_Left", L"Texture\\Robber1_Left.bmp");
	}
}

void Monster::SetPlayerObj(Player* pObj)
{
	playerObj = pObj;
	SpriteFlip();
}


void Monster::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	TAG* tag = pOtherObj->GetTag();
	if ( *tag == TAG::WEAPON)
	{
		const Projectile* proj = dynamic_cast<const Projectile*>(_pOther->GetObj());
		if (proj)
		{
			m_iHp -= proj->power;

		}

		if(m_iHp<=0)
			EventMgr::GetInst()->DeleteObject(this);
	}
	else if (*tag == TAG::PLYAER)
	{
		time = 0;
	}
}

void Monster::ExitCollision(Collider* _pOther)
{

}

void Monster::StayCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	TAG* tag = pOtherObj->GetTag();
	if (time > m_fDelay && *tag == TAG::PLYAER)
	{
		//공격
		playerObj->currentHP -= m_fAttack;
		time = 0;
	}
	time += m_fSpeed * fDT * 3;
}