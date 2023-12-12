#pragma once
#include "UIButton.h"
class Pokemon;
class PokemonSelectBtn :
    public UIButton
{
public:
    PokemonSelectBtn(Pokemon* pokemon, int idx);
    ~PokemonSelectBtn();
private:
    Pokemon* _pokemon;
    int _partyIdx;
};