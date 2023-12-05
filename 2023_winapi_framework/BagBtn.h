#pragma once
#include "UIButton.h"
class BagBtn :
    public UIButton
{
public:
    BagBtn();
    ~BagBtn();
public:
    void OnClick() override;
};

