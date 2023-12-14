#pragma once
#include "UIButton.h"
class RunBtn :
    public UIButton
{
public:
    RunBtn();
    ~RunBtn();
public:
    void Update() override;
    void Render(HDC _dc) override;
    void OnClick() override;
};

