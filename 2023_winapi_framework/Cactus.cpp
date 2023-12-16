#include "pch.h"
#include "Cactus.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Game_Scene.h"
#include "Projectile.h"
#include "ResMgr.h"
#include "Collider.h"
#include "EventMgr.h"
Cactus::Cactus()
	:m_projectileTex(nullptr),
	_currentTime(0.f)
{
	m_wpType = WEAPON_TYPE::CACTUS;
	m_projectileTex = ResMgr::GetInst()->TexLoad(L"CactusProjectile", L"Texture\\Projectile\\Cactus.bmp");
}

Cactus::~Cactus()
{
}
void Cactus::Update()
{
	_currentTime += fDT;
	SetPos(owner->GetPos());
	if (_currentTime >= cooltime)
	{
		std::shared_ptr<Scene> scene = SceneMgr::GetInst()->GetCurScene();
		for (int i = 0; i < projectileCnt; ++i)
		{
			Projectile* proj = new Projectile();
			proj->SetTexutre(m_projectileTex);
			proj->SetSpeed(_bulletSpeed);
			proj->SetPos(GetPos());
			Vec2 dir = Vec2(rand(), rand());
			dir.x *= rand() % 2 == 0 ? 1 : -1;
			dir.y *= rand() % 2 == 0 ? 1 : -1;
			
			dir = dir.Normalize();

			proj->SetTag(TAG::WEAPON);
			proj->SetDir(dir);
			proj->SetScale(Vec2(bulletSize, bulletSize));
			proj->owner = this;
			proj->power = power;
			proj->isCactus = true;
			proj->SetDuration(duration);
			proj->GetCollider()->SetScale(Vec2(bulletSize, bulletSize));
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

void Cactus::Render(HDC _dc)
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

void Cactus::Upgrade()
{

	if (level <= 1)
	{
		owner->AddWeapon(m_wpType);
	}
	++level;
	
	
	_bulletSpeed += 20.f;
	bulletSize += 20;
	projectileCnt+= level %3 ? 1: 0;
	
}