#pragma once

struct Pokemon;
class DeckManager
{

	SINGLE(DeckManager);

public:
	Pokemon* GetPokemonByIdx(int idx);
	void RemovePokemonByIdx(int idx);
	void SwapPokemonByIdx(int idx1, int idx2);
	bool AddPokemon(Pokemon pokemon);
	vector<Pokemon>& GetPokemon() { return decks; }


private:
	vector<Pokemon> decks;

};

