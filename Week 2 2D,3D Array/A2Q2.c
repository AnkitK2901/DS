#include<stdio.h>
void transpose()
{
    int i,j,x,y,a;
    printf("Enter row: ");
    scanf("%d",&x);
    printf("Enter column: ");
    scanf("%d",&y);
    int array1[x][y];
    int array2[y][x];
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("Enter element (%d,%d): ",i,j);
            scanf("%d",&array1[i][j]);
        }
    }
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            array2[j][i]=array1[i][j];
        }
    }
    for(i=0;i<y;i++)
    {
        for(j=0;j<x;j++)
        {
            printf("Element %d,%d :%d\n",i,j,array2[i][j]);
        }
    }
}
int main(){
    transpose();    
    return 0;
}