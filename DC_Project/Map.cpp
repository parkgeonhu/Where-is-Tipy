#include "Map.h"
#include "MyFunction.h"
#include "Def.h"
#include "CGameScene.h"
#include "time.h"

RECT tempRect;

float GetDistanceSquare(D3DXVECTOR2 v1, D3DXVECTOR2 v2);

Map::Map(Laon *laon, Item *item, Block *block)
{
	srand((unsigned)time(NULL));

	this->laon = laon;
	this->item = item;
	this->block = block;

	laonCopy = Rect(laon->rect1.left, laon->rect1.top, laon->rect1.right, laon->rect1.bottom);
	
	square = new CSprite("image/square2.png");


	mapcount = 0;
	y = 300;
	jumping = false;
	ax_on = block_on = -1;

	for (; mapcount < 1000 * 1000; mapcount++) {
		random = rand() % 100 + 1;

		PushMap(new Map_(mapcount, random, false, false, false));
	}
}

Map::~Map()
{
	MAPLIST::iterator iter;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			for (iter = mapList[i][j].begin(); iter != mapList[i][j].end(); iter++)
				delete (*iter);
		}
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			mapList[i][j].clear();
		}
	}
}

void Map::PushMap(Map_ *p)
{
	mapList[(mapcount/10000)][(mapcount%1000)/10].push_back(p);
}

void Map::Update(float eTime)
{
	x = y = MapMove = check_x = check_y = check_up = check_down = block_new = false;
	block_cancel = true;
	
	//callMap[i][0] : 세로, callMap[i][1] : 가로
	callMap[0][0] = (laonCopy.top - 301 - 400) / 700, callMap[0][1] = (laonCopy.left - 400) / 700;																	   
	callMap[1][0] = (laonCopy.top - 301 - 400) / 700, callMap[1][1] = (laonCopy.left) / 700;
	callMap[2][0] = (laonCopy.top - 301 - 400) / 700, callMap[2][1] = (laonCopy.left + 400) / 700;
	callMap[3][0] = (laonCopy.top - 301 + 400) / 700, callMap[3][1] = (laonCopy.left - 400) / 700;
	callMap[4][0] = (laonCopy.top - 301 + 400) / 700, callMap[4][1] = (laonCopy.left) / 700;
	callMap[5][0] = (laonCopy.top - 301 + 400) / 700, callMap[5][1] = (laonCopy.left + 400) / 700;

	for (int i = 0; i < 6; i ++)
	{
		if (callMap[i][1] < 0) callMap[i][1] = 99;
		if (callMap[i][1] > 99) callMap[i][1] = 0;

		if (callMap[i][0] < 0) callMap[i][0] = 1;
	}

	if ((MyKeyState('Q') == 1))
	{
		ax_on = -ax_on;
		block_on = -1;
		if (ax_on == 1) item = new Item(laon);
		if (ax_on == -1) delete item;
	}
	if (ax_on == 1) item->Update(eTime);

	if ((MyKeyState('E') == 1))
	{
		block_on = -block_on;
		ax_on = -1;
		if (block_on == 1) block = new Block(laon);
		if (block_on == -1) delete block;
	}
	if (block_on == 1) block->Update(eTime);


	/*if ((MyKeyState(VK_UP) == 1) && jumping == false) jumping = true, jump_y = laonCopy.top;
	if (jumping)
	{
		y = -300;
		if (jump_y - 100 > laonCopy.top) y = 300, jumping = false;
	}
	else y = 300;*/

	if (MyKeyState(VK_LEFT) > 0) x = -300;
	if (MyKeyState(VK_RIGHT) > 0) x = 300;
	if (MyKeyState(VK_UP) > 0) y = -300;
	if (MyKeyState(VK_DOWN) > 0) y = 300;

	laonCopy.left += x * eTime;
	laonCopy.top += y * eTime;

	MAPLIST::iterator iter;

	for (int i = 0; i < 6; i++)
	{
		for (iter = mapList[callMap[i][0]][callMap[i][1]].begin(); iter != mapList[callMap[i][0]][callMap[i][1]].end(); iter++)
		{
			(*iter)->Update(eTime);
			(*iter)->pos.x = (rect.left) - ((*iter)->pos.x - laon->rect1.left);
			(*iter)->pos.y = (rect.top) - ((*iter)->pos.y - laon->rect1.top);
		}
	}
	
	for (int i = 0; i < 6; i++)
	{
		for (iter = mapList[callMap[i][0]][callMap[i][1]].begin(); iter != mapList[callMap[i][0]][callMap[i][1]].end(); iter++)
		{
			(*iter)->Update(eTime);

			rect = Rect((*iter)->pos.x, (*iter)->pos.y, (*iter)->pos.x + BLOCKMAX, (*iter)->pos.y + BLOCKMAX);
			
			if (IntersectRect(&tempRect, &laonCopy, &rect))
			{
				MapMove = true;

				if (y == -300 && laonCopy.top > (*iter)->pos.y + 60){
					check_y = 1;
				}
				else if (y == 300 && laonCopy.bottom < (*iter)->pos.y + 10){
					check_y = 2;
				}
				else if (x == 300 && laonCopy.right < (*iter)->pos.x + 10){
					check_x = 1;
				}
				else if (x == -300 && laonCopy.left > (*iter)->pos.x + 60){
					check_x = 2;
				}
			}
			if (IntersectRect(&tempRect, &laon->rect3, &rect))
				check_down = true, check_up = true;
		}
	}

	/*if (MapMove)
	{
		x = y = 0;
		if (check_y == 1 && check_up == false) y = 300, jump_y += 100;
		if (check_y == 2 && check_down == false) y = -300, jumping = false;
		if (check_x == 1) x = -300;
		if (check_x == 2) x = 300;

		laonCopy.left += x * eTime;
		laonCopy.top += y * eTime;
	}*/

	for (int i = 0; i < 6; i++)
	{
		for (iter = mapList[callMap[i][0]][callMap[i][1]].begin(); iter != mapList[callMap[i][0]][callMap[i][1]].end(); iter++)
		{
			(*iter)->Update(eTime);
			(*iter)->pos.x = (laon->rect1.left) - ((*iter)->pos.x - rect.left);
			(*iter)->pos.y = (laon->rect1.top) - ((*iter)->pos.y - rect.top);
		}
	}

	/*for (int i = 0; i < 6; i++)
	{
		for (iter = mapList[callMap[i][0]][callMap[i][1]].begin(); iter != mapList[callMap[i][0]][callMap[i][1]].end(); iter++)
		{
			rect = Rect((*iter)->pos.x, (*iter)->pos.y, (*iter)->pos.x + BLOCKMAX, (*iter)->pos.y + BLOCKMAX);

			if (IntersectRect(&tempRect, &laon->rect4, &rect) && (check_down == true))
				check_down = false;
			if (IntersectRect(&tempRect, &laon->rect2, &rect) && (check_up == true))
				check_up = false;

			if (ax_on == 1)
			{
				if (IntersectRect(&tempRect, &item->rect_item, &rect))
				{
					if (item->check)
					{
						(*iter)->strength--;
						item->check = false;
						if ((*iter)->strength == 0)
						{
							delete (*iter);
							iter = mapList[callMap[i][0]][callMap[i][1]].erase(iter);
						}
					}
				}
			}

			if (block_on == 1)
			{
				if (IntersectRect(&tempRect, &block->rect, &rect))
				{
					if (block->check != false)
					{
						block_x = (*iter)->pos.x, block_y = (*iter)->pos.y;
						block_new = true;
					}
				}

				if (IntersectRect(&tempRect, &block->rect_check, &rect))
				{
					block_cancel = false;
				}
			}
		}
	}

	if (block_new == true && block_cancel == true)
	{
		PushMap(new Map_(false, block->block_check, block->check, block_x, block_y)), block->check = false;;
	}*/

	square->pos.x = laonCopy.left;
	square->pos.y = laonCopy.top;

}

void Map::Render(D3DXMATRIX *pmat)
{
	IObject::Render(pmat);
	MAPLIST::iterator iter;
	for (int i = 0; i < 6; i++)
	{
		for (iter = mapList[callMap[i][0]][callMap[i][1]].begin(); iter != mapList[callMap[i][0]][callMap[i][1]].end(); iter++)
		{
			(*iter)->Render(&this->mat);
		}
	}
	if (ax_on == 1) item->Render(&this->mat);
	if (block_on == 1) block->Render(&this->mat);
	square->Render(&this->mat);

}

float GetDistanceSquare(D3DXVECTOR2 v1, D3DXVECTOR2 v2)
{
	D3DXVECTOR2 d = v1 - v2;
	return d.x*d.x + d.y*d.y;
}