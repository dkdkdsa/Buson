#pragma once
#include "UIButton.h"

class FieldDeckPanel;
class FieldDeckBtn :
    public UIButton
{

public:
    FieldDeckBtn(Vec2 pos, Vec2 scale);
    ~FieldDeckBtn();

    void Update() override;
    void OnClick() override;
    void SetFieldPanel(FieldDeckPanel* panel) { _panel = panel; }

private:
    Vec2 Lerp(Vec2 a, Vec2 b, float t) {

        return Vec2({ a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t });

    }

    FieldDeckPanel* _panel;
    float _per;
    Vec2 _origin, _panelOrigin;
    Vec2 _end, _panelEnd;
    bool _isFold;
    bool _isClick;

};

