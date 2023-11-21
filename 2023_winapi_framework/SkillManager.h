#pragma once
class Skill;
class SkillManager
{

	SINGLE(SkillManager);

private:
	map<wstring, Skill*> _skillContainer;

public:
	void Init();
	Skill* GetSkill(wstring key) {

		return _skillContainer[key];

	}

};

