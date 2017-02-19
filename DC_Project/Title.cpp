#include "Title.h"
#include "CMenuScene.h"
#include "myFunction.h"
#include "UI.h"

extern HWND g_hWnd;

UI * ui;

Title::Title()
{
	title = new CSprite("image/Title/Title.png");
	ui = new UI();
	player = new CSprite("image/Title/Hippo/stand/hippo1.png");
	cartoon[0] = new CSprite("image/Title/Comic/intro1-1.png");
	cartoon[1] = new CSprite("image/Title/Comic/intro1-2.png");
	cartoon[2] = new CSprite("image/Title/Comic/intro2-1.png");
	cartoon[3] = new CSprite("image/Title/Comic/intro2-2.png");
	cartoon[4] = new CSprite("image/Title/Comic/intro3-1.png");
	cartoon[5] = new CSprite("image/Title/Comic/intro3-2.png");
	cartoon[6] = new CSprite("image/Title/Comic/intro4-1.png");
	cartoon[7] = new CSprite("image/Title/Comic/intro4-2.png");
	cartoon[8] = new CSprite("image/Title/Comic/intro5-1.png");
	cartoon[9] = new CSprite("image/Title/Comic/intro5-2.png");
	cartoon[10] = new CSprite("image/Title/Comic/intro6.png");
	pAni = new CAnimation(8, 10.0f);
	pAni->PushFrame("image/Title/Hippo/stand/hippo2.png", 0);
	pAni->PushFrame("image/Title/Hippo/stand/hippo3.png", 1);
	pAni->PushFrame("image/Title/Hippo/stand/hippo4.png", 2);
	pAni->PushFrame("image/Title/Hippo/stand/hippo5.png", 3);
	pAni->PushFrame("image/Title/Hippo/stand/hippo6.png", 4);
	pAni->PushFrame("image/Title/Hippo/stand/hippo7.png", 5);
	pAni->PushFrame("image/Title/Hippo/stand/hippo8.png", 6);
	pAni->PushFrame("image/Title/Hippo/stand/hippo9.png", 7);
	sound = new SoundMgr();
	sound->addSound(BUTTON_BGM, "Sound/button.mp3");
	sound->addSound(CLEAR_BGM, "Sound/clear.mp3");
	sound->addSound(INGAME_BGM, "Sound/ingame.mp3");
	sound->addSound(MAIN_BGM, "Sound/main.mp3");
	sound->addSound(STAR_BGM, "Sound/star.mp3");
	sound->addSound(STORY1_BGM, "Sound/story1.mp3");
	sound->addSound(STORY2_BGM, "Sound/story2.mp3");
	sound->addSound(BOSS_BGM, "Sound/boss.mp3");
	player->scalingCenter = player->GetCenter();
	pAni->scalingCenter = player->GetCenter();
	player->pos.x = 100; player->pos.y = 650 - player->height;
	pAni->pos.x = 100; pAni->pos.y = 650 - player->height;
	posY = 650 - player->height;
	player->scale.x = -1; pAni->scale.x = -1;
	time = cartoonPage = 0;
	isJumping = isCartoon = isChangeScene = isDestoryWindow = false;
	issleep = false;
	loading = false;
}

Title::~Title()
{
	delete title;
	delete player, pAni;
	for (int i = 0; i < 10; i++){ delete cartoon[i]; }
}

void Title::Update(float eTime)
{
	sound->Update();
	if (loading == true){
		if (!isCartoon)
		{
			sound->Playis(MAIN_BGM);
			if (MyKeyState(VK_LEFT) > 0 || MyKeyState(VK_RIGHT) > 0) { pAni->Update(eTime); }
			else { player->Update(NULL); }

			if (MyKeyState(VK_LEFT) > 0) { player->pos.x -= 200 * eTime; player->scale.x = 1; pAni->scale.x = 1; }
			if (MyKeyState(VK_RIGHT) > 0) { player->pos.x += 200 * eTime; player->scale.x = -1; pAni->scale.x = -1; }

			time += eTime;

			if (MyKeyState(VK_SPACE) > 0 && !isJumping)
			{
				isJumping = true;
			}
			if (isJumping)
			{
				player->pos.y += movingPosY;
				movingPosY = sin(time * 3.5) * 100;
				player->pos.y -= movingPosY;
				if (player->pos.y > posY) { isJumping = false; }
			}
			if (!isJumping) { time = 0; }

			pAni->pos.x = player->pos.x; pAni->pos.y = player->pos.y;

			if (player->pos.x + player->width > 900)
			{
				sound->Stop(MAIN_BGM);
				isCartoon = true;
			}
			else if (player->pos.x + player->width < 0)
			{
				isDestoryWindow = true;
			}
		}
		else if (isCartoon) {
			sound->Playis(STORY1_BGM);
			if (MyKeyState(VK_SPACE) == 1)
			{
				if (cartoonPage == 10)
				{
					isChangeScene = true;
				}
				cartoonPage++;
			}
		}

		if (isChangeScene)
		{
			sound->Stop(MAIN_BGM);
			sound->Stop(STORY1_BGM);
			ChangeScene(new CMenuScene(sound));
		}
		else if (isDestoryWindow)
		{
			DestroyWindow(g_hWnd);
		}
	}
}

void Title::Render() {
	if (issleep == true){
		Sleep(2000);
		loading = true;
		issleep = false;
	}
	if (loading == true){
		title->Render(NULL);
		if (MyKeyState(VK_LEFT) > 0 || MyKeyState(VK_RIGHT) > 0) { pAni->Render(NULL); }
		else { pAni->Render(NULL); }

		if (isCartoon){ cartoon[cartoonPage]->Render(NULL); }
	}
	else{
		ui->loading->Render(&ui->mat);
		issleep = true;
	}
}