/*#include <stdio.h>

int main(){
    int n;
    int count=0;

    printf("Number of values you want to enter : ");
    scanf("%d", &n);

    int array[n];
    int array2[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter value : ");
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++)
    {
        count=0;
        for (int j = 0; j < n; j++)
        {
            if(array[i]==array[j]){
                array2[i]=array[i];
                count++;
            }
        }
        printf("%d is present %d times in array.\n", array2[i], count);
        
    }
    
    
    return 0;
}*/





/*#include<stdio.h>
int main(){
    int arr[2][3]={{1,2,3},{4,5,6}};
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("Element (%d,%d): %d\n",i,j,arr[i][j]);
        }
    }
    return 0;
}*/



/*#include<stdio.h>
int main(){
    int x,y;
    printf("enter row: ");
    scanf("%d",&x);
    printf("enter column: ");
    scanf("%d",&y);
    int array[x][y];
    int i,j;
    for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                printf("enter element: ");
                scanf("%d",&array[i][j]);
            }
        }
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("element %d,%d :%d\n",i,j,array[i][j]);            
        }
    }
    return 0;
}*/








/*#include<stdio.h>
int main(){
    int x,y;
    printf("Enter row: ");
    scanf("%d",&x);
    printf("Enter column: ");
    scanf("%d",&y);
    int array1[x][y];
    int array2[x][y];
    int array3[x][y];
    int i,j;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("Enter element array1 (%d,%d): ",i,j);
            scanf("%d",&array1[i][j]);
        }
    }
    printf("\nArray1\n");
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("%d ",array1[i][j]);            
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("Enter element array2 (%d,%d): ",i,j);
            scanf("%d",&array2[i][j]);
        }
    }
    printf("\nArray2\n");
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("%d ",array2[i][j]);            
        }
        printf("\n");
    }
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            array3[i][j]=array1[i][j]+array2[i][j];            
        }
    }
    printf("\nArray3\n");
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("%d ",array3[i][j]);            
        }
        printf("\n");
    }
    return 0;
}*/

/*

// C program to show inserting a node
// after a given node in given Linked List
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
	int data;
	struct Node* next;
};

// Given a node prev_node, insert a new
// node after the given prev_node
void insertAfter(struct Node* prev_node, int new_data)
{
	// 1. check if the given prev_node
	// is NULL
	if (prev_node == NULL) {
		printf("The given previous node cannot be NULL");
		return;
	}

	// 2. allocate new node
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));

	// 3. put in the data
	new_node->data = new_data;

	// 4. Make next of new node
	// as next of prev_node
	new_node->next = prev_node->next;

	// 5. move the next of prev_node
	// as new_node
	prev_node->next = new_node;
}

// Function to insert element in LL
void push(struct Node* head_ref, int new_data)
{
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (head_ref);
	(head_ref) = new_node;
}

// This function prints contents of
// linked list starting from head
void printList(struct Node* node)
{
	while (node != NULL) {
		printf(" %d", node->data);
		node = node->next;
	}
	printf("\n");
}

// Driver code
int main()
{
	// Start with the empty list
	struct Node* head = NULL;

	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);

	printf("Created Linked list is: ");
	printList(head);

	// Insert 1 at the beginning.
	insertAfter(head, 1);

	printf("After inserting 1 after 2: ");
	printList(head);

	return 0;
}

*/

#include<stdio.h>
#include<stdlib.h>
struct link
{
	int info;
	struct link *next;
};
void create(struct link *node);
void display(struct link *node);
struct link* insertAtAnyPosition(struct link *node);
struct link* insertAtFirst(struct link *node);
void main()
{
	struct link *node;
	node = (struct link *)malloc(sizeof(struct link));
	if(node==NULL)
	{
		printf("\n Memory is not allocated");
		exit(0);
	}	
	create(node);
	printf("\n Before insertion.");
	display(node);
	struct link* newLink=insertAtAnyPosition(node);
	printf("\n After insertion.");
	display(newLink);
}
void create(struct link *node)
{
	char opt;
	printf("\n Enter a value: ");
	scanf("%d", &node->info);
	node->next=NULL;
	printf("\n Any more to entry(y/n): ");
	scanf(" %c", &opt);
	while(opt=='Y' || opt=='y')
	{
		node->next=(struct link *)malloc(sizeof(struct link));
		if(node==NULL)
		{
			printf("\n Memory is not allocated");
			exit(0);
		}
		node=node->next;
		printf("\n Enter a value: ");
		scanf("%d", &node->info);
		node->next=NULL;
		printf("\n Any more to entry(y/n): ");
		scanf(" %c", &opt);
	}
}
void display(struct link *node)
{
	while(node!=NULL)
	{
		printf("\n%d", node->info);
		node=node->next;
	}
}
struct link * insertAtAnyPosition(struct link *node)
{
	struct link *temp1=node;
	int count=1,pos,i;
	while(temp1->next!=NULL)
	{
		count++;
		temp1=temp1->next;
	}
	printf("\n Enter position to insert: ");
	scanf("%d", &pos);
	if(pos>count)
	{
		printf("\n This position is not available.");
		exit(0);
	}
    struct link *curr = (struct link *) malloc(sizeof(struct link));
    if(curr==NULL)
	{
		printf("\n Memory is not allocated");
		exit(0);
	}
    struct link *temp2=node;
    if(pos==0)
    {
    	return (insertAtFirst(temp2));
	}
	else
	{
	printf("\n Enter a value for current node: ");
	scanf("%d", &curr->info);
	curr->next=NULL;
    for(i=1;i<pos;i++)
	{
		temp2=temp2->next;
	}
    curr->next = temp2->next;
    temp2->next = curr;
	}
    return node;
}
struct link * insertAtFirst(struct link *node)
{
    struct link * curr = (struct link *) malloc(sizeof(struct link));
    if(curr==NULL)
	{
		printf("\n Memory is not allocated");
		exit(0);
	}
    printf("\n Enter a value for current node: ");
	scanf("%d", &curr->info);

    curr->next = node;
    node=curr;
    
	return node; 
}	
