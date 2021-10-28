#include "BST.hpp"

/*
Programmer: Lucas Anderson
Class: CptS 122; Lab Section 6
Programming Assignment: 6
Date: 10/28/2021
Description: this program converts text from "Convert.txt" into morse code and dislays the output to the screen
*/

int main(void) {
	BST Tree;
	Tree.printInOrder(Tree.getRoot());


	std::fstream infile;
	infile.open("Convert.txt", std::fstream::in);
	if (infile.is_open()){
		std::string line;
		while (getline(infile, line)) {
			for (int i = 0; i < line.size(); ++i) {
				std::cout << Tree.convert(toupper(line[i]), Tree.getRoot()) << " ";
			}
			std::cout << "\n";
		}
	} else {
		std::cout << "FILE NOT OPEN" << "\n";
	}
	infile.close();
}