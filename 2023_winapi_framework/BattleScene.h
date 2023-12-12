#pragma once
#include "Scene.h"
#include "pokemon.h"
#include "BattleUI.h"

class Texture;
class BattleScene : public Scene
{
public:
	virtual void Init() override;
	// 배틀 씬의 업뎃에서 입력 대기를 받고 (이때 입력의 경우 PtInRect()를 사용해서 마우스 포인트가 렉트 내부에 있는지 체크) 
	// 입력이 들어오면 UI 외의 오브젝트의 업뎃을 꺼주고 UI 만 업뎃 시키고 다 끝나면 다시 업뎃을 킨다. (준용쌤 프레임워크의 경우 오브젝트가 죽었다 라고 표현)
	void Update() override;
	void Render(HDC _dc) override;
	void Release() override;
	void PlayEnterBattleIntro();
	void BattleCycle(Skill* selectedSkill);
	void SetCurUI();
private:
	// Pokemons
	std::vector<Pokemon*> _playerPokemons;
	std::vector<Pokemon*> _wildPokemons;

	// Background
	Texture* _bgTex;
	Vec2 _bgScale;
	Vec2 _bgPos;
	// Platform - enemy
	Texture* _enemyPlatform;
	Vec2 _enemyPlatformPos;
	Vec2 _enemyPlatformScale;
	// Platform - player
	Texture* _playerplatform;
	Vec2 _playerPlatformPos;
	Vec2 _playerPlatformScale;

	


	// Battle UI
	BattleUI* _curUI;
	std::vector<BattleUI*> _battleUIVec;
};