#include "pch.h"
#include "Collider.h"
#include "ResMgr.h"
#include "Robber1.h"

void Robber1::SpriteFlip()
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