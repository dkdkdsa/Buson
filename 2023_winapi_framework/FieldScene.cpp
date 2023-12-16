#include "pch.h"
#include "FieldScene.h"
#include "Field.h"
#include "Core.h"
#include "PokemonMakeBtn.h"
#include "PokemonBox.h"
#include "FieldDeckBtn.h"
#include "FieldDeckPanel.h"
#include "Texture.h"
#include "ResMgr.h"


void FieldScene::Init()
{

	Core::GetInst()->ResizeWindow(1280, 720);
	auto screenPoint = Core::GetInst()->GetResolution();

	bgTex = ResMgr::GetInst()->TexLoad(L"FieldBG", L"Texture\\Field\\FieldBG.bmp");
	panelTex = ResMgr::GetInst()->TexLoad(L"FieldPanel", L"Texture\\Field\\FieldPanel.bmp");


	ResMgr::GetInst()->LoadSound(L"Field", L"Sound\\Field.mp3", true);

#pragma region Field

	Vec2 fieldSize = Vec2({ screenPoint.x * 0.9f, screenPoint.y / 1.5f });
	Vec2 fieldCenter = Vec2({ screenPoint.x / 2, screenPoint.y / 2 + 50 });

	auto* field_1 = new Field(fieldCenter, fieldSize);
	_fieldList.push_back(field_1);

#pragma endregion

#pragma region UI

	Vec2 uiCenter = Vec2({ screenPoint.x / 2, screenPoint.y / 2 });

	auto* addBtn = new PokemonMakeBtn();
	addBtn->SetFieldScene(this);
	AddObject(addBtn, OBJECT_GROUP::DEFAULT);

	auto* pokemonBox = new PokemonBox(uiCenter + Vec2({ 300, -270 }), Vec2({ 450, 100 }), this);
	AddObject(pokemonBox, OBJECT_GROUP::DEFAULT);

	auto* fieldDeckPanel = new FieldDeckPanel(Vec2({ -250, 450 }), Vec2({ 500, 500 }), field_1);
	AddObject(fieldDeckPanel, OBJECT_GROUP::DEFAULT);

	auto* fieldDeckBtn = new FieldDeckBtn(Vec2({ 35, 300 }), Vec2({ 75, 200 }));
	fieldDeckBtn->SetFieldPanel(fieldDeckPanel);
	AddObject(fieldDeckBtn, OBJECT_GROUP::DEFAULT);

#pragma endregion

	ResMgr::GetInst()->Play(L"Field");

}

void FieldScene::Update()
{

	_fieldList[_currentAbleField]->Update();
	Scene::Update();

}

void FieldScene::Render(HDC _dc)
{

	int w = bgTex->GetWidth();
	int h = bgTex->GetHeight();

	int pw = panelTex->GetWidth();
	int ph = panelTex->GetHeight();

	BitBlt(
		_dc,
		0,
		0,
		1280,
		720,
		bgTex->GetDC(),
		0,
		0,
		SRCCOPY);

	TransparentBlt(
		_dc,
		0,
		15,
		1280,
		150,
		panelTex->GetDC(),
		0,
		0,
		pw,
		ph,
		RGB(255, 0, 255));

	_fieldList[_currentAbleField]->Render(_dc);
	Scene::Render(_dc);

}

void FieldScene::Release()
{

	Scene::Release();

	for (int i = 0; i < _fieldList.size(); i++) {

		delete _fieldList[i];

	}
	_fieldList.clear();
}
