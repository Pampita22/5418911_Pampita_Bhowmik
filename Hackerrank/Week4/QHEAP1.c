//QHEAP1
//solved in c
#include<stdio.h>

int arr[100000];
int n=0;

void insert (int x)
{
    arr[n++]=x;
}
void deleteVal(int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            for(int j=i;j<n-1;j++)
            {
                arr[j]=arr[j+1];
            }
            n--;
            break;
        }
    }
}
int getMin()
{
    int min=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]<min)
        min=arr[i];
    }
    return min;
}
int main()
{
    int Q, type,x;
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d",&x);
            insert(x);
        }
        if(type==2)
        {
            scanf("%d",&x);
            deleteVal(x);
        }
        if(type==3)
        {
            printf("%d\n",getMin());
        }
    }
    return 0;
}
