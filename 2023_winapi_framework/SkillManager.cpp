#include "pch.h"
#include "SkillManager.h"
#include "Skill.h"

void SkillManager::Init()
{

	CreateSkill();

}


void SkillManager::CreateSkill()
{

	//ex
	map<int, vector<wstring>> grass
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	map<int, vector<wstring>> fire
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	map<int, vector<wstring>> water
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	map<int, vector<wstring>> electric
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	map<int, vector<wstring>> ice
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	map<int, vector<wstring>> fighting
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	map<int, vector<wstring>> poison
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	map<int, vector<wstring>> ground
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};


	map<int, vector<wstring>> flying
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	map<int, vector<wstring>> psychic
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	map<int, vector<wstring>> bug
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	map<int, vector<wstring>> rock
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	map<int, vector<wstring>> ghost
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	map<int, vector<wstring>> dragon
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	map<int, vector<wstring>> dark
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	map<int, vector<wstring>> steel
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	map<int, vector<wstring>> normal
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{2, {L"ex1", L"ex2", L"ex3", L"ex4"}},
		{3, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	_learnSkillContainer.insert({ PokemonType::Normal, normal });
	_learnSkillContainer.insert({ PokemonType::Fire, fire });
	_learnSkillContainer.insert({ PokemonType::Water, water });
	_learnSkillContainer.insert({ PokemonType::Electric, electric });
	_learnSkillContainer.insert({ PokemonType::Grass, grass });
	_learnSkillContainer.insert({ PokemonType::Ice, ice });
	_learnSkillContainer.insert({ PokemonType::Fighting, fighting });
	_learnSkillContainer.insert({ PokemonType::Poison, poison });
	_learnSkillContainer.insert({ PokemonType::Ground, ground });
	_learnSkillContainer.insert({ PokemonType::Flying, flying });
	_learnSkillContainer.insert({ PokemonType::Psychic, fighting });
	_learnSkillContainer.insert({ PokemonType::Bug, fighting });
	_learnSkillContainer.insert({ PokemonType::Rock, rock });
	_learnSkillContainer.insert({ PokemonType::Ghost, ghost });
	_learnSkillContainer.insert({ PokemonType::Dragon, dragon });
	_learnSkillContainer.insert({ PokemonType::Dark, dark });
	_learnSkillContainer.insert({ PokemonType::Steel, steel });

}

vector<wstring> SkillManager::LearnSkill(vector<PokemonType> types, int evolutionCount)
{

	int len = 4 / types.size();
	vector<wstring> result;

	for (int k = 0; k < types.size(); k++) {

		auto type = types[k];

		//복사로 가져오기
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