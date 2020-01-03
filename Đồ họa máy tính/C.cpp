#include <winbgim.h>
#include <stdio.h>
#include <math.h>

#define RADS  0.017453
#define FACT 0.7071

void C(int,float,float);

main()
{
      int gd=0, gm, n;
      
      printf("n="); scanf("%d",&n);
	  initwindow(1000,600);
      setbkcolor(15); setcolor(1); cleardevice();
      moveto(550, 150);
      C(n, 300, 90);
      getch();
      closegraph();
}

void C(int n,float len,float d)
{
	if (n>0){
		d+=45;
		C(n-1,len*FACT,d);
		d-=90;
		C(n-1,len*FACT,d);
		d+=45;
	} else linerel(int(len*cos(d*RADS)), int(len*sin(d*RADS)));
}
