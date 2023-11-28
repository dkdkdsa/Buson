#pragma once
#include "pokemon.h"
enum class SkillGroup 
{

	Status = 0, // 분류 - 변화 (스테이터스 관련 변화, 상태이상 관련 변화 등)
	Attack	// 분류 - 공격 (물리, 특수 통합)

};

enum class BattleEffectGroup 
{

	None = 0,		// 부가효과 없음
	Poison,		// 독
	Burn,		// 화상
	Paralysis,	// 마비
	Sleep,		// 잠듦
	Freeze,		// 얼음
	Confusion,	// 혼란
	Flinch,		// 풀죽음

};

class Skill
{
public:
	Skill();
	~Skill();
public:
	void BattleEffect();
public:
	wstring				Name;					// 기술 이름
	SkillGroup			SkillGroup;				// 기술 분류
	int					Damage;					// 위력
	int					Accuracy;				// 명중률
	PokemonType			SkillType;					// 기술 타입
	BattleEffectGroup	BattleEffectGroup;		// 부가효과
};