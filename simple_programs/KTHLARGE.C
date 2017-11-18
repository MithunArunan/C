#include<stdio.h>

struct heap
{
int *time;
int size;
int capacity;
};
typedef struct heap Heap;

Heap* init(Heap* h)
{
 h->time = (int*) malloc(sizeof(int)*50);
 h->size = 0;
 h->capacity = 50;
 return h;
}

Heap* buildHeap(Heap* h, int timeData)
{
 int index;
 if(h->size ==0)
  h->time[++h->size]  = timeData;
 else
 {
  for(index = ++h->size; (timeData > h->time[index/2])&&(index > 1) ; index/=2)
  {
    h->time[index] = h->time[index/2];
  }
  h->time[index] = timeData;
 }
 return h;
}

void display(Heap*);

main()
{
int max1,num; Heap *h;
clrscr();
h = init(h);
h= buildHeap(h,5);
h= buildHeap(h,10);
h= buildHeap(h,15);
h= buildHeap(h,2);
h= buildHeap(h,3);
h= buildHeap(h,9);
display(h);
printf("WHich largest to print");
scanf("%d",&num);
while(num--)
{
 max1 =deleteMax(h);
}
printf("Maximum element is %d",max1);
printf("\n");
display(h);
getch();
return 0;
}

void display(Heap *h)
{
 int index;
 for(index=1;index <= h->size ; index++)
 printf(" %d ",h->time[index]);
}

int deleteMax(Heap *h)
{
  int min,last,index,child ;
  if(h->size == 0)
   printf("Heap is empty");
  else
  {
   min = h->time[1];
   last = h->time[h->size--];
   //compare
   for(index=1; (2*index) <= h->size ; index=child)
   {
    child = 2*index;
    if(child != h->size && h->time[child] < h->time[child+1])
    child++;
    if(h->time[child] > last)
    {
     h->time[index]  = h->time[child];
    }
    else
     break;
   }
   h->time[index] = last;
  }
  return min;
}