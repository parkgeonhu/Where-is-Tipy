#include "CMenuScene.h"
#include "CGameScene.h"
#include "myFunction.h"
#include "Title.h"
#include "Def.h"
#include "UI.h"
#include <fstream>

extern UI * ui;  //�ʼ� ui

Stage * stage;

CMenuScene::CMenuScene(SoundMgr *sound){
	stage = new Stage(sound);
	this->sound = sound;
	starRead();
}

CMenuScene::~CMenuScene(){
}

void CMenuScene::starRead(){
	FILE *fp;
	string * result;
	char s[81];
	int i = 0;
	fp = fopen("star.txt", "r");  // ���� ����

	while (fgets(s, 81, fp) != NULL) {
		s[strlen(s) - 1] = '\0';
	}
	result = strSplit(s, " ");
	for (int i = 0; i < 7; i++){
		stage->menuStar[i] = atoi(result[i].c_str());
	}
	fclose(fp);
}

void CMenuScene::Update(float eTime){
	sound->Update();
	sound->Playis(MAIN_BGM);
	D3DXVECTOR2 tempMouse = MyGetCursorPos();
	if (MyKeyState(VK_LBUTTON) == 1){
		for (int i = 0; i < ui->eggCount; i++){
			if (inBounds(tempMouse, ui->menuRect[i])){
				stage->setNowStage(i);
				ChangeScene(new CGameScene());
			}
		}
	}
}



void CMenuScene::Render(){
	ui->menuBackGround->Render(&ui->mat);
	for (int i = 0; i<7; i++){
		ui->menu_star[i][stage->menuStar[i]]->Render(&ui->mat);
	}
}

BOOL CMenuScene::inBounds(D3DXVECTOR2 vector, RECT rect){
	if (vector.x > rect.left && vector.x < rect.right - 1 && vector.y > rect.top
		&& vector.y < rect.bottom - 1)
		return true;
	else
		return false;
}