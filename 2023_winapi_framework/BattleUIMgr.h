#pragma once
#include "BattleUI.h"

enum class BattleUIType {
	ActionSelect = 0,
	SkillSelect,
	PokemonSelect,
	Bag,
	Run
};

class BattleUIMgr
{
	SINGLE(BattleUIMgr);
public:
	void Init();
	BattleUI* GetCurBattleUI() {
		return _curBattleUI;
	}
	BattleUI* GetBattleUI(BattleUIType uiType) {
		return _battleUIContainer[(int)uiType];
	}
	void SetBattleUI(BattleUI* ui) {
		_battleUIContainer.push_back(ui);
	}
	void SetCurUI(BattleUIType uiType) {
		_curBattleUI = _battleUIContainer[(int)uiType];
	}
	void ChangeBattleUI(BattleUIType uiType);
private:
	BattleUI* _curBattleUI;
	std::vector<BattleUI*> _battleUIContainer;
};

