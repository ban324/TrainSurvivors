#pragma once
#include "define.h"
#include "pch.h"
#include "weapon.h"
#include "GaugeBar.h"

class UpgradeWindow;
class LevelMgr
{
	SINGLE(LevelMgr);
private://변수
	bool isRun;
	bool isOpen;
	int level;
	int maxExperience;
	int currentExperience;
	vector<int> levelEx;
	GaugeBar* gaugeBar;
	UpgradeWindow* windowObj[3];
	vector<Weapon*> playerWeapons;
public://함수
	void Update();
	void Render(HDC _dc);
	//미리 플레이어 무기 가져오고
	void SettingWeapons(vector<Weapon*>& weapons);
	//경험치 증가
	void IncreseExperience(int ex);
	//패널 띄우기
	void UpgradePanelUp();
	void UpgradePanelDown();
	//버튼 클릭시
	void OnUpgradeBtnClick(int index);
	//무기 업그레이드
	void UpgradeWeapon(int index);
private://get,set, 반환함수, 기타함수 등등
	const bool GetOpen() const { return isOpen; }
	const int GetLevel() const { return level; }
	const int Experience() const { return maxExperience; }
};