#include "CGameScene.h"
#include "Def.h"
#include "Player.h"
#include "myFunction.h"

extern CSprite *g_map;
extern GameState state;

Player::Player(Stage *stage, SoundMgr* sound)
{
	this->sound = sound;
	player[0] = new CSprite("image/Player/father/stand/crocodile1.png");
	player[1] = new CSprite("image/Player/mother/stand/crocodile1.png");
	player[2] = new CSprite("image/Player/baby/stand/crocodile1.png");
	playerLie[0] = new CSprite("image/Player/father/lie/crocodileLie1.png");
	playerLie[1] = new CSprite("image/Player/mother/lie/crocodileLie1.png");
	playerLie[2] = new CSprite("image/Player/baby/lie/crocodileLie1.png");
	this->stage = stage;

	pAni[0] = new CAnimation(8, 10.0f);
	pAni[0]->PushFrame("image/Player/father/stand/crocodile1.png", 0);
	pAni[0]->PushFrame("image/Player/father/stand/crocodile2.png", 1);
	pAni[0]->PushFrame("image/Player/father/stand/crocodile3.png", 2);
	pAni[0]->PushFrame("image/Player/father/stand/crocodile4.png", 3);
	pAni[0]->PushFrame("image/Player/father/stand/crocodile5.png", 4);
	pAni[0]->PushFrame("image/Player/father/stand/crocodile6.png", 5);
	pAni[0]->PushFrame("image/Player/father/stand/crocodile7.png", 6);
	pAni[0]->PushFrame("image/Player/father/stand/crocodile8.png", 7);
	pAni[1] = new CAnimation(8, 10.0f);
	pAni[1]->PushFrame("image/Player/mother/stand/crocodile1.png", 0);
	pAni[1]->PushFrame("image/Player/mother/stand/crocodile2.png", 1);
	pAni[1]->PushFrame("image/Player/mother/stand/crocodile3.png", 2);
	pAni[1]->PushFrame("image/Player/mother/stand/crocodile4.png", 3);
	pAni[1]->PushFrame("image/Player/mother/stand/crocodile5.png", 4);
	pAni[1]->PushFrame("image/Player/mother/stand/crocodile6.png", 5);
	pAni[1]->PushFrame("image/Player/mother/stand/crocodile7.png", 6);
	pAni[1]->PushFrame("image/Player/mother/stand/crocodile8.png", 7);
	pAni[2] = new CAnimation(8, 10.0f);
	pAni[2]->PushFrame("image/Player/baby/stand/crocodile1.png", 0);
	pAni[2]->PushFrame("image/Player/baby/stand/crocodile2.png", 1);
	pAni[2]->PushFrame("image/Player/baby/stand/crocodile3.png", 2);
	pAni[2]->PushFrame("image/Player/baby/stand/crocodile4.png", 3);
	pAni[2]->PushFrame("image/Player/baby/stand/crocodile5.png", 4);
	pAni[2]->PushFrame("image/Player/baby/stand/crocodile6.png", 5);
	pAni[2]->PushFrame("image/Player/baby/stand/crocodile7.png", 6);
	pAni[2]->PushFrame("image/Player/baby/stand/crocodile8.png", 7);

	pLieAni[0] = new CAnimation(4, 10.0f);
	pLieAni[0]->PushFrame("image/Player/father/lie/crocodileLie1.png", 0);
	pLieAni[0]->PushFrame("image/Player/father/lie/crocodileLie2.png", 1);
	pLieAni[0]->PushFrame("image/Player/father/lie/crocodileLie3.png", 2);
	pLieAni[0]->PushFrame("image/Player/father/lie/crocodileLie4.png", 3);
	pLieAni[1] = new CAnimation(4, 10.0f);
	pLieAni[1]->PushFrame("image/Player/mother/lie/crocodileLie1.png", 0);
	pLieAni[1]->PushFrame("image/Player/mother/lie/crocodileLie2.png", 1);
	pLieAni[1]->PushFrame("image/Player/mother/lie/crocodileLie3.png", 2);
	pLieAni[1]->PushFrame("image/Player/mother/lie/crocodileLie4.png", 3);
	pLieAni[2] = new CAnimation(4, 10.0f);
	pLieAni[2]->PushFrame("image/Player/baby/lie/crocodileLie1.png", 0);
	pLieAni[2]->PushFrame("image/Player/baby/lie/crocodileLie2.png", 1);
	pLieAni[2]->PushFrame("image/Player/baby/lie/crocodileLie3.png", 2);
	pLieAni[2]->PushFrame("image/Player/baby/lie/crocodileLie4.png", 3);

	player[0]->pos.x = stage->getFatherPos(stage->getNowStage())[0];
	player[0]->pos.y = stage->getFatherPos(stage->getNowStage())[1] - player[0]->height - 10;
	player[1]->pos.x = stage->getMotherPos(stage->getNowStage())[0];
	player[1]->pos.y = stage->getMotherPos(stage->getNowStage())[1] - player[1]->height - 10;
	player[2]->pos.x = stage->getChildPos(stage->getNowStage())[0];
	player[2]->pos.y = stage->getChildPos(stage->getNowStage())[1] - player[2]->height - 10;
	player[0]->scalingCenter = player[0]->GetCenter();
	pAni[0]->scalingCenter = player[0]->GetCenter();
	pAni[0]->pos.x = player[0]->pos.x; pAni[0]->pos.y = player[0]->pos.y;
	player[1]->scalingCenter = player[1]->GetCenter();
	pAni[1]->scalingCenter = player[1]->GetCenter();
	pAni[1]->pos.x = player[1]->pos.x; pAni[1]->pos.y = player[1]->pos.y;
	player[2]->scalingCenter = player[2]->GetCenter();
	pAni[2]->scalingCenter = player[2]->GetCenter();
	pAni[2]->pos.x = player[2]->pos.x; pAni[2]->pos.y = player[2]->pos.y;

	playerLie[0]->scalingCenter = playerLie[0]->GetCenter(); pLieAni[0]->scalingCenter = playerLie[0]->GetCenter();
	playerLie[1]->scalingCenter = playerLie[1]->GetCenter(); pLieAni[1]->scalingCenter = playerLie[1]->GetCenter();
	playerLie[2]->scalingCenter = playerLie[2]->GetCenter(); pLieAni[2]->scalingCenter = playerLie[2]->GetCenter();

	playerMove = false;
	isJumping[0] = isJumping[1] = isJumping[2] = isFalling[0] = isFalling[1] = isFalling[2] = false;
	fallCount = 0;
	time = 0;
	jump[0] = jump[1] = jump[2] = 0;
	jumpMax[0] = 300; jumpMax[1] = 360; jumpMax[2] = 335;
	select = 0;
	stageRect = stage->getStageRect(stage->getNowStage());
	isLie[0] = false; isLie[1] = false; isLie[2] = false, isButton = false;;

	setting();
}

Player::~Player()
{

	for (int i = 0; i < 3; i++)
	{
		delete pAni[i], pLieAni[i], player[i], playerLie[i];
	}
}

void Player::Update(float eTime)
{
	sound->Update();
	pAni[select]->Update(eTime);
	pLieAni[select]->Update(eTime);
	playerMove = true; isFalling[0] = isFalling[1] = isFalling[2] = true;
	time += eTime;

	if (MyKeyState('1') == 1) {
		if (select != 0){
			choiceCount++;
		}
		select = 0; 
	}
	if (MyKeyState('2') == 1) {
		if (select != 1){
			choiceCount++;
		}
		select = 1;
	}
	if (MyKeyState('3') == 1) {
		if (select != 2){
			choiceCount++;
		}
		select = 2; 
	}

	for (int i = 0; i < 3; i++)
	{
		if (player[select]->pos.x + player[select]->width + 200 * eTime < 1028 && MyKeyState(VK_RIGHT) > 0)
		{
			if (isLie[select]) { playerRect = Rect(playerLie[select]->pos.x + 200 * eTime, playerLie[select]->pos.y, playerLie[select]->pos.x + playerLie[select]->width + 200 * eTime, playerLie[select]->pos.y + playerLie[select]->height); }
			else  { playerRect = Rect(player[select]->pos.x + 200 * eTime, player[select]->pos.y, player[select]->pos.x + player[select]->width + 200 * eTime, player[select]->pos.y + player[select]->height); }

			for (int i = 0; i < stage->getRectCount(stage->getNowStage()); i++)
			{
				if (IntersectRect(&rtCrash, &stageRect[i], &playerRect))  { playerMove = false; }
				if (stage->getIsLieRect(i) && stageRect[i].top <= playerRect.top && stageRect[i].bottom >= playerRect.bottom)  { playerMove = true; }
			}
			for (int i = 0; i < 3; i++)
			{
				if (isLie[i]) { comparePlayerRect = Rect(playerLie[i]->pos.x, playerLie[i]->pos.y, playerLie[i]->pos.x + playerLie[i]->width, playerLie[i]->pos.y + playerLie[i]->height); }
				else { comparePlayerRect = Rect(player[i]->pos.x, player[i]->pos.y, player[i]->pos.x + player[i]->width, player[i]->pos.y + player[i]->height); }

				if (i != select && IntersectRect(&rtCrash, &comparePlayerRect, &playerRect)) { playerMove = false; }
			}
			if (isButton && stage->getNowStage() == 3)
			{
				for (int i = 0; i < stage->getfootholdRectCount(stage->getNowStage()); i++)
				{
					if (IntersectRect(&rtCrash, &stage->getFootholdRect(stage->getNowStage())[i], &playerRect))  { playerMove = false; }
				}
			}
			if (playerMove) { player[select]->pos.x += 200 * eTime / 3; playerLie[select]->pos.x += 200 * eTime / 3; }
		}
	}
	playerMove = true;
	for (int i = 0; i < 3; i++)
	{
		if (player[select]->pos.x - 200 * eTime > 0 && MyKeyState(VK_LEFT) > 0)
		{
			if (isLie[select]) { playerRect = Rect(playerLie[select]->pos.x - 200 * eTime, playerLie[select]->pos.y, playerLie[select]->pos.x + playerLie[select]->width - 200 * eTime, playerLie[select]->pos.y + playerLie[select]->height); }
			else  { playerRect = Rect(player[select]->pos.x - 200 * eTime, player[select]->pos.y, player[select]->pos.x + player[select]->width - 200 * eTime, player[select]->pos.y + player[select]->height); }
			for (int i = 0; i < stage->getRectCount(stage->getNowStage()); i++)
			{
				if (IntersectRect(&rtCrash, &stageRect[i], &playerRect)) { playerMove = false; }
				if (stage->getIsLieRect(i) && stageRect[i].top <= playerRect.top && stageRect[i].bottom >= playerRect.bottom)  { playerMove = true; }
			}
			for (int i = 0; i < 3; i++)
			{
				if (isLie[i]) { comparePlayerRect = Rect(playerLie[i]->pos.x, playerLie[i]->pos.y, playerLie[i]->pos.x + playerLie[i]->width, playerLie[i]->pos.y + playerLie[i]->height); }
				else { comparePlayerRect = Rect(player[i]->pos.x, player[i]->pos.y, player[i]->pos.x + player[i]->width, player[i]->pos.y + player[i]->height); }

				if (i != select && IntersectRect(&rtCrash, &comparePlayerRect, &playerRect)) { playerMove = false; }
			}
			if (isButton && stage->getNowStage() == 3)
			{
				for (int i = 0; i < stage->getfootholdRectCount(stage->getNowStage()); i++)
				{
					if (IntersectRect(&rtCrash, &stage->getFootholdRect(stage->getNowStage())[i], &playerRect))  { playerMove = false; }
				}
			}
			if (playerMove) { player[select]->pos.x += -200 * eTime / 3; playerLie[select]->pos.x += -200 * eTime / 3; }

		}
	}

	// 떨어질때
	for (int j = 0; j < 3; j++)
	{
		if (!isJumping[j])
		{
			for (int i = 0; i < 5; i++)
			{
				if (i == 2) { jump[j] += 1; }
				if (jump[j] >= 25)	{ jump[j] = 25; }
				speedY = (((jump[j] / 1.5) * (jump[j] / 1.5)) + 200) / 5;
				if (isLie[j])
				{
					playerRect = Rect(playerLie[j]->pos.x, playerLie[j]->pos.y + speedY * eTime ,
						playerLie[j]->pos.x + playerLie[j]->width, playerLie[j]->pos.y + playerLie[j]->height + speedY * eTime);
				}
				else
				{
					playerRect = Rect(player[j]->pos.x, player[j]->pos.y + speedY * eTime,
						player[j]->pos.x + player[j]->width, player[j]->pos.y + player[j]->height + speedY * eTime);
				}
				for (int i = 0; i < stage->getRectCount(stage->getNowStage()); i++)
				{
					 if (IntersectRect(&rtCrash, &stageRect[i], &playerRect)) { isFalling[j] = false;}
				}
				for (int i = 0; i < stage->getRectCount(stage->getNowStage()); i++)
				{
					if (stage->getIsLieRect(i) && IntersectRect(&rtCrash, &stageRect[i], &playerRect) && stageRect[i].top <= playerRect.top && stageRect[i].bottom >= playerRect.bottom) { isFalling[j] = true; }
				}
				if (isButton && stage->getNowStage() == 3)
				{
					for (int i = 0; i < stage->getfootholdRectCount(stage->getNowStage()); i++)
					{
						if (IntersectRect(&rtCrash, &stage->getFootholdRect(stage->getNowStage())[i], &playerRect))  { isFalling[j] = false; }
					}
				}
				for (int i = 0; i < 3; i++)
				{
					if (isLie[i]) { comparePlayerRect = Rect(playerLie[i]->pos.x, playerLie[i]->pos.y, playerLie[i]->pos.x + playerLie[i]->width, playerLie[i]->pos.y + playerLie[i]->height); }
					else { comparePlayerRect = Rect(player[i]->pos.x, player[i]->pos.y, player[i]->pos.x + player[i]->width, player[i]->pos.y + player[i]->height); }
					if (i != j && IntersectRect(&rtCrash, &comparePlayerRect, &playerRect)) { isFalling[j] = false;  jump[j] = 0; }
				}
				if (isFalling[j]) { player[j]->pos.y += speedY * eTime;  playerLie[j]->pos.y += speedY * eTime; }
				else { jump[j] = 0; }
			}
		}
		else if (isJumping[j]) { isFalling[j] = false; }
	}
	// 점프
	if ((MyKeyState(VK_SPACE) > 0 && !isJumping[select]) && !isFalling[select] && !isLie[select])
	{
		sound->Play(PLAYERUP_BGM);
	}
	if ((MyKeyState(VK_SPACE) > 0 || isJumping[select]) && !isFalling[select] && !isLie[select])
	{
		for (int i = 0; i < 3; i++)
		{
			isJumping[select] = true;
			if (i == 2) { jump[select] += 10; }
			speedY = -((((jumpMax[select] - jump[select]) / 2) * ((jumpMax[select] - jump[select]) / 2) + 300)) * eTime / 3;
			if (jump[select] >= jumpMax[select])
			{
				isJumping[select] = false;
				isFalling[select] = true;
				jump[select] = 0;
			}
			if (isLie[select]) {
				playerRect = Rect(playerLie[select]->pos.x, playerLie[select]->pos.y + speedY * eTime,
					playerLie[select]->pos.x + playerLie[select]->width, playerLie[select]->pos.y + playerLie[select]->height + speedY * eTime);
			}
			else
			{
				playerRect = Rect(player[select]->pos.x, player[select]->pos.y + speedY * eTime,
					player[select]->pos.x + player[select]->width, player[select]->pos.y + player[select]->height + speedY * eTime);
			}
			for (int i = 0; i < stage->getRectCount(stage->getNowStage()); i++)
			{
				if (IntersectRect(&rtCrash, &stageRect[i], &playerRect)) { isFalling[select] = true; isJumping[select] = false; jump[select] = 0; }
			}
			for (int i = 0; i < 3; i++)
			{
				if (isLie[i]) { comparePlayerRect = Rect(playerLie[i]->pos.x, playerLie[i]->pos.y, playerLie[i]->pos.x + playerLie[i]->width, playerLie[i]->pos.y + playerLie[i]->height); }
				else { comparePlayerRect = Rect(player[i]->pos.x, player[i]->pos.y, player[i]->pos.x + player[i]->width, player[i]->pos.y + player[i]->height); }
				if (i != select && IntersectRect(&rtCrash, &comparePlayerRect, &playerRect)) { isFalling[select] = true; isJumping[select] = false;  jump[select] = 0; }
			}
			if (isButton && stage->getNowStage() == 3)
			{
				for (int i = 0; i < stage->getfootholdRectCount(stage->getNowStage()); i++)
				{
					if (IntersectRect(&rtCrash, &stage->getFootholdRect(stage->getNowStage())[i], &playerRect))  { isFalling[select] = true; isJumping[select] = false; jump[select] = 0; }
				}
			}
			if (isJumping[select]) { player[select]->pos.y += speedY * eTime; playerLie[select]->pos.y += speedY * eTime; }
		}
	}

	

	for (int j = 0; j < 3; j++)
	{
		if (j != select && isJumping[j] && !isFalling[j])
		{
			for (int i = 0; i < 3; i++)
			{
				isJumping[j] = true;
				if (i == 2) { jump[j] += 10; }
				speedY = -((((jumpMax[j] - jump[j]) / 2) * ((jumpMax[j] - jump[j]) / 2) + 300)) * eTime / 3;
				if (jump[j] >= jumpMax[j])
				{
					isJumping[j] = false;
					isFalling[j] = true;
					jump[j] = 0;
				}
				player[j]->pos.y += speedY * eTime;  playerLie[j]->pos.y += speedY * eTime;
			}
		}
	}

	// 눕기 
	if (MyKeyState(VK_DOWN) == 1 && !isJumping[select] && !isFalling[select])
	{
		isLieSuccess = true;
		if (isLie[select])
		{
			playerRect = Rect(playerLie[select]->pos.x, playerLie[select]->pos.y - (player[select]->height - playerLie[select]->height), playerLie[select]->pos.x + player[select]->width, playerLie[select]->pos.y - (player[select]->height - playerLie[select]->height) + player[select]->height);
			for (int i = 0; i < stage->getRectCount(stage->getNowStage()); i++)
			{
				if (IntersectRect(&rtCrash, &stageRect[i], &playerRect)) {  isLieSuccess = false; }
			}
		}
		else
		{
			playerRect = Rect(player[select]->pos.x, player[select]->pos.y + (player[select]->height - playerLie[select]->height), player[select]->pos.x + playerLie[select]->width, player[select]->pos.y + (player[select]->height - playerLie[select]->height) + playerLie[select]->height);
			for (int i = 0; i < stage->getRectCount(stage->getNowStage()); i++)
			{
				if (IntersectRect(&rtCrash, &stageRect[i], &playerRect)) {  isLieSuccess = false; }
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (isLie[i]) { comparePlayerRect = Rect(playerLie[i]->pos.x, playerLie[i]->pos.y, playerLie[i]->pos.x + playerLie[i]->width, playerLie[i]->pos.y + playerLie[i]->height); }
			else { comparePlayerRect = Rect(player[i]->pos.x, player[i]->pos.y, player[i]->pos.x + player[i]->width, player[i]->pos.y + player[i]->height); }

			if (i != select && IntersectRect(&rtCrash, &comparePlayerRect, &playerRect)) { isLieSuccess = false; }
		}

		if (isLieSuccess)
		{
			sound->Play(PLAYERDOWN_BGM);
			if (isLie[select]) { player[select]->pos = D3DXVECTOR2(playerLie[select]->pos.x, playerLie[select]->pos.y - (player[select]->height - playerLie[select]->height)); }
			else { playerLie[select]->pos = D3DXVECTOR2(player[select]->pos.x, player[select]->pos.y + (player[select]->height - playerLie[select]->height)); }
			isLie[select] = !isLie[select];
		}
	}

	//버튼
	for (int i = 0; i < stage->getButtonRectCount(stage->getNowStage()); i++)
	{
		if (isLie[select]) { playerRect = Rect(playerLie[select]->pos.x, playerLie[select]->pos.y, playerLie[select]->pos.x + playerLie[select]->width, playerLie[select]->pos.y + playerLie[select]->height); }
		else  { playerRect = Rect(player[select]->pos.x, player[select]->pos.y, player[select]->pos.x + player[select]->width, player[select]->pos.y + player[select]->height); }

		if (IntersectRect(&rtCrash, &stage->getButtonRect(stage->getNowStage())[i], &playerRect))
		{
			if (stage->getNowStage() == 3)
			{
				isButton = true; stage->isButton = true;
				for (int j = 0; j < 3; j++)
				{
					if (isLie[j]) { playerRect = Rect(playerLie[j]->pos.x, playerLie[j]->pos.y, playerLie[j]->pos.x + playerLie[j]->width, playerLie[j]->pos.y + playerLie[j]->height); }
					else  { playerRect = Rect(player[j]->pos.x, player[j]->pos.y, player[j]->pos.x + player[j]->width, player[j]->pos.y + player[j]->height); }

					for (int i = 0; i < stage->getfootholdRectCount(stage->getNowStage()); i++)
					{
						if (IntersectRect(&rtCrash, &stage->getFootholdRect(stage->getNowStage())[i], &playerRect))  { isButton = false;  stage->isButton = false; }
					}
				}
			}
			else if (stage->getNowStage() == 5 && i == 0)
			{
				stage->isStage6Button = true;
			}
			else if (stage->getNowStage() == 5 && i == 1)
			{
				for (int j = 0; j < 2; j++)
				{
					isButton = true;
					stage->isButton = true;
				}
			}
		}
	}
	
	if (stage->isStage6Button)
	{
		for (int j = 0; j < 2; j++)
		{
			stage->hippo[j]->moving(stage->getHippoPos(j + 4)[0] + 5, stage->getHippoPos(j + 4)[1], eTime);
		}
	}

	stage->isStage7Button[0] = false;
	stage->isStage7Button[1] = false;
	stage->isStage7Button[2] = false;
	if (stage->getNowStage() == 6)
	{
		for (int i = 0; i < stage->getButtonRectCount(stage->getNowStage()); i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (isLie[j]) { playerRect = Rect(playerLie[j]->pos.x, playerLie[j]->pos.y, playerLie[j]->pos.x + playerLie[j]->width, playerLie[j]->pos.y + playerLie[j]->height); }
				else  { playerRect = Rect(player[j]->pos.x, player[j]->pos.y, player[j]->pos.x + player[j]->width, player[j]->pos.y + player[j]->height); }

				if (IntersectRect(&rtCrash, &stage->getButtonRect(stage->getNowStage())[i], &playerRect))
				{
					stage->isStage7Button[i] = true;
				}
			}
		}
	}

	
	isUp = false;
	if (isButton && stage->getNowStage() == 5)
	{
		for (int j = 0; j < 3; j++)
		{
			if (isLie[j]) { playerRect = Rect(playerLie[j]->pos.x, playerLie[j]->pos.y + 50 * eTime, playerLie[j]->pos.x + playerLie[j]->width, playerLie[j]->pos.y + playerLie[j]->height + 50 * eTime); }
			else  { playerRect = Rect(player[j]->pos.x, player[j]->pos.y + 50 * eTime, player[j]->pos.x + player[j]->width, player[j]->pos.y + player[j]->height + 50 * eTime); }

			if (IntersectRect(&rtCrash, &stage->getStageRect(stage->getNowStage())[4], &playerRect) 
				&& stage->getStageRect(stage->getNowStage())[4].left < playerRect.left && stage->getStageRect(stage->getNowStage())[4].right > playerRect.right
				&& stage->getStageRect(stage->getNowStage())[4].left < playerRect.right && stage->getStageRect(stage->getNowStage())[4].right > playerRect.right)
			{
				player[j]->pos.y += -100 * eTime; playerLie[j]->pos.y += -100 * eTime;
				isUp = true;
			}
			if (isUp)
			{
				if (isLie[j]) { playerRect = Rect(playerLie[j]->pos.x, playerLie[j]->pos.y - 100 * eTime, playerLie[j]->pos.x + playerLie[j]->width, playerLie[j]->pos.y + playerLie[j]->height - 100 * eTime); }
				else  { playerRect = Rect(player[j]->pos.x, player[j]->pos.y - 100 * eTime, player[j]->pos.x + player[j]->width, player[j]->pos.y + player[j]->height - 100 * eTime); }

				for (int i = 0; i < 3; i++)
				{
					if (isLie[i]) { comparePlayerRect = Rect(playerLie[i]->pos.x, playerLie[i]->pos.y + 50 * eTime, playerLie[i]->pos.x + playerLie[i]->width, playerLie[i]->pos.y + playerLie[i]->height + 50 * eTime); }
					else { comparePlayerRect = Rect(player[i]->pos.x, player[i]->pos.y + 50 * eTime, player[i]->pos.x + player[i]->width, player[i]->pos.y + player[i]->height + 50 * eTime); }

					if (i != j && IntersectRect(&rtCrash, &comparePlayerRect, &playerRect)) { player[i]->pos.y += -100 * eTime; playerLie[i]->pos.y += -100 * eTime; }
				}
			}
		}

		stage->Moving(eTime);
		
	}


	// 물
	stage->isWaterIn = false;
	for (int i = 0; i < stage->getWaterRectCount(stage->getNowStage()); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (isLie[j]) { playerRect = Rect(playerLie[j]->pos.x, playerLie[j]->pos.y, playerLie[j]->pos.x + playerLie[j]->width, playerLie[j]->pos.y + playerLie[j]->height); }
			else  { playerRect = Rect(player[j]->pos.x, player[j]->pos.y, player[j]->pos.x + player[j]->width, player[j]->pos.y + player[j]->height); }
			
			if (IntersectRect(&rtCrash, &stage->getWaterRect(stage->getNowStage())[i], &playerRect)) { stage->isWaterIn = true; }
			if (IntersectRect(&rtCrash, &stage->getWaterRect(stage->getNowStage())[i], &playerRect)
				&& stage->getWaterRect(stage->getNowStage())[i].top <= playerRect.top && stage->getWaterRect(stage->getNowStage())[i].bottom >= playerRect.bottom)
			{
				//setting();
				sound->Stop(BOSS_BGM);
				sound->Stop(INGAME_BGM);
				sound->Play(DEAD_BGM);
				state = GameOver;
			}
		}
	}

	// HIPPO
	for (int i = 0; i < 2; i++)
	{
		if (stage->getNowStage() == stage->getHippoStage(i))
		{
			if (isLie[select]) { playerRect = Rect(playerLie[select]->pos.x, playerLie[select]->pos.y, playerLie[select]->pos.x + playerLie[select]->width, playerLie[select]->pos.y + playerLie[select]->height); }
			else  { playerRect = Rect(player[select]->pos.x, player[select]->pos.y, player[select]->pos.x + player[select]->width, player[select]->pos.y + player[select]->height); }

			for (int j = 0; j < stage->getHippoCount(i); j++)
			{
				blockRect = Rect(stage->hippo[j]->getPosX() + 15, stage->hippo[j]->getPosY() + 5,
					stage->hippo[j]->getPosX() + stage->hippo[j]->getWidth() - 15, stage->hippo[j]->getPosY() + stage->hippo[j]->getHeight() - 5);
				if (IntersectRect(&rtCrash, &blockRect, &playerRect))
				{
					//setting();
					sound->Stop(BOSS_BGM);
					sound->Stop(INGAME_BGM);
					sound->Play(DEAD_BGM);
					state = GameOver;
				}
			}
		}
	}

	// 클리어 위치
	isClear = true;
	for (int i = 0; i < 3; i++)
	{
		if (isLie[i]) {
			playerRect = Rect(playerLie[i]->pos.x, playerLie[i]->pos.y,
				playerLie[i]->pos.x + playerLie[i]->width, playerLie[i]->pos.y + playerLie[i]->height);
		}
		else
		{
			playerRect = Rect(player[i]->pos.x, player[i]->pos.y,
				player[i]->pos.x + player[i]->width, player[i]->pos.y + player[i]->height);
		}
		if (!IntersectRect(&rtCrash, &stage->getCelarStageRect(stage->getNowStage()), &playerRect) || isJumping[i] || isFalling[i]) { isClear = false; }
	}
	if (isClear) { 
		sound->Stop(BOSS_BGM);
		sound->Stop(INGAME_BGM);
		sound->Play(CLEAR_BGM);
		state = Clear;
		//setting();
	}

	for (int i = 0; i<3; i++)
	{
		pAni[i]->pos.x = player[i]->pos.x; pAni[i]->pos.y = player[i]->pos.y;
		pLieAni[i]->pos.x = playerLie[i]->pos.x; pLieAni[i]->pos.y = playerLie[i]->pos.y;
	}

	if (MyKeyState(VK_TAB) == 1) { stage->setNowStage(stage->getNowStage() + 1); }
}

void Player::Render(D3DXMATRIX *pmat) {
	IObject::Render(pmat);
	if (MyKeyState(VK_LEFT) > 0) { player[select]->scale.x = 1; pAni[select]->scale.x = 1, playerLie[select]->scale.x = 1; pLieAni[select]->scale.x = 1; }
	if (MyKeyState(VK_RIGHT) > 0) { player[select]->scale.x = -1; pAni[select]->scale.x = -1, playerLie[select]->scale.x = -1; pLieAni[select]->scale.x = -1; }

	if (isLie[0] == false) { if ((MyKeyState(VK_LEFT) > 0 || MyKeyState(VK_RIGHT) > 0) && select == 0) { pAni[0]->Render(&this->mat); } else { player[0]->Render(&this->mat); } }
	else { if ((MyKeyState(VK_LEFT) > 0 || MyKeyState(VK_RIGHT) > 0) && select == 0) { pLieAni[0]->Render(&this->mat); } else { playerLie[0]->Render(&this->mat); } }
	if (isLie[1] == false) { if ((MyKeyState(VK_LEFT) > 0 || MyKeyState(VK_RIGHT) > 0) && select == 1) { pAni[1]->Render(&this->mat); } else { player[1]->Render(&this->mat); } }
	else { if ((MyKeyState(VK_LEFT) > 0 || MyKeyState(VK_RIGHT) > 0) && select == 1) { pLieAni[1]->Render(&this->mat); } else { playerLie[1]->Render(&this->mat); } }
	if (isLie[2] == false) { if ((MyKeyState(VK_LEFT) > 0 || MyKeyState(VK_RIGHT) > 0) && select == 2) { pAni[2]->Render(&this->mat); } else { player[2]->Render(&this->mat); } }
	else { if ((MyKeyState(VK_LEFT) > 0 || MyKeyState(VK_RIGHT) > 0) && select == 2) { pLieAni[2]->Render(&this->mat); } else { playerLie[2]->Render(&this->mat); }; }
}

void Player::setting()
{

	player[0]->pos.x = stage->getFatherPos(stage->getNowStage())[0];
	player[0]->pos.y = stage->getFatherPos(stage->getNowStage())[1] - player[0]->height - 10;
	player[1]->pos.x = stage->getMotherPos(stage->getNowStage())[0];
	player[1]->pos.y = stage->getMotherPos(stage->getNowStage())[1] - player[1]->height - 10;
	player[2]->pos.x = stage->getChildPos(stage->getNowStage())[0];
	player[2]->pos.y = stage->getChildPos(stage->getNowStage())[1] - player[2]->height - 10;

	playerMove = false;
	isJumping[0] = isJumping[1] = isJumping[2] = isFalling[0] = isFalling[1] = isFalling[2] = false;
	fallCount = 0;
	time = 0;
	jump[0] = jump[1] = jump[2] = 0;
	jumpMax[0] = 300; jumpMax[1] = 360; jumpMax[2] = 335;
	select = 0;
	choiceCount = 0;
	stageRect = stage->getStageRect(stage->getNowStage());
	isLie[0] = false; isLie[1] = false; isLie[2] = false;
	isButton = false;
	stage->isStage6Button = false;
	for (int i = 0; i < 2; i++)
	{
		if (stage->getNowStage() == stage->getHippoStage(i))
		{
			for (int j = 0; j < stage->getHippoCount(i); j++)
			{
				stage->hippo[j]->setPos(stage->getHippoPos(j + i * 2)[0], stage->getHippoPos(j + i * 2)[1]);
			}
		}
	}

	if (stage->getNowStage() == 5) { stage->setStageRect(stage->getFootholdRect(5)[0]); }
	if (stage->getNowStage() == 6) { stage->setStageRect(stage->getFootholdRect(6)[0]); }
	stage->isButton = false;
	stage->isWaterIn = false;
	stage->isStage7Button[0] = stage->isStage7Button[1] = stage->isStage7Button[2] = false;
	stage->clear = false;
}