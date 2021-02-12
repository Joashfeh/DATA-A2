#pragma once
#include "Quad.h"
#include "Position.h"

class Quad;

class GO {
private:
	Position pos;
	Quad*    Area;
	int      GO_ID;

public:

	GO();
	GO(int ID, int x, int y);
	~GO();

	void  setArea(Quad* area);
	void  setPos(int x, int y);

	Quad* getArea();
	int   getX();
	int   getY();
	int   getID();
};

