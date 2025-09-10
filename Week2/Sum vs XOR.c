//Sum vs XOR
//solved in c
#include<stdio.h>
long sum(long n)
{
    if(n==0)
    return 1;
    
    int zero=0;
    while(n>0){
        if(n%2==0)
            zero++;
        n/=2;
        }
        long result=1;
        for(int i=0;i<zero;i++)
        {
            result*=2;
        }
        return result;
}
int main()
{
    long n;
    scanf("%ld",&n);
    printf("%ld\n",sum(n));
    return 0;
}
