#pragma once
#include "Object.h"

class Texture;

class UIButton :
    public Object
{


public:

    UIButton(wstring textureKey, wstring path, Vec2 pos, Vec2 scale);
    void Update() override;
    void Render(HDC _dc) override;
    virtual void OnClick() = 0;
    void CheckHover();

    void RenderBtnSelector(HDC _dc);

protected:
    Texture* _mainTex;
    RECT _btnRt;
    bool isHover;

    Texture* _btnSelectorLT;
    Texture* _btnSelectorLB;
    Texture* _btnSelectorRT;
    Texture* _btnSelectorRB;
};

