#pragma once
#include "BattleUI.h"
class BattleScene;
class ActionSelectUI :
    public BattleUI
{
public:
    ActionSelectUI();
    ~ActionSelectUI();
private:
    std::vector<UIButton*> _buttons;
};