#pragma once
#include "pokemon.h"
enum class SkillGroup 
{

	Status, // �з� - ��ȭ (�������ͽ� ���� ��ȭ, �����̻� ���� ��ȭ ��)
	Attack	// �з� - ���� (����, Ư�� ����)

};

enum class BattleEffectGroup 
{

	None,		// �ΰ�ȿ�� ����
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
	wstring				_name;					// ��� �̸�
	SkillGroup			_skillGroup;			// ��� �з�
	int					_damage;				// ����
	int					_accuracy;				// ���߷�
	PokemonType			_type;					// ��� Ÿ��
	BattleEffectGroup	_battleEffectGroup;		// �ΰ�ȿ��
};