#pragma once
#include "Object.h"

class Texture;
class Field;
class FieldScene;
struct Pokemon;
class PokemonBox : public Object
{

public:
    PokemonBox(Vec2 pos, Vec2 size, FieldScene* field);
    ~PokemonBox();
    void Update() override;
    void Render(HDC _dc) override;


private:
    void SetAblePokemon();
    Texture* _tex;
    Pokemon* _curPokemon;
    Field* _field;
    FieldScene* _fieldScene;
    Vec2 origin;
    float per;

};