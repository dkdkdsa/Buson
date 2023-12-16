#include "pch.h"
#include "PokemonManager.h"
#include "SkillManager.h"

void PokemonManager::Init()
{

	CreatePokemon();

}

Pokemon PokemonManager::GetPokemon(int encyclopediaNumber)
{
	
	auto pokemon = _pokemonContainer[encyclopediaNumber];
	pokemon.Stats = PokemonStats({

			GetRealValue(pokemon.Stats.Hp, rand() % 10, rand() % 30, pokemon.EvolutionCount * 20) + 110,

			GetRealValue(pokemon.Stats.Attack, rand() % 10, rand() % 30, pokemon.EvolutionCount * 20),

			GetRealValue(pokemon.Stats.Defense, rand() % 10, rand() % 30, pokemon.EvolutionCount * 20),

			GetRealValue(pokemon.Stats.Speed, rand() % 10, rand() % 30, pokemon.EvolutionCount * 20)

		});

	pokemon.SkillsKey = SkillManager::GetInst()->LearnSkill(pokemon.Type, pokemon.EvolutionCount);

	return pokemon;

}

Pokemon PokemonManager::GetRamdomPokemonByLevel(int lv)
{

	int size = _levelPokemonContainer[lv].size();

	int idx = rand() % size;

	auto pokemon = _levelPokemonContainer[lv][idx];

	pokemon.Stats = PokemonStats({

		GetRealValue(pokemon.Stats.Hp, rand() % 31, (rand() % 30), pokemon.EvolutionCount * 20) + 110,

		GetRealValue(pokemon.Stats.Attack, rand() % 31, rand() % 30, pokemon.EvolutionCount * 20),

		GetRealValue(pokemon.Stats.Defense, rand() % 31, rand() % 30, pokemon.EvolutionCount * 20),

		GetRealValue(pokemon.Stats.Speed, rand() % 31, rand() % 30, pokemon.EvolutionCount * 20)

		});

	pokemon.SkillsKey = SkillManager::GetInst()->LearnSkill(pokemon.Type, pokemon.EvolutionCount);

	return pokemon;

}
void PokemonManager::CreatePokemon()
{

	Pokemon curPokemon;

#pragma region �̻��ؾ�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Grass },
			{

				45, //HP
				49 + 32.5f, //Attack
				49 + 32.5f, //Defence
				45, //Speed

			},
			{},
			L"001",
			L"�̻��ؾ�",
			1,
			2
	);

	_pokemonContainer[1] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

	curPokemon = Pokemon
	(

		{ PokemonType::Grass },
			{

				60, //HP
				62 + 40, //Attack
				63 + 40, //Defence
				60, //Speed

			},
		{},
			L"002",
			L"�̻���Ǯ",
			2,
			3
	);

	_pokemonContainer[2] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

	curPokemon = Pokemon
	(

		{ PokemonType::Grass },
			{

				80, //HP
				82 + 50, //Attack
				83 + 50, //Defence
				80, //Speed

			},
		{},
			L"003",
			L"�̻��ز�",
			3,
			0
			);

	_pokemonContainer[3] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);

#pragma endregion

#pragma region ���̸�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Fire },
			{

				39, //HP
				52 + 25.f, //Attack
				43 + 25.f, //Defence
				65, //Speed

			},
		{},
			L"004",
			L"���̸�",
			1,
			5
	);

	_pokemonContainer[4] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Fire },
			{

				58, //HP
				64 + 32.5f, //Attack
				58 + 32.5f, //Defence
				80, //Speed

			},
			{},
			L"005",
			L"���ڵ�",
			2,
			6

	);

	_pokemonContainer[5] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Fire },
			{

				78, //HP
				84 + 42.5f, //Attack
				78 + 42.5f, //Defence
				100, //Speed

			},
		{},
		L"006",
		L"���ڸ�",
		3,
		0

		);


	_pokemonContainer[6] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);

#pragma endregion

#pragma region ���α�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				44, //HP
				48 + 32.f, //Attack
				65 + 32.f, //Defence
				43, //Speed

			},
		{},
			L"007",
			L"���α�",
			1,
			8
			);

	_pokemonContainer[7] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				59, //HP
				63 + 32.5f, //Attack
				80 + 32.5f, //Defence
				58, //Speed

			},
		{},
			L"008",
			L"��Ϻα�",
			2,
			9
	);

	_pokemonContainer[8] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				79, //HP
				83 + 42.5f, //Attack
				100 + 42.5f, //Defence
				78, //Speed

			},
			{},
			L"009",
			L"�źϿ�",
			3,
			0
	);

	_pokemonContainer[9] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);


#pragma endregion

#pragma region ĳ����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Bug },
			{

				45, //HP
				30 + 5.f, //Attack
				35 + 5.f, //Defence
				45, //Speed

			},
		{},
		L"010",
		L"ĳ����",
		1,
		11
	);

	_pokemonContainer[10] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Bug },
			{

				50, //HP
				20 + 12.5f, //Attack
				55 + 12.5f, //Defence
				30, //Speed

			},
		{},
		L"011",
		L"�ܵ���",
		2,
		12
		);

	_pokemonContainer[11] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Bug },
			{

				60, //HP
				45 + 40.f, //Attack
				50 + 40.f, //Defence
				70, //Speed

			},
		{},
		L"012",
		L"������",
		3,
		0
		);

	_pokemonContainer[12] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);

#pragma endregion

#pragma region ������_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Bug },
			{

				40, //HP
				35 + 10.f, //Attack
				30 + 10.f, //Defence
				50, //Speed

			},
		{},
		L"013",
		L"������",
		1,
		14
	);

	_pokemonContainer[13] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Bug },
			{

				45, //HP
				25 + 12.5f, //Attack
				50 + 12.5f, //Defence
				35, //Speed

			},
		{},
		L"014",
		L"������",
		2,
		15
		);

	_pokemonContainer[14] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Bug },
			{

				65, //HP
				80 + 22.5f, //Attack
				40 + 22.5f, //Defence
				75, //Speed

			},
		{},
		L"015",
		L"��ħ��",
		3,
		0
		);

	_pokemonContainer[15] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);

#pragma endregion

#pragma region ����_�迭


	curPokemon = Pokemon
	(
		{ PokemonType::Normal, PokemonType::Flying },
			{

				40, //HP
				45 + 17.5f, //Attack
				40 + 17.5f, //Defence
				56, //Speed

			},
		{},
		L"016",
		L"����",
		1,
		17
		);

	_pokemonContainer[16] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Normal, PokemonType::Flying },
			{

				63, //HP
				60 + 25.f, //Attack
				55 + 25.f, //Defence
				71, //Speed

			},
		{},
		L"017",
		L"����",
		2,
		18
		);

	_pokemonContainer[17] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Normal, PokemonType::Flying },
			{

				83, //HP
				80 + 35.f, //Attack
				75 + 35.f, //Defence
				91, //Speed

			},
		{},
		L"018",
		L"������",
		3,
		0
		);

	_pokemonContainer[18] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);


#pragma endregion

#pragma region ����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Normal },
			{

				30	, //HP
				56 + 12.5f, //Attack
				35 + 12.5f, //Defence
				72, //Speed

			},
		{},
		L"019",
		L"����",
		1,
		20
		);

	_pokemonContainer[19] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Normal },
			{

				55, //HP
				81 + 25.f, //Attack
				60 + 25.f, //Defence
				97, //Speed

			},
		{},
		L"020",
		L"��Ʈ��",
		2,
		0
		);

	_pokemonContainer[20] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

#pragma endregion

#pragma region ������_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Normal, PokemonType::Flying },
			{

				40, //HP
				60 + 15.5f, //Attack
				30 + 15.5f, //Defence
				70, //Speed

			},
		{},
		L"021",
		L"������",
		1,
		22
		);

	_pokemonContainer[21] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Normal, PokemonType::Flying },
			{

				65, //HP
				90 + 30.5f, //Attack
				65 + 30.5f, //Defence
				100, //Speed

			},
		{},
		L"022",
		L"����帱��",
		2,
		0
		);

	_pokemonContainer[22] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

#pragma endregion

#pragma region �ƺ�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Poison },
			{

				35, //HP
				60 + 20.f, //Attack
				44 + 20.f, //Defence
				55, //Speed

			},
		{},
		L"023",
		L"�ƺ�",
		1,
		24
		);

	_pokemonContainer[23] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Poison },
			{

				60, //HP
				85 + 35.f, //Attack
				69 + 35.f, //Defence
				80, //Speed

			},
		{},
		L"024",
		L"�ƺ�ũ",
		2,
		0
		);

	_pokemonContainer[24] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

#pragma endregion

#pragma region ��ī��_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Electric },
			{

				35, //HP
				55 + 25.f, //Attack
				30 + 25.f, //Defence
				90, //Speed

			},
		{},
		L"025",
		L"��ī��",
		1,
		26
		);

	_pokemonContainer[25] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Electric },
			{

				60, //HP
				90 + 45.f, //Attack
				55 + 45.f, //Defence
				100, //Speed

			},
		{},
		L"026",
		L"������",
		2,
		0
		);

	_pokemonContainer[26] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

#pragma endregion

#pragma region �𷡵���_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Ground },
			{

				50, //HP
				75 + 15.f, //Attack
				85 + 15.f, //Defence
				40, //Speed

			},
		{},
		L"027",
		L"�𷡵���",
		1,
		28
		);

	_pokemonContainer[27] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Ground },
			{

				75, //HP
				100 + 25.5f, //Attack
				110 + 25.5f, //Defence
				65, //Speed

			},
		{},
		L"028",
		L"����",
		2,
		0
		);

	_pokemonContainer[28] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

#pragma endregion

#pragma region �ϵ己_��_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Poison },
			{

				55, //HP
				47 + 20.f, //Attack
				52 + 20.f, //Defence
				41, //Speed

			},
		{},
		L"029",
		L"�ϵ己��",
		1,
		30
		);

	_pokemonContainer[29] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Poison },
			{

				70, //HP
				62 + 25.5f, //Attack
				67 + 25.5f, //Defence
				56, //Speed

			},
		{},
		L"030",
		L"�ϵ帮��",
		2,
		31
		);

	_pokemonContainer[30] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Poison, PokemonType::Ground },
			{

				90, //HP
				82 + 37.5f, //Attack
				87 + 37.5f, //Defence
				76, //Speed

			},
		{},
		L"031",
		L"�ϵ���",
		3,
		0
		);

	_pokemonContainer[31] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);

#pragma endregion

#pragma region �ϵ己_��_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Poison },
			{

				46, //HP
				57 + 20.f, //Attack
				40 + 20.f, //Defence
				50, //Speed

			},
		{},
		L"032",
		L"�ϵ己��",
		1,
		33
		);

	_pokemonContainer[32] = curPokemon;
	_levelPokemonContainer[1].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Poison },
			{

				61, //HP
				72 + 27.5f, //Attack
				57 + 27.5f, //Defence
				65, //Speed

			},
		{},
		L"033",
		L"�ϵ帮��",
		2,
		34
		);

	_pokemonContainer[33] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Poison, PokemonType::Ground },
			{

				81, //HP
				92 + 37.5f, //Attack
				77 + 37.5f, //Defence
				85, //Speed

			},
		{},
		L"034",
		L"�ϵ�ŷ",
		3,
		0
		);

	_pokemonContainer[34] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �߻�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Normal },
			{

				70, //HP
				45 + 30.f, //Attack
				48 + 30.f, //Defence
				35, //Speed

			},
		{},
		L"035",
		L"�߻�",
		1,
		0
		);

	_pokemonContainer[35] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Normal },
			{

				95, //HP
				70 + 42.5f, //Attack
				73 + 42.5f, //Defence
				60, //Speed

			},
		{},
		L"036",
		L"�Ƚ�",
		2,
		0
		);

	_pokemonContainer[36] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �Ľ�����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Fire },
			{

				38, //HP
				41 + 32.5f, //Attack
				40 + 32.5f, //Defence
				65, //Speed

			},
		{},
		L"037",
		L"�Ľ�����",
		1,
		38
		);

	_pokemonContainer[37] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Fire },
			{

				73, //HP
				76 + 50.f, //Attack
				75 + 50.f, //Defence
				100, //Speed

			},
		{},
		L"038",
		L"��������",
		2,
		0
		);

	_pokemonContainer[38] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region Ǫ��_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Normal },
			{

				115, //HP
				45 + 17.5f, //Attack
				20 + 17.5f, //Defence
				20, //Speed

			},
		{},
		L"039",
		L"Ǫ��",
		1	,
		40
		);

	_pokemonContainer[39] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Normal },
			{

				140, //HP
				70 + 25.f, //Attack
				45 + 25.f, //Defence
				45, //Speed

			},
		{},
		L"040",
		L"Ǫũ��",
		2,
		0
		);

	_pokemonContainer[40] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �ֹ�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Poison, PokemonType::Flying },
			{

				40, //HP
				45 + 20.f, //Attack
				35 + 20.f, //Defence
				55, //Speed

			},
		{},
		L"041",
		L"�ֹ�",
		1,
		42
		);

	_pokemonContainer[41] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Poison, PokemonType::Flying },
			{

				75	, //HP
				80 + 37.5f, //Attack
				70 + 37.5f, //Defence
				90, //Speed

			},
		{},
		L"042",
		L"���",
		2,
		0
		);

	_pokemonContainer[42] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �ѹ���_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Grass, PokemonType::Poison },
			{

				45		, //HP
				50 + 37.5f, //Attack
				55 + 37.5f, //Defence
				30, //Speed

			},
		{},
		L"043",
		L"�ѹ���",
		1,
		44
		);

	_pokemonContainer[43] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Grass, PokemonType::Poison },
			{

				60	, //HP
				65 + 47.5f, //Attack
				70 + 47.5f, //Defence
				40, //Speed

			},
		{},
		L"044",
		L"������",
		2,
		45
		);

	_pokemonContainer[44] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);
	
	curPokemon = Pokemon
	(
		{ PokemonType::Grass, PokemonType::Poison },
			{

				75	, //HP
				80 + 50.f, //Attack
				85 + 50.f, //Defence
				50, //Speed

			},
		{},
		L"045",
		L"���÷��þ�",
		3,
		0
		);

	_pokemonContainer[45] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �Ķ�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Bug, PokemonType::Grass },
			{

				35	, //HP
				70 + 27.5f, //Attack
				55 + 27.5f, //Defence
				25, //Speed

			},
		{},
		L"046",
		L"�Ķ�",
		1,
		47
		);

	_pokemonContainer[46] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Bug, PokemonType::Grass },
			{

				60	, //HP
				95 + 40.f, //Attack
				80 + 40.f, //Defence
				30, //Speed

			},
		{},
		L"047",
		L"�Ķ�Ʈ",
		2,
		0
		);

	_pokemonContainer[47] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Bug, PokemonType::Poison },
			{

				60	, //HP
				55 + 20.f, //Attack
				50 + 20.f, //Defence
				45, //Speed

			},
		{},
		L"048",
		L"����",
		1,
		49
		);

	_pokemonContainer[48] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Bug, PokemonType::Poison },
			{

				70	, //HP
				65 + 35.f, //Attack
				60 + 35.f, //Defence
				95, //Speed

			},
		{},
		L"049",
		L"������",
		2,
		0
		);

	_pokemonContainer[49] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ��״�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Ground },
			{

				10	, //HP
				55 + 27.5f, //Attack
				25 + 27.5f, //Defence
				95, //Speed

			},
		{},
		L"050",
		L"��״�",
		1,
		51
		);

	_pokemonContainer[50] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Ground },
			{

				35	, //HP
				80 + 35.f, //Attack
				50 + 35.f, //Defence
				120, //Speed

			},
		{},
		L"051",
		L"��Ʈ����",
		2,
		0
		);

	_pokemonContainer[51] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Normal },
			{

				40	, //HP
				45 + 20.f, //Attack
				35 + 20.f, //Defence
				90, //Speed

			},
		{},
		L"052",
		L"����",
		1,
		53	
		);

	_pokemonContainer[52] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Normal },
			{

				65	, //HP
				70 + 27.5f, //Attack
				60 + 27.5f, //Defence
				115, //Speed

			},
		{},
		L"053",
		L"�丣�ÿ�",
		2,
		0
		);

	_pokemonContainer[53] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ����Ĵ�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				50	, //HP
				52 + 25.f, //Attack
				48 + 25.f, //Defence
				55, //Speed

			},
		{},
		L"054",
		L"����Ĵ�",
		1,
		55
		);

	_pokemonContainer[54] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				80	, //HP
				82 + 40.f, //Attack
				78 + 40.f, //Defence
				85, //Speed

			},
		{},
		L"055",
		L"���",
		2,
		0
		);

	_pokemonContainer[55] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ��Ű_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Fighting },
			{

				40	, //HP
				80 + 17.5f, //Attack
				35 + 17.5f, //Defence
				70, //Speed

			},
		{},
		L"056",
		L"��Ű",
		1,
		57
		);

	_pokemonContainer[56] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Fighting },
			{

				60	, //HP
				105 + 30.f, //Attack
				60 + 30.f, //Defence
				95, //Speed

			},
		{},
		L"057",
		L"������",
		2,
		0
		);

	_pokemonContainer[57] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);



#pragma endregion

#pragma region ����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Fire },
			{

				55	, //HP
				70 + 25.f, //Attack
				45 + 25.f, //Defence
				60, //Speed

			},
		{},
		L"058",
		L"����",
		1,
		59
		);

	_pokemonContainer[58] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Fire },
			{

				90	, //HP
				110 + 30.f, //Attack
				85 + 30.f, //Defence
				95, //Speed

			},
		{},
		L"059",
		L"����",
		2,
		0
		);

	_pokemonContainer[59] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ��ì��_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				40	, //HP
				50 + 20.f, //Attack
				40 + 20.f, //Defence
				90, //Speed

			},
		{},
		L"060",
		L"��ì��",
		1,
		61
		);

	_pokemonContainer[60] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				65	, //HP
				65 + 25.f, //Attack
				65 + 25.f, //Defence
				90, //Speed

			},
		{},
		L"061",
		L"����ì��",
		2,
		62
		);

	_pokemonContainer[61] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				90	, //HP
				85 + 35.f, //Attack
				95 + 35.f, //Defence
				70, //Speed

			},
		{},
		L"062",
		L"��ì��",
		3,
		0
		);

	_pokemonContainer[62] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ĳ�̽�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Psychic },
			{

				25	, //HP
				20 + 52.5f, //Attack
				15 + 52.5f, //Defence
				90, //Speed

			},
		{},
		L"063",
		L"ĳ�̽�",
		1,
		64
		);

	_pokemonContainer[63] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Psychic },
			{

				40	, //HP
				35 + 60.f, //Attack
				30 + 60.f, //Defence
				105, //Speed

			},
		{},
		L"064",
		L"���ֶ�",
		2,
		65
		);

	_pokemonContainer[64] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Psychic },
			{

				55	, //HP
				50 + 67.5f, //Attack
				45 + 67.5f, //Defence
				120, //Speed

			},
		{},
		L"065",
		L"�ĵ�",
		3,
		0
		);

	_pokemonContainer[65] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion


#pragma region �����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Fighting },
			{

				70	, //HP
				80 + 17.5f, //Attack
				50 + 17.5f, //Defence
				35, //Speed

			},
		{},
		L"066",
		L"�����",
		1,
		67
		);

	_pokemonContainer[66] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Fighting },
			{

				80	, //HP
				100 + 25.f, //Attack
				70 + 25.f, //Defence
				45, //Speed

			},
		{},
		L"067",
		L"������",
		2,
		68
		);

	_pokemonContainer[67] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Fighting },
			{

				90	, //HP
				130 + 37.5f, //Attack
				80 + 37.5f, //Defence
				55, //Speed

			},
		{},
		L"068",
		L"���¸�",
		3,
		0
		);

	_pokemonContainer[68] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Grass, PokemonType::Poison },
			{

				50	, //HP
				75 + 35.f, //Attack
				35 + 35.f, //Defence
				55, //Speed

			},
		{},
		L"069",
		L"�����",
		1,
		70
		);

	_pokemonContainer[69] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);


	curPokemon = Pokemon
	(
		{ PokemonType::Grass, PokemonType::Poison },
			{

				65	, //HP
				90 + 42.5f, //Attack
				50 + 42.5f, //Defence
				55, //Speed

			},
		{},
		L"070",
		L"������",
		2,
		71
		);

	_pokemonContainer[70] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Grass, PokemonType::Poison },
			{

				80	, //HP
				105 + 50.0f, //Attack
				65 + 50.f, //Defence
				70, //Speed

			},
		{},
		L"071",
		L"������Ʈ",
		3,
		0
		);

	_pokemonContainer[71] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �մ���_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Water, PokemonType::Poison },
			{

				40	, //HP
				40 + 50.0f, //Attack
				35 + 50.f, //Defence
				70, //Speed

			},
		{},
		L"072",
		L"�մ���",
		1,
		73
		);

	_pokemonContainer[72] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Water, PokemonType::Poison },
			{

				80	, //HP
				70 + 60.0f, //Attack
				65 + 60.f, //Defence
				100, //Speed

			},
		{},
		L"073",
		L"���ĸ�",
		2,
		0
		);

	_pokemonContainer[73] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ������_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Rock, PokemonType::Ground },
			{

				40	, //HP
				80 + 15.f, //Attack
				100 + 15.f, //Defence
				20, //Speed

			},
		{},
		L"074",
		L"������",
		1,
		75
		);

	_pokemonContainer[74] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Rock, PokemonType::Ground },
			{

				55	, //HP
				95 + 17.5f, //Attack
				115 + 17.5f, //Defence
				35, //Speed

			},
		{},
		L"075",
		L"������",
		2,
		76
		);

	_pokemonContainer[75] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Rock, PokemonType::Ground },
			{

				80	, //HP
				110 + 27.5f, //Attack
				130 + 27.5f, //Defence
				145, //Speed

			},
		{},
		L"076",
		L"������",
		3,
		0
		);

	_pokemonContainer[76] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ����Ÿ_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Fire },
			{

				50	, //HP
				85 + 32.5f, //Attack
				55 + 32.5f, //Defence
				90, //Speed

			},
		{},
		L"077",
		L"����Ÿ",
		1,
		78
		);

	_pokemonContainer[77] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Fire },
			{

				65	, //HP
				100 + 40.f, //Attack
				70 + 40.f, //Defence
				105, //Speed

			},
		{},
		L"078",
		L"���߸�",
		2,
		0
		);

	_pokemonContainer[78] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �ߵ�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Water, PokemonType::Psychic },
			{

				90	, //HP
				65 + 20.f, //Attack
				65 + 20.f, //Defence
				15, //Speed

			},
		{},
		L"079",
		L"�ߵ�",
		1,
		80
		);

	_pokemonContainer[79] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Water, PokemonType::Psychic },
			{

				95	, //HP
				75 + 40.f, //Attack
				110 + 40.f, //Defence
				30, //Speed

			},
		{},
		L"080",
		L"�ߵ���",
		2,
		0
		);

	_pokemonContainer[80] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Electric },
			{

				25	, //HP
				35 + 47.5f, //Attack
				70 + 47.5f, //Defence
				45, //Speed

			},
		{},
		L"081",
		L"����",
		1,
		82
		);

	_pokemonContainer[81] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Electric },
			{

				50	, //HP
				60 + 60.f, //Attack
				95 + 60.f, //Defence
				70, //Speed

			},
		{},
		L"082",
		L"��������",
		2,
		0
		);

	_pokemonContainer[82] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �Ŀ���_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Normal, PokemonType::Flying },
			{

				52	, //HP
				65 + 29.f, //Attack
				55 + 29.f, //Defence
				60, //Speed

			},
		{},
		L"083",
		L"�Ŀ���",
		1,
		0
		);

	_pokemonContainer[83] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �ε�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Normal, PokemonType::Flying },
			{

				35	, //HP
				85 + 17.5f, //Attack
				45 + 17.5f, //Defence
				75, //Speed

			},
		{},
		L"084",
		L"�ε�",
		1,
		85
		);

	_pokemonContainer[84] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Normal, PokemonType::Flying },
			{

				60	, //HP
				110 + 30.f, //Attack
				70+ 30.f, //Defence
				100, //Speed

			},
		{},
		L"085",
		L"��Ʈ����",
		2,
		0
		);

	_pokemonContainer[85] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				65	, //HP
				45 + 35.f, //Attack
				55 + 35.f, //Defence
				45, //Speed

			},
		{},
		L"086",
		L"����",
		1,
		87
		);

	_pokemonContainer[86] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				90	, //HP
				70 + 47.5f, //Attack
				80 + 47.5f, //Defence
				70, //Speed

			},
		{},
		L"087",
		L"�극��",
		2,
		0
		);

	_pokemonContainer[87] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ������_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Poison },
			{

				80	, //HP
				80 + 20.f, //Attack
				50 + 20.f, //Defence
				25, //Speed

			},
		{},
		L"088",
		L"������",
		1,
		89
		);

	_pokemonContainer[88] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Poison },
			{

				105	, //HP
				105 + 32.5f, //Attack
				75 + 32.5f, //Defence
				50, //Speed

			},
		{},
		L"089",
		L"������",
		2,
		0
		);

	_pokemonContainer[89] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				30	, //HP
				65 + 22.5f, //Attack
				100 + 22.5f, //Defence
				40, //Speed

			},
		{},
		L"090",
		L"����",
		1,
		91
		);

	_pokemonContainer[90] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				50	, //HP
				95 + 42.5f, //Attack
				180 + 42.5f, //Defence
				70, //Speed

			},
		{},
		L"091",
		L"�ĸ���",
		2,
		0
		);

	_pokemonContainer[91] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Ghost, PokemonType::Poison },
			{

				30	, //HP
				35 + 50.f, //Attack
				30 + 50.f, //Defence
				80, //Speed

			},
		{},
		L"092",
		L"�����",
		1,
		93
		);

	_pokemonContainer[92] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Ghost, PokemonType::Poison },
			{

				45	, //HP
				50 + 57.5f, //Attack
				45 + 57.5f, //Defence
				95, //Speed

			},
		{},
		L"093",
		L"��콺Ʈ",
		2,
		94
		);

	_pokemonContainer[93] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Ghost, PokemonType::Poison },
			{

				60, //HP
				65 + 65.f, //Attack
				60 + 65.f, //Defence
				110, //Speed

			},
		{},
		L"094",
		L"����",
		3,
		0
		);

	_pokemonContainer[94] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �ս���_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Ground, PokemonType::Rock },
			{

				35, //HP
				45 + 15.f, //Attack
				160 + 15.f, //Defence
				70, //Speed

			},
		{},
		L"095",
		L"�ս���",
		1,
		0
		);

	_pokemonContainer[95] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion


#pragma region ������_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Psychic },
			{

				60, //HP
				48 + 45.f, //Attack
				45 + 45.f, //Defence
				42, //Speed

			},
		{},
		L"096",
		L"������",
		1,
		97
		);

	_pokemonContainer[96] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Psychic },
			{

				85, //HP
				73 + 57.5f, //Attack
				70 + 57.5f, //Defence
				67, //Speed

			},
		{},
		L"097",
		L"������",
		2,
		0
		);

	_pokemonContainer[97] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ũ��_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				30, //HP
				105 + 12.5f, //Attack
				90 + 12.5f, //Defence
				50, //Speed

			},
		{},
		L"098",
		L"�׷�",
		1,
		99
		);

	_pokemonContainer[98] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				55, //HP
				130 + 25.f, //Attack
				115 + 25.f, //Defence
				75, //Speed

			},
		{},
		L"099",
		L"ŷ�׷�",
		2,
		0
		);

	_pokemonContainer[99] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Electric },
			{

				40, //HP
				30 + 27.5f, //Attack
				50 + 27.5f, //Defence
				100, //Speed

			},
		{},
		L"100",
		L"�����",
		1,
		101
		);

	_pokemonContainer[100] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Electric },
			{

				60, //HP
				50 + 40.f, //Attack
				70 + 40.f, //Defence
				140, //Speed

			},
		{},
		L"101",
		L"�պ�",
		2,
		0
		);

	_pokemonContainer[101] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �ƶ�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Grass, PokemonType::Psychic },
			{

				60, //HP
				40 + 30.f, //Attack
				80 + 30.f, //Defence
				40, //Speed

			},
		{},
		L"102",
		L"�ƶ�",
		1,
		103
		);

	_pokemonContainer[102] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Grass, PokemonType::Psychic },
			{

				95, //HP
				95 + 62.5f, //Attack
				85 + 62.5f, //Defence
				55, //Speed

			},
		{},
		L"103",
		L"����",
		2,
		0
		);

	_pokemonContainer[103] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ������_�迭


	curPokemon = Pokemon
	(
		{ PokemonType::Ground },
			{

				50, //HP
				50 + 20.f, //Attack
				95 + 20.f, //Defence
				35, //Speed

			},
		{},
		L"104",
		L"������",
		1,
		105
		);

	_pokemonContainer[104] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Ground },
			{

				60, //HP
				80 + 25.f, //Attack
				110 + 25.f, //Defence
				45, //Speed

			},
		{},
		L"105",
		L"�ֱ���",
		2,
		0
		);

	_pokemonContainer[105] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �ö�Ҹ�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Fighting },
			{

				50, //HP
				120 + 17.5f, //Attack
				53 + 17.5f, //Defence
				87, //Speed

			},
		{},
		L"106",
		L"�ö�Ҹ�",
		1,
		0
		);

	_pokemonContainer[106] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ȫ����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Fighting },
			{

				50, //HP
				105 + 17.5f, //Attack
				79 + 17.5f, //Defence
				87, //Speed

			},
		{},
		L"107",
		L"ȫ����",
		1,
		0
		);

	_pokemonContainer[107] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Normal },
			{

				90, //HP
				55 + 30.f, //Attack
				75 + 30.f, //Defence
				30, //Speed

			},
		{},
		L"108",
		L"�����",
		1,
		0
		);

	_pokemonContainer[108] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �ǰ���_�迭


	curPokemon = Pokemon
	(
		{ PokemonType::Poison },
			{

				40, //HP
				65 + 30.f, //Attack
				95 + 30.f, //Defence
				35, //Speed

			},
		{},
		L"109",
		L"�ǰ���",
		1,
		110
		);

	_pokemonContainer[109] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Poison },
			{

				65, //HP
				90 + 42.5f, //Attack
				120 + 42.5f, //Defence
				60, //Speed

			},
		{},
		L"110",
		L"�ǵ�����",
		2,
		0
		);

	_pokemonContainer[110] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ��ī��_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Ground, PokemonType::Rock },
			{

				80, //HP
				85 + 15.f, //Attack
				95 + 15.f, //Defence
				25, //Speed

			},
		{},
		L"111",
		L"��ī��",
		1,
		112
		);

	_pokemonContainer[111] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Ground, PokemonType::Rock },
			{

				105, //HP
				130 + 22.5f, //Attack
				120 + 22.5f, //Defence
				40, //Speed

			},
		{},
		L"112",
		L"�ڻѸ�",
		2,
		0
		);

	_pokemonContainer[112] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ��Ű_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Normal },
			{

				250, //HP
				5 + 52.5f, //Attack
				5 + 52.5f, //Defence
				50, //Speed

			},
		{},
		L"113",
		L"��Ű",
		1,
		0
		);

	_pokemonContainer[113] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Grass },
			{

				65, //HP
				55 + 50.f, //Attack
				115 + 50.f, //Defence
				60, //Speed

			},
		{},
		L"114",
		L"����",
		1,
		0
		);

	_pokemonContainer[114] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region Ļī_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Normal },
			{

				105, //HP
				95 + 20.f, //Attack
				80 + 20.f, //Defence
				90, //Speed

			},
		{},
		L"115",
		L"Ļī",
		1,
		0
		);

	_pokemonContainer[115] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				30, //HP
				40 + 35.f, //Attack
				70 + 35.f, //Defence
				60, //Speed

			},
		{},
		L"116",
		L"����",
		1,
		117
		);

	_pokemonContainer[116] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				55, //HP
				65 + 47.5f, //Attack
				95 + 47.5f, //Defence
				85, //Speed

			},
		{},
		L"117",
		L"�����",
		2,
		0
		);

	_pokemonContainer[117] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ��ġ_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				45, //HP
				67 + 25.f, //Attack
				60 + 25.f, //Defence
				63, //Speed

			},
		{},
		L"118",
		L"��ġ",
		1,
		119
		);

	_pokemonContainer[118] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				80, //HP
				92 + 40.f, //Attack
				65 + 40.f, //Defence
				68, //Speed

			},
		{},
		L"119",
		L"����ġ",
		2,
		0
		);

	_pokemonContainer[119] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �����縮_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				30, //HP
				45 + 35.f, //Attack
				55 + 35.f, //Defence
				85, //Speed

			},
		{},
		L"120",
		L"�����縮",
		1,
		121
		);

	_pokemonContainer[120] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				60, //HP
				75 + 50.f, //Attack
				85 + 50.f, //Defence
				115, //Speed

			},
		{},
		L"121",
		L"����Ÿ",
		2,
		0
		);

	_pokemonContainer[121] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion


#pragma region ���Ӹ�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Psychic },
			{

				40, //HP
				45 + 50.f, //Attack
				65 + 50.f, //Defence
				90, //Speed

			},
		{},
		L"122",
		L"���Ӹ�",
		1,
		0
		);

	_pokemonContainer[122] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ����ũ_�迭


	curPokemon = Pokemon
	(
		{ PokemonType::Bug, PokemonType::Flying },
			{

				70, //HP
				110 + 27.5f, //Attack
				80 + 27.5f, //Defence
				105, //Speed

			},
		{},
		L"123",
		L"����ũ",
		1,
		0
		);

	_pokemonContainer[123] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ���ֶ�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Ice, PokemonType::Psychic },
			{

				65, //HP
				50 + 47.5f, //Attack
				45 + 47.5f, //Defence
				95, //Speed

			},
		{},
		L"124",
		L"���ֶ�",
		1,
		0
		);

	_pokemonContainer[124] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ������_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Electric },
			{

				65, //HP
				83 + 42.5f, //Attack
				57 + 42.5f, //Defence
				105, //Speed

			},
		{},
		L"125",
		L"������",
		1,
		0
		);

	_pokemonContainer[125] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ���׸�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Fire},
			{

				65, //HP
				95 + 42.5f, //Attack
				57 + 42.5f, //Defence
				93, //Speed

			},
		{},
		L"126",
		L"���׸�",
		1,
		0
		);

	_pokemonContainer[126] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �ڻ�����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Bug },
			{

				65, //HP
				125 + 22.5f, //Attack
				100 + 22.5f, //Defence
				85, //Speed

			},
		{},
		L"127",
		L"�ڻ�����",
		1,
		0
		);

	_pokemonContainer[127] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ��Ÿ�ν�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Bug },
			{

				75, //HP
				100 + 35.f, //Attack
				95 + 35.f, //Defence
				110, //Speed

			},
		{},
		L"128",
		L"��Ÿ�ν�",
		1,
		0
		);

	_pokemonContainer[128] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �׾�ŷ_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				20, //HP
				10 + 10.f, //Attack
				55 + 10.f, //Defence
				80, //Speed

			},
		{},
		L"129",
		L"�׾�ŷ",
		1,
		130
		);

	_pokemonContainer[129] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				95, //HP
				125 + 50.f, //Attack
				79 + 50.f, //Defence
				81, //Speed

			},
		{},
		L"130",
		L"���󵵽�",
		2,
		0
		);

	_pokemonContainer[130] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ������_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Water, PokemonType::Ice },
			{

				130, //HP
				85 + 47.5f, //Attack
				80 + 47.5f, //Defence
				60, //Speed

			},
		{},
		L"131",
		L"������",
		1,
		0
		);

	_pokemonContainer[131] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);


#pragma endregion

#pragma region ��Ÿ��_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Normal },
			{

				48, //HP
				48 + 24.f, //Attack
				48 + 24.f, //Defence
				48, //Speed

			},
		{},
		L"132",
		L"��Ÿ��",
		1,
		-2
		);

	_pokemonContainer[132] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �̺���_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Normal },
			{

				55, //HP
				55 + 32.5f, //Attack
				50 + 32.5f, //Defence
				55, //Speed

			},
		{},
		L"133",
		L"�̺���",
		1,
		-1
		);

	_pokemonContainer[133] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Water },
			{

				130, //HP
				65 + 55.f, //Attack
				60 + 55.f, //Defence
				65, //Speed

			},
		{},
		L"134",
		L"���̵�",
		2,
		0
		);

	_pokemonContainer[134] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Electric },
			{

				65, //HP
				65 + 55.f, //Attack
				60 + 55.f, //Defence
				130, //Speed

			},
		{},
		L"135",
		L"���ǽ��",
		2,
		0
		);

	_pokemonContainer[135] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Fire },
			{

				65, //HP
				130 + 55.f, //Attack
				60 + 55.f, //Defence
				65, //Speed

			},
		{},
		L"136",
		L"�ν���",
		2,
		0
		);

	_pokemonContainer[136] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ������_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Normal },
			{

				65, //HP
				60 + 37.5f, //Attack
				70 + 37.5f, //Defence
				40, //Speed

			},
		{},
		L"137",
		L"������",
		1,
		0
		);

	_pokemonContainer[137] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion


#pragma region �ϳ���Ʈ_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Rock, PokemonType::Water },
			{

				35, //HP
				40 + 45.f, //Attack
				100 + 45.f, //Defence
				45, //Speed

			},
		{},
		L"138",
		L"�ϳ���Ʈ",
		1,
		139
		);

	_pokemonContainer[138] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Rock, PokemonType::Water },
			{

				70, //HP
				60 + 57.5f, //Attack
				125 + 57.5f, //Defence
				55, //Speed

			},
		{},
		L"139",
		L"�Ͻ�Ÿ",
		2,
		0
		);

	_pokemonContainer[139] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Rock, PokemonType::Water },
			{

				30, //HP
				80 + 22.5f, //Attack
				90 + 22.5f, //Defence
				55, //Speed

			},
		{},
		L"140",
		L"����",
		1,
		141
		);

	_pokemonContainer[140] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Rock, PokemonType::Water },
			{

				60, //HP
				115 + 35.f, //Attack
				105 + 35.f, //Defence
				55, //Speed

			},
		{},
		L"141",
		L"����Ǫ��",
		2,
		0
		);

	_pokemonContainer[141] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ���׶�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Rock, PokemonType::Flying },
			{

				80, //HP
				105 + 30.f, //Attack
				65 + 30.f, //Defence
				130, //Speed

			},
		{},
		L"142",
		L"���׶�",
		1,
		0
		);

	_pokemonContainer[142] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region �Ḹ��_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Normal },
			{

				160, //HP
				110 + 32.5f, //Attack
				65 + 32.5f, //Defence
				30, //Speed

			},
		{},
		L"143",
		L"�Ḹ��",
		1,
		0
		);

	_pokemonContainer[143] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ������_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Ice, PokemonType::Flying },
			{

				90, //HP
				85 + 62.5f, //Attack
				100 + 62.5f, //Defence
				85, //Speed

			},
		{},
		L"144",
		L"������",
		4,
		0
		);

	_pokemonContainer[144] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ���_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Electric, PokemonType::Flying },
			{

				90, //HP
				90 + 62.5f, //Attack
				85 + 62.5f, //Defence
				100, //Speed

			},
		{},
		L"145",
		L"���",
		4,
		0
		);

	_pokemonContainer[145] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ���_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Fire, PokemonType::Flying },
			{

				90, //HP
				100 + 62.5f, //Attack
				90 + 62.5f, //Defence
				90, //Speed

			},
		{},
		L"146",
		L"���̾�",
		4,
		0
		);

	_pokemonContainer[146] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);


#pragma endregion


#pragma region �̴�_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Dragon },
			{

				41, //HP
				64 + 25.f, //Attack
				45 + 25.f, //Defence
				50, //Speed

			},
		{},
		L"147",
		L"�̴�",
		1,
		148
		);

	_pokemonContainer[147] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Dragon },
			{

				61, //HP
				84 + 35.f, //Attack
				65 + 35.f, //Defence
				70, //Speed

			},
		{},
		L"148",
		L"�ŷ�",
		2,
		149
		);

	_pokemonContainer[148] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

	curPokemon = Pokemon
	(
		{ PokemonType::Dragon, PokemonType::Flying },
			{

				91, //HP
				134 + 50.f, //Attack
				95 + 50.f, //Defence
				80, //Speed

			},
		{},
		L"149",
		L"������",
		3,
		0
		);

	_pokemonContainer[149] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ����_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Psychic },
			{

				106, //HP
				110 + 77.f, //Attack
				90 + 77.f, //Defence
				140, //Speed

			},
		{},
		L"150",
		L"����",
		4,
		0
		);

	_pokemonContainer[150] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region ��_�迭

	curPokemon = Pokemon
	(
		{ PokemonType::Psychic},
			{

				100, //HP
				100 + 50.f, //Attack
				100 + 50.f, //Defence
				100, //Speed

			},
		{},
		L"151",
		L"��",
		4,
		0
		);

	_pokemonContainer[151] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion


}

float PokemonManager::GetRealValue(float groupValue, float objectVel, float effortValue, float lv)
{
	return ((groupValue * 2) + objectVel + (effortValue / 4)) * lv / 100 + 5;
}