#include "pch.h"
#include "TimeMgr.h"
#include "FieldObject.h"
#include "Texture.h"
#include "ResMgr.h"
#include "KeyMgr.h"
#include "Core.h"

FieldObject::FieldObject(Pokemon pokemon)
{

	_texture = ResMgr::GetInst()->FindPokemonTexture(pokemon.SpriteKey, PokemonSprite_Type::Field);
	_pokemon = pokemon;

	m_vScale = Vec2({ _texture->GetWidth(), _texture->GetHeight() });

	_flipBm = CreateCompatibleBitmap(_texture->GetDC(), _texture->GetWidth(), _texture->GetHeight());
	_flipDc = CreateCompatibleDC(_texture->GetDC());

	SelectObject(_flipDc, _flipBm);
	_coolTime = rand() % 3;

}

FieldObject::~FieldObject()
{

	DeleteDC(_flipDc);
	DeleteObject(_flipBm);

}

void FieldObject::Update()
{

	_objRect = RECT_MAKE((int)m_vPos.x, (int)m_vPos.y, (int)m_vScale.x, (int)m_vScale.y);

	if (_isDrag) {

		_isMove = false;
		_coolTime = rand() % (10 - 2 + 1) + 2;
		_curTime = 0;
		return;

	}

	_coolTime -= fDT;

	if (_coolTime > 0) return;

	if (_isMove == false) {

		Vec2 vec = Vec2({ (rand() % (30 - -30 + 1) + -30) + m_vPos.x,  (rand() % (30 - -30 + 1) + -30) + m_vPos.y });

		if (PtInRect(&_fieldRect, { (int)vec.x, (int)vec.y })) {

			_origin = m_vPos;
			_end = vec;
			_flip = _end.x > _origin.x;
			_isMove = true;

		}
		else {

			_coolTime = 0.5f;

		}

	}
	else {

		_curTime += fDT;
		m_vPos = Lerp(_origin, _end, _curTime);

		if (_curTime > 1) {

			_curTime = 0;
			_coolTime = rand() % (10 - 2 + 1) + 2;
			_isMove = false;

		}

	}

}

void FieldObject::Render(HDC _dc)
{

	auto width = _texture->GetWidth();
	auto height = _texture->GetHeight();

	if (_flip) {

		StretchBlt(
			_flipDc,
			width - 1,
			0,
			-width,
			height,
			_texture->GetDC(),
			0,
			0,
			width,
			height,
			SRCCOPY);

		TransparentBlt(
			_dc,
			(int)(m_vPos.x - width / 2),
			(int)(m_vPos.y - height / 2),
			width,
			height,
			_flipDc,
			0,
			0,
			width,
			height,
			RGB(255, 0, 255));

	}
	else {

		TransparentBlt(
			_dc,
			(int)(m_vPos.x - width / 2),
			(int)(m_vPos.y - height / 2),
			width,
			height,
			_texture->GetDC(),
			0,
			0,
			width,
			height,
			RGB(255, 0, 255));

	}

}