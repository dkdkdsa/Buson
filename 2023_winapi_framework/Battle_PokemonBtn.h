#pragma once
#include "UIButton.h"
class Battle_PokemonBtn
	: public UIButton
{
public:
	Battle_PokemonBtn();
	~Battle_PokemonBtn();
public:
	void Update() override;
	void Render(HDC _dc) override;
	void OnClick() override;
};

