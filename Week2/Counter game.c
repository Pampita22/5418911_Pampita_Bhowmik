//Counter game
//solved in c
#include<stdio.h>

int isPower(long long n)
{
    return(n && !(n & (n-1)));
}
long long hPower(long long n)
{
    long long power=1;
    while(power*2<=n)
    {
        power*=2;
    }
    return power;
}

void game(long long n)
{
    int turns=0;
    while(n>1)
    {
        if(isPower(n))
        {
            n/=2;
        }
        else {
        n-=hPower(n);
        }
        turns++;
    }
    if(turns%2==0)
    {
        printf("Richard\n");
    }
    else{
        printf("Louise\n");
    }
}
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
    long long n;
    scanf("%lld",&n);
    game(n); 
   } 
   return 0;
}
