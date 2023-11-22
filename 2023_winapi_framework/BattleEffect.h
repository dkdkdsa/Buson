#pragma once
#include "Skill.h"
class BattleEffect
{
public:
	BattleEffect(BattleEffectGroup battleEffectGroup);
	~BattleEffect();
public:
	void Execution(BattleEffectGroup battleEffectGroup);
};