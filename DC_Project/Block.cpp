#include "Block.h"
#include "def.h"
#include "myFunction.h"

Block::Block(Laon *laon)
{
	block = new CSprite("image/back.png");
	this->laon = laon;
	check = block_check = false;
	scale = D3DXVECTOR2(0.2, 0.3);
}

Block::~Block()
{
	delete block;
}

void Block::Update(float eTime)
{
	if (MyKeyState('1') == 1) block = new CSprite("image/square1.png"), block_check = 1;
	else if (MyKeyState('2') == 1) block = new CSprite("image/sand.png"), block_check = 2;
	else if (MyKeyState('3') == 1) block = new CSprite("image/soil.png"), block_check = 3;
	rect = Rect(NULL, NULL, NULL, NULL);
	pos.y = laon->square2->pos.y + 15;
	pos.x = laon->square2->pos.x + 10;

	check = false;
	if (block_check != false)
	{
		if (MyKeyState('S') == 1) 
			check = 1, rect = Rect(laon->square2->pos.x + 10, laon->square2->pos.y + 190, laon->square2->pos.x + 30, laon->square2->pos.y + 210), rect_check = Rect(laon->square2->pos.x + 10, laon->square2->pos.y + 120, laon->square2->pos.x + 30, laon->square2->pos.y + 140);
		else if (MyKeyState('W') == 1) 
			check = 2, rect = Rect(laon->square2->pos.x + 10, laon->square2->pos.y - 140, laon->square2->pos.x + 30, laon->square2->pos.y - 120), rect_check = Rect(laon->square2->pos.x + 10, laon->square2->pos.y - 60, laon->square2->pos.x + 30, laon->square2->pos.y - 30);
		else if (MyKeyState('A') == 1) 
			check = 3, rect = Rect(laon->square2->pos.x - 160, laon->square2->pos.y + 20, laon->square2->pos.x - 140, laon->square2->pos.y + 40), rect_check = Rect(laon->square2->pos.x - 90, laon->square2->pos.y + 20, laon->square2->pos.x - 110, laon->square2->pos.y + 40);
		else if (MyKeyState('D') == 1) 
			check = 4, rect = Rect(laon->square2->pos.x + 170, laon->square2->pos.y + 20, laon->square2->pos.x + 190, laon->square2->pos.y + 40), rect_check = Rect(laon->square2->pos.x + 100, laon->square2->pos.y + 20, laon->square2->pos.x + 120, laon->square2->pos.y + 40);
	}
}

void Block::Render(D3DXMATRIX *pmat)
{
	IObject::Render(pmat);
	block->Render(&this->mat);
}