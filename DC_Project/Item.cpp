#include "Item.h"
#include "def.h"
#include "myFunction.h"

Item::Item(Laon *laon)
{
	ax = new CSprite("image/ax.jpg");
	this->laon = laon;
	check = false;
	scale = D3DXVECTOR2(0.4, 0.6);
}

Item::~Item()
{
	delete ax;
}

void Item::Update(float eTime)
{
	pos.y = laon->square2->pos.y + 15;
	pos.x = laon->square2->pos.x + 10;

	if (MyKeyState('S') == 1) pos.y = laon->square2->pos.y + 40, check = true;
	else if (MyKeyState('W') == 1) pos.y = laon->square2->pos.y - 25, check = true;
	else if (MyKeyState('A') == 1) pos.x = laon->square2->pos.x - 15, check = true;
	else if (MyKeyState('D') == 1) pos.x = laon->square2->pos.x + 40, check = true;

	rect_item = Rect(pos.x, pos.y, pos.x + 20, pos.y + 30);
}

void Item::Render(D3DXMATRIX *pmat)
{
	IObject::Render(pmat);
	ax->Render(&this->mat);
}