#include<stdio.h>

main()
{
int *arr,n,index,iLoop1,iLoop2;
scanf("%d",&n);
arr =(int*) malloc (sizeof(int)*n);
for(index=0; index<n ;index++)
scanf("%d",&arr[index]);

printf("Printing elements\n");
for(index=0; index<n ;index++)
printf("%d",arr[index]);


for(index=0;index<n-1;index++)
 {
   int  leftSum=0,rightSum=0;
   for(iLoop1=0;iLoop1<index;iLoop1++)
    leftSum += arr[iLoop1];
   for(iLoop2 = index+1	 ; iLoop2 < n; iLoop2++)
    rightSum	 += arr[iLoop2];
   if(leftSum == rightSum)
    printf("\n\nIndex is %d ",index);
 }
getch();
return 0;
}