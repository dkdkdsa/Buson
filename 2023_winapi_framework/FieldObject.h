#pragma once
#include "Object.h"
#include "pokemon.h"
class Texture;
class FieldObject :
    public Object
{

public:
    FieldObject(Pokemon pokemon);
    ~FieldObject();
    void Update() override;
    void Render(HDC _dc) override;

    const Pokemon& GetPokemon() const { return _pokemon; }
    void SetPokemon(Pokemon pokemon) { _pokemon = pokemon; }

private:
    Texture* _texture;
    Pokemon _pokemon;

};

