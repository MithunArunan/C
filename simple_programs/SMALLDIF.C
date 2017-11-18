#include<stdio.h>

main()
{
 int arr[5], index, index2, thisDiff, smallDiff;
 int pair1, pair2;
 for(index=0 ; index < 5 ;index++)
 scanf("%d",&arr[index]);

 for(index=0;index<5-1;index++)
 {
  for(index2=index+1,thisDiff=0;index2 < 5 ;index2++)
  {
    thisDiff = arr[index] - arr[index2];
     if(abs(thisDiff) < abs(smallDiff)  )
     {
      smallDiff = thisDiff;
      pair1=index;
      pair2= index2;
     }
   }
 }
 printf("the Pair are %d %d",arr[pair1],arr[pair2]);
 getch();
 return 0;
}