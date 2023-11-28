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

		{1, {L"ex1", L"ex2", L"ex3", L"ex4"}}

	};

	_learnSkillContainer.insert({PokemonType::Grass, grass});

}

vector<wstring> SkillManager::LearnSkill(PokemonType type, int evolutionCount)
{

	//복사로 가져오기
	auto container = _learnSkillContainer[type][evolutionCount];
	vector<wstring> result;

	for (int i = 0; i < 1000; i++) {

		int idx1 = rand() % container.size();
		int idx2 = rand() % container.size();

		std::swap(container[idx1], container[idx2]);

	}

	for (int i = 0; i < 4; i++) {


		result.push_back(container[i]);

	}

	return result;

}