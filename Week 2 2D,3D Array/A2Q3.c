// Write a C program to perform three tuple representation of sparse matrix and display all the elements.

#include<stdio.h>
int main()
{
    int x,y,i,j,count=0,size,a=0;
    printf("Enter Row: ");
    scanf("%d",&x);
    printf("Enter Column: ");
    scanf("%d",&y);
    int array[x][y];
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("Enter Element(%d,%d): ",i,j);
            scanf("%d",&array[i][j]);
        }
    }
    size=x*y;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            if(array[i][j]!=0)
            {
                count+=1;
            }
        }
    }
    int three_tuple_rep[3][count];
    if(count<size/2)
    {
        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                if(array[i][j]!=0)
                {
                    three_tuple_rep[0][a]=i;
                    three_tuple_rep[1][a]=j;
                    three_tuple_rep[2][a]=array[i][j];
                    a+=1;
                }
            }
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<count;j++)
            {
                printf("%d ",three_tuple_rep[i][j]);
            }
            printf("\n");   
        }
    }
    else
    {
        printf("\nThis is not a Sparse Matrix");
    }
    return 0;
}