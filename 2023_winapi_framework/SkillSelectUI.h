#pragma once
#include "BattleUI.h"
class SkillSelectBtn;
class SkillSelectUI :
    public BattleUI
{
public:
    SkillSelectUI();
    ~SkillSelectUI();
public:
    void Init() override;
    void Update() override;
private:
    std::vector<SkillSelectBtn*> _skillBtns;
};