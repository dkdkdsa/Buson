#pragma once
#include "pokemon.h"
enum class SkillGroup 
{

	Status,
	Attack

};

enum class BattleEffectGroup 
{

	Poison,
	Burn,
	Paralysis,
	Sleep,
	Freeze,
	Confusion,
	Flinch

};

class Skill
{
public:
	Skill();
	~Skill();
public:
	void BattleEffect();
public:
	//string _name;
	SkillGroup _skillGroup;
	int _damage;
	int Accuracy;
	PokemonType _type;
	BattleEffectGroup _battleEffectGroup;
};