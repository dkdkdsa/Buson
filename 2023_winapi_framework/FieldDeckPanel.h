#pragma once
#include "Object.h"
class Field;
class DeckPokemonPanel;
class Texture;
class FieldDeckPanel :
    public Object
{

public:
    FieldDeckPanel(Vec2 pos, Vec2 scale, Field* field);
    ~FieldDeckPanel();

    void Render(HDC _dc) override;
    void Update() override;
    vector<DeckPokemonPanel*> renders;

private:
    Texture* mainTex;

};

