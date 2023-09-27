#include<stdio.h>
#define SIZE 3
void push(){
    if(top==SIZE-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top]=val;
        printf("%d","inserted successfully",val);
    }
}
int main(){
    int stack[SIZE],top=-1,val;
    printf("Enter Value:");
    scanf("%d",&val);
    push();
    return 0;
}





