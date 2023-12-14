#include "pch.h"
#include "PokemonSelectCancelBtn.h"
#include "Texture.h"
#include "Core.h"
#include "BattleUIMgr.h"
#include "KeyMgr.h"
PokemonSelectCancelBtn::PokemonSelectCancelBtn() : UIButton(L"SelectCancelBtn.bmp", L"Texture\\Battle\\Pokemon_Select\\SelectCancelBtn.bmp", { 0, 0 }, { 300, 75 })
{
	m_strName = L"PokemonSelectCancel";
	m_vScale = Vec2({ _mainTex->GetWidth() * 2, _mainTex->GetHeight() * 2 });
	auto screenPoint = Core::GetInst()->GetResolution();
	SetPos(Vec2(
		{ (long)(512 - m_vScale.x)
		, (long)(790 - m_vScale.y) }));

}

PokemonSelectCancelBtn::~PokemonSelectCancelBtn()
{
}

void PokemonSelectCancelBtn::Update()
{
	_btnRt = RECT_MAKE((long)m_vPos.x, (long)m_vPos.y, (long)m_vScale.x * 2, (long)m_vScale.y * 2);

	if (KEY_DOWN(KEY_TYPE::LBUTTON) && PtInRect(&_btnRt, KeyMgr::GetInst()->GetMousePos())) {

		OnClick();
	}
}

void PokemonSelectCancelBtn::Render(HDC _dc)
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

void PokemonSelectCancelBtn::OnClick()
{
	BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::ActionSelect);
}
