#pragma once
#include "define.h"
#include "pch.h"
#include "weapon.h"
#include "GaugeBar.h"

class UpgradeWindow;
class LevelMgr
{
	SINGLE(LevelMgr);
private://����
	bool isRun;
	bool isOpen;
	int level;
	int maxExperience;
	int currentExperience;
	vector<int> levelEx;
	GaugeBar* gaugeBar;
	UpgradeWindow* windowObj[3];
	vector<Weapon*> playerWeapons;
public://�Լ�
	void Update();
	void Render(HDC _dc);
	//�̸� �÷��̾� ���� ��������
	void SettingWeapons(vector<Weapon*>& weapons);
	//����ġ ����
	void IncreseExperience(int ex);
	//�г� ����
	void UpgradePanelUp();
	void UpgradePanelDown();
	//��ư Ŭ����
	void OnUpgradeBtnClick(int index);
	//���� ���׷��̵�
	void UpgradeWeapon(int index);
private://get,set, ��ȯ�Լ�, ��Ÿ�Լ� ���
	const bool GetOpen() const { return isOpen; }
	const int GetLevel() const { return level; }
	const int Experience() const { return maxExperience; }
};