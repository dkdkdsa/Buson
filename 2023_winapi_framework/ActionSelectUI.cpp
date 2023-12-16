#include "pch.h"
#include "ActionSelectUI.h"
#include "BattleScene.h"
#include "FightBtn.h"
#include "BagBtn.h"
#include "RunBtn.h"
#include "Battle_PokemonBtn.h"
#include "Core.h"
#include "Texture.h"
ActionSelectUI::ActionSelectUI() : BattleUI(L"BattleSceneBackground.bmp", L"Texture\\Battle\\BattleSceneBackground.bmp", { 256, 1209 }, { 512, 406 })
{
	m_strName = L"ActionSelectUI";
	auto screenPoint = Core::GetInst()->GetResolution();

	SetEnable(true);

	SetBtnVec(new FightBtn());

	//GetBtnVec()[0]->SetScale(Vec2({ 100, 100 }));
	//GetBtnVec()[0]->SetPos(Vec2(
	//	{ 256 - (long)(GetBtnVec()[0]->GetScale().x / 2)
	//	, (long)((screenPoint.y / 4) * 2.5f)}));

	SetBtnVec(new BagBtn());

	/*GetBtnVec()[1]->SetPos(Vec2(
		{ 5
		, (long)(screenPoint.y - GetBtnVec()[1]->GetScale().y * 2) }));*/

	SetBtnVec(new RunBtn());

	/*GetBtnVec()[2]->SetPos(Vec2(
		{ 256 - (long)(GetBtnVec()[2]->GetScale().x / 2)
		, (long)(screenPoint.y - GetBtnVec()[2]->GetScale().y * 2) }));*/

	SetBtnVec(new Battle_PokemonBtn());

	/*GetBtnVec()[3]->SetPos(Vec2(
		{ (long)(screenPoint.x - (GetBtnVec()[3]->GetScale().x + 21))
		, (long)(screenPoint.y - GetBtnVec()[3]->GetScale().y * 2) }));*/

}

ActionSelectUI::~ActionSelectUI()
{

}

void ActionSelectUI::Init()
{

}

void ActionSelectUI::Update()
{
	for (int i = 0; i < GetBtnVec().size(); ++i) {
		GetBtnVec()[i]->Update();
	}
	Object::Update();
}

void ActionSelectUI::Render(HDC _dc)
{
	if (_mainTex == nullptr) {
		RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);
	}
	else {
		TransparentBlt(
			_dc,
			m_vPos.x - m_vScale.x / 2,
			m_vPos.y - m_vScale.y * 2,
			m_vScale.x,
			m_vScale.y,
			_mainTex->GetDC(),
			0,
			0,
			_mainTex->GetWidth(),
			_mainTex->GetHeight(),
			RGB(255, 0, 255));
	}
	for (int i = 0; i < _buttons.size(); ++i) {
		_buttons[i]->Render(_dc);
	}


}

//void ActionSelectUI::Render(HDC _dc)
//{
//	for (int i = 0; i < _buttons.size(); ++i) {
//		_buttons[i]->Render(_dc);
//	}
//	//Object::Render(_dc);
//}