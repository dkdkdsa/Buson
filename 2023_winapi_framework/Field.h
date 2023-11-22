#pragma once
#include "Object.h"
#include "pokemon.h"

class FieldObject;
class Field :
    public Object
{

public:
    Field(Vec2 center, Vec2 fieldSize);
    ~Field();

    void Update() override;
    void Render(HDC _dc) override;
    void AddPokemon(Pokemon pokemon);

private:
    vector<FieldObject*> _thisFieldObject;

};

