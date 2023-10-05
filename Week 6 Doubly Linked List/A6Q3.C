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
    printf("Enter value : ");
    scanf("%d", &new->data);
    new->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
    return head;
}
struct node *reverseDoublyLinkedList(struct node *head)
{
    struct node *temp = NULL;
    struct node *current = head;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
    {
        head = temp->prev;
    }
    return head;
}
void showDLL(struct node *current)
{
    printf("\nNULL <-> ");
    while (current != NULL)
    {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL;
    head->next = NULL;
    printf("Enter value : ");
    scanf("%d", &head->data);
    for (int i = 0; i < 4; i++)
    {
        head = insertatend(head);
    }
    printf("Original Doubly Linked List: ");
    showDLL(head);
    head = reverseDoublyLinkedList(head);
    printf("Reversed Doubly Linked List: ");
    showDLL(head);
    return 0;
}