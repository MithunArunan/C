#include<stdio.h>
#include<string.h>

main()
{
int index=0,i;
char word[50],str2[500]; // fgets(str,100,stdin)
clrscr();
strcpy(str2,"");
scanf("%[^\n]s",str2);
while(str2[index])
{
// printf( " %d ",str[index++]) ;
 i=0;
 while(str2[index] != 32)
  {
  if(!str2[index])
    break;
  // printf("Inside 2");
    word[i] = str2[index];
//   printf(" %c ",str2[index]);
   index++;i++;
  }
    word[i] = '\0';
    strrev(word);
    printf("\n%s",word);

  if(!str2[index])
    break;
  index++;
//  if(str[index] != 10)
//   index++;  */
}
printf("\n%s",str2);
getch();
return 0;
}