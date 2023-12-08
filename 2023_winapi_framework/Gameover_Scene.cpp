#include "pch.h"
#include "Gameover_Scene.h"
#include "Object.h"
#include "Core.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "Introbackground.h"
#include "SceneMgr.h"

void Gameover_Scene::Init()
{
	Introbackground* pObj = new Introbackground(ResMgr::GetInst()->TexLoad(L"BlackBackground", L"Texture\\BlackBackground.bmp"));
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - 1000, Core::GetInst()->GetResolution().y / 2 - 400 })));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, OBJECT_GROUP::BACKGROUND);

	//폰트 세팅
	ResMgr::GetInst()->LoadFont(L"TitleFont", L"Font\\MainFont.ttf", 70);
	ResMgr::GetInst()->LoadFont(L"SubFont", L"Font\\MainFont.ttf", 30);

	// 사운드 세팅
	ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	ResMgr::GetInst()->LoadSound(L"Shoot", L"Sound\\laserShoot.wav", false);
	ResMgr::GetInst()->Play(L"BGM");
}

void Gameover_Scene::Update()
{
	Scene::Update();

	if (KEY_DOWN(KEY_TYPE::ENTER))
	{
		SceneMgr::GetInst()->LoadScene(L"Start_Scene");
	}
}

void Gameover_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);

	SetTextAlign(_dc, TA_CENTER);
	SetBkMode(_dc, 0);
	SetTextColor(_dc, RGB(255, 0, 0));
	SelectObject(_dc, ResMgr::GetInst()->GetFont(L"TitleFont"));
	TextOut(_dc, 750, 200, L"GAMEOVER", 8);
	SetTextColor(_dc, RGB(255, 255, 255));
	SelectObject(_dc, ResMgr::GetInst()->GetFont(L"SubFont"));
	TextOut(_dc, 750, 400, L"Press Enter to Restart", 22);
}

void Gameover_Scene::Release()
{
	Scene::Release();
}
