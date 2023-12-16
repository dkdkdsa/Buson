#pragma once
#include "BattleUI.h"
class BattleScene; struct Pokemon;
class ActionSelectUI :
    public BattleUI
{
public:
    ActionSelectUI();
    ~ActionSelectUI();
public:
    void Init() override;
    void Update() override;
    void Render(HDC _dc) override;
private:
    //std::vector<UIButton*> _buttons;
    Pokemon* _pokemon;
};