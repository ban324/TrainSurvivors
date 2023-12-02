#include "pch.h"
#include "Monster.h"
#include "TimeMgr.h"
#include "Collider.h"
#include "Object.h"
#include "EventMgr.h"
#include "SceneMgr.h"
#include "ResMgr.h"
#include "Texture.h"
Monster::Monster()
	: playerObj(nullptr)
	, m_fSpeed(100.f)
	, m_attack(10)
	, m_fMaxDis(50.f)
	, m_vCenterPos(Vec2(10.f, 10.f))
	, m_fDir(1.f) // 오른쪽부터 이동
	, m_iHp(5)
	, m_pTex(nullptr)
{
	CreateCollider();
}

Monster::~Monster()
{
}

void Monster::Update()
{
	//m_fDir = playerObj->GetPos().x > m_vCenterPos.x ? 1 : -1;
	Vec2 vCurPos = GetPos();
	vCurPos.x += m_fSpeed * fDT * m_fDir;
	
	// 내가 갈 수 있는 거리 최대로 갔냐? => 방향 바꿔줄거야.
	//float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDis;
	//if (fDist > 0.f)
	//{
	//	// dir 바꾸기
	//	m_fDir *= -1;
	//	vCurPos.x += fDist * m_fDir;
	//}
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

void Monster::SetPlayerObj(Player* pObj)
{
	playerObj = pObj;
	m_fDir = playerObj->GetPos().x > m_vCenterPos.x ? 1 : -1;
	if (m_fDir == 1) //오른쪽사진
	{
		//m_pTex = ResMgr::GetInst()->TexLoad(L"Monster", L"Texture\\Robber1.bmp");
	}
	else //왼쪽사진
	{
		//m_pTex = ResMgr::GetInst()->TexLoad(L"Monster", L"Texture\\Robber1.bmp");	
	}
	m_pTex = ResMgr::GetInst()->TexLoad(L"Monster", L"Texture\\planem.bmp");
}


void Monster::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();
	TAG* tag = pOtherObj->GetTag();
	if ( *tag == TAG::WEAPON)
	{
		// 삭제처리해주면돼.
		m_iHp--;
		if(m_iHp<=0)
			EventMgr::GetInst()->DeleteObject(this);
	}
	else if (*tag == TAG::PLYAER)
	{
		playerObj->currentHP -= m_attack;
		EventMgr::GetInst()->DeleteObject(this);
	}
}

void Monster::ExitCollision(Collider* _pOther)
{
}

void Monster::StayCollision(Collider* _pOther)
{
}