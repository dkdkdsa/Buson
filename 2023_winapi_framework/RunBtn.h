#pragma once
#include "UIButton.h"
class RunBtn :
    public UIButton
{
public:
    RunBtn();
    ~RunBtn();
public:
    void OnClick() override;
};

