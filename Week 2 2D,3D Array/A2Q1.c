#include<stdio.h>
int main(){
    int x,y,i,j,a=0;
    printf("Enter row: ");
    scanf("%d",&x);
    printf("Enter column: ");
    scanf("%d",&y);
    int array[x][y];
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("Enter element (%d,%d): ",i,j);
            scanf("%d",&array[i][j]);
        }
    }
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("Element %d,%d :%d\n",i,j,array[i][j]);
            a+=array[i][j];            
        }
    }
    printf("\nSum is %d",a);
    return 0;
}