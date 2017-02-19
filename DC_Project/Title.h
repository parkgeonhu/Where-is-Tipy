#pragma once
#include "IScene.h"
#include "CAnimation.h"
#include "SoundMgr.h"

class Title :public IScene
{
private:
public:
	CSprite *title, *player, *cartoon[11];
	CAnimation *pAni;
	SoundMgr *sound;
	int cartoonPage;
	double time;
	double movingPosY, posY;
	bool isJumping, isCartoon, isChangeScene, isDestoryWindow;

	bool loading = false;
	bool issleep = false;

	Title();
	~Title();
	void Update(float eTime);
	void Render();
};