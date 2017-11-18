#include<stdio.h>
#include<conio.h>


main()
{
struct num
{
 int n1:2;
 int n2:3;
 int n3:4;
}num = {3,4,5};

printf("%d%d%d",num.n1,num.n2,num.n3);
getch();
return  0;
}