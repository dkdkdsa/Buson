#include "pch.h"
#include "SceneMgr.h"
#include "Start_Scene.h"
#include "Game_Scene.h"
#include "FieldScene.h"
#include "BattleScene.h"
#include "IntroScene.h"

void SceneMgr::Init()
{

	m_pCurScene = nullptr;
	// ¾À µî·Ï
	RegisterScene(L"Start_Scene",std::make_shared<Start_Scene>());
	RegisterScene(L"Game_Scene", std::make_shared<Game_Scene>());
	RegisterScene(L"Field_Scene", std::make_shared<FieldScene>());
	RegisterScene(L"Battle_Scene", std::make_shared<BattleScene>());
	RegisterScene(L"Intro_Scene", std::make_shared<IntroScene>());

	// Ã¹ ¾À ÁöÁ¤
	LoadScene(L"Field_Scene");

}

void SceneMgr::Update()
{
	m_pCurScene->Update();
	m_pCurScene->FinalUpdate();
}

void SceneMgr::Render(HDC _dc)
{
	m_pCurScene->Render(_dc);
}

void SceneMgr::LoadScene(const wstring& _scenename)
{

	wstring name = _scenename;

	// ¾ÀÀÌ ÀÖÀ¸¸é
	if (m_pCurScene != nullptr)
	{
		m_pCurScene->Release();
		m_pCurScene = nullptr;
	}

	auto iter = m_mapScenes.find(name);

	if (iter != m_mapScenes.end())
	{
		m_pCurScene = iter->second;
		m_pCurScene->Init();
	}
}

void SceneMgr::RegisterScene(const wstring& _scenename, std::shared_ptr<Scene> _scene)
{
	m_mapScenes.insert(m_mapScenes.end(), {_scenename, _scene});
}
