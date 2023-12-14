#pragma once
#include "UIButton.h"

enum class BtnPos {
    LT = 0,
    LB,
    RT,
    RB
};

class SkillSelectBtn :
    public UIButton
{
public:
    SkillSelectBtn();
    ~SkillSelectBtn();
public:
    void Update() override;
    void Render(HDC _dc) override;
    void OnClick() override;
    void PosInit(BtnPos _btnpos);
private:
    int _idx;
};