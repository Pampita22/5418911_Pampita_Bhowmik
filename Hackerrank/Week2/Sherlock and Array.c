//Sherlock and Array
//solved in c
#include<stdio.h>

void sum(int arr[],int n)
{
    int total=0;
    for(int i=0;i<n;i++)
    {
        total+=arr[i];
    }
    
    int left=0;
    for(int i=0;i<n;i++)
    {
        int right=total-left-arr[i];
        if(left==right)
        {
            printf("YES\n");
            return ;
        }
        left+=arr[i];
    }
    printf("NO\n");
}

int main()
{
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
        sum(arr,n);
           
    }
    return 0;
}
