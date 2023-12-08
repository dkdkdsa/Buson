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

		Vec2 pos = Lerp(_origin, _end, _per);

		SetPos(pos);
		_panel->SetPos(pos);

	}
	else {

		_isClick = false;

	}

}

void FieldDeckBtn::OnClick()
{

	if (_isFold) {

		_origin = m_vPos;
		_end = _origin + Vec2({300, 0});
		_per = 0;

	}
	else {

		_origin = m_vPos;
		_end = _origin - Vec2({ 300, 0 });
		_per = 0;

	}

	_isFold = !_isFold;
	_isClick = true;

}
