#pragma once
struct Pokemon;
class PokemonManager
{

	SINGLE(PokemonManager);

public:
	void Init();
	Pokemon* GetPokemon(int encyclopediaNumber) {

		return _pokemonContainer[encyclopediaNumber];

	}

	Pokemon* GetRamdomPokemonByLevel(int lv) {

		int size = _levelPokemonContainer[lv].size();

		int idx = rand() % size;

		return _levelPokemonContainer[lv][idx];

	}

	void CreatePokemon();

private:
	map<int, Pokemon*> _pokemonContainer;
	map<int, vector<Pokemon*>> _levelPokemonContainer;

};