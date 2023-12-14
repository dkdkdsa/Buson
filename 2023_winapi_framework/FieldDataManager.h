#pragma once

struct Pokemon;

class FieldDataManager
{

	SINGLE(FieldDataManager);

public:
	void AddPokemon(Pokemon pokemon);
	void ReleasePokemon();
	vector<Pokemon> GetAllPokemon();

private:
	vector<Pokemon> pokemonVec;

};