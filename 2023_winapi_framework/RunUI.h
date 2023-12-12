#pragma once
#include "BattleUI.h"
class BattleScene;
class RunUI :
    public BattleUI
{
public:
    RunUI();
    ~RunUI();
private:
    std::vector<UIButton*> _buttons;
};

