#include "BSTNode.hpp"

//std::string dKeys[39] = { "A",  "B",    "C",    "D",   "E", "F",    "G",   "H",    "I",  "J",    "K",   "L",    "M",  "N",  "O",   "P",    "Q",    "R",   "S",   "T", "U",   "V",    "W",   "X",    "Y",    "Z",    "0",     "1",     "2",     "3",     "4",     "5",     "6",     "7",     "8",     "9",     ".",      ",",      "?" };
//std::string dVals[39] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--.."};

//constructor
Node::Node(char c, std::string m) {
	character = c;
	morse = m;
}

//setters
void Node::setPLeft(Node* newNode) {
	pLeft = newNode;
}

void Node::setPRight(Node* newNode) {
	pRight = newNode;
}

//getters
Node* Node::getPLeft() {
	return pLeft;
}

Node* Node::getPRight() {
	return pRight;
}

char Node::getChar() {
	return character;
}

std::string Node::getMorse() {
	return morse;
}