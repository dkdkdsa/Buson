#include "pch.h"
#include "PokemonManager.h"
#include "SkillManager.h"

void PokemonManager::Init()
{

	CreatePokemon();

}

Pokemon PokemonManager::GetPokemon(int encyclopediaNumber)
{
	
	auto pokemon = _pokemonContainer[encyclopediaNumber];
	pokemon.Stats = PokemonStats({

			GetRealValue(pokemon.Stats.Hp, rand() % 10, rand() % 30, pokemon.EvolutionCount * 20) + 110,

			GetRealValue(pokemon.Stats.Attack, rand() % 10, rand() % 30, pokemon.EvolutionCount * 20),

			GetRealValue(pokemon.Stats.Defense, rand() % 10, rand() % 30, pokemon.EvolutionCount * 20),

			GetRealValue(pokemon.Stats.Speed, rand() % 10, rand() % 30, pokemon.EvolutionCount * 20)

		});

	pokemon.SkillsKey = SkillManager::GetInst()->LearnSkill(pokemon.Type[0], pokemon.EvolutionCount);

	return pokemon;

}

Pokemon PokemonManager::GetRamdomPokemonByLevel(int lv)
{

	int size = _levelPokemonContainer[lv].size();

	int idx = rand() % size;

	auto pokemon = _levelPokemonContainer[lv][idx];

	pokemon.Stats = PokemonStats({

		GetRealValue(pokemon.Stats.Hp, rand() % 10, (rand() % 30), pokemon.EvolutionCount * 20) + 110,

		GetRealValue(pokemon.Stats.Attack, rand() % 10, rand() % 30, pokemon.EvolutionCount * 20),

		GetRealValue(pokemon.Stats.Defense, rand() % 10, rand() % 30, pokemon.EvolutionCount * 20),

		GetRealValue(pokemon.Stats.Speed, rand() % 10, rand() % 30, pokemon.EvolutionCount * 20)

		});

	pokemon.SkillsKey = SkillManager::GetInst()->LearnSkill(pokemon.Type[0], pokemon.EvolutionCount);

	return pokemon;

}
void PokemonManager::CreatePokemon()
{

	Pokemon curPokemon;

#pragma region 이상해씨_개열

	curPokemon = Pokemon
	(
		{ PokemonType::Grass },
			{

				45, //HP
				49 + 32.5f, //Attack
				49 + 32.5f, //Defence
				45, //Speed

			},
			SkillManager::GetInst()->LearnSkill(PokemonType::Grass, 1),
			L"001",
			L"이상해씨",
			1,
			2
	);

	_pokemonContainer[1] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

	curPokemon = Pokemon
	(

		{ PokemonType::Grass },
			{

				60, //HP
				62 + 40, //Attack
				63 + 40, //Defence
				60, //Speed

			},
			SkillManager::GetInst()->LearnSkill(PokemonType::Grass, 1),
			L"002",
			L"이상해풀",
			2,
			3
	);

	_pokemonContainer[2] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

	curPokemon = Pokemon
	(

		{ PokemonType::Grass },
			{

				80, //HP
				82 + 50, //Attack
				83 + 50, //Defence
				80, //Speed

			},
			SkillManager::GetInst()->LearnSkill(PokemonType::Grass, 1),
			L"003",
			L"이상해꽃",
			3,
			0
			);

	_pokemonContainer[3] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);

#pragma endregion


}

float PokemonManager::GetRealValue(float groupValue, float objectVel, float effortValue, float lv)
{
	return ((groupValue * 2) + objectVel + (effortValue / 4)) * lv / 100 + 5;
}
