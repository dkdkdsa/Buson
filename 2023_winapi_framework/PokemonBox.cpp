#include "pch.h"
#include "PokemonBox.h"
#include "pokemon.h"
#include "Texture.h"
#include "ResMgr.h"
#include "PokemonManager.h"
#include "KeyMgr.h"
#include "Field.h"
#include "FieldObject.h"
#include "FieldScene.h"
#include <string>

PokemonBox::PokemonBox(Vec2 pos, Vec2 size, FieldScene* field)
{

	_tex = ResMgr::GetInst()->TexLoad(L"PokemonBox", L"Texture\\Field\\PokemonBox.bmp");

	_resizeBitMap = CreateCompatibleBitmap(_tex->GetDC(), _tex->GetWidth(), _tex->GetHeight());
	_resizeDc = CreateCompatibleDC(_tex->GetDC());
	_fieldScene = field;

	SetPos(pos);
	SetScale(size);

}

PokemonBox::~PokemonBox()
{

	DeleteDC(_resizeDc);
	DeleteObject(_resizeBitMap);

}

void PokemonBox::Update()
{

	if (_fieldScene) {

		_field = _fieldScene->GetAbleField();

	}

	if (_curPokemon && _curPokemon->Type.size() == 0) {

		_curPokemon = nullptr;

	}

	if (KEY_DOWN(KEY_TYPE::RBUTTON)) {

		auto* obj = _field->ChackBound(nullptr, KeyMgr::GetInst()->GetMousePos());

		if (obj != nullptr) {

			_curPokemon = &obj->GetPokemon();

		}
		else {

			_curPokemon = nullptr;

		}

	}

}

void PokemonBox::Render(HDC _dc)
{

	auto width = _tex->GetWidth();
	auto height = _tex->GetHeight();

	StretchBlt(
		_resizeDc,
		0,
		0,
		m_vScale.x,
		m_vScale.y,
		_tex->GetDC(),
		0,
		0,
		width,
		height,
		SRCCOPY);

	TransparentBlt(
		_dc,
		(int)(m_vPos.x - m_vScale.x / 2),
		(int)(m_vPos.y - m_vScale.y / 2),
		m_vScale.x,
		m_vScale.y,
		_tex->GetDC(),
		0,
		0,
		width,
		height,
		RGB(255, 0, 255));

	if (_curPokemon == nullptr) return;

	HFONT font = ResMgr::GetInst()->LoadFont(L"Font\\neodgm.ttf", L"Neo�ձٸ�", 20);
	
	HFONT oldFont = (HFONT)SelectObject(_dc, font);

	wstring attackText = L"���ݷ� : " + std::to_wstring((int)_curPokemon->Stats.Attack);
	wstring defText = L"���� : " + std::to_wstring((int)_curPokemon->Stats.Defense);
	wstring hpText = L"ü�� : " + std::to_wstring((int)_curPokemon->Stats.Hp);
	wstring speedText = L"���ǵ� : " + std::to_wstring((int)_curPokemon->Stats.Speed);

	COLORREF oldColor = SetTextColor(_dc, RGB(255, 255, 255));
	SetBkMode(_dc, 1);

	TextOut(_dc, m_vPos.x - 70, m_vPos.y - 30, attackText.c_str(), attackText.length());
	TextOut(_dc, m_vPos.x + 70, m_vPos.y - 30, defText.c_str(), defText.length());
	TextOut(_dc, m_vPos.x + 70, m_vPos.y + 20, hpText.c_str(), hpText.length());
	TextOut(_dc, m_vPos.x - 70, m_vPos.y + 20, speedText.c_str(), speedText.length());
	TextOut(_dc, m_vPos.x - 180, m_vPos.y + 30, _curPokemon->PokemonName.c_str(), _curPokemon->PokemonName.length());

	SelectObject(_dc, oldFont);
	SetTextColor(_dc, oldColor);
	DeleteObject(font);

}

void PokemonBox::SetAblePokemon()
{
}
