#pragma once
#include "BattleUI.h"
class BattleScene; struct Pokemon;
class PokemonSelectUI :
    public BattleUI
{
public:
    PokemonSelectUI();
    ~PokemonSelectUI();
public:
    void Init() override;
    void Update() override;
private:
    std::vector<Pokemon*> _pokemons;
    std::vector<UIButton*> _pokemonBtns;
};