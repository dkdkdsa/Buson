#include "pch.h"
#include "IntroScene.h"
#include "Core.h"
#include "ResMgr.h"
#include "Texture.h"
#include "GameStartBtn.h"
#include "GameExitBtn.h"

void IntroScene::Init()
{

	Core::GetInst()->ResizeWindow(800, 680);

	bg = ResMgr::GetInst()->TexLoad(L"IntroBG", L"Texture\\Intro\\IntroBG.bmp");


	ResMgr::GetInst()->LoadSound(L"Field", L"Sound\\Field.mp3", true);

	auto* gsB = new GameStartBtn(Vec2({ 800 / 2 }, 680 / 2 + 100), Vec2({ 72 * 6, 30 * 4 }));
	AddObject(gsB, OBJECT_GROUP::DEFAULT);

	auto* exB = new GameExitBtn(Vec2({ 800 / 2 }, 680 / 2 + 230), Vec2({ 72 * 6, 30 * 4 }));
	AddObject(exB, OBJECT_GROUP::DEFAULT);

	ResMgr::GetInst()->Play(L"Field");

}

void IntroScene::Update()
{

	Scene::Update();

}

void IntroScene::Render(HDC _dc)
{


	TransparentBlt(

		_dc,
		0,
		0,
		800,
		680,
		bg->GetDC(),
		0,
		0,
		bg->GetWidth(),
		bg->GetHeight(),
		RGB(255, 0, 255)

	);

	Scene::Render(_dc);
}

void IntroScene::Release()
{

	Scene::Release();

}
