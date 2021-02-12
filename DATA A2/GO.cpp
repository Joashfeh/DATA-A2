#include "GO.h"

GO::GO() {
}

GO::GO(int ID, int x, int y) {
	this->GO_ID = ID;
	this->pos.Set(x, y);
}

GO::~GO() {
}

void GO::setArea(Quad* area) {
	this->Area = area;
}

void GO::setPos(int x, int y) {
	this->pos.Set(x, y);
}

Quad* GO::getArea() {
	return this->Area;
}

int GO::getX() {
	return this->pos.x;
}

int GO::getY() {
	return this->pos.y;
}

int GO::getID() {
	return this->GO_ID;
}
