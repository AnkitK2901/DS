// WAP to insert an element into an array at a particular position

#include<stdio.h>

int main(){

    int n,i,a,j,temp;

    printf("Enter size of array:");
    scanf("%d",&n);

    int array[n+1];  

    for(i=0;i<=n-1;i+=1)
    {
    printf("Enter elemenets\n");
    scanf("%d",&array[i]);
    }
    
    printf("Enter element to enter in array:");
    scanf("%d",&a);
    
    printf("Enter position:");
    scanf("%d",&j);
    
    for(i=n;i>j;i--)
    {
        //array[i+1]=array[i];
        //temp=array[i-1];
        array[i]=array[i-1];
    }
    
    array[j]=a;
    
    for(i=0;i<=n;i++){
        printf("\nElement %d",array[i]);
    }
    return 0;
}
