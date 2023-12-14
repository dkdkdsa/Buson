#pragma once
#include "UIButton.h"
class PokemonSelectCancelBtn :
    public UIButton
{
public:
    PokemonSelectCancelBtn();
    ~PokemonSelectCancelBtn();
public:
    void Update() override;
    void Render(HDC _dc) override;
    void OnClick() override;
};