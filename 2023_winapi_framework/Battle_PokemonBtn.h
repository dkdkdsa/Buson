#pragma once
#include "UIButton.h"
class Battle_PokemonBtn
	: public UIButton
{
public:
	Battle_PokemonBtn();
	~Battle_PokemonBtn();
public:
	void OnClick() override;
};

