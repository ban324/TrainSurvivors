#include "pch.h"
#include "MonsterMgr.h"
#include "TimeMgr.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "Object.h"

void MonsterMgr::SetPlayerObj(Object* pObj)
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

void MonsterMgr::UpgradeSpawn()//������ ��������/�� ���� ȣ��
{
	spawnTime -= 0.1f;
}

void MonsterMgr::Update()
{
	if (IsSpawning() && currentTime > spawnTime)
	{
		currentTime = 0;

		int monsterScale = 10;

		pMonster = new Monster;
		pMonster->SetPlayerObj(playerObj);
		pMonster->SetPos(SpawnVec2());
		pMonster->SetScale(Vec2(monsterScale, monsterScale));
		pMonster->SetCenterPos(pMonster->GetPos());
		pMonster->SetMoveDis(10);
		SceneMgr::GetInst()->GetCurScene()->AddObject(pMonster, OBJECT_GROUP::MONSTER);
	}
	else
	{
		currentTime += fDT;
	}
}