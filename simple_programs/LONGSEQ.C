#include<stdio.h>
#include<limits.h>

void swap(int*,int*) ;
void bubbleSort(int*,int);

main()
{
int *arr,index,index2,seqCount,seqIndex,thisCount,num;
arr = (int*) malloc(sizeof(int)*7);

for(index=0;index<7;index++)
scanf("%d",&arr[index]);

//Sort and then find the longest seq!!
bubbleSort(arr,7);

seqCount = INT_MIN;
seqIndex  = 0;

for(index=0;index<(7-1);index++)
{
 num = arr[index];
 for(index2=index+1,thisCount=1; index2 < 7; index2++)
 {
    if( (num+1) == arr[index2] )
    {
     num = arr[index2];
     thisCount++;
    }
    else
     break;
 }
 if(thisCount > seqCount )
 {
  seqCount = thisCount;
  seqIndex = index;
 }

}
printf("\n\n");
for(index=0;index<7;index++)
printf(" %d ",arr[index]);

printf("\n\n Index is %d and Count %d\n\n",seqIndex,seqCount);

for( index = seqIndex; index < seqCount+seqIndex; index++)
printf(" %d ",arr[index]);




getch();
return 0;
}

void bubbleSort(int *arr,int num)
{
  int index,index1;
  for(index=0;index<num-1;index++)
    for(index1=index+1;index1<num;index1++)
      if(arr[index] > arr[index1])
       swap(&arr[index],&arr[index1])  ;
}

void swap(int *a,int *b)
{
  int tmp;
  tmp = *b;
  *b = *a;
  *a = tmp;
}