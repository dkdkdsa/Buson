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



}