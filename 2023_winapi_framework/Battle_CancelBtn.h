#pragma once
#include "UIButton.h"
class Battle_CancelBtn :
    public UIButton
{
public:
    Battle_CancelBtn();
    ~Battle_CancelBtn();
public:
    void Render(HDC _dc) override;
    void OnClick() override;
};