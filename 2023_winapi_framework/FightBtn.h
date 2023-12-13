#pragma once
#include "UIButton.h"
class FightBtn :
    public UIButton
{
public:
    FightBtn();
    ~FightBtn();
public:
    void Render(HDC _dc) override;
    void OnClick() override;
};

