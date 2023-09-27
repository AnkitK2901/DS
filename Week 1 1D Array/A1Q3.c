// consider the array containing temperature data for a week(sunday to saturday)  temperature_data=[25,28,27,30,31,29,26] write a program to perfome the following tasks 
// A. find the average temperature for the week. 
// B. identify the hottest day(highest temperature) and the coldest day(lowest temperature) of the week. 
// C. calculate the temperature range (diffrence between the hottest and coldest days)

#include <stdio.h>
int main(){
    int a,n,i,j,sum=0,mean;
    int array[7]={25,28,27,30,31,29,26};
    for (i=0;i<7;i++){
        for (j=0;j<7-i;j++){
            a = array[j+1];
            if(array[j]>array[j+1]){
                array[j+1]=array[j];
                array[j]=a;
            }
        }
        sum=sum+array[i];
        }
        mean=sum/7;
        printf("Average Temp=%d",mean);
        a=array[0];
        n=array[6];
        printf("\nLowest Temp:%d",a);
        printf("\nHighest Temp:%d",n);
        printf("\nDiffrence %d",n-a);        
    return 0;
}