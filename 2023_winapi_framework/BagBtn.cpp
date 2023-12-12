#include "pch.h"
#include "BagBtn.h"
#include "BattleUIMgr.h"

BagBtn::BagBtn() : UIButton(L"Battle_BagBtn.bpm", L"Texture\\Battle\\Button\\Battle_BagBtn.bpm", { 0, 0 }, { 300, 75 })
{
}

BagBtn::~BagBtn()
{
}

void BagBtn::OnClick()
{
	BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::Bag);
}
