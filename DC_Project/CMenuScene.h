
#pragma once
#include "SoundMgr.h"
#include "IScene.h"
#include "Stage.h"
#include "Player.h"

class CMenuScene : public IScene {
public:

	CMenuScene(SoundMgr *sound);
	~CMenuScene();

	SoundMgr *sound;

	void Update(float eTime);
	void Render();

	void starRead();

	BOOL inBounds(D3DXVECTOR2 vector, RECT rect);
};