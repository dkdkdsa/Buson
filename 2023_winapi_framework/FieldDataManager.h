#pragma once

struct Pokemon;

class FieldDataManager
{

	SINGLE(FieldDataManager);

public:
	void AddPokemon(Pokemon pokemon);
	void ReleasePokemon();
	vector<Pokemon> GetAllPokemon();
	int GetMoney() { return money; }
	void AddMoney(int v) { money += v; }

private:
	vector<Pokemon> pokemonVec;
	int money = 3000;

};