#pragma once
#include "CAnimation.h"
#include "myFunction.h"

class UI : public IObject{
private:
public:
	UI();
	~UI();


	bool menuflag = false;


	//��ũ��
	CSprite * gameover;
	CSprite * stop;
	CSprite * clear;
	CSprite * menuBackGround; //�޴� ��׶���
	CSprite * starScore0;  //�� 0��
	CSprite * starScore1;  //�� 1��
	CSprite * starScore2;  //�� 2��
	CSprite * starScore3;  //�� 3��
	CSprite * loading;

	CSprite * help1;
	CSprite * help2;
	CSprite * help3;
	CSprite * help4;  //select ���۹��

	//��ư
	CSprite * gamestopBtn; //�ΰ��ӿ��� ��ž��ư
	CSprite * fail_main;
	CSprite * fail_restart;
	CSprite * stop_main;
	CSprite * stop_restart;
	CSprite * stop_resume;
	CSprite * clear_restart;
	CSprite * clear_main;
	CSprite * clear_next;

	CSprite * menu_star[7][4]; //�޴��� �� ����
	CSprite * clear_star[4]; //Ŭ����ȭ�� �� ����

	CSprite * select_1;
	CSprite * select_2;
	CSprite * select_3;

	RECT stopRect[3];
	RECT clearRect[3];
	RECT gameoverRect[2];
	RECT gameStopBtnRect;
	RECT menuRect[7];

	RECT getGameStopBtn() { gameStopBtnRect = Rect(gamestopBtn->pos.x, gamestopBtn->pos.y, gamestopBtn->pos.x + gamestopBtn->width, gamestopBtn->pos.y + gamestopBtn->height); return gameStopBtnRect; }

	int stopRectCount = 3;
	int claerRectCount = 3;
	int gameoverRectCount = 2;
	int clearRectCount = 3;
	int eggCount = 7;

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);

	void ComponentSetPos();
};