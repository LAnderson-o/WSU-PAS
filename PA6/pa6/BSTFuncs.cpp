#include "BST.hpp"

BST::BST() {
	pRoot = nullptr;
	std::fstream infile;
	infile.open("morseTable.txt", std::fstream::in);
	if(infile){
		std::string newMorse;
		std::string charVal;
		while (!infile.eof()) {
			infile >> charVal >> newMorse;
			insert(charVal[0], newMorse, pRoot);
		}
	} else {
		std::cout << "FILE NOT OPEN" << "\n";
	}
	infile.close();
}

void BST::insert(char c, std::string s, Node* pTree) {
	if (pTree == nullptr) {//empty
		pRoot = new Node(c, s);
	}
	else if (pTree != nullptr) {
			if (pTree->getChar() > c) {//left
				if (pTree->getPLeft() == nullptr) {
					pTree->setPLeft(new Node(c, s));
				} else {
					insert(c, s, pTree->getPLeft());
				}
			} else if (pTree->getChar() < c) {//right
				if (pTree->getPRight() == nullptr) {
					pTree->setPRight(new Node(c, s));
				} else {
					insert(c, s, pTree->getPRight());
				}
			}
	}
}

void BST::printInOrder(Node* pTree) {
	if (pTree != nullptr) {
		printInOrder(pTree->getPLeft());
		std::cout << pTree->getChar() << pTree->getMorse() << "\n";
		printInOrder(pTree->getPRight());
	}
}

void BST::printPostOrder(Node* pTree) {
	if (pTree != nullptr) {
		printPostOrder(pTree->getPLeft());
		printPostOrder(pTree->getPRight());
		std::cout << pTree->getChar() << pTree->getMorse() << "\n";
	}
}

void BST::printPreOrder(Node* pTree) {
	if (pTree != nullptr) {
		std::cout << pTree->getChar() << pTree->getMorse() << "\n";
		printPreOrder(pTree->getPLeft());
		printPreOrder(pTree->getPRight());
	}
}

Node* BST::getRoot() {
	return pRoot;
}

std::string BST::convert(char newChar, Node* pTree) {
	if(pTree != nullptr){
		char checkChar = pTree->getChar();
		if (newChar == checkChar) {
			return pTree->getMorse();
		}
		if (newChar < checkChar) {
			return convert(newChar, pTree->getPLeft());
		}
		if (newChar > checkChar) {
			return convert(newChar, pTree->getPRight());
		}
	}
}