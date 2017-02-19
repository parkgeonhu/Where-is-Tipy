#include "CGameScene.h"
#include "Def.h"
#include "Hippo.h"

extern CSprite *g_map;

Hippo::Hippo()
{
	hippo = new CSprite("image/Hippo/Hippo1.png");
	isJumping = false;
	movingPosY = time = 0;
}

Hippo::~Hippo()
{
	delete hippo;
}

void Hippo::Update(float eTime)
{
	time++;
	jumpTime += eTime;

	if (time > 128 * 2)
	{
		isJumping = true;
		time = 0;
	}
	if (isJumping)
	{
		hippo->pos.y += movingPosY;
		movingPosY = sin(jumpTime * 2) * 100;
		hippo->pos.y -= movingPosY;
		if (hippo->pos.y > posY) { isJumping = false; }
	}
	else
	{
		jumpTime = 0;
	}
}

void Hippo::Render(D3DXMATRIX *pmat) {
	IObject::Render(pmat);
	hippo->Render(&this->mat);
}

void Hippo::setPos(double posX, double posY)
{
	posX -= 5; posY -= 5;
	hippo->pos.x = posX;
	hippo->pos.y = posY;
	this->posY = posY;
	isJumping = false;
	movingPosY = time = 0;
}

void Hippo::moving(double posX, double posY, float eTime)
{
	if (hippo->pos.x < posX) { hippo->pos.x += 30 * eTime; }
	if (hippo->pos.y < posY) { hippo->pos.y += 30 * eTime; }

}