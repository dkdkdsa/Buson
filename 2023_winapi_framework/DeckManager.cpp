#include "pch.h"
#include "pokemon.h"
#include "DeckManager.h"

Pokemon* DeckManager::GetPokemonByIdx(int idx)
{

	if (decks.size() <= idx) return nullptr;
	
	return &decks[idx];

}

void DeckManager::RemovePokemonByIdx(int idx)
{

	decks.erase(decks.begin() + idx);

}

void DeckManager::SwapPokemonByIdx(int idx1, int idx2)
{

	std::swap(decks[idx1], decks[idx2]);

}

bool DeckManager::AddPokemon(Pokemon pokemon)
{

	if (decks.size() < 6) {

		decks.push_back(pokemon);
		return true;

	}
	else {

		return false;

	}



}
