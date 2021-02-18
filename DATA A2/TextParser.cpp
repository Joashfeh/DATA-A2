#include "TextParser.h"

// Text Parser for Object Data, using delimiters to tokenize the string input.
// Object info must be in format of "ID,x,y"
void TextParser(GOManager* QuadTree, std::string filename) {
	std::ifstream pointData;
	pointData.open(filename);

	if (!pointData) {
		std::cout << "Error opening file" << std::endl;
		return;
	}

	std::string ID;
	std::string x;
	std::string y;
	char ch;
	while (!pointData.eof()) {
		std::getline(pointData, ID, ',');
		std::getline(pointData, x, ',');
		std::getline(pointData, y);

		QuadTree->insert(
			std::stoi(ID), 
			std::stoi(x), 
			std::stoi(y)
		);
	}

}
