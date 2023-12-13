#pragma once
#include "Object.h"
#include "pokemon.h"

class Texture;
class FieldObject :
    public Object
{

public:
    FieldObject(Pokemon pokemon);
    ~FieldObject();
    void Update() override;
    void Render(HDC _dc) override;

    Pokemon& GetPokemon() { return _pokemon; }
    void SetPokemon(Pokemon pokemon) { _pokemon = pokemon; }
    const RECT& GetRect() const { return _objRect; }
    void SetFieldRect(RECT rt) { _fieldRect = rt; }
    void SetIsDrag(bool b) { _isDrag = b; }
    Vec2 Lerp(Vec2 a, Vec2 b, float t) {

        return Vec2({ a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t });

    }

    const Texture* GetTexture() const { return _texture; }

private:
    Texture* _texture;
    Pokemon _pokemon;
    RECT _objRect;
    RECT _fieldRect;
    HBITMAP _flipBm;
    HDC _flipDc;
    HDC _outLineDc;
    HBITMAP _outLineBM;
    float _coolTime;
    float _curTime;
    bool _flip;
    bool _isMove;
    bool _isDrag;
    Vec2 _origin, _end;
    float per;
    Vec2 originScale;

};

