#include "pch.h"
#include "BattleBtn.h"

BattleBtn::BattleBtn() : UIButton(L"asdf", L"asdf", Vec2({ 300, 100 }), Vec2({ 300, 75 }))
{
}

BattleBtn::~BattleBtn()
{
}

void BattleBtn::OnClick()
{
	// 눌렀을 때 어떤 버튼이냐에 따라 다르게 실행해줘야함
}