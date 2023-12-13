#include "pch.h"
#include "PokemonSelectUI.h"
#include "PokemonManager.h"
#include "Core.h"
#include "PokemonSelectBtn.h"
#include "PokemonSelectCancelBtn.h"
PokemonSelectUI::PokemonSelectUI() : BattleUI(L"BattleSceneBackground.bpm", L"Texture\\Battle\\Pokemon_Select\\SelectMenuBackground.bmp", { 256, 1209 }, { 512, 406 })
{
	m_strName = L"PokemonSelectUI";
	auto screenPoint = Core::GetInst()->GetResolution();
	SetEnable(false);

	for (int i = 0; i < 6; ++i) {
		_pokemonBtns.push_back(new PokemonSelectBtn());
		SetBtnVec(_pokemonBtns[i]);
	}

	SetBtnVec(new PokemonSelectCancelBtn());

	//for (int i = 0; i < 현재 플레이어 파티 포켓몬 수; ++i) {
	// _buttons.push_back(new PokemonSelectUI());
	//}
	//이건 나중에 대원이가 만들면 추가
}

PokemonSelectUI::~PokemonSelectUI()
{
}

void PokemonSelectUI::Update()
{
}
