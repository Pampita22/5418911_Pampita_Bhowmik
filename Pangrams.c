//Pangrams
//Solved inc

#include<stdio.h>
#include<ctype.h>

int isPangram(char s[])
{
    int letters[26] = {0};
    int count = 0;
    
    for(int i = 0; s[i] != '\0';i++)
    {
        char ch = tolower(s[i]);
        if(ch >= 'a' && ch <= 'z')
        {
            if(letters[ch - 'a'] == 0){
                letters[ch - 'a']=1;
                count ++;
  
            }
        }
    }
    return count == 26;
    
}

int main()
{
    char str[1001];
    fgets(str, sizeof(str), stdin);
    
    if(isPangram(str))
    
        printf("pangram\n");
    
    else 
    
        printf("not pangram\n");
    
    return 0;
}
