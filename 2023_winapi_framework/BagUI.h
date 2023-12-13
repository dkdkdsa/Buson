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
    void Update();
private:
    std::vector<UIButton*> _pokemonBtns;
};

