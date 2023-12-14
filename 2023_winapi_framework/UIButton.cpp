#include "pch.h"
#include "UIButton.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "Texture.h"


UIButton::UIButton(wstring textureKey, wstring path, Vec2 pos, Vec2 scale)
{
	if (textureKey != L"") {

		_mainTex = ResMgr::GetInst()->TexLoad(textureKey, path);

	}

	m_vPos = pos;

	if (_mainTex != nullptr) {

		m_vScale = Vec2({ _mainTex->GetWidth(), _mainTex->GetHeight() });

	}
	else {

		m_vScale = scale;

	}

	_btnSelectorLT = ResMgr::GetInst()->TexLoad(L"BtnSelectorLT.bmp", L"Texture\\Battle\\Button\\BtnSelectorLT.bmp");
	_btnSelectorLB = ResMgr::GetInst()->TexLoad(L"BtnSelectorLB.bmp", L"Texture\\Battle\\Button\\BtnSelectorLB.bmp");
	_btnSelectorRT = ResMgr::GetInst()->TexLoad(L"BtnSelectorRT.bmp", L"Texture\\Battle\\Button\\BtnSelectorRT.bmp");
	_btnSelectorRB = ResMgr::GetInst()->TexLoad(L"BtnSelectorRB.bmp", L"Texture\\Battle\\Button\\BtnSelectorRB.bmp");

	_btnRt = RECT_MAKE((long)pos.x, (long)pos.y, (long)scale.x, (long)scale.y);
}

void UIButton::Update()
{

	_btnRt = RECT_MAKE((long)m_vPos.x, (long)m_vPos.y, (long)m_vScale.x, (long)m_vScale.y);

	if (KEY_DOWN(KEY_TYPE::LBUTTON) && PtInRect(&_btnRt, KeyMgr::GetInst()->GetMousePos())) {

		OnClick();

	}

	CheckHover();

}

void UIButton::Render(HDC _dc)
{

	if (_mainTex == nullptr) {

		RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);

	}
	else
	{

		TransparentBlt(
			_dc,
			m_vPos.x,
			m_vPos.y,
			m_vScale.x,
			m_vScale.y,
			_mainTex->GetDC(),
			0,
			0,
			m_vScale.x,
			m_vScale.y,
			RGB(255, 0, 255));

	}
}

void UIButton::CheckHover()
{

	if (PtInRect(&_btnRt, KeyMgr::GetInst()->GetMousePos())) {

		isHover = true;

	}
	else {

		isHover = false;

	}

}

void UIButton::RenderBtnSelector(HDC _dc)
{
	int w = _btnSelectorLT->GetWidth();
	int h = _btnSelectorLT->GetHeight();

	// LT
	TransparentBlt(
		_dc,
		_btnRt.left - w,
		_btnRt.top - h,
		w,
		h,
		_btnSelectorLT->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	// LB
	TransparentBlt(
		_dc,
		_btnRt.left - w,
		_btnRt.bottom + h,
		w,
		h,
		_btnSelectorLB->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	// RT
	TransparentBlt(
		_dc,
		_btnRt.right + w,
		_btnRt.top - h,
		w,
		h,
		_btnSelectorRT->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	// RB
	TransparentBlt(
		_dc,
		_btnRt.right + w,
		_btnRt.bottom + h,
		w,
		h,
		_btnSelectorRB->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));
}
