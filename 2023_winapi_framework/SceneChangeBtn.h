#pragma once
#include "UIButton.h"

class SceneChangeBtn :
    public UIButton
{

public:
    SceneChangeBtn(Vec2 pos, Vec2 scale, wstring texKey, wstring path, wstring sceneName);
    ~SceneChangeBtn();
    void Update() override;
    void OnClick() override;
    void Render(HDC _dc) override;
    Vec2 offset;

private:
    wstring sceneName;

};

