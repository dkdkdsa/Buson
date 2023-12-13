#include "pch.h"
#include "FieldDeckPanel.h"
#include "Field.h"
#include "DeckPokemonPanel.h"
#include "ResMgr.h"
#include "Texture.h"
#include "SceneChangeBtn.h"

FieldDeckPanel::FieldDeckPanel(Vec2 pos, Vec2 scale, Field* field)
{

	m_vPos = pos;
	m_vScale = scale;

	auto* obj_1 = new DeckPokemonPanel(Vec2(-130, -150), Vec2({200, 75}), Vec2({0, 0}), 0);
	auto* obj_2 = new DeckPokemonPanel(Vec2(130, -150), Vec2({ 200, 75 }), Vec2({ 0, 0 }), 1);
	auto* obj_3 = new DeckPokemonPanel(Vec2(-130, -40), Vec2({ 200, 75 }), Vec2({ 0, 0 }), 2);
	auto* obj_4 = new DeckPokemonPanel(Vec2(130, -40), Vec2({ 200, 75 }), Vec2({ 0, 0 }), 3);
	auto* obj_5 = new DeckPokemonPanel(Vec2(-130, 70), Vec2({ 200, 75 }), Vec2({ 0, 0 }), 4);
	auto* obj_6 = new DeckPokemonPanel(Vec2(130, 70), Vec2({ 200, 75 }), Vec2({ 0, 0 }), 5);

	obj_1->SetField(field);
	obj_2->SetField(field);
	obj_3->SetField(field);
	obj_4->SetField(field);
	obj_5->SetField(field);
	obj_6->SetField(field);

	renders.push_back(obj_1);
	renders.push_back(obj_2);
	renders.push_back(obj_3);
	renders.push_back(obj_4);
	renders.push_back(obj_5);
	renders.push_back(obj_6);

	mainTex = ResMgr::GetInst()->TexLoad(L"DeckBG", L"Texture\\Field\\DeckBG.bmp");

	sceneChangeBtn = new SceneChangeBtn(Vec2({ 0, 170 }), Vec2(300, 100), L"PokemonBox", L"Texture\\Field\\PokemonBox.bmp", L"Battle_Scene");

}

FieldDeckPanel::~FieldDeckPanel()
{

	for (int i = 0; i < renders.size(); i++) {

		delete renders[i];

	}

	delete sceneChangeBtn;

}

void FieldDeckPanel::Render(HDC _dc)
{

	//RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);

	int w = mainTex->GetWidth();
	int h = mainTex->GetHeight();

	TransparentBlt(
		_dc,
		m_vPos.x - m_vScale.x / 2,
		m_vPos.y - m_vScale.y / 2,
		m_vScale.x,
		m_vScale.y,
		mainTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	for (int i = 0; i < renders.size(); i++) {

		renders[i]->Render(_dc);

	}

	sceneChangeBtn->Render(_dc);

}

void FieldDeckPanel::Update()
{

	for (int i = 0; i < renders.size(); i++) {

		renders[i]->Update();
		renders[i]->SetOffset(m_vPos);

	}

	sceneChangeBtn->Update();
	sceneChangeBtn->offset = m_vPos;


}
