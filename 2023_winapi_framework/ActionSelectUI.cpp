#include "pch.h"
#include "ActionSelectUI.h"
#include "BattleScene.h"
#include "FightBtn.h"
#include "BagBtn.h"
#include "RunBtn.h"
#include "Battle_PokemonBtn.h"
#include "Core.h"
ActionSelectUI::ActionSelectUI() : BattleUI(L"BattleSceneBackground.bmp", L"Texture\\Battle\\BattleSceneBackground.bmp", { 256, 1209 }, { 512, 406 })
{
	SetEnable(true);

	SetBtnVec(new FightBtn());
	SetBtnVec(new BagBtn());
	SetBtnVec(new RunBtn());
	SetBtnVec(new Battle_PokemonBtn());
}

ActionSelectUI::~ActionSelectUI()
{

}

void ActionSelectUI::Update()
{
	for (int i = 0; i < GetBtnVec().size(); ++i) {
		GetBtnVec()[i]->Update();
	}
	Object::Update();
}

//void ActionSelectUI::Render(HDC _dc)
//{
//	for (int i = 0; i < _buttons.size(); ++i) {
//		_buttons[i]->Render(_dc);
//	}
//	//Object::Render(_dc);
//}