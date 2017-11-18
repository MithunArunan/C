#include<stdio.h>

main()
{
//Print Rectangle of characters
int x =7,i,j,k,p=34;
char arr[] = {'Z','Y','X','R'};
clrscr();
for(i=0;i<((x/2)+1);i++)
{
 gotoxy(p,i+1);
// printf("\n");
 for(j=-i;j<=i;j++)
 {
   printf("%cf",arr[abs(j)]);
 }
 p-=1;
}
for(k=((x/2)+1);k>=0;k--)
{
 gotoxy(p,++i);
// printf("\n");
 for(j=-k;j<=k;j++)
 {
   printf("%c",arr[abs(j)]);
 }
 p+=1;
}
getch();
return 0;
}