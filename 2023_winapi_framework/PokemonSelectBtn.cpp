#include "pch.h"
#include "PokemonSelectBtn.h"
#include "Texture.h"

PokemonSelectBtn::PokemonSelectBtn() : UIButton(L"NullPokemonSelectedBtn.bmp", L"Texture\\Battle\\Button\\NullPokemonSelectedBtn.bmp", { 0, 0 }, { 300, 75 })
{
}

PokemonSelectBtn::~PokemonSelectBtn()
{
}

void PokemonSelectBtn::Render(HDC _dc)
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

void PokemonSelectBtn::OnClick()
{

}
