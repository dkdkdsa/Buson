#include "pch.h"
#include "PokemonSelectUI.h"
#include "PokemonManager.h"
#include "Core.h"
#include "PokemonSelectBtn.h"
#include "PokemonSelectCancelBtn.h"
#include "DeckManager.h"
#include "pokemon.h"
#include "BattleMgr.h"
PokemonSelectUI::PokemonSelectUI() : BattleUI(L"PokemonSelectMenu.bmp", L"Texture\\Battle\\Pokemon_Select\\PokemonSelectMenu.bmp", { 256, 1209 }, { 512, 406 })
{
	//_pokemons = pokemons;
	m_strName = L"PokemonSelectUI";
	auto screenPoint = Core::GetInst()->GetResolution();

	
	_pokemons = BattleMgr::GetInst()->GetPokemons();
	for (int i = 0; i < _pokemons.size(); ++i) {
		_pokemonBtns.push_back(new PokemonSelectBtn());
		static_cast<PokemonSelectBtn*>(_pokemonBtns[i])->PokemonSetting(i + 1, _pokemons[i]);
		static_cast<PokemonSelectBtn*>(_pokemonBtns[i])->PokemonTexInit();
		SetBtnVec(_pokemonBtns[i]);
	}

	SetBtnVec(new PokemonSelectCancelBtn());
	
}

PokemonSelectUI::~PokemonSelectUI()
{
}

void PokemonSelectUI::Init()
{
	
}

void PokemonSelectUI::Update()
{
	for (int i = 0; i < GetBtnVec().size(); ++i) {
		GetBtnVec()[i]->Update();
	}
	Object::Update();
}
