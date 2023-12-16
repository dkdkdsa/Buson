#include "pch.h"
#include "pokemon.h"
#include "Skill.h"
#include "BattleScene.h"
#include "Core.h"
#include "ActionSelectUI.h"
#include "SkillSelectUI.h"
#include "PokemonSelectUI.h"
#include "BagUI.h"
#include "RunUI.h"
#include "PokemonShiftUI.h"
#include "NullUI.h"
#include "BattleUIMgr.h"
#include "ResMgr.h"
#include "Texture.h"
#include "DeckManager.h"
#include "TimeMgr.h"
#include "PokemonManager.h"
#include "Texture.h"
BattleScene::BattleScene()
{
	
}

void BattleScene::Init()
{
	Core::GetInst()->ResizeWindow(528, 816);
	auto screenPoint = Core::GetInst()->GetResolution();

	_bgPos = Vec2({ 256, 197 });
	_bgScale = Vec2({ 512, 394 });
	_bgTex = ResMgr::GetInst()->TexLoad(
		L"BattleBackground.bmp",
		L"Texture\\Battle\\Field\\MainBackground.bmp");

	for (int i = 0; i < DeckManager::GetInst()->GetPokemon().size(); ++i) {
		_playerPokemons.push_back(DeckManager::GetInst()->GetPokemonByIdx(i));
	}
	for (int i = 0; i < _playerPokemons.size(); ++i) {
		_playerPokemons[i]->MaxHp = _playerPokemons[i]->Stats.Hp;
	}
	SetCurPokemon(_playerPokemons.front());

	SetWildPokemon();

	_curPokeTexPos = Vec2({ 50, 128 });
	_curPokeTexScale = Vec2({ _curPokemonTex->GetWidth() * 2, _curPokemonTex->GetHeight() * 2 });

	_curPokeHpBarTex = ResMgr::GetInst()->TexLoad(L"Battle_PlayerHpBar.bmp", L"Texture\\Battle\\Pokemon_State\\Battle_PlayerHpBar.bmp");
	_curPokeHpBarTexScale = Vec2({ (int)_curPokeHpBarTex->GetWidth() * 2, (int)_curPokeHpBarTex->GetHeight() * 2 });
	_curPokeHpBarTexPos = Vec2({ (int)(512 - _curPokeHpBarTexScale.x), 195 });

	_curPokeHpGaugeTex = ResMgr::GetInst()->TexLoad(L"HpGauge_Green.bmp", L"Texture\\Battle\\Pokemon_State\\HpGauge_Green.bmp");
	_curPokeHpGaugeTexScale = Vec2({ (int)(_curPokemon->Stats.Hp / _curPokemon->MaxHp * 100), (int)(_curPokeHpGaugeTex->GetHeight()) });
	_curPokeHpGaugeTexPos = Vec2({ _curPokeHpBarTexPos.x + 120, _curPokeHpBarTexPos.y + 40 });

	_wildPokemonTex = ResMgr::GetInst()->FindPokemonTexture(_wildPokemon->SpriteKey, PokemonSprite_Type::Battle_Front);
	_wildPokeTexScale = Vec2({ _wildPokemonTex->GetWidth() * 2, _wildPokemonTex->GetHeight() * 2 });
	_wildPokeTexPos = Vec2({ (int)(256 + (_wildPokeTexScale.x / 3 - 5)), 30 });

	_wildPokeHpBarTex = ResMgr::GetInst()->TexLoad(L"Battle_WildHpBar.bmp", L"Texture\\Battle\\Pokemon_State\\Battle_WildHpBar.bmp");
	_wildPokeHpBarTexScale = Vec2({ _wildPokeHpBarTex->GetWidth() * 2, _wildPokeHpBarTex->GetHeight() * 2 });
	_wildPokeHpBarTexPos = Vec2({ 0, 50 });

	_wildPokeHpGaugeTex = ResMgr::GetInst()->TexLoad(L"HpGauge_Green.bmp", L"Texture\\Battle\\Pokemon_State\\HpGauge_Green.bmp");
	_wildPokeHpGaugeTexScale = Vec2({ (int)(_wildPokemon->Stats.Hp / _curPokemon->MaxHp * 100), (int)(_wildPokeHpGaugeTex->GetHeight()) });
	_wildPokeHpGaugeTexPos = Vec2({ _wildPokeHpBarTexPos.x + 96, _wildPokeHpBarTexPos.y + 40 });

	ActionSelectUI* actionSelectUI = new ActionSelectUI();
	SkillSelectUI* skillSelectUI = new SkillSelectUI();
	PokemonSelectUI* pokemonSelectUI = new PokemonSelectUI();
	BagUI* bagUI = new BagUI();
	RunUI* runUI = new RunUI();
	PokemonShiftUI* pokemonShiftUI = new PokemonShiftUI();
	NullUI* nullUI = new NullUI();

	BattleUIMgr::GetInst()->SetBattleUI(actionSelectUI);
	BattleUIMgr::GetInst()->SetBattleUI(skillSelectUI);
	BattleUIMgr::GetInst()->SetBattleUI(pokemonSelectUI);
	BattleUIMgr::GetInst()->SetBattleUI(bagUI);
	BattleUIMgr::GetInst()->SetBattleUI(runUI);
	BattleUIMgr::GetInst()->SetBattleUI(pokemonShiftUI);
	BattleUIMgr::GetInst()->SetBattleUI(nullUI);
	
	

	/*AddObject(BattleUIMgr::GetInst()->GetBattleUI(BattleUIType::ActionSelect), OBJECT_GROUP::Battle_UI);
	AddObject(BattleUIMgr::GetInst()->GetBattleUI(BattleUIType::SkillSelect), OBJECT_GROUP::Battle_UI);
	AddObject(BattleUIMgr::GetInst()->GetBattleUI(BattleUIType::PokemonSelect), OBJECT_GROUP::Battle_UI);
	AddObject(BattleUIMgr::GetInst()->GetBattleUI(BattleUIType::Bag), OBJECT_GROUP::Battle_UI);
	AddObject(BattleUIMgr::GetInst()->GetBattleUI(BattleUIType::Run), OBJECT_GROUP::Battle_UI);*/

	BattleUIMgr::GetInst()->SetCurUI(BattleUIType::ActionSelect);
}

void BattleScene::Update()
{
	BattleUIMgr::GetInst()->GetCurBattleUI()->Update();

	/*static float timer = 1.f;
	timer -= fDT;
	if (timer <= 0) {
		_curPokemon->Stats.Hp -= 10;
		_wildPokemon->Stats.Hp -= 10;
		timer = 1.f;
	}*/

	if (_curPokemon->Stats.Hp / _curPokemon->MaxHp * 100 <= 0.f) {
		_curPokemon->Stats.Hp = 0;
	}
	else if (_curPokemon->Stats.Hp / _curPokemon->MaxHp * 100 <= 21.f) {
		_curPokeHpGaugeTex = ResMgr::GetInst()->TexLoad(L"HpGauge_Red.bmp", L"Texture\\Battle\\Pokemon_State\\HpGauge_Red.bmp");

	}
	else if (_curPokemon->Stats.Hp / _curPokemon->MaxHp * 100 <= 51.f) {
		_curPokeHpGaugeTex = ResMgr::GetInst()->TexLoad(L"HpGauge_Yellow.bmp", L"Texture\\Battle\\Pokemon_State\\HpGauge_Yellow.bmp");
	}

	if (_wildPokemon->Stats.Hp / _wildPokemon->MaxHp * 100 <= 0.f) {
		_wildPokemon->Stats.Hp = 0;
	}
	else if (_wildPokemon->Stats.Hp / _wildPokemon->MaxHp * 100 <= 21.f) {
		_wildPokeHpGaugeTex = ResMgr::GetInst()->TexLoad(L"HpGauge_Red.bmp", L"Texture\\Battle\\Pokemon_State\\HpGauge_Red.bmp");
	}
	else if (_wildPokemon->Stats.Hp / _wildPokemon->MaxHp * 100 <= 51.f) {
		_wildPokeHpGaugeTex = ResMgr::GetInst()->TexLoad(L"HpGauge_Yellow.bmp", L"Texture\\Battle\\Pokemon_State\\HpGauge_Yellow.bmp");
	}
	

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
	BattleUIMgr::GetInst()->GetCurBattleUI()->Render(_dc);

	int w = _curPokemonTex->GetWidth();
	int h = _curPokemonTex->GetHeight();

	TransparentBlt(
		_dc,
		_curPokeTexPos.x,
		_curPokeTexPos.y,
		_curPokeTexScale.x,
		_curPokeTexScale.y,
		_curPokemonTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	w = _wildPokemonTex->GetWidth();
	h = _wildPokemonTex->GetHeight();

	TransparentBlt(
		_dc,
		_wildPokeTexPos.x,
		_wildPokeTexPos.y,
		_wildPokeTexScale.x,
		_wildPokeTexScale.y,
		_wildPokemonTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	w = _curPokeHpBarTex->GetWidth();
	h = _curPokeHpBarTex->GetHeight();

	TransparentBlt(
		_dc,
		_curPokeHpBarTexPos.x,
		_curPokeHpBarTexPos.y,
		_curPokeHpBarTexScale.x,
		_curPokeHpBarTexScale.y,
		_curPokeHpBarTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	w = _wildPokeHpBarTex->GetWidth();
	h = _wildPokeHpBarTex->GetHeight();

	TransparentBlt(
		_dc,
		_wildPokeHpBarTexPos.x,
		_wildPokeHpBarTexPos.y,
		_wildPokeHpBarTexScale.x,
		_wildPokeHpBarTexScale.y,
		_wildPokeHpBarTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	w = _curPokeHpGaugeTex->GetWidth();
	h = _curPokeHpGaugeTex->GetHeight();

	TransparentBlt(
		_dc,
		_curPokeHpGaugeTexPos.x,
		_curPokeHpGaugeTexPos.y,
		_curPokemon->Stats.Hp / _curPokemon->MaxHp * 100,
		_curPokeHpGaugeTex->GetHeight(),
		_curPokeHpGaugeTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	TransparentBlt(
		_dc,
		_wildPokeHpGaugeTexPos.x,
		_wildPokeHpGaugeTexPos.y,
		_wildPokemon->Stats.Hp / _wildPokemon->MaxHp * 100,
		_wildPokeHpGaugeTex->GetHeight(),
		_wildPokeHpGaugeTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	HFONT font = ResMgr::GetInst()->LoadFont(L"Font\\neodgm.ttf", L"NeoµÕ±Ù¸ð", 18);
	HFONT oldFont = (HFONT)SelectObject(_dc, font);

	// Player Pokemon
	wstring hpText = std::to_wstring((int)_curPokemon->Stats.Hp);
	wstring maxHpText = std::to_wstring(_curPokemon->MaxHp);
	wstring lvText = std::to_wstring(_curPokemon->EvolutionCount * 20);
	// Wild Pokemon
	wstring wLvText = std::to_wstring(_wildPokemon->EvolutionCount * 20);

	
	COLORREF oldColor = SetTextColor(_dc, RGB(0, 0, 0));
	SetBkMode(_dc, 1);
	// Player HP
	TextOut(_dc, _curPokeHpBarTexPos.x + 145, _curPokeHpBarTexPos.y + 53, hpText.c_str(), hpText.length());
	TextOut(_dc, _curPokeHpBarTexPos.x + 188, _curPokeHpBarTexPos.y + 53, maxHpText.c_str(), maxHpText.length());

	HFONT namefont = ResMgr::GetInst()->LoadFont(L"Font\\neodgm.ttf", L"NeoµÕ±Ù¸ð", 22);
	(HFONT)SelectObject(_dc, namefont);
	// Player Lv & Name
	TextOut(_dc, _curPokeHpBarTexPos.x + 192, _curPokeHpBarTexPos.y + 12, lvText.c_str(), lvText.length());
	TextOut(_dc, _curPokeHpBarTexPos.x + 30, _curPokeHpBarTexPos.y + 10, _curPokemon->PokemonName.c_str(), _curPokemon->PokemonName.length());
	// Wild Lv & Name
	TextOut(_dc, _wildPokeHpBarTexPos.x + 168, _wildPokeHpBarTexPos.y + 12, wLvText.c_str(), wLvText.length());
	TextOut(_dc, _wildPokeHpBarTexPos.x + 10, _wildPokeHpBarTexPos.y + 10, _wildPokemon->PokemonName.c_str(), _wildPokemon->PokemonName.length());
	
	SelectObject(_dc, oldFont);
	SetTextColor(_dc, oldColor);
	DeleteObject(font);
	DeleteObject(namefont);

	Scene::Render(_dc);
}

void BattleScene::Release()
{
	std::vector<Pokemon*> playerPokemons;
	_playerPokemons = playerPokemons;
	BattleUIMgr::GetInst()->ReleaseBattleUI();
	Scene::Release();
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
	if (_playerPokemons[0]->Stats.Speed > _wildPokemon->Stats.Speed) {			// Player first
		firstActionPokemon = _playerPokemons.front();
		secondActionPokemon = _wildPokemon;
	}
	else if (_playerPokemons[0]->Stats.Speed < _wildPokemon->Stats.Speed) {		// Wild frist
		firstActionPokemon = _wildPokemon;
		secondActionPokemon = _playerPokemons.front();
	}
	else { // <----------------------------------------------------------------------- Equals - Random select
		int randVal = rand() % 2;
		if (randVal == 0) { // <------------------------------------------------------ Player first
			firstActionPokemon = _playerPokemons.front();
			secondActionPokemon = _wildPokemon;
		}
		else { // <------------------------------------------------------------------- Wild first
			firstActionPokemon = _wildPokemon;
			secondActionPokemon = _playerPokemons.front();
		}
	} // Speed Calculation End

	// First action process
	//firstActionPokemon->UseSkill(secondActionPokemon, selectedSkill);				// First action pokemon attack

	//// Second action process
	//secondActionPokemon->UseSkill(firstActionPokemon, selectedSkill);				// Second action pokemon attack
}