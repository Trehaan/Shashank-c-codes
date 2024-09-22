#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

typedef struct
{
	int top;
	int* arr;
}Stack;

void push(Stack* st,int ele)
{
    st->arr = realloc(st->arr,sizeof(int)*((++st->top)+1));
    st->arr[st->top] = ele;
}

int pop(Stack* st)
{
    int popped = st->arr[st->top];
    st->arr = realloc(st->arr,sizeof(int)*(st->top--));
    return popped;
}

void init(Stack* st)
{
	st->top = -1;
	st->arr = malloc(0);
}

int eval(int a,int b,char x)
{
	switch(x)
	{
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		case '%':
			return a%b;
	}
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int prefix_calc(char* exp)
{
	Stack stack;
	Stack* st = &stack;
	init(st);
	int i,a,b,num,mult;
	bool readingNum = false;
	for (i = strlen(exp) - 1; i>=0 ;i--)
	{
		if (readingNum)
		{
		    if (isdigit(exp[i]))
		    {
		        num += mult*(exp[i]-'0');
		        mult*=10;
		    }
		    else
		    {
		        readingNum = false;
		        push(st,num);
		    }
		}
		
		else if (isdigit(exp[i]))
		{
		    num = exp[i] - '0';
		    readingNum = true;
		    mult = 10;
		}
		    
	    if (isOperator(exp[i]))
        {
            a = pop(st);
            b = pop(st);
            push(st,eval(a,b,exp[i]));
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
	
	printf("%d",prefix_calc(str));
}
	
