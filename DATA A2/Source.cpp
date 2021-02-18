#include <iostream>
#include "GOManager.h"
#include "TextParser.h"
#include <exception>

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
				} catch (std::invalid_argument& e) {
					if (input == "q") return 0;
					std::cout << "Invalid Argument";
				}
				break;
			}
			
		} catch (std::invalid_argument& e) {
			if (input == "q") return 0;
			std::cout << "Invalid Argument" << std::endl;
		}

	} while (1);

}