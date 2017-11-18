#include<stdio.h>

main()
{
int arr[10],index,size=0,ind,iLoop;
for(index=0;index < 5;index++)
{
 scanf("%d",&arr[index]);
 size++;
}

for(index=0;index<size-1;index++)
{
 for(ind =index+1;ind < size ;ind++)
  if(arr[ind] == arr[index])
  { // Shift up operation!
     printf("Dup found");
     for(iLoop=ind;iLoop < size-1;iLoop++)
     arr[ind] = arr[ind+1] ;
     size--;
  }
}

for(index=0;index < size ;index++)
printf(" %d ",arr[index]);

getch();
return 0;
}