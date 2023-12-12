#pragma once
#include "Scene.h"
#include "pokemon.h"
#include "BattleUI.h"

class Texture;
class BattleScene : public Scene
{
public:
	virtual void Init() override;
	// ��Ʋ ���� �������� �Է� ��⸦ �ް� (�̶� �Է��� ��� PtInRect()�� ����ؼ� ���콺 ����Ʈ�� ��Ʈ ���ο� �ִ��� üũ) 
	// �Է��� ������ UI ���� ������Ʈ�� ������ ���ְ� UI �� ���� ��Ű�� �� ������ �ٽ� ������ Ų��. (�ؿ�� �����ӿ�ũ�� ��� ������Ʈ�� �׾��� ��� ǥ��)
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