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

	Normal = 1,
	Fire,
	Water,		
	Grass,		
	Electric,	
	Psychic,	
	Ice,		
	Dragon,		
	Dark,		
	Fighting,	
	Flying,		
	Poison,		
	Ground,		
	Rock,		
	Ghost,		
	Steel		

};

struct Pokemon {

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
    PokemonStats Stats;
	std::vector<std::wstring> SkillsKey;
	std::wstring SpriteKey;
	int EvolutionCount;
	int EvolutionNumber;//다음 진화 도감번호 0이면 진화불가능

};

