#pragma once
#include "CAnimation.h"
#include "SoundMgr.h"
#include "Stage.h"

class Player : public IObject{
private:
	SoundMgr *sound;
	CSprite *player[3], *playerLie[3];
	bool playerMove, isLieSuccess, isClear;
	RECT rtCrash, blockRect, playerRect, comparePlayerRect, *stageRect;
	bool isJumping[3], isFalling[3], isLie[3], isButton, isUp;
	int jump[3];
	int jumpMax[3];

	CAnimation *pAni[3], *pLieAni[3];

	int speedY, fallCount;
	double time;
public:

	Player(Stage *stage, SoundMgr *sound);
	~Player();

	Stage *stage;
	int choiceCount;
	int select;

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);

	void setting();

	void Fall(float eTime);
	void Jump(float eTime);
	
	
	
	BOOL IntersectRect(_Out_ LPRECT lprcDst, _In_ CONST RECT *lprcSrc1, _In_ CONST RECT *lprcSrc2)
	{
		if ((lprcSrc1->left < lprcSrc2->right && lprcSrc1->right > lprcSrc2->left) &&
			(lprcSrc1->top < lprcSrc2->bottom && lprcSrc1->bottom > lprcSrc2->top))
		{
			return TRUE;
		}

		return FALSE;
	}
};