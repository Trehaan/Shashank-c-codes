#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int top;
    int* arr;
} Stack;

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

void dec_to_bin(int x)
{
    Stack stack;
    Stack* st = &stack;
    st->top = -1;
    st->arr = malloc(0);

    while (x!=0)
    {
        push(st,x%2);
        x /= 2;
    }

    while (st->top >= 0)
        printf("%d",pop(st));
}

int main()
{
    int num;
    printf("Enter the decimal number : ");
    scanf("%d",&num);
    dec_to_bin(num);
    return 0;
}


