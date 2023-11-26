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

	Normal,		// 노말
	Fire,		// 불
	Water,		// 물
	Grass,		// 풀
	Electric,	// 전기
	Psychic,	// 에스퍼
	Ice,		// 얼음
	Dragon,		// 드래곤
	Dark,		// 악
	Fighting,	// 격투
	Flying,		// 비행
	Poison,		// 독
	Ground,		// 땅
	Rock,		// 바위
	Ghost,		// 고스트
	Steel		// 강철

};

struct Pokemon {

	std::vector<PokemonType>	Type;
    PokemonStats				Stats;
	std::wstring				SkillsKey[4];
	std::wstring				SpriteKey;
	int							EvolutionCount;

};

