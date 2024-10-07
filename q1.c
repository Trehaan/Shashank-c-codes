#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
} Node;

Node* createNode(int data, Node* prev, Node* next)
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = next;
	node->prev = prev;

	return node;
}

bool isEmpty(Node* head)
{
	return !head;
}

void insertR(Node** head_ref,int data)
{
	if (!(*head_ref))
	{
		*head_ref = createNode(data,NULL,NULL);
		return;
	}

	Node* current = *head_ref;
	while (current->next)
		current = current->next;

	current->next = createNode(data,current,NULL);

}

int deleteR(Node** head_ref)
{

	int data;

	if (!(*head_ref)->next)
	{
		data = (*head_ref)->data;
		*head_ref = NULL;
	}

	else
	{

		Node* current = *head_ref;
		while (current->next->next)
			current = current->next;

		data = current->next->data;
		current->next = NULL;

	}

	return data;

}

void insertL(Node** head_ref, int data)
{
	if (!(*head_ref))
	{
		*head_ref = createNode(data,NULL,NULL);
		return;
	}

	Node* node = createNode(data,NULL,*head_ref);
	(*head_ref)->prev = node;
	*head_ref = node;
}

int deleteL(Node** head_ref)
{
	int data = (*head_ref)->data;
	*head_ref = (*head_ref)->next;
	(*head_ref)->prev = NULL;
	return data;
}

void display(Node* head)
{
	printf("Linked List : NULL -> ");
	while (head)
	{
		printf("%d -> ",head->data);
		head = head->next;
	}
	printf("NULL\n");
}

int main()
{
	Node* head = NULL;

	int choice;
	int ele;

	do
	{
		printf("\n\n1)InsertL\n2)InsertR\n3)DeleteL\n4)DeleteR\n5)Display\n6)Quit \n\n");
		scanf("%d",&choice);

		switch (choice)
		{
			case 1:
				printf("Enter the element : ");
				scanf("%d",&ele);
				insertL(&head,ele);
				break;

			case 2:
				printf("Enter the element : ");
				scanf("%d",&ele);
				insertR(&head,ele);
				break;

			case 3:
				if (isEmpty(head))
					printf("Linked List is empty!\n");
				else
					printf("%d deleted from left.\n",deleteL(&head));
				break;

			case 4:
				if (isEmpty(head))
					printf("Linked List is empty!\n");
				else
					printf("%d deleted from right.\n",deleteR(&head));
				break;

			case 5:
				display(head);
				break;

			case 6:
				break;
		}
	}  while ( choice != 6 );

	return 0;
}