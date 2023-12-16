#include "pch.h"
#include "BattleMgr.h"
#include "DeckManager.h"
#include "PokemonManager.h"
#include "pokemon.h"
#include "BattleScene.h"
#include "SceneMgr.h"
#include "Core.h"
#include "TimeMgr.h"
#include "Skill.h"
#include "EasingManager.h"
#include <random>
#include "BattleUIMgr.h"
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

		COLORREF oldColor = SetTextColor(_dc, RGB(0, 0, 0));
		SetBkMode(_dc, 1);
		TextOut(_dc, 30, 305, _curText.c_str(), _curText.length());

		SelectObject(_dc, oldFont);
		SetTextColor(_dc, oldColor);
		DeleteObject(font);
	}
}

void BattleMgr::SetWildPokemon()
{
	std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())->SetWildPokemon();
}

void BattleMgr::StartOneTurn(Skill* usedSkill)
{
	BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::NullUI);

	while (_attackTimer > 0) {
		_attackTimer -= fDT;
		_curText = std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())
			->GetCurPokemon()->PokemonName
			+ L"의 "
			+ usedSkill->Name
			+ L"!";
	}
	int wildCurHp = std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())
		->GetWildPokemon()->Stats.Hp;
	std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())
		->GetCurPokemon()->UseSkill(std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())
			->GetWildPokemon(), usedSkill);
	_attackTimer = 3;
	std::mt19937 gen(_rd());
	std::uniform_int_distribution<int> dis(0, 3);
	int wildSkillIdx = dis(gen);
	wstring text = L"야생 "
		+ std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())
		->GetWildPokemon()->PokemonName;
	+L"의 "
		+ std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())
		->GetWildPokemon()->Skills[wildSkillIdx]->Name
		+ L"!";
	while (_attackTimer > 0) {
		_attackTimer -= fDT;
		_curText = text;
	}
	std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())
		->GetWildPokemon()->UseSkill(
			std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())
			->GetCurPokemon(),
			std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())
			->GetWildPokemon()->Skills[wildSkillIdx]);
	_attackTimer = 3;
	
	if (std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())
		->GetWildPokemon()->Stats.Hp <= 0) {
		text = std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())
			->GetWildPokemon()->PokemonName + L"은/는 쓰러졌다!";
		while (_attackTimer > 0) {
			_attackTimer -= fDT;
			_curText = text;
		}
		std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())
			->SetWildPokemon();
		BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::ActionSelect);
	}
	if (std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())
		->GetCurPokemon()->Stats.Hp <= 0) {
		text = std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())
			->GetCurPokemon()->PokemonName + L"은/는 쓰러졌다!";
		while (_attackTimer > 0) {
			_attackTimer -= fDT;
			_curText = text;
		}
		BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::PokemonSelect);
		return;
	}
	BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::ActionSelect);
}
