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

#pragma region 이상해씨_개열

	_pokemonContainer.insert(
		{ 1,
		new Pokemon
		(
			{ PokemonType::Grass },
			{

				1, //HP
				1, //Attack
				1, //Defence
				1, //Speed

			},
			SkillManager::GetInst()->LearnSkill(PokemonType::Grass, 1),
			L"OO1",
			1,
			2

		) });

#pragma endregion


}
