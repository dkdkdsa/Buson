#pragma once
#include "BattleUI.h"
class BattleScene;
class PokemonSelectUI :
    public BattleUI
{
public:
    PokemonSelectUI();
    ~PokemonSelectUI();
public:
    void Update() override;
private:
    std::vector<UIButton*> _pokemonBtns;
};