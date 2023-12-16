#pragma once
#include "UIButton.h"
class PokemonShiftCancelBtn :
    public UIButton
{
public:
    PokemonShiftCancelBtn();
    ~PokemonShiftCancelBtn();
public:
    void Update() override;
    void Render(HDC _dc) override;
    void OnClick() override;
private:

};