#include<iostream>

struct node{
	int data;
	node* right;
	node* left;
};

class BST
{
	node* Root;
public:
	//Create node
	node* creation()
	{
		node* newNode = new node();
		return newNode;
	}
	
};
int main(){

	return 0;	
}
