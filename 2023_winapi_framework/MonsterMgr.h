#pragma once
#include "define.h"
#include "pch.h"
#include "Monster.h"
#include "Object.h"

class MonsterMgr
{
	SINGLE(MonsterMgr);
private:
	Monster* pMonster = nullptr;
	Object* playerObj;
	float spawnTime = 2.f;
	float currentTime = 0.f;
	bool isSpawning = false;
public:
	void SetPlayerObj(Object* pObj);
	void StartSpawnMonster();
	void StopSpawnMonster();
	void UpgradeSpawn();
	void Update();
private:
	const Vec2 SpawnVec2() const
	{
		playerObj->GetPos().x;
		int spawnX = playerObj->GetPos().x;
		bool left = rand() % 2 == 0;
		spawnX += rand() % 2 == 0 ? 300 : -300;
		Vec2 spawnVec;
		spawnVec.x = spawnX;
		spawnVec.y = playerObj->GetPos().y;
		return spawnVec;
	}
	const bool& IsSpawning() const
	{
		return isSpawning;
	}
};