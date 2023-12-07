#include "pch.h"
#include "Collider.h"
#include "ResMgr.h"
#include "Robber2.h"

void Robber2::SpriteFlip()
{
	m_fDirX = playerObj->GetPos().x > m_vCenterPos.x ? 1 : -1;
	m_fDirY = playerObj->GetPos().y > m_vCenterPos.y ? 1 : -1;
	if (m_fDirX == 1)
	{
		m_pTex = ResMgr::GetInst()->TexLoad(L"Robber2_Right", L"Texture\\Robber2_Right.bmp");
	}
	else
	{
		m_pTex = ResMgr::GetInst()->TexLoad(L"Robber2_Left", L"Texture\\Robber2_Left.bmp");
	}
}