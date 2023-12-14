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
#include "TimeMgr.h"
#include "EasingManager.h"
#include <string>

PokemonBox::PokemonBox(Vec2 pos, Vec2 size, FieldScene* field)
{

	_tex = ResMgr::GetInst()->TexLoad(L"PokemonBox", L"Texture\\Field\\PokemonBox.bmp");
	_fieldScene = field;
	origin = size;

	SetPos(pos);
	SetScale(size);

}

PokemonBox::~PokemonBox()
{



}

void PokemonBox::Update()
{


	if (_fieldScene) {

		_field = _fieldScene->GetAbleField();

	}

	if (_curPokemon == nullptr) {

		per -= fDT * 2.f;

	}
	else {

		per += fDT * 2.f;

	}

	per = std::clamp(per, 0.f, 1.f);

	m_vScale = EasingManager::GetInst()->EasingVec(origin, origin + Vec2({ 20, 20 }), per, Ease::InOutCubic);

	if (_curPokemon && _curPokemon->Type.size() == 0) {

		_curPokemon = nullptr;

	}

	SetAblePokemon();

}

void PokemonBox::Render(HDC _dc)
{

	auto width = _tex->GetWidth();
	auto height = _tex->GetHeight();

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

	HFONT font = ResMgr::GetInst()->LoadFont(L"Font\\neodgm.ttf", L"Neo둥근모", 20);
	
	HFONT oldFont = (HFONT)SelectObject(_dc, font);

	wstring attackText = L"공격력 : " + std::to_wstring((int)_curPokemon->Stats.Attack);
	wstring defText = L"방어력 : " + std::to_wstring((int)_curPokemon->Stats.Defense);
	wstring hpText = L"체력 : " + std::to_wstring((int)_curPokemon->Stats.Hp);
	wstring speedText = L"스피드 : " + std::to_wstring((int)_curPokemon->Stats.Speed);

	COLORREF oldColor = SetTextColor(_dc, RGB(255, 255, 255));
	SetBkMode(_dc, 1);

	TextOut(_dc, m_vPos.x - 70, m_vPos.y - 30, attackText.c_str(), attackText.length());
	TextOut(_dc, m_vPos.x + 70, m_vPos.y - 30, defText.c_str(), defText.length());
	TextOut(_dc, m_vPos.x + 70, m_vPos.y + 20, hpText.c_str(), hpText.length());
	TextOut(_dc, m_vPos.x - 70, m_vPos.y + 20, speedText.c_str(), speedText.length());
	TextOut(_dc, m_vPos.x - 180, m_vPos.y + 30, _curPokemon->PokemonName.c_str(), _curPokemon->PokemonName.length());

	Texture* pokemonTex = ResMgr::GetInst()->FindPokemonTexture(_curPokemon->SpriteKey, PokemonSprite_Type::Field);

	int pW = pokemonTex->GetWidth();
	int pH = pokemonTex->GetHeight();

	TransparentBlt(
		_dc,
		(int)(m_vPos.x - origin.x / 2) + 45,
		(int)(m_vPos.y - origin.y / 2),
		75,
		75,
		pokemonTex->GetDC(),
		0,
		0,
		pW,
		pH,
		RGB(255, 0, 255));

	SelectObject(_dc, oldFont);
	SetTextColor(_dc, oldColor);
	DeleteObject(font);

}

void PokemonBox::SetAblePokemon()
{

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