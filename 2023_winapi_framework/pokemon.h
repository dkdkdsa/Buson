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

	Normal = 0,	// 노말
	Fire,		// 불
	Water,		// 물
	Electric,	// 전기
	Grass,		// 풀
	Ice,		// 얼음
	Fighting,	// 격투
	Poison,		// 독
	Ground,		// 땅
	Flying,		// 비행
	Psychic,	// 에스퍼
	Bug,		// 벌레
	Rock,		// 바위
	Ghost,		// 고스트
	Dragon,		// 드래곤
	Dark,		// 악
	Steel,		// 강철
	End
};

struct Pokemon {

	std::vector<PokemonType>	Type;
	PokemonStats				Stats;
	std::vector<Skill>			Skills;
	std::wstring				SkillsKey[4];
	std::wstring				SpriteKey;
	int							EvolutionCount;

	// 열: 공격을 받는 타입
	// 행: 공격을 하는 타입
	/// <summary>
	///   공 격 을  받 는  타 입
	/// 공
	/// 격
	/// 을
	/// 
	/// 하
	/// 는
	/// 
	/// 타
	/// 입
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

