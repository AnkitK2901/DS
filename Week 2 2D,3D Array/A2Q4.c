#include<stdio.h>
int main()
{
    int i,j,k,n,m,p;
    printf("Enter Row: ");
    scanf("%d",&n);
    printf("Enter Column: ");
    scanf("%d",&m);
    printf("Enter Height: ");
    scanf("%d",&p);    
    int array[n][m][p];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            for(k=0;k<p;k++)
            {
                printf("Enter Element(%d,%d): ",i,j,k);
                scanf("%d",&array[i][j][k]);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            for(k=0;k<p;k++)
            {
                printf("%d ",array[i][j][k]);
            }
            printf("\n")`
        }
        printf("\n");
    }
    return 0;
}

/*#include<stdio.h>
void School_Data()
{
    
}
int main()
{
    return 0;
}*/