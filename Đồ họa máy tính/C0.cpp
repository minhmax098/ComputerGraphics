#include <winbgim.h>
#include <stdio.h>
#include <math.h>

#define RADS  0.017453
#define FACT 0.7071

void C(int,float,float);

main()
{
      int n,a=0,b=0,x1,y1,x2,y2;
	  float len, dir,c;
      
      printf("n="); scanf("%d",&n);
	  initwindow(1300,700);
      setbkcolor(15); setcolor(1); cleardevice();
      while (!a || !b){
      	delay(1);
		if (ismouseclick(WM_LBUTTONDOWN)){
			a=1;
			getmouseclick (WM_LBUTTONDOWN,x1,y1);
			setcolor(1);circle(x1,y1,3);
		}
		if (ismouseclick(WM_RBUTTONDOWN)){
			b=1;
			getmouseclick (WM_RBUTTONDOWN,x2,y2);
			setcolor(4);circle(x2,y2,3);
		}
		if (a && b){
			len=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
			c=(x2-x1)/len;
			dir=acos(c);
			dir*=180/M_PI;
			len=int(len);
			dir=int(dir);
			printf("len=%0.0f, dir=%0.0f",len,dir);
			moveto(x1,y1); setcolor(1);
			C(n,len,dir); 
			getch();
			closegraph();
		}
	  }
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
