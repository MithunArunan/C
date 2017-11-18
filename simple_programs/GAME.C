/* A Game Written By a Friend OF Mine, Hope You Enjoy it*/

#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>

#define right 0
#define left 1
#define up 2
#define down 3

void wall(void);
void food(void);
int x[100],y[100],i,length=12,score=0,l_k=right,eat=0,xf,yf;

void main()
{
	clrscr();
	gotoxy(22,11);
	printf("Use the arrow keys to change direction");
	gotoxy(23,12);
	printf("Press 'P' to PAUSE and 'Esc' to EXIT");
	gotoxy(27,13);
	printf("Press ENTER to continue...");
	getch();
	clrscr();
	wall();
	for(i=length-1;i>=0;i--)             //positioning the snake initially
	{
		x[i]=45-i;
		y[i]=20;
	}
	while(1)
	{
		while(kbhit()==0)
		{
			gotoxy(60,1);
			printf("TOTAL SCORE : %d",score);
			for(i=length-1;i>0;i--)
			{
				x[i]=x[i-1];
				y[i]=y[i-1];
			}
			for(i=length-1;i>=0;i--)        //snake structure
			{
				gotoxy(x[i],y[i]);
				printf("0");
			}
			gotoxy(x[0],y[0]);
			printf("#");
			gotoxy(x[length-1],y[length-1]);
			printf(" ");
			food();
			if(l_k==right || l_k==left)       //main delays
			{
				delay(80);
			}
			if(l_k==up || l_k==down)
			{
				delay(130);
			}
			if(x[0]==78 || x[0]==3 || y[0]==2 || y[0]==25) //hit wall
			{
				delay(1000);
				clrscr();
				wall();
				gotoxy(30,13);
				printf("You have hit the wall.");
				gotoxy(33,14);
				printf("Total score : %d",score);
				getch();
				exit(0);
			}


			if(l_k==right)
			{
				x[0]++;
			}
			if(l_k==left)
			{
				x[0]--;
			}
			if(l_k==up)
			{
				y[0]--;
			}
			if(l_k==down)
			{
				y[0]++;
			}


			for(i=length-1;i>1;i--)      //hit itself
			{
				if(x[0]==x[i] && y[0]==y[i])
				{
					delay(1000);
					clrscr();
					wall();
					gotoxy(32,13);
					printf("You have hit Yourself");
					gotoxy(33,14);
					printf("Total score : %d",score);
					getch();
					getch();
					exit(0);
				}
			}

		}
		union REGS i,o;
		i.h.ah=0;
		int86(22,&i,&o);
		if(o.h.ah==25)
		{
			gotoxy(2,1);
			printf("PAUSED...");
			while(kbhit()==0);
			gotoxy(2,1);
			printf("         ");
		}
		if(o.h.ah==1)
		{
			exit(0);
		}
		else if(o.h.ah==72 && l_k!=down)
		{
			l_k=up;
		}
		else if(o.h.ah==77 && l_k!=left)
		{
			l_k=right;
		}
		else if(o.h.ah==80 && l_k!=up)
		{
			l_k=down;
		}
		else if(o.h.ah==75 && l_k!=right)
		{
			l_k=left;
		}
	}
}

void wall(void)
{
	int x1,y1;
	for(x1=2;x1<=79;x1++)
	{
		gotoxy(x1,2);
		printf("=");
		gotoxy(x1,25);
		printf("=");
	}
	for(y1=3;y1<=24;y1++)
	{
		gotoxy(2,y1);
		printf("||");
		gotoxy(78,y1);
		printf("||");
	}
}

void food(void)
{
	if(eat==0)
	{
		srand(time(NULL));
		xf=(rand()%(73))+4;
		yf=(rand()%(21))+3;
		eat=1;
	}
	gotoxy(xf,yf);
	printf("*");

	if((xf==x[0])&&(yf==y[0]))
	{
		score=score+9;
		length++;
		eat=0;
	}
}

// by MAK
// still has bugs.... :(