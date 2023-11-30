#pragma once
#include "UIButton.h"
class FightBtn :
    public UIButton
{
public:
    FightBtn();
    ~FightBtn();
public:
    void OnClick() override;
private:
};

