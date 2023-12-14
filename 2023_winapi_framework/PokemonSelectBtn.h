#pragma once
#include "UIButton.h"
#include "pokemon.h"
#include "DeckManager.h"
class Texture;
class PokemonSelectBtn :
    public UIButton
{
public:
    PokemonSelectBtn();
    ~PokemonSelectBtn();
public:
    void PokemonSetting(int idx) {
        _partyIdx = idx;
        _pokemon = DeckManager::GetInst()->GetPokemonByIdx(_partyIdx - 1);
        _maxHp = _pokemon->Stats.Hp;
    }
    void Update() override;
    void Render(HDC _dc) override;
    void OnClick() override;
    void InitPos();
    void PokemonTexInit();
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
    
    Vec2 _hpTxtPos;
    Vec2 _maxHpTxtPos;

    Vec2 _lvPos;
};