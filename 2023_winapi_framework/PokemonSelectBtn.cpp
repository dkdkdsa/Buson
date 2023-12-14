#include "pch.h"
#include "pokemon.h"
#include "PokemonSelectBtn.h"
#include "Texture.h"
#include "KeyMgr.h"
#include "Core.h"
#include "ResMgr.h"
#include "DeckManager.h"
PokemonSelectBtn::PokemonSelectBtn() : UIButton(L"UnselectedPokemon_2.bmp", L"Texture\\Battle\\Pokemon_Select\\UnselectedPokemon_2.bmp", { 0, 0 }, { 512, 406 })
{

	m_strName = L"PokemonSelectBtn";
	m_vScale = Vec2({ _mainTex->GetWidth() * 2, _mainTex->GetHeight() * 2 });
	auto screenPoint = Core::GetInst()->GetResolution();
}

PokemonSelectBtn::~PokemonSelectBtn()
{

}

void PokemonSelectBtn::Update()
{
	_btnRt = RECT_MAKE((long)m_vPos.x, (long)m_vPos.y, (long)m_vScale.x * 2, (long)m_vScale.y * 2);

	if (KEY_DOWN(KEY_TYPE::LBUTTON) && PtInRect(&_btnRt, KeyMgr::GetInst()->GetMousePos())) {

		OnClick();
	}

	CheckHover();

	
}

void PokemonSelectBtn::Render(HDC _dc)
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

	w = _pokeTex->GetWidth();
	h = _pokeTex->GetHeight();

	TransparentBlt(
		_dc,
		_pokeTexPos.x,
		_pokeTexPos.y,
		48,
		48,
		_pokeTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	w = _hpBarTex->GetWidth();
	h = _hpBarTex->GetHeight();

	TransparentBlt(
		_dc,
		_hpBarPos.x,
		_hpBarPos.y,
		_hpBarScale.x,
		_hpBarScale.y,
		_hpBarTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	HFONT font = ResMgr::GetInst()->LoadFont(L"Font\\neodgm.ttf", L"NeoµÕ±Ù¸ð", 23);
	HFONT oldFont = (HFONT)SelectObject(_dc, font);

	wstring hpText = std::to_wstring((int)_pokemon->Stats.Hp);
	wstring maxHpText = std::to_wstring((int)_maxHp);
	wstring lvText = std::to_wstring(_pokemon->EvolutionCount * 20);
	COLORREF oldColor = SetTextColor(_dc, RGB(255, 255, 255));
	SetBkMode(_dc, 1);
	TextOut(_dc, _hpTxtPos.x, _hpTxtPos.y, hpText.c_str(), hpText.length());
	TextOut(_dc, _maxHpTxtPos.x, _maxHpTxtPos.y, maxHpText.c_str(), maxHpText.length());
	TextOut(_dc, _lvPos.x, _lvPos.y, lvText.c_str(), lvText.length());

	SelectObject(_dc, oldFont);
	SetTextColor(_dc, oldColor);
	DeleteObject(font);
}

void PokemonSelectBtn::OnClick()
{

}

void PokemonSelectBtn::InitPos()
{
	auto screenPoint = Core::GetInst()->GetResolution();
	switch (_partyIdx) {
	case 1: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"UnSelectedPokemon_1.bmp", L"Texture\\Battle\\Pokemon_Select\\UnSelectedPokemon_1.bmp");
		SetPos(Vec2(
			{ (long)(256 - m_vScale.x - 2)
			, (long)(screenPoint.y / 2 - 7) }));
	}
		  break;
	case 2: {
		SetPos(Vec2(
			{ (long)(512 - m_vScale.x - 2)
			, (long)(screenPoint.y / 2 + 10) }));
	}
		  break;
	case 3: {
		SetPos(Vec2(
			{ (long)(256 - m_vScale.x - 2)
			, (long)(screenPoint.y / 2 + 95) }));
	}
		  break;
	case 4: {
		SetPos(Vec2(
			{ (long)(512 - m_vScale.x - 2)
			, (long)(screenPoint.y / 2 + 112) }));
	}
		  break;
	case 5: {
		SetPos(Vec2(
			{ (long)(256 - m_vScale.x - 2)
			, (long)(screenPoint.y / 2 + 196) }));
	}
		  break;
	case 6: {
		SetPos(Vec2(
			{ (long)(512 - m_vScale.x - 2)
			, (long)(screenPoint.y / 2 + 213) }));
	}
		  break;
	}


}

void PokemonSelectBtn::PokemonTexInit()
{
	_pokeTex = ResMgr::GetInst()->FindPokemonTexture(_pokemon->SpriteKey, PokemonSprite_Type::Field);
	_pokeTexScale = Vec2({ _pokeTex->GetWidth() / 1.4f, _pokeTex->GetHeight() / 1.4f });
	InitPos();
	_pokeTexPos = Vec2({ m_vPos.x + 25, m_vPos.y + 10 });

	if (_pokemon->Stats.Hp == 0) {
		if (_partyIdx == 1) {
			_mainTex = ResMgr::GetInst()->TexLoad(L"DiedPokemon_1.bmp", L"Texture\\Battle\\Pokemon_Select\\DiedPokemon_1.bmp");
		}
		else {
			_mainTex = ResMgr::GetInst()->TexLoad(L"DiedPokemon_2.bmp", L"Texture\\Battle\\Pokemon_Select\\DiedPokemon_2.bmp");
		}
	}

	if (_pokemon->Stats.Hp / _maxHp * 100 >= 51.f) {
		_hpBarTex = ResMgr::GetInst()->TexLoad(L"HpGauge_Green.bmp", L"Texture\\Battle\\Pokemon_State\\HpGauge_Green.bmp");
	}
	else if (_pokemon->Stats.Hp / _maxHp * 100 >= 21.f) {
		_hpBarTex = ResMgr::GetInst()->TexLoad(L"HpGauge_Yellow.bmp", L"Texture\\Battle\\Pokemon_State\\HpGauge_Yellow.bmp");
	}
	else {
		_hpBarTex = ResMgr::GetInst()->TexLoad(L"HpGauge_Red.bmp", L"Texture\\Battle\\Pokemon_State\\HpGauge_Red.bmp");
	}

	_hpBarPos = Vec2({ _pokeTexPos.x + 100, _pokeTexPos.y + 36 });
	_hpBarScale = Vec2({ (int)(_pokemon->Stats.Hp / _maxHp * 100), 10 });

	_hpTxtPos = Vec2({ _hpBarPos.x + 4, _hpBarPos.y + 16 });
	_maxHpTxtPos = Vec2({ _hpTxtPos.x + 55, _hpTxtPos.y });

	_lvPos = Vec2({ _pokeTexPos.x + 19, _pokeTexPos.y + 52 });
}