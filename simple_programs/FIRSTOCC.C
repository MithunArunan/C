#include<stdio.h>
#include<conio.h>

char* findFirstOccur(char ** stringArr);
char** allocateMem(char** stringArr);
char** readStrings(char** s);
int checkEqual(char s1[] , char s2[] );

main()
{
char ** str;
char *fOccur;
str = allocateMem(str);
str = readStrings(str);
//Find the first occurence of the non duplicate string...
// Presume the string is sorted initially..
// Use binary search for efficiency or Linear search as simple soluton
//Linear search
fOccur =(char*) malloc(sizeof(char)*10)        ;
fOccur = findFirstOccur(str);
printf("\nResultant is %s\n\n\n",fOccur);

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

char* findFirstOccur(char** stringArr)
{
 int iLoop;
 for( iLoop=0 ; iLoop < 10; iLoop += 2 )
 {
   if(checkEqual(stringArr[iLoop],stringArr [iLoop+1]))
   {
    break;
   }
 }
 return stringArr[iLoop];
}

int checkEqual(char s1[] , char s2[] )
{
 int index=0;
 while(s1[index] !='\0' ||  s2[index] !='\0' )
 {
	if( s1[index] != s2[index] )
	break;
	index++;
 }
 if(s1[index] == '\0' && s2[index] =='\0' )
 return 0;
 return 1;
}