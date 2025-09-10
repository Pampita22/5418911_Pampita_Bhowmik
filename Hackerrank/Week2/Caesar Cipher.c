//Caesar Cipher
//solved in c
#include<stdio.h>

void caserCipher(char s[],int k)
{
    k=k%26;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            s[i]='a'+(s[i]-'a'+k)%26;
            
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            s[i]='A'+(s[i]-'A'+k)%26;
        }
    }
}
int main(){
    int k,n;
    char s[1000];
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%d",&k);
    
    caserCipher(s,k);
    printf("%s\n",s);
    return 0;
}
