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

	Normal,		// �븻
	Fire,		// ��
	Water,		// ��
	Grass,		// Ǯ
	Electric,	// ����
	Psychic,	// ������
	Ice,		// ����
	Dragon,		// �巡��
	Dark,		// ��
	Fighting,	// ����
	Flying,		// ����
	Poison,		// ��
	Ground,		// ��
	Rock,		// ����
	Ghost,		// ��Ʈ
	Steel		// ��ö

};

struct Pokemon {

	std::vector<PokemonType>	Type;
    PokemonStats				Stats;
	std::wstring				SkillsKey[4];
	std::wstring				SpriteKey;
	int							EvolutionCount;

};

