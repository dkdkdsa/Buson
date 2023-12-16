#pragma once
#include "SceneMgr.h"
#include "BattleScene.h"
struct Pokemon;
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
private:
	int lvAvg;
};

