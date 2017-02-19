#pragma once
#include "CAnimation.h"
#include "myFunction.h"

class Hippo : public IObject{
private:
	CSprite *hippo;
	CSprite *kinghippo;

	int time;
	double jumpTime, posX, posY, movingPosY;
	bool isJumping;

public:
	CAnimation *sleepAni[3];

	Hippo();
	~Hippo();

	double getPosX() { return hippo->pos.x; }
	double getPosY() { return hippo->pos.y; }
	double getWidth() { return hippo->width; }
	double getHeight() { return hippo->height; }

	void setPos(double posX, double posY);
	void moving(double posX, double posY, float eTime);

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);


};