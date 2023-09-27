// Write a program to find the median of the elements in the given one dimensional array. The median is in the middle value of a sorted data set or the average of the two middle values for an even number of elements.

#include <stdio.h>
int main(){
    int a,n,i,j;
    printf("Number of elements to insert: ");
    scanf("%d", &n);
    int array[n];
    for (i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d", &array[i]);
    }
    for (i=0;i<n;i++){
        for (j=0;j<n-i;j++){
            a = array[j+1];
            if(array[j]>array[j+1]){
                array[j+1]=array[j];
                array[j]=a;
            }
        }        
    }
    if(n%2==0){
        printf("Median:%d",(array[(n/2)-1]+array[(n/2)])/2);
    }
    else{
        printf("Median:%d",array[n/2]);
    }
    return 0;
}