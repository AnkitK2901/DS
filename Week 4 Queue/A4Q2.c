#include <stdio.h>
#define MAX_SIZE 100 
int cq[MAX_SIZE];  
int front=-1,rear=-1;  
int isEmpty() 
{
    return front == -1;
}
int isFull() 
{
    return (front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1));
}
void CQINSERT(int item) 
{
    if (isFull()) 
    {
        printf("Queue is full. Cannot insert.\n");
        return;
    }
    if (front == -1) 
    {
        front = rear = 0; 
    } 
    else 
    {
        rear = (rear + 1) % MAX_SIZE; 
    }
    cq[rear] = item; 
}
int CQDELETE() 
{
    int item;
    if (isEmpty()) 
    {
        printf("Queue is empty. Cannot delete.\n");
        return -1; 
    }
    item = cq[front]; 
    if (front == rear) 
    {
        front = rear = -1; 
    } 
    else 
    {
        front = (front + 1) % MAX_SIZE; 
    }
    return item;
}
void displayQueue() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty.\n");
        return;
    }
    int current = front;
    printf("Circular Queue elements: ");
    do{
        printf("%d ", cq[current]);
        current = (current + 1) % MAX_SIZE;
    }while (current != (rear + 1) % MAX_SIZE);
    printf("\n");
}
int main() 
{    
    CQINSERT(1);
    CQINSERT(2);
    CQINSERT(3);
    CQINSERT(4);
    displayQueue();
    printf("Deleted item: %d\n", CQDELETE());
    displayQueue();
    CQINSERT(5);
    displayQueue();
    printf("Deleted item: %d\n", CQDELETE());
    printf("Deleted item: %d\n", CQDELETE());
    displayQueue();
    return 0;
}