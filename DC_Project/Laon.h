#pragma once
#include "CAnimation.h"

class Laon:public IObject {
public:
	Laon();
	~Laon();

	int x, y;
	 
	CSprite *square2;
	CAnimation *pAni;

	RECT rect1, rect2, rect3, rect4;

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);
};