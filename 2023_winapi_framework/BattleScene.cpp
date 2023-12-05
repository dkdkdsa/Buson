#include "pch.h"
#include "BattleScene.h"
#include "ActionSelectUI.h"

void BattleScene::Init()
{
	AddObject(new ActionSelectUI(), OBJECT_GROUP::Battle_UI);

}

void BattleScene::Update()
{
	Scene::Update();
}

void BattleScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void BattleScene::Release()
{
	Scene::Release();
	// ���� UI vector �� �ִ� �ֵ� delete �������
}

void BattleScene::PlayEnterBattleIntro()
{
}

void BattleScene::BattleCycle(Skill* selectedSkill)
{
	// Player skill select

	// Wild_Pokemon skill random select

	Pokemon* firstActionPokemon;
	Pokemon* secondActionPokemon;

	// Speed Calculation
	if (_playerPokemons[0]->Stats.Speed > _wildPokemons[0]->Stats.Speed) {			// Player first
		firstActionPokemon = _playerPokemons.front();
		secondActionPokemon = _wildPokemons.front();
	}
	else if (_playerPokemons[0]->Stats.Speed < _wildPokemons[0]->Stats.Speed) {		// Wild frist
		firstActionPokemon = _wildPokemons.front();
		secondActionPokemon = _playerPokemons.front();
	}
	else { // <----------------------------------------------------------------------- Equals - Random select
		int randVal = rand() % 2;
		if (randVal == 0) { // <------------------------------------------------------ Player first
			firstActionPokemon = _playerPokemons.front();
			secondActionPokemon = _wildPokemons.front();
		}
		else { // <------------------------------------------------------------------- Wild first
			firstActionPokemon = _wildPokemons.front();
			secondActionPokemon = _playerPokemons.front();
		}
	} // Speed Calculation End

	// First action process
	firstActionPokemon->UseSkill(secondActionPokemon, selectedSkill);				// First action pokemon attack

	// Second action process
	secondActionPokemon->UseSkill(firstActionPokemon, selectedSkill);				// Second action pokemon attack
}