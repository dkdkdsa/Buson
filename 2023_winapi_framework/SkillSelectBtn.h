#pragma once
#include "UIButton.h"
#include "Skill.h"

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
    void InitSkill(Skill* skill);
    void Update() override;
    void Render(HDC _dc) override;
    void OnClick() override;
    void PosInit(BtnPos _btnpos);
private:
    int _idx;
};