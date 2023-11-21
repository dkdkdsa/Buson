#pragma once
#include"pch.h"

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

	PokemonType Type;
	PokemonStats Stats;
	Skill* Skills[4];
	int EvolutionCount;
	wstring SpriteKey;

};

