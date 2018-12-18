

#include <iostream>

Node * BinaryTree(tree * root, int target)
{
	if(root == NULL)
		return;
	node* now = root;


	if(now->value == target)
	{

		return now;
	}
	else if ( now->value > target)
	{
		BinaryTree(now->rightChild, target);
	}	
	else
	{
		BinaryTree(now->leftChild, target);
	}

}

Node * List(Node * node)
{
	int len = 0;
	Node * head = node;

	while(!node->NULL)
	{
		node = node->next;
		len++;
	}
	int srand = srand() % len;

	while(srand--)
	{
		head = head->next;
	}
	return head;
}



#!/bin/bash


ls  > 
