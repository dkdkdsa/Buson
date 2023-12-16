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

		{1, {L"����", L"�ٳ�������", L"����ä��", L"������", L"�ް��巹��"}},
		{2, {L"����", L"�ٳ�������", L"����ä��", L"������", L"�ް��巹��", L"�Ⱑ�巹��", L"�����", L"�����ø���", L"���ȣ��", L"�׷����ͼ�", L"��������", L"���������̵�"}},
		{3, {L"����", L"�ٳ�������", L"����ä��", L"������", L"�ް��巹��", L"�Ⱑ�巹��", L"�����", L"�����ø���", L"���ȣ��", L"�׷����ͼ�", L"��������", L"���������̵�", L"�ϵ��÷�Ʈ", L"��������", L"�Ŀ���", L"����ظ�"}}

	};

	_learnSkillContainer.insert({ PokemonType::Grass, grass });

	map<int, vector<wstring>> fire
	{
		{1, {L"�Ҳɼ���", L"��Ʈ������", L"�������÷���", L"���¿��", L"�Ҳɾ���"}},
		{2, {L"�Ҳɼ���", L"��Ʈ������", L"�������÷���", L"���¿��", L"�Ҳɾ���", L"�Ҳ���ġ", L"ȭ���ڵ���", L"�극����ű", L"��ǳ", L"ȭ�����"}},
		{3, {L"�Ҳɼ���", L"��Ʈ������", L"�������÷���", L"���¿��", L"�Ҳɾ���", L"�Ҳ���ġ", L"ȭ���ڵ���", L"�극����ű", L"��ǳ", L"ȭ�����", L"�Ҵ빮��", L"������Ʈ��", L"������Ʈ", L"�÷������̺�"}}
	};

	_learnSkillContainer.insert({ PokemonType::Fire, fire });

	map<int, vector<wstring>> water
	{
		{1, {L"������", L"��ǰ", L"��������Ʈ", L"���������"}},
		{2, {L"������", L"��ǰ", L"��������Ʈ", L"���������", L"��ǰ����", L"����������", L"���̺�", L"�����ĵ�", L"����������", L"�ĵ�Ÿ��"}},
		{3, {L"������", L"��ǰ", L"��������Ʈ", L"���������", L"��ǰ����", L"����������", L"���̺�", L"�����ĵ�", L"����������", L"�ĵ�Ÿ��", L"���̵������", L"���̵��ĳ��"}}
	};

	_learnSkillContainer.insert({ PokemonType::Water, water });

	map<int, vector<wstring>> normal
	{
		{1, {L"��ġ��", L"���ӻ�ġ��", L"������", L"Ǯ����", L"�����ġ��", L"��������", L"°������", L"�����Ҹ�", L"������ȭ"}},
		{2, {L"��ġ��", L"���ӻ�ġ��", L"������", L"Ǯ����", L"�����ġ��", L"��������", L"°������", L"�����Ҹ�", L"������ȭ", L"����", L"������", L"��ġ��", L"����ġ��", L"�ް�����ġ", L"���ǵ彺Ÿ"}},
		{3, {L"��ġ��", L"���ӻ�ġ��", L"������", L"Ǯ����", L"�����ġ��", L"��������", L"°������", L"�����Ҹ�", L"������ȭ", L"����", L"������", L"��ġ��", L"����ġ��", L"�ް�����ġ", L"���ǵ彺Ÿ", L"������", L"����Ʈ��ġ��", L"����", L"�ı�����", L"���ǻ�����Ŭ", L"�ް���ű"}}
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
		{2, {L"�𷡻Ѹ���", L"����Ѹ���", L"�ӵ��", L"������", L"���ٱ�ġ��", L"��������", L"������ź", L"�����ǹ߱�����"}},
		{3, {L"�𷡻Ѹ���", L"����Ѹ���", L"�ӵ��", L"������", L"���ٱ�ġ��", L"��������", L"������ź", L"�����ǹ߱�����", L"10������", L"�帱���̳�", L"��������", L"����"}}
	};

	_learnSkillContainer.insert({ PokemonType::Ground, ground });

	map<int, vector<wstring>> rock
	{
		{1, {L"����߸���", L"��������Ʈ", L"��������", L"��������"}},
		{2, {L"����߸���", L"��������Ʈ", L"��������", L"��������", L"��������", L"�ϼ�����", L"�������", L"�Ŀ���"}},
		{3, {L"����߸���", L"��������Ʈ", L"��������", L"��������", L"��������", L"�ϼ�����", L"�������", L"�Ŀ���", L"�ϼ���", L"���濡��", L"�糯��ġ��"}}
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
		{1, {L"ȯ���", L"������", L"�����̵�", L"��Ʈ������"}},
		{2, {L"ȯ���", L"������", L"�����̵�", L"��Ʈ������", L"��������", L"�����ڼ�ũ", L"����ǹ�ġ��", L"������Ŀ��"}},
		{3, {L"ȯ���", L"������", L"�����̵�", L"��Ʈ������", L"��������", L"�����ڼ�ũ", L"����ǹ�ġ��", L"������Ŀ��", L"�����", L"������Ű�׽ý�"}}
	};

	_learnSkillContainer.insert({ PokemonType::Psychic, psychic });

	map<int, vector<wstring>> ice
	{
		{1, {L"���ζ��", L"���帧ħ", L"������ġ", L"��������"}},
		{2, {L"���ζ��", L"���帧ħ", L"������ġ", L"��������", L"����������", L"�õ���ġ", L"���帧������"}},
		{3, {L"���ζ��", L"���帧ħ", L"������ġ", L"��������", L"����������", L"�õ���ġ", L"���帧������", L"���̽��ظ�", L"������", L"�õ���"}}
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
		{1, {L"�����ϵ�", L"�����ڸ���", L"�����ٶ�", L"����������"}},
		{2, {L"�����ϵ�", L"�����ڸ���", L"�����ٶ�", L"����������", L"�����Ǿߴܹ���", L"����ũ�ν�", L"�ñ׳κ�", L"����"}},
		{3, {L"�����ϵ�", L"�����ڸ���", L"�����ٶ�", L"����������", L"�����Ǿߴܹ���", L"����ũ�ν�", L"�ñ׳κ�", L"����", L"�ް���", L"�������"}}
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

	_learnSkillContainer.insert({ PokemonType::Dragon, poison });

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
	Skill skill;
	skill = Skill(
		L"����",
		SkillGroup::Attack,
		20,
		100,
		25,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"�ٳ�������",
		SkillGroup::Attack,
		55,
		95,
		25,
		PokemonType::Grass,
		BattleEffectGroup::Critical,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"����ä��",
		SkillGroup::Attack,
		45,
		100,
		25,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"������",
		SkillGroup::Attack,
		40,
		100,
		40,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"�ް��巹��",
		SkillGroup::Attack,
		40,
		100,
		15,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"�Ⱑ�巹��",
		SkillGroup::Attack,
		75,
		100,
		10,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"�����",
		SkillGroup::Attack,
		25,
		100,
		30,
		PokemonType::Grass,
		BattleEffectGroup::Continue,
		0,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"�����ø���",
		SkillGroup::Attack,
		60,
		100,
		20,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"���ȣ��",
		SkillGroup::Attack,
		75,
		100,
		10,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"�׷����ͼ�",
		SkillGroup::Attack,
		65,
		90,
		10,
		PokemonType::Grass,
		BattleEffectGroup::DEFRankDown,
		1,
		50
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"��������",
		SkillGroup::Attack,
		90,
		100,
		10,
		PokemonType::Grass,
		BattleEffectGroup::DEFRankDown,
		1,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"���������̵�",
		SkillGroup::Attack,
		90,
		100,
		15,
		PokemonType::Grass,
		BattleEffectGroup::Critical,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"�ϵ��÷�Ʈ",
		SkillGroup::Attack,
		150,
		90,
		5,
		PokemonType::Grass,
		BattleEffectGroup::Recoil,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"��������",
		SkillGroup::Attack,
		130,
		90,
		5,
		PokemonType::Grass,
		BattleEffectGroup::MyAtkDown,
		2,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"�Ŀ���",
		SkillGroup::Attack,
		130,
		85,
		10,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"����ظ�",
		SkillGroup::Attack,
		120,
		100,
		15,
		PokemonType::Grass,
		BattleEffectGroup::DamageRecoil,
		3,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"�Ҳɼ���",
		SkillGroup::Attack,
		40,
		100,
		25,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"��Ʈ������",
		SkillGroup::Attack,
		50,
		100,
		20,
		PokemonType::Fire,
		BattleEffectGroup::MySEPUp,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"�������÷���",
		SkillGroup::Attack,
		75,
		100,
		10,
		PokemonType::Fire,
		BattleEffectGroup::AtkRankDown,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"���¿��",
		SkillGroup::Attack,
		60,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::None,
		0,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"�Ҳɾ���",
		SkillGroup::Attack,
		65,
		95,
		15,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"�Ҳ���ġ",
		SkillGroup::Attack,
		75,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"ȭ���ڵ���",
		SkillGroup::Attack,
		60,
		100,
		25,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"�극����ű",
		SkillGroup::Attack,
		85,
		90,
		10,
		PokemonType::Fire,
		BattleEffectGroup::Critical,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"��ǳ",
		SkillGroup::Attack,
		95,
		90,
		10,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		1,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"ȭ�����",
		SkillGroup::Attack,
		90,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		1,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"�Ҵ빮��",
		SkillGroup::Attack,
		110,
		85,
		5,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		1,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"������Ʈ��",
		SkillGroup::Attack,
		150,
		90,
		5,
		PokemonType::Fire,
		BattleEffectGroup::Recoil,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"������Ʈ",
		SkillGroup::Attack,
		130,
		90,
		5,
		PokemonType::Fire,
		BattleEffectGroup::MyAtkDown,
		2,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"�÷������̺�",
		SkillGroup::Attack,
		120,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::DamageRecoil,
		3,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"������",
		SkillGroup::Attack,
		40,
		100,
		25,
		PokemonType::Water,
		BattleEffectGroup::None,
		3,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"��ǰ",
		SkillGroup::Attack,
		40,
		100,
		30,
		PokemonType::Water,
		BattleEffectGroup::SPERankDown,
		1,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"��������Ʈ",
		SkillGroup::Attack,
		40,
		100,
		20,
		PokemonType::Water,
		BattleEffectGroup::ActionPriority,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"���������",
		SkillGroup::Attack,
		35,
		85,
		15,
		PokemonType::Water,
		BattleEffectGroup::None,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });
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