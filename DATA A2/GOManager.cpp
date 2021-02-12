#include "GOManager.h"
#include <iostream>

GOManager::GOManager() {
	root = new Quad(ROOT, Position(100, 100), NULL, 200, 200, 0);
}

GOManager::~GOManager() {
	DeleteAll(root);
}

// Inserts GOs using recursion starting from the root.
void GOManager::insert(int ID, int x, int y) {
	root->insertGO(new GO(ID, x, y));
}

// Deletes all quads and GOs inside using recursion starting from the root.
void GOManager::DeleteAll(Quad* quad) {
	if (quad == nullptr)
		return;

	DeleteAll(&quad->getTopLeft());
	DeleteAll(&quad->getTopRight());
	DeleteAll(&quad->getBotLeft());
	DeleteAll(&quad->getBotRight());

	delete quad;
}

// Print tree
void GOManager::PrintTree() {
	root->PrintGOsInside("");
}
// Function to print out nearby GOs of a given GO_ID.
void GOManager::PrintNearbyGO(int GO_ID) {
	for (int i = 0; i < root->GOList.size(); ++i) {
		if (root->GOList[i]->getID() == GO_ID) {
			root->GOList[i]->getArea()->PrintNearbyGOs(GO_ID);
		}
	}
}

