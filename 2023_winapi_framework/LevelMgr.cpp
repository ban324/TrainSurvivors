#include "pch.h"
#include "TimeMgr.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "LevelMgr.h"
#include "KeyMgr.h"
#include "UpgradeWindow.h"
#include "Core.h"
#include "EventMgr.h"
#include "GaugeBar.h"
#include "weapon.h"
#include "MonsterMgr.h"
#include "ResMgr.h"
#include <iostream>

void LevelMgr::Update()
{
	if (!isRun) return;

	if (isOpen)
	{
		for (int i = 0; i < 3; i++)
		{
			if (KEY_DOWN(KEY_TYPE::LBUTTON) && windowObj[i]->IsRange(KeyMgr::GetInst()->GetMousePos()))
			{
				OnUpgradeBtnClick(i);
			}
		}
	}
	else//경험치 쌓기
	{
		if (gaugeBar->currentExperience > maxExperience)
		{
				level++;

			maxExperience = 1 + level * level;
			UpgradePanelUp();
		}
	}
}

void LevelMgr::Render(HDC _dc)
{
	if (!isOpen) return;

	for (int i = 0; i < 3; i++)
	{
		SelectObject(_dc, ResMgr::GetInst()->GetFont(L"SubFont"));

		Weapon* ww = windowObj[i]->weapon;

		wstring levelStr = std::to_wstring(ww->level);
		LPCWSTR name = ww->GetName().c_str();
		LPCWSTR level = levelStr.c_str();

		int nameLength = ww->GetName().length();
		int levelLength = levelStr.length() + 1;

		TextOut(_dc, windowObj[i]->GetPos().x, windowObj[i]->GetPos().y, name, nameLength);
		TextOut(_dc, windowObj[i]->GetPos().x, windowObj[i]->GetPos().y + 50, level, levelLength);
	}
}

void LevelMgr::SettingWeapons(vector<Weapon*>& weapons)
{
	isRun = true;

	gaugeBar = new GaugeBar;
	gaugeBar->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - 200, 50 })));
	gaugeBar->SetScale(Vec2(100.f, 100.f));
	//gaugeBar->SetTag(TAG::PLYAER);
	SceneMgr::GetInst()->GetCurScene()->AddObject(gaugeBar, OBJECT_GROUP::UI);

	levelEx = { 50, 50, 50, 50 };//레벨당 최대경험치

	level = 0;
	maxExperience = 1 + level * level;
	gaugeBar->Reset(maxExperience);

	playerWeapons.clear();

	for (int i = 0; i < weapons.size(); i++)
	{
		playerWeapons.push_back(weapons[i]);
	}
}

void LevelMgr::IncreseExperience(int ex)
{
	gaugeBar->Increse(ex);
}

void LevelMgr::UpgradePanelUp()
{
	//isOpen = true;
	
	std::set<int> benIndex;
	for (int i = 0; i < 3; i++)
	{
		int weaponIndex = rand() % playerWeapons.size();
		while (benIndex.find(weaponIndex) != benIndex.end())
		{
			weaponIndex = rand() % playerWeapons.size();
		}
		benIndex.insert(weaponIndex);

		windowObj[i] = new UpgradeWindow(playerWeapons[weaponIndex]);
		windowObj[i]->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - (i * 500) + 300, Core::GetInst()->GetResolution().y / 2 })));
		windowObj[i]->SetScale(Vec2(300.f, 400.f));
		//pObj->SetTag(TAG::PLYAER);
		SceneMgr::GetInst()->GetCurScene()->AddObject(windowObj[i], OBJECT_GROUP::UI);
	}
	isOpen = true;
	TimeMgr::GetInst()->Pause(true);
}

void LevelMgr::UpgradePanelDown()
{
	TimeMgr::GetInst()->Pause(false);
	isOpen = false;
	maxExperience = 1 + level * level;
	gaugeBar->Reset(maxExperience);
	for (int i = 0; i < 3; i++)
	{
		MonsterMgr::GetInst()->UpgradeSpawn();
		EventMgr::GetInst()->DeleteObject(windowObj[i]);
	}
}

void LevelMgr::OnUpgradeBtnClick(int index)
{
	UpgradeWeapon(index);
	UpgradePanelDown();
}

void LevelMgr::UpgradeWeapon(int index)
{
	windowObj[index]->UpgradeWeapon();
}