#pragma once
#include "Scene.h"
#include "BattleUI.h"
#include "pokemon.h"
#include "ResMgr.h"
#include "PokemonManager.h"
#include "DeckManager.h"

class Texture;
class BattleScene : public Scene
{
public:
	BattleScene();
public:
	virtual void Init() override;
	
	void Update() override;
	void Render(HDC _dc) override;
	void Release() override;
	void PlayEnterBattleIntro();
	void BattleCycle(Skill selectedSkill);
	Pokemon GetCurPokemon() {

		return *_curPokemon;

	}
	Pokemon GetWildPokemon() {

		return *_wildPokemon;

	}
	void SetCurPokemon(Pokemon* pokemon) {
		_curPokemon = pokemon;
		_curPokemonTex = ResMgr::GetInst()->FindPokemonTexture(_curPokemon->SpriteKey, PokemonSprite_Type::Battle_Back);
	}
	void SetWildPokemon() {
		int lvAvg = 0;
		for (int i = 0; i < DeckManager::GetInst()->GetPokemon().size(); ++i) {
			lvAvg += DeckManager::GetInst()->GetPokemonByIdx(i)->EvolutionCount;
		}
		lvAvg /= DeckManager::GetInst()->GetPokemon().size();
		if (lvAvg <= 1) {
			_tempPokemon = (PokemonManager::GetInst()->GetRamdomPokemonByLevel(1));
		}
		else if (lvAvg <= 2) {
			_tempPokemon = (PokemonManager::GetInst()->GetRamdomPokemonByLevel(2));
		}
		else if (lvAvg <= 3) {
			_tempPokemon = (PokemonManager::GetInst()->GetRamdomPokemonByLevel(3));
		}
		else {
			_tempPokemon = (PokemonManager::GetInst()->GetRamdomPokemonByLevel(4));
		}
		_wildPokemon = &_tempPokemon;
		_wildPokemon->MaxHp = _wildPokemon->Stats.Hp;
	}
	void SetCurUI();
private:
	// Pokemons
	std::vector<Pokemon*> _playerPokemons;
	Pokemon* _wildPokemon;
	Pokemon _tempPokemon;
	Pokemon* _curPokemon;

	friend class PokemonSelectBtn;

	Texture* _curPokemonTex;
	Vec2 _curPokeTexPos;
	Vec2 _curPokeTexScale;
	Texture* _wildPokemonTex;
	Vec2 _wildPokeTexPos;
	Vec2 _wildPokeTexScale;

	// Background
	Texture* _bgTex;
	Vec2 _bgScale;
	Vec2 _bgPos;

	// Pokemon Status UI
	Texture* _curPokeHpBarTex;
	Vec2 _curPokeHpBarTexPos;
	Vec2 _curPokeHpBarTexScale;
	Texture* _curPokeHpGaugeTex;
	Vec2 _curPokeHpGaugeTexPos;
	Vec2 _curPokeHpGaugeTexScale;
	// Wild Pokemon Status UI
	Texture* _wildPokeHpBarTex;
	Vec2 _wildPokeHpBarTexPos;
	Vec2 _wildPokeHpBarTexScale;
	Texture* _wildPokeHpGaugeTex;
	Vec2 _wildPokeHpGaugeTexPos;
	Vec2 _wildPokeHpGaugeTexScale;


	// Battle UI
	BattleUI* _curUI;
	std::vector<BattleUI*> _battleUIVec;

	friend class BattleMgr;
};