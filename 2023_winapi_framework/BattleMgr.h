#pragma once
#include "SceneMgr.h"
#include "BattleScene.h"
#include <random>
struct Pokemon; class Skill;
class BattleMgr : public Scene
{
	SINGLE(BattleMgr);

public:
	virtual void Init() override;
	void Update() override;
	void Render(HDC _dc) override;

public:
	void ChangeCurPokemon(Pokemon* pokemon) {
		std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())->SetCurPokemon(pokemon);
	}
	void SetWildPokemon();
	std::vector<Pokemon*> GetPokemons() {
		return std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())->_playerPokemons;
	}
	void StartOneTurn(Skill* usedSkill);
private:
	int _lvAvg;
	bool _turnStarted = false;
	wstring _curText = L"무엇을 할까?";
	float _attackTimer = 3;
	std::random_device _rd;

};

