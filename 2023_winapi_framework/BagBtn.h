#pragma once
#include "UIButton.h"
class BagBtn :
    public UIButton
{
public:
    BagBtn();
    ~BagBtn();
public:
    void Render(HDC _dc) override;
    void OnClick() override;
};

