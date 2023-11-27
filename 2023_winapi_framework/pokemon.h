#pragma once
#include <xstring>
#include <vector>
#include "Skill.h"

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

	Normal = 0,	// �븻
	Fire,		// ��
	Water,		// ��
	Electric,	// ����
	Grass,		// Ǯ
	Ice,		// ����
	Fighting,	// ����
	Poison,		// ��
	Ground,		// ��
	Flying,		// ����
	Psychic,	// ������
	Bug,		// ����
	Rock,		// ����
	Ghost,		// ��Ʈ
	Dragon,		// �巡��
	Dark,		// ��
	Steel,		// ��ö
	End
};

struct Pokemon {

	std::vector<PokemonType>	Type;
	PokemonStats				Stats;
	std::vector<Skill>			Skills;
	std::wstring				SkillsKey[4];
	std::wstring				SpriteKey;
	int							EvolutionCount;

	/*float TypeSheet[(int)PokemonType::End][(int)PokemonType::End] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5f, 0, 1, 1, 0.5f },
		{ 1, 0.5f, 0.5f, 1, 2, 2, 1, 1, 1, 1, 1, 2, 0.5f, 1, 0.5f, 1, 2 },
		{ 1, 2, 0.5f, 1, 0.5f, 1, 1, 1, 2, 1, 1, 1, 2, 1, 0.5f, 1, 1 },
		{ 1, 1, 2, 0.5f, 0.5f, 1, 1, 1, 0, 2, 1, 1, 1, 1, 0.5f, 1, 1 },
		{ 1, 0.5f, 2, 1, 0.5f, 1, 1, 0.5f, 2, 0.5f, 1, 0.5f, 2, 1, 0.5f, 1, 0.5f },
		{ 1, 0.5f, 0.5f, 1, 2, 0.5f, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, 0.5f },
		{ 2, 1, 1, 1, 1, 2, 1, 0.5f, 1, 0.5f, 0.5f, 0.5f, 2, 0, 1, 2, 2 },
		{  }
	};*/

	void UseSkill(Pokemon* enemyPokemon, Skill usedSkill) {
		float damageMultiplier = 1.f;
		int damage = (Stats.Attack * usedSkill.Damage);
		if (Type.front() == usedSkill.Type || Type[1] == usedSkill.Type) {
			damage *= 1.5f;
		}
		//if(usedSkill.Type)
	}
};

