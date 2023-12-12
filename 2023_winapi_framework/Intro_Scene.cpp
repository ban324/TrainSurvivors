#include "pch.h"
#include "Intro_Scene.h"
#include "Introbackground.h"
#include "Core.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "SceneMgr.h"
#include "Texture.h"

void Intro_Scene::Init()
{
	Introbackground* pObj = new Introbackground(ResMgr::GetInst()->TexLoad(L"IntroBackground", L"Texture\\Background.bmp"));
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - 1000, Core::GetInst()->GetResolution().y / 2 - 400 })));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, OBJECT_GROUP::BACKGROUND);

	//폰트 세팅
	ResMgr::GetInst()->LoadFont(L"TitleFont", L"Font\\MainFont.ttf", 70);
	ResMgr::GetInst()->LoadFont(L"SubFont", L"Font\\MainFont.ttf", 30);

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
	SetBkMode(_dc, 0);
	SelectObject(_dc, ResMgr::GetInst()->GetFont(L"TitleFont"));
	TextOut(_dc, 750, 200, L"TrainSurvivors", 14);
	SelectObject(_dc, ResMgr::GetInst()->GetFont(L"SubFont"));
	TextOut(_dc, 750, 400, L"Press Enter", 11);
}

void Intro_Scene::Release()
{
	Scene::Release();
}
