#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
	char** arr;
	int top;
}Stack;

void init(Stack* st)
{
	st->top = -1;
	st->arr = malloc(0);
}

void push(Stack* st, char* ele)
{
	st->arr = realloc(st->arr,sizeof(char*)*((++st->top)+1));
	st->arr[st->top] = ele;
}

char* pop(Stack* st)
{
	char* popped = st->arr[st->top];
	st->arr = realloc(st->arr,sizeof(char*)*(st->top--));
	return popped;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

char* postToPre(char* postfix)
{
	Stack s;
	Stack* st = &s;
	init(st);

	bool readingNum = false;
	char* str;
	char* op1;
	char* op2;
	int k;

	char* ptr;
	for (ptr = postfix; *ptr != '\0'; ptr++)
	{
		char c = *ptr;

		if (readingNum)
		{
			if (isdigit(c))
			{
				str = realloc(str,sizeof(char)*((++k)+1));
				str[k] = c;
			}
			else
			{
				readingNum = false;
				
				if (c == ' ')
				{
					str = realloc(str,sizeof(char)*((++k)+1));
					str[k] = c;
				}

				push(st,str);
			}
		}

		else if (isdigit(c))
		{	
			readingNum = true;
			str = calloc(1,sizeof(char));
			str[k = 0] = c;
		}

		if (isOperator(c))
		{
			op2 = pop(st);
			op1 = pop(st);
			str = calloc(2+strlen(op1)+strlen(op2),sizeof(char));
			str[0] = c;
			str[1] = ' ';
			strcat(str,op1);
			strcat(str,op2);
			push(st,str);
		}
	}

	return pop(st);

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

	char* res = postToPre(str);
	printf("%s\n%d",res,res[strlen(res)-1] == ' ');

}

