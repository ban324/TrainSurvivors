#include "pch.h"
#include "MonsterMgr.h"
#include "TimeMgr.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "Object.h"

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

void MonsterMgr::UpgradeSpawn()//아이템 고를때마다/다 고를때 호출
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

		int monsterScale = 10;
		Monster* pMonster = new Monster;
		pMonster->SetTag(TAG::ENEMY);
		pMonster->SetPos(SpawnVec2());
		pMonster->SetScale(Vec2(monsterScale, monsterScale));
		pMonster->SetCenterPos(pMonster->GetPos());
		pMonster->SetPlayerObj(playerObj);
		pMonster->SetStat(enemyHp, enemyAttack);
		pMonster->SetMoveDis(10);
		SceneMgr::GetInst()->GetCurScene()->AddObject(pMonster, OBJECT_GROUP::MONSTER);
	}
	else
	{
		currentTime += fDT;
	}
}