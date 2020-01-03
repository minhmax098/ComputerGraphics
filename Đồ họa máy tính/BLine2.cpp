#include <winbgim.h>
#include <math.h>


void BLine2(int x1, int y1, int x2, int y2);

main()
{
      int mx,my;
      
      initwindow(1300,700);
      setbkcolor(15); setcolor(1); cleardevice();
      mx=getmaxx(); my=getmaxy();
	  BLine2(0, 400, 1200, 0);
	  getch();
      closegraph();
}

void BLine2(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, e, eg, ekg, c;
	
	dx=x2-x1; dy=y2-y1; c=getcolor();
	e=-2*dy-dx; ekg=-2*dy;  eg=-2*dy-2*dx;
	for (x=x1, y=y1; x<=x2; x++){
		putpixel(x, y, c); 
		delay(10);
		if (e<0) e+=ekg;
		else {
			e+=eg;
			y--;
		}
	} 
}
