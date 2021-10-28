#include <string>
#include <iostream>
#include <fstream>
#include <cctype>

class Node {
public:
	//constructor
	Node(char c, std::string m);

	//setters
	void setPLeft(Node* newNode);
	void setPRight(Node* newNode);

	//getters
	Node* getPLeft();
	Node* getPRight();
	char getChar();
	std::string getMorse();
private:
	char character;
	std::string morse;
	Node* pLeft;
	Node* pRight;
};