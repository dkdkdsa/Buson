#include "pch.h"
#include "PokemonSelectUI.h"
#include "PokemonManager.h"
#include "Core.h"
#include "PokemonSelectBtn.h"
#include "PokemonSelectCancelBtn.h"
#include "DeckManager.h"
PokemonSelectUI::PokemonSelectUI() : BattleUI(L"PokemonSelectMenu.bmp", L"Texture\\Battle\\Pokemon_Select\\PokemonSelectMenu.bmp", { 256, 1209 }, { 512, 406 })
{
	m_strName = L"PokemonSelectUI";
	auto screenPoint = Core::GetInst()->GetResolution();

	for (int i = 0; i < DeckManager::GetInst()->GetPokemon().size(); ++i) {
		_pokemonBtns.push_back(new PokemonSelectBtn());
		static_cast<PokemonSelectBtn*>(_pokemonBtns[i])->PokemonTexInit(i + 1);
		SetBtnVec(_pokemonBtns[i]);
	}

	SetBtnVec(new PokemonSelectCancelBtn());

	//for (int i = 0; i < ���� �÷��̾� ��Ƽ ���ϸ� ��; ++i) {
	// _buttons.push_back(new PokemonSelectUI());
	//}
	//�̰� ���߿� ����̰� ����� �߰�
}

PokemonSelectUI::~PokemonSelectUI()
{
}

void PokemonSelectUI::Update()
{
	for (int i = 0; i < GetBtnVec().size(); ++i) {
		GetBtnVec()[i]->Update();
	}
	Object::Update();
}
