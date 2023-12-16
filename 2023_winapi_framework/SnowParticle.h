#pragma once
#include "Object.h"

class Texture;

class SnowParticle : Object
{

public:
	SnowParticle(Vec2 pos);
	~SnowParticle();
	void Update() override;
	void Render(HDC _dc) override;

private:
	Texture* _tex;

};

