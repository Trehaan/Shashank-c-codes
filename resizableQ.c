#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
	int front,rear,size;
	int* arr;
} queue;

void init(queue* q,int size)
{
	q->front = -1;
	q->rear = -1;
	q->size = size;
	q->arr = malloc(sizeof(int)*size);
}

bool isFull(queue* q)
{
	return q->front == (q->rear + 1) % q->size;
}

bool isEmpty(queue* q)
{
	return q->front == -1;
}

void enqueue(queue* q,int ele)
{
	if (isEmpty(q))
		q->front = 0;

	q->rear = (q->rear + 1) % q->size;
	q->arr[q->rear] = ele;
}

int dequeue(queue* q)
{
	int ele = q->arr[q->front];

	if (q->front == q->rear)
		q->front = q->rear = -1;

	else
		q->front = (q->front + 1) % q->size;

	return ele;
}

void display(queue* q)
{
	printf("\nQueue : ");

	if (!isEmpty(q))
	{
		int i;
		for (i = q->front; i != q->rear; i = (i + 1) % q->size)
			printf("%d\t",q->arr[i]);
		printf("%d\n\n",q->arr[q->rear]);
	}
}

int main()
{
	queue* q = malloc(sizeof(queue));
	int len;
	printf("Enter the size of the queue : ");
	scanf("%d",&len);

	init(q,len);

	int choice;
	int ele;
	do
	{
		printf("\n1)Enqueue\n2)Dequeue\n3)Display\n4)Quit\n\nEnter the number pertaining to the desired operation : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				if (isFull(q))
				{
					printf("Queue full.\n");
					do
					{
						printf("Enter the new queue size : ");
						scanf("%d",&len);
					} while (len <= q->size);

					int prev_size = q->size;
					q->size = len;
					q->arr = realloc(q->arr, sizeof(int)*len);

					if (q->front > q->rear)
					{
						int i;
						for (i = 0; i < prev_size - q->front; i++)
							q->arr[len-i-1] = q->arr[prev_size-i-1];

						q->front += len-prev_size; 
					}

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
				display(q);
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