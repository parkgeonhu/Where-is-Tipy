#include "Crash.h"
#include "Laon.h"
#include "Map.h"

extern CSprite *g_map;

Crash::Crash(Laon *laon, Map *map) {
	this->laon = laon;
	this->map = map;
}
void Crash::Update(float eTime){
	this->map->a_1 = false;
	this->laon->r2 = this->map->r2;
	this->map->n_pos = this->laon->n_pos;
	this->map->r2.right = this->map->r2.left + g_map->width;
	this->map->r2.bottom = this->map->r2.top + g_map->height;

	if (IntersectRect(&this->laon->tempRect, &this->laon->r1, &this->laon->r2)) {
		this->laon->jumping = false;
		this->laon->gv = 0.f;
		if (this->laon->pos.y + this->laon->laon->height > this->laon->r2.top + 1) {
			this->laon->pos.y = this->laon->r2.top - this->laon->laon->height + 1;
		}
	}

	for (int i = 0; i<10; i++)
	{
		if (i == 0)
		{
			sum = 0;
			this->map->r2.top;
		}
		if (this->map->n_pos.x > this->map->A[i].x_s - 10 && this->map->n_pos.x < this->map->A[i].x_e + 10)
		{
			if (this->map->n_pos.x > this->map->A[i].x_s - 10 && this->map->n_pos.x < this->map->A[i].x_s && this->laon->r1.top + 50 > this->map->top - this->map->A[i].y)
				this->map->a_1 = 1;
			if (this->map->n_pos.x > this->map->A[i].x_e && this->map->n_pos.x < this->map->A[i].x_e + 10 && this->laon->r1.top + 50 > this->map->top - this->map->A[i].y)
				this->map->a_1 = 2;
		}
		if (this->map->n_pos.x > this->map->A[i].x_s && this->map->n_pos.x < this->map->A[i].x_e)
			sum += this->map->A[i].y;
		if (i == 9 || this->map->A[i].x_s > this->map->n_pos.x)
		{
			this->map->r2.top = this->map->top - sum;
			break;
		}
	}


}