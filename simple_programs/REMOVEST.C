#include<stdio.h>


// Remove duplications in a string
// Without using the Shift up/down operations! .. Destroy the input string allowed!!
main()
{
char str[100], strLen;
int index , i, tail=0 ;
scanf("%s",str);
strLen = strlen(str);
// Letter 1 no problem!
tail++;
for(index=1; index <strLen ; index++)
{
  for( i=0 ; i<tail; i++)
  {
    if(str[i] == str[index])
     break;
  }
  if(i == tail)
  str[tail++] = str[index];
}
str[tail]='\0';
printf("\nAfter  %s",str);
getch();
return 0;
}