#include "pch.h"
#include "FieldDataManager.h"
#include "pokemon.h"

void FieldDataManager::AddPokemon(Pokemon pokemon)
{

	pokemonVec.push_back(pokemon);
	
}

void FieldDataManager::ReleasePokemon()
{

	pokemonVec.clear();

}

vector<Pokemon> FieldDataManager::GetAllPokemon()
{

	return pokemonVec;

}
