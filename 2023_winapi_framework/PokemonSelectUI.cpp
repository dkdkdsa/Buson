#include "pch.h"
#include "PokemonSelectUI.h"
#include "PokemonManager.h"

PokemonSelectUI::PokemonSelectUI() : BattleUI(L"BattleSceneBackground.bpm", L"Texture\\Battle\\BattleSceneBackground.bpm", { 0, 0 }, { 1280, 720 })
{
	SetEnable(false);
	//for (int i = 0; i < ���� �÷��̾� ��Ƽ ���ϸ� ��; ++i) {
	// _buttons.push_back(new PokemonSelectUI());
	//}
	//�̰� ���߿� ����̰� ����� �߰�
}

PokemonSelectUI::~PokemonSelectUI()
{
}