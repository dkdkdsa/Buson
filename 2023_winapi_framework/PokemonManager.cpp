#include "pch.h"
#include "PokemonManager.h"
#include "pokemon.h"
#include "SkillManager.h"

void PokemonManager::Init()
{

	CreatePokemon();

}

void PokemonManager::CreatePokemon()
{

	Pokemon* curPokemon;

#pragma region 이상해씨_개열

	curPokemon = new Pokemon
	(
		{ PokemonType::Grass },
			{

				1, //HP
				1, //Attack
				1, //Defence
				1, //Speed

			},
			SkillManager::GetInst()->LearnSkill(PokemonType::Grass, 1),
			L"001",
			1,
			2

	);

	_pokemonContainer[1] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

#pragma endregion


}
