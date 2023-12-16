#include "pch.h"
#include "BattleMgr.h"
#include "DeckManager.h"
#include "PokemonManager.h"
#include "pokemon.h"
void BattleMgr::Init()
{

}

void BattleMgr::Update()
{
}

void BattleMgr::Render(HDC _dc)
{
}

void BattleMgr::SetWildPokemon()
{
	std::dynamic_pointer_cast<BattleScene>(SceneMgr::GetInst()->GetCurScene())->SetWildPokemon();
}
