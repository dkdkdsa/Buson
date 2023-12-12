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
