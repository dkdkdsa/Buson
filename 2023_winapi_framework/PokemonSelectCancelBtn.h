#pragma once
#include "UIButton.h"
class PokemonSelectCancelBtn :
    public UIButton
{
public:
    PokemonSelectCancelBtn();
    ~PokemonSelectCancelBtn();
public:
    void Render(HDC _dc) override;
    void OnClick() override;
};