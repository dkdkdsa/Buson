#pragma once

#include "pokemon.h"

class PokemonManager
{

	SINGLE(PokemonManager);

public:
	void Init();
	Pokemon GetPokemon(int encyclopediaNumber);

	Pokemon GetRamdomPokemonByLevel(int lv);

	void CreatePokemon();

	float GetRealValue(float groupValue, float objectVel, float effortValue, float lv);

private:
	map<int, Pokemon> _pokemonContainer;
	map<int, vector<Pokemon>> _levelPokemonContainer;

};