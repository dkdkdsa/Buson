#include "pch.h"
#include "Field.h"
#include "FieldObject.h"
#define RENDER_DEBUG

Field::Field(Vec2 center, Vec2 fieldSize)
{

	m_vPos = center;
	m_vScale = fieldSize;

}

Field::~Field()
{
}

void Field::Update()
{

	for (const auto& obj : _thisFieldObject) {

		obj->Update();

	}

}

void Field::Render(HDC _dc)
{

#ifdef RENDER_DEBUG

	RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);

#endif // RENDER_DEBUG



	for (const auto& obj : _thisFieldObject) {

		obj->Render(_dc);

	}

}

void Field::AddPokemon(Pokemon pokemon)
{



}
