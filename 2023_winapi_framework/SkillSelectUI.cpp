#include "pch.h"
#include "SkillSelectUI.h"
#include "Battle_CancelBtn.h"
#include "SkillSelectBtn.h"
#include "Core.h"
#include "DeckManager.h"
#include "SceneMgr.h"
#include "BattleScene.h"

SkillSelectUI::SkillSelectUI() : BattleUI(L"BattleSceneBackground.bmp", L"Texture\\Battle\\BattleSceneBackground.bmp", { 256, 1209 }, { 512, 406 })
{
	m_strName = L"SkillSelectUI";
	auto screenPoint = Core::GetInst()->GetResolution();

	for (int i = 0; i < 4; ++i) {
		_skillBtns.push_back(new SkillSelectBtn());
		_skillBtns[i]->InitSkill(std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())->GetCurPokemon().SkillsKey[i]);
		_skillBtns[i]->PosInit((BtnPos)i);
		SetBtnVec(_skillBtns[i]);
	}

	SetBtnVec(new Battle_CancelBtn());
	
}

SkillSelectUI::~SkillSelectUI()
{
}

void SkillSelectUI::Init()
{
	for (int i = 0; i < 4; ++i) {
		_skillBtns[i]->InitSkill(std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())->GetCurPokemon().SkillsKey[i]);
	}
}

void SkillSelectUI::Update()
{
	for (int i = 0; i < GetBtnVec().size(); ++i) {
		GetBtnVec()[i]->Update();
	}
	Object::Update();
}
