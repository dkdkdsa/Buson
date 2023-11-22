#include "pch.h"
#include "FieldScene.h"
#include "FieldObject.h"

void FieldScene::Init()
{

	auto* debug = new FieldObject(L"001");
	AddObject(debug, OBJECT_GROUP::FIELD_OBJECT);

}
