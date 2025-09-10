//The Maximum Subarray
//solved in c
#include<stdio.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    else 
        return b;
}

int maxSubarray(int arr[],int n)
{
    int curr_sum=arr[0];
    int best_sum=arr[0];
    for(int i=1;i<n;i++)
    {
        if(curr_sum+arr[i]>arr[i])
       {
        curr_sum=curr_sum+arr[i];
       } 
       else 
       {
        curr_sum=arr[i];
       }
       
       if(curr_sum>best_sum)
       {
        best_sum=curr_sum;
       }
    }
    return best_sum;
}

int maxSubs(int arr[],int n)
{
    int sum=0;
    int max_ele=arr[0];
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            sum+=arr[i];
        }
        if(arr[i]>max_ele)
        {
            max_ele=arr[i];
        }
    }
    if(sum==0)
    {
        return max_ele;
    }
    else 
    {
        return sum;
    }  
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        int subarray_sum=maxSubarray(arr,n);
        int subs_sum=maxSubs(arr,n);
        printf("%d %d\n",subarray_sum,subs_sum);
    }
    return 0;
}
