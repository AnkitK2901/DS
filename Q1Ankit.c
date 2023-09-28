// Ankit Kumar 28/09/23 Lab evaluation
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *insertatend(struct node *head)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &new->data);
    if(head==NULL)
	{
        head=new;
        head->next=NULL;
        return head;
    }
    struct node * temp = head;
    while(temp->next!=NULL)
	{
        temp=temp->next;
    }
    new->next=NULL;
    temp->next=new;
    return head;
}
struct node *showLinkList(struct node *ptr)
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
    }
}
struct node *afteraddition(struct node *ptr)
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
            printf("%d ", ptr->data+10);
            ptr = ptr->next;
        }
    }
}
int main()
{
    struct node *head;
    head=NULL;
    for(int i=0;i<5;i++)
    {
        head=insertatend(head);
    }
    printf("Before addition");
    showLinkList(head);
    printf("\nAfter addition");
    afteraddition(head);
    return 0;
}