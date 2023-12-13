#pragma once
#include "UIButton.h"

class FieldScene;

class PokemonMakeBtn :
    public UIButton
{

public:
    PokemonMakeBtn();
    void Update() override;
    void OnClick() override;
    void Render(HDC _dc) override;
    void SetFieldScene(FieldScene* scene) { _fieldScene = scene; }

private:
    FieldScene* _fieldScene;
    float per;
    Vec2 originScale;

};

