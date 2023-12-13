#pragma once
#include "UIButton.h"
class RunBtn :
    public UIButton
{
public:
    RunBtn();
    ~RunBtn();
public:
    void Render(HDC _dc) override;
    void OnClick() override;
};

