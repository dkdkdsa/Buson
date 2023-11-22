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

	auto* debug = new Field(fieldCenter, fieldSize);
	AddObject(debug, OBJECT_GROUP::FIELD);

#pragma endregion


}
