#include "CGameScene.h"
#include "CMenuScene.h"
#include "myFunction.h"
#include "Title.h"
#include "Def.h"
#include "UI.h"
#include <fstream>
#include <conio.h>

extern HWND g_hWnd;
extern UI * ui;
extern Stage * stage;

GameState state;

CGameScene::CGameScene() {
	sound = new SoundMgr();
	sound->addSound(BUTTON_BGM, "Sound/button.mp3");
	sound->addSound(CLEAR_BGM, "Sound/clear.mp3");
	sound->addSound(INGAME_BGM, "Sound/ingame.mp3");
	sound->addSound(MAIN_BGM, "Sound/main.mp3");
	sound->addSound(STAR_BGM, "Sound/star.mp3");
	sound->addSound(STORY1_BGM, "Sound/story1.mp3");
	sound->addSound(STORY2_BGM, "Sound/story2.mp3");
	sound->addSound(PLAYERUP_BGM, "Sound/dadup.mp3");
	sound->addSound(PLAYERDOWN_BGM, "Sound/babydown.mp3");
	sound->addSound(BOSS_BGM, "Sound/boss.mp3");
	sound->addSound(DEAD_BGM, "Sound/dead.mp3");
	player = new Player(stage, sound);
	font = new Font("굴림", 1, 25);
	isCartoon = cartoonPage = isChangeScene = isChangeSceneMenu = 0;
	cartoon[0] = new CSprite("image/Title/Comic/end1.png");
	cartoon[1] = new CSprite("image/Title/Comic/end2.png");
	cartoon[2] = new CSprite("image/Title/Comic/end3.png");
	helpflag = false;
	issleep = false;
	loading = false;
	state = Running;
	font->pos.x = 30 / 2;
	font->pos.y = 70 / 2;
}

CGameScene::~CGameScene() {
	delete player, sound;
	delete cartoon[0], cartoon[1], cartoon[2];
}

void CGameScene::Update(float eTime) {
	if (loading == true){
		sound->Update();
		sound->Stop(MAIN_BGM);
		if (state == Running){
			sound->Stop(CLEAR_BGM);
			sound->Stop(DEAD_BGM);
			if (stage->getNowStage() == 6){
				//sound->Stop(INGAME_BGM);
				sound->Playis(BOSS_BGM);
			}
			else{
				sound->Playis(INGAME_BGM);
			}
			UpdateRunning(eTime);
		}
		else if (state == GameOver){
			UpdateGameover(eTime);
		}
		else if (state == Stop){
			UpdateStop(eTime);
		}
		else if (state == Clear){
			UpdateClear(eTime);
		}
		if (stage->getNowStage() == 7) { sound->Stop(INGAME_BGM); sound->Stop(BOSS_BGM); isCartoon = true; }
		if (this->isCartoon)
		{
			sound->Stop(BOSS_BGM);
			sound->Playis(STORY2_BGM);
			if (MyKeyState(VK_SPACE) == 1)
			{
				if (cartoonPage == 2)
				{
					isChangeScene = true;
				}
				cartoonPage++;
			}
		}
		if (isChangeScene)
		{
			sound->Stop(BOSS_BGM);
			sound->Stop(STORY2_BGM);
			ChangeScene(new Title());
		}
		else if (isChangeSceneMenu)
		{
			sound->Stop(INGAME_BGM);
			sound->Stop(BOSS_BGM);
			ChangeScene(new CMenuScene(sound));
		}
	}
}

void CGameScene::Render() {
	if (issleep == true){
		Sleep(4000);
		loading = true;
		issleep = false;
	}
	if (loading == true){
		RenderEveryTime();
		if (state == Stop && !isCartoon){
			RenderStop();
		}
		else if (state == GameOver && !isCartoon){
			RenderGameover();
		}
		else if (state == Clear && !isCartoon){
			RenderClear();
		}
	}
	else{
		ui->loading->Render(&ui->mat);
		issleep = true;
	}
}

void CGameScene::UpdateRunning(float eTime){
	if (!isCartoon)
	{
		stage->Update(eTime);
		if (stage->clear != 1){ player->Update(eTime); }
		if (MyKeyState(VK_ESCAPE) == 1 || (MyKeyState(VK_LBUTTON) == 1 && inBounds(MyGetCursorPos(), ui->getGameStopBtn()))){
			state = Stop;
		}
		if (MyKeyState(VK_SPACE) == 1 || MyKeyState(VK_RETURN) == 1 || MyKeyState(VK_LEFT) == 1 || MyKeyState(VK_RIGHT) == 1 || MyKeyState(VK_UP) == 1 || MyKeyState(VK_DOWN) == 1){
			if (stage->getNowStage() == 0){
				if (order > 0){
					helpflag = true;
				}
				order++;
			}
			else{
				helpflag = true;
			}
		}
		if (!(stage->getNowStage() == 0 || stage->getNowStage() == 2 || stage->getNowStage() == 4)){
			helpflag = false;
		}
	}

} //게임 running state일 때 업데이트


void CGameScene::UpdateGameover(float eTime){
	if (MyKeyState(VK_LBUTTON) == 1){
		for (int i = 0; i < ui->gameoverRectCount; i++){
			if (inBounds(MyGetCursorPos(), ui->gameoverRect[i]) == true){
				if (i == 0){
					player->setting();
					state = Running;
				}
				else if (i == 1){
					isChangeSceneMenu = true;
				}
			}
		}
	}

} //게임오버 state일 때 업데이트

void CGameScene::UpdateStop(float eTime){
	if (MyKeyState(VK_ESCAPE) == 1 || (MyKeyState(VK_LBUTTON) == 1 && inBounds(MyGetCursorPos(), ui->getGameStopBtn()))){
		state = Running;
	}
	if (MyKeyState(VK_LBUTTON) == 1){
		for (int i = 0; i < ui->stopRectCount; i++){
			if (inBounds(MyGetCursorPos(), ui->stopRect[i]) == true){
				if (i == 0){
					player->setting();
					state = Running;
				}
				else if (i == 2){
					state = Running;
				}
				else if (i == 1){
					isChangeSceneMenu = true;
				}
			}
		}
	}

} //게임이 멈추었을 때 업데이트 부분

void CGameScene::UpdateClear(float eTime){

	if (MyKeyState(VK_LBUTTON) == 1){
		for (int i = 0; i < ui->clearRectCount; i++){
			if (inBounds(MyGetCursorPos(), ui->clearRect[i]) == true){
				if (i == 0){
					stage->setNowStage(stage->getNowStage());
					player->setting();
					state = Running;
				} //restart
				else if (i == 1){
					isChangeSceneMenu = true;
				} //menu
				else{
					stage->setNowStage(stage->getNowStage() + 1);
					player->setting();
					state = Running;
				} //next
			}
		}
	}
	if (MyKeyState(VK_SPACE) == 1)
	{
		stage->setNowStage(stage->getNowStage() + 1);
		player->setting();
		state = Running;
	}
}

void CGameScene::RenderEveryTime(){
	if (!isCartoon)
	{
		stage->Render(NULL);
		player->Render(NULL);

		//물 렌더
		if (stage->getNowStage() == 2)
		{
			if (stage->isWaterIn) { stage->waterHover[0]->Render(&stage->mat); }
			else { stage->water[0]->Render(&stage->mat); }
		}

		if (stage->getNowStage() == 3)
		{
			if (stage->isWaterIn) { stage->waterHover[1]->Render(&stage->mat); }
			else { stage->water[1]->Render(&stage->mat); }
		}
		if (stage->getNowStage() == 4)
		{
			if (stage->isWaterIn) { stage->waterHover[2]->Render(&stage->mat); }
			else { stage->water[2]->Render(&stage->mat); }
		}
		//물 렌더 끝
		ui->gamestopBtn->Render(NULL);
		if (player->select == 0){
			ui->select_1->Render(&ui->mat);
		}
		else if (player->select == 1){
			ui->select_2->Render(&ui->mat);
		}
		else if (player->select == 2){
			ui->select_3->Render(&ui->mat);
		}

		//바뀐 횟수 렌더 시작
		font->SetText("바뀐 횟수 : %d", player->choiceCount);
		font->Render();

		//help 렌더 시작
		if (stage->getNowStage() == 0 && helpflag == false){
			if (order == 0){
				ui->help1->Render(&ui->mat);
			}
			else{
				ui->help4->Render(&ui->mat);
			}
		}
		else if (stage->getNowStage() == 2 && helpflag == false){
			order = 0;  //ㄴ 상관
			ui->help2->Render(&ui->mat);
		}
		else if (stage->getNowStage() == 4 && helpflag == false){
			ui->help3->Render(&ui->mat);
		}
	}
	else
	{
		cartoon[cartoonPage]->Render(NULL);
	}
}

void CGameScene::RenderStop(){
	ui->stop->Render(&ui->mat);
	ui->stop_main->Render(&ui->mat);
	ui->stop_restart->Render(&ui->mat);
	ui->stop_resume->Render(&ui->mat);
}

void CGameScene::RenderGameover(){
	ui->gameover->Render(&ui->mat);
	ui->fail_main->Render(&ui->mat);
	ui->fail_restart->Render(&ui->mat);
}

void CGameScene::RenderClear(){
	if (player->choiceCount - stage->getMinChoiceCount(stage->getNowStage()) <= 0){ starCount = 3; }
	else if (player->choiceCount - stage->getMinChoiceCount(stage->getNowStage()) <= 1){ starCount = 2; }
	else if (player->choiceCount - stage->getMinChoiceCount(stage->getNowStage()) <= 2){ starCount = 1; }
	else { starCount = 0; }
	if (stage->menuStar[stage->getNowStage()] < starCount){
		stage->menuStar[stage->getNowStage()] = starCount;
		starSet();
	}
	ui->clear_star[starCount]->Render(&ui->mat);
	ui->clear_restart->Render(&ui->mat);
	ui->clear_main->Render(&ui->mat);
	ui->clear_next->Render(&ui->mat);
}

void CGameScene::starSet(){
	if (remove("star.txt") == -1)
		printf("star.txt를 삭제할 수 없습니다.\n");
	else
		printf("star.txt를 삭제하였습니다.\n");
	FILE *fp;
	fp = fopen("star.txt", "w");  // 파일 열기
	//ofstream logFile("star.txt", ios::out);
	static char str[50];
	for (int i = 0; i < 7; i++){
		static char temp[50];
		sprintf(temp, "%d ", stage->menuStar[i]);
		strcat(str, temp);
		memset(temp, 0, sizeof(temp));
	}
	fwrite(str, sizeof(str), 1, fp);
	memset(str, 0, sizeof(str));
	fclose(fp);
	//logFile << str;
	//logFile.close();
}

BOOL CGameScene::inBounds(D3DXVECTOR2 vector, RECT rect){
	if (vector.x > rect.left && vector.x < rect.right - 1 && vector.y > rect.top
		&& vector.y < rect.bottom - 1)
		return true;
	else
		return false;
}