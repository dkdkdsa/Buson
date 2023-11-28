#include "pch.h"
#include "BattleScene.h"

void BattleScene::Update()
{

}

void BattleScene::Render(HDC _dc)
{
}

void BattleScene::PlayEnterBattleIntro()
{
}

void BattleScene::BattleCycle(Skill selectedSkill)
{
	// Player skill select

	// Wild_Pokemon skill random select

	Pokemon* firstActionPokemon;
	Pokemon* secondActionPokemon;

	// Speed Calculation
	if (_playerPokemons[0]->Stats.Speed > _wildPokemons[0]->Stats.Speed) {			// Player first
		firstActionPokemon = _playerPokemons[0];
		secondActionPokemon = _wildPokemons[0];
	}
	else if (_playerPokemons[0]->Stats.Speed < _wildPokemons[0]->Stats.Speed) {		// Wild frist
		firstActionPokemon = _wildPokemons[0];
		secondActionPokemon = _playerPokemons[0];
	}
	else { // <----------------------------------------------------------------------- Equals - Random select
		int randVal = rand() % 2;
		if (randVal == 0) { // <------------------------------------------------------ Player first
			firstActionPokemon = _playerPokemons[0];
			secondActionPokemon = _wildPokemons[0];
		}
		else { // <------------------------------------------------------------------- Wild first
			firstActionPokemon = _wildPokemons[0];
			secondActionPokemon = _playerPokemons[0];
		}
	} // Speed Calculation End

	// First action process
	firstActionPokemon->UseSkill(secondActionPokemon, selectedSkill);				// First action pokemon attack

	// Second action process
	secondActionPokemon->UseSkill(firstActionPokemon, selectedSkill);				// Second action pokemon attack
}

void BattleScene::Init()
{
}
