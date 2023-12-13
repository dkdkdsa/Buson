#include "pch.h"
#include "BattleUIMgr.h"
#include "ActionSelectUI.h"
#include "SkillSelectUI.h"
#include "PokemonSelectUI.h"
#include "BagUI.h"
#include "RunUI.h""

void BattleUIMgr::Init()
{
	/*_battleUIContainer.push_back(new ActionSelectUI());
	_battleUIContainer.push_back(new SkillSelectUI());
	_battleUIContainer.push_back(new PokemonSelectUI());
	_battleUIContainer.push_back(new BagUI());
	_battleUIContainer.push_back(new RunUI());*/
	/*SetCurUI(BattleUIType::ActionSelect);*/
}

void BattleUIMgr::ChangeBattleUI(BattleUIType uiType)
{
	// Current UI Rendering end
	_curBattleUI->SetEnable(false);
	// Change current UI to Selected UI
	SetCurUI(uiType);
	// Start changed UI Rendering
	_curBattleUI->SetEnable(true);
}
