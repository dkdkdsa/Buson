#include "pch.h"
#include "FightBtn.h"
#include "BattleUIMgr.h"
#include "Core.h"

FightBtn::FightBtn() : UIButton(L"Battle_FightBtn.bmp", L"Texture\\Battle\\Button\\Battle_FightBtn.bmp", Vec2({ 256, 400 }), Vec2({ 512, 406 }))
{
	//m_vScale = Vec2({ m_vScale.x * 2, m_vScale.y });
	auto screenPoint = Core::GetInst()->GetResolution();
	m_vPos = Vec2({ 0, 500 });
	// �ƴ� �ù� ���⼭ �������� �ٲ�µ� �������� �� �ٲ�
	m_vScale = Vec2({ 100, 100 });
}

FightBtn::~FightBtn()
{
}

void FightBtn::OnClick()
{
	BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::SkillSelect);
}