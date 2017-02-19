#pragma once
#include "CAnimation.h"
#include "Laon.h"

class Block :public IObject {
public:
	Block(Laon *laon);
	~Block();

	int x, y, check, block_check;

	RECT rect, rect_check;

	Laon *laon;

	CSprite *block;

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);
};