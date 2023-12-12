#include "pch.h"
#include "PokemonSelectUI.h"
#include "PokemonManager.h"

PokemonSelectUI::PokemonSelectUI() : BattleUI(L"BattleSceneBackground.bpm", L"Texture\\Battle\\BattleSceneBackground.bpm", { 0, 0 }, { 1280, 720 })
{
	SetEnable(false);
	//for (int i = 0; i < 현재 플레이어 파티 포켓몬 수; ++i) {
	// _buttons.push_back(new PokemonSelectUI());
	//}
	//이건 나중에 대원이가 만들면 추가
}

PokemonSelectUI::~PokemonSelectUI()
{
}