#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
	int top;
	char* arr;

} Stack;

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

bool equals(Stack* s1,Stack* s2)
{
	bool flag = false;
	while (s1->top != -1)
	{
		if (pop(s1) != pop(s2))
		{	
			flag = true;
			break;
		}
	}

	if (flag)
		return false;
	else
		return true;
}

bool isPalindrome(Stack* orig_st)
{
	Stack* new_st = malloc(sizeof(Stack));
	new_st->top = -1;
	new_st->arr = malloc(0);

	/*char ele;
	while (new_st->top != orig_st->top)
	{
		ele = pop(orig_st);
		if (new_st->top != orig_st->top)
			push(new_st,ele);
	}*/

	while (new_st->top < orig_st->top - 1)
		push(new_st,pop(orig_st));

	if (new_st->top == orig_st->top-1)
		pop(orig_st);

	bool ret = equals(orig_st,new_st);
	free(new_st->arr);
	free(new_st);

	return ret;

}

int main()
{
	Stack stack;
	stack.top = -1;
	stack.arr = malloc(0);

	printf("Enter the string : ");
	char c;
	while ((c = getchar()) != '\n')
		push(&stack,c);

	if (isPalindrome(&stack))
		printf("Palindrome");
	else
		printf("Not Palindrome");

	free(stack.arr);
}