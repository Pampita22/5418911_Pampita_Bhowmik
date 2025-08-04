//DISPLAY DAY OF THE WEEK BASED ON USER INPUT USING FOR LOOP
#include<stdio.h>
int main()
{
  int day;
  for(int i=0;i,10;i++)
  {
    printf("Enter a number(1-7)");
    scanf("%d",&day);
    switch(day){
      case 1:
      printf("Monday\n");
      return 0;
      case 2:
      printf("Tuesday\n");
      return 0;
      case 3:
      printf("Wednesday\n");
      return 0;
      case 4:
      printf("Thursday\n");
      return 0;
      case 5:
      printf("Friday\n");
      return 0;
      case 6:
      printf("Saturday\n");
      return 0;
      case 7:
      printf("Sunday\n");
      return 0;
      default:
      printf("Wrong choice.Please enter number again\n");
    }
  }
}