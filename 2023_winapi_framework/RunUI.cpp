#include "pch.h"
#include "RunUI.h"

RunUI::RunUI() : BattleUI(L"BattleSceneBackground.bpm", L"Texture\\Battle\\BattleSceneBackground.bpm", { 0, 0 }, { 1280, 720 })
{
	SetEnable(false);
}

RunUI::~RunUI()
{
}
