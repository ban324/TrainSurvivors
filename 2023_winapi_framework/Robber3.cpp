#include "pch.h"
#include "Collider.h"
#include "ResMgr.h"
#include "Robber3.h"

void Robber3::SpriteFlip()
{
	m_fDirX = playerObj->GetPos().x > m_vCenterPos.x ? 1 : -1;
	m_fDirY = playerObj->GetPos().y > m_vCenterPos.y ? 1 : -1;
	if (m_fDirX == 1)
	{
		m_pTex = ResMgr::GetInst()->TexLoad(L"Robber3_Right", L"Texture\\Robber3_Right.bmp");
	}
	else
	{
		m_pTex = ResMgr::GetInst()->TexLoad(L"Robber3_Left", L"Texture\\Robber3_Left.bmp");
	}
}