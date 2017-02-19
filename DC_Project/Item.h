#pragma once
#include "CAnimation.h"
#include "Laon.h"

class Item :public IObject {
public:
	Item(Laon *laon);
	~Item();

	int x, y, check;

	Laon *laon;

	RECT rect_item;

	CSprite *ax;

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);
};