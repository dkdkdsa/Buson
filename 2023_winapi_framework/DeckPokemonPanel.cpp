#include "pch.h"
#include "DeckPokemonPanel.h"
#include "DeckManager.h"
#include "Texture.h"
#include "pokemon.h"
#include "Field.h"
#include "ResMgr.h"
#include "KeyMgr.h"

DeckPokemonPanel::DeckPokemonPanel(Vec2 pos, Vec2 scale, Vec2 offset, int idx) : UIButton(L"PokemonBox", L"Texture\\Field\\PokemonBox.bmp", pos, scale)
{

	m_vPos = pos;
	m_vScale = scale;
	curIdx = idx;
	this->offset = offset;
	

}

DeckPokemonPanel::~DeckPokemonPanel()
{
}

void DeckPokemonPanel::SetField(Field* field)
{

	curField = field;

}

void DeckPokemonPanel::Update()
{

	_btnRt = RECT_MAKE((long)m_vPos.x + (long)offset.x, (long)m_vPos.y + (long)offset.y, (long)m_vScale.x, (long)m_vScale.y);

	if (KEY_DOWN(KEY_TYPE::LBUTTON) && PtInRect(&_btnRt, KeyMgr::GetInst()->GetMousePos())) {

		OnClick();

	}

	curPokemon = DeckManager::GetInst()->GetPokemonByIdx(curIdx);


}

void DeckPokemonPanel::Render(HDC _dc)
{

	int w = _mainTex->GetWidth();
	int h = _mainTex->GetHeight();

	TransparentBlt(
		_dc,
		(m_vPos.x + offset.x) - m_vScale.x / 2,
		(m_vPos.y + offset.y) - m_vScale.y / 2,
		m_vScale.x,
		m_vScale.y,
		_mainTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	if (curPokemon == nullptr) return;

	Texture* pokemonTex = ResMgr::GetInst()->FindPokemonTexture(curPokemon->SpriteKey, PokemonSprite_Type::Field);

	int pW = pokemonTex->GetWidth();
	int pH = pokemonTex->GetHeight();

	TransparentBlt(
		_dc,
		(int)((m_vPos.x + offset.x) - m_vScale.x / 2) + 5,
		(int)((m_vPos.y + offset.y) - m_vScale.y / 2) + 15,
		45,
		45,
		pokemonTex->GetDC(),
		0,
		0,
		pW,
		pH,
		RGB(255, 0, 255));

	COLORREF oldColor = SetTextColor(_dc, RGB(255, 255, 255));
	SetBkMode(_dc, 1);

	HFONT font = ResMgr::GetInst()->LoadFont(L"Font\\neodgm.ttf", L"NeoµÕ±Ù¸ð", 20);
	HFONT oldFont = (HFONT)SelectObject(_dc, font);

	TextOut(_dc, (m_vPos.x + offset.x) - 40, (m_vPos.y + offset.y) - 10, curPokemon->PokemonName.c_str(), curPokemon->PokemonName.length());

	SetTextColor(_dc, oldColor);
	SelectObject(_dc, oldFont);
	DeleteObject(font);

}

void DeckPokemonPanel::OnClick()
{

	if (curPokemon == nullptr) return;

	curField->AddPokemon(*curPokemon);
	DeckManager::GetInst()->RemovePokemonByIdx(curIdx);
	curPokemon = nullptr;

}

