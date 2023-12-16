#include "pch.h"
#include "PokemonShiftCancelBtn.h"
#include "Texture.h"
#include "Core.h"
#include "KeyMgr.h"
#include "BattleUIMgr.h"
PokemonShiftCancelBtn::PokemonShiftCancelBtn() : UIButton(L"Battle_CancelBtn.bmp", L"Texture\\Battle\\Button\\Battle_CancelBtn.bmp", { 0, 0 }, { 512, 406 })
{
	m_strName = L"PokemonShiftCancelBtn";
	m_vScale = Vec2({ _mainTex->GetWidth() * 2, _mainTex->GetHeight() });
	auto screenPoint = Core::GetInst()->GetResolution();
	SetPos(Vec2({ (int)(256 - (m_vScale.x / 2)), (int)(screenPoint.y - m_vScale.y * 2 - 16) }));
}

PokemonShiftCancelBtn::~PokemonShiftCancelBtn()
{
}

void PokemonShiftCancelBtn::Update()
{
	_btnRt = RECT_MAKE((long)m_vPos.x, (long)(m_vPos.y + m_vScale.y), (long)m_vScale.x * 2, (long)m_vScale.y);

	if (KEY_DOWN(KEY_TYPE::LBUTTON) && PtInRect(&_btnRt, KeyMgr::GetInst()->GetMousePos())) {

		OnClick();
	}
}

void PokemonShiftCancelBtn::Render(HDC _dc)
{
	int w = _mainTex->GetWidth();
	int h = _mainTex->GetHeight();

	TransparentBlt(
		_dc,
		m_vPos.x,
		m_vPos.y,
		m_vScale.x,
		m_vScale.y * 2,
		_mainTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));
}

void PokemonShiftCancelBtn::OnClick()
{
	BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::PokemonSelect);
}
