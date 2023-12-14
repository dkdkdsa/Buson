#include "pch.h"
#include "BagUI.h"
#include "Core.h"
#include "PokemonSelectBtn.h"
#include "DeckManager.h"
BagUI::BagUI() : BattleUI(L"BattleSceneBackground.bpm", L"Texture\\Battle\\BattleSceneBackground.bpm", { 0, 0 }, { 1280, 720 })
{
	m_strName = L"BagUI";
	auto screenPoint = Core::GetInst()->GetResolution();

	
}

BagUI::~BagUI()
{
}

void BagUI::Update()
{
}
