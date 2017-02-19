#pragma once
#include "IScene.h"
#include "Stage.h"
#include "Player.h"
#include "SoundMgr.h"
#include "Font.h"

class CGameScene : public IScene {
public:
	CGameScene();
	~CGameScene();
	Player *player;
	CSprite *cartoon[3];
	SoundMgr *sound;

	Font* font;

	RECT gameStopBtn;
	int cartoonPage;
	bool isCartoon, isChangeScene, isChangeSceneMenu;
	bool helpflag = false;
	bool issleep = false;
	bool loading = false;
	int starCount;
	int order=0;

	void starSet();

	void Update(float eTime);
	void Render();

	void UpdateRunning(float eTime);
	void UpdateGameover(float eTime);
	void UpdateStop(float eTime);
	void UpdateClear(float eTime);

	void RenderEveryTime();
	void RenderStop();
	void RenderGameover();
	void RenderClear();

	BOOL inBounds(D3DXVECTOR2 vector, RECT rect);
};