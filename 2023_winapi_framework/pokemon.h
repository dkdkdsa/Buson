#pragma once

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


};

