#include "pch.h"
#include "Battle_PokemonBtn.h"
#include "BattleUIMgr.h"
#include "Texture.h"
#include "Core.h"
#include "KeyMgr.h"
Battle_PokemonBtn::Battle_PokemonBtn() : UIButton(L"Battle_PokemonBtn.bmp", L"Texture\\Battle\\Button\\Battle_PokemonBtn.bmp", { 0, 0 }, { 512, 406 })
{
	m_strName = L"Battle_PokemonBtn";
	m_vScale = Vec2({ _mainTex->GetWidth() * 2, _mainTex->GetHeight() * 2 });
	auto screenPoint = Core::GetInst()->GetResolution();
	SetPos(Vec2(
		{ (long)(507 - (m_vScale.x / 2))
		, (long)(screenPoint.y - m_vScale.y + 11) }));
}

Battle_PokemonBtn::~Battle_PokemonBtn()
{
}

void Battle_PokemonBtn::Update()
{
	_btnRt = RECT_MAKE((long)m_vPos.x, (long)m_vPos.y, (long)m_vScale.x * 2, (long)m_vScale.y * 2);

	if (KEY_DOWN(KEY_TYPE::LBUTTON) && PtInRect(&_btnRt, KeyMgr::GetInst()->GetMousePos())) {

		OnClick();
	}
}

void Battle_PokemonBtn::Render(HDC _dc)
{

	int w = _mainTex->GetWidth();
	int h = _mainTex->GetHeight();

	TransparentBlt(
		_dc,
		m_vPos.x - m_vScale.x / 2,
		m_vPos.y - m_vScale.y / 2,
		m_vScale.x,
		m_vScale.y,
		_mainTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

}

void Battle_PokemonBtn::OnClick()
{
	BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::PokemonSelect);
}
