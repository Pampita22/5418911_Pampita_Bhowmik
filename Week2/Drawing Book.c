//Drawing Book
//Solved in c
#include<stdio.h>

int pageCount(int n, int p)
{
    int front=p/2;
    int back=(n/2)-(p/2);
    if(front<back)
    {
        return front;
    }
    else {
    return back;
    }
}

int main()
{
    int n,p;
    scanf("%d %d",&n,&p);
    int result=pageCount(n,p);
    printf("%d",result);
    
}
