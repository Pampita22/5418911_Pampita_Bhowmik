//Highest Value Palindrome
//solved in c
#include<stdio.h>
#include<string.h>

char* highest(char s[],int n,int k)
{
    static char res[100005];
    int mark[100005]={0};   
    int l,r;
    strcpy(res,s);
    
    l=0,r=n-1;
    while(l<r)
    {
        if(res[l]!=res[r])
        {
            if(res[l]>res[r]) res[r]=res[l];
            else res[l]=res[r];
            mark[l]=mark[r]=1;
            k--;
        }
        l++;
        r--;
    }
    
    
    if(k < 0) return "-1";
    
    l=0;r=n-1;
    while(l <= r && k > 0) {
        if (l == r) {
            if (res[l] != '9' && k > 0) res[l] = '9';
        } else {
            if (res[l] != '9') {
                if ((mark[l] || mark[r]) && k >= 1) {
                    res[l] = res[r] = '9';
                    k--;
                } else if (!mark[l] && !mark[r] && k >= 2) {
                    res[l] = res[r] = '9';
                    k -= 2;
                }
            }
        }
        l++;
        r--;
    }
    return res;
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    char s[100005];
    scanf("%s",s);
    printf("%s\n",highest(s,n,k));
    return 0;
}
