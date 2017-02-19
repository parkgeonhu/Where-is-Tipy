#pragma once
#include "CAnimation.h"
#include "Map_.h"
#include "Laon.h"
#include "Item.h"
#include "Block.h"
#include <list>

class Map_;

using namespace std;
typedef list<Map_*> MAPLIST;

class Map :public IObject
{
public:
	Map(Laon *laon, Item *item, Block *block);
	~Map();

	CSprite *square;
	Laon *laon;
	Item *item;
	Block *block;
	MAPLIST mapList[100][100];
	RECT rect, laonCopy;

	int random, ax_on;
	int mapcount, x, y, callMap[6][2];
	int check_x, check_y, MapMove, check_up, check_down;
	int jumping;
	int block_on, block_new, block_cancel;
	double block_x, block_y, jump_y;

	void PushMap(Map_ *p);
	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);
};