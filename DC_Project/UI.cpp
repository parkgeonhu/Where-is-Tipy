#include "CGameScene.h"
#include "Def.h"
#include "UI.h"

UI::UI(){
	//스크린
	gameover = new CSprite("image/UI/gameover.png");
	stop = new CSprite("image/UI/stop.png");
	clear = new CSprite("image/UI/clear.png");

	//버튼
	gamestopBtn = new CSprite("image/UI/game_stop.png");
	fail_main = new CSprite("image/UI/fail_main.png");
	fail_restart = new CSprite("image/UI/fail_restart.png");
	stop_main = new CSprite("image/UI/stop_main.png");
	stop_restart = new CSprite("image/UI/stop_restart.png");
	stop_resume = new CSprite("image/UI/stop_resume.png");
	clear_restart = new CSprite("image/UI/clear_restart.png");
	clear_main = new CSprite("image/UI/clear_main.png");
	clear_next = new CSprite("image/UI/clear_next.png");

	select_1 = new CSprite("image/UI/select_1.png");
	select_2 = new CSprite("image/UI/select_2.png");
	select_3 = new CSprite("image/UI/select_3.png");

	//로딩
	loading = new CSprite("image/UI/loading.png");

	//메뉴
	menuBackGround = new CSprite("image/UI/menu_Back.png");

	//help
	help1 = new CSprite("image/HELP/1.png");
	help2 = new CSprite("image/HELP/2.png");
	help3 = new CSprite("image/HELP/3.png");
	help4 = new CSprite("image/HELP/4.png");

	//별
	for (int i = 0; i < 7; i++){
		menu_star[i][0] = new CSprite("image/UI/menu_star0.png");
		menu_star[i][1] = new CSprite("image/UI/menu_star1.png");
		menu_star[i][2] = new CSprite("image/UI/menu_star2.png");
		menu_star[i][3] = new CSprite("image/UI/menu_star3.png");
	}
	
	clear_star[0] = new CSprite("image/UI/clear_star0.png");
	clear_star[1] = new CSprite("image/UI/clear_star1.png");
	clear_star[2] = new CSprite("image/UI/clear_star2.png");
	clear_star[3] = new CSprite("image/UI/clear_star3.png");

	stopRect[0] = Rect(236, 296, 411, 372);
	stopRect[1] = Rect(437, 297, 571, 372);
	stopRect[2] = Rect(597, 296, 772, 372);

	gameoverRect[0] = Rect(220, 268, 501, 388);
	gameoverRect[1] = Rect(559, 268, 779, 388);

	clearRect[0] = Rect(258, 446, 427, 522);
	clearRect[1] = Rect(453, 446, 587, 522);
	clearRect[2] = Rect(620, 446, 789, 522);

	//메뉴 rect
	menuRect[0] = Rect(56, 590, 106, 648);
	menuRect[1] = Rect(190, 590, 240, 648);
	menuRect[2] = Rect(370, 590, 420, 648);
	menuRect[3] = Rect(512, 590, 562, 648);
	menuRect[4] = Rect(669, 590, 719, 648);
	menuRect[5] = Rect(774, 590, 824, 648);
	menuRect[6] = Rect(920, 544, 1009, 648);

	ComponentSetPos();
}

UI::~UI(){
}

void UI::Update(float eTime){
}

void UI::Render(D3DXMATRIX *pmat){

}

void UI::ComponentSetPos(){
	//스크린

	//버튼
	gamestopBtn->pos.x = 30;
	gamestopBtn->pos.y = 30;

	fail_restart->pos.x = 220;
	fail_restart->pos.y = 268;
	fail_main->pos.x = 559;
	fail_main->pos.y = 268;

	stop_restart->pos.x = 236;
	stop_restart->pos.y = 296;

	stop_main->pos.x = 437;
	stop_main->pos.y = 296;

	stop_resume->pos.x = 597;
	stop_resume->pos.y = 296;

	clear_restart->pos.x = 258;
	clear_restart->pos.y = 446;

	clear_main->pos.x = 453;
	clear_main->pos.y = 446;

	clear_next->pos.x = 620;
	clear_next->pos.y = 446;

	for (int i = 0; i < 4; i++){
		menu_star[0][i]->pos.x = 50 - 115;
		menu_star[0][i]->pos.y = 380 - 70;
	}
	for (int i = 0; i < 4; i++){
		menu_star[1][i]->pos.x = 184 - 115;
		menu_star[1][i]->pos.y = 380 - 70;
	}
	for (int i = 0; i < 4; i++){
		menu_star[2][i]->pos.x = 364 - 115;
		menu_star[2][i]->pos.y = 380 - 70;
	}
	for (int i = 0; i < 4; i++){
		menu_star[3][i]->pos.x = 506 - 115;
		menu_star[3][i]->pos.y = 380 - 70;
	}
	for (int i = 0; i < 4; i++){
		menu_star[4][i]->pos.x = 663 - 115;
		menu_star[4][i]->pos.y = 380 - 70;
	}
	for (int i = 0; i < 4; i++){
		menu_star[5][i]->pos.x = 768 - 115;
		menu_star[5][i]->pos.y = 380 - 70;
	}
	for (int i = 0; i < 4; i++){
		menu_star[6][i]->pos.x = 934 - 115;
		menu_star[6][i]->pos.y = 380 - 70;
	}

	select_1 ->pos.x= 1024-300-30;
	select_1->pos.y = 30;
	select_2 ->pos.x= 1024-300-30;
	select_2->pos.y = 30;
	select_3 ->pos.x=1024-300-30;
	select_3->pos.y = 30;
}