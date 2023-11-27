#include "pch.h"
#include "FieldObject.h"
#include "Texture.h"
#include "ResMgr.h"
#include "KeyMgr.h"

FieldObject::FieldObject(Pokemon pokemon)
{

	_texture = ResMgr::GetInst()->FindPokemonTexture(pokemon.SpriteKey, PokemonSprite_Type::Field);
	_pokemon = pokemon;

	m_vScale = Vec2({ _texture->GetWidth(), _texture->GetHeight() });

}

FieldObject::~FieldObject()
{
}

void FieldObject::Update()
{

	_objRect = RECT_MAKE((int)m_vPos.x, (int)m_vPos.y, (int)m_vScale.x, (int)m_vScale.y);

	if (KEY_DOWN(KEY_TYPE::LBUTTON) && PtInRect(&_objRect, KeyMgr::GetInst()->GetMousePos())) {



	}

}

void FieldObject::Render(HDC _dc)
{

	auto width = _texture->GetWidth();
	auto height = _texture->GetHeight();

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
