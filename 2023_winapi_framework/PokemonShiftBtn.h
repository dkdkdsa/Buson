#pragma once
#include "UIButton.h"
class Pokemon; class Texture;
class PokemonShiftBtn :
    public UIButton
{
public:
    PokemonShiftBtn();
    ~PokemonShiftBtn();
public:
    void Update() override;
    void Render(HDC _dc) override;
    void OnClick() override;
    void SetPokemon(Pokemon* pokemon);
private:
    Pokemon* _pokemon;

    Texture* _pokemonTex;
    Vec2 _pokemonTexPos;
    Vec2 _pokemonTexScale;
};