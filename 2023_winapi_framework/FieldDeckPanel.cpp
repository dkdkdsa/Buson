#include "pch.h"
#include "FieldDeckPanel.h"

FieldDeckPanel::FieldDeckPanel(Vec2 pos, Vec2 scale)
{

	m_vPos = pos;
	m_vScale = scale;

}

FieldDeckPanel::~FieldDeckPanel()
{
}

void FieldDeckPanel::Render(HDC _dc)
{

	RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);

}
