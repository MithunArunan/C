#include<stdio.h>
#include<conio.h>

char** allocateMem(char**);
char** readStrings(char** s) ;

int main(void)
{
 char **stringArr;
 int iLoop1;
 int index =0;
 // TO allocate memory to the string Array
 stringArr = allocateMem(stringArr);
 // Elements to insert into the array
 readStrings(stringArr);
 index=0;
 while( index < 10)
 {
    printf(" %s \n",stringArr[index]);
    index++;
 }
 printf("\n--------------------------------------\n");
 getch();
 return 0;
}

char** allocateMem(char** stringArr)
{
 int iLoop1;
 stringArr = (char**) malloc(sizeof(char*)*10);
 for(iLoop1=0 ; iLoop1<10 ; iLoop1++ )
	stringArr[iLoop1] = (char*) malloc(sizeof(char)*15);
 return stringArr;
}

char** readStrings(char** s)
{
 int index;
   printf("Elements to read");
 for(index=0 ; index<10 ; index++ )
	scanf("%s",s[index]);
 return s;
}