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

#pragma region 이상해씨_계열

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
			L"이상해씨",
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
			L"이상해풀",
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
			L"이상해꽃",
			3,
			0
			);

	_pokemonContainer[3] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);

#pragma endregion

#pragma region 파이리_계열

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
			L"파이리",
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
			L"리자드",
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
		L"리자몽",
		3,
		0

		);


	_pokemonContainer[6] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);

#pragma endregion

#pragma region 꼬부기_계열

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
			L"꼬부기",
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
			L"어니부기",
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
			L"거북왕",
			3,
			0
	);

	_pokemonContainer[9] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);


#pragma endregion

#pragma region 캐터피_계열

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
		L"캐터피",
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
		L"단데기",
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
		L"버터플",
		3,
		0
		);

	_pokemonContainer[12] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);

#pragma endregion

#pragma region 뿔충이_계열

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
		L"뿔충이",
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
		L"딱충이",
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
		L"독침붕",
		3,
		0
		);

	_pokemonContainer[15] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);

#pragma endregion

#pragma region 구구_계열


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
		L"구구",
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
		L"피죤",
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
		L"피죤투",
		3,
		0
		);

	_pokemonContainer[18] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);


#pragma endregion

#pragma region 꼬렛_계열

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
		L"꼬렛",
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
		L"레트라",
		2,
		0
		);

	_pokemonContainer[20] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

#pragma endregion

#pragma region 깨비참_계열

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
		L"깨비참",
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
		L"깨비드릴조",
		2,
		0
		);

	_pokemonContainer[22] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

#pragma endregion

#pragma region 아보_계열

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
		L"아보",
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
		L"아보크",
		2,
		0
		);

	_pokemonContainer[24] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

#pragma endregion

#pragma region 피카츄_계열

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
		L"피카츄",
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
		L"라이츄",
		2,
		0
		);

	_pokemonContainer[26] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

#pragma endregion

#pragma region 모래두지_계열

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
		L"모래두지",
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
		L"고지",
		2,
		0
		);

	_pokemonContainer[28] = curPokemon;
	_levelPokemonContainer[2].push_back(curPokemon);

#pragma endregion

#pragma region 니드런_여_계열

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
		L"니드런♀",
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
		L"니드리나",
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
		L"니드퀸",
		3,
		0
		);

	_pokemonContainer[31] = curPokemon;
	_levelPokemonContainer[3].push_back(curPokemon);

#pragma endregion

#pragma region 니드런_남_계열

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
		L"니드런♂",
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
		L"니드리노",
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
		L"니드킹",
		3,
		0
		);

	_pokemonContainer[34] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 삐삐_계열

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
		L"삐삐",
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
		L"픽시",
		2,
		0
		);

	_pokemonContainer[36] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 식스테일_계열

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
		L"식스테일",
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
		L"나인테일",
		2,
		0
		);

	_pokemonContainer[38] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 푸린_계열

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
		L"푸린",
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
		L"푸크린",
		2,
		0
		);

	_pokemonContainer[40] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 주뱃_계열

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
		L"주뱃",
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
		L"골뱃",
		2,
		0
		);

	_pokemonContainer[42] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 뚜벅쵸_계열

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
		L"뚜벅쵸",
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
		L"냄새꼬",
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
		L"라플레시아",
		3,
		0
		);

	_pokemonContainer[45] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 파라스_계열

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
		L"파라스",
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
		L"파라섹트",
		2,
		0
		);

	_pokemonContainer[47] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 콘팡_계열

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
		L"콘팡",
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
		L"도나리",
		2,
		0
		);

	_pokemonContainer[49] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 디그다_계열

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
		L"디그다",
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
		L"닥트리오",
		2,
		0
		);

	_pokemonContainer[51] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 나옹_계열

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
		L"나옹",
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
		L"페르시온",
		2,
		0
		);

	_pokemonContainer[53] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 고라파덕_계열

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
		L"고라파덕",
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
		L"골덕",
		2,
		0
		);

	_pokemonContainer[55] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 망키_계열

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
		L"망키",
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
		L"성원숭",
		2,
		0
		);

	_pokemonContainer[57] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);



#pragma endregion

#pragma region 가디_계열

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
		L"가디",
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
		L"윈디",
		2,
		0
		);

	_pokemonContainer[59] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 발챙이_계열

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
		L"발챙이",
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
		L"수륙챙이",
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
		L"강챙이",
		3,
		0
		);

	_pokemonContainer[62] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 캐이시_계열

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
		L"캐이시",
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
		L"윤겔라",
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
		L"후딘",
		3,
		0
		);

	_pokemonContainer[65] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion


#pragma region 알통몬_계열

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
		L"알통몬",
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
		L"근육몬",
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
		L"괴력몬",
		3,
		0
		);

	_pokemonContainer[68] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 모다피_계열

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
		L"모다피",
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
		L"우츠동",
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
		L"우츠보트",
		3,
		0
		);

	_pokemonContainer[71] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 왕눈해_계열

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
		L"왕눈해",
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
		L"독파리",
		2,
		0
		);

	_pokemonContainer[73] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 꼬마돌_계열

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
		L"꼬마돌",
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
		L"데구리",
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
		L"딱구리",
		3,
		0
		);

	_pokemonContainer[76] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 포니타_계열

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
		L"포니타",
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
		L"날쌩마",
		2,
		0
		);

	_pokemonContainer[78] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 야돈_계열

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
		L"야돈",
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
		L"야도란",
		2,
		0
		);

	_pokemonContainer[80] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 코일_계열

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
		L"코일",
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
		L"레어코일",
		2,
		0
		);

	_pokemonContainer[82] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 파오리_계열

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
		L"파오리",
		1,
		0
		);

	_pokemonContainer[83] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 두두_계열

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
		L"두두",
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
		L"두트리오",
		2,
		0
		);

	_pokemonContainer[85] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 쥬쥬_계열

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
		L"쥬쥬",
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
		L"쥬레곤",
		2,
		0
		);

	_pokemonContainer[87] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 질퍽이_계열

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
		L"질퍽이",
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
		L"질뻐기",
		2,
		0
		);

	_pokemonContainer[89] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 셀러_계열

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
		L"셀러",
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
		L"파르셀",
		2,
		0
		);

	_pokemonContainer[91] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 고오스_계열

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
		L"고오스",
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
		L"고우스트",
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
		L"팬텀",
		3,
		0
		);

	_pokemonContainer[94] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 롱스톤_계열

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
		L"롱스톤",
		1,
		0
		);

	_pokemonContainer[95] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion


#pragma region 슬리프_계열

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
		L"슬리프",
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
		L"슬리퍼",
		2,
		0
		);

	_pokemonContainer[97] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 크랩_계열

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
		L"그랩",
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
		L"킹그랩",
		2,
		0
		);

	_pokemonContainer[99] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 찌리리공_계열

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
		L"찌리리공",
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
		L"붐볼",
		2,
		0
		);

	_pokemonContainer[101] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 아라리_계열

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
		L"아라리",
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
		L"나시",
		2,
		0
		);

	_pokemonContainer[103] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 탕구리_계열


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
		L"탕구리",
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
		L"텅구리",
		2,
		0
		);

	_pokemonContainer[105] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 시라소몬_계열

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
		L"시라소몬",
		1,
		0
		);

	_pokemonContainer[106] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 홍수몬_계열

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
		L"홍수몬",
		1,
		0
		);

	_pokemonContainer[107] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 내루미_계열

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
		L"내루미",
		1,
		0
		);

	_pokemonContainer[108] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 또가스_계열


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
		L"또가스",
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
		L"또도가스",
		2,
		0
		);

	_pokemonContainer[110] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 뿔카노_계열

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
		L"뿔카노",
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
		L"코뿌리",
		2,
		0
		);

	_pokemonContainer[112] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 럭키_계열

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
		L"럭키",
		1,
		0
		);

	_pokemonContainer[113] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 덩쿠리_계열

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
		L"덩쿠리",
		1,
		0
		);

	_pokemonContainer[114] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 캥카_계열

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
		L"캥카",
		1,
		0
		);

	_pokemonContainer[115] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 쏘드라_계열

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
		L"쏘드라",
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
		L"씨드라",
		2,
		0
		);

	_pokemonContainer[117] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 콘치_계열

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
		L"콘치",
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
		L"왕콘치",
		2,
		0
		);

	_pokemonContainer[119] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 별가사리_계열

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
		L"별가사리",
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
		L"아쿠스타",
		2,
		0
		);

	_pokemonContainer[121] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion


#pragma region 마임맨_계열

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
		L"마임맨",
		1,
		0
		);

	_pokemonContainer[122] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 스라크_계열


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
		L"스라크",
		1,
		0
		);

	_pokemonContainer[123] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 루주라_계열

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
		L"루주라",
		1,
		0
		);

	_pokemonContainer[124] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 에레브_계열

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
		L"에레브",
		1,
		0
		);

	_pokemonContainer[125] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 마그마_계열

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
		L"마그마",
		1,
		0
		);

	_pokemonContainer[126] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 쁘사이저_계열

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
		L"쁘사이저",
		1,
		0
		);

	_pokemonContainer[127] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 켄타로스_계열

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
		L"켄타로스",
		1,
		0
		);

	_pokemonContainer[128] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 잉어킹_계열

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
		L"잉어킹",
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
		L"갸라도스",
		2,
		0
		);

	_pokemonContainer[130] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 라프라스_계열

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
		L"라프라스",
		1,
		0
		);

	_pokemonContainer[131] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);


#pragma endregion

#pragma region 메타몽_계열

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
		L"메타몽",
		1,
		-2
		);

	_pokemonContainer[132] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 이브이_계열

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
		L"이브이",
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
		L"샤미드",
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
		L"쥬피썬더",
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
		L"부스터",
		2,
		0
		);

	_pokemonContainer[136] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 폴리곤_계열

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
		L"폴리곤",
		1,
		0
		);

	_pokemonContainer[137] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion


#pragma region 암나이트_계열

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
		L"암나이트",
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
		L"암스타",
		2,
		0
		);

	_pokemonContainer[139] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 투구_계열

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
		L"투구",
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
		L"투구푸스",
		2,
		0
		);

	_pokemonContainer[141] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 프테라_계열

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
		L"프테라",
		1,
		0
		);

	_pokemonContainer[142] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 잠만보_계열

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
		L"잠만보",
		1,
		0
		);

	_pokemonContainer[143] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 프리저_계열

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
		L"프리저",
		4,
		0
		);

	_pokemonContainer[144] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 썬더_계열

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
		L"썬더",
		4,
		0
		);

	_pokemonContainer[145] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 썬더_계열

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
		L"파이어",
		4,
		0
		);

	_pokemonContainer[146] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);


#pragma endregion


#pragma region 미뇽_계열

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
		L"미뇽",
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
		L"신룡",
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
		L"망나룡",
		3,
		0
		);

	_pokemonContainer[149] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 뮤츠_계열

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
		L"뮤츠",
		4,
		0
		);

	_pokemonContainer[150] = curPokemon;
	_levelPokemonContainer[curPokemon.EvolutionCount].push_back(curPokemon);

#pragma endregion

#pragma region 뮤_계열

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
		L"뮤",
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