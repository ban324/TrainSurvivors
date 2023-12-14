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
	virtual void SpriteFlip();
	virtual void EnterCollision(Collider* _pOther) override;
	virtual void ExitCollision(Collider* _pOther)  override;
	virtual void StayCollision(Collider* _pOther)  override;

public:
	void SetPlayerObj(Player* pObj);
	void SetSpeed(float _f) { m_fSpeed = _f; }
	void SetStat(float _hp, float _attack, float _ex) {
		m_iHp = _hp; m_fAttack = _attack; m_fEx = _ex;
	}
	void SetCenterPos(Vec2 _vPos) 
	{ 
		m_vCenterPos = _vPos;
	}
	void SetMoveDis(float _f) { m_fMaxDis = _f; }
	const float& GetSpeed() const { return m_fSpeed; }
	MONSTER_KIND* GetKind() const { return kind; }
	void SetKind(MONSTER_KIND val) {
		kind = new MONSTER_KIND;
		*kind = val;
	};
protected:
	MONSTER_KIND* kind;
	Player* playerObj;
	float m_fSpeed; // ���� ���ǵ�
	float m_fAttack;
	float m_fDelay;
	Vec2 m_vCenterPos; // �߽� ��ġ
	float m_fMaxDis; // �̵��� �� �ִ� �ִ� �Ÿ�
	float m_fDirX; // ����(-1: ����, 1: ������)
	float m_fDirY; // ����(-1: ����, 1: ������)
	int   m_iHp; // ü��
	int	  m_fEx;
	int	  time;
	Texture* m_pTex;
};

