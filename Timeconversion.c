//Time Conversion
//Solved in c
#include<stdio.h>
#include<string.h>

char* timeConversion(char* s)
{
    static char result[9];
    int hour=(s[0]-'0')*10+(s[1]-'0');
    
    if(s[8]=='A' && hour==12){
        hour=0;
    }
    else if(s[8]=='P' && hour!=12)
    {
        hour+=12;
    }
    
    sprintf(result,"%02d:%c%c:%c%c",hour,s[3],s[4],s[6],s[7]);
    return result;
}

int main()
{
    char s[11];
    scanf("%10s",s);
    printf("%s\n",timeConversion(s));
    return 0;
 
}
