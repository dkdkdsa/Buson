#pragma once
#include "UIButton.h"
struct Pokemon;
class Field;
class DeckPokemonPanel :
    public UIButton
{

public:
    DeckPokemonPanel(Vec2 pos, Vec2 scale, Vec2 offset, int idx);
    ~DeckPokemonPanel();
    void SetField(Field* field);
    void Update() override;
    void Render(HDC _dc) override;
    void OnClick() override;
    void SetOffset(Vec2 s) { offset = s; }
    


private:
    Pokemon* curPokemon;
    int curIdx;
    Field* curField;
    Vec2 offset;

};

