#pragma once
#include "Object.h"
class FieldDeckPanel :
    public Object
{

public:
    FieldDeckPanel(Vec2 pos, Vec2 scale);
    ~FieldDeckPanel();

    void Render(HDC _dc) override;

};

