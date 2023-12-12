#pragma once
#include "define.h"
#include "pch.h"

class LevelMgr
{
	SINGLE(LevelMgr);
private://����
	int level;
	int experience;
	int currentExperience;
public://�Լ�
	//�г� ����
	void UpgradePanelUp();
	void UpgradePanelDown();
	//��ư Ŭ����
	void OnUpgradeBtnClick();
	//������ ���� ����
	void RandomWeapon();
	//���� ���׷��̵�
	void UpgradeWeapon();
private://get,set, ��ȯ�Լ�, ��Ÿ�Լ� ���
	const int GetLevel() const { return level; }
	const int Experience() const { return experience; }
};