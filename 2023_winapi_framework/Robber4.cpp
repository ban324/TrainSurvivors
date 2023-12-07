#include "pch.h"
#include "Collider.h"
#include "ResMgr.h"
#include "Robber4.h"

void Robber4::SpriteFlip()
{
	m_fDirX = playerObj->GetPos().x > m_vCenterPos.x ? 1 : -1;
	m_fDirY = playerObj->GetPos().y > m_vCenterPos.y ? 1 : -1;
	if (m_fDirX == 1)
	{
		m_pTex = ResMgr::GetInst()->TexLoad(L"Robber3_Right", L"Texture\\Robber4_Right.bmp");
	}
	else
	{
		m_pTex = ResMgr::GetInst()->TexLoad(L"Robber3_Left", L"Texture\\Robber4_Left.bmp");
	}
}