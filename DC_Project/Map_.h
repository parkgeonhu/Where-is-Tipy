#pragma once
#include "Laon.h"
#include "CAnimation.h"
#include "Map.h"
class Map;

class Map_ : public IObject
{
public:
	Map_(int mapcount, int random, int check, double rect_x, double rect_y);
	~Map_();
	CSprite *Sprite;
	float speed;
	bool isErase;

	RECT rect;
	Map *map;
	//Laon *laon;

	int strength;

	int PY;

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);
};