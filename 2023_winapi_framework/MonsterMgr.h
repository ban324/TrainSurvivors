#pragma once
#include "define.h"
#include "pch.h"
#include "Monster.h"

class MonsterMgr
{
	SINGLE(MonsterMgr);
private:
	Monster* pMonster = nullptr;
	Vec2 playerVec;
	float spawnTime = 2.f;
	float currentTime = 0.f;
	bool isSpawning = false;
public:
	void SetPlayerVec(Vec2 pVec);
	void StartSpawnMonster();
	void StopSpawnMonster();
	void UpgradeSpawn();
	void Update();
private:
	const Vec2 SpawnVec2() const
	{
		int spawnX = playerVec.x;
		bool left = rand() % 2 == 0;
		spawnX += rand() % 2 == 0 ? 10 : -10;
		Vec2 spawnVec;
		spawnVec.x = spawnX;
		spawnVec.y = playerVec.y;
		return spawnVec;
	}
	const bool& IsSpawning() const
	{
		return isSpawning;
	}
};