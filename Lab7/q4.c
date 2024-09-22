#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 5

typedef struct
{
	int arr[MAX];
	int top;
} Stack;

void initStack(Stack* st)
{
	st->top = -1;
}

bool isStackEmpty(Stack* st)
{
	return (st->top == -1);
}

bool isStackFull(Stack* st)
{
	return (st->top == MAX - 1);
}

void push(Stack* st,int ele)
{
	if (isStackFull(st))
	{
		printf("Stack Overflow!\n");
		return;
	}
	st->arr[++st->top] = ele;
}

int pop(Stack* st)
{
	if (isStackEmpty(st))
	{
		printf("Stack Underflow!\n");
		return -99999;
	}
	return st->arr[st->top--];
}

typedef struct
{
	Stack stack1;
	Stack stack2;
	Stack* s1;
	Stack* s2;

} queue;

void initQueue(queue* q)
{
	q->s1 = &q->stack1;
	q->s2 = &q->stack2;
	initStack(q->s1);
	initStack(q->s2);
}

bool isQueueEmpty(queue* q)
{
	return (isStackEmpty(q->s1) && isStackEmpty(q->s2));
}

bool isQueueFull(queue* q)
{
	return ((q->s1->top + q->s2->top) == MAX - 2);
}

void enqueue(queue* q,int ele)
{
	if (isQueueFull(q))
	{
		printf("Queue full.");
		return;
	}

	push(q->s1,ele);
}

int dequeue(queue* q)
{
	if (isQueueEmpty(q))
	{
		printf("Queue empty.\n");
		return -99999;
	}

	if (isStackEmpty(q->s2))
	{
		while(!isStackEmpty(q->s1))
			push(q->s2,pop(q->s1));
	}

	int x = pop(q->s2);
	printf("%d ",x);
	return x;
}

int main()
{
	queue que;
	queue* q = &que;
	initQueue(q);

	enqueue(q,2);
	enqueue(q,59);
	enqueue(q,69);

	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);

	return 0;
}