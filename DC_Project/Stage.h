#pragma once
#include "CAnimation.h"
#include "myFunction.h"
#include "Hippo.h"
#include "SoundMgr.h"
class Stage : public IObject{
private:
	CSprite *stage[9], *footHold, *Stage4foot;
	CSprite *sky[3];

	CSprite *button[6], *buttonHover[6];
	CSprite * egg[6];
	CSprite * bigEgg;
	CAnimation *bossHippoAni;
	CSprite *stage7FootHold;
	RECT stageRect[9][9];
	RECT clearRect[9];
	RECT waterRect[9][2];
	RECT buttonRect[9][3];
	RECT footholdRect[9][2];
	SoundMgr *sound;

	int rectCount[9];
	int fatherPos[9][2];
	int motherPos[9][2];
	int childPos[9][2];
	int isLieRect[9][9];
	int waterRectCount[9];
	int footholdRectCount[9];
	int buttonRectCount[9];
	int hippoStage[2];
	int hippoCount[2];
	int MinChoiceCount[7];
	int nowStage;
	double hippoPos[6][2];

protected:

public:
	bool isWaterIn;
	bool isButton;
	bool isStage7Button[3];
	bool isStage6Button;
	bool flag = false;

	CSprite *water[3], *waterHover[3];

	int clear;
	int menuStar[7];
	Stage(SoundMgr *sound);
	~Stage();

	Hippo *hippo[2];

	bool getIsLieRect(int rectNum) { return isLieRect[nowStage][rectNum]; }
	int* getFatherPos(int stage){ return fatherPos[stage]; }
	int* getMotherPos(int stage){ return motherPos[stage]; }
	int* getChildPos(int stage){ return childPos[stage]; }
	int getNowStage(){ return nowStage; }
	int getRectCount(int i) { return rectCount[i]; }
	int getWaterRectCount(int stage) { return waterRectCount[stage]; }
	int getButtonRectCount(int stage) { return buttonRectCount[stage]; }
	int getfootholdRectCount(int stage) { return footholdRectCount[stage]; }
	int getHippoStage(int stage) { return hippoStage[stage]; }
	int getHippoCount(int stage) { return hippoCount[stage]; }
	int getMinChoiceCount(int stage){ return MinChoiceCount[stage]; }
	double* getHippoPos(int i) { return hippoPos[i]; }
	RECT* getStageRect(int stage) { return stageRect[stage]; }
	RECT getCelarStageRect(int stage) { return clearRect[stage]; }
	RECT* getWaterRect(int stage) { return waterRect[stage]; }
	RECT* getButtonRect(int stage) { return buttonRect[stage]; }
	RECT* getFootholdRect(int stage) { return footholdRect[stage]; }
	
	void Moving(float eTime);

	void setNowStage(int nowStage){
		this->nowStage = nowStage;
	}

	void setStageRect(RECT foothold) { if (nowStage == 5) { this->stageRect[5][4] = foothold; } else if (nowStage == 6) { this->stageRect[6][5] = foothold; } }

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);


};