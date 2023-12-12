#include "pch.h"
#include "ActionSelectUI.h"
#include "BattleScene.h"
#include "FightBtn.h"
#include "BagBtn.h"
#include "RunBtn.h"
#include "Battle_PokemonBtn.h"
#include "Core.h"
ActionSelectUI::ActionSelectUI() : BattleUI(L"BattleSceneBackground.bmp", L"Texture\\Battle\\BattleSceneBackground.bmp", { 256, 1209 }, { 512, 406 })
{
	SetEnable(true);
	_buttons.push_back(new FightBtn());
	_buttons.push_back(new BagBtn());
	_buttons.push_back(new RunBtn());
	_buttons.push_back(new Battle_PokemonBtn());
}

ActionSelectUI::~ActionSelectUI()
{

}
