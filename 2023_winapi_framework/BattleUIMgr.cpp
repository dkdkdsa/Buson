#include "pch.h"
#include "BattleUIMgr.h"
#include "ActionSelectUI.h"
#include "SkillSelectUI.h"
#include "PokemonSelectUI.h"

void BattleUIMgr::Init()
{
	_battleUIContainer.push_back(new ActionSelectUI());
	_battleUIContainer.push_back(new SkillSelectUI());
	_battleUIContainer.push_back(new PokemonSelectUI());
}

void BattleUIMgr::ChangeBattleUI(BattleUIType uiType)
{
	// Current UI Rendering end
	_curBattleUI->SetEnable(true);
	// Change current UI to Selected UI
	_curBattleUI = _battleUIContainer[(int)uiType];
	// Start changed UI Rendering
	_curBattleUI->SetEnable(false);
}
