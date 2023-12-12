#include "pch.h"
#include "BattleUI.h"
#include "Texture.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "SceneMgr.h"
#include "Core.h"
BattleUI::BattleUI(wstring textureKey, wstring path, Vec2 pos, Vec2 scale)
{
	_mainTex = nullptr;
	auto screenPoint = Core::GetInst()->GetResolution();

	//m_vPos = Vec2({ screenPoint.x / 2, screenPoint.y / 2 });
	//m_vScale = Vec2({ screenPoint.x, screenPoint.y / 2 });
	m_vPos = Vec2({ screenPoint.x / 2, 1206 });
	//m_vScale = Vec

	_mainTex = ResMgr::GetInst()->TexLoad(textureKey, path);

	if (_mainTex != nullptr) {
		//m_vScale = Vec2({ _mainTex->GetWidth(), _mainTex->GetHeight() });
		m_vScale = Vec2({ screenPoint.x, screenPoint.y / 2 });
	}
	else {

		m_vScale = scale;
	}

	_uiRect = RECT_MAKE((int)pos.x, (int)pos.y, (int)scale.x, (int)scale.y);
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
			m_vPos.y - m_vScale.y * 2,
			m_vScale.x,
			m_vScale.y,
			_mainTex->GetDC(),
			0,
			0,
			_mainTex->GetWidth(),
			_mainTex->GetHeight(),
			RGB(255, 0, 255));
	}
}