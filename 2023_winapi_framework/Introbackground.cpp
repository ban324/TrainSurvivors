#include "pch.h"
#include "Introbackground.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Texture.h"
#include "PathMgr.h"
#include "ResMgr.h"
Introbackground::Introbackground(Texture* tex)
	: m_pTex(tex)
{
	//m_pTex = ResMgr::GetInst()->TexLoad(L"Player", L"plane.bmp");
}
Introbackground::~Introbackground()
{
	
}

void Introbackground::Update()
{
	Vec2 vPos = GetPos();
	SetPos(vPos);
	/*Vec2 vScale = GetScale();
	SetScale(vScale);*/
}

void Introbackground::Render(HDC _dc)
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
