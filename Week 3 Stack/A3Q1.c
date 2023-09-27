#include<stdio.h>
#define SIZE 5
int top=-1,stack[SIZE];
void push(int a)
{
    if(top==SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top]=a;
        printf("%d inserted successfully at %d\n",a,top);
    }
}
void pop()
{
    if(top!=-1)
    {
        printf("%d is removed from %d\n",stack[top],top);
        top--;
    }
    else
    {
        printf("Underflow");
    }
}
void peek()
{
    if(top!=-1)
    {
        printf("%d is topmost element\n",stack[top]);
    }
    else
    {
        printf("Underflow\n");
    }
}
void display()
{
    if(top==-1)
    {
        printf("Underflow\n");
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
    push(6); 
    push(7);
    push(8);
    push(5);
    push(3);
    pop();
    push(10);
    pop();
    pop();
    peek();
    display();
    return 0;
}