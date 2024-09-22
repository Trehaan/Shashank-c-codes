#include <stdio.h>
#include <string.h>

int main()
{
    char arr[20];
    printf("Enter  string : ");
    int i = 0;
    while ((arr[i++] = getchar())!='\n'){};
    arr[i++] = '\0';
    
    printf("%s",arr);

    return 0;
}