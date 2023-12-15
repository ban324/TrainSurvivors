#include "pch.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Weapon.h"
#include "Scene.h"
#include "Texture.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include"MachineGun.h"
#include "Animation.h"
#include "Turret.h"
#include "MonsterMgr.h"
#include "Cactus.h"
#include "BurnWheel.h"
Player::Player()
	: m_pTex(nullptr),
	speed(100.f),
	power(1.f),
	duration(1.f),
	bulletSize(1.f),
	coolTimePercent(1.f),
	maxHP(10),
	currentHP(maxHP)
{
	dir = Vec2(1, 0);
	//m_pTex = new Texture;
	//wstring strFilePath = PathMgr::GetInst()->GetResPath();
	//strFilePath += L"Texture\\plane.bmp";
	//m_pTex->Load(strFilePath);
	CreateAnimator();
	m_pTex = ResMgr::GetInst()->TexLoad(L"L_Player", L"Texture\\Train_Left.bmp");
	GetAnimator()->CreateAnim(L"Train_Left", m_pTex, Vec2(0.f, 0.f),
		Vec2(128.f, 128.f), Vec2(128.f, 0.f), 8, 0.05f);
	m_pTex = ResMgr::GetInst()->TexLoad(L"R_Player", L"Texture\\Train_Right.bmp");
	isRight = true;
	GetAnimator()->CreateAnim(L"Train_Right", m_pTex, Vec2(0.f, 0.f),
		Vec2(128.f, 128.f), Vec2(128.f, 0.f), 8, 0.05f);
	//m_pTex = ResMgr::GetInst()->TexLoad(L"jiwoo", L"Texture\\jiwoo.bmp");
	CreateCollider();
	GetCollider()->SetScale(Vec2(60.f,60.f));
	//GetCollider()->SetOffSetPos(Vec2(50.f,0.f));
	GetAnimator()->PlayAnim(L"Train_Right", true);
	//// ������ �ǵ帮��
	//Animation* pAnim = GetAnimator()->FindAnim(L"Jiwoo_Front");
	//// �ϳ���
	//pAnim->SetFrameOffset(0, Vec2(0.f, 20.f));
	
	//// ������ �� 
	//for (size_t i = 0; i < pAnim->GetMaxFrame(); ++i)
	//	pAnim->SetFrameOffset(i, Vec2(0.f, 20.f));

	BurnWheel* mcg = new BurnWheel();
	if (mcg)
	{
		mcg->bulletSize = 30.f;
		mcg->cooltime = 1.f;
		mcg->duration = 10.f;
		mcg->SetSpeed(10.f);
		mcg->projectileCnt = 1;
		mcg->power = 5.f;
		mcg->SetPos(GetPos());;
		mcg->owner = this;
		weapons.push_back(mcg);
	}
}
Player::~Player()
{
	//if (nullptr != m_pTex)
	//	delete m_pTex;
}
void Player::Update()
{

	if (KEY_PRESS(KEY_TYPE::LEFT))
	{
		dir.x = -1;
		GetAnimator()->PlayAnim(L"Train_Left", true);
	}
	if (KEY_PRESS(KEY_TYPE::RIGHT))
	{
		dir.x = 1;
		GetAnimator()->PlayAnim(L"Train_Right", true);
	}
	for (auto iter = weapons.begin(); iter != weapons.end(); ++iter)
	{
		(*iter)->Update();
	}
	Vec2 vPos = GetPos();
	vPos.x += dir.x * 100 * fDT;	
	SetPos(vPos);
	GetAnimator()->Update();
	
	if (currentHP <= 0)
	{
		MonsterMgr::GetInst()->StopSpawnMonster();
		SceneMgr::GetInst()->LoadScene(L"Gameover_Scene");
	}
}

void Player::CreateBullet()
{
	Bullet* pBullet = new Bullet;
	Vec2 vBulletPos = GetPos();
	vBulletPos.y -= GetScale().y / 2.f;
	pBullet->SetPos(vBulletPos);
	pBullet->SetScale(Vec2(25.f,25.f));
//	pBullet->SetDir(M_PI / 4 * 7);
//	pBullet->SetDir(120* M_PI / 180);
	pBullet->SetDir(Vec2(-10.f,-15.f));
	pBullet->SetName(L"Player_Bullet");
	SceneMgr::GetInst()->GetCurScene()->AddObject(pBullet, OBJECT_GROUP::BULLET);
}

void Player::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();
	//// 1. �⺻ �ű��
	//BitBlt(_dc
	//	,(int)(vPos.x - vScale.x /2)
	//	,(int)(vPos.y - vScale.y /2)
	//	, Width,Height, m_pTex->GetDC()
	//	,0,0,SRCCOPY);

	//// 2. ���� �Ⱦ��
	//TransparentBlt(_dc
	//	, (int)(vPos.x - vScale.x / 2)
	//	, (int)(vPos.y - vScale.y / 2)
	//	, Width, Height, m_pTex->GetDC()
	//	, 0, 0, Width,Height, RGB(255,0,255));

	//// 3. Ȯ�� �� ���
	//StretchBlt(_dc
	//	, (int)(vPos.x - vScale.x / 2)
	//	, (int)(vPos.y - vScale.y / 2)
	//	, Width ,Height, m_pTex->GetDC()
	//	, 0, 0, Width, Height, SRCCOPY);

	// 4. ȸ��
	// �ﰢ�Լ�, ȸ�����
	//Plgblt(_dc
	//	, (int)(vPos.x - vScale.x / 2)
	//	, (int)(vPos.y - vScale.y / 2)
	//	, Width, Height, m_pTex->GetDC()
	//	, 0, 0, Width, Height, RGB(255, 0, 255));
	Component_Render(_dc);
	for (auto iter = weapons.begin(); iter != weapons.end(); ++iter)
	{
		(*iter)->Render(_dc);
	}

}
