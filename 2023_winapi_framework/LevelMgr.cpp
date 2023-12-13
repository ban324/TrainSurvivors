#include "pch.h"
#include "TimeMgr.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "LevelMgr.h"
#include "KeyMgr.h"
#include "UpgradeWindow.h"
#include "Core.h"

void LevelMgr::UpgradePanelUp()
{
	windowObj1 = new UpgradeWindow;
	windowObj1->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	windowObj1->SetScale(Vec2(300.f, 400.f));
	//pObj->SetTag(TAG::PLYAER);
	SceneMgr::GetInst()->GetCurScene()->AddObject(windowObj1, OBJECT_GROUP::UI);

	if (windowObj1->IsRange(KeyMgr::GetInst()->GetMousePos()))
	{

	}
}

void LevelMgr::UpgradePanelDown()
{

}

void LevelMgr::OnUpgradeBtnClick()
{

}

void LevelMgr::RandomWeapon()
{

}

void LevelMgr::UpgradeWeapon()
{

}