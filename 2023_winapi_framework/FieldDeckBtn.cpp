#include "pch.h"
#include "FieldDeckBtn.h"
#include "FieldDeckPanel.h"
#include "TimeMgr.h"

FieldDeckBtn::FieldDeckBtn(Vec2 pos, Vec2 scale) : UIButton(L"DeckBtn", L"Texture\\Field\\PkBtn.bmp", pos, scale)
{

	_isFold = true;
	_isClick = false;
	_per = 0;
	_origin = pos;

}

FieldDeckBtn::~FieldDeckBtn()
{
}

void FieldDeckBtn::Update()
{

	UIButton::Update();

	if (!_isClick) return;

	_per += fDT * 3;

	if (_per < 1) {


		SetPos(Lerp(_origin, _end, _per));
		_panel->SetPos(Lerp(_panelOrigin, _panelEnd, _per));

	}
	else {

		_isClick = false;

	}

}

void FieldDeckBtn::OnClick()
{

	if (_isClick) return;

	if (_isFold) {

		_origin = m_vPos;
		_panelOrigin = _panel->GetPos();

		_end = _origin + Vec2({300, 0});
		_panelEnd = _panelOrigin + Vec2({ 300, 0 });

	}
	else {

		_origin = m_vPos;
		_panelOrigin = _panel->GetPos();

		_end = _origin - Vec2({ 300, 0 });
		_panelEnd = _panelOrigin - Vec2({ 300, 0 });

	}

	_per = 0;
	_isFold = !_isFold;
	_isClick = true;

}
