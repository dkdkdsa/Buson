#pragma once
#include "BattleUI.h"

enum class BattleUIType {
	ActionSelect = 0,
	SkillSelect,
	PokemonSelect,
	Bag,
	Run,
	PokemonShiftUI,
	End
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
		_curBattleUI->Init();
	}
	void ReleaseBattleUI() {
		for (int i = 0; i < _battleUIContainer.size(); ++i) {
			_battleUIContainer[i]->Release();
			delete _battleUIContainer[i];
		}
		_battleUIContainer.clear();
	}
	void ChangeBattleUI(BattleUIType uiType);
private:
	BattleUI* _curBattleUI;
	std::vector<BattleUI*> _battleUIContainer;
};

