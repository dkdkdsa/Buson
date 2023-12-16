#include "pch.h"
#include "PokemonShiftBtn.h"
#include "Texture.h"
#include "ResMgr.h"
#include "pokemon.h"
#include "KeyMgr.h"
#include "Core.h"
#include "BattleMgr.h"
#include "BattleUIMgr.h"
#include "ResMgr.h"
PokemonShiftBtn::PokemonShiftBtn() : UIButton(L"ShiftPokemonBtn.bmp", L"Texture\\Battle\\Button\\ShiftPokemonBtn.bmp", { 0, 0 }, { 512, 406 })
{
	m_strName = L"PokemonShiftBtn";
	m_vScale = Vec2({ _mainTex->GetWidth() * 2, _mainTex->GetHeight() * 2 });
	auto screenPoint = Core::GetInst()->GetResolution();
	m_vPos = Vec2({ (long)(256 - (m_vScale.x / 2)), (long)(screenPoint.y / 4 * 2.7f - (m_vScale.y / 2)) });
	_pokemonTex = ResMgr::GetInst()->FindPokemonTexture(L"001", PokemonSprite_Type::Field);
	_pokemonTexScale = Vec2({ _pokemonTex->GetWidth(), _pokemonTex->GetHeight() });
	_pokemonTexPos = Vec2({ (int)(256 - (_pokemonTexScale.x / 2)), (int)(screenPoint.y / 3 * 2) });
}

PokemonShiftBtn::~PokemonShiftBtn()
{
}

void PokemonShiftBtn::Update()
{
	_btnRt = RECT_MAKE((int)(m_vPos.x + (m_vScale.x / 2)), (int)(m_vPos.y + (m_vScale.y / 2)), (int)(m_vScale.x), (int)(m_vScale.y));

	if (KEY_DOWN(KEY_TYPE::LBUTTON) && PtInRect(&_btnRt, KeyMgr::GetInst()->GetMousePos())) {

		OnClick();
	}
}

void PokemonShiftBtn::Render(HDC _dc)
{
	int w = _mainTex->GetWidth();
	int h = _mainTex->GetHeight();

	TransparentBlt(
		_dc,
		m_vPos.x,
		m_vPos.y,
		m_vScale.x,
		m_vScale.y,
		_mainTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	w = _pokemonTex->GetWidth();
	h = _pokemonTex->GetHeight();

	TransparentBlt(
		_dc,
		_pokemonTexPos.x,
		_pokemonTexPos.y,
		_pokemonTexScale.x,
		_pokemonTexScale.x,
		_pokemonTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	HFONT font = ResMgr::GetInst()->LoadFont(L"Font\\neodgm.ttf", L"NeoµÕ±Ù¸ð", 23);
	HFONT oldFont = (HFONT)SelectObject(_dc, font);
	wstring shiftTxt = L"SHIFT";
	COLORREF oldColor = SetTextColor(_dc, RGB(255, 255, 255));
	SetBkMode(_dc, 1);

	TextOut(_dc, _pokemonTexPos.x - 20, _pokemonTexPos.y - 50, _pokemon->PokemonName.c_str(), _pokemon->PokemonName.length());
	TextOut(_dc, _pokemonTexPos.x, _pokemonTexPos.y + 70, shiftTxt.c_str(), shiftTxt.length());

	SelectObject(_dc, oldFont);
	SetTextColor(_dc, oldColor);
	DeleteObject(font);
}

void PokemonShiftBtn::OnClick()
{
	BattleMgr::GetInst()->ChangeCurPokemon(_pokemon);
	BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::ActionSelect);
	ResMgr::GetInst()->Play(L"ButtonClick");
}

void PokemonShiftBtn::SetPokemon(Pokemon* pokemon)
{
	_pokemon = pokemon;
	_pokemonTex = ResMgr::GetInst()->FindPokemonTexture(_pokemon->SpriteKey, PokemonSprite_Type::Field);
}
