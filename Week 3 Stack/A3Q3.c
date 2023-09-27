#include <stdio.h>
int main()
{
    char str[]="Ankit";
    int size = sizeof(str)/sizeof(char);
    int top = size-2;
    char rev_str[100];
    printf("Reversed String : ");
    for (int i = top; i >= 0; i--)
    {
        rev_str[top-i]=str[i];
    }
    printf("%s", rev_str);
    return 0;
}