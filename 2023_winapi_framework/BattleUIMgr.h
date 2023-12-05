#pragma once
#include "BattleUI.h"

enum class BattleUIType {

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
	void ChangeBattleUI(BattleUIType uiType);
private:
	BattleUI* _curBattleUI;
	std::vector<BattleUI*> _battleUIContainer;
};

