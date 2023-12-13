#pragma once
#include "define.h"
#include "pch.h"
#include <windows.h>

class UpgradeWindow;
class LevelMgr
{
	SINGLE(LevelMgr);
private:
	INPUT_RECORD rec;
private://변수
	bool isOpen;
	int level;
	int experience;
	int currentExperience;
	UpgradeWindow* windowObj[3];
public://함수
	//Update
	void Update();
	//패널 띄우기
	void UpgradePanelUp(Weapon* playerWeapons[]);
	void UpgradePanelDown();
	//버튼 클릭시
	void OnUpgradeBtnClick(int index);
	//랜덤한 무기 선택
	void RandomWeapon();
	//무기 업그레이드
	void UpgradeWeapon();
private://get,set, 반환함수, 기타함수 등등
	const bool GetOpen() const { return isOpen; }
	const int GetLevel() const { return level; }
	const int Experience() const { return experience; }
};