#include "pch.h"
#include "BattleEffect.h"

BattleEffect::BattleEffect(BattleEffectGroup battleEffectGroup)
{
	switch (battleEffectGroup)
	{
	case BattleEffectGroup::Poison:
		break;
	case BattleEffectGroup::Burn:
		break;
	case BattleEffectGroup::Paralysis:
		break;
	case BattleEffectGroup::Sleep:
		break;
	case BattleEffectGroup::Freeze:
		break;
	case BattleEffectGroup::Confusion:
		break;
	case BattleEffectGroup::Flinch:
		break;
	default:
		break;
	}
}

BattleEffect::~BattleEffect()
{
}

void BattleEffect::Execution(BattleEffectGroup battleEffectGroup)
{

}
