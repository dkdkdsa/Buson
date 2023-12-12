#include "pch.h"
#include "Battle_PokemonBtn.h"
#include "BattleUIMgr.h"

Battle_PokemonBtn::Battle_PokemonBtn() : UIButton(L"Battle_PokemonBtn.bpm", L"Texture\\Battle\\Button\\Battle_PokemonBtn.bpm", { 0, 0 }, { 300, 75 })
{
}

Battle_PokemonBtn::~Battle_PokemonBtn()
{
}

void Battle_PokemonBtn::OnClick()
{
	BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::PokemonSelect);
}
