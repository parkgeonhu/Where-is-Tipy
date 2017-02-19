#include "CGameScene.h"
#include "Def.h"
#include "Stage.h"

extern CSprite *g_map;
extern GameState state;

Stage::Stage(SoundMgr *sound)
{
	this->sound = sound;
	isStage7Button[0] = isStage7Button[1] = isStage7Button[2] = false;
	stage[0] = new CSprite("image/Stage/Stage1.png");
	stage[1] = new CSprite("image/Stage/Stage2.png");
	stage[2] = new CSprite("image/Stage/Stage3.png");
	stage[3] = new CSprite("image/Stage/Stage4.png");
	stage[4] = new CSprite("image/Stage/Stage6.png");
	stage[5] = new CSprite("image/Stage/Stage7.png");
	stage[6] = new CSprite("image/Stage/Stage8.png");
	footHold = new CSprite("image/Stage/footHold.png");
	Stage4foot = new CSprite("image/Stage/Stage4foot.png");
	stage7FootHold = new CSprite("image/Stage/Stage7FootHold.png");
	sky[0] = new CSprite("image/Stage/Sky1.png");
	water[0] = new CSprite("image/Stage/Stage3water.png");
	waterHover[0] = new CSprite("image/Stage/Stage3waterHover.png");
	water[1] = new CSprite("image/Stage/Stage4water.png");
	waterHover[1] = new CSprite("image/Stage/Stage4waterHover.png");
	water[2] = new CSprite("image/Stage/Stage6water.png");
	waterHover[2] = new CSprite("image/Stage/Stage6waterHover.png");

	button[0] = new CSprite("image/Button/button.png");
	button[1] = new CSprite("image/Button/button.png");
	button[2] = new CSprite("image/Button/button.png");
	button[3] = new CSprite("image/Button/button.png");
	button[4] = new CSprite("image/Button/button.png");
	button[5] = new CSprite("image/Button/button.png");

	buttonHover[0] = new CSprite("image/Button/buttonHover.png");
	buttonHover[1] = new CSprite("image/Button/buttonHover.png");
	buttonHover[2] = new CSprite("image/Button/buttonHover.png");
	buttonHover[3] = new CSprite("image/Button/buttonHover.png");
	buttonHover[4] = new CSprite("image/Button/buttonHover.png");
	buttonHover[5] = new CSprite("image/Button/buttonHover.png");
	egg[0] = new CSprite("image/egg/egg.png");
	egg[1] = new CSprite("image/egg/egg.png");
	egg[2] = new CSprite("image/egg/egg.png");
	egg[3] = new CSprite("image/egg/egg.png");
	egg[4] = new CSprite("image/egg/egg.png");
	egg[5] = new CSprite("image/egg/egg.png");
	bigEgg = new CSprite("image/egg/bigEgg.png");
	bossHippoAni = new CAnimation(5, 5.0f);
	bossHippoAni->PushFrame("image/Hippo/bossHippo1.png", 0);
	bossHippoAni->PushFrame("image/Hippo/bossHippo2.png", 1);
	bossHippoAni->PushFrame("image/Hippo/bossHippo3.png", 2);
	bossHippoAni->PushFrame("image/Hippo/bossHippo4.png", 3);
	bossHippoAni->PushFrame("image/Hippo/bossHippo5.png", 4);
	bossHippoAni->pos.x = 512;
	bossHippoAni->pos.y = 610;
	for (int i = 0; i < 2; i++)
	{
		hippo[i] = new Hippo();
	}

	nowStage = 0;
	isWaterIn = isButton = false;
	hippoStage[0] = 4; hippoCount[0] = 2;
	hippoStage[1] = 5; hippoCount[1] = 2;

	fatherPos[0][0] = 120;
	fatherPos[0][1] = stage[0]->height - 120;
	motherPos[0][0] = 60;
	motherPos[0][1] = stage[0]->height - 120;
	childPos[0][0] = 10;
	childPos[0][1] = stage[0]->height - 120;

	fatherPos[1][0] = 120;
	fatherPos[1][1] = stage[0]->height - 120;
	motherPos[1][0] = 60;
	motherPos[1][1] = stage[0]->height - 120;
	childPos[1][0] = 10;
	childPos[1][1] = stage[0]->height - 120;

	fatherPos[2][0] = 120;
	fatherPos[2][1] = stage[0]->height - 120;
	motherPos[2][0] = 60;
	motherPos[2][1] = stage[0]->height - 120;
	childPos[2][0] = 10;
	childPos[2][1] = stage[0]->height - 120;

	fatherPos[3][0] = 120;
	fatherPos[3][1] = stage[0]->height - 568;
	motherPos[3][0] = 60;
	motherPos[3][1] = stage[0]->height - 558;
	childPos[3][0] = 10;
	childPos[3][1] = stage[0]->height - 568;

	fatherPos[4][0] = 120;
	fatherPos[4][1] = stage[0]->height - 118 - 100;
	motherPos[4][0] = 60;
	motherPos[4][1] = stage[0]->height - 118 - 80;
	childPos[4][0] = 10;
	childPos[4][1] = stage[0]->height - 118 - 50;

	fatherPos[5][0] = 120;
	fatherPos[5][1] = stage[0]->height - 368 - 100;
	motherPos[5][0] = 60;
	motherPos[5][1] = stage[0]->height - 368 - 80;
	childPos[5][0] = 10;
	childPos[5][1] = stage[0]->height - 368 - 50;


	fatherPos[5][0] = 120;
	fatherPos[5][1] = stage[0]->height - 368 - 100;
	motherPos[5][0] = 60;
	motherPos[5][1] = stage[0]->height - 368 - 80;
	childPos[5][0] = 10;
	childPos[5][1] = stage[0]->height - 368 - 50;

	fatherPos[6][0] = 120;
	fatherPos[6][1] = 100;
	motherPos[6][0] = 60;
	motherPos[6][1] = 100;
	childPos[6][0] = 10;
	childPos[6][1] = 100;

	MinChoiceCount[0] = 4;
	waterRectCount[0] = 0;
	buttonRectCount[0] = 0;
	footholdRectCount[0] = 0;
	stageRect[0][0] = Rect(0, stage[0]->height - 120, stage[0]->width, stage[0]->height);
	stageRect[0][1] = Rect(412, 578, 412 + 320, 578 + 70);
	clearRect[0] = Rect(920 - 70, 0, 920 + 70, 598 + 100 + 60);
	isLieRect[0][0] = false;
	isLieRect[0][1] = false;

	MinChoiceCount[1] = 3;
	waterRectCount[1] = 0;
	buttonRectCount[1] = 0;
	footholdRectCount[1] = 0;
	stageRect[1][0] = Rect(0, stage[0]->height - 120, stage[1]->width, stage[1]->height);
	stageRect[1][1] = Rect(300, 0, 800, stage[0]->height - 120 - 70);
	stageRect[1][2] = Rect(300, stage[0]->height - 120 - 70, 800, stage[1]->height - 120);
	clearRect[1] = Rect(920 - 70, 0, 920 + 70, 598 + 100 + 60);
	isLieRect[1][0] = false;
	isLieRect[1][1] = false;
	isLieRect[1][2] = true;

	MinChoiceCount[2] = 3;
	waterRectCount[2] = 1;
	buttonRectCount[2] = 0;
	footholdRectCount[2] = 0;
	stageRect[2][0] = Rect(0, 768 - 118, 250, 768);
	stageRect[2][1] = Rect(250, 768 - 38, 650, 768);
	stageRect[2][2] = Rect(590, 768 - 38 - 40, 650, 768 - 38);
	stageRect[2][3] = Rect(650, 768 - 118, 1024, 768);
	waterRect[2][0] = Rect(250, 768 - 38 - 80, 650, 768 - 38);
	water[0]->pos.x = 250; water[0]->pos.y = 768 - 38 - 80;
	waterHover[0]->pos.x = 250; waterHover[0]->pos.y = 768 - 38 - 80;
	clearRect[2] = Rect(920 - 70, 0, 920 + 70, 598 + 100 + 60);
	isLieRect[2][0] = false;
	isLieRect[2][1] = false;
	isLieRect[2][2] = false;
	isLieRect[2][3] = false;

	MinChoiceCount[3] = 3;
	waterRectCount[3] = 1;
	buttonRectCount[3] = 1;
	footholdRectCount[3] = 2;
	stageRect[3][0] = Rect(0, 768 - 568, 200, 768);
	stageRect[3][1] = Rect(200, 768 - 428, 600, 768);
	stageRect[3][2] = Rect(600, 768 - 568, 750, 768);
	stageRect[3][3] = Rect(900, 768 - 568, 1024, 768);
	waterRect[3][0] = Rect(200, 768 - 428 - 60, 600, 768 - 428);
	water[1]->pos.x = 200; water[1]->pos.y = 768 - 428 - 60;
	waterHover[1]->pos.x = 200; waterHover[1]->pos.y = 768 - 428 - 60;
	buttonRect[3][0] = Rect(660, 170, 690, 200);
	button[0]->pos.x = 660; button[0]->pos.y = 170;
	buttonHover[0]->pos.x = 660; buttonHover[0]->pos.y = 170 + 14;
	footholdRect[3][0] = Rect(500, 290, 550, 340);
	footholdRect[3][1] = Rect(550, 240, 600, 340);
	Stage4foot->pos.x = 500; Stage4foot->pos.y = 240;
	clearRect[3] = Rect(920 - 70, 0, 920 + 70, 598 + 100 + 60);
	isLieRect[3][0] = false;
	isLieRect[3][1] = false;
	isLieRect[3][2] = false;
	isLieRect[3][3] = false;

	MinChoiceCount[4] = 4;
	waterRectCount[4] = 1;
	buttonRectCount[4] = 0;
	footholdRectCount[4] = 0;
	stageRect[4][0] = Rect(0, 768 - 120, 300, 768);
	stageRect[4][1] = Rect(300, 648 + 60, 600, 768);
	stageRect[4][2] = Rect(600, 768 - 120, 700, 768);
	stageRect[4][3] = Rect(700, 768 - 48, 850, 768);
	stageRect[4][4] = Rect(850, 768 - 120, 1024, 768);
	hippoPos[0][0] = 700 + 5; hippoPos[0][1] = 640;
	hippoPos[1][0] = 700 + 15 + hippo[0]->getWidth(); hippoPos[1][1] = 640;
	waterRect[4][0] = Rect(300, 648, 600, 648 + 60);
	clearRect[4] = Rect(920 - 70, 0, 920 + 70, 598 + 100 + 60);
	isLieRect[4][0] = false;
	isLieRect[4][1] = false;
	isLieRect[4][2] = false;
	isLieRect[4][3] = false;
	isLieRect[4][4] = false;

	MinChoiceCount[5] = 4;
	waterRectCount[5] = 0;
	buttonRectCount[5] = 2;
	footholdRectCount[5] = 0;
	stageRect[5][0] = Rect(0, 768 - 368, 200, 768);
	stageRect[5][1] = Rect(200, 768 - 68, 200 + 424, 768);
	stageRect[5][2] = Rect(1024 - 400 - 80 - 300, 768 - 68 - 300, 1024 - 400 - 80, 768 - 68 - 300 + 98);
	stageRect[5][3] = Rect(200 + 424, 768 - 368, 1024, 768);
	stageRect[5][4] = Rect(1024 - 400 - 80, 700, 1024 - 400, 700 + 300);
	footholdRect[5][0] = Rect(1024 - 400 - 80, 700, 1024 - 400, 700 + 300);
	buttonRect[5][0] = Rect(210, 700 - 30, 250, 700);
	buttonRect[5][1] = Rect(650, 300 + 70, 680, 400);
	button[1]->pos.x = 210; button[1]->pos.y = 670;
	buttonHover[1]->pos.x = 210; buttonHover[1]->pos.y = 670 + 14;
	button[2]->pos.x = 650; button[2]->pos.y = 300 + 70;
	buttonHover[2]->pos.x = 650; buttonHover[2]->pos.y = 370 + 14;
	clearRect[5] = Rect(920 - 70, 0, 920 + 70, 598 + 100 + 60);
	hippoPos[2][0] = (1024 - 780) + 10; hippoPos[2][1] = 400 - hippo[0]->getHeight() + 10;
	hippoPos[3][0] = (1024 - 780) + hippo[0]->getWidth() * 2 + 20; hippoPos[3][1] = 400 - hippo[0]->getHeight() + 10;
	hippoPos[4][0] = (1024 - 780) + 10 + hippo[0]->getWidth(); hippoPos[4][1] = 400 - hippo[0]->getHeight() + 10 + hippo[0]->getHeight() - 15;
	hippoPos[5][0] = (1024 - 780) + hippo[0]->getWidth() * 2 + 20 + hippo[0]->getWidth(); hippoPos[5][1] = 400 - hippo[0]->getHeight() + 10 + hippo[0]->getHeight() - 15;
	isLieRect[5][0] = false;
	isLieRect[5][1] = false;
	isLieRect[5][2] = false;
	isLieRect[5][3] = false;
	isLieRect[5][4] = false;

	MinChoiceCount[6] = 5;
	waterRectCount[6] = 0;
	buttonRectCount[6] = 3;
	footholdRectCount[6] = 0;
	stageRect[6][0] = Rect(0, 228, 200, 388);
	stageRect[6][1] = Rect(0, 478, 200, 548);
	stageRect[6][2] = Rect(0, 658, 200, 768);
	stageRect[6][3] = Rect(824, 428, 1024, 513);
	stageRect[6][4] = Rect(824, 568, 1024, 768);
	stageRect[6][5] = Rect(200, 658, 824, 768); //보스 서 있을 타일
	footholdRect[6][0] = Rect(200, 658, 824, 768);
	buttonRect[6][0] = Rect(0, (388 + 478) / 2, 30, (388 + 478) / 2 + 30);
	buttonRect[6][1] = Rect(0, (548 + 658)/2, 30, (548 + 658)/2+30);
	buttonRect[6][2] = Rect(1024 - 30, (518) + 30, 1024, (518 + 568) / 2 + 30); //완료(3:45)

	button[3]->pos.x = 0; button[3]->pos.y = (388 + 478) / 2 + 15; //왼쪽 상단
	buttonHover[3]->pos.x = 0; buttonHover[3]->pos.y = (388 + 478) / 2 + 15 + 14;

	button[4]->pos.x = 0; button[4]->pos.y = (548 + 658) / 2 + 25; //왼쪽 하단
	buttonHover[4]->pos.x = 0; buttonHover[4]->pos.y = (548 + 658) / 2 + 25 + 14;

	button[5]->pos.x = 1024 - 30; button[5]->pos.y = (518) + 20; //오른쪽
	buttonHover[5]->pos.x = 1024 - 30; buttonHover[5]->pos.y = (518) + 20 + 14;

	//clearRect[5] = Rect(920 - 70, 0, 920 + 70, 598 + 100 + 60);
	isLieRect[6][0] = false;
	isLieRect[6][1] = false;
	isLieRect[6][2] = false;
	isLieRect[6][3] = false;
	isLieRect[6][4] = false;
	isLieRect[6][5] = false;


	//egg 스테이지 별 위치
	egg[0]->pos.x = 920; //확인
	egg[0]->pos.y = 598-5;
	egg[1]->pos.x = 920; //확인
	egg[1]->pos.y = 598-5;
	egg[2]->pos.x = 920; //확인 수정 필요?
	egg[2]->pos.y = 598-5;
	egg[3]->pos.x = 940; //확인 x
	egg[3]->pos.y = 768-568-58;
	egg[4]->pos.x = 920; //확인
	egg[4]->pos.y = 598-5;
	egg[5]->pos.x = 920; //확인
	egg[5]->pos.y = 768 - 368 - 58;

	rectCount[0] = 2;
	rectCount[1] = 3;
	rectCount[2] = 4;
	rectCount[3] = 4;
	rectCount[4] = 5;
	rectCount[5] = 5;
	rectCount[6] = 6;

	isStage6Button = false;
}

Stage::~Stage()
{
	delete sky[0];
}

void Stage::Update(float eTime)
{
	sound->Update();
	if (nowStage == hippoStage[0])
	{
		for (int j = 0; j < hippoCount[0]; j++)
		{
			hippo[j]->Update(eTime);
		}
	}
	if (nowStage == 5) { footHold->pos.y = stageRect[5][4].top - 400; }
	if (nowStage == 6) { bossHippoAni->Update(eTime); }
	if (nowStage == 6 && isStage7Button[0] && isStage7Button[1] && isStage7Button[2])
	{
		clear = 1;
	}
	if (clear)
	{
		if (stage7FootHold->pos.y  < 300)
		{
			stage7FootHold->pos.y += 50 * eTime;
			bossHippoAni->pos.y += 50 * eTime;
		}
		else
		{
			clear = 2;
			state = Clear;
			sound->Stop(INGAME_BGM);
			sound->Stop(BOSS_BGM);
			sound->Play(CLEAR_BGM);
		}
	}
}

void Stage::Render(D3DXMATRIX *pmat) {
	IObject::Render(pmat);
	sky[0]->Render(&this->mat);

	for (int i = 0; i < 2; i++)
	{
		if (nowStage == hippoStage[i])
		{
			for (int j = 0; j < hippoCount[i]; j++)
			{
				hippo[j]->Render(&this->mat);
			}
		}
	}
	stage[nowStage]->Render(&this->mat);
	
	if (nowStage == 5)
	{
		footHold->Render(&this->mat);
	}
	if (nowStage == 6)
	{
		stage7FootHold->Render(&this->mat);
		bossHippoAni->Render(&this->mat);
	}

	for (int i = 0; i < this->getButtonRectCount(nowStage); i++)
	{
		if (nowStage == 3)
		{
			if (isButton){ buttonHover[i]->Render(&this->mat); Stage4foot->Render(&this->mat); }
			else  button[i]->Render(&this->mat);
		}
		if (nowStage == 5)
		{
			//수정 시작
			if (isStage6Button){
				buttonHover[1]->Render(&this->mat);
			}
			else{
				button[1]->Render(&this->mat);
			}
			//수정 끝
			if (isButton){ buttonHover[2]->Render(&this->mat);}
			else  button[2]->Render(&this->mat);
		}
		else if (nowStage == 6)
		{
			if (isStage7Button[0]){ buttonHover[3]->Render(&this->mat); }
			else  { button[3]->Render(&this->mat); }
			if (isStage7Button[1]){ buttonHover[4]->Render(&this->mat); }
			else  { button[4]->Render(&this->mat); }
			if (isStage7Button[2]){ buttonHover[5]->Render(&this->mat); }
			else  { button[5]->Render(&this->mat); }
		}
	}
	if (nowStage < 6){ egg[nowStage]->Render(&this->mat); }

}

void Stage::Moving(float eTime)
{
	if (stageRect[5][4].top > 400)
	{
		stageRect[5][4].top -= 50 * eTime;
	}
	else
	{
		stageRect[5][4].top = 400;
	}
}