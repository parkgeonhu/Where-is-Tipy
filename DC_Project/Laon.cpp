#include "Laon.h"
#include "CGameScene.h"
#include "myFunction.h"
#include "Def.h"

extern HWND g_hWnd;
extern CSprite *g_bg;
extern CSprite *g_map;

Laon::Laon() {
	square2 = new CSprite("image/Walking/1.png");
	square2->pos.x = 380;
	square2->pos.y = 300;

	pAni = new CAnimation(2, 7.0f);
	pAni->PushFrame("image/Walking/2.png", 0);
	pAni->PushFrame("image/Walking/3.png", 1);
	pAni->pos.x = 380;
	pAni->pos.y = 300;
	
	rect1 = Rect(square2->pos.x, square2->pos.y, square2->pos.x + MAX_x, square2->pos.y + MAX_y);

	rect2 = Rect(square2->pos.x + 10, square2->pos.y - 30 , square2->pos.x + MAX_x - 10, square2->pos.y + MAX_y - 30);
	rect3 = Rect(square2->pos.x, square2->pos.y + 20, square2->pos.x + MAX_x, square2->pos.y + MAX_y - 20);
	rect4 = Rect(square2->pos.x + 10, square2->pos.y + 30, square2->pos.x + MAX_x - 10, square2->pos.y + MAX_y + 30);

	pAni->scalingCenter = square2->GetCenter();
	square2->scalingCenter = square2->GetCenter();
}
Laon::~Laon() {
	delete square2;
	delete pAni;
}
void Laon::Update(float eTime) {
	pAni->Update(eTime);

	square2->Update(eTime);
}
void Laon::Render(D3DXMATRIX *pmat) {
	IObject::Render(pmat);
	if (MyKeyState(VK_LEFT) > 0 || MyKeyState(VK_RIGHT) > 0)
	{
		if (MyKeyState(VK_RIGHT) > 0) pAni->scale = D3DXVECTOR2(1, 1), square2->scale = D3DXVECTOR2(1,1);
		else pAni->scale = D3DXVECTOR2(-1, 1), square2->scale = D3DXVECTOR2(-1, 1);

		pAni->Render(&this->mat);
	}
	else square2->Render(&this->mat);
}