#include "pch.h"
#include "MachineGun.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Game_Scene.h"
#include "Projectile.h"
#include "ResMgr.h"
#include "Collider.h"
#include "EventMgr.h"
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
			proj->SetTag(TAG::WEAPON);
			proj->SetDir(dir);
			proj->SetScale(Vec2(20.f, 20.f));
			proj->owner = this;
			proj->power = power;
			proj->SetDuration(duration);
			proj->GetCollider()->SetScale(Vec2(20.f,20.f));
			vecProjectiles.push_back(proj);
			scene->AddObject(proj, OBJECT_GROUP::BULLET);
			
		}
		_currentTime = 0;
	}
	for (auto iter = vecProjectiles.begin(); iter != vecProjectiles.end(); ++iter)
	{
		(*iter)->Update();
	}
}

void MachineGun::Render(HDC _dc)
{
	for (auto iter = vecProjectiles.begin(); iter != vecProjectiles.end(); ++iter)
	{
		if (!(*iter)->GetIsDead())
		{

			(*iter)->Render(_dc);
		}
		else
		{
			assert(*iter);
			EventMgr::GetInst()->DeleteObject(*iter);
			iter = vecProjectiles.erase(iter);
		}
	}
}
