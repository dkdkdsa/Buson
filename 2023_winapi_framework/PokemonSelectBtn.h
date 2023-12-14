#pragma once
#include "UIButton.h"
#include "pokemon.h"
class Texture;
class PokemonSelectBtn :
    public UIButton
{
public:
    PokemonSelectBtn();
    ~PokemonSelectBtn();
public:
    void Update() override;
    void Render(HDC _dc) override;
    void OnClick() override;
    void InitPos();
    void PokemonTexInit(int idx);
private:
    Pokemon* _pokemon;
    int _partyIdx;

    Texture* _pokeTex;
    Vec2 _pokeTexScale;
    Vec2 _pokeTexPos;

    float _maxHp;
    Texture* _hpBarTex;
    Vec2 _hpBarScale;
    Vec2 _hpBarPos;
};