#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

typedef struct
{
	char* arr;
	int top;
} Stack;

void init(Stack* st)
{
	st->top = -1;
	st->arr = NULL; // Better initialization for the stack
}

void push(Stack* st, char ele)
{
	st->arr = realloc(st->arr, sizeof(char) * ((++st->top) + 1));
	st->arr[st->top] = ele;
}

char pop(Stack* st)
{
	if (st->top == -1)
		return '\0'; // Return null character if stack is empty

	char popped = st->arr[st->top];
	st->top--; // Decrease the top index without reallocating
	return popped;
}

bool isValid(char* exp)
{
	Stack stack;
	Stack* st = &stack;
	init(st);
	char cur;

	for (char* ptr = exp; *ptr != '\0'; ptr++)
	{
		char c = *ptr;

		if (c == '(' || c == '[' || c == '{')
			push(st, c);
		else if (c == ')' || c == ']' || c == '}')
		{
			cur = pop(st);
			if (cur == '\0' || (c == ')' && cur != '(') || (c == ']' && cur != '[') || (c == '}' && cur != '{'))
				return false;
		}
	}

	return (st->top == -1); // Stack should be empty if the expression is valid
}

int main()
{
	char str[100];
	printf("Enter the string: ");
	fgets(str, 100, stdin);
	str[strcspn(str, "\n")] = '\0'; // Remove the newline character from input

	if (isValid(str))
		printf("The expression is valid.\n");
	else
		printf("The expression is invalid.\n");

	return 0;
}
