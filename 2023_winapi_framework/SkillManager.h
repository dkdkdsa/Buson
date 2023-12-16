#pragma once
#include "pokemon.h"

class Skill;
class SkillManager
{

	SINGLE(SkillManager);

private:

	map<wstring, Skill*> _skillContainer;
	map<PokemonType, map<int, vector<wstring>>> _learnSkillContainer;

public:
	void Init();
	Skill* GetSkill(wstring key) {

		return _skillContainer[key];

	}
	vector<wstring> LearnSkill(vector<PokemonType> type, int evolutionCount);

private:
	void CreateSkill();

};

