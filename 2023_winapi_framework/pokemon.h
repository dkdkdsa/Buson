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

	Normal,		
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

	std::vector<PokemonType> Type;
    PokemonStats Stats;
	std::wstring SkillsKey[4];
	std::wstring SpriteKey;
	int EvolutionCount;

};

