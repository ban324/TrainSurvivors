#include "pch.h"
#include "TimeMgr.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "LevelMgr.h"
#include "KeyMgr.h"
#include "UpgradeWindow.h"
#include "Core.h"
#include "EventMgr.h"

void LevelMgr::UpgradePanelUp(Weapon* playerWeapons[])
{
	isOpen = true;

	std::set<int> benIndex;
	for (int i = 0; i < 3; i++)
	{
		int weaponIndex = rand() % sizeof(playerWeapons);
		while (benIndex.find(weaponIndex) != benIndex.end())
		{
			weaponIndex = rand() % sizeof(playerWeapons);
		}
		benIndex.insert(weaponIndex);

		windowObj[i] = new UpgradeWindow(playerWeapons[weaponIndex]);
		windowObj[i]->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - (i * 500) + 300, Core::GetInst()->GetResolution().y / 2 })));
		windowObj[i]->SetScale(Vec2(300.f, 400.f));
		//pObj->SetTag(TAG::PLYAER);
		SceneMgr::GetInst()->GetCurScene()->AddObject(windowObj[i], OBJECT_GROUP::UI);
	}
}

void LevelMgr::Update()
{
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
	windowObj[index]->UpgradeWeapon();
	UpgradePanelDown();
}

void LevelMgr::RandomWeapon()
{

}

void LevelMgr::UpgradeWeapon()
{

}