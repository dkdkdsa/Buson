#include "pch.h"
#include "FightBtn.h"
#include "BattleUIMgr.h"

FightBtn::FightBtn() : UIButton(L"Battle_FightBtn.bmp", L"Texture\\Battle\\Button\\Battle_FightBtn.bmp", Vec2({ 300, 100 }), Vec2({ 300, 75 }))
{
	// ������ �� enable�� ���� Render �� enable�� true �ΰ͸� ������ �ϵ��� �ϸ� �� �� ����

	//�ǳ��� ����� �� �ӿ� ��ư�� �־� �ǳڿ��� ���� ��ư���� �������ϵ���
	//��) ��� ���� �ǳڿ����� ��� ��ư 4���� ��� ��ư 1���� ������ �ְ� �̸� ������
	//�ൿ ���� �ǳڿ����� �ο��, ���ϸ�, ����, ���� ��ư�� ������ �̸� �������Ѵ�.
}

FightBtn::~FightBtn()
{
}

void FightBtn::OnClick()
{
	BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::SkillSelect);
}