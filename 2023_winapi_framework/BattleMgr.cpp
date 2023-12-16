#include "pch.h"
#include "BattleMgr.h"
#include "DeckManager.h"
#include "PokemonManager.h"
#include "pokemon.h"
#include "BattleScene.h"
#include "SceneMgr.h"
void BattleMgr::Init()
{

}

void BattleMgr::Update()
{
}

void BattleMgr::Render(HDC _dc)
{
	if (std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene()) != nullptr) {
		HFONT font = ResMgr::GetInst()->LoadFont(L"Font\\neodgm.ttf", L"Neo둥근모", 30);
		HFONT oldFont = (HFONT)SelectObject(_dc, font);
		wstring actionText = L"무엇을 할까?";
		COLORREF oldColor = SetTextColor(_dc, RGB(0, 0, 0));
		SetBkMode(_dc, 1);
		TextOut(_dc, 30, 305, actionText.c_str(), actionText.length());

		SelectObject(_dc, oldFont);
		SetTextColor(_dc, oldColor);
		DeleteObject(font);
	}
}

void BattleMgr::SetWildPokemon()
{
	std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())->SetWildPokemon();
}
