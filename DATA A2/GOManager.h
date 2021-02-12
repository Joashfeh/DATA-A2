#pragma once
#include "Quad.h"
class GOManager {
private:
	Quad* root;

public:
	GOManager();
	~GOManager();

	void insert(int ID, int x, int y);
	void DeleteAll(Quad* quad);
	void PrintTree();
	void PrintNearbyGO(int GO_ID);
};

