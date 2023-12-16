#pragma once
#include "BattleUI.h"
#include "PokemonShiftBtn.h"
class Texture; class Pokemon;
class PokemonShiftUI :
    public BattleUI
{
public:
    PokemonShiftUI();
    ~PokemonShiftUI();
public:
    void Init() override;
    void Update() override;
    void SetPokemon(Pokemon* pokemon) {
        static_cast<PokemonShiftBtn*>(_btns.front())->SetPokemon(pokemon);
    }
private:
    std::vector<UIButton*> _btns;
};