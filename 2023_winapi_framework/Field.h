#pragma once
#include "Object.h"
#include "pokemon.h"
#include <unordered_set>

class FieldObject;
class Texture;
class Field :
    public Object
{

public:
    Field(Vec2 center, Vec2 fieldSize);
    ~Field();

    void Update() override;
    void Render(HDC _dc) override;
    FieldObject* AddPokemon(Pokemon pokemon);
    void SetDrag();
    void ReleaseDrag();
    void Drag();
    FieldObject* ChackBound(FieldObject* currentObject, POINT mousePos);
    void AddDeck();

private:
    std::vector<FieldObject*> _thisFieldObject;
    FieldObject* _dragObject;
    Texture* _tex;

};

