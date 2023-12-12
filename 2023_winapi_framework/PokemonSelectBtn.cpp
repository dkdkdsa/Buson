#include "pch.h"
#include "PokemonSelectBtn.h"

PokemonSelectBtn::PokemonSelectBtn(Pokemon* pokemon, int idx) : UIButton(L"NullPokemonSelectedBtn.bpm", L"Texture//Battle//Button//NullPokemonSelectedBtn.bpm", { 0, 0 }, { 300, 75 })
{
	_pokemon = pokemon;
	if (_pokemon != nullptr) {

	}
	else {

	}
}

PokemonSelectBtn::~PokemonSelectBtn()
{
}
