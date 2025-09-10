//Diagonal Difference
//Solved in c
#include<stdio.h>
#include<stdlib.h>

int absdiff(int n,int arr[n][n])

{
    int primarynum=0;
    int secondarynum=0;
    
    for(int i=0;i<n;i++){
        primarynum+=arr[i][i];
        secondarynum+=arr[i][n-i-1];
    }
    return abs(primarynum-secondarynum);
    
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n][n];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int result=absdiff(n,arr);
    printf("%d",result);
    
    return 0;
    
}
