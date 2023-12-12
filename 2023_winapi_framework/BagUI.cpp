#include "pch.h"
#include "BagUI.h"

BagUI::BagUI() : BattleUI(L"BattleSceneBackground.bpm", L"Texture\\Battle\\BattleSceneBackground.bpm", { 0, 0 }, { 1280, 720 })
{
	SetEnable(false);
}

BagUI::~BagUI()
{
}
