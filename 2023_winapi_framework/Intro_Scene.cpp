#include "pch.h"
#include "Intro_Scene.h"
#include "Core.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "SceneMgr.h"
void Intro_Scene::Init()
{
	//폰트 세팅
	ResMgr::GetInst()->LoadFont(L"TitleFont", L"Font\\MainFont.ttf", 60);
	ResMgr::GetInst()->LoadFont(L"SubFont", L"Font\\MainFont.ttf", 20);

	// 사운드 세팅
	/*ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	ResMgr::GetInst()->LoadSound(L"Shoot", L"Sound\\laserShoot.wav", false);
	ResMgr::GetInst()->Play(L"BGM");*/
}

void Intro_Scene::Update()
{
	Scene::Update();

	if (KEY_DOWN(KEY_TYPE::ENTER))
	{
		SceneMgr::GetInst()->LoadScene(L"Start_Scene");
		//SceneMgr::GetInst()->LoadScene(L"Game_Scene");
	}
}

void Intro_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);

	SetTextAlign(_dc, TA_CENTER);
	SelectObject(_dc, ResMgr::GetInst()->GetFont(L"TitleFont"));
	TextOut(_dc, 600, 200, L"TrainSurvivors", 14);
	SelectObject(_dc, ResMgr::GetInst()->GetFont(L"SubFont"));
	TextOut(_dc, 600, 300, L"Press Enter", 11);
}

void Intro_Scene::Release()
{
	Scene::Release();
}
