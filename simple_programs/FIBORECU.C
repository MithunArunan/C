#include<stdio.h>
#include<conio.h>

// Fibonacci
int fibo(int);
main()
{
printf("Fibo number %d",fibo(34));
getch();
return 0;
}

int fibo(int n)
{
 if(n ==0)
 return 0;
 else if(n ==1)
  return 1;
 else
   return fibo(n-1)+fibo(n-2);

}