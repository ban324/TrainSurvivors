#include "pch.h"
#include "Intro_Scene.h"
#include "Core.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "SceneMgr.h"
void Intro_Scene::Init()
{
	HDC mainDC = Core::GetInst()->GetMainDC();
	TextOut(mainDC, 500, 100, L"TrainSurvivors", 14);
	TextOut(mainDC, 500, 100, L"Press Enter", 11);

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
}

void Intro_Scene::Release()
{
	Scene::Release();
}
