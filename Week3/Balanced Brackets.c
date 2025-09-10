//Balanced Brackets
//solved in c


#include<stdio.h>
#include<string.h>

#define MAX 1000

int isBalanced(char *s)
{
    char stack[MAX];
    int top=-1;
    
    for(int i=0;i<strlen(s);i++)
    {
        char c=s[i];
        
        if(c=='('||c=='{'||c=='[')
        {
            stack[++top]=c;
        }
        else{
            if(top==-1) return 0;
            char last=stack[top--];
            if((c==')'&&last!='(')||
            (c=='}'&&last!='{')||
            (c==']'&&last!='['))
                {
                    return 0;
             
                }   
        }
    }
    return (top==-1);     
}

int main()
{
    int n;
    scanf("%d",&n);
    char s[1001];
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        if(isBalanced(s))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
