#include "pch.h"
#include "SkillSelectBtn.h"
#include "BattleUIMgr.h"
#include "Texture.h"
#include "Core.h"



SkillSelectBtn::SkillSelectBtn() : UIButton(L"NormalBtn.bmp", L"Texture\\Battle\\Button\\NormalBtn.bmp", { 256, 1209 }, { 512, 406 })
{
	m_strName = L"SkillSelectBtn";
	m_vScale = Vec2({ _mainTex->GetWidth() * 2, _mainTex->GetHeight() * 2 });
}

SkillSelectBtn::~SkillSelectBtn()
{
}

void SkillSelectBtn::Render(HDC _dc)
{

	int w = _mainTex->GetWidth();
	int h = _mainTex->GetHeight();

	TransparentBlt(
		_dc,
		m_vPos.x,
		m_vPos.y,
		m_vScale.x,
		m_vScale.y,
		_mainTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

}

void SkillSelectBtn::OnClick()
{
	// ���� ��Ʋ �� ��Ʋ ����Ŭ�ϰ� �����ؼ�
	// ���⼭ ������ �ϸ� ��Ʋ ����Ŭ �����ؼ�
	// �� �� ���ư����� �������
}

void SkillSelectBtn::PosInit(BtnPos _btnpos)
{
	switch (_btnpos) {
	case BtnPos::LT:
		SetPos(Vec2(
			{ (long)(128 - (m_vScale.x / 2))
			, (long)((203 - (m_vScale.y / 2)) * 3) - 2 }));
		break;
	case BtnPos::LB:
		SetPos(Vec2(
			{ (long)(128 - (m_vScale.x / 2))
			, (long)((203 - (m_vScale.y / 2)) * 3.8f) + 4 }));
		break;
	case BtnPos::RT:
		SetPos(Vec2(
			{ (long)(384 - (m_vScale.x / 2))
			, (long)((203 - (m_vScale.y / 2)) * 3) - 2 }));
		break;
	case BtnPos::RB:
		SetPos(Vec2(
			{ (long)(384 - (m_vScale.x / 2))
			, (long)((203 - (m_vScale.y / 2)) * 3.8f) + 4 }));
		break;
	}
}
