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

	PokemonType Type;
	PokemonStats Stats;


};

