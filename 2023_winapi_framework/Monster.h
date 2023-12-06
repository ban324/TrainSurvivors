#pragma once
#include "Object.h"
#include "Player.h"
class Texture;
class Monster : public Object
{
public:
	Monster();
	~Monster();
public:
	void Update() override;
	void Render(HDC _dc) override;
	void SpriteFlip();
	virtual void EnterCollision(Collider* _pOther) override;
	virtual void ExitCollision(Collider* _pOther)  override;
	virtual void StayCollision(Collider* _pOther)  override;

public:
	void SetPlayerObj(Player* pObj);
	void SetSpeed(float _f) { m_fSpeed = _f; }
	void SetStat(float _hp, float _attack) { m_iHp = _hp; m_attack = _attack; }
	void SetCenterPos(Vec2 _vPos) 
	{ 
		m_vCenterPos = _vPos;
	}
	void SetMoveDis(float _f) { m_fMaxDis = _f; }
	const float& GetSpeed() const { return m_fSpeed; }
private:
	Player* playerObj;
	float m_fSpeed; // ���� ���ǵ�
	float m_attack;
	Vec2 m_vCenterPos; // �߽� ��ġ
	float m_fMaxDis; // �̵��� �� �ִ� �ִ� �Ÿ�
	float m_fDirX; // ����(-1: ����, 1: ������)
	float m_fDirY; // ����(-1: ����, 1: ������)
	int   m_iHp; // ü��
	Texture* m_pTex;
};

