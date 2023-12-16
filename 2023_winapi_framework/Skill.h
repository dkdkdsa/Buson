#pragma once
#include "pokemon.h"
enum class SkillGroup 
{

	Status = 0, // �з� - ��ȭ (�������ͽ� ���� ��ȭ, �����̻� ���� ��ȭ ��)
	Attack	// �з� - ���� (����, Ư�� ����)

};

enum class BattleEffectGroup 
{

	None = 0,		// �ΰ�ȿ�� ����
	Poison,		// ��
	Burn,		// ȭ��
	Paralysis,	// ����
	Sleep,		// ���
	Freeze,		// ����
	Confusion,	// ȥ��
	Flinch,		// Ǯ����
	Drain,		// ü�� ���
	Continue,	// ����
	Critical,	// �޼�
	AtkRankDown,// ���ݷ�ũ�ٿ�
	DEFRankDown,// ��ũ�ٿ�
	SPERankDown,// �ӵ���ũ�ٿ�
	MyAtkDown,	// �� ���ݴٿ�
	MyDEFDown,  // �� ���ٿ�
	MySPEDown,  // �� �ӵ��ٿ�
	Recoil,		// �ݵ�
	DamageRecoil,//������ �ݵ�
	MyAtkUp,	// �� ���� ��
	MyDEFUp,	// �� ��� ��
	MySEPUp,	// �� �ӵ� ��
	ActionPriority, // �켱��

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
	wstring				Name;					// ��� �̸�
	SkillGroup			SkillGroup;				// ��� �з�
	int					Damage;					// ����
	int					Accuracy;				// ���߷�
	int					PP;						// ��밡�� Ƚ��
	PokemonType			SkillType;				// ��� Ÿ��
	BattleEffectGroup	BattleEffectGroup;		// �ΰ�ȿ��
	int					EffectCnt;				// �ΰ�ȿ�� ���
	int					Percentage;				// �ΰ�ȿ���ߵ� Ȯ��

};