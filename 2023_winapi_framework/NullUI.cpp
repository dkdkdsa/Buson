#include "pch.h"
#include "NullUI.h"
#include "Texture.h"
NullUI::NullUI() : BattleUI(L"BattleSceneBackground.bmp", L"Texture\\Battle\\BattleSceneBackground.bmp", { 256, 1209 }, { 512, 406 })
{
	m_strName = L"NullUI";
}

NullUI::~NullUI()
{
}

void NullUI::Init()
{
}

void NullUI::Update()
{
}

void NullUI::Render(HDC _dc)
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
