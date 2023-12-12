#include "pch.h"
#include "IntroScene.h"
#include "Core.h"

void IntroScene::Init()
{

	Core::GetInst()->ResizeWindow(720, 680);

}

void IntroScene::Update()
{

	Scene::Update();

}

void IntroScene::Render(HDC _dc)
{

	Scene::Render(_dc);

}

void IntroScene::Release()
{

	Scene::Release();

}
