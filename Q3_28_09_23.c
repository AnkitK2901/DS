// 3. Write a program to merge two linked lists.
#include <stdio.h>
#include <stdlib.h>
struct node1
{
    int data1;
    struct node1 *next1;
};
struct node2
{
    int data2;
    struct node2 *next2;
};
struct node1 *insertEnd1(struct node1 *head1)
{
    struct node1 *new1 = (struct node1 *)malloc(sizeof(struct node1));
    printf("Enter value for list1: ");
    scanf("%d", &new1->data1);
    if (head1 == NULL)
    {
        head1 = new1;
        head1->next1 = NULL;
        return head1;
    }
    struct node1 *temp1 = head1;
    while (temp1->next1 != NULL)
    {
        temp1 = temp1->next1;
    }
    new1->next1 = NULL;
    temp1->next1 = new1;
    return head1;
}
struct node2 *insertEnd2(struct node2 *head2)
{
    struct node2 *new2 = (struct node2 *)malloc(sizeof(struct node2));
    printf("Enter value for list2: ");
    scanf("%d", &new2->data2);
    if (head2 == NULL)
    {
        head2 = new2;
        head2->next2 = NULL;
        return head2;
    }
    struct node2 *temp2 = head2;
    while (temp2->next2 != NULL)
    {
        temp2 = temp2->next2;
    }
    new2->next2 = NULL;
    temp2->next2 = new2;
    return head2;
}
void merge(struct node1 *head1, struct node2 *head2)
{
    struct node1 *temp = head1;
    while (temp->next1 != NULL)
    {
        temp = temp->next1;
    }
    temp->next1 = (struct node1 *)head2;
}
struct node1 *showLinkList1(struct node1 *ptr)
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
            printf("%d ", ptr->data1);
            ptr = ptr->next1;
        }
        printf("-> NULL (End of Linked List)");
    }
}
struct node2 *showLinkList2(struct node2 *ptr)
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
            printf("%d ", ptr->data2);
            ptr = ptr->next2;
        }
        printf("-> NULL (End of Linked List)");
    }
}
int main()
{
    struct node1 *head1;
    head1 = NULL;
    for (int x = 0; x < 5; x++)
    {
        head1 = insertEnd1(head1);
    }
    struct node2 *head2;
    head2 = NULL;
    for (int x = 0; x < 5; x++)
    {
        head2 = insertEnd2(head2);
    }
    showLinkList1(head1);
    showLinkList2(head2);
    printf("\nAfter Operation");
    merge(head1, head2);
    showLinkList1(head1);
    return 0;
}