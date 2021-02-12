#include <iostream>
#include "GOManager.h"
#include "TextParser.h"

int main(void) {
	GOManager qtree;
	TextParser(&qtree, "Game Objects//Objects.txt");
	
	std::string input;
	do {

		std::cout << "(1) Print Tree\n(2) Print surrounding GOs\nEnter Choice: ";
		std::cin >> input;
		try {
			int i = std::stoi(input);
			switch (i) {
			case 1: 
				system("cls");
				qtree.PrintTree();
				break;
			case 2:
				std::cout << "Enter GO ID: ";
				std::cin >> input;
				try {
					i = std::stoi(input);
					qtree.PrintNearbyGO(i);
					std::cout << std::endl;
				} catch (...) {
					std::cout << "You have entered an invalid ID";
				}
				break;
			}
			
		} catch (...) {
			std::cout << "You have entered an invalid input." << std::endl;
		}

	} while (input != "Q" || input != "q");

}