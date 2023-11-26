#pragma once
#include "UIButton.h"

class FieldScene;

class PokemonMakeBtn :
    public UIButton
{

public:
    PokemonMakeBtn();
    void OnClick() override;
    void SetFieldScene(FieldScene* scene) { _fieldScene = scene; }

private:
    FieldScene* _fieldScene;

};

