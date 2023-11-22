#pragma once
#include "Object.h"
class Texture;
class FieldObject :
    public Object
{

public:
    FieldObject(wstring key);
    ~FieldObject();
    void Update() override;
    void Render(HDC _dc) override;

private:
    Texture* _texture;

};

