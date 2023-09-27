#include<stdio.h>
#define SIZE 10
int stack[SIZE],top=-1;
void push()
{
    if(top==SIZE-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        int n;
        printf("Enter no of elements you want to enter upto 10: ");
        scanf("%d",&n);
        if(n>10)
        {
            printf("Invalid size\n");
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                top++;
                printf("Enter element for stack at position %d :",top);
                scanf("%d",&stack[top]);
            }
        }
    }
}
void display()
{
    if(top==-1)
    {
        printf("Underflow");        
    }
    else    
    {
        for(int i=top;i>=0;i--)
        {
            printf("\n%d ",stack[i]);
        }
    }
}
int main()
{
    push();
    display();
    return 0;
}