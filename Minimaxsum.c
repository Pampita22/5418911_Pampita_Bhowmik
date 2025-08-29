//Mini-Max sum
//Solved in c
#include <stdio.h>

void miniMaxSum(int arr[5])
{
    int i,min,max;
    long total=0;
    
    min=arr[0];
    max=arr[0];
    
    for(int i=0;i<5;i++)
    {
        total+=arr[i];
        
        if(arr[i]<min)
        min=arr[i];
        
        if(arr[i]>max)
        max=arr[i];
        
    }
    long minSum=total-max;
    long maxSum=total-min;
    
    printf("%ld %ld\n",minSum,maxSum);
}
int main()
{
    int arr[5];
    int i;
    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    miniMaxSum(arr);
    return 0;
}
