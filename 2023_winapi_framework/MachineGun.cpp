#include "pch.h"
#include "MachineGun.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Game_Scene.h"
#include "Projectile.h"
#include "ResMgr.h"
MachineGun::MachineGun()
	:m_projectileTex(nullptr),
	_currentTime(0.f)
{
	m_projectileTex = ResMgr::GetInst()->TexLoad(L"MachineGunProjectile", L"Texture\\Projectile\\MachineGunProjectile.bmp");
}

MachineGun::~MachineGun()
{
}
void MachineGun::Update()
{
	_currentTime += fDT;
	SetPos(owner->GetPos());
	if (_currentTime >= cooltime)
	{
		std::shared_ptr<Scene> scene =  SceneMgr::GetInst()->GetCurScene();
		for (int i = 0; i < projectileCnt; ++i)
		{
			Projectile * proj = new Projectile();
			proj->SetTexutre(m_projectileTex);
			proj->SetSpeed(_bulletSpeed);
			proj->SetPos(GetPos());
			Vec2 dir = owner->dir;
			proj->SetDir(dir);
			scene->AddObject(proj, OBJECT_GROUP::BULLET);
		}
		_currentTime = 0;
	}
}

void MachineGun::Render(HDC _dc)
{
}
