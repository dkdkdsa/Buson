#pragma once
#include "Scene.h"
#include "pokemon.h"
class BattleScene : public Scene
{
public:
	virtual void Init() override;
private:
	void PlayEnterBattleIntro();
	void BattleCycle(Skill selectedSkill);
private:
	std::vector<Pokemon*> _playerPokemons;
	std::vector<Pokemon*> _wildPokemons;
	
};

