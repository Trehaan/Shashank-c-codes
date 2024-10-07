#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int val,exp;
	Node *prev,*next;
}

Node* createNode(int val,int exp,Node* prev,Node* next)
{
	Node* node = malloc(sizeof(Node));
	node->val = val;
	node->exp = exp;
	node->prev = prev;
	node->next = next;
}

void insertR(Node* header, int val, int exp)
{
	if (!header->next)
	{
		header->next = createNode(val,exp,NULL,NULL);
		return;
	}

	Node* current = header;
	while (current->next != NULL && header)
}

Node* add(Node* n1, Node* n2)
{

}

