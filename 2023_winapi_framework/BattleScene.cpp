#include "pch.h"
#include "BattleScene.h"
#include "Core.h"
#include "ActionSelectUI.h"
#include "SkillSelectUI.h"
#include "PokemonSelectUI.h"
#include "BagUI.h"
#include "RunUI.h"
#include "BattleUIMgr.h"
#include "ResMgr.h"
#include "Texture.h"

void BattleScene::Init()
{
	Core::GetInst()->ResizeWindow(528, 816);
	auto screenPoint = Core::GetInst()->GetResolution();

	_bgPos = Vec2({ 256, 197 });
	_bgScale = Vec2({ 512, 394 });
	_bgTex = ResMgr::GetInst()->TexLoad(
		L"BattleBackground.bmp", 
		L"Texture\\Battle\\Field\\MainBackground.bmp");

	ActionSelectUI* actionSelectUI = new ActionSelectUI();
	SkillSelectUI* skillSelectUI = new SkillSelectUI();
	PokemonSelectUI* pokemonSelectUI = new PokemonSelectUI();
	BagUI* bagUI = new BagUI();
	RunUI* runUI = new RunUI();
	
	BattleUIMgr::GetInst()->SetBattleUI(actionSelectUI);
	BattleUIMgr::GetInst()->SetBattleUI(skillSelectUI);
	BattleUIMgr::GetInst()->SetBattleUI(pokemonSelectUI);
	BattleUIMgr::GetInst()->SetBattleUI(bagUI);
	BattleUIMgr::GetInst()->SetBattleUI(runUI);

	AddObject(BattleUIMgr::GetInst()->GetBattleUI(BattleUIType::ActionSelect), OBJECT_GROUP::Battle_UI);
	AddObject(BattleUIMgr::GetInst()->GetBattleUI(BattleUIType::SkillSelect), OBJECT_GROUP::Battle_UI);
	AddObject(BattleUIMgr::GetInst()->GetBattleUI(BattleUIType::PokemonSelect), OBJECT_GROUP::Battle_UI);
	AddObject(BattleUIMgr::GetInst()->GetBattleUI(BattleUIType::Bag), OBJECT_GROUP::Battle_UI);
	AddObject(BattleUIMgr::GetInst()->GetBattleUI(BattleUIType::Run), OBJECT_GROUP::Battle_UI);
}

void BattleScene::Update()
{
	Scene::Update();
}

void BattleScene::Render(HDC _dc)
{
	RECT_RENDER(_bgPos.x, _bgPos.y, _bgScale.x, _bgScale.y, _dc);
	int width = _bgTex->GetWidth();
	int height = _bgTex->GetHeight();
	StretchBlt(_dc
		, (int)(_bgPos.x - _bgScale.x / 2)
		, (int)(_bgPos.y - _bgScale.y / 2)
		, _bgScale.x, _bgScale.y, _bgTex->GetDC()
		, 0, 0, width, height, SRCCOPY);
	Scene::Render(_dc);
}

void BattleScene::Release()
{
	Scene::Release();
	// 추후 UI vector 에 있는 애들 delete 해줘야함
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