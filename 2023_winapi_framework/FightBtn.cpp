#include "pch.h"
#include "FightBtn.h"
#include "BattleUIMgr.h"

FightBtn::FightBtn() : UIButton(L"Battle_FightBtn.bmp", L"Texture\\Battle\\Button\\Battle_FightBtn.bmp", Vec2({ 300, 100 }), Vec2({ 300, 75 }))
{
	// 눌렀을 때 enable을 만들어서 Render 시 enable이 true 인것만 렌더링 하도록 하면 될 것 같음

	//판넬을 만들고 그 속에 버튼을 넣어 판넬에서 하위 버튼들을 렌더링하도록
	//예) 기술 선택 판넬에서는 기술 버튼 4개와 취소 버튼 1개를 가지고 있고 이를 렌더링
	//행동 선택 판넬에서는 싸운다, 포켓몬, 가방, 도망 버튼을 가지고 이를 렌더링한다.
}

FightBtn::~FightBtn()
{
}

void FightBtn::OnClick()
{
	BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::SkillSelect);
}