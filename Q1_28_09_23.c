// 1. Write a program to multiply every element of the linked list with 10.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
struct Node *showLinkList(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("\n\nLinked list is Empty.");
    }
    else
	{
        printf("\nLink list contains : ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("-> NULL (End of Linked List)");
    }
}
struct Node *insertEnd(struct Node * head)
{
    struct Node * new = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value : ");
    scanf("%d", &new->data);
    if(head==NULL)
	{
        head=new;
        head->next=NULL;
        return head;
    }
    struct Node * temp = head;
    while(temp->next!=NULL)
	{
        temp=temp->next;
    }
    new->next=NULL;
    temp->next=new;
    return head;
}
struct Node *aftermultiply(struct Node * ptr)
{
    if (ptr == NULL)
    {
        printf("\n\nLinked list is Empty.");
    }
    else
	{
        printf("\nLink list contains : ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data*10);
            ptr = ptr->next;
        }
        printf("-> NULL (End of Linked List)");
    }
}
int main()
{
    struct Node *head;
    head = NULL;
    for (int x = 0; x < 5; x++)
	{
        head=insertEnd(head);
    }
    printf("\nAfter Operation\n");
    showLinkList(head);
    head=aftermultiply(head);
    return 0;
}