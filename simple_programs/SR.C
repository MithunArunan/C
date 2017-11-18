#include<stdio.h>


struct var
{
int data;
}s= {1};

main()
{
 //struct var s1;
 printf("Struct varialbe value is %d",s.data);
 getch();
 return 0;
}