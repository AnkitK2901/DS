// wap to calculate the mean and standard deviation of the elements in the given 1-d array. The standard deviation measures the amount of variation or dispersion in the data set.

#include<stdio.h>
#include<math.h>
int main(){
    int array[5],i,sum=0,mean,d=0,sd,a,y=0;
    for(i=0;i<=4;i+=1){
        printf("Enter elemenets\n");
        scanf("%d",&array[i]);
        }
    printf("\n");
    for(i=0;i<=4;i+=1){
        sum=sum+array[i];
        printf("Element %d: %d\n",i+1,array[i]);
        }
        printf("\n");
        mean=sum/5;
        printf("sum=%d",sum);
        printf("\n");
        printf("mean=%d",mean);
        printf("\n"); 
        for(i=0;i<=4;i+=1){
            d=(array[i]-mean);
            a=pow(d,2);
            y+=a;
        }
        int x=y/4;
        sd=pow(x,0.5);
        printf("standard deviation=%d",sd);
        return 0;
}
