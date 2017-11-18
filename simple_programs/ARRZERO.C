#include<stdio.h>

main()
{
int rows, cols,iLoop1,iLoop2,arr[50][50],row[50],col[50];
printf("Enter the rows and colums");
scanf("%d %d",&rows,&cols);
for(iLoop1=0 ; iLoop1 < rows ; iLoop1++)
 for(iLoop2=0; iLoop2 < cols ; iLoop2++)
  scanf("%d",&arr[iLoop1][iLoop2]);

for(iLoop1=0 ; iLoop1 < rows ; iLoop1++)
 {
  for(iLoop2=0; iLoop2 < cols ; iLoop2++)
   printf(" %d ",arr[iLoop1][iLoop2]);
   printf("\n");
  }
for(iLoop1=0 ; iLoop1 < rows ; iLoop1++)
 for(iLoop2=0; iLoop2 < cols ; iLoop2++)
  {
   if(arr[iLoop1][iLoop2] == 0)
     {
      row[iLoop1] = 1;
      col[iLoop2] = 1;
     }
  }

for(iLoop1=0 ; iLoop1 < rows ; iLoop1++)
 for(iLoop2=0; iLoop2 < cols ; iLoop2++)
  {
   if(row[iLoop1] == 1 || col[iLoop2] == 1)
     {
      arr[iLoop1][iLoop2] = 0;
     }
  }

  printf("\n\n");
for(iLoop1=0 ; iLoop1 < rows ; iLoop1++)
 {
  for(iLoop2=0; iLoop2 < cols ; iLoop2++)
   printf(" %d ",arr[iLoop1][iLoop2]);
   printf("\n");
  }

getch();
return 0;
}