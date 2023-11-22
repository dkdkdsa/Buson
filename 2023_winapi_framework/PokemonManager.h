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

	void CreatePokemon();

private:
	map<int, Pokemon*> _pokemonContainer;
	vector<Pokemon*> _level_1_Pokemon;
	vector<Pokemon*> _level_2_Pokemon;
	vector<Pokemon*> _level_3_Pokemon;

};