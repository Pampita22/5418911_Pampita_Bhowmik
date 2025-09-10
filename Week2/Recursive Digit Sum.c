//Recursive Digit Sum
//solved in c
#include<stdio.h>
long long sum(char n[]){
    long long sum=0;
    for(int i=0;n[i]!='\0';i++)
    {
        sum+=n[i]-'0';
    }
    return sum;
}

long long digit(long long num)
{
    if(num<10)return num;
    long long sum=0;
    
    while(num>0)
    {
        sum+=num%10;
        num/=10;
    }
    return digit(sum);
}




int main()
{
    char n[100005];
    int k;
    scanf(" %s %d",n,&k);
    long long total=sum(n);
    total*=k;
    printf("%lld\n",digit(total));
    return 0;
    
    
}
