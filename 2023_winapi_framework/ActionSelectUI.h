#pragma once
#include "BattleUI.h"
class BattleScene;
class ActionSelectUI :
    public BattleUI
{
public:
    ActionSelectUI();
    ~ActionSelectUI();
    void Update() override;
    //void Render(HDC _dc) override;
private:
    //std::vector<UIButton*> _buttons;
};