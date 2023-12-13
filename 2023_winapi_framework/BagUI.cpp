#include "pch.h"
#include "BagUI.h"
#include "Core.h"
#include "PokemonSelectBtn.h"
BagUI::BagUI() : BattleUI(L"BattleSceneBackground.bpm", L"Texture\\Battle\\BattleSceneBackground.bpm", { 0, 0 }, { 1280, 720 })
{
	m_strName = L"BagUI";
	auto screenPoint = Core::GetInst()->GetResolution();

	for (int i = 0; i < _pokemonBtns.size(); ++i) {
		SetBtnVec(_pokemonBtns[i]);
	}
}

BagUI::~BagUI()
{
}

void BagUI::Update()
{
}
