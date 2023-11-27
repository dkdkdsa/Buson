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

	for (size_t i = 0; i < _thisFieldObject.size(); ++i)
	{

		if (!_thisFieldObject[i]->GetIsDead()) {

			delete _thisFieldObject[i];

		}

	}

	_thisFieldObject.clear();

}

void Field::Update()
{

	for (size_t i = 0; i < _thisFieldObject.size(); ++i)
	{

		if (!_thisFieldObject[i]->GetIsDead())
			_thisFieldObject[i]->Update();

	}

}

void Field::Render(HDC _dc)
{

#ifdef RENDER_DEBUG

	RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);

#endif // RENDER_DEBUG

	for (size_t i = 0; i < _thisFieldObject.size();)
	{

		if (!_thisFieldObject[i]->GetIsDead()) {

			_thisFieldObject[i]->Render(_dc);
			i++;

		}
		else {

			_thisFieldObject.erase(_thisFieldObject.begin() + i);

		}

	}


}

void Field::AddPokemon(Pokemon pokemon)
{

	auto fieldObject = new FieldObject(pokemon);

	int xa = ((int)(m_vPos.x - m_vScale.x / 2));
	int xb = ((int)(m_vPos.x + m_vScale.x / 2));

	int ya = ((int)(m_vPos.y - m_vScale.y / 2));
	int yb = ((int)(m_vPos.y + m_vScale.y / 2));

	int x = rand() % (xb - xa + 1) + xa;
	int y = rand() % (yb - ya + 1) + ya;

	fieldObject->SetPos(Vec2({ x, y }));
	_thisFieldObject.push_back(fieldObject);
	
}

FieldObject* Field::ChackBound(FieldObject* currentObject, POINT mousePos)
{
	return nullptr;
}
