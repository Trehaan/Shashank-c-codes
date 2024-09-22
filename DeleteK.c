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

void delk(Stack* orig_st,int k)
{
    int count = 0;
    Stack* new_st = malloc(sizeof(Stack));
    new_st->top = -1;
    new_st->arr = malloc(0);
    push(new_st,pop(orig_st));

    while (count<k && orig_st->top > -1)
    {
        if (new_st->arr[new_st->top] > orig_st->arr[orig_st->top])
            push(new_st,pop(orig_st));
        else
        {
            pop(new_st);
            count++;
            if (new_st->top == -1 && count<k)
                push(new_st,pop(orig_st));
        }
    } 

    while (new_st->top > -1)
        push(orig_st,pop(new_st));
}

int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);

    Stack st;
    st.top = -1;
    st.arr = malloc(0);

    printf("Enter the elements : ");
    int i,arr[n];
    for (i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for (i=n-1;i>-1;i--)
        push(&st,arr[i]);

    printf("Enter k : ");
    int k;
    scanf("%d",&k);

    delk(&st,k);

    printf("\nArray after kdel :- \n\n");
    while (st.top > -1)
        printf("%d ",pop(&st));
}