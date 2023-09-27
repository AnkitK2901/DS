#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *pre;
    struct node *next;
};
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
    new->pre = temp;
    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->pre = NULL;
    head->next = NULL;
    printf("Enter value : ");
    scanf("%d", &head->data);
    for (int i = 0; i < 4; i++)
    {
        head = insertatend(head);
    }
    showDLL(head);
    return 0;
}