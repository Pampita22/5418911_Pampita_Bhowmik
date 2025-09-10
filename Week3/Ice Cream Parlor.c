//Ice Cream Parlor
//solved in c
#include<stdio.h>

void icecream(int m,int cost[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(cost[i]+cost[j]==m)
            {
                printf("%d %d\n",i+1,j+1);
                return;
                
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,n;
        scanf("%d",&m);
        scanf("%d",&n);
        
        int cost[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&cost[i]);
        }
        icecream(m,cost,n);
        
    }
    return 0;
}

