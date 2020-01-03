#include <winbgim.h>
#include <stdio.h>
#include <math.h>

#define RADS  0.017453

void K(int,float,float);

main()
{
      int n;
      
      printf("n="); scanf("%d",&n);
	  initwindow(1300,700);
      setbkcolor(15); setcolor(0); cleardevice();
      moveto(50, 600);
      K(n, 1200, 0);
      getch();
      closegraph();
}

void K(int n,float len,float d)
{
	if (n>0){
		K(n-1,len/3,d); 
		d-=60;
		K(n-1,len/3,d);
		d+=120;
		K(n-1,len/3,d);
		d-=60;
		K(n-1,len/3,d);
	} else linerel(int(len*cos(d*RADS)), int(len*sin(d*RADS)));
}
