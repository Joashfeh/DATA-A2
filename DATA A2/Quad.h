#pragma once
#include "GO.h"
#include <vector>
#include <string>
#include "Position.h"

class GO;

enum QUAD_TYPE {
	TOPL,
	TOPR,
	BOTL,
	BOTR,
	ROOT
};

class Quad {
private:

	// Pointers for the quad.

	Quad*     parent;
	Quad*     TOPLEFT;
	Quad*     TOPRIGHT;
	Quad*     BOTLEFT;
	Quad*     BOTRIGHT;

	QUAD_TYPE quadType;
	Position  pos; // x & y are in the center of the quad.
	float     width; // width from the left to right of the quad
	float     height; // height from the top to bottom of the quad
	int		  hierarchy; // integer value used for the quad's hierachy in the quad tree.
	int		  capacity; // capacity to check if the quad needs to be subdivided.
	bool	  divided; // boolean to check if this quad has been divided before.

public:
	std::vector<GO*> GOList;

	Quad();
	Quad
	(
		QUAD_TYPE quadType,
		Position pos,
		Quad* parent,
		float width,
		float height,
		int hierarchy
	);
	~Quad();

	bool  containsGO(GO* obj);
	void  insertGO(GO* obj);
	void  subDivide();
	void  PrintGOsInside(std::string spaces);
	void  PrintNearbyGOs(int GO_ID);

	Quad& getTopLeft();
	Quad& getTopRight();
	Quad& getBotLeft();
	Quad& getBotRight();
};

