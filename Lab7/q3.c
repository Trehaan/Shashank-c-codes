#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
	int* arr;
	int front,rear;
	int size;
} queue;

void init(queue* q,int len)
{
	q->arr = malloc(sizeof(int)*len);
	q->front = 0;
	q->rear = 0;
	q->size = len;
}

bool isFull(queue* q)
{
	return ((q->rear + 1)%q->size == q->front);
}

bool isEmpty(queue* q)
{
	return (q->front == 0);
}

void enqueue(queue* q,int ele)
{
	if (isFull(q))
	{
		printf("Queue full.\n");
		return;
	}

	if (isEmpty(q))
		q->front = 1;

	q->rear = (q->rear + 1) % q->size;
	q->arr[q->rear] = ele;
}

int dequeue(queue* q)
{
	int ele;

	if (isEmpty(q))
		printf("Queue empty.\n");

	ele = q->front;

	if (q->front == q->rear)
	{
		q->front = q->rear = 0;
	}
	else
	{
		q->front  = (q->front + 1) % q->size;
	}

	return ele;
}

void display(queue* q)
{
	int i;
	for (i=q->front;i!=q->rear;i++)
	{
		printf("%d ",q->arr[i]);
	}
	printf("%d\n",q->arr[q->rear]);
}

void test()
{
	int i,j,n,k;
	printf("Enter N,K : ");
	scanf("%d,%d",&n,&k);

	queue que;
	queue* q = &que;

	init(q,n+1);
	for (i=0;i<n;i++)
		enqueue(q,i+1);

	for (i=0;i<(n/3);i++)
	{
		for (j=0;j<3;j++)
		{
			if (dequeue(q) == k)
			{
				if (j==2)
					printf("No\n");
				else
					printf("Yes\n");
				return;
			}
		}
	}		
}

int main()
{
	int i,t;

	printf("Enter T : ");
	scanf("%d",&t);

	for (i = 0;i<t;i++)
	{
		printf("\nTEST CASE %d : \n",i+1);
		test();
	}

}