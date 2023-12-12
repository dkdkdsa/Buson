#pragma once
#include "BattleUI.h"
class BattleScene;
class BagUI :
    public BattleUI
{
public:
    BagUI();
    ~BagUI();
private:
    std::vector<UIButton*> _buttons;
};

