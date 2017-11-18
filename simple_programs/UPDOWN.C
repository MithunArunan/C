#include<stdio.h>

main()
{
int **arr, rows=5, cols =5,i,j, x, y, k;
arr =(int**) malloc(sizeof(int*)*rows);
 for( i=0 ; i<rows ; i++)
  arr[i] = (int*) malloc(sizeof(int)*cols);

 for(i=0 ;i<rows; i++)
   for(j=0;j<cols;j++)
    scanf("%d",&arr[i][j]);

 for(i=0 ;i<rows; i++)
 {
   for(j=0;j<cols;j++)
    printf(" %d ",arr[i][j]);
    printf("\n");

 }

 printf("Print the positionss to    ");
 scanf("%d %d",&x,&y);
 //Print Updown
 j =y; i=x;
 if( x==0)
 {
  k=1;
  for( ; j<cols; j++)
  {
    for( ; ((i <rows) && (i >= 0)) ; i+=k)
    {
     printf(" %d ",arr[i][j]);
    }
    if(i == -1)
    {
     k =1;
     i++;
    }
    else
    {
     k =-1;
     i--;
    }
  }
 }
 else
 {
  k=-1;
  for( ; j<cols; j++)
  {
    for( ; ((i <rows) && (i >= 0)) ; i+=k)
    {
     printf(" %d ",arr[i][j]);
    }
    if(i == -1)
    {
     k =1;
     i++;
    }
    else
    {
     k =-1;
     i--;
    }
  }
 }
getch();
return 0;
}