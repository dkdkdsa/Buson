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

#pragma region �̻��ؾ�_����

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
			L"�̻��ؾ�",
			1,
			2
	);

	_pokemonContainer[1] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

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
			L"002",
			L"�̻���Ǯ",
			2,
			3
	);

	_pokemonContainer[2] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

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
			L"003",
			L"�̻��ز�",
			3,
			0
			);

	_pokemonContainer[3] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);

#pragma endregion


}
