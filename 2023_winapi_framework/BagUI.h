#pragma once
#include "BattleUI.h"
class BattleScene;
class BagUI :
    public BattleUI
{
public:
    BagUI();
    ~BagUI();
public:
    void Update() override;
    void Release() override;
private:
    std::vector<UIButton*> _pokemonBtns;
};

