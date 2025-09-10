//Sales by Match 
//Solved in c
#include<stdio.h>

int socks(int arr[],int n)
{
    int pairs=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==-1)
         continue;
        
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                pairs++;
                arr[j]=-1;
                break;
            }   
        }   
    }
    return pairs;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int result=socks(arr,n);
    printf("%d\n",result);
    return 0;

}
