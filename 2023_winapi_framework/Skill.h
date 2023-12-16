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
	Drain,		// 체력 흡수
	Continue,	// 연속
	Critical,	// 급소
	AtkRankDown,// 공격랭크다운
	DEFRankDown,// 방어랭크다운
	SPERankDown,// 속도랭크다운
	MyAtkDown,	// 내 공격다운
	MyDEFDown,  // 내 방어다운
	MySPEDown,  // 내 속도다운
	Recoil,		// 반동
	DamageRecoil,//데미지 반동
	MyAtkUp,	// 내 공격 업
	MyDEFUp,	// 내 방어 업
	MySEPUp,	// 내 속도 업
	ActionPriority, // 우선도

};

class Skill
{
public:
	Skill() {

	}
	Skill(
		wstring name,
		SkillGroup skillGroup,
		int damage,
		int accuracy,
		int pp,
		PokemonType skillType,
		BattleEffectGroup battleEffectGruop,
		int effectCnt,
		int percentage)
	{
		Name = name;
		SkillGroup = skillGroup;
		Damage = damage;
		Accuracy = accuracy;
		PP = pp;
		SkillType = skillType;
		BattleEffectGroup = battleEffectGruop;
		EffectCnt = effectCnt;
		Percentage = percentage;
	}
	~Skill();
public:
	void BattleEffect();
public:
	wstring				Name;					// 기술 이름
	SkillGroup			SkillGroup;				// 기술 분류
	int					Damage;					// 위력
	int					Accuracy;				// 명중률
	int					PP;						// 사용가능 횟수
	PokemonType			SkillType;				// 기술 타입
	BattleEffectGroup	BattleEffectGroup;		// 부가효과
	int					EffectCnt;				// 부가효과 계수
	int					Percentage;				// 부가효과발동 확률

};