#pragma once
#include "BattleUI.h"
class BattleScene;
class PokemonSelectUI :
    public BattleUI
{
public:
    PokemonSelectUI();
    ~PokemonSelectUI();
private:
    std::vector<UIButton*> _buttons;
};