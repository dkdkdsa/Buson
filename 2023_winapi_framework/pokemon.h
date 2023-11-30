#pragma once
#include<xstring>
#include<vector>
class Skill;
struct PokemonStats
{

	float Hp;		
	float Attack;	
	float Defense;	
	float Speed;	

};

enum class PokemonType
{

	Normal = 0,
	Fire,
	Water,		
	Electric,	
	Grass,		
	Ice,		
	Fighting,	
	Poison,		
	Ground,		
	Flying,		
	Psychic,	
	Bug,
	Rock,		
	Ghost,		
	Dragon,		
	Dark,		
	Steel,
	End

};

struct Pokemon {

	Pokemon() {


	}

	Pokemon(
		vector<PokemonType> type,
		PokemonStats stats,
		std::vector<std::wstring> skillsKey,
		std::wstring spriteKey,
		int evolutionCount,
		int evolutionNumber) 
	{

		Type = type;
		Stats = stats;
		SkillsKey = skillsKey;
		SpriteKey = spriteKey;
		EvolutionCount = evolutionCount;
		EvolutionNumber = evolutionNumber;

	}

	std::vector<PokemonType> Type;
	std::vector<Skill*> Skills;
    PokemonStats Stats;
	std::vector<std::wstring> SkillsKey;
	std::wstring SpriteKey;
	int EvolutionCount;
	int EvolutionNumber;//다음 진화 도감번호 0이면 진화불가능

	float TypeSheet[(int)PokemonType::End][(int)PokemonType::End] = {
		/*Normal*/		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5f, 0, 1, 1, 0.5f },
		/*Fire*/		{ 1, 0.5f, 0.5f, 1, 2, 2, 1, 1, 1, 1, 1, 2, 0.5f, 1, 0.5f, 1, 2 },
		/*Water*/		{ 1, 2, 0.5f, 1, 0.5f, 1, 1, 1, 2, 1, 1, 1, 2, 1, 0.5f, 1, 1 },
		/*Electric*/	{ 1, 1, 2, 0.5f, 0.5f, 1, 1, 1, 0, 2, 1, 1, 1, 1, 0.5f, 1, 1 },
		/*Grass*/		{ 1, 0.5f, 2, 1, 0.5f, 1, 1, 0.5f, 2, 0.5f, 1, 0.5f, 2, 1, 0.5f, 1, 0.5f },
		/*Ice*/			{ 1, 0.5f, 0.5f, 1, 2, 0.5f, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, 0.5f },
		/*Fighing*/		{ 2, 1, 1, 1, 1, 2, 1, 0.5f, 1, 0.5f, 0.5f, 0.5f, 2, 0, 1, 2, 2 },
		/*Poison*/		{ 1, 1, 1, 1, 2, 1, 1, 0.5f, 0.5f, 1, 1, 1, 0.5f, 0.5f, 1, 1, 0 },
		/*Ground*/		{ 1, 2, 1, 2, 0.5f, 1, 1, 2, 1, 0, 1, 0.5f, 2, 1, 1, 1, 2 },
		/*Flying*/		{ 1, 1, 1, 0.5f, 2, 1, 2, 1, 1, 1, 1, 2, 0.5f, 1, 1, 1, 0.5f },
		/*Psychic*/		{ 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 0.5f, 1, 1, 1, 1, 0, 0.5f },
		/*Bug*/			{ 1, 0.5f, 1, 1, 2, 1, 0.5f, 0.5f, 1, 0.5f, 2, 1, 1, 0.5f, 1, 2, 0.5f },
		/*Rock*/		{ 1, 2, 1, 1, 1, 2, 0.5f, 1, 0.5f, 2, 1, 1, 1, 1, 0.5f },
		/*Ghost*/		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 0.5f, 1 },
		/*Dragon*/		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 0.5f },
		/*Dark*/		{ 1, 1, 1, 1, 1, 1, 0.5f, 1, 1, 1, 2, 1, 1, 2, 1, 0.5f, 1 },
		/*Steel*/		{ 1, 0.5f, 0.5f, 0.5f, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0.5f }
	};

	void UseSkill(Pokemon* enemyPokemon, Skill* usedSkill);
};

