//Sparse Arrays
//Solved in c
#include<stdio.h>
#include<string.h>

//#define MAX_STRINGS 1000
//#define MAX_LEN 101

void matchingStrings(int n, char strings[][21],int q,char queries[][21],int result[]){
    for(int i=0;i<q;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(strcmp(queries[i],strings[j])==0)
            {
                count++;
            }
        }
        result[i]=count;
    }
}

int main()
{
    int n,q;
    
    scanf("%d",&n);
    char strings[n][21];
    for(int i=0;i<n;i++)
    {
        scanf("%s",strings[i]);
    }
    
    scanf("%d",&q);
    char queries[q][21];
    for(int i=0;i<q;i++)
    {
        scanf("%s",queries[i]);
    }
    int result[q];
    
    matchingStrings(n,strings,q,queries,result);
    
    for(int i=0;i<q;i++)
    {
        printf("%d\n",result[i]);
    }
    return 0;
}
