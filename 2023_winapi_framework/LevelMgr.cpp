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
	else//°æÇèÄ¡ ½×±â
	{
		if (gaugeBar->currentExperience > maxExperience)
		{
			level++;
			gaugeBar->Reset();
			maxExperience = levelEx[level];
			UpgradePanelUp();
		}
	}
}

void LevelMgr::SettingWeapons(Weapon* weapons[])
{
	isRun = true;

	gaugeBar = new GaugeBar;
	gaugeBar->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	gaugeBar->SetScale(Vec2(100.f, 100.f));
	//gaugeBar->SetTag(TAG::PLYAER);
	SceneMgr::GetInst()->GetCurScene()->AddObject(gaugeBar, OBJECT_GROUP::UI);

	levelEx.push_back(100);
	levelEx.push_back(110);
	levelEx.push_back(120);
	levelEx.push_back(130);

	level = 0;
	gaugeBar->Reset();
	maxExperience = levelEx[level];

	for (int i = 0; i < sizeof(weapons); i++)
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
	isOpen = true;
	level++;

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
		windowObj[i]->ShowText();
		//pObj->SetTag(TAG::PLYAER);
		SceneMgr::GetInst()->GetCurScene()->AddObject(windowObj[i], OBJECT_GROUP::UI);
	}
}

void LevelMgr::UpgradePanelDown()
{
	isOpen = false;
	for (int i = 0; i < 3; i++)
	{
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