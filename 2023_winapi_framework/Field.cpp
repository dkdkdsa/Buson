#include "pch.h"
#include "Field.h"
#include "FieldObject.h"
#include "KeyMgr.h"
#include "EventMgr.h"
#include "PokemonManager.h"
#include "ResMgr.h"
#include "Texture.h"
#include "DeckManager.h"
//#define RENDER_DEBUG

Field::Field(Vec2 center, Vec2 fieldSize)
{

	m_vPos = center;
	m_vScale = fieldSize;
	_tex = ResMgr::GetInst()->TexLoad(L"FieldBg", L"Texture\\Field\\BoxField.bmp");

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

	if (KEY_DOWN(KEY_TYPE::MBUTTON)) {

		AddDeck();

	}


	if (KEY_DOWN(KEY_TYPE::LBUTTON)) {

		SetDrag();

	}

	Drag();

	if (KEY_UP(KEY_TYPE::LBUTTON)) {

		ReleaseDrag();

	}

}

void Field::Render(HDC _dc)
{

#ifdef RENDER_DEBUG

	RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);

#endif // RENDER_DEBUG

	int width = _tex->GetWidth();
	int height = _tex->GetHeight();

	StretchBlt(_dc
		, (int)(m_vPos.x - m_vScale.x / 2)
		, (int)(m_vPos.y - m_vScale.y / 2)
		, m_vScale.x, m_vScale.y, _tex->GetDC()
		, 0, 0, width, height, SRCCOPY);

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

FieldObject* Field::AddPokemon(Pokemon pokemon)
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

	fieldObject->SetFieldRect(RECT_MAKE((int)m_vPos.x, (int)m_vPos.y, (int)m_vScale.x, (int)m_vScale.y));

	return fieldObject;
	
}

void Field::SetDrag()
{

	auto mPos = KeyMgr::GetInst()->GetMousePos();

	for (size_t i = 0; i < _thisFieldObject.size(); ++i)
	{

		if (!_thisFieldObject[i]->GetIsDead()) {

			auto rt = _thisFieldObject[i]->GetRect();
			if (PtInRect(&rt, mPos)) {

				_dragObject = _thisFieldObject[i];
				std::swap(_thisFieldObject[i], _thisFieldObject.back());
				_dragObject->SetIsDrag(true);
				return;

			}

		}

	}

}

void Field::ReleaseDrag()
{

	if (_dragObject != nullptr) {

		auto mPos = KeyMgr::GetInst()->GetMousePos();
		auto* boundObj = ChackBound(_dragObject, mPos);

		if (boundObj != nullptr) {

			if (boundObj->GetPokemon().SpriteKey == _dragObject->GetPokemon().SpriteKey 
				&& _dragObject->GetPokemon().EvolutionNumber != 0) {

				AddPokemon(*PokemonManager::GetInst()->GetPokemon(_dragObject->GetPokemon().EvolutionNumber))->SetPos(Vec2({mPos.x, mPos.y}));

				EventMgr::GetInst()->DeleteObject(boundObj);
				EventMgr::GetInst()->DeleteObject(_dragObject);

			}

		}
		else {

			RECT rt = RECT_MAKE(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y);
			auto mPos = KeyMgr::GetInst()->GetMousePos();

			if (!PtInRect(&rt, mPos)) {

				EventMgr::GetInst()->DeleteObject(_dragObject);
				_dragObject = nullptr;
				return;

			}

			_dragObject->SetIsDrag(false);

		}

		_dragObject = nullptr;

	}


}

void Field::Drag()
{

	if (_dragObject != nullptr) {

		auto mPos = KeyMgr::GetInst()->GetMousePos();
		_dragObject->SetPos(Vec2({ mPos.x, mPos.y }));

	}

}

FieldObject* Field::ChackBound(FieldObject* currentObject, POINT mousePos)
{
	
	for (size_t i = 0; i < _thisFieldObject.size(); ++i)
	{

		if (!_thisFieldObject[i]->GetIsDead() && _thisFieldObject[i] != currentObject) {

			auto rt = _thisFieldObject[i]->GetRect();
			if (PtInRect(&rt, mousePos)) {

				return _thisFieldObject[i];

			}

		}

	}

	return nullptr;

}

void Field::AddDeck()
{

	auto obj = ChackBound(nullptr, KeyMgr::GetInst()->GetMousePos());

	if (obj != nullptr) {

		if (DeckManager::GetInst()->AddPokemon(obj->GetPokemon())) {

			EventMgr::GetInst()->DeleteObject(obj);

		}

	}

}
