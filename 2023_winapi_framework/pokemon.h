#pragma once
#include <xstring>
#include <vector>
#include "Skill.h"

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

	// ��: ������ �޴� Ÿ��
	// ��: ������ �ϴ� Ÿ��
	/// <summary>
	///   �� �� ��  �� ��  Ÿ ��
	/// ��
	/// ��
	/// ��
	/// 
	/// ��
	/// ��
	/// 
	/// Ÿ
	/// ��
	/// </summary>
	/// <param name="enemyPokemon"></param>
	/// <param name="usedSkill"></param>

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

	void UseSkill(Pokemon* enemyPokemon, Skill usedSkill) {
		int damage = 0.44f * (Stats.Attack / enemyPokemon->Stats.Defense); // Default Damage based on level 50
		for (int i = 0; i < Type.size(); ++i) { // Same-type attack bonus 
			if (Type[i] == usedSkill.Type)
				damage *= 1.5f;
		}
		for (int i = 0; i < (int)PokemonType::End; ++i) {
			damage *= TypeSheet[(int)usedSkill.Type][i];
		}
		enemyPokemon->Stats.Hp -= damage;
	}
};

