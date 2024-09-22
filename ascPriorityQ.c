#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct 
{
	int* arr;
	int size;
	int capacity;
} queue ;

void init(queue* q, int cap)
{
	q->capacity = cap;
	q->arr = malloc(sizeof(int)*cap);
	q->size = 0;
}

bool isEmpty(queue* q)
{
	return q->size == 0;
}

bool isFull(queue* q)
{
	return q->size == q->capacity;
}

void enqueue(queue* q,int ele)
{
	int i = q->size - 1;
	while ( i >= 0 && q->arr[i] < ele)
	{
		q->arr[i+1] = q->arr[i];
		i--;
	}

	q->arr[i+1] = ele;
	q->size++;
}

int dequeue(queue* q)
{
	int ele = q->arr[q->size-1];
	q->size--;
	return ele;
}

int peek(queue* q)
{
	return q->arr[q->size-1];
}

int main()
{
	queue* q = malloc(sizeof(queue));
	int cap;
	printf("Enter the size of the array : ");
	scanf("%d",&cap);

	init(q,cap);
	int choice,ele;
	do 
	{
		printf("\n1)Enqueue\n2)Dequeue\n3)Peek\n4)Quit\n\nEnter the number pertaining to the desired operation : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				if (isFull(q))
				{
					printf("Queue full.\n");
					break;
				}

				printf("Enter the element to enqueue : ");
				scanf("%d",&ele);
				enqueue(q,ele);
				printf("%d enqueued.\n");
				break;

			case 2:
				if (isEmpty(q))
					printf("Queue empty.\n");
				else
					printf("%d dequeued.\n",dequeue(q));
				break;

			case 3:
				if (isEmpty(q))
					printf("Queue empty.\n");
				else
					printf("Peeked at %d",peek(q));
				break;

			case 4:
				break;

			default:
				printf("INVALID INPUT!\nEnter a valid choice.\n");
				break;

		}


	} while (choice != 4);

	return 0;
}