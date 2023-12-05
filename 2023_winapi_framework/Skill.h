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

};

class Skill
{
public:
	Skill();
	~Skill();
public:
	void BattleEffect();
public:
	wstring				Name;					// ��� �̸�
	SkillGroup			SkillGroup;				// ��� �з�
	int					Damage;					// ����
	int					Accuracy;				// ���߷�
	PokemonType			SkillType;					// ��� Ÿ��
	BattleEffectGroup	BattleEffectGroup;		// �ΰ�ȿ��
};