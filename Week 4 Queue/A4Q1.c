#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE],front=-1,rear=-1;
void enqueue(int value) 
{
    if(rear==SIZE-1) 
    {
        printf("Queue is full\n");
    } 
    else 
    {
        if(front==-1) 
        {
            front=0;
        }
        rear++;
        queue[rear]=value;
        printf("%d inserted into the queue.\n", value);
    }
}
void dequeue() 
{
    if(front==-1) 
    {
        printf("Queue is empty\n");
    } 
    else 
    {
        printf("%d deleted from the queue.\n", queue[front]);
        if (front==rear) 
        {
            front=rear=-1;
        } 
        else 
        {
            front++;
        }
    }
}
void traverse() 
{
    if(front==-1) 
    {
        printf("Queue is empty.\n");
    } 
    else 
    {
        printf("Queue elements: ");
        for(int i=front;i<=rear;i++) 
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main() 
{
    int choice, value;
    while(1) 
    {
        printf("1. Enqueue\n2. Dequeue\n3. Traverse\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) 
        {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid\n");
                exit(0);
        }
    }
    return 0;
}
