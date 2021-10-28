#include "BSTNode.hpp"

class BST {
public:
	//constructors
	BST();
	void insert(char c, std::string s, Node* pTree);
	void printInOrder(Node* pTree);
	void printPostOrder(Node* pTree);
	void printPreOrder(Node* pTree);
	std::string convert(char newChar, Node* pTree);

	Node* getRoot();
private:
	Node* pRoot;
};