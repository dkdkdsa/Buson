#include "pch.h"
#include "ActionSelectUI.h"
#include "BattleScene.h"
#include "FightBtn.h"
#include "BagBtn.h"
#include "RunBtn.h"
#include "Battle_PokemonBtn.h"

ActionSelectUI::ActionSelectUI() : BattleUI(L"BattleSceneBackground.bpm", L"Texture\\Battle\\BattleSceneBackground.bpm", { 0, 0 }, { 1280, 720 })
{
	SetEnable(false);
	_buttons.push_back(new FightBtn());
	_buttons.push_back(new BagBtn());
	_buttons.push_back(new RunBtn());
	_buttons.push_back(new Battle_PokemonBtn());
}

ActionSelectUI::~ActionSelectUI()
{

}
