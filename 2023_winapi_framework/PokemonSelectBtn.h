#pragma once
#include "UIButton.h"
class Pokemon;
class PokemonSelectBtn :
    public UIButton
{
public:
    PokemonSelectBtn();
    ~PokemonSelectBtn();
public:
    void SetPokemon(Pokemon* pokemon, int idx) {
        _pokemon = pokemon;
        _partyIdx = idx;
    }
    void Render(HDC _dc) override;
    void OnClick() override;
private:
    Pokemon* _pokemon;
    int _partyIdx;
};