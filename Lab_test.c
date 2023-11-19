#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *insertatend(struct node *head)
{
    struct node *temp = head;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &new->data);
    new->next = NULL;
    if (head == NULL)
    {
        new->prev = NULL;
        return new;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
    return head;
}
struct node *insertatbeginning(struct node *head)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &new->data);
    new->prev = NULL;
    new->next = head;
    if (head != NULL)
    {
        head->prev = new;
    }
    return new;
}
struct node *insertAtSpecificPosition(struct node *head)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value: ");
    scanf("%d", &new->data);
    int i = 0, pos = 0;
    printf("Enter position: ");
    scanf("%d", &pos);
    struct node *temp = head;
    while (i != pos - 1)
    {
        temp = temp->next;
        i++;
    }m
    new->next = temp->next;
    new->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = new;
    }
    temp->next = new;
    return head;
}
void showLinkList(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("\n\nLinked list is Empty.");
    }
    else
    {
        printf("\nLink list contains: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("-> NULL (End of Linked List)");
    }
}
void freeList(struct node *head)
{
    struct node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main()
{
    struct node *head = NULL;
    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at the end\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at specific position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = insertatend(head);
            break;
        case 2:
            head = insertatbeginning(head);
            break;
        case 3:
            head = insertAtSpecificPosition(head);
            break;
        case 4:
            showLinkList(head);
            break;
        case 5:
            printf("Exiting\n");
            freeList(head);
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}
