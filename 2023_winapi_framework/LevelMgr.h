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
private://����
	bool isOpen;
	int level;
	int experience;
	int currentExperience;
	UpgradeWindow* windowObj[3];
public://�Լ�
	//Update
	void Update();
	//�г� ����
	void UpgradePanelUp(Weapon* playerWeapons[]);
	void UpgradePanelDown();
	//��ư Ŭ����
	void OnUpgradeBtnClick(int index);
	//������ ���� ����
	void RandomWeapon();
	//���� ���׷��̵�
	void UpgradeWeapon();
private://get,set, ��ȯ�Լ�, ��Ÿ�Լ� ���
	const bool GetOpen() const { return isOpen; }
	const int GetLevel() const { return level; }
	const int Experience() const { return experience; }
};