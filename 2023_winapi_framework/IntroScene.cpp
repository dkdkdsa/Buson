#include "pch.h"
#include "IntroScene.h"
#include "Core.h"
#include "ResMgr.h"
#include "Texture.h"
#include "GameStartBtn.h"
#include "GameExitBtn.h"

void IntroScene::Init()
{

	Core::GetInst()->ResizeWindow(720, 680);

	bg = ResMgr::GetInst()->TexLoad(L"IntroBG", L"Texture\\Intro\\IntroBG.bmp");
	buson = ResMgr::GetInst()->TexLoad(L"BS", L"Texture\\Intro\\아름다우신 부성이의 물따르는모습.bmp");

	auto* gsB = new GameStartBtn(Vec2({ 720 / 2 }, 680 / 2 + 100), Vec2({ 72 * 4, 24 * 4 }));
	AddObject(gsB, OBJECT_GROUP::DEFAULT);

	auto* exB = new GameExitBtn(Vec2({ 720 / 2 }, 680 / 2 + 230), Vec2({ 72 * 4, 24 * 4 }));
	AddObject(exB, OBJECT_GROUP::DEFAULT);

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
		720,
		680,
		bg->GetDC(),
		0,
		0,
		bg->GetWidth(),
		bg->GetHeight(),
		RGB(255, 0, 255)

	);


	TransparentBlt(

		_dc,
		720 / 2 - 273 / 2 - 30,
		328 / 2 - 60,
		273,
		328,
		buson->GetDC(),
		0,
		0,
		buson->GetWidth(),
		buson->GetHeight(),
		RGB(255, 0, 255)

	);

	Scene::Render(_dc);
}

void IntroScene::Release()
{

	Scene::Release();

}
