// WAP to search an element from an array by using linear search

#include<stdio.h>

int main(){

    int n,i,x,count=0,y,z;
    printf("Enter size of array:");
    scanf("%d",&n);
    int array[n];  

    for(i=0;i<=n-1;i+=1)
    {
    printf("Enter elemenets\n");
    scanf("%d",&array[i]);
    }

    printf("Enter element you want to search:");
    scanf("%d",&x);

    for(i=0;i<=n-1;i+=1){
        if(array[i]==x){
            count+=1;
            y=array[i];
            z=i;
        }
    }

    if(count==1){
        printf("element %d found at %dth position",y,z);
    }
    else{
        printf("\nelement not found");
    }
    return 0;
}