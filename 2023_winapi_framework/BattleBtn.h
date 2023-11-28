#pragma once
#include "UIButton.h"
class BattleBtn :
    public UIButton
{
public:
    BattleBtn();
    ~BattleBtn();
public:
    void OnClick() override;
private:

};

