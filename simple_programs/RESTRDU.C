#include<stdio.h>


// Remove duplications in a string
// Without using the Shift up/down operations! .. Destroy the input string allowed!!
main()
{
char str[100], strLen;
int index , i, tail=0, hit[256]; // Assume it to be ASCII
scanf("%s",str);
strLen = strlen(str);
// Letter 1 no problem!
hit[str[tail++]] = 1;

for(index=1; index <strLen ; index++)
{

  if(!hit[str[index]])
  {
   str[tail++] = str[index];
   hit[str[index]] = 1;
  }
}
str[tail]='\0';
printf("\nAfter 	 %s",str);
getch();
return 0;
}