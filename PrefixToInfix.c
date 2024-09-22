#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
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

int getMinPrec(char* x, int y)
{
	int i,cur_prec,min_prec = y;
	bool check = true;

	for (i=0;i<strlen(x);i++)
	{
		if (x[i] == '(')
			check = false;
		else if (x[i] == ')')
			check = true;
		else if (check)
		{
			if (isOperator(x[i]))
			{
				cur_prec = prec(x[i]);
				if (cur_prec < min_prec)
					min_prec = cur_prec;
			}
		}
	}

	return min_prec;
}

bool isExp(char* x)
{
	int i;
	bool flag = false;
	
	for (i=0;i<strlen(x);i++)
	{
		if (isOperator(x[i]))
		{
			flag = true; 
			break;
		}
	}

	return flag;
}

void bracket(char* x)
{
	int i;
	printf("x.length = %d\n",strlen(x));
	x = realloc(x,sizeof(char)*(strlen(x) + 1));
	for (i = strlen(x) - 1; i >= 1; i-- )
	{
		x[i] = x[i-1];
		printf("%s\n",x);
	}
	x[0] = '(';
	x[strlen(x)] = ')';
	printf("%s\n",x);
}

char* preToIn(char* prefix)
{
	Stack s;
	Stack* st = &s;
	init(st);

	bool readingNum = false;
	char* str;
	char* op1;
	char* op2;
	int k,i;

	char* ptr;
	for (ptr = prefix + strlen(prefix) - 1; ptr >= prefix; ptr--)
	{
		char c = *ptr;

		if (readingNum)
		{
			if (isdigit(c))
			{
				str = realloc(str,sizeof(char)*((++k)+1));
				for (i=k;i>=1;i--)
					str[i] = str[i-1];
				str[0] = c; 
				continue;
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
			printf("Op1 = %s\n",op1 = pop(st));
			printf("Op2 = %s\n",op2 = pop(st));

			int min = getMinPrec(op1,getMinPrec(op2,5));
			printf("min prec = %d\n",min);
			printf("prec(c) = %d\n",prec(c));
			if (prec(c) >= min)
			{
				if (isExp(op1))
					bracket(op1);
				if (isExp(op2))
					bracket(op2); 
			}

			str = calloc(3+strlen(op1)+strlen(op2),sizeof(char));
			strcpy(str,op1);
			str[strlen(str)] = c;
			str[strlen(str)] = ' ';
			str[strlen(str)] = '\0';
			strcat(str,op2);
			printf("str = %s\n",str);
			push(st,str);
		}


		/*else if (c == ' ')
		{
			str = realloc(str,sizeof(char)*((++k)+1));
			str[k] = c;
		}*/

		printf("\nStack : ");
		for (i = st->top;i>=0;i--)
			printf("%s\t",st->arr[i]);
		printf("\n");

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

	printf("%s",preToIn(str));

}

