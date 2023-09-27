// WAP to find out duplicate element from an array

#include<stdio.h>

int main(){

    int n,i,j;

    printf("Enter size of array:");
    scanf("%d",&n);

    int array[n];  

    for(i=0;i<=n-1;i+=1)
    {
    printf("Enter elemenets\n");
    scanf("%d",&array[i]);
    }

    for(i=0;i<=n-1;i+=1)
    {
        for(j=i+1;j<n;j++)
        {
            if(array[i]==array[j]){                
            printf("\nduplicate element is:%d",array[i]);
            }
        }
    }
    return 0;
}



