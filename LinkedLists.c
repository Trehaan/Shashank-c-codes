#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct NODE
{
	int data;
	struct NODE* next;
};

struct NODE* createNode(int data, struct NODE* next)
{
	struct NODE* node = (struct NODE*)malloc(sizeof(struct NODE));
	node->data = data;
	node->next = next;

	return node;
}

void insertAtEnd(struct NODE** tail_ref, int data)
{
	struct NODE* node = createNode(data,NULL);
	(*tail_ref)->next = node;
	*tail_ref = node;
}

void insertAtStart(struct NODE** head_ref, int data)
{
	struct NODE* node = createNode(data,*head_ref);
	*head_ref = node;
}

int deleteFromStart(struct NODE** head_ref)
{
	int data = (*head_ref)->data;
	struct NODE* temp = *head_ref;
	*head_ref = (*head_ref)->next;
	free(temp);
	return data;
}

int deleteFromEnd(struct NODE* head, struct NODE** tail_ref)
{
	int data = (*tail_ref)->data;
	struct NODE* current = head;
	while (current->next != *tail_ref)
		current = current->next;

	current->next = NULL;
	free(*tail_ref);
	*tail_ref = current;
	return data;
}

void display(struct NODE* head)
{
	printf("\nLINKED LIST : ");

	if (head == NULL)
		return;
	
	struct NODE* temp = head;

	while (temp->next != NULL)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("%d\n",temp->data);
}

int main()
{
	struct NODE* head = NULL;
	struct NODE* tail = NULL;

	int choice;
	int num;
	do 
	{
		printf("\n\n1)InsertAtEnd\n2)InsertAtStart\n3)DeleteFromEnd\n4)DeleteFromStart\n5)Display\n6)Quit\n\nEnter the number pertaining to the desired operation : ");
		scanf("%d",&choice);

		switch (choice)
		{
			case 1:

				printf("Enter the element : ");
				scanf("%d",&num);

				if (tail == NULL)
					head = tail = createNode(num,NULL);
				else
					insertAtEnd(&tail,num);
				break;

			case 2:

				printf("Enter the number : ");
				scanf("%d",&num);

				if (tail == NULL)
					head = tail = createNode(num,NULL);
				else
					insertAtStart(&head,num);
				break;

			case 3:

				if (tail == NULL)
					printf("Linked List Empty.");
				else
					printf("%d deleted from end.\n",deleteFromEnd(head,&tail));
				break;

			case 4:

				if (head == NULL)
					printf("Linked List Empty.\n");
				else
					printf("%d deleted from start.\n",deleteFromStart(&head));
				break;

			case 5:

				display(head);
				break;

			case 6:
				break;

		}


	} while ( choice != 6);

	return 0;
}