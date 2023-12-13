#include "pch.h"
#include "Battle_CancelBtn.h"
#include "BattleUIMgr.h"
#include "Texture.h"
#include "Core.h"
Battle_CancelBtn::Battle_CancelBtn() : UIButton(L"Battle_CancelBtn.bmp", L"Texture\\Battle\\Button\\Battle_CancelBtn.bmp", { 0, 0 }, { 512, 406 })
{
	m_strName = L"Battle_CancelBtn";
	m_vScale = Vec2({ _mainTex->GetWidth() * 2, _mainTex->GetHeight() * 2 });
	auto screenPoint = Core::GetInst()->GetResolution();
	SetPos(Vec2(
		{ (long)(256 - (m_vScale.x / 2))
		, (long)(screenPoint.y - m_vScale.y - 16) }
	));
}

Battle_CancelBtn::~Battle_CancelBtn()
{
}

void Battle_CancelBtn::Render(HDC _dc)
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

void Battle_CancelBtn::OnClick()
{
	BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::ActionSelect);
}