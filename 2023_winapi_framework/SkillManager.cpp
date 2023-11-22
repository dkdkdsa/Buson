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
	map<int, vector<wstring>> dark
	{

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	_learnSkillContainer.insert({PokemonType::Dark, dark});

}

void SkillManager::LearnSkill(PokemonType type, int evolutionCount, wstring* arr)
{

	//복사로 가져오기
	auto container = _learnSkillContainer[type][evolutionCount];

	for (int i = 0; i < 1000; i++) {

		int idx1 = rand() % container.size();
		int idx2 = rand() % container.size();

		std::swap(container[idx1], container[idx2]);

	}

	for (int i = 0; i < 4; i++) {


		*(arr + i) = container[i];

	}

}