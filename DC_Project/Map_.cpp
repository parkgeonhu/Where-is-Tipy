#include "Map_.h"
#include "def.h"
#include "myFunction.h"
#include "stdlib.h"
#include "time.h"


Map_::Map_(int mapcount, int random, int check, double rect_x, double rect_y)
{
	if (check == false)
	{
		if (random < 85)
		{
			Sprite = new CSprite("image/square1.png");
			strength = 1;
		}
		else if (random > 85 && random < 95)
		{
			Sprite = new CSprite("image/sand.png");
			strength = 2;
		}
		else
		{
			Sprite = new CSprite("image/soil.png");
			strength = 3;
		}
		pos.y = 500 + (mapcount / 1000) * BLOCKMAX;
		pos.x = (mapcount % 1000) * BLOCKMAX;
		scale = D3DXVECTOR2(0.7, 0.7);
		rect = Rect(pos.x, pos.y, pos.x + BLOCKMAX, pos.y + BLOCKMAX);
	}
	else
	{
		if (random == 1) Sprite = new CSprite("image/square1.png"), strength = 1;
		else if (random == 2) Sprite = new CSprite("image/sand.png"), strength = 2;
		else if (random == 3) Sprite = new CSprite("image/soil.png"), strength = 3;

		
		if (check == 1) pos.y = (rect_y) - 70, pos.x = (rect_x) ;
		else if (check == 2) pos.y = (rect_y) + 70, pos.x = (rect_x) ;
		else if (check == 3) pos.y = (rect_y), pos.x = (rect_x) + 70 ;
		else if (check == 4) pos.y = (rect_y), pos.x = (rect_x) - 70;

		scale = D3DXVECTOR2(0.7, 0.7);
		rect = Rect(pos.x, pos.y, pos.x + BLOCKMAX, pos.y + BLOCKMAX);
	}
}

Map_::~Map_()
{
	delete Sprite;
}

void Map_::Update(float eTime)
{
	Sprite->Update(eTime);
}

void Map_::Render(D3DXMATRIX *pmat)
{
	IObject::Render(pmat);
	Sprite->Render(&this->mat);
}