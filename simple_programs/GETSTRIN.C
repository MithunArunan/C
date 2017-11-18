#include<stdio.h>

main()
{
char str[100];
fgets(str,100,stdin);
printf("\n  %s",str);
getch();
return 0;
}