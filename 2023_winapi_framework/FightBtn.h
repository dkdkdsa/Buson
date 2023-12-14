#pragma once
#include "UIButton.h"
class FightBtn :
    public UIButton
{
public:
    FightBtn();
    ~FightBtn();
public:
    void Update() override;
    void Render(HDC _dc) override;
    void OnClick() override;
};

