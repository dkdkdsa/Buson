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

	Fire,
	Ice

};

struct Pokemon {

	std::vector<PokemonType> Type;
    PokemonStats Stats;
	std::wstring SkillsKey[4];
	std::wstring SpriteKey;
	int EvolutionCount;

};

