#include "pch.h"
#include "FieldScene.h"
#include "Field.h"
#include "Core.h"

void FieldScene::Init()
{

	auto screenPoint = Core::GetInst()->GetResolution();

#pragma region Field

	Vec2 fieldSize = Vec2({ screenPoint.x * 0.9f, screenPoint.y / 1.5f });
	Vec2 fieldCenter = Vec2({ screenPoint.x / 2, screenPoint.y / 2 + 50 });

	auto* field_1 = new Field(fieldCenter, fieldSize);
	_fieldList.push_back(field_1);

#pragma endregion


}

void FieldScene::Update()
{

	Scene::Update();
	_fieldList[_currentAbleField]->Update();

}

void FieldScene::Render(HDC _dc)
{

	Scene::Render(_dc);
	_fieldList[_currentAbleField]->Render(_dc);

}

void FieldScene::Release()
{

	Scene::Release();

	for (int i = 0; i < _fieldList.size(); i++) {

		delete _fieldList[i];

	}

	_fieldList.clear();
}
