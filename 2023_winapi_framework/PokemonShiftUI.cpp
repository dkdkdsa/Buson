#include "pch.h"
#include "PokemonShiftUI.h"
#include "Pokemon.h"
#include "PokemonShiftBtn.h"
#include "PokemonShiftCancelBtn.h"
PokemonShiftUI::PokemonShiftUI() : BattleUI(L"PokemonShiftBg.bmp", L"Texture\\Battle\\Pokemon_Select\\PokemonShiftBg.bmp", { 256, 1209 }, { 512, 406 })
{
	m_strName = L"PokemonShiftUI";

	_btns.push_back(new PokemonShiftBtn());
	_btns.push_back(new PokemonShiftCancelBtn());
	for (int i = 0; i < _btns.size(); ++i) {
		SetBtnVec(_btns[i]);
	}
}

PokemonShiftUI::~PokemonShiftUI()
{
}

void PokemonShiftUI::Init()
{
	
}

void PokemonShiftUI::Update()
{
	for (int i = 0; i < GetBtnVec().size(); ++i) {
		GetBtnVec()[i]->Update();
	}
	Object::Update();
}
