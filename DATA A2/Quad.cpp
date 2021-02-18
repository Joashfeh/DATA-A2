#include "Quad.h"
#include <sstream>
#include <iostream>
#include <math.h>

Quad::Quad() {
	quadType = ROOT;
	capacity = 3;
	divided = false;

	TOPLEFT = NULL;
	TOPRIGHT = NULL;
	BOTLEFT = NULL;
	BOTRIGHT = NULL;
}

// Overloaded function for Quad initialisation.
Quad::Quad(QUAD_TYPE quadType, Position pos, Quad* parent, float width, float height, int hierarchy) {

	this->quadType = quadType;
	this->hierarchy = hierarchy;
	this->width = width;
	this->height = height;
	this->pos = pos;
	this->capacity = 3;
	this->divided = false;

	this->parent = parent;

	TOPLEFT = NULL;
	TOPRIGHT = NULL;
	BOTLEFT = NULL;
	BOTRIGHT = NULL;

}

Quad::~Quad() {
}

/*A method to check if the GO is within a quad's space.
In the case of a quad having a width and height of 1, The GO may exist on one of the four corners of the quad, as quad positions exist on the cartesian plane as well.
If a quad has a position of (12.5, 12.5), and a width and height of 1, a GO will only exist in this quad if its x and y positions are equal to or greater than its left and top starts, and will not exist in the quad if the point is equal to its bottom or right edges.
*/
bool Quad::containsGO(GO* obj) {
	return (obj->getX() >= this->pos.x - this->width / 2 &&
			obj->getX() < this->pos.x + this->width / 2 &&
			obj->getY() >= this->pos.y - this->height / 2 &&
			obj->getY() < this->pos.y + this->height / 2);
}

void Quad::insertGO(GO* obj) {

	// Cancel insert if an object with the same position already exists.
	for (GO* objects : GOList) {
		if (obj->getX() == objects->getX() && obj->getY() == objects->getY())
			return;
	}

	// if returns the function if the GO does not exist within the quad's space.
	if (!containsGO(obj))
		return;

	obj->setArea(this);
	GOList.push_back(obj);

	// If the number of GOs in the quad has exceeded its given capacity.
	if (GOList.size() > capacity) {
		if (!divided) {
			subDivide();
		}

		TOPLEFT->insertGO(obj);
		TOPRIGHT->insertGO(obj);
		BOTLEFT->insertGO(obj);
		BOTRIGHT->insertGO(obj);
	}
}

void Quad::subDivide() {

	// Quad with a size of 1 cannot be split anymore.
	if (width == 1 && height == 1)
		return;

	// Using integer division for odd widths and heights when subdividing.
	float leftWidth = floor(this->width / 2);
	float rightWidth = floor(this->width / 2);
	float topHeight = floor(this->height / 2);
	float botHeight = floor(this->height / 2);

	// if width and height is odd, follow assignment criteria.
	if (std::fmod(width, 2) != 0) 
		rightWidth += 1;

	if (std::fmod(height, 2) != 0)
		botHeight += 1;

	// assign new quads to the pointers within the quads.
	this->TOPLEFT = new Quad(TOPL, Position(pos.x - leftWidth / 2, pos.y - topHeight / 2), this, leftWidth, topHeight, this->hierarchy + 1);
	this->TOPRIGHT = new Quad(TOPR, Position(pos.x + rightWidth / 2, pos.y - topHeight / 2), this, rightWidth, topHeight, this->hierarchy + 1);
	this->BOTLEFT = new Quad(BOTL, Position(pos.x - leftWidth / 2, pos.y + botHeight / 2), this, leftWidth, botHeight, this->hierarchy + 1);
	this->BOTRIGHT = new Quad(BOTR, Position(pos.x + rightWidth / 2, pos.y + botHeight / 2), this, rightWidth, botHeight, this->hierarchy + 1);
	
	// insert the existing GOs into the new quads as creating a new quad would result in an empty vector.
	for (int i = 0; i < GOList.size() - 1; ++i) {
		TOPLEFT->insertGO(GOList[i]);
		TOPRIGHT->insertGO(GOList[i]);
		BOTLEFT->insertGO(GOList[i]);
		BOTRIGHT->insertGO(GOList[i]);
	}

	this->divided = true;
}

// Prints the list of GOs in the tree.
void Quad::PrintGOsInside(std::string spaces) {

	if (this == nullptr)
		return;

	// Type is the string used to print the Quad Type using the enum to check.
	std::string Type;
	switch (this->quadType) {
	case TOPL:
		Type = "TOPL";
		break;
	case TOPR:
		Type = "TOPR";
		break;
	case BOTL:
		Type = "BOTL";
		break;
	case BOTR:
		Type = "BOTR";
		break;
	case ROOT:
		Type = "ROOT";
		break;
	}

	std::stringstream ss;
	ss << spaces << hierarchy << "-" << Type << " (" << this->GOList.size() << ")";
	std::cout << ss.str() << std::endl;

	// Recursion to print out the next Quad's objects
	this->TOPLEFT->PrintGOsInside(spaces + ' ');
	this->TOPRIGHT->PrintGOsInside(spaces + ' ');
	this->BOTLEFT->PrintGOsInside(spaces + ' ');
	this->BOTRIGHT->PrintGOsInside(spaces + ' ');
}

// A method used by the GOManager to find nearby GOs in a specific quad given a GO's ID.
void Quad::PrintNearbyGOs(int GO_ID) {
	std::cout << "Nearby GO's ID(s): ";
	// Print out the nearby GOs without printing out the one being searched for.
	for (int i = 0; i < this->GOList.size(); ++i) {
		if (GOList[i]->getID() == GO_ID)
			continue;
		else {
			std::cout << GOList[i]->getID();
			if (i != GOList.size() - 1)
				std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

// Getter functions for quads.

Quad &Quad::getTopLeft() {
	return *TOPLEFT;
}

Quad &Quad::getTopRight() {
	return *TOPRIGHT;
}

Quad &Quad::getBotLeft() {
	return *BOTLEFT;
}

Quad &Quad::getBotRight() {
	return *BOTRIGHT;
}
