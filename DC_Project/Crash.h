#pragma once

class Laon;
class Map;
class Crash {
public:
	Crash(Laon *laon,Map *map);

	Laon *laon;
	Map *map;

	int sum;

	void Update(float eTime);
};