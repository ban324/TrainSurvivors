#include "pch.h"
#include "MonsterMgr.h"
#include "TimeMgr.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "Object.h"
#include "Robber1.h"
#include "Robber2.h"
#include "Robber3.h"
#include "Robber4.h"

void MonsterMgr::SetPlayerObj(Player* pObj)
{
	playerObj = pObj;
}

void MonsterMgr::StartSpawnMonster()
{
	isSpawning = true;
}

void MonsterMgr::StopSpawnMonster()
{
	isSpawning = false;
}

void MonsterMgr::UpgradeSpawn()//아이템 고를때마다 고를때 호출
{
	spawnTime -= 0.1f;
	enemyHp += 1.f;
	enemyAttack += 1.f;
}

void MonsterMgr::Update()
{
	if (IsSpawning() && currentTime > spawnTime)
	{
		currentTime = 0;

		Monster* pMonster;

		int random = rand() % 10;
		if (random > 6)
		{
			pMonster = new Robber1;
			pMonster->SetKind(MONSTER_KIND::NORMAL1);
			pMonster->SetStat(enemyHp, enemyAttack, 50);
		}
		else if (random > 3)
		{
			pMonster = new Robber2;
			pMonster->SetKind(MONSTER_KIND::NORMAL2); 
			pMonster->SetStat(enemyHp, enemyAttack, 50);
		}
		else if (random > 0)
		{
			pMonster = new Robber3;
			pMonster->SetKind(MONSTER_KIND::NORMAL3);
			pMonster->SetStat(enemyHp, enemyAttack, 50);
		}
		else
		{
			pMonster = new Robber4;
			pMonster->SetKind(MONSTER_KIND::BOSS);
			pMonster->SetStat(enemyHp, enemyAttack, 60);
		}

		int monsterScale = 10;
		TAG monsterTag = TAG::ENEMY;
		pMonster->SetTag(monsterTag);
		pMonster->SetPos(SpawnVec2());
		pMonster->SetScale(Vec2(monsterScale, monsterScale));
		pMonster->SetCenterPos(pMonster->GetPos());
		pMonster->SetPlayerObj(playerObj);
		pMonster->SetMoveDis(10);
		SceneMgr::GetInst()->GetCurScene()->AddObject(pMonster, OBJECT_GROUP::MONSTER);
	}
	else
	{
		currentTime += fDT;
	}
}