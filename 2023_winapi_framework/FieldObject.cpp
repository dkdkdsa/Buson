#include "pch.h"
#include "FieldObject.h"
#include "Texture.h"
#include "ResMgr.h"

FieldObject::FieldObject(Pokemon pokemon)
{

	_texture = ResMgr::GetInst()->FindPokemonTexture(pokemon.SpriteKey, PokemonSprite_Type::Field);
	_pokemon = pokemon;

}

FieldObject::~FieldObject()
{
}

void FieldObject::Update()
{
}

void FieldObject::Render(HDC _dc)
{

	auto width = _texture->GetWidth();
	auto height = _texture->GetHeight();

	TransparentBlt(
		_dc,
		(int)(m_vPos.x - m_vScale.x / 2),
		(int)(m_vPos.y - m_vScale.y / 2),
		width,
		height,
		_texture->GetDC(),
		0, 
		0,
		width,
		height,
		RGB(255, 0, 255));

}