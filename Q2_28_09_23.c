// 2. Write a program to print the number of non-zero elements in the list.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
int count=0;
void number_of_non_zero_element(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("\n\nLinked list is Empty.");
    }
    else
	{
        while (ptr != NULL)
        {
            if(ptr->data!=0)
            {
                count++;
            }
            ptr = ptr->next;
        }
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
int main()
{
    struct Node *head;
    head = NULL;
    for (int x = 0; x < 5; x++)
	{
        head=insertEnd(head);
    }
    number_of_non_zero_element(head);
    printf("no. of non zero element: %d",count);
    return 0;
}