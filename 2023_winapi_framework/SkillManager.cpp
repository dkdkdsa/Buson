#include "pch.h"
#include "SkillManager.h"
#include "Skill.h"

void SkillManager::Init()
{

	CreateSkill();

}


void SkillManager::CreateSkill()
{

	map<int, vector<wstring>> grass
	{

		{1, {L"���", L"�ٳ�������", L"����ä��", L"������", L"�ް��巹��"}},
		{2, {L"���", L"�ٳ�������", L"����ä��", L"������", L"�ް��巹��", L"�Ⱑ�巹��", L"�����", L"�����ø���", L"���ȣ��", L"�׷����ͼ�", L"��������", L"�������̵�"}},
		{3, {L"���", L"�ٳ�������", L"����ä��", L"������", L"�ް��巹��", L"�Ⱑ�巹��", L"�����", L"�����ø���", L"���ȣ��", L"�׷����ͼ�", L"��������", L"�������̵�", L"�ϵ��÷�Ʈ", L"��������", L"�Ŀ���", L"����ظ�"}}

	};

	_learnSkillContainer.insert({ PokemonType::Grass, grass });

	map<int, vector<wstring>> fire
	{
		{1, {L"�Ҳɼ���", L"��Ʈ������", L"�������÷���", L"���¿��", L"�Ҳɾ���"}},
		{2, {L"�Ҳɼ���", L"��Ʈ������", L"�������÷���", L"���¿��", L"�Ҳɾ���", L"�Ҳ���ġ", L"ȭ���ڵ���", L"�극����ű", L"��ǳ", L"ȭ�����"}},
		{3, {L"�Ҳɼ���", L"��Ʈ������", L"�������÷���", L"���¿��", L"�Ҳɾ���", L"�Ҳ���ġ", L"ȭ���ڵ���", L"�극����ű", L"��ǳ", L"ȭ�����", L"�Ҵ빮��", L"����Ʈ��", L"������Ʈ", L"�÷������̺�"}}
	};

	_learnSkillContainer.insert({ PokemonType::Fire, fire });

	map<int, vector<wstring>> water
	{
		{1, {L"������", L"��ǰ", L"�������Ʈ", L"���������"}},
		{2, {L"������", L"��ǰ", L"�������Ʈ", L"���������", L"��ǰ����", L"����������", L"�����ĵ�", L"���������", L"�ĵ�Ÿ��"}},
		{3, {L"������", L"��ǰ", L"�������Ʈ", L"���������", L"��ǰ����", L"����������", L"�����ĵ�", L"���������", L"�ĵ�Ÿ��", L"���̵������", L"���̵��ĳ��"}}
	};

	_learnSkillContainer.insert({ PokemonType::Water, water });

	map<int, vector<wstring>> normal
	{
		{1, {L"��ġ��", L"���ӻ�ġ��", L"������", L"Ǯ����", L"�����ġ��", L"��������", L"°������", L"�����Ҹ�", L"������ȭ"}},
		{2, {L"��ġ��", L"���ӻ�ġ��", L"������", L"Ǯ����", L"�����ġ��", L"��������", L"°������", L"�����Ҹ�", L"������ȭ", L"����", L"������", L"��ġ��", L"����ġ��", L"�ް�����ġ", L"���ǵ彺Ÿ"}},
		{3, {L"��ġ��", L"���ӻ�ġ��", L"������", L"Ǯ����", L"�����ġ��", L"��������", L"°������", L"�����Ҹ�", L"������ȭ", L"����", L"������", L"��ġ��", L"����ġ��", L"�ް�����ġ", L"���ǵ彺Ÿ", L"������", L"����", L"�ı�����", L"���ǻ�����Ŭ", L"�ް���ű"}}
	};

	_learnSkillContainer.insert({ PokemonType::Normal, normal });

	map<int, vector<wstring>> fighting
	{
		{1, {L"�±Ǵ��", L"������ġ", L"��������", L"�߰�", L"�׷ο���ġ"}},
		{2, {L"�±Ǵ��", L"������ġ", L"��������", L"�߰�", L"�׷ο���ġ", L"��ű", L"�巹����ġ", L"�ĵ�ź", L"��ī�̾���"}},
		{3, {L"�±Ǵ��", L"������ġ", L"��������", L"�߰�", L"�׷ο���ġ", L"��ű", L"�巹����ġ", L"�ĵ�ź", L"��ī�̾���", L"���ձ���", L"���ظ�", L"��û����", L"������ġ"}}
	};

	_learnSkillContainer.insert({ PokemonType::Fighting, fighting });

	map<int, vector<wstring>> ground
	{
		{1, {L"�𷡻Ѹ���", L"����Ѹ���", L"�ӵ��", L"������"}},
		{2, {L"�𷡻Ѹ���", L"����Ѹ���", L"�ӵ��", L"������", L"���ٱ�ġ��", L"������", L"������ź", L"�����ǹ߱�����"}},
		{3, {L"�𷡻Ѹ���", L"����Ѹ���", L"�ӵ��", L"������", L"���ٱ�ġ��", L"������", L"������ź", L"�����ǹ߱�����", L"10������", L"�帱���̳�", L"��������", L"����"}}
	};

	_learnSkillContainer.insert({ PokemonType::Ground, ground });

	map<int, vector<wstring>> rock
	{
		{1, {L"����߸���", L"������Ʈ", L"��������", L"��������"}},
		{2, {L"����߸���", L"������Ʈ", L"��������", L"��������", L"�ϼ�����", L"�������", L"�Ŀ���"}},
		{3, {L"����߸���", L"������Ʈ", L"��������", L"��������", L"�ϼ�����", L"�������", L"�Ŀ���", L"�ϼ���", L"���濡��", L"�糯��ġ��"}}
	};

	_learnSkillContainer.insert({ PokemonType::Rock, rock });

	map<int, vector<wstring>> electric
	{
		{1, {L"�����ũ", L"����ũ", L"������", L"�Ϸ�Ʈ����Ʈ", L"������"}},
		{2, {L"�����ũ", L"����ũ", L"������", L"�Ϸ�Ʈ����Ʈ", L"������", L"������ġ", L"10����Ʈ", L"����", L"���ϵ庼Ʈ"}},
		{3, {L"�����ũ", L"����ũ", L"������", L"�Ϸ�Ʈ����Ʈ", L"������", L"������ġ", L"10����Ʈ", L"����", L"���ϵ庼Ʈ", L"��Ʈ��Ŭ", L"������", L"����"}}
	};

	_learnSkillContainer.insert({ PokemonType::Electric, electric });

	map<int, vector<wstring>> psychic
	{
		{1, {L"ȯ���", L"������", L"����̵�", L"��Ʈ������"}},
		{2, {L"ȯ���", L"������", L"����̵�", L"��Ʈ������", L"��������", L"�����ڼ�ũ", L"����ǹ�ġ��", L"������Ŀ��"}},
		{3, {L"ȯ���", L"������", L"����̵�", L"��Ʈ������", L"��������", L"�����ڼ�ũ", L"����ǹ�ġ��", L"������Ŀ��", L"�����", L"������Ű�׽ý�"}}
	};

	_learnSkillContainer.insert({ PokemonType::Psychic, psychic });

	map<int, vector<wstring>> ice
	{
		{1, {L"���ζ��", L"��帧ħ", L"������ġ", L"��������"}},
		{2, {L"���ζ��", L"��帧ħ", L"������ġ", L"��������", L"����������", L"�õ���ġ", L"��帧������"}},
		{3, {L"���ζ��", L"��帧ħ", L"������ġ", L"��������", L"����������", L"�õ���ġ", L"��帧������", L"���̽��ظ�", L"������", L"�õ���"}}
	};

	_learnSkillContainer.insert({ PokemonType::Ice, ice });

	map<int, vector<wstring>> dark
	{
		{1, {L"���󰡶�����", L"Ź�ļ�������", L"�ºα�����", L"��ũ�ƿ�"}},
		{2, {L"���󰡶�����", L"Ź�ļ�������", L"�ºα�����", L"��ũ�ƿ�", L"�������ֵθ���", L"�������", L"����Ʈ����Ʈ"}},
		{3, {L"���󰡶�����", L"Ź�ļ�������", L"�ºα�����", L"��ũ�ƿ�", L"�������ֵθ���", L"�������", L"����Ʈ����Ʈ", L"�����ĵ�", L"������μ���"}}
	};

	_learnSkillContainer.insert({ PokemonType::Dark, dark });

	map<int, vector<wstring>> flying
	{
		{1, {L"�ٶ�����Ű��", L"����ġ��", L"��������", L"�ɱ�"}},
		{2, {L"�ٶ�����Ű��", L"����ġ��", L"��������", L"�ɱ�", L"ȸ���θ�", L"�����ȯ", L"�ɾƴ��", L"�������"}},
		{3, {L"�ٶ�����Ű��", L"����ġ��", L"��������", L"�ɱ�", L"ȸ���θ�", L"�����ȯ", L"�ɾƴ��", L"�������", L"��ǳ", L"��ũ����", L"�극�̺����"}}
	};

	_learnSkillContainer.insert({ PokemonType::Flying, flying });

	map<int, vector<wstring>> bug
	{
		{1, {L"����ϵ�", L"�����ڸ���", L"�����ٶ�", L"����������"}},
		{2, {L"����ϵ�", L"�����ڸ���", L"�����ٶ�", L"����������", L"�����Ǿߴܹ���", L"����ũ�ν�", L"�ñ׳κ�", L"����"}},
		{3, {L"����ϵ�", L"�����ڸ���", L"�����ٶ�", L"����������", L"�����Ǿߴܹ���", L"����ũ�ν�", L"�ñ׳κ�", L"����", L"�ް���", L"�������"}}
	};

	_learnSkillContainer.insert({ PokemonType::Bug, bug });

	map<int, vector<wstring>> dragon
	{
		{1, {L"���Ǽ���", L"ȸ����", L"������", L"�巡������"}},
		{2, {L"���Ǽ���", L"ȸ����", L"������", L"�巡������", L"�����ĵ�", L"�巡��ũ��", L"������"}},
		{3, {L"���Ǽ���", L"ȸ����", L"������", L"�巡������", L"�����ĵ�", L"�巡��ũ��", L"������", L"����", L"�巡����̺�", L"�뼺��"}}
	};

	_learnSkillContainer.insert({ PokemonType::Dragon, dragon });

	map<int, vector<wstring>> poison
	{
		{1, {L"��ħ", L"���ؾ�", L"������", L"����������"}},
		{2, {L"��ħ", L"���ؾ�", L"������", L"����������", L"ũ�ν�������", L"������ź", L"�������̺�"}},
		{3, {L"��ħ", L"���ؾ�", L"������", L"����������", L"ũ�ν�������", L"������ź", L"�������̺�", L"Ʈ��", L"����Ʈ��Ʈ"}}
	};

	_learnSkillContainer.insert({ PokemonType::Poison, poison });

	map<int, vector<wstring>> ghost
	{
		{1, {L"����Ʈ���", L"�ӱ�", L"�Ű��", L"�߽�"}},
		{2, {L"����Ʈ���", L"�ӱ�", L"�Ű��", L"�߽�", L"������ġ", L"����÷��", L"����ũ��"}},
		{3, {L"����Ʈ���", L"�ӱ�", L"�Ű��", L"�߽�", L"������ġ", L"����÷��", L"����ũ��", L"������", L"�����ѹٶ�"}}
	};

	_learnSkillContainer.insert({ PokemonType::Ghost, ghost });

	map<int, vector<wstring>> steel
	{
		{1, {L"��Żũ�ο�", L"�Ҹ���ġ", L"���Ҽ�", L"���׳ݺ�"}},
		{2, {L"��Żũ�ο�", L"�Ҹ���ġ", L"���Ҽ�", L"���׳ݺ�", L"���̾����", L"������ĳ��", L"�̷���"}},
		{3, {L"��Żũ�ο�", L"�Ҹ���ġ", L"���Ҽ�", L"���׳ݺ�", L"���̾����", L"������ĳ��", L"�̷���", L"�ڸ���ġ", L"���̾�����", L"��ö����"}}
	};

	_learnSkillContainer.insert({ PokemonType::Steel, steel });

}

void SkillManager::InitSkillContainer()
{
	_skillContainer.insert({ L"���", new Skill(
		L"���",
		SkillGroup::Attack,
		20,
		100,
		25,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100)
	});

	_skillContainer.insert({ L"�ٳ�������", new Skill(
		L"�ٳ�������",
		SkillGroup::Attack,
		55,
		95,
		25,
		PokemonType::Grass,
		BattleEffectGroup::Critical,
		1,
		100) 
	});

	_skillContainer.insert({ L"����ä��", new Skill(
		L"����ä��",
		SkillGroup::Attack,
		45,
		100,
		25,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100) 
	});

	_skillContainer.insert({ L"������", new Skill(
		L"������",
		SkillGroup::Attack,
		40,
		100,
		40,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100) 
	});

	_skillContainer.insert({ L"�ް��巹��", new Skill(
		L"�ް��巹��",
		SkillGroup::Attack,
		40,
		100,
		15,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100) 
	});

	_skillContainer.insert({ L"�Ⱑ�巹��", new Skill(
		L"�Ⱑ�巹��",
		SkillGroup::Attack,
		75,
		100,
		10,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100)
	});

	_skillContainer.insert({ L"�����", new Skill(
		L"�����",
		SkillGroup::Attack,
		25,
		100,
		30,
		PokemonType::Grass,
		BattleEffectGroup::Continue,
		0,
		100)
	});

	_skillContainer.insert({ L"�����ø���", new Skill(
		L"�����ø���",
		SkillGroup::Attack,
		60,
		100,
		20,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100)
	});

	_skillContainer.insert({ L"���ȣ��", new Skill(
		L"���ȣ��",
		SkillGroup::Attack,
		75,
		100,
		10,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100)
	});

	_skillContainer.insert({ L"�׷����ͼ�", new Skill(
		L"�׷����ͼ�",
		SkillGroup::Attack,
		65,
		90,
		10,
		PokemonType::Grass,
		BattleEffectGroup::DEFRankDown,
		1,
		50)
	});

	_skillContainer.insert({ L"��������", new Skill(
		L"��������",
		SkillGroup::Attack,
		90,
		100,
		10,
		PokemonType::Grass,
		BattleEffectGroup::DEFRankDown,
		1,
		10)
	});

	_skillContainer.insert({ L"�������̵�", new Skill(
		L"�������̵�",
		SkillGroup::Attack,
		90,
		100,
		15,
		PokemonType::Grass,
		BattleEffectGroup::Critical,
		1,
		100)
	});

	_skillContainer.insert({ L"�ϵ��÷�Ʈ", new Skill(
		L"�ϵ��÷�Ʈ",
		SkillGroup::Attack,
		150,
		90,
		5,
		PokemonType::Grass,
		BattleEffectGroup::Recoil,
		1,
		100)
	});

	_skillContainer.insert({ L"��������", new Skill(
		L"��������",
		SkillGroup::Attack,
		130,
		90,
		5,
		PokemonType::Grass,
		BattleEffectGroup::MyAtkDown,
		2,
		100)
	});

	_skillContainer.insert({ L"�Ŀ���", new Skill(
		L"�Ŀ���",
		SkillGroup::Attack,
		130,
		85,
		10,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100)
	});

	_skillContainer.insert({ L"����ظ�", new Skill(
		L"����ظ�",
		SkillGroup::Attack,
		120,
		100,
		15,
		PokemonType::Grass,
		BattleEffectGroup::DamageRecoil,
		3,
		100)
	});

	_skillContainer.insert({ L"�Ҳɼ���", new Skill(
		L"�Ҳɼ���",
		SkillGroup::Attack,
		40,
		100,
		25,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10)
	});

	_skillContainer.insert({ L"��Ʈ������", new Skill(
		L"��Ʈ������",
		SkillGroup::Attack,
		50,
		100,
		20,
		PokemonType::Fire,
		BattleEffectGroup::MySEPUp,
		1,
		100)
	});

	_skillContainer.insert({ L"�������÷���", new Skill(
		L"�������÷���",
		SkillGroup::Attack,
		75,
		100,
		10,
		PokemonType::Fire,
		BattleEffectGroup::AtkRankDown,
		1,
		100)
	});

	_skillContainer.insert({ L"���¿��", new Skill(
		L"���¿��",
		SkillGroup::Attack,
		60,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::None,
		0,
		100)
	});

	_skillContainer.insert({ L"�Ҳɾ���", new Skill(
		L"�Ҳɾ���",
		SkillGroup::Attack,
		65,
		95,
		15,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10)
	});

	_skillContainer.insert({ L"�Ҳ���ġ", new Skill(
		L"�Ҳ���ġ",
		SkillGroup::Attack,
		75,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10)
	});

	_skillContainer.insert({ L"ȭ���ڵ���", new Skill(
		L"ȭ���ڵ���",
		SkillGroup::Attack,
		60,
		100,
		25,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10)
	});

	_skillContainer.insert({ L"�극����ű", new Skill(
		L"�극����ű",
		SkillGroup::Attack,
		85,
		90,
		10,
		PokemonType::Fire,
		BattleEffectGroup::Critical,
		1,
		100)
	});

	_skillContainer.insert({ L"��ǳ", new Skill(
		L"��ǳ",
		SkillGroup::Attack,
		95,
		90,
		10,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		1,
		10)
	});

	_skillContainer.insert({ L"ȭ�����", new Skill(
		L"ȭ�����",
		SkillGroup::Attack,
		90,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		1,
		10)
	});

	_skillContainer.insert({ L"�Ҵ빮��", new Skill(
		L"�Ҵ빮��",
		SkillGroup::Attack,
		110,
		85,
		5,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		1,
		10)
	});

	_skillContainer.insert({ L"����Ʈ��", new Skill(
		L"����Ʈ��",
		SkillGroup::Attack,
		150,
		90,
		5,
		PokemonType::Fire,
		BattleEffectGroup::Recoil,
		1,
		100)
	});

	_skillContainer.insert({ L"������Ʈ", new Skill(
		L"������Ʈ",
		SkillGroup::Attack,
		130,
		90,
		5,
		PokemonType::Fire,
		BattleEffectGroup::MyAtkDown,
		2,
		100)
	});

	_skillContainer.insert({ L"�÷������̺�", new Skill(
		L"�÷������̺�",
		SkillGroup::Attack,
		120,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::DamageRecoil,
		3,
		100)
	});

	_skillContainer.insert({ L"������", new Skill(
		L"������",
		SkillGroup::Attack,
		40,
		100,
		25,
		PokemonType::Water,
		BattleEffectGroup::None,
		3,
		100)
	});

	_skillContainer.insert({ L"��ǰ", new Skill(
		L"��ǰ",
		SkillGroup::Attack,
		40,
		100,
		30,
		PokemonType::Water,
		BattleEffectGroup::SPERankDown,
		1,
		10)
	});

	_skillContainer.insert({ L"�������Ʈ", new Skill(
		L"�������Ʈ",
		SkillGroup::Attack,
		40,
		100,
		20,
		PokemonType::Water,
		BattleEffectGroup::ActionPriority,
		1,
		100)
	});

	_skillContainer.insert({ L"���������", new Skill(
		L"���������",
		SkillGroup::Attack,
		35,
		85,
		15,
		PokemonType::Water,
		BattleEffectGroup::None,
		1,
		100)
	});

	_skillContainer.insert({ L"��ǰ����", new Skill(
		L"��ǰ����",
		SkillGroup::Attack,
		65,
		100,
		20,
		PokemonType::Water,
		BattleEffectGroup::SPERankDown,
		1,
		10)
	});

	_skillContainer.insert({ L"����������", new Skill(
		L"����������",
		SkillGroup::Attack,
		80,
		100,
		15,
		PokemonType::Water,
		BattleEffectGroup::Flinch,
		1,
		20)
	});

	_skillContainer.insert({ L"�����ĵ�", new Skill(
		L"�����ĵ�",
		SkillGroup::Attack,
		60,
		100,
		20,
		PokemonType::Water,
		BattleEffectGroup::Confusion,
		1,
		20)
	});

	_skillContainer.insert({ L"���������", new Skill(
		L"���������",
		SkillGroup::Attack,
		90,
		90,
		10,
		PokemonType::Water,
		BattleEffectGroup::None,
		1,
		20)
	});

	_skillContainer.insert({ L"�ĵ�Ÿ��", new Skill(
		L"�ĵ�Ÿ��",
		SkillGroup::Attack,
		90,
		100,
		15,
		PokemonType::Water,
		BattleEffectGroup::None,
		1,
		20)
	});

	_skillContainer.insert({ L"���̵������", new Skill(
		L"���̵������",
		SkillGroup::Attack,
		110,
		80,
		5,
		PokemonType::Water,
		BattleEffectGroup::None,
		1,
		20)
	});

	_skillContainer.insert({ L"���̵��ĳ��", new Skill(
		L"���̵��ĳ��",
		SkillGroup::Attack,
		150,
		90,
		5,
		PokemonType::Water,
		BattleEffectGroup::Recoil,
		1,
		100)
	});

	_skillContainer.insert({ L"��ġ��", new Skill(
		L"��ġ��",
		SkillGroup::Attack,
		40,
		100,
		35,
		PokemonType::Normal,
		BattleEffectGroup::None,
		1,
		100)
	});

	_skillContainer.insert({ L"���ӻ�ġ��", new Skill(
		L"���ӻ�ġ��",
		SkillGroup::Attack,
		15,
		85,
		10,
		PokemonType::Normal,
		BattleEffectGroup::Continue,
		1,
		100)
	});

	_skillContainer.insert({ L"������", new Skill(
	L"������",
	SkillGroup::Attack,
	40,
	100,
	35,
	PokemonType::Normal,
	BattleEffectGroup::None,
	1,
	100)
	});

	_skillContainer.insert({ L"Ǯ����", new Skill(
	L"Ǯ����",
	SkillGroup::Attack,
	50,
	95,
	30,
	PokemonType::Normal,
	BattleEffectGroup::None,
	1,
	100)
	});

	_skillContainer.insert({ L"�����ġ��", new Skill(
	L"�����ġ��",
	SkillGroup::Attack,
	40,
	100,
	35,
	PokemonType::Normal,
	BattleEffectGroup::None,
	1,
	100)
	});

	_skillContainer.insert({ L"��������", new Skill(
	L"��������",
	SkillGroup::Status,
	0,
	100,
	30,
	PokemonType::Normal,
	BattleEffectGroup::DEFRankDown,
	1,
	100)
	});

	_skillContainer.insert({ L"°������", new Skill(
	L"°������",
	SkillGroup::Status,
	0,
	100,
	30,
	PokemonType::Normal,
	BattleEffectGroup::DEFRankDown,
	1,
	100)
	});

	_skillContainer.insert({ L"�����Ҹ�", new Skill(
	L"�����Ҹ�",
	SkillGroup::Status,
	0,
	100,
	40,
	PokemonType::Normal,
	BattleEffectGroup::AtkRankDown,
	1,
	100)
	});

	_skillContainer.insert({ L"������ȭ", new Skill(
	L"������ȭ",
	SkillGroup::Attack,
	40,
	100,
	30,
	PokemonType::Normal,
	BattleEffectGroup::ActionPriority,
	1,
	100)
	});

	_skillContainer.insert({ L"����", new Skill(
	L"����",
	SkillGroup::Attack,
	90,
	85,
	20,
	PokemonType::Normal,
	BattleEffectGroup::DamageRecoil,
	4,
	100)
	});

	_skillContainer.insert({ L"������", new Skill(
	L"������",
	SkillGroup::Attack,
	85,
	100,
	15,
	PokemonType::Normal,
	BattleEffectGroup::Paralysis,
	0,
	30)
	});

	_skillContainer.insert({ L"��ġ��", new Skill(
	L"��ġ��",
	SkillGroup::Attack,
	70,
	100,
	15,
	PokemonType::Normal,
	BattleEffectGroup::Flinch,
	0,
	30)
	});

	_skillContainer.insert({ L"����ġ��", new Skill(
	L"����ġ��",
	SkillGroup::Attack,
	80,
	75,
	20,
	PokemonType::Normal,
	BattleEffectGroup::None,
	0,
	30)
	});

	_skillContainer.insert({ L"�ް�����ġ", new Skill(
	L"�ް�����ġ",
	SkillGroup::Attack,
	80,
	85,
	20,
	PokemonType::Normal,
	BattleEffectGroup::None,
	0,
	30)
	});

	_skillContainer.insert({ L"���ǵ彺Ÿ", new Skill(
	L"���ǵ彺Ÿ",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Normal,
	BattleEffectGroup::None,
	0,
	30)
	});

	_skillContainer.insert({ L"������", new Skill(
	L"������",
	SkillGroup::Attack,
	250,
	100,
	5,
	PokemonType::Normal,
	BattleEffectGroup::DeadRecoil,
	0,
	100)
	});

	_skillContainer.insert({ L"����", new Skill(
	L"����",
	SkillGroup::Attack,
	200,
	100,
	5,
	PokemonType::Normal,
	BattleEffectGroup::DeadRecoil,
	0,
	100)
	});

	_skillContainer.insert({ L"�ı�����", new Skill(
	L"�ı�����",
	SkillGroup::Attack,
	150,
	90,
	5,
	PokemonType::Normal,
	BattleEffectGroup::Recoil,
	0,
	100)
	});

	_skillContainer.insert({ L"���ǻ�����Ŭ", new Skill(
	L"���ǻ�����Ŭ",
	SkillGroup::Attack,
	120,
	100,
	15,
	PokemonType::Normal,
	BattleEffectGroup::DamageRecoil,
	3,
	100)
	});

	_skillContainer.insert({ L"�ް���ű", new Skill(
	L"�ް���ű",
	SkillGroup::Attack,
	120,
	75,
	5,
	PokemonType::Normal,
	BattleEffectGroup::None,
	3,
	100)
	});

	_skillContainer.insert({ L"�±Ǵ��", new Skill(
	L"�±Ǵ��",
	SkillGroup::Attack,
	50,
	100,
	25,
	PokemonType::Fighting,
	BattleEffectGroup::Critical,
	1,
	100)
	});

	_skillContainer.insert({ L"������ġ", new Skill(
	L"������ġ",
	SkillGroup::Attack,
	40,
	100,
	30,
	PokemonType::Fighting,
	BattleEffectGroup::ActionPriority,
	1,
	100)
	});

	_skillContainer.insert({ L"��������", new Skill(
	L"��������",
	SkillGroup::Attack,
	40,
	100,
	15,
	PokemonType::Fighting,
	BattleEffectGroup::DEFRankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"�߰�", new Skill(
	L"�߰�",
	SkillGroup::Attack,
	60,
	100,
	10,
	PokemonType::Fighting,
	BattleEffectGroup::Paralysis,
	1,
	30)
		});

	_skillContainer.insert({ L"�׷ο���ġ", new Skill(
	L"�׷ο���ġ",
	SkillGroup::Attack,
	40,
	100,
	20,
	PokemonType::Fighting,
	BattleEffectGroup::MyAtkUp,
	1,
	100)
		});

	_skillContainer.insert({ L"��ű", new Skill(
	L"��ű",
	SkillGroup::Attack,
	65,
	100,
	20,
	PokemonType::Fighting,
	BattleEffectGroup::SPERankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"�巹����ġ", new Skill(
	L"�巹����ġ",
	SkillGroup::Attack,
	75	,
	100,
	10,
	PokemonType::Fighting,
	BattleEffectGroup::Drain,
	2,
	100)
		});

	_skillContainer.insert({ L"�ĵ�ź", new Skill(
	L"�ĵ�ź",
	SkillGroup::Attack,
	80	,
	100,
	20,
	PokemonType::Fighting,
	BattleEffectGroup::None,
	2,
	100)
		});

	_skillContainer.insert({ L"��ī�̾���", new Skill(
	L"��ī�̾���",
	SkillGroup::Attack,
	85	,
	90,
	15,
	PokemonType::Fighting,
	BattleEffectGroup::None,
	2,
	100)
		});

	_skillContainer.insert({ L"���ձ���", new Skill(
	L"���ձ���",
	SkillGroup::Attack,
	120	,
	70,
	5,
	PokemonType::Fighting,
	BattleEffectGroup::DEFRankDown,
	1,
	10)
		});

	_skillContainer.insert({ L"���ظ�", new Skill(
	L"���ظ�",
	SkillGroup::Attack,
	100	,
	90,
	10,
	PokemonType::Fighting,
	BattleEffectGroup::SPERankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"��û����", new Skill(
	L"��û����",
	SkillGroup::Attack,
	120	,
	100,
	5,
	PokemonType::Fighting,
	BattleEffectGroup::MyA_DDown,
	1,
	100)
		});

	_skillContainer.insert({ L"������ġ", new Skill(
	L"������ġ",
	SkillGroup::Attack,
	150	,
	100,
	20,
	PokemonType::Fighting,
	BattleEffectGroup::ActionPriority,
	5,
	100)
		});

	_skillContainer.insert({ L"�𷡻Ѹ���", new Skill(
	L"�𷡻Ѹ���",
	SkillGroup::Status,
	0,
	100,
	15,
	PokemonType::Ground,
	BattleEffectGroup::AccuracyDown,
	1,
	100)
		});

	_skillContainer.insert({ L"����Ѹ���", new Skill(
	L"����Ѹ���",
	SkillGroup::Attack,
	20,
	100,
	10,
	PokemonType::Ground,
	BattleEffectGroup::AccuracyDown,
	1,
	100)
		});

	_skillContainer.insert({ L"�ӵ��", new Skill(
	L"�ӵ��",
	SkillGroup::Attack,
	55,
	95,
	15,
	PokemonType::Ground,
	BattleEffectGroup::SPERankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"������", new Skill(
	L"������",
	SkillGroup::Attack,
	25,
	90,
	10,
	PokemonType::Ground,
	BattleEffectGroup::Continue,
	1,
	100)
		});

	_skillContainer.insert({ L"���ٱ�ġ��", new Skill(
	L"���ٱ�ġ��",
	SkillGroup::Attack,
	65,
	85,
	10,
	PokemonType::Ground,
	BattleEffectGroup::Flinch,
	1,
	10)
		});

	_skillContainer.insert({ L"������", new Skill(
	L"������",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Ground,
	BattleEffectGroup::SPERankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"������ź", new Skill(
	L"������ź",
	SkillGroup::Attack,
	65,
	85,
	10,
	PokemonType::Ground,
	BattleEffectGroup::AccuracyDown,
	1,
	30)
		});

	_skillContainer.insert({ L"�����ǹ߱�����", new Skill(
	L"�����ǹ߱�����",
	SkillGroup::Attack,
	75,
	100,
	10,
	PokemonType::Ground,
	BattleEffectGroup::None,
	1,
	30)
		});

	_skillContainer.insert({ L"10������", new Skill(
	L"10������",
	SkillGroup::Attack,
	95,
	95,
	10,
	PokemonType::Ground,
	BattleEffectGroup::None,
	1,
	30)
		});

	_skillContainer.insert({ L"�帱���̳�", new Skill(
	L"�帱���̳�",
	SkillGroup::Attack,
	80,
	95,
	10,
	PokemonType::Ground,
	BattleEffectGroup::Critical,
	1,
	100)
		});

	_skillContainer.insert({ L"��������", new Skill(
	L"��������",
	SkillGroup::Attack,
	90,
	100,
	10,
	PokemonType::Ground,
	BattleEffectGroup::DEFRankDown,
	1,
	10)
		});

	_skillContainer.insert({ L"����", new Skill(
	L"����",
	SkillGroup::Attack,
	100,
	100,
	10,
	PokemonType::Ground,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"����߸���", new Skill(
	L"����߸���",
	SkillGroup::Attack,
	50,
	100,
	15,
	PokemonType::Rock,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"������Ʈ", new Skill(
	L"������Ʈ",
	SkillGroup::Attack,
	25,
	90,
	10,
	PokemonType::Rock,
	BattleEffectGroup::Continue,
	1,
	100)
		});

	_skillContainer.insert({ L"��������", new Skill(
	L"��������",
	SkillGroup::Attack,
	60,
	100,
	5,
	PokemonType::Rock,
	BattleEffectGroup::MyStatAllUp,
	1,
	10)
		});

	_skillContainer.insert({ L"��������", new Skill(
	L"��������",
	SkillGroup::Attack,
	50,
	90,
	20,
	PokemonType::Rock,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"�ϼ�����", new Skill(
	L"�ϼ�����",
	SkillGroup::Attack,
	60,
	95,
	15,
	PokemonType::Rock,
	BattleEffectGroup::SPERankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"�������", new Skill(
	L"�������",
	SkillGroup::Attack,
	75,
	90,
	10,
	PokemonType::Rock,
	BattleEffectGroup::Flinch,
	1,
	30)
		});

	_skillContainer.insert({ L"�Ŀ���", new Skill(
	L"�Ŀ���",
	SkillGroup::Attack,
	80,
	100,
	20,
	PokemonType::Rock,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"�ϼ���", new Skill(
	L"�ϼ���",
	SkillGroup::Attack,
	150,
	90,
	5,
	PokemonType::Rock,
	BattleEffectGroup::Recoil,
	1,
	100)
		});

	_skillContainer.insert({ L"���濡��", new Skill(
	L"���濡��",
	SkillGroup::Attack,
	100,
	80,
	5,
	PokemonType::Rock,
	BattleEffectGroup::Critical,
	1,
	100)
		});

	_skillContainer.insert({ L"�糯��ġ��", new Skill(
	L"�糯��ġ��",
	SkillGroup::Attack,
	150,
	80,
	5,
	PokemonType::Rock,
	BattleEffectGroup::DamageRecoil,
	2,
	100)
		});

	_skillContainer.insert({ L"�����ũ", new Skill(
	L"�����ũ",
	SkillGroup::Attack,
	40,
	100,
	30,
	PokemonType::Electric,
	BattleEffectGroup::Paralysis,
	2,
	10)
		});

	_skillContainer.insert({ L"����ũ", new Skill(
	L"����ũ",
	SkillGroup::Attack,
	65,
	100,
	20,
	PokemonType::Electric,
	BattleEffectGroup::Paralysis,
	2,
	30)
		});

	_skillContainer.insert({ L"������", new Skill(
	L"������",
	SkillGroup::Attack,
	50,
	90,
	10,
	PokemonType::Electric,
	BattleEffectGroup::MyAtkUp,
	1,
	70)
		});

	_skillContainer.insert({ L"�Ϸ�Ʈ����Ʈ", new Skill(
	L"�Ϸ�Ʈ����Ʈ",
	SkillGroup::Attack,
	55,
	95,
	15,
	PokemonType::Electric,
	BattleEffectGroup::SPERankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"������", new Skill(
	L"������",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Electric,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"������ġ", new Skill(
	L"������ġ",
	SkillGroup::Attack,
	75,
	100,
	15,
	PokemonType::Electric,
	BattleEffectGroup::Paralysis,
	1,
	10)
		});

	_skillContainer.insert({ L"10����Ʈ", new Skill(
	L"10����Ʈ",
	SkillGroup::Attack,
	90,
	100,
	15,
	PokemonType::Electric,
	BattleEffectGroup::Paralysis,
	1,
	10)
		});

	_skillContainer.insert({ L"����", new Skill(
	L"����",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Electric,
	BattleEffectGroup::Paralysis,
	1,
	30)
		});

	_skillContainer.insert({ L"���ϵ庼Ʈ", new Skill(
	L"���ϵ庼Ʈ",
	SkillGroup::Attack,
	90,
	100,
	15,
	PokemonType::Electric,
	BattleEffectGroup::DamageRecoil,
	4,
	100)
		});

	_skillContainer.insert({ L"��Ʈ��Ŭ", new Skill(
	L"��Ʈ��Ŭ",
	SkillGroup::Attack,
	120,
	100,
	15,
	PokemonType::Electric,
	BattleEffectGroup::DamageRecoil,
	3,
	100)
		});

	_skillContainer.insert({ L"������", new Skill(
	L"������",
	SkillGroup::Attack,
	120,
	50,
	5,
	PokemonType::Electric,
	BattleEffectGroup::Paralysis,
	3,
	100)
		});

	_skillContainer.insert({ L"����", new Skill(
	L"����",
	SkillGroup::Attack,
	110,
	70,
	10,
	PokemonType::Electric,
	BattleEffectGroup::Paralysis,
	3,
	30)
		});

	_skillContainer.insert({ L"ȯ���", new Skill(
	L"ȯ���",
	SkillGroup::Attack,
	65,
	100,
	20,
	PokemonType::Psychic,
	BattleEffectGroup::Confusion,
	3,
	10)
		});

	_skillContainer.insert({ L"������", new Skill(
	L"������",
	SkillGroup::Attack,
	50,
	100,
	25,
	PokemonType::Psychic,
	BattleEffectGroup::Confusion,
	3,
	10)
		});

	_skillContainer.insert({ L"����̵�", new Skill(
	L"����̵�",
	SkillGroup::Status,
	0,
	100,
	30,
	PokemonType::Psychic,
	BattleEffectGroup::MySEPUp,
	3,
	100)
		});

	_skillContainer.insert({ L"��Ʈ������", new Skill(
	L"��Ʈ������",
	SkillGroup::Attack,
	60,
	100,
	25,
	PokemonType::Psychic,
	BattleEffectGroup::Flinch,
	3,
	30)
		});

	_skillContainer.insert({ L"��������", new Skill(
	L"��������",
	SkillGroup::Attack,
	85,
	100,
	10,
	PokemonType::Psychic,
	BattleEffectGroup::None,
	3,
	100)
		});

	_skillContainer.insert({ L"�����ڼ�ũ", new Skill(
	L"�����ڼ�ũ",
	SkillGroup::Attack,
	80,
	100,
	10,
	PokemonType::Psychic,
	BattleEffectGroup::None,
	3,
	100)
		});

	_skillContainer.insert({ L"����ǹ�ġ��", new Skill(
	L"����ǹ�ġ��",
	SkillGroup::Attack,
	80,
	90,
	15,
	PokemonType::Psychic,
	BattleEffectGroup::Flinch,
	3,
	20)
		});

	_skillContainer.insert({ L"������Ŀ��", new Skill(
	L"������Ŀ��",
	SkillGroup::Attack,
	70,
	100,
	20,
	PokemonType::Psychic,
	BattleEffectGroup::Critical,
	3,
	100)
		});

	_skillContainer.insert({ L"�����", new Skill(
	L"�����",
	SkillGroup::Attack,
	80,
	100,
	20,
	PokemonType::Psychic,
	BattleEffectGroup::Critical,
	3,
	10)
		});

	_skillContainer.insert({ L"������Ű�׽ý�", new Skill(
	L"������Ű�׽ý�",
	SkillGroup::Attack,
	90,
	100,
	10,
	PokemonType::Psychic,
	BattleEffectGroup::DEFRankDown,
	1,
	10)
		});

	_skillContainer.insert({ L"���ζ��", new Skill(
	L"���ζ��",
	SkillGroup::Attack,
	40,
	100,
	25,
	PokemonType::Ice,
	BattleEffectGroup::Freeze,
	1,
	10)
		});

	_skillContainer.insert({ L"��帧ħ", new Skill(
	L"��帧ħ",
	SkillGroup::Attack,
	25,
	100,
	30,
	PokemonType::Ice,
	BattleEffectGroup::Continue,
	1,
	100)
		});

	_skillContainer.insert({ L"������ġ", new Skill(
	L"������ġ",
	SkillGroup::Attack,
	40,
	100,
	30,
	PokemonType::Ice,
	BattleEffectGroup::ActionPriority,
	1,
	100)
		});

	_skillContainer.insert({ L"��������", new Skill(
	L"��������",
	SkillGroup::Attack,
	65,
	95,
	15,
	PokemonType::Ice,
	BattleEffectGroup::Freeze,
	1,
	10)
		});

	_skillContainer.insert({ L"����������", new Skill(
	L"����������",
	SkillGroup::Attack,
	70,
	100,
	20,
	PokemonType::Ice,
	BattleEffectGroup::Freeze,
	1,
	10)
		});

	_skillContainer.insert({ L"�õ���ġ", new Skill(
	L"�õ���ġ",
	SkillGroup::Attack,
	75,
	100,
	15,
	PokemonType::Ice,
	BattleEffectGroup::Freeze,
	1,
	10)
		});

	_skillContainer.insert({ L"��帧������", new Skill(
	L"��帧������",
	SkillGroup::Attack,
	85,
	90,
	10,
	PokemonType::Ice,
	BattleEffectGroup::Flinch,
	1,
	30)
		});

	_skillContainer.insert({ L"���̽��ظ�", new Skill(
	L"���̽��ظ�",
	SkillGroup::Attack,
	100,
	90,
	10,
	PokemonType::Ice,
	BattleEffectGroup::MySPEDown,
	1,
	100)
		});

	_skillContainer.insert({ L"������", new Skill(
	L"������",
	SkillGroup::Attack,
	110,
	70,
	5,
	PokemonType::Ice,
	BattleEffectGroup::Freeze,
	1,
	10)
		});

	_skillContainer.insert({ L"�õ���", new Skill(
	L"�õ���",
	SkillGroup::Attack,
	90,
	100,
	10,
	PokemonType::Ice,
	BattleEffectGroup::Freeze,
	1,
	10)
		});

	_skillContainer.insert({ L"���󰡶�����", new Skill(
	L"���󰡶�����",
	SkillGroup::Attack,
	40,
	100,
	20,
	PokemonType::Dark,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"Ź�ļ�������", new Skill(
	L"Ź�ļ�������",
	SkillGroup::Attack,
	65,
	100,
	20,
	PokemonType::Dark,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"�ºα�����", new Skill(
	L"�ºα�����",
	SkillGroup::Attack,
	60,
	100,
	10,
	PokemonType::Dark,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"��ũ�ƿ�", new Skill(
	L"��ũ�ƿ�",
	SkillGroup::Attack,
	55,
	95,
	15,
	PokemonType::Dark,
	BattleEffectGroup::AtkRankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"�������ֵθ���", new Skill(
	L"�������ֵθ���",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Dark,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"�������", new Skill(
	L"�������",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Dark,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"����Ʈ����Ʈ", new Skill(
	L"����Ʈ����Ʈ",
	SkillGroup::Attack,
	85,
	95,
	10,
	PokemonType::Dark,
	BattleEffectGroup::AccuracyDown,
	1,
	40)
		});

	_skillContainer.insert({ L"������μ���", new Skill(
	L"������μ���",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Dark,
	BattleEffectGroup::DEFRankDown,
	1,
	20)
		});

	_skillContainer.insert({ L"�ٶ�����Ű��", new Skill(
	L"�ٶ�����Ű��",
	SkillGroup::Attack,
	40,
	100,
	35,
	PokemonType::Flying,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"����ġ��", new Skill(
	L"����ġ��",
	SkillGroup::Attack,
	60,
	100,
	35,
	PokemonType::Flying,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"��������", new Skill(
	L"��������",
	SkillGroup::Attack,
	60,
	95,
	25,
	PokemonType::Flying,
	BattleEffectGroup::Critical,
	1,
	100)
		});

	_skillContainer.insert({ L"�ɱ�", new Skill(
	L"�ɱ�",
	SkillGroup::Attack,
	35,
	100,
	35,
	PokemonType::Flying,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"ȸ���θ�", new Skill(
	L"ȸ���θ�",
	SkillGroup::Attack,
	35,
	100,
	35,
	PokemonType::Flying,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"�����ȯ", new Skill(
	L"�����ȯ",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Flying,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"�ɾƴ��", new Skill(
	L"�ɾƴ��",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Flying,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"�������", new Skill(
	L"�������",
	SkillGroup::Attack,
	75,
	95,
	15,
	PokemonType::Flying,
	BattleEffectGroup::Flinch,
	1,
	30)
		});

	_skillContainer.insert({ L"��ǳ", new Skill(
	L"��ǳ",
	SkillGroup::Attack,
	110,
	70,
	10,
	PokemonType::Flying,
	BattleEffectGroup::Confusion,
	1,
	30)
		});

	_skillContainer.insert({ L"��ũ����", new Skill(
	L"��ũ����",
	SkillGroup::Attack,
	55,
	100,
	15,
	PokemonType::Flying,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"�극�̺����", new Skill(
	L"�극�̺����",
	SkillGroup::Attack,
	120,
	100,
	15,
	PokemonType::Flying,
	BattleEffectGroup::DamageRecoil,
	3,
	100)
		});

	_skillContainer.insert({ L"����ϵ�", new Skill(
	L"����ϵ�",
	SkillGroup::Attack,
	25,
	100,
	20,
	PokemonType::Bug,
	BattleEffectGroup::None,
	3,
	100)
		});

	_skillContainer.insert({ L"�����ڸ���", new Skill(
	L"�����ڸ���",
	SkillGroup::Attack,
	40,
	95,
	20,
	PokemonType::Bug,
	BattleEffectGroup::None,
	3,
	100)
		});

	_skillContainer.insert({ L"�����ٶ�", new Skill(
	L"�����ٶ�",
	SkillGroup::Attack,
	60,
	100,
	5,
	PokemonType::Bug,
	BattleEffectGroup::MyStatAllUp,
	3,
	10)
		});

	_skillContainer.insert({ L"����������", new Skill(
	L"����������",
	SkillGroup::Attack,
	50,
	100,
	20,
	PokemonType::Bug,
	BattleEffectGroup::AtkRankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"�����Ǿߴܹ���", new Skill(
	L"�����Ǿߴܹ���",
	SkillGroup::Attack,
	90,
	100,
	10,
	PokemonType::Bug,
	BattleEffectGroup::AtkRankDown,
	1,
	10)
		});

	_skillContainer.insert({ L"����ũ�ν�", new Skill(
	L"����ũ�ν�",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Bug,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"�ñ׳κ�", new Skill(
	L"�ñ׳κ�",
	SkillGroup::Attack,
	75,
	100,
	15,
	PokemonType::Bug,
	BattleEffectGroup::Confusion,
	1,
	10)
		});

	_skillContainer.insert({ L"����", new Skill(
	L"����",
	SkillGroup::Attack,
	80,
	100,
	10,
	PokemonType::Bug,
	BattleEffectGroup::Drain,
	2,
	100)
		});

	_skillContainer.insert({ L"�ް���", new Skill(
	L"�ް���",
	SkillGroup::Attack,
	120,
	85,
	10,
	PokemonType::Bug,
	BattleEffectGroup::None,
	2,
	100)
		});

	_skillContainer.insert({ L"�������", new Skill(
	L"�������",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Bug,
	BattleEffectGroup::AtkRankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"���Ǽ���", new Skill(
	L"���Ǽ���",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Dragon,
	BattleEffectGroup::Paralysis,
	1,
	30)
		});

	_skillContainer.insert({ L"ȸ����", new Skill(
	L"ȸ����",
	SkillGroup::Attack,
	40,
	100,
	20,
	PokemonType::Dragon,
	BattleEffectGroup::Flinch,
	1,
	20)
		});

	_skillContainer.insert({ L"������", new Skill(
	L"������",
	SkillGroup::Attack,
	40,
	90,
	15,
	PokemonType::Dragon,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"�巡������", new Skill(
	L"�巡������",
	SkillGroup::Attack,
	60,
	90,
	10,
	PokemonType::Dragon,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"�����ĵ�", new Skill(
	L"�����ĵ�",
	SkillGroup::Attack,
	85,
	100,
	10,
	PokemonType::Dragon,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"�巡��ũ��", new Skill(
	L"�巡��ũ��",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Dragon,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"������", new Skill(
	L"������",
	SkillGroup::Status,
	0,
	100,
	20,
	PokemonType::Dragon,
	BattleEffectGroup::MyA_SUp,
	1,
	100)
		});

	_skillContainer.insert({ L"����", new Skill(
	L"����",
	SkillGroup::Attack,
	120,
	100,
	10,
	PokemonType::Dragon,
	BattleEffectGroup::MyConfusion,
	1,
	100)
		});

	_skillContainer.insert({ L"�巡����̺�", new Skill(
	L"�巡����̺�",
	SkillGroup::Attack,
	100,
	75,
	10,
	PokemonType::Dragon,
	BattleEffectGroup::Flinch,
	1,
	20)
		});

	_skillContainer.insert({ L"�뼺��", new Skill(
	L"�뼺��",
	SkillGroup::Attack,
	130,
	90,
	5,
	PokemonType::Dragon,
	BattleEffectGroup::MyAtkDown,
	2,
	20)
		});

	_skillContainer.insert({ L"��ħ", new Skill(
	L"��ħ",
	SkillGroup::Attack,
	15,
	100,
	35,
	PokemonType::Poison,
	BattleEffectGroup::Poison,
	2,
	30)
		});

	_skillContainer.insert({ L"���ؾ�", new Skill(
	L"���ؾ�",
	SkillGroup::Attack,
	40,
	100,
	30,
	PokemonType::Poison,
	BattleEffectGroup::DEFRankDown,
	2,
	10)
		});

	_skillContainer.insert({ L"������", new Skill(
	L"������",
	SkillGroup::Attack,
	50,
	100,
	15,
	PokemonType::Poison,
	BattleEffectGroup::Poison,
	2,
	50)
		});

	_skillContainer.insert({ L"����������", new Skill(
	L"����������",
	SkillGroup::Attack,
	50,
	100,
	25,
	PokemonType::Poison,
	BattleEffectGroup::Poison,
	2,
	10)
		});

	_skillContainer.insert({ L"ũ�ν�������", new Skill(
	L"ũ�ν�������",
	SkillGroup::Attack,
	70,
	100,
	20,
	PokemonType::Poison,
	BattleEffectGroup::Poison,
	2,
	10)
		});

	_skillContainer.insert({ L"������ź", new Skill(
	L"������ź",
	SkillGroup::Attack,
	90,
	100,
	10,
	PokemonType::Poison,
	BattleEffectGroup::Poison,
	2,
	30)
		});

	_skillContainer.insert({ L"�������̺�", new Skill(
	L"�������̺�",
	SkillGroup::Attack,
	95,
	100,
	10,
	PokemonType::Poison,
	BattleEffectGroup::Poison,
	2,
	10)
		});

	_skillContainer.insert({ L"Ʈ��", new Skill(
	L"Ʈ��",
	SkillGroup::Attack,
	120,
	90,
	10,
	PokemonType::Poison,
	BattleEffectGroup::None,
	2,
	100)
		});

	_skillContainer.insert({ L"����Ʈ��Ʈ", new Skill(
	L"����Ʈ��Ʈ",
	SkillGroup::Attack,
	120,
	80,
	5,
	PokemonType::Poison,
	BattleEffectGroup::Poison,
	2,
	30)
		});

	_skillContainer.insert({ L"����Ʈ���", new Skill(
	L"����Ʈ���",
	SkillGroup::Attack,
	0,
	100,
	5,
	PokemonType::Ghost,
	BattleEffectGroup::LvDamage,
	1,
	100)
		});

	_skillContainer.insert({ L"�ӱ�", new Skill(
	L"�ӱ�",
	SkillGroup::Attack,
	30,
	100,
	30,
	PokemonType::Ghost,
	BattleEffectGroup::Paralysis,
	1,
	30)
		});

	_skillContainer.insert({ L"�Ű��", new Skill(
	L"�Ű��",
	SkillGroup::Attack,
	30,
	100,
	15,
	PokemonType::Ghost,
	BattleEffectGroup::Flinch,
	1,
	30)
		});

	_skillContainer.insert({ L"�߽�", new Skill(
	L"�߽�",
	SkillGroup::Attack,
	40,
	100,
	30,
	PokemonType::Ghost,
	BattleEffectGroup::ActionPriority,
	1,
	100)
		});

	_skillContainer.insert({ L"������ġ", new Skill(
	L"������ġ",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Ghost,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"����÷��", new Skill(
	L"����÷��",
	SkillGroup::Attack,
	65,
	100,
	10,
	PokemonType::Ghost,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"����ũ��", new Skill(
	L"����ũ��",
	SkillGroup::Attack,
	70,
	100,
	15,
	PokemonType::Ghost,
	BattleEffectGroup::Critical,
	1,
	100)
		});

	_skillContainer.insert({ L"������", new Skill(
	L"������",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Ghost,
	BattleEffectGroup::DEFRankDown,
	1,
	20)
		});

	_skillContainer.insert({ L"�����ѹٶ�", new Skill(
	L"�����ѹٶ�",
	SkillGroup::Attack,
	60,
	100,
	5,
	PokemonType::Ghost,
	BattleEffectGroup::MyStatAllUp,
	1,
	100)
		});

	_skillContainer.insert({ L"��Żũ�ο�", new Skill(
	L"��Żũ�ο�",
	SkillGroup::Attack,
	50,
	95,
	35,
	PokemonType::Steel,
	BattleEffectGroup::MyAtkDown,
	1,
	10)
		});

	_skillContainer.insert({ L"�Ҹ���ġ", new Skill(
	L"�Ҹ���ġ",
	SkillGroup::Attack,
	40,
	100,
	30,
	PokemonType::Steel,
	BattleEffectGroup::ActionPriority,
	1,
	100)
		});

	_skillContainer.insert({ L"���Ҽ�", new Skill(
	L"���Ҽ�",
	SkillGroup::Attack,
	50,
	85,
	10,
	PokemonType::Steel,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"���׳ݺ�", new Skill(
	L"���׳ݺ�",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Steel,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"���̾����", new Skill(
	L"���̾����",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Steel,
	BattleEffectGroup::Flinch,
	1,
	30)
		});

	_skillContainer.insert({ L"������ĳ��", new Skill(
	L"������ĳ��",
	SkillGroup::Attack,
	80,
	100,
	10,
	PokemonType::Steel,
	BattleEffectGroup::DEFRankDown,
	1,
	10)
		});

	_skillContainer.insert({ L"�̷���", new Skill(
	L"�̷���",
	SkillGroup::Attack,
	65,
	85,
	10,
	PokemonType::Steel,
	BattleEffectGroup::AccuracyDown,
	1,
	30)
		});

	_skillContainer.insert({ L"�ڸ���ġ", new Skill(
	L"�ڸ���ġ",
	SkillGroup::Attack,
	90,
	90,
	10,
	PokemonType::Steel,
	BattleEffectGroup::MyAtkUp,
	1,
	20)
		});

	_skillContainer.insert({ L"���̾�����", new Skill(
	L"���̾�����",
	SkillGroup::Attack,
	100,
	75,
	15,
	PokemonType::Steel,
	BattleEffectGroup::DEFRankDown,
	1,
	30)
		});

	_skillContainer.insert({ L"��ö����", new Skill(
	L"��ö����",
	SkillGroup::Attack,
	70,
	90,
	25,
	PokemonType::Steel,
	BattleEffectGroup::MyDEFUp,
	1,
	10)
		});
}

vector<wstring> SkillManager::LearnSkill(vector<PokemonType> types, int evolutionCount)
{

	int len = 4 / types.size();
	vector<wstring> result;

	for (int k = 0; k < types.size(); k++) {

		auto type = types[k];

		//����� ��������
		auto container = _learnSkillContainer[type][evolutionCount];

		for (int i = 0; i < 1000; i++) {

			int idx1 = rand() % container.size();
			int idx2 = rand() % container.size();

			std::swap(container[idx1], container[idx2]);

		}

		for (int i = 0; i < len; i++) {


			result.push_back(container[i]);

		}

	}

	return result;

}