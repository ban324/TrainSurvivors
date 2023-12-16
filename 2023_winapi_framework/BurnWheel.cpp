#include "pch.h"
#include "BurnWheel.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Game_Scene.h"
#include "Projectile.h"
#include "ResMgr.h"
#include "Collider.h"
#include "EventMgr.h"

BurnWheel::BurnWheel()
	:
	_bulletDelay (0),
	_bulletSpeed(0),
	_currentTime(0),
	m_projectileTex(0)
{
	m_wpType = WEAPON_TYPE::BURNINGWHEEL;

	m_projectileTex = ResMgr::GetInst()->TexLoad(L"BurnWheel", L"Texture\\Projectile\\BurnWheel.bmp");

}

BurnWheel::~BurnWheel()
{

}

void BurnWheel::Update()
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
			Vec2 dir = Vec2(0,0);
			dir.x = owner->dir.x * -1;
			proj->SetTag(TAG::WEAPON);
			proj->SetDir(dir);
			proj->SetScale(Vec2(bulletSize, bulletSize));
			proj->owner = this;
			proj->power = power;
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

void BurnWheel::Render(HDC _dc)
{
	for (auto iter = vecProjectiles.begin(); iter != vecProjectiles.end(); ++iter)
	{
		if (!(*iter)->GetIsDead())
		{

			(*iter)->Render(_dc);
		}
		else
		{
			//assert(*iter);
			//EventMgr::GetInst()->DeleteObject(*iter);
			//iter = vecProjectiles.erase(iter);
		}
		if (iter == vecProjectiles.end())break;
	}

}

void BurnWheel::Upgrade()
{
	if (level <= 1)
	{
		owner->AddWeapon(m_wpType);
	}
	else
	{
		duration += 0.3f;
		_bulletSpeed++;
		bulletSize += 8.f;
		projectileCnt += level % 5;
	}
	++level;
}
