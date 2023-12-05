#include "pch.h"
#include "BattleUI.h"
#include "Texture.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "SceneMgr.h"

BattleUI::BattleUI(wstring textureKey, wstring path, Vec2 pos, Vec2 scale)
{
	_mainTex = nullptr;
	m_vPos = pos;

	if (_mainTex != nullptr) {

		m_vScale = Vec2({ _mainTex->GetWidth(), _mainTex->GetHeight() });

	}
	else {

		m_vScale = scale;

	}

	_uiRect = RECT_MAKE((long)pos.x, (long)pos.y, (long)scale.x, (long)scale.y);
	SetEnable(false);
}

BattleUI::~BattleUI()
{

}

void BattleUI::Update()
{
	Object::Update();
	for (int i = 0; i < _buttons.size(); ++i) {
		_buttons[i].Update();
	}
}

void BattleUI::Render(HDC _dc)
{
	if (_mainTex == nullptr) {
		RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);
	}
	else {
		TransparentBlt(
			_dc,
			m_vPos.x - m_vScale.x / 2,
			m_vPos.y - m_vScale.y / 2,
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