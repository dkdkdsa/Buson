#pragma once
#include "BattleUI.h"
class NullUI :
    public BattleUI
{
public:
    NullUI();
    ~NullUI();
public:
    void Init() override;
    void Update() override;
    void Render(HDC _dc) override;
private:
};

