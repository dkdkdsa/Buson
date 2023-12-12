#include "pch.h"
#include "RunBtn.h"
#include "BattleUIMgr.h"

RunBtn::RunBtn() : UIButton(L"Battle_RunBtn.bpm", L"Texture\\Battle\\Button\\Battle_RunBtn.bpm", { 0, 0 }, { 300, 75 })
{
}

RunBtn::~RunBtn()
{
}

void RunBtn::OnClick()
{
	BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::Run);
}
