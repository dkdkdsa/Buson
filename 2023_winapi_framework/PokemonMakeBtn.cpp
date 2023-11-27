#include "pch.h"
#include "PokemonMakeBtn.h"
#include "PokemonManager.h"
#include "SceneMgr.h"
#include "FieldScene.h"
#include "Field.h"

PokemonMakeBtn::PokemonMakeBtn() : UIButton(L"asdf", L"asdf", Vec2({ 300, 100 }), Vec2({300, 75}))
{
}

void PokemonMakeBtn::OnClick()
{

	auto* field = _fieldScene->GetAbleField();
	field->AddPokemon(*PokemonManager::GetInst()->GetRamdomPokemonByLevel(1));

}
