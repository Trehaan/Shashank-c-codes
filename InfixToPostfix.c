#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>

typedef struct
{
	int top;
	char* arr;

} Stack;

void init(Stack* st)
{
	st->top = -1;
	st->arr = malloc(0);
}

void push(Stack* st,char ele)
{
	st->arr = realloc(st->arr,sizeof(char)*((++st->top)+1));
	st->arr[st->top] = ele;
}

char pop(Stack* st)
{
	char popped = st->arr[st->top];
	st->arr = realloc(st->arr,sizeof(char)*(st->top--));
	return popped;
}

bool isEmpty(Stack* st)
{
	return (st->top == -1);
}

int prec(char c)
{
	if ( c == '(')
		return 0;
	else if ( c == '+' || c == '-' )
		return 1;
	else if ( c == '*' || c == '/' )
		return 2;
	else if ( c == '^')
		return 3;
}

char* inToPost(char* infix)
{
	Stack stack;
	Stack* st = &stack;
	char* postfix = malloc(sizeof(char)*strlen(infix));
	int k = 0;

	init(st);

	int i;
	char x;
	for (i=0;infix[i]!='\0';i++)
	{
		char c = infix[i];

		if (isdigit(c))
		{
			postfix[k++] = c;
		}

		else if (c == '(')
		{
			push(st,c);
		}

		else if (c == ')')
		{
			while ((x = pop(st)) != '(')
				postfix[k++] = x;
		}

		else
		{
			while (!isEmpty(st))
			{
				if (prec(c) <= prec(st->arr[st->top]))
					postfix[k++] = pop(st);
				else
					break;
			}

			push(st,c);
		}

	}

	while (!isEmpty(st))
		postfix[k++] = pop(st);

	return postfix;
}

int main()
{
	char str[100];
	printf("Enter the string : ");
	fgets(str,100,stdin);
	int i=0;
	while (1)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}

		i++;
	}

	printf("%s",inToPost(str));

}