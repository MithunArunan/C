// Simple Solution to find the element that appears once in sorted array...
#include<stdio.h>


int bSearch(int arr[], int low, int high);
main()
{
 int *arr,arrLength,iLoop,index;
 printf("Enter the array length");
 // Get length from the user
 scanf("%d",&arrLength);
 arr =(int*) malloc(sizeof(int)*arrLength);
 printf("Enter the sorted array");
 for(iLoop=0 ; iLoop<arrLength ; iLoop++)
	scanf("%d",&arr[iLoop]);
 for( index=0 ; index < arrLength ; index += 2 )
	if( arr[index] != arr[index+1]  )
		break;
 printf("Element that appears once is %d\n",arr[index]);
 printf("\nWith binary Search result is %d\n", bSearch(arr,0,arrLength-1));
 getch();
 return 0;
}

int bSearch(int arr[], int low, int high)
{
      int mid;
      if(low > high)
       return NULL;
      while(low <= high)
      {
       mid = (high+low)/2;
       if(arr[mid] == arr[mid-1])
	if(mid%2 != 0)
	      low = mid+1;
	else
		high = mid-1;
       else if(arr[mid] == arr[mid+1])
	if(mid%2 !=0)
	       high = mid-1;
	else
		low = mid+1;
      else
	return arr[mid];
       }
       return NULL;

}