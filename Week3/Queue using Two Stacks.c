//Queue using Two Stacks
//solved in c
#include<stdio.h>
#define MAX 100000

int s1[MAX],s2[MAX];
int top1=-1,top2=-1;

void enqueue(int x)
{
    s1[++top1]=x;
}
void dequeue()
{
    if(top2==-1)
    {
        while(top1!=-1)
        {
            s2[++top2]=s1[top1--];
        }
    }
    if(top2!=-1)
    {
        top2--;
    }
}
void front(){
    if(top2==-1)
    {
        while(top1!=-1)
        {
            s2[++top2]=s1[top1--];
        }
    }
    if(top2!=-1)
    {
        printf("%d\n",s2[top2]);
    }
}

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            int x;
            scanf("%d",&x);
            enqueue(x);
        }
        else if(type==2)
        {
            dequeue();
        }
        else if(type==3)
        {
            front();
        }
    }
    return 0;
}
