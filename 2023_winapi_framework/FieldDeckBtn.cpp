#include "pch.h"
#include "FieldDeckBtn.h"
#include "FieldDeckPanel.h"
#include "TimeMgr.h"
#include "Texture.h"
#include "EasingManager.h"

FieldDeckBtn::FieldDeckBtn(Vec2 pos, Vec2 scale) : UIButton(L"DeckBtn", L"Texture\\Field\\PkBtn.bmp", pos, scale)
{

	_isFold = true;
	_isClick = false;
	_per = 0;
	_origin = pos;
	m_vScale = scale;
	originScale = scale;

}

FieldDeckBtn::~FieldDeckBtn()
{
}

void FieldDeckBtn::Update()
{

	UIButton::Update();

	if (isHover && _isFold) {

		_hoverPer += fDT * 2.f;

	}
	else {

		_hoverPer -= fDT * 2.f;

	}

	_hoverPer = std::clamp(_hoverPer, 0.f, 1.f);

	m_vScale = EasingManager::GetInst()->EasingVec(originScale, originScale + Vec2(20, 20), _hoverPer, Ease::InOutBack);

	if (!_isClick) return;

	_per += fDT * 3;

	if (_per < 1) {


		SetPos(Lerp(_origin, _end, _per));
		_panel->SetPos(Lerp(_panelOrigin, _panelEnd, _per));

	}
	else {

		_panel->SetPos(_panelEnd);
		SetPos(_end);
		_isClick = false;

	}

}

void FieldDeckBtn::OnClick()
{

	if (_isClick) return;

	if (_isFold) {

		_origin = m_vPos;
		_panelOrigin = _panel->GetPos();

		_end = _origin + Vec2({ 500, 0});
		_panelEnd = _panelOrigin + Vec2({ 500, 0 });

	}
	else {

		_origin = m_vPos;
		_panelOrigin = _panel->GetPos();

		_end = _origin - Vec2({ 500, 0 });
		_panelEnd = _panelOrigin - Vec2({ 500, 0 });

	}

	_per = 0;
	_isFold = !_isFold;
	_isClick = true;

}

void FieldDeckBtn::Render(HDC _dc)
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
