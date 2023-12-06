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
		int xAbs = (rand() % 1400) - 700;
		spawnX += xAbs;
		int yAbs = 700 - abs(xAbs);
		spawnY += rand() % 2 == 0 ? yAbs : -yAbs;
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