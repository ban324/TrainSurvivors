#pragma once
#include "define.h"
#include "pch.h"

class LevelMgr
{
	SINGLE(LevelMgr);
private://변수
	int level;
	int experience;
	int currentExperience;
public://함수
	//패널 띄우기
	void UpgradePanelUp();
	void UpgradePanelDown();
	//버튼 클릭시
	void OnUpgradeBtnClick();
	//랜덤한 무기 선택
	void RandomWeapon();
	//무기 업그레이드
	void UpgradeWeapon();
private://get,set, 반환함수, 기타함수 등등
	const int GetLevel() const { return level; }
	const int Experience() const { return experience; }
};