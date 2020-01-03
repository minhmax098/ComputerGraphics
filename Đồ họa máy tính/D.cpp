#include <winbgim.h>
#include <math.h>

#define RADS  0.017453
#define FACT 0.7071

void D(int,float,float,int);

main()
{
      
      initwindow(1000,600);
      setbkcolor(15); setcolor(2); cleardevice();
      moveto(550, 150);
      D(16, 300, 90,1);
      getch();
      closegraph();
}

void D(int n,float len,float d, int s)
{
	if (n>0){
		d+=45*s;
		D(n-1,len*FACT,d,1);
		d-=90*s;
		D(n-1,len*FACT,d,-1);
	} else linerel(int(len*cos(d*RADS)), int(len*sin(d*RADS)));
}
