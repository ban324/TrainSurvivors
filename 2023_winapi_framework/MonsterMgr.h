#pragma once
#include "define.h"
#include "pch.h"
#include "Monster.h"
#include "Object.h"

class MonsterMgr
{
	SINGLE(MonsterMgr);
private:
	Player* playerObj;
	float enemyHp = 5.f;
	float enemyAttack = 2.f;
	float spawnTime = 2.f;
	float currentTime = 0.f;
	bool isSpawning = false;
public:
	void SetPlayerObj(Player* pObj);
	void StartSpawnMonster();
	void StopSpawnMonster();
	void UpgradeSpawn();
	void Update();
private:
	const Vec2 SpawnVec2() const
	{
		playerObj->GetPos().x;
		int spawnX = playerObj->GetPos().x;
		int spawnY = playerObj->GetPos().y;
		bool left = rand() % 2 == 0;
		bool up = rand() % 2 == 0;
		spawnX += rand() % 2 == 0 ? 700 : -700;
		spawnY += rand() % 2 == 0 ? 700 : -700;
		Vec2 spawnVec;
		spawnVec.x = spawnX;
		spawnVec.y = spawnY;
		return spawnVec;
	}
	const bool& IsSpawning() const
	{
		return isSpawning;
	}
};