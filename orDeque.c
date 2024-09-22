#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
	char** arr;
	int front;
	int rear;
	int size;
} deque;

void init(deque* q, int size)
{
	q->front = q->rear = -1;
	q->size = size;
	q->arr = malloc(sizeof(char*)*size);
}

bool isFull(deque* q)
{
	return q->front == (q->rear + 1) % q->size; 
}

bool isEmpty(deque* q)
{
	return q->front == -1;
}

void insertR(deque* q, char* ele)
{
	if (isEmpty(q))
		q->front = 0;

	q->rear = (q->rear + 1) % q->size;
	q->arr[q->rear] = ele;
}

char* deleteF(deque* q)
{
	char* ele = q->arr[q->front];

	if (q->front == q->rear)
		q->front = q->rear = -1;
	else
		q->front = (q->front + 1) % q->size;

	return ele;
}

void insertF(deque* q, char* ele)
{
	if (isEmpty(q))
	{
		q->front = q->rear = 0;
	}

	else
		q->front = (q->front - 1 + q->size) % q->size;
	
	q->arr[q->front] = ele;
}

/*char* deleteR(deque* q)
{
	char* ele = q->arr[q->rear];

	if (q->front == q->rear)
		q->front = q->rear = -1;
	else
		q->rear = (q->rear - 1) % q->size;

	return ele;
}*/

void display(deque* q)
{
	printf("\nQueue : ");

	if (!isEmpty(q))
	{
		int i;
		for (i = q->front; i != q->rear; i = (i + 1) % q->size)
			printf("%s\t",q->arr[i]);
		printf("%s\n\n",q->arr[q->rear]);
	}
}

int main()
{
	deque* q = malloc(sizeof(deque));
	int len;
	printf("Enter the size of the queue : ");
	scanf("%d",&len);

	init(q,len);

	int choice;
	char* ele;
	do
	{
		printf("\n1)Insert at Front\n2)Delete from front\n3)Insert at Rear\n4)Display\n5)Quit\n\nEnter the number pertaining to the desired operation : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				if (isFull(q))
				{
					printf("Queue full.\n");
					break;
				}

				printf("Enter the element to insert at front : ");
				ele = malloc(sizeof(char)*50);
				scanf("%s",ele);

				insertF(q,ele);
				printf("%s inserted at front.\n");
				break;

			case 2:
				if (isEmpty(q))
					printf("Queue empty.\n");
				else
					printf("%s deleted from front.\n",deleteF(q));
				break;

			case 3:
				if (isFull(q))
				{
					printf("Queue full.\n");
					break;
				}

				printf("Enter the element to insert at rear : ");
				ele = malloc(sizeof(char)*50);
				scanf("%s",ele);

				insertR(q,ele);
				printf("%s inserted at rear.\n");
				break;

			case 4:
				display(q);
				break;

			case 5:
				break;

			default:
				printf("INVALID INPUT!\nEnter a valid choice.\n");
				break;

		}


	} while (choice != 5);

	return 0;
}